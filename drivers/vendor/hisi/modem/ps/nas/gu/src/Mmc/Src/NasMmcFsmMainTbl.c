

/*****************************************************************************
  1 ͷ�ļ�����
*****************************************************************************/


#include "NasFsm.h"
#include "NasMmcFsmMain.h"
#include "NasMmcTimerMgmt.h"
#include "MmcGmmInterface.h"
#include "MmcMmInterface.h"
#include "NasMmcSndInternalMsg.h"
/* ɾ��ExtAppMmcInterface.h*/
#include "NasMmcFsmMainTbl.h"

#include "MsccMmcInterface.h"

#include "PsRrmInterface.h"



#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#define    THIS_FILE_ID        PS_FILE_ID_NAS_MMC_FSMMAIN_C

/*****************************************************************************
  2 ȫ�ֱ�������
*****************************************************************************/

/* Ԥ����״̬�� */

/* NAS MMC״̬�� */
NAS_FSM_DESC_STRU                       g_stNasMmcMainFsmDesc;


/*����״̬���������� */
/* NAS_MMC_L1_STA_NULL������ */
NAS_ACT_STRU   g_astNasMmcNullActTbl[]                      =
{
    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_START_REQ,
                      NAS_MMC_RcvStartReq_NULL),

    NAS_ACT_TBL_ITEM( WUEPS_PID_MMC,
                      MMCMMC_SWITCH_ON_RSLT_CNF,
                      NAS_MMC_RcvSwitchOnRslt_NULL),

    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_POWER_OFF_REQ,
                      NAS_MMC_RcvPowerOffReq_NULL),
};

/* NAS_MMC_L1_STA_INITIAL������ */
NAS_ACT_STRU   g_astNasMmcInitialActTbl[]                   =
{
    /* �û����������� */
    NAS_ACT_TBL_ITEM(UEPS_PID_MSCC,
                     ID_MSCC_MMC_POWER_OFF_REQ,
                     NAS_MMC_RcvPowerOffReq_L1Main),

    NAS_ACT_TBL_ITEM(WUEPS_PID_MMC,
                     MMCMMC_POWER_OFF_RSLT_CNF,
                     NAS_MMC_RcvPowerOffRslt_L1Main),

    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_SYS_CFG_SET_REQ,
                      NAS_MMC_RcvSysCfgReq_L1Main),

    NAS_ACT_TBL_ITEM( WUEPS_PID_MMC,
                      MMCMMC_SYSCFG_RSLT_CNF,
                      NAS_MMC_RcvSyscfgRsltCnf_L1Main),

    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_PLMN_LIST_REQ,
                      NAS_MMC_RcvTafPlmnListReq_L1Main),

#if (FEATURE_ON == FEATURE_CSG)
    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_CSG_LIST_SEARCH_REQ,
                      NAS_MMC_RcvMsccCsgListSearchReq_L1Main),

    NAS_ACT_TBL_ITEM( VOS_PID_TIMER,
                      TI_NAS_MMC_PERIOD_TRYING_USER_CSG_LIST_SEARCH,
                      NAS_MMC_RcvTiPeriodTryingUserCsgListExpired_L1Main),

#endif
    NAS_ACT_TBL_ITEM( VOS_PID_TIMER,
                      TI_NAS_MMC_PERIOD_TRYING_USER_PLMN_LIST,
                      NAS_MMC_RcvTiPeriodTryingUserPlmnListExpired_L1Main),

    NAS_ACT_TBL_ITEM( WUEPS_PID_MMC,
                      MMCMMC_PLMN_LIST_RSLT_CNF,
                      NAS_MMC_RcvMmcPlmnListRsltCnf_L1Main),

    /* MSCC���͹������û�ָ���������� */
    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_PLMN_SPECIAL_REQ,
                      NAS_MMC_RcvPlmnSpecialReq_L1Main),

    /* MSCC���͹����Ŀ����������� */
    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_PLMN_SEARCH_REQ,
                      NAS_MMC_RcvMsccPlmnSrchReq_L1Main),

    /* MSCC���͹����Ļ�ȡ���� */
    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_ACQ_REQ,
                      NAS_MMC_RcvMsccAcqReq_L1Main),

    /* MSCC���͹�����ע������ */
    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_REG_REQ,
                      NAS_MMC_RcvMsccRegReq_L1Main),

    /* MSCC���͹�����PowerSave���� */
    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_POWER_SAVE_REQ,
                      NAS_MMC_RcvMsccPowerSaveReq_L1Main),

