#include "main.h"

const static unsigned char UDPData[]="UDP�ͻ���ʵ������!\r\n";

struct udp_pcb *udp_pcb;
struct ip_addr ipaddr;
struct pbuf *udp_p;
/***********************************************************************
�������ƣ�void UDP_client_init(void)
��    �ܣ����udp�ͻ��˳�ʼ��
***********************************************************************/
void UDP_client_init(void)
{
	udp_p = pbuf_alloc(PBUF_RAW,sizeof(UDPData),PBUF_RAM);
	udp_p -> payload = (void *)UDPData;
	My_IP4_ADDR(&ipaddr,UDP_UDP_REMOTE_IP);				//Զ��IP
	udp_pcb = udp_new();
	udp_bind(udp_pcb,IP_ADDR_ANY,UDP_CLIENT_PORT); 	/* �󶨱���IP��ַ */
	udp_connect(udp_pcb,&ipaddr,UDP_REMOTE_PORT); 		/* ����Զ������ */		
}
/***********************************************************************
�������ƣ�My_IP4_ADDR(void)
��    �ܣ�IP��ַ��װ��
***********************************************************************/
void My_IP4_ADDR(struct ip_addr *ipaddr,unsigned char a,unsigned char b,unsigned char c,unsigned char d)
{
	ipaddr->addr = htonl(((u32_t)((a) & 0xff) << 24) | \
                               ((u32_t)((b) & 0xff) << 16) | \
                               ((u32_t)((c) & 0xff) << 8) | \
                                (u32_t)((d) & 0xff));
}
/***********************************************************************
�������ƣ�void UDP_client_init(void)
��    �ܣ����udp�ͻ��˳�ʼ��
***********************************************************************/
void UDP_Send_Data(struct udp_pcb *pcb,struct pbuf *p)
{
	udp_send(pcb,p);
	UDP_Delay(0XFFFFF);//��ʱ�����ܷ���̫��	
}

/***********************************************************************
�������ƣ�Delay(unsigned long ulVal)
��    �ܣ�����ѭ������һ������ʱ
***********************************************************************/
static void UDP_Delay(unsigned long ulVal) /* ����ѭ������һ������ʱ */
{
	while ( --ulVal != 0 );
}