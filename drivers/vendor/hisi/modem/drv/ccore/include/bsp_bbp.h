
#ifndef _BSP_BBP_H_
#define _BSP_BBP_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "product_config.h"
#include "osl_types.h"
#include "mdrv_bbp.h"
#include "mdrv_pm.h"

typedef enum{
    BBP_PART_TOP = 0,
    BBP_DMA = 0,
    BBP_UL,/*1*/
    BBP_INT,/*2*/
    BBP_LSTU,/*3*/
    BBP_TSTU,/*4*/
    BBP_CTU,/*5*/
    BBP_ABB,/*6*/
    BBP_SCTRL,/*7*/
    BBP_LDRX,/*8*/
    BBP_TDRX,/*9*/
    BBP_WBBP,/*10*/
    BBP_CROSS_MIPI_MEM,/*11*/
    BBP_CROSS_MIPI_CTRL,/*12*/
    BBP_CDRX,/*13*/
    BBP_G0BBP,/*14*/
    BBP_G1BBP,/*15*/
    BBP_UCBBP,/*16*/
    BBP_PART_BUTT
}BBP_PART_ID_E;

struct bbp_dma_cfg
{
    u32 chan;/*ʹ�õ�ͨ����*/
    u32 bbp_addr;/*��Ҫ���Ƶ���ʼ��ַ*/
    u32 soc_addr;/*��Ҫ���Ƶ�Ŀ�ĵ�ַ*/
    u32 size;    /* ��Ҫ�洢�������Ĵ����ռ��С����λΪbyte */
    u32 type;   /*0:���ݴ�SOC�ռ���Ƶ�BBP�ռ䣬1:��BBP�ռ���Ƶ�SOC�ռ�*/
};

