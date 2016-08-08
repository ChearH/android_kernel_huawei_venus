

#ifndef __CNAS_XREG_TIMER_H__
#define __CNAS_XREG_TIMER_H__

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include  "vos.h"


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)

/*****************************************************************************
  2 宏定义
*****************************************************************************/
#define TI_CNAS_XREG_TIMER_PWROFF_ESTCNF_PT_LEN     (5*1000)   /* 和XSD保护定时器保持一致 */
#define TI_CNAS_XREG_TIMER_ESTCNF_PT_LEN            (330*1000) /* 接入层定时器大小为5分钟 */
#define TI_CNAS_XREG_TIMER_ABORTCNF_PT_LEN          (30*1000)
#define TI_CNAS_XREG_TIMER_ZONELIST_PT_LEN          (3600000)  /* 1小时 */
#define TI_CNAS_XREG_TIMER_CARDFILE_CNF_LEN         (5*1000)

/*****************************************************************************
  3 枚举定义
*****************************************************************************/


enum CNAS_XREG_TIMER_ID_ENUM
{
    TI_CNAS_XREG_TIMER_T57M,                /* T57m定时器 */
    TI_CNAS_XREG_TIMER_PERIOD_REG,          /* 周期注册定时器 */
    TI_CNAS_XREG_TIMER_ESTCNF_PT,           /* 发送CAS注册消息的保护定时器 */
    TI_CNAS_XREG_TIMER_PWROFF_ESTCNF_PT,    /* 发送CAS关机消息的保护定时器 */
    TI_CNAS_XREG_TIMER_ABORTCNF_PT,         /* 发送CAS终止消息的保护定时器 */
    TI_CNAS_XREG_TIMER_ZONELIST_PT,         /* ZONELIST保护定时器确保SLICE翻转没有影响 */
    TI_CNAS_XREG_TIMER_CARDFILE_CNF_PT,     /* 读取卡文件保护定时器 */
    TI_CNAS_XREG_TIMER_ID_BUTT
};
typedef VOS_UINT32  CNAS_XREG_TIMER_ID_ENUM_UINT32;


/*****************************************************************************
  4 全局变量声明
*****************************************************************************/


/*****************************************************************************
  5 消息头定义
*****************************************************************************/


/*****************************************************************************
  6 消息定义
*****************************************************************************/


/*****************************************************************************
  7 STRUCT定义
*****************************************************************************/


/*****************************************************************************
  8 UNION定义
*****************************************************************************/


/*****************************************************************************
  9 OTHERS定义
*****************************************************************************/


/*****************************************************************************
  10 函数声明
*****************************************************************************/
#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)



#endif




#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif




#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of __CNAS_XREG_TIMER_H__ */