#if (FEATURE_ON == FEATURE_DSDS)
    /* MSCC���͹�����ID_MSCC_MMC_SRV_ACQ_REQ */
    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_SRV_ACQ_REQ,
                      NAS_MMC_RcvMsccSrvAcqReq_L1Main),
#endif

    /* MMC�ڲ�������������� */
    NAS_ACT_TBL_ITEM( WUEPS_PID_MMC,
                      MMCMMC_INTER_PLMN_SEARCH_REQ,
                      NAS_MMC_RcvInterPlmnSrchReq_Initial),

    NAS_ACT_TBL_ITEM( WUEPS_PID_MMC,
                      MMCMMC_INTER_ANYCELL_SEARCH_REQ,
                      NAS_MMC_RcvInterAnyCellSrchReq_Initial),

    /* �յ�������ɻظ���Ϣ */
    NAS_ACT_TBL_ITEM( WUEPS_PID_MMC,
                      MMCMMC_PLMN_SELECTION_RSLT_CNF,
                      NAS_MMC_RcvMmcPlmnSelectionRslt_Initial),

    NAS_ACT_TBL_ITEM( WUEPS_PID_MMC,
                      MMCMMC_ANYCELL_SEARCH_RSLT_CNF,
                      NAS_MMC_RcvMmcAnycellSearchRslt_Initial),

    NAS_ACT_TBL_ITEM( WUEPS_PID_MMC,
                      MMCMMC_GET_GEO_RSLT_CNF,
                      NAS_MMC_RcvMmcGetGeoRslt_Initial),

    NAS_ACT_TBL_ITEM( UEPS_PID_RRM,
                      ID_RRM_PS_STATUS_IND,
                      NAS_MMC_RcvRrmPsStatusInd_L1Main),

    NAS_ACT_TBL_ITEM( WUEPS_PID_MM,
                      MMCMM_CM_SERVICE_IND,
                      NAS_MMC_RcvMmCmServiceInd_Initial),

#if (FEATURE_ON == FEATURE_LTE)
    NAS_ACT_TBL_ITEM( WUEPS_PID_MM,
                      MMCMM_CSFB_ABORT_IND,
                      NAS_MMC_RcvMmCsfbAbortInd_Initial),
#endif

    NAS_ACT_TBL_ITEM( WUEPS_PID_MM,
                      MMCMM_PLMN_SEARCH_IND,
                      NAS_MMC_RcvMmPlmnSearchInd_Initial),

    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_PLMN_USER_RESEL_REQ,
                      NAS_MMC_RcvUserReselReq_L1Main),


    NAS_ACT_TBL_ITEM( WUEPS_PID_MMC,
                      MMCMMC_INTER_DPLMN_SET_REQ,
                      NAS_MMC_RcvMmcInterDplmnSetReq_Initial),

    /* �ײ㷢�����ϵͳ��ѡ */
    NAS_ACT_TBL_ITEM( WUEPS_PID_WRR,
                      RRMM_SUSPEND_IND,
                      NAS_MMC_RcvSuspendInd_Initial),

    NAS_ACT_TBL_ITEM( UEPS_PID_GAS,
                      RRMM_SUSPEND_IND,
                      NAS_MMC_RcvSuspendInd_Initial),

#if (FEATURE_ON == FEATURE_LTE)
    NAS_ACT_TBL_ITEM( PS_PID_MM,
                      ID_LMM_MMC_SUSPEND_IND,
                      NAS_MMC_RcvSuspendInd_Initial),

    NAS_ACT_TBL_ITEM( PS_PID_MM,
                      ID_LMM_MMC_DETACH_CNF,
                      NAS_MMC_RcvLmmDetachCnf_L1Main),

    NAS_ACT_TBL_ITEM( PS_PID_MM,
                      ID_LMM_MMC_AREA_LOST_IND,
                      NAS_MMC_RcvAreaLostInd_Initial),
#endif

    NAS_ACT_TBL_ITEM( WUEPS_PID_WRR,
                      RRMM_AREA_LOST_IND,
                      NAS_MMC_RcvAreaLostInd_Initial),

    NAS_ACT_TBL_ITEM( UEPS_PID_GAS,
                      RRMM_AREA_LOST_IND,
                      NAS_MMC_RcvAreaLostInd_Initial),

    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_GET_GEO_REQ,
                      NAS_MMC_RcvMsccGetGeoReq_L1Main),


#if (FEATURE_ON == FEATURE_LTE)
    NAS_ACT_TBL_ITEM( PS_PID_MM,
                      ID_LMM_MMC_SERVICE_RESULT_IND,
                      NAS_MMC_RcvLmmServiceResultInd_Initial),
#endif

    /* available Timer��ʱ����ʱ */
    NAS_ACT_TBL_ITEM(VOS_PID_TIMER,
                     TI_NAS_MMC_AVAILABLE_TIMER,
                     NAS_MMC_RcvTiAvailTimerExpired_L1Main),

};

/* NAS_MMC_L1_STA_ON_PLMN������ */
NAS_ACT_STRU   g_astNasMmcOnPlmnActTbl[] =
{
    /* �û����������� */
    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_POWER_OFF_REQ,
                      NAS_MMC_RcvPowerOffReq_L1Main),

    /* �յ��ػ�״̬���Ļظ���Ϣ  */
    NAS_ACT_TBL_ITEM( WUEPS_PID_MMC,
                      MMCMMC_POWER_OFF_RSLT_CNF,
                      NAS_MMC_RcvPowerOffRslt_L1Main),

    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_SYS_CFG_SET_REQ,
                      NAS_MMC_RcvSysCfgReq_L1Main),

    NAS_ACT_TBL_ITEM( WUEPS_PID_MMC,
                      MMCMMC_SYSCFG_RSLT_CNF,
                      NAS_MMC_RcvSyscfgRsltCnf_L1Main),


    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_PLMN_LIST_REQ,
                      NAS_MMC_RcvTafPlmnListReq_L1Main),

#if (FEATURE_ON == FEATURE_CSG)
    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_CSG_LIST_SEARCH_REQ,
                      NAS_MMC_RcvMsccCsgListSearchReq_L1Main),

    NAS_ACT_TBL_ITEM( VOS_PID_TIMER,
                      TI_NAS_MMC_PERIOD_TRYING_USER_CSG_LIST_SEARCH,
                      NAS_MMC_RcvTiPeriodTryingUserCsgListExpired_L1Main),

#endif
    NAS_ACT_TBL_ITEM( VOS_PID_TIMER,
                      TI_NAS_MMC_PERIOD_TRYING_USER_PLMN_LIST,
                      NAS_MMC_RcvTiPeriodTryingUserPlmnListExpired_L1Main),

    NAS_ACT_TBL_ITEM( WUEPS_PID_MMC,
                      MMCMMC_PLMN_LIST_RSLT_CNF,
                      NAS_MMC_RcvMmcPlmnListRsltCnf_L1Main),

    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_PLMN_SPECIAL_REQ,
                      NAS_MMC_RcvUserSpecPlmnSearch_OnPlmn),

    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_PLMN_SEARCH_REQ,
                      NAS_MMC_RcvMsccPlmnSrchReq_L1Main),

    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_PLMN_USER_RESEL_REQ,
                      NAS_MMC_RcvUserReselReq_L1Main),

    /* MSCC���͹����Ļ�ȡ���� */
    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_ACQ_REQ,
                      NAS_MMC_RcvMsccAcqReq_L1Main),

    /* MSCC���͹�����ע������ */
    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_REG_REQ,
                      NAS_MMC_RcvMsccRegReq_L1Main),

    /* MSCC���͹�����PowerSave���� */
    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_POWER_SAVE_REQ,
                      NAS_MMC_RcvMsccPowerSaveReq_L1Main),

    /* MMC�ڲ�������б��������� */
    NAS_ACT_TBL_ITEM( WUEPS_PID_MMC,
                      MMCMMC_INTER_PLMN_LIST_REQ,
                      NAS_MMC_RcvMmcInterPlmnListReq_OnPlmn),

    /* �ײ㷢�����ϵͳ��ѡ */
    NAS_ACT_TBL_ITEM( WUEPS_PID_WRR,
                      RRMM_SUSPEND_IND,
                      NAS_MMC_RcvRrMmSuspendInd_OnPlmn),

    NAS_ACT_TBL_ITEM( UEPS_PID_GAS,
                      RRMM_SUSPEND_IND,
                      NAS_MMC_RcvRrMmSuspendInd_OnPlmn),

