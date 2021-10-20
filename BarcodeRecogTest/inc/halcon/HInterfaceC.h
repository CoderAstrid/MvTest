/*****************************************************************************
 * HInterfaceC.h
 *****************************************************************************
 *
 * Project:      HALCON/HLib
 * Description:  Prototypes for HALCON/C interface
 *
 * (c) 1996-2019 by MVTec Software GmbH
 *                  www.mvtec.com
 *
 *****************************************************************************/

#ifndef HINTERFACE_C_H
#define HINTERFACE_C_H

/*===========================================================================*/
/*                             Defines                                      */
/*===========================================================================*/


/*===========================================================================*/
/*                             Prototypes                                    */
/*===========================================================================*/
extern LIntExport Herror HcErrorHandling(Hproc_handle ph, Herror err);

extern LIntExport Herror HcException(HINT op_id, Herror err);

extern LIntExport Herror HcPreCall(HINT proc_index, Hproc_handle* ph);

extern LIntExport Herror HcCall(Hproc_handle ph);

extern LIntExport Herror HcPostCall(Hproc_handle ph, Herror err);

extern LIntExport Herror HcStoreIO(Hproc_handle ph, HINT par,
                                   Hobject inObjVar);

extern LIntExport Herror HcStoreICL(Hproc_handle ph, HINT par, Hlong value);

extern LIntExport Herror HcStoreICD(Hproc_handle ph, HINT par, double value);

extern LIntExport Herror HcStoreICS(Hproc_handle ph, HINT par,
                                    char const* value);
extern LIntExport Herror HcStoreICSEnc(Hproc_handle ph, HINT par,
                                       char const* value);

extern LIntExport Herror HcStoreICT(Hproc_handle ph, HINT par,
                                    Htuple const* value);
extern LIntExport Herror HcStoreICTEnc(Hproc_handle ph, HINT par,
                                       Htuple const* value);


#define HcInitOCL(PH, PAR, PLONG)                                             \
  do                                                                          \
  {                                                                           \
    HWriteGV_OutpCtrlStack_p(PH, PARNR, &HGetGV_OutpCtrlNested(PH, PAR);      \
  } while (0)

#define HcInitOCD(PH, PAR, PLONG)                                             \
  do                                                                          \
  {                                                                           \
    HWriteGV_OutpCtrlStack_p(PH, PARNR, &HGetGV_OutpCtrlNested(PH, PAR);      \
  } while (0)

#define HcInitOCS(PH, PAR, PLONG)                                             \
  do                                                                          \
  {                                                                           \
    HWriteGV_OutpCtrlStack_p(PH, PARNR, &HGetGV_OutpCtrlNested(PH, PAR);      \
  } while (0)


#define HcInitOCT(PH, PAR, PHTUPLE)                                           \
  do                                                                          \
  {                                                                           \
    HCT_INIT((Hctuple*)(PHTUPLE));                                            \
    HWriteGV_OutpCtrlList_p(PH, PAR, PHTUPLE);                                \
  } while (0)


extern LIntExport Herror HcStoreOO(Hproc_handle ph, HINT par,
                                   Hobject* outObjVar, Herror err);

extern LIntExport Herror HcStoreOCL(Hproc_handle ph, HINT par,
                                    Hlong* outCtrlVar, Herror err);

extern LIntExport Herror HcStoreOCD(Hproc_handle ph, HINT par,
                                    double* outCtrlVar, Herror err);

extern LIntExport Herror HcStoreOCS(Hproc_handle ph, HINT par,
                                    char* outCtrlVar, Herror err);

extern LIntExport Herror HcStoreOCSEnc(Hproc_handle ph, HINT par,
                                       char* outCtrlVar, Herror err);

extern LIntExport Herror HcStoreOCT(Hproc_handle ph, HINT par,
                                    Htuple* outCtrlVar, Herror err);

extern LIntExport Herror HcStoreOCTEnc(Hproc_handle ph, HINT par,
                                       Htuple* outCtrlVar, Herror err);

#endif