/*��������*/
/*****************************************************************************
* �� �� : bsp_bbp_power_status
* �� �� : dpmģ����ã����ڲ鿴bbpģ�����µ�״̬
* �� �� : ģʽ��������
* �� �� : ��
* �� �� : 0:�ɹ�����0ʧ��
* ˵ �� :
*****************************************************************************/
int bsp_bbp_power_status(PWC_COMM_MODE_E enModeId, PWC_COMM_MODULE_E enModuleId, PWC_COMM_MODEM_E enModemId);
/*****************************************************************************
* �� �� : bsp_bbp_power_up
* �� �� : dpmģ����ã����ڸ�bbpģ���ϵ�
* �� �� : ģʽ��������
* �� �� : ��
* �� �� : 0:�ɹ�����0ʧ��
* ˵ �� :
*****************************************************************************/
int bsp_bbp_power_up(PWC_COMM_MODE_E enModeId, PWC_COMM_MODULE_E enModuleId, PWC_COMM_MODEM_E enModemId);
/*****************************************************************************
* �� �� : bsp_bbp_power_down
* �� �� : dpmģ����ã����ڸ�bbpģ���µ�
* �� �� : ģʽ��ģ�飬������
* �� �� : ��
* �� �� : 0:�ɹ�����0ʧ��
* ˵ �� :
*****************************************************************************/
int bsp_bbp_power_down(PWC_COMM_MODE_E enModeId, PWC_COMM_MODULE_E enModuleId, PWC_COMM_MODEM_E enModemId);
/*****************************************************************************
* �� �� : bsp_bbp_dfs_status
* �� �� : dpmģ����ã����ڻ�ȡbbp pll ״̬
* �� �� : ģʽ��ģ�飬������
* �� �� : ��
* �� �� : 0x20:�رգ�0x10:����
* ˵ �� :
*****************************************************************************/
int bsp_bbp_dfs_status(PWC_COMM_MODE_E enModeId, PWC_COMM_MODULE_E enModuleId, PWC_COMM_MODEM_E enModemId);
/*****************************************************************************
* �� �� : bsp_bbp_dfs_enable
* �� �� : dpmģ����ã����ڴ�bbp pll
* �� �� : ģʽ��ģ�飬������
* �� �� : ��
* �� �� : 0x20:�رգ�0x10:����
* ˵ �� :
*****************************************************************************/
int bsp_bbp_dfs_enable(PWC_COMM_MODE_E enModeId, PWC_COMM_MODULE_E enModuleId, PWC_COMM_MODEM_E enModemId);
/*****************************************************************************
* �� �� : bsp_bbp_dfs_disable
* �� �� : dpmģ����ã����ڹر�bbp pll
* �� �� : ģʽ��ģ�飬������
* �� �� : ��
* �� �� : 0x20:�رգ�0x10:����
* ˵ �� :
*****************************************************************************/
int bsp_bbp_dfs_disable(PWC_COMM_MODE_E enModeId, PWC_COMM_MODULE_E enModuleId, PWC_COMM_MODEM_E enModemId);
/***************************************************************************
 �� �� ��  : bsp_bbp_enable_bbpclk()
 ��������  : ��bbp���ʱ��
 �������  : enModeId      Э��ģʽ
    	     enModuleId    ����ģ��
    	     enModemId     ����
 �������  : ��
 �� �� ֵ  : BBP_OK         �ɹ�
             ����           ʧ��
**************************************************************************/
int bsp_bbp_clk_enable (PWC_COMM_MODE_E enModeId, PWC_COMM_MODULE_E enModuleId, PWC_COMM_MODEM_E enModemId);
/***************************************************************************
 �� �� ��  : bsp_bbp_clk_disable()
 ��������  : ͨ��ģ�����BBPģ�����
 �������  : enModeId      Э��ģʽ
    	     enModuleId    ����ģ��
    	     enModemId     ����
 �������  : ��
 �� �� ֵ  : BBP_OK         �ɹ�
             ����           ʧ��
**************************************************************************/
int bsp_bbp_clk_disable (PWC_COMM_MODE_E enModeId, PWC_COMM_MODULE_E enModuleId, PWC_COMM_MODEM_E enModemId);
/*****************************************************************************
* �� �� : bsp_bbp_get_wakeup_time
* �� �� : ���͹��ĵ��ã�������ѯ˯�߳�ʱʱ��
* �� �� : void
* �� �� : void
* �� �� : bbp˯��ʣ��ʱ�䣬��λΪ32.768KHzʱ�Ӽ���
* ˵ �� : �������ĸ�ģ���ж೤ʱ�䱻�滽�ѣ�
		    ֻ������С��ʱ��
*****************************************************************************/
u32 bsp_bbp_get_wakeup_time(void);
/*****************************************************************************
* �� �� : bsp_bbp_get_gubbp_wakeup_status
* �� �� : pmģ�����
* �� �� : void
* �� �� : void
* �� �� : ��ǰʱ��
* ˵ �� :
*****************************************************************************/
u32 bsp_bbp_get_gubbp_wakeup_status(void);
/*****************************************************************************
* �� �� : bsp_bbp_part_addr_get
* �� �� : bbp ��ģ�����ַ��ȡ
* �� �� : void
* �� �� : void
* �� �� : ʹ��bbp�ռ��ģ�����
* ˵ �� :
*****************************************************************************/
void* bsp_bbp_part_addr_get(BBP_PART_ID_E part_id);

/*****************************************************************************
* �� �� : bsp_bbp_dma_tran
* �� �� : ʹ��bbp dma�������ݰ���
* �� �� : Ŀ���ַ��Դ��ַ������
* �� �� : vo
* �� �� :
* ˵ �� :
*****************************************************************************/
void bsp_bbp_dma_tran(struct bbp_dma_cfg *dma_config);

/*****************************************************************************
* �� �� : bsp_bbp_dma_finish
* �� �� : �ȴ�bbp dma�������
* �� �� : Ŀ���ַ��Դ��ַ������
* �� �� : vo
* �� �� :
* ˵ �� :
*****************************************************************************/
void bsp_bbp_dma_finish(struct bbp_dma_cfg *dma_config);

/*****************************************************************************
* �� �� : bsp_bbp_init
* �� �� : bbp ��ʼ��
* �� �� : void
* �� �� : void
* �� �� : ����ģ�����
* ˵ �� :
*****************************************************************************/
s32 bsp_bbp_init(void);




#ifdef __cplusplus
}
#endif

#endif /*end #ifndef _BSP_BBP_H_*/

