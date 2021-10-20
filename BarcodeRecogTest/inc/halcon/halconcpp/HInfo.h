/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 19.05
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HINFO
#define HCPP_HINFO

namespace HalconCpp
{

// Class grouping system information related functionality.
class LIntExport HInfo
{

public:




  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Query slots concerning information with relation to the operator get_operator_info.
  static HTuple QueryOperatorInfo();

  // Query slots of the online-information concerning the operator get_param_info.
  static HTuple QueryParamInfo();

  // Get operators with the given string as a substring of their name.
  static HTuple GetOperatorName(const HString& Pattern);

  // Get operators with the given string as a substring of their name.
  static HTuple GetOperatorName(const char* Pattern);

#ifdef _WIN32
  // Get operators with the given string as a substring of their name.
  static HTuple GetOperatorName(const wchar_t* Pattern);
#endif

  // Get default data type for the control parameters of a HALCON-operator.
  static HTuple GetParamTypes(const HString& OperatorName, HTuple* OutpCtrlParType);

  // Get default data type for the control parameters of a HALCON-operator.
  static HTuple GetParamTypes(const char* OperatorName, HTuple* OutpCtrlParType);

#ifdef _WIN32
  // Get default data type for the control parameters of a HALCON-operator.
  static HTuple GetParamTypes(const wchar_t* OperatorName, HTuple* OutpCtrlParType);
#endif

  // Get number of the different parameter classes of a HALCON-operator.
  static HString GetParamNum(const HString& OperatorName, Hlong* InpObjPar, Hlong* OutpObjPar, Hlong* InpCtrlPar, Hlong* OutpCtrlPar, HString* Type);

  // Get number of the different parameter classes of a HALCON-operator.
  static HString GetParamNum(const char* OperatorName, Hlong* InpObjPar, Hlong* OutpObjPar, Hlong* InpCtrlPar, Hlong* OutpCtrlPar, HString* Type);

#ifdef _WIN32
  // Get number of the different parameter classes of a HALCON-operator.
  static HString GetParamNum(const wchar_t* OperatorName, Hlong* InpObjPar, Hlong* OutpObjPar, Hlong* InpCtrlPar, Hlong* OutpCtrlPar, HString* Type);
#endif

  // Get the names of the parameters of a HALCON-operator.
  static HTuple GetParamNames(const HString& OperatorName, HTuple* OutpObjPar, HTuple* InpCtrlPar, HTuple* OutpCtrlPar);

  // Get the names of the parameters of a HALCON-operator.
  static HTuple GetParamNames(const char* OperatorName, HTuple* OutpObjPar, HTuple* InpCtrlPar, HTuple* OutpCtrlPar);

#ifdef _WIN32
  // Get the names of the parameters of a HALCON-operator.
  static HTuple GetParamNames(const wchar_t* OperatorName, HTuple* OutpObjPar, HTuple* InpCtrlPar, HTuple* OutpCtrlPar);
#endif

  // Get information concerning a HALCON-operator.
  static HTuple GetOperatorInfo(const HString& OperatorName, const HString& Slot);

  // Get information concerning a HALCON-operator.
  static HTuple GetOperatorInfo(const char* OperatorName, const char* Slot);

#ifdef _WIN32
  // Get information concerning a HALCON-operator.
  static HTuple GetOperatorInfo(const wchar_t* OperatorName, const wchar_t* Slot);
#endif

  // Get information concerning the operator parameters.
  static HTuple GetParamInfo(const HString& OperatorName, const HString& ParamName, const HString& Slot);

  // Get information concerning the operator parameters.
  static HTuple GetParamInfo(const char* OperatorName, const char* ParamName, const char* Slot);

#ifdef _WIN32
  // Get information concerning the operator parameters.
  static HTuple GetParamInfo(const wchar_t* OperatorName, const wchar_t* ParamName, const wchar_t* Slot);
#endif

  // Search names of all operators assigned to one keyword.
  static HTuple SearchOperator(const HString& Keyword);

  // Search names of all operators assigned to one keyword.
  static HTuple SearchOperator(const char* Keyword);

#ifdef _WIN32
  // Search names of all operators assigned to one keyword.
  static HTuple SearchOperator(const wchar_t* Keyword);
#endif

  // Get keywords which are assigned to operators.
  static HTuple GetKeywords(const HString& OperatorName);

  // Get keywords which are assigned to operators.
  static HTuple GetKeywords(const char* OperatorName);

#ifdef _WIN32
  // Get keywords which are assigned to operators.
  static HTuple GetKeywords(const wchar_t* OperatorName);
#endif

  // Get information concerning the chapters on operators.
  static HTuple GetChapterInfo(const HTuple& Chapter);

  // Get information concerning the chapters on operators.
  static HTuple GetChapterInfo(const HString& Chapter);

  // Get information concerning the chapters on operators.
  static HTuple GetChapterInfo(const char* Chapter);

#ifdef _WIN32
  // Get information concerning the chapters on operators.
  static HTuple GetChapterInfo(const wchar_t* Chapter);
#endif

  // Query all available window types.
  static HTuple QueryWindowType();

  // Get the output treatment of an image matrix.
  static HString GetComprise(const HWindow& WindowHandle);

  // Query the region display modes.
  static HTuple QueryShape();

  // Query the possible line widths.
  static void QueryLineWidth(Hlong* Min, Hlong* Max);

  // Query the number of colors for color output.
  static HTuple QueryColored();

  // Query information about the specified image acquisition interface.
  static HString InfoFramegrabber(const HString& Name, const HString& Query, HTuple* ValueList);

  // Query information about the specified image acquisition interface.
  static HString InfoFramegrabber(const char* Name, const char* Query, HTuple* ValueList);

#ifdef _WIN32
  // Query information about the specified image acquisition interface.
  static HString InfoFramegrabber(const wchar_t* Name, const wchar_t* Query, HTuple* ValueList);
#endif

};

}

#endif