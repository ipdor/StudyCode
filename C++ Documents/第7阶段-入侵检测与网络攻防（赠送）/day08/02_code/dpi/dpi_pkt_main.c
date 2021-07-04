#include "dpi.h"
#include <stdio.h>

//声明一下函数
int dpi_ssh_analyze(dpi_pkt *pkt);

 //定义一个函数指针，专门用来识别协议报文
dpi_protocol_analyze_func_t  dpi_tcp_analyze_funcs[ProtocolTCPEnd]=
{
    dpi_ssh_analyze
};

void dpi_pkt_tcp(dpi_result *res , dpi_pkt *pkt);
void dpi_pkt_udp(dpi_result *res , dpi_pkt *pkt);

//解析ip报文的函数
void dpi_pkt_ip(dpi_result *res , dpi_pkt *pkt)
{
    //ip报文计数++
    res->ip_count++;
    //ip版本号要为4
    if(pkt->ip_packet->version != 4)
    {
        DPI_LOG_DEBUG("IP version not eq 4\n");
        return ;
    }
    //ip首部长度要记住
    int ihl = pkt->ip_packet->ihl << 2; //单位是4，所以要乘以4
    //ip报文总长度
    int ip_totlen = ntohs(pkt->ip_packet->tot_len);
    //判断片偏移是否为0
    if((pkt->ip_packet->frag_off & htons(0x01ff)) != 0)
    {
        DPI_LOG_DEBUG("IP frag off  not eq 0\n");
        return;
    }

    //根据ip报文是什么协议来进行分支
    switch(pkt->ip_packet->protocol)
    {
    case IPPROTO_TCP:
        //tcp
        //计算数据的长度以及起始位置
        pkt->tcp_len = ip_totlen - ihl; 
        //如果数据区域没有数据，跳过
        if(pkt->tcp_len<=0)
            return;
        pkt->tcp_packet = (struct tcphdr*)((char*)pkt->ip_packet + ihl);
        dpi_pkt_tcp(res,pkt);
        break;
    case IPPROTO_UDP:
        //udp
        pkt->udp_len = ip_totlen - ihl; 
        //如果数据区域没有数据，跳过
        if(pkt->udp_len<=0)
            return;
        pkt->udp_packet = (char*)pkt->ip_packet + ihl;
        dpi_pkt_udp(res,pkt);
        break;
    default:
        break;
    }


}
//TCP的解析函数
void dpi_pkt_tcp(dpi_result *res , dpi_pkt *pkt)
{
    res->tcp_count++;
    //计算tcp头部长度
    int tcphl = pkt->tcp_packet->doff * 4 ;

    //计算数据区域的长度
    pkt->payload_len = pkt->tcp_len - tcphl;  //数据区域长度=tcp报文总长度-tcp头长
    pkt->payload = (uint8_t*)pkt->tcp_packet + tcphl;

    int i;
    for(i=0;i<ProtocolTCPEnd;++i)
    {
        if(dpi_tcp_analyze_funcs[i](pkt))
        {
            //匹配了对应的协议
            res->tcp_payload_count[i]++;
            break;
        }
    }





}
//UDP的解析函数
void dpi_pkt_udp(dpi_result *res , dpi_pkt *pkt)
{
    res->udp_count++;
}
