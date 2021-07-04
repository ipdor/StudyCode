#include "dpi.h"
//解析ip报文的函数
void dpi_pkt_ip(dpi_result *res , dpi_pkt *pkt)
{
    //ip报文计数++
    res->ip_count++;
}