#if (FEATURE_ON == FEATURE_DSDS)
    /* MSCC���͹�����ID_MSCC_MMC_SRV_ACQ_REQ */
    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_SRV_ACQ_REQ,
                      NAS_MMC_RcvMsccSrvAcqReq_L1Main),
#endif

    NAS_ACT_TBL_ITEM( WUEPS_PID_MM,
                      MMCMM_CM_SERVICE_IND,
                      NAS_MMC_RcvMmCmServiceInd_OnPlmn),

    NAS_ACT_TBL_ITEM( WUEPS_PID_MM,
                      MMCMM_PLMN_SEARCH_IND,
                      NAS_MMC_RcvMmPlmnSearchInd_OnPlmn),



    /* MM���͵��������� */
    NAS_ACT_TBL_ITEM( WUEPS_PID_MM,
                      MMCMM_RR_CONN_INFO_IND,
                      NAS_MMC_RcvMmRrConnInfoInd_OnPlmn),

    /* GMM���͵��������� */
    NAS_ACT_TBL_ITEM( WUEPS_PID_GMM,
                      MMCGMM_SIGNALING_STATUS_IND,
                      NAS_MMC_RcvGmmSignalingStatusInd_OnPlmn),

    NAS_ACT_TBL_ITEM( WUEPS_PID_GMM,
                      MMCGMM_TBF_REL_IND,
                      NAS_MMC_RcvGmmTbfRelInd_OnPlmn),

    NAS_ACT_TBL_ITEM( WUEPS_PID_MM,
                      MMCMM_RR_REL_IND,
                      NAS_MMC_RcvMmRrRelInd_OnPlmn),

    NAS_ACT_TBL_ITEM( WUEPS_PID_WRR,
                      RRMM_REL_IND,
                      NAS_MMC_RcvRrMmRelInd_OnPlmn),

    /* CSҵ���¿���Ч���������� */
    NAS_ACT_TBL_ITEM( WUEPS_PID_MM,
                      MMCMM_CM_SERVICE_REJECT_IND,
                      NAS_MMC_RcvCmServiceRejectInd_OnPlmn),

    /* PS��ע������Ϣ */
    NAS_ACT_TBL_ITEM( WUEPS_PID_GMM,
                      GMMMMC_PS_REG_RESULT_IND,
                      NAS_MMC_RcvPsRegResultInd_OnPlmn),

    /* CS��ע������Ϣ */
    NAS_ACT_TBL_ITEM( WUEPS_PID_MM,
                      MMMMC_CS_REG_RESULT_IND,
                      NAS_MMC_RcvCsRegResultInd_OnPlmn),

    /* �յ� MM Abort��Ϣ */
    NAS_ACT_TBL_ITEM( WUEPS_PID_MM,
                      MMMMC_ABORT_IND,
                      NAS_MMC_RcvMmAbortInd_OnPlmn),

    /*���緢���detach*/
    NAS_ACT_TBL_ITEM( WUEPS_PID_GMM,
                      MMCGMM_NETWORK_DETACH_IND,
                      NAS_MMC_RcvNetworkDetachInd_OnPlmn),

    /* available Timer��ʱ����ʱ */
    NAS_ACT_TBL_ITEM(VOS_PID_TIMER,
                     TI_NAS_MMC_AVAILABLE_TIMER,
                     NAS_MMC_RcvTiAvailTimerExpired_L1Main),

    NAS_ACT_TBL_ITEM( UEPS_PID_RRM,
                      ID_RRM_PS_STATUS_IND,
                      NAS_MMC_RcvRrmPsStatusInd_L1Main),

    /* AS�ϱ���ϵͳ��Ϣ */
    NAS_ACT_TBL_ITEM( WUEPS_PID_WRR,
                      RRMM_SYS_INFO_IND,
                      NAS_MMC_RcvRrMmSysInfo_OnPlmn),

    NAS_ACT_TBL_ITEM( UEPS_PID_GAS,
                      GRRMM_SYS_INFO_IND,
                      NAS_MMC_RcvGrrMmSysInfo_OnPlmn),

    NAS_ACT_TBL_ITEM( WUEPS_PID_GMM,
                      GMMMMC_SERVICE_REQUEST_RESULT_IND,
                      NAS_MMC_RcvGmmServiceRequestResultInd_OnPlmn),

    /* AS�ϱ���ǰ���� */
    NAS_ACT_TBL_ITEM( WUEPS_PID_WRR,
                      RRMM_AREA_LOST_IND,
                      NAS_MMC_RcvAreaLostInd_OnPlmn),

    NAS_ACT_TBL_ITEM( UEPS_PID_GAS,
                      RRMM_AREA_LOST_IND,
                      NAS_MMC_RcvAreaLostInd_OnPlmn),

    NAS_ACT_TBL_ITEM( VOS_PID_TIMER,
                      TI_NAS_MMC_CUSTOMIZED_FORB_LA_TIMER,
                      NAS_MMC_RcvCustomizedForbLaTimerExpired_OnPlmn),

    NAS_ACT_TBL_ITEM( VOS_PID_TIMER,
                      TI_NAS_MMC_FORBID_LA_TIMER,
                      NAS_MMC_RcvForbLaTimerExpired_OnPlmn ),

    /* ��ѡ״̬����ɽ���Ĵ��� */
    NAS_ACT_TBL_ITEM( WUEPS_PID_MMC,
                      MMCMMC_SUSPEND_RSLT_CNF,
                      NAS_MMC_RcvMmcMmcSuspendRslt_OnPlmn),

    NAS_ACT_TBL_ITEM( VOS_PID_TIMER,
                      TI_NAS_MMC_PERIOD_TRYING_INTER_PLMN_LIST,
                      NAS_MMC_RcvTiPeriodTryingInterPlmnListExpired_OnPlmn),



    /* �յ�HPLMN��ʱ����ʱ��Ϣ,���Խ��и����ȼ�/�������� */
    NAS_ACT_TBL_ITEM( VOS_PID_TIMER,
                      TI_NAS_MMC_HPLMN_TIMER,
                      NAS_MMC_RcvTiHplmnTimerExpired_OnPlmn),

    /* �յ�10s�����Գ��Ը����ȼ�������ʱ����ʱ��Ϣ�����Խ��и����ȼ�/�������� */
    NAS_ACT_TBL_ITEM( VOS_PID_TIMER,
                      TI_NAS_MMC_PERIOD_TRYING_HIGH_PRIO_PLMN_SEARCH,
                      NAS_MMC_RcvTiTryingHighPrioPlmnSearchExpired_OnPlmn),

    NAS_ACT_TBL_ITEM( VOS_PID_TIMER,
                      TI_NAS_MMC_HIGH_PRIO_RAT_HPLMN_TIMER,
                      NAS_MMC_RcvTiHighPrioRatHplmnSrchTimerExpired_OnPlmn),

    /* �յ�������״̬����ɽ�� */
    NAS_ACT_TBL_ITEM( WUEPS_PID_MMC,
                      MMCMMC_BG_PLMN_SEARCH_RSLT_CNF,
                      NAS_MMC_RcvBgPlmnSearchRsltCnf_OnPlmn),

    NAS_ACT_TBL_ITEM( WUEPS_PID_WRR,
                      RRMM_LIMIT_SERVICE_CAMP_IND,
                      NAS_MMC_RcvRrmmLimitServiceCampInd_OnPlmn),

