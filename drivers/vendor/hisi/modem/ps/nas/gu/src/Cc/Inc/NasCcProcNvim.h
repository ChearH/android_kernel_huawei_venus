
#ifndef _MN_CALL_PROC_NVIM_H_
#define _MN_CALL_PROC_NVIM_H_

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include  "MnCall.h"
#include  "NasMntn.h"


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)

/*****************************************************************************
  1 全局变量定义
*****************************************************************************/

/*****************************************************************************
  2 宏定义
*****************************************************************************/

#define NAS_CC_NV_ITEM_ACTIVE          (1)                                      /* NV项激活 */
#define NAS_CC_NV_ITEM_DEACTIVE        (0)                                      /* NV项未激活 */


/*****************************************************************************
  3 枚举定义
*****************************************************************************/


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

VOS_VOID  NAS_CC_ReadCcbsNvim( VOS_VOID );
VOS_VOID NAS_CC_ReadNvimInfo(VOS_VOID);

VOS_VOID  NAS_CC_ReadCcTimerLenNvim( VOS_VOID );

VOS_VOID  NAS_CC_ReadCcT303LenNvim( VOS_VOID );

#if (FEATURE_ON == FEATURE_PTM)
VOS_VOID NAS_CC_ReadErrlogCtrlInfoNvim(VOS_VOID);
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

#endif /* end of MnCallCtx.h */

