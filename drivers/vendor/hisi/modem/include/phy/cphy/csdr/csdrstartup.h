

#ifndef __CSDRSTARTUP_H__
#define __CSDRSTARTUP_H__


/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)

/*****************************************************************************
  2 宏定义
*****************************************************************************/

/* 尾部BIT校验值 */
#define CSDR_NV_TAIL_BIT_CHECK_VALUE0               ( 0x5555AAAA )
#define CSDR_NV_TAIL_BIT_CHECK_VALUE1               ( 0x5A5A5A5A )

/*****************************************************************************
  3 枚举定义
*****************************************************************************/
/*****************************************************************************
 枚举名    : CSDR_DSP_FLAG_ENUM
 枚举说明  : 是否有效标志
*****************************************************************************/
enum CSDR_DSP_FLAG_ENUM
{
    CSDR_DSP_INVALID_FLAG                   = 0,                                    /* 无效标志 */
    CSDR_DSP_VALID_FLAG                     = 1,                                    /* 有效标志 */
    CSDR_DSP_FLAG_BUTT
};
typedef PHY_UINT32 CSDR_DSP_FLAG_ENUM_UINT32;

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
 结构名    :CSDR_DSP_SHARE_START_UP_INFO_STRU
 协议表格  :
 结构说明  :DSP启动共享信息结构
*****************************************************************************/
typedef struct
{
    PHY_UINT32  uwHeadBit;                                      /* 头部保护字节，约定为'0x5555aaaa' */
    PHY_UINT32  uwLoadImageAddr;                                /* BIN文件加载到DDR的地址 */
    PHY_UINT32  uw1xBackupAddr;                                 /* 1X数据备份地址 */
    PHY_UINT32  uwEvdoBackupAddr;                               /* EVDO数据备份地址 */
    PHY_UINT32  uwDspShakeHandInfoAddr;                         /* DSP和APM握手信息地址 */
    PHY_UINT32  uwCdmaCsdrNvInfoAddr;                           /* CSDR NV信息地址 */
    PHY_UINT32  uwMailBoxAddr;                                  /* 邮箱信息地址 */
    PHY_UINT32  uwObjBaseAddr;                                  /* base addrs */
    PHY_UINT32  uwReserved[7];                                  /* 保留字节 */
    PHY_UINT32  uwTailBit;                                      /* 尾部保护字节，约定为'0xaaaa5555' */
}CSDR_DSP_SHARE_START_UP_INFO_STRU;

/*****************************************************************************
 结构名    :CSDR_DSP_APM_SHAKE_HAND_INFO_STRU
 协议表格  :
 结构说明  :DSP与APM的握手信息结构
*****************************************************************************/
typedef struct
{
    CSDR_DSP_FLAG_ENUM_UINT32   uwDspLoadedFlag;                               /* DSP加载标记，在DSP的代码被加载时直接初始化为置上的状态 */
    volatile CSDR_DSP_FLAG_ENUM_UINT32   uwDspStartRunFlag;                 /* DSP开始启动标记，初始化成无效状态，在APM成功写入NV信息后置成有效 */
    PHY_UINT32                  uwDspStartRunTimeStamp;                        /* 记录DSP开始启动标记置成有效的时刻 */
    CSDR_DSP_FLAG_ENUM_UINT32   uwDspInitReadyFlag;                            /* DSP初始化完成标记，初始化成无效状态，在DSP完成公共模块加载后置成有效 */
    PHY_UINT32                  uwDspInitReadyTimeStamp;                       /* 记录DSP初始化完成标记置成有效的时刻 */
    PHY_UINT32                  uwShakehandWithDrv;                            /* 记录DSP初始化完成标记置成有效的时刻 */
}CSDR_DSP_APM_SHAKE_HAND_INFO_STRU;

/*****************************************************************************
 结构名    :CSDR_SHARE_MBX_ADDR_INFO_STRU
 协议表格  :
 结构说明  :共享邮箱地址信息结构
*****************************************************************************/
typedef struct
{
    PHY_UINT32  uwPsMailboxDlBaseAddr;                          /* PS下行邮箱地址 */
    PHY_UINT32  uwPsMailboxUlBaseAddr;                          /* PS上行邮箱地址 */
    PHY_UINT32  uwOmMailboxDlBaseAddr;                          /* OM下行邮箱地址 */
    PHY_UINT32  uwCphyMbxLoadMemAddr;
    PHY_UINT32  uwCphyMbxWorkModeAddr;
}CSDR_SHARE_MBX_ADDR_INFO_STRU;

/*****************************************************************************
  7 UNION定义
*****************************************************************************/


/*****************************************************************************
  8 OTHERS定义
*****************************************************************************/


/*****************************************************************************
  9 全局变量声明
*****************************************************************************/
extern PHY_UINT8 g_aucHybridModeBackUpBuff[];

/*****************************************************************************
  10 函数声明
*****************************************************************************/












#if ((VOS_OS_VER == VOS_WIN32) || (VOS_OS_VER == VOS_NUCLEUS))
#pragma pack()
#else
#pragma pack(0)
#endif


#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of csdrstartup.h */