#if (FEATURE_MULTI_MODEM == FEATURE_ON)
    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_NCELL_INFO_NOTIFY,
                      NAS_MMC_RcvMsccNcellInfoNotify_OnPlmn),
#endif

#if   (FEATURE_ON == FEATURE_LTE)

    NAS_ACT_TBL_ITEM( PS_PID_MM,
                      ID_LMM_MMC_DETACH_CNF,
                      NAS_MMC_RcvLmmDetachCnf_L1Main),

    /* �յ�Lģ��ϵͳ��Ϣ�Ĵ��� */
    NAS_ACT_TBL_ITEM( PS_PID_MM,
                      ID_LMM_MMC_SYS_INFO_IND,
                      NAS_MMC_RcvLSysInfoInd_OnPlmn),

    /* Lģע��Ĺ����л��յ��������Ӵ��ڵı�־��Ҫ���� */
    NAS_ACT_TBL_ITEM( PS_PID_MM,
                      ID_LMM_MMC_STATUS_IND,
                      NAS_MMC_RcvLmmMmcStatusInd_OnPlmn),

    /* attach ind */
    NAS_ACT_TBL_ITEM( PS_PID_MM,
                      ID_LMM_MMC_ATTACH_IND,
                      NAS_MMC_RcvLmmMmcAttachInd_OnPlmn),
    /* tau ind */
    NAS_ACT_TBL_ITEM( PS_PID_MM,
                      ID_LMM_MMC_TAU_RESULT_IND,
                      NAS_MMC_RcvLmmMmcTauResultInd_OnPlmn),

    /* detach����ȷ�� */
    NAS_ACT_TBL_ITEM( PS_PID_MM,
                      ID_LMM_MMC_DETACH_IND,
                      NAS_MMC_RcvLmmMmcDetachInd_OnPlmn),

    /* Service ind:ID_LMM_MMC_SERVICE_RESULT_IND */
    NAS_ACT_TBL_ITEM( PS_PID_MM,
                      ID_LMM_MMC_SERVICE_RESULT_IND,
                      NAS_MMC_RcvLmmMmcServiceRsltInd_OnPlmn),

    /* �յ�Lģ�Ķ�����Ϣ�Ĵ��� */
    NAS_ACT_TBL_ITEM( PS_PID_MM,
                      ID_LMM_MMC_AREA_LOST_IND,
                      NAS_MMC_RcvLmmAreaLostInd_OnPlmn),

    /* �յ�LMM����ϵͳ��ѡ��Ϣ,����suspend״̬�� */
    NAS_ACT_TBL_ITEM( PS_PID_MM,
                      ID_LMM_MMC_SUSPEND_IND,
                      NAS_MMC_RcvLmmMmcSuspendInd_OnPlmn),


    NAS_ACT_TBL_ITEM( PS_PID_MM,
                      ID_LMM_MMC_ATTACH_CNF,
                      NAS_MMC_RcvLmmAttachCnf_L1Main),

