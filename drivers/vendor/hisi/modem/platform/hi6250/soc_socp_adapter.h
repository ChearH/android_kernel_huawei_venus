

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/

#ifndef __SOC_SOCP_ADAPTER_H__
#define __SOC_SOCP_ADAPTER_H__

#ifdef __cplusplus
    #if __cplusplus
        extern "C" {
    #endif
#endif



/*****************************************************************************
  2 宏定义
*****************************************************************************/
#define SOC_SOCP_CODER_SRC_CHAN                 0x00

#define SOC_SOCP_CHAN_DEF(chan_type, chan_id)   ((chan_type<<16)|chan_id)


/*****************************************************************************
  3 枚举定义
*****************************************************************************/

/*编码源通道ID枚举定义*/
enum SOCP_CODER_SRC_ENUM
{
    SOCP_CODER_SRC_LOM_CNF1     = SOC_SOCP_CHAN_DEF(SOC_SOCP_CODER_SRC_CHAN,0),  /* OM命令响应(A核) */
    SOCP_CODER_SRC_BSP_ACORE    = SOC_SOCP_CHAN_DEF(SOC_SOCP_CODER_SRC_CHAN,1),  /* BSP OM通道(A核) */
    SOCP_CODER_SRC_LOM_IND1     = SOC_SOCP_CHAN_DEF(SOC_SOCP_CODER_SRC_CHAN,2),  /* OM诊断消息(A核,高优先级) */
    SOCP_CODER_SRC_LOM_IND4     = SOC_SOCP_CHAN_DEF(SOC_SOCP_CODER_SRC_CHAN,3),  /* OM诊断消息(A核,低优先级) */
    SOCP_CODER_SRC_LOM_IND2     = SOC_SOCP_CHAN_DEF(SOC_SOCP_CODER_SRC_CHAN,4),  /* OM诊断消息(C核,高优先级) */
    SOCP_CODER_SRC_LOM_IND3     = SOC_SOCP_CHAN_DEF(SOC_SOCP_CODER_SRC_CHAN,5),  /* OM诊断消息(C核,低优先级) */
    SOCP_CODER_SRC_LOM_CNF2     = SOC_SOCP_CHAN_DEF(SOC_SOCP_CODER_SRC_CHAN,6),  /* OM命令响应(C核) */
    SOCP_CODER_SRC_RSV1         = SOC_SOCP_CHAN_DEF(SOC_SOCP_CODER_SRC_CHAN,7),  /* 保留 */
    SOCP_CODER_SRC_BSP_CCORE    = SOC_SOCP_CHAN_DEF(SOC_SOCP_CODER_SRC_CHAN,8),  /* BSP OM通道(C核) */
    SOCP_CODER_SRC_HIFI         = SOC_SOCP_CHAN_DEF(SOC_SOCP_CODER_SRC_CHAN,9),  /* GU HIFI诊断消息 */
    SOCP_CODER_SRC_RSV2         = SOC_SOCP_CHAN_DEF(SOC_SOCP_CODER_SRC_CHAN,10), /* 保留 */
    SOCP_CODER_SRC_AXI_MONITOR  = SOC_SOCP_CHAN_DEF(SOC_SOCP_CODER_SRC_CHAN,11), /* AXI monitor */
    SOCP_CODER_SRC_MCU1         = SOC_SOCP_CHAN_DEF(SOC_SOCP_CODER_SRC_CHAN,12), /* MCU诊断消息 */
    SOCP_CODER_SRC_RSV3         = SOC_SOCP_CHAN_DEF(SOC_SOCP_CODER_SRC_CHAN,13), /* 保留 */
    SOCP_CODER_SRC_LDSP1        = SOC_SOCP_CHAN_DEF(SOC_SOCP_CODER_SRC_CHAN,14), /* LDSP诊断消息 */
    SOCP_CODER_SRC_LDSP2        = SOC_SOCP_CHAN_DEF(SOC_SOCP_CODER_SRC_CHAN,15), /* LDSP诊断消息 */
    SOCP_CODER_SRC_BBP_LOG      = SOC_SOCP_CHAN_DEF(SOC_SOCP_CODER_SRC_CHAN,16), /* LBBP LOG消息(通道与硬件绑定不能调整) */
    SOCP_CODER_SRC_BBP_BUS      = SOC_SOCP_CHAN_DEF(SOC_SOCP_CODER_SRC_CHAN,17), /* LBBP BUS消息(通道与硬件绑定不能调整) */
    SOCP_CODER_SRC_CPROC        = SOC_SOCP_CHAN_DEF(SOC_SOCP_CODER_SRC_CHAN,18), /* CPROC诊断消息 */
    SOCP_CODER_SRC_AP_BSP       = SOC_SOCP_CHAN_DEF(SOC_SOCP_CODER_SRC_CHAN,19), /* AP_BSP诊断消息 */
    SOCP_CODER_SRC_AP_APP       = SOC_SOCP_CHAN_DEF(SOC_SOCP_CODER_SRC_CHAN,20), /* AP_APP诊断消息 */
    SOCP_CODER_SRC_AP_DDR       = SOC_SOCP_CHAN_DEF(SOC_SOCP_CODER_SRC_CHAN,21), /* AP_DDR诊断消息 */
    SOCP_CODER_SRC_ISP          = SOC_SOCP_CHAN_DEF(SOC_SOCP_CODER_SRC_CHAN,22), /* ISP诊断消息 */
    SOCP_CODER_SRC_XDSP         = SOC_SOCP_CHAN_DEF(SOC_SOCP_CODER_SRC_CHAN,23), /* XDSP诊断消息 */
    SOCP_CODER_SRC_BBP_DS       = SOC_SOCP_CHAN_DEF(SOC_SOCP_CODER_SRC_CHAN,24), /* LBBP数采消息 */
    SOCP_CODER_SRC_GUBBP1       = SOC_SOCP_CHAN_DEF(SOC_SOCP_CODER_SRC_CHAN,25), /* GUBBP诊断消息 */
    SOCP_CODER_SRC_GUBBP2       = SOC_SOCP_CHAN_DEF(SOC_SOCP_CODER_SRC_CHAN,26), /* GUBBP诊断消息 */
    SOCP_CODER_SRC_GUDSP1       = SOC_SOCP_CHAN_DEF(SOC_SOCP_CODER_SRC_CHAN,27), /* GUDSP诊断消息 */
    SOCP_CODER_SRC_GUDSP2       = SOC_SOCP_CHAN_DEF(SOC_SOCP_CODER_SRC_CHAN,28), /* GUDSP诊断消息 */
    SOCP_CODER_SRC_RSV4         = SOC_SOCP_CHAN_DEF(SOC_SOCP_CODER_SRC_CHAN,29), /* 保留 */
    SOCP_CODER_SRC_RSV5         = SOC_SOCP_CHAN_DEF(SOC_SOCP_CODER_SRC_CHAN,30), /* 保留 */
    SOCP_CODER_SRC_RSV6         = SOC_SOCP_CHAN_DEF(SOC_SOCP_CODER_SRC_CHAN,31), /* 保留 */
    SOCP_CODER_SRC_BUTT
};


/*****************************************************************************
  4 消息头定义
*****************************************************************************/


/*****************************************************************************
  5 消息定义
*****************************************************************************/



/*****************************************************************************
  6 STRUCT定义
*****************************************************************************/



/*****************************************************************************
  7 UNION定义
*****************************************************************************/



/*****************************************************************************
  8 OTHERS定义
*****************************************************************************/



/*****************************************************************************
  9 全局变量声明
*****************************************************************************/


/*****************************************************************************
  10 函数声明
*****************************************************************************/


#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of bbp_cdma_on_interface.h */
