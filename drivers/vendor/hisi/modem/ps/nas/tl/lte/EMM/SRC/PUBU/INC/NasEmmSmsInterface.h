/******************************************************************************

    Copyright(C)2008,Hisilicon Co. LTD.

 ******************************************************************************
  File Name       : NasEmmSmsInterface.h
  Description     : NasEmmSmsInterface.h header file
  History         :
     1.sunbing 49683       2011-11-14     Draft Enact
     2.
******************************************************************************/

#ifndef __NASEMMSMSINTERFACE_H__
#define __NASEMMSMSINTERFACE_H__

/*****************************************************************************
  1 Include Headfile
*****************************************************************************/
#include  "LmmSmsInterface.h"

/*****************************************************************************
  1.1 Cplusplus Announce
*****************************************************************************/
#ifdef __cplusplus
#if __cplusplus
    extern "C" {
#endif
#endif
/*****************************************************************************
#pragma pack(*)    设置字节对齐方式
*****************************************************************************/
#if (VOS_OS_VER != VOS_WIN32)
#pragma pack(4)
#else
#pragma pack(push, 4)
#endif


/*****************************************************************************
  2 macro
*****************************************************************************/


/*****************************************************************************
  3 Massage Declare
*****************************************************************************/


/*****************************************************************************
  4 Enum
*****************************************************************************/


/*****************************************************************************
   5 STRUCT
*****************************************************************************/


/*****************************************************************************
  6 UNION
*****************************************************************************/


/*****************************************************************************
  7 Extern Global Variable
*****************************************************************************/


/*****************************************************************************
  8 Fuction Extern
*****************************************************************************/
extern   VOS_VOID  NAS_LMM_SndLmmSmsEstCnf( VOS_VOID );
extern VOS_VOID  NAS_LMM_SndLmmSmsErrInd(LMM_SMS_ERR_CAUSE_ENUM_UINT32  enErrCause);

extern   VOS_VOID NAS_LMM_SndLmmSmsDataInd(const VOS_UINT8* aucMsg,VOS_UINT32 ulMsgLen);

extern   VOS_UINT32  NAS_EMM_PreProcMsgSmsDataReq( MsgBlock * pMsg );
extern   VOS_UINT32  NAS_EMM_PreProcMsgSmsEstReq(MsgBlock * pMsg );


extern  VOS_UINT32 NAS_EMM_SndSmsdataFailProc(VOS_VOID* pMsg,VOS_UINT32 *pulIsDelBuff);
/*****************************************************************************
  9 OTHERS
*****************************************************************************/









#if (VOS_OS_VER != VOS_WIN32)
#pragma pack()
#else
#pragma pack(pop)
#endif

#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif


#endif /* end of NasEmmSmsInterface.h */