#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)
    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_CL_ASSOCIATED_INFO_NTF,
                      NAS_MMC_RcvMsccCLAssociatedInfoNtf_OnPlmn),
#endif

#endif

    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_IMS_VOICE_CAP_NOTIFY,
                      NAS_MMC_RcvMsccImsVoiceCapInd_OnPlmn),

#if (FEATURE_IMS == FEATURE_ON)
    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_IMS_SWITCH_STATE_IND,
                      NAS_MMC_RcvMsccImsSwitchStateInd_OnPlmn ),
#endif

    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_VOICE_DOMAIN_CHANGE_IND,
                      NAS_MMC_RcvMsccVoiceDomainChangeInd_OnPlmn ),

};

/* NAS_MMC_L1_STA_OOC������ */
NAS_ACT_STRU   g_astNasMmcOOCActTbl[]   =
{
    /* �û����������� */
    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_POWER_OFF_REQ,
                      NAS_MMC_RcvPowerOffReq_L1Main),

    NAS_ACT_TBL_ITEM( WUEPS_PID_MMC,
                      MMCMMC_POWER_OFF_RSLT_CNF,
                      NAS_MMC_RcvPowerOffRslt_L1Main),

    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_SYS_CFG_SET_REQ,
                      NAS_MMC_RcvSysCfgReq_L1Main),

    NAS_ACT_TBL_ITEM( WUEPS_PID_MMC,
                      MMCMMC_SYSCFG_RSLT_CNF,
                      NAS_MMC_RcvSyscfgRsltCnf_L1Main),

    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_PLMN_LIST_REQ,
                      NAS_MMC_RcvTafPlmnListReq_L1Main),

#if (FEATURE_ON == FEATURE_CSG)
    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_CSG_LIST_SEARCH_REQ,
                      NAS_MMC_RcvMsccCsgListSearchReq_L1Main),

    NAS_ACT_TBL_ITEM( VOS_PID_TIMER,
                      TI_NAS_MMC_PERIOD_TRYING_USER_CSG_LIST_SEARCH,
                      NAS_MMC_RcvTiPeriodTryingUserCsgListExpired_L1Main),
#endif
    /* MSCC���͹����Ļ�ȡ���� */
    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_ACQ_REQ,
                      NAS_MMC_RcvMsccAcqReq_L1Main),

    /* MSCC���͹�������ע������ */
    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_REG_REQ,
                      NAS_MMC_RcvMsccRegReq_L1Main),

    /* MSCC���͹�����PowerSave���� */
    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_POWER_SAVE_REQ,
                      NAS_MMC_RcvMsccPowerSaveReq_L1Main),

    NAS_ACT_TBL_ITEM( VOS_PID_TIMER,
                      TI_NAS_MMC_PERIOD_TRYING_USER_PLMN_LIST,
                      NAS_MMC_RcvTiPeriodTryingUserPlmnListExpired_L1Main),

    NAS_ACT_TBL_ITEM( WUEPS_PID_MMC,
                      MMCMMC_PLMN_LIST_RSLT_CNF,
                      NAS_MMC_RcvMmcPlmnListRsltCnf_L1Main),

