#include "dpi.h"

//ntp头定义
typedef struct dpi_ntp_header
{
    //位序要注意大端位序还是小端位序
#if __BYTE_ORDER == __LITTLE_ENDIAN
    uint16_t mode:3;
    uint16_t vn:3;
    uint16_t li:2;
#elif __BYTE_ORDER == __BIG_ENDIAN
    uint16_t li:2;
    uint16_t vn:3;
    uint16_t mode:3;
#endif
    uint8_t stratum;
    uint8_t poll;
    uint8_t precision;
}dpi_ntp_header;

//分析ntp协议报文的函数
int dpi_ntp_analyze(dpi_pkt *pkt)
{
    //报文长度 要么 48字节 要么 60字节
    if(pkt->payload_len!=48&&pkt->payload_len!=60)
        return 0;
    dpi_ntp_header *ntp = (dpi_ntp_header*)pkt->payload;
    //VN : 4
    if(ntp->vn!=4)
    {
        return 0;
    }
    //Stratum: 0-16
    if(ntp->stratum>16)
    {
        return 0;
    }

    //没有办法判断的话，判断端口
    //if(pkt->udp_packet->source == htons(123))

    return 1;
}