#if (FEATURE_ON == FEATURE_DSDS)
    /* MSCC���͹�����ID_MSCC_MMC_SRV_ACQ_REQ */
    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_SRV_ACQ_REQ,
                      NAS_MMC_RcvMsccSrvAcqReq_L1Main),
#endif

    NAS_ACT_TBL_ITEM( WUEPS_PID_MM,
                      MMCMM_CM_SERVICE_IND,
                      NAS_MMC_RcvMmCmServiceInd_Ooc),

    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_PLMN_SPECIAL_REQ,
                      NAS_MMC_RcvPlmnSpecialReq_L1Main),

    /* available Timer��ʱ����ʱ */
    NAS_ACT_TBL_ITEM( VOS_PID_TIMER,
                      TI_NAS_MMC_AVAILABLE_TIMER,
                      NAS_MMC_RcvTiAvailTimerExpired_L1Main),

    NAS_ACT_TBL_ITEM( UEPS_PID_RRM,
                      ID_RRM_PS_STATUS_IND,
                      NAS_MMC_RcvRrmPsStatusInd_L1Main),

    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_PLMN_USER_RESEL_REQ,
                      NAS_MMC_RcvUserReselReq_L1Main),

#if (FEATURE_ON == FEATURE_LTE)
    NAS_ACT_TBL_ITEM( PS_PID_MM,
                      ID_LMM_MMC_DETACH_CNF,
                      NAS_MMC_RcvLmmDetachCnf_L1Main),

    NAS_ACT_TBL_ITEM( PS_PID_MM,
                      ID_LMM_MMC_ATTACH_CNF,
                      NAS_MMC_RcvLmmAttachCnf_L1Main),

    NAS_ACT_TBL_ITEM( PS_PID_MM,
                      ID_LMM_MMC_SERVICE_RESULT_IND,
                      NAS_MMC_RcvLmmMmcServiceRsltInd_OnPlmn),
#endif

#if (FEATURE_MULTI_MODEM == FEATURE_ON)
    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_NCELL_INFO_NOTIFY,
                      NAS_MMC_RcvMsccNcellInfoNotify_OnPlmn),
#endif

    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_PLMN_SEARCH_REQ,
                      NAS_MMC_RcvMsccPlmnSrchReq_Ooc),
};
/* In NAS_MMC_L1_STA_DEACT state, action table
   reference NAS_MMC_L1_STA_OOC��
*/
NAS_ACT_STRU g_astNasMmcDeactActTbl[]  =
{
    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_POWER_OFF_REQ,
                      NAS_MMC_RcvPowerOffReq_L1Main),

    NAS_ACT_TBL_ITEM( WUEPS_PID_MMC,
                      MMCMMC_POWER_OFF_RSLT_CNF,
                      NAS_MMC_RcvPowerOffRslt_L1Main),

    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_SYS_CFG_SET_REQ,
                      NAS_MMC_RcvSysCfgReq_L1Main),

    NAS_ACT_TBL_ITEM( WUEPS_PID_MMC,
                      MMCMMC_SYSCFG_RSLT_CNF,
                      NAS_MMC_RcvSyscfgRsltCnf_L1Main),

    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_PLMN_LIST_REQ,
                      NAS_MMC_RcvTafPlmnListReq_L1Main),


#if (FEATURE_ON == FEATURE_CSG)
    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_CSG_LIST_SEARCH_REQ,
                      NAS_MMC_RcvMsccCsgListSearchReq_L1Main),

    NAS_ACT_TBL_ITEM( VOS_PID_TIMER,
                      TI_NAS_MMC_PERIOD_TRYING_USER_CSG_LIST_SEARCH,
                      NAS_MMC_RcvTiPeriodTryingUserCsgListExpired_L1Main),

#endif
    /* MSCC���͹����Ļ�ȡ���� */
    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_ACQ_REQ,
                      NAS_MMC_RcvMsccAcqReq_L1Main),

    /* MSCC���͹�������ע������ */
    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_REG_REQ,
                      NAS_MMC_RcvMsccRegReq_L1Main),

    /* MSCC���͹�����PowerSave���� */
    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_POWER_SAVE_REQ,
                      NAS_MMC_RcvMsccPowerSaveReq_L1Main),

    NAS_ACT_TBL_ITEM( VOS_PID_TIMER,
                      TI_NAS_MMC_PERIOD_TRYING_USER_PLMN_LIST,
                      NAS_MMC_RcvTiPeriodTryingUserPlmnListExpired_L1Main),

    NAS_ACT_TBL_ITEM( WUEPS_PID_MMC,
                      MMCMMC_PLMN_LIST_RSLT_CNF,
                      NAS_MMC_RcvMmcPlmnListRsltCnf_L1Main),
#if (FEATURE_ON == FEATURE_DSDS)
    /* MSCC���͹�����ID_MSCC_MMC_SRV_ACQ_REQ */
    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_SRV_ACQ_REQ,
                      NAS_MMC_RcvMsccSrvAcqReq_L1Main),
#endif

    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_PLMN_SPECIAL_REQ,
                      NAS_MMC_RcvPlmnSpecialReq_L1Main),

    NAS_ACT_TBL_ITEM( UEPS_PID_RRM,
                      ID_RRM_PS_STATUS_IND,
                      NAS_MMC_RcvRrmPsStatusInd_L1Main_Deactive),

    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_PLMN_USER_RESEL_REQ,
                      NAS_MMC_RcvUserReselReq_L1Main),

#if (FEATURE_ON == FEATURE_LTE)
    NAS_ACT_TBL_ITEM( PS_PID_MM,
                      ID_LMM_MMC_DETACH_CNF,
                      NAS_MMC_RcvLmmDetachCnf_L1Main),

    NAS_ACT_TBL_ITEM( PS_PID_MM,
                      ID_LMM_MMC_ATTACH_CNF,
                      NAS_MMC_RcvLmmAttachCnf_L1Main),

    NAS_ACT_TBL_ITEM( PS_PID_MM,
                      ID_LMM_MMC_SERVICE_RESULT_IND,
                      NAS_MMC_RcvLmmMmcServiceRsltInd_OnPlmn),
#endif

#if (FEATURE_MULTI_MODEM == FEATURE_ON)
    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_NCELL_INFO_NOTIFY,
                      NAS_MMC_RcvMsccNcellInfoNotify_OnPlmn),
#endif

    NAS_ACT_TBL_ITEM( UEPS_PID_MSCC,
                      ID_MSCC_MMC_PLMN_SEARCH_REQ,
                      NAS_MMC_RcvMsccPlmnSrchReq_Deact),
#if (FEATURE_ON == FEATURE_LTE)
    NAS_ACT_TBL_ITEM( PS_PID_MM,
                      ID_LMM_MMC_RESUME_IND,
                      NAS_MMC_RcvLmmResumeInd_Deact),
#endif
};
NAS_STA_STRU g_astNasMmcL1MainStaTbl[] =
{
    /*****************���弰�ػ���������ʼ��״̬ת�Ʊ�**********************/
    NAS_STA_TBL_ITEM( NAS_MMC_L1_STA_NULL,
                      g_astNasMmcNullActTbl ),

    /*****************��������ע��״̬ת�Ʊ�**********************/
    NAS_STA_TBL_ITEM( NAS_MMC_L1_STA_INITIAL,
                      g_astNasMmcInitialActTbl ),

    /*****************������פ��������פ��ʱ���״̬ת�Ʊ�**********************/
    NAS_STA_TBL_ITEM( NAS_MMC_L1_STA_ON_PLMN,
                      g_astNasMmcOnPlmnActTbl ),

    /*****************���������κ�����ʱ���״̬ת�Ʊ�**********************/
    NAS_STA_TBL_ITEM( NAS_MMC_L1_STA_OOC,
                      g_astNasMmcOOCActTbl ),

    /*****************������DEACTIVE״̬ʱ���״̬ת�Ʊ�*********************/
    NAS_STA_TBL_ITEM( NAS_MMC_L1_STA_DEACT,
                      g_astNasMmcDeactActTbl ),
};


VOS_UINT32 NAS_MMC_GetL1MainStaTblSize( VOS_VOID  )
{
    return (sizeof(g_astNasMmcL1MainStaTbl)/sizeof(NAS_STA_STRU));
}


NAS_FSM_DESC_STRU * NAS_MMC_GetMainFsmDescAddr(VOS_VOID)
{
    return (&g_stNasMmcMainFsmDesc);
}

/*****************************************************************************
  3 ����ʵ��
*****************************************************************************/


#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif