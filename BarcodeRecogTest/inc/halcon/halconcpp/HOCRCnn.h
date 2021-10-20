/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 19.05
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HOCRCNN
#define HCPP_HOCRCNN

namespace HalconCpp
{

// Represents an instance of a CNN OCR classifier.
class LIntExport HOCRCnn : public HHandle
{

public:

  // Create an uninitialized instance
  HOCRCnn():HHandle() {}

  // Copy constructor
  HOCRCnn(const HOCRCnn& source) : HHandle(source) {}

  // Copy constructor
  HOCRCnn(const HHandle& handle);

  // Create HOCRCnn from handle, taking ownership
  explicit HOCRCnn(Hlong handle);

  bool operator==(const HHandle& obj) const
  {
    return HHandleBase::operator==(obj);
  }

  bool operator!=(const HHandle& obj) const
  {
    return HHandleBase::operator!=(obj);
  }

protected:

  // Verify matching semantic type ('ocr_cnn')!
  virtual void AssertType(Hphandle handle) const;

public:

  // Deep copy of all data represented by this object instance
  HOCRCnn Clone() const;



/*****************************************************************************
 * Operator-based class constructors
 *****************************************************************************/

  // read_ocr_class_cnn: Read an CNN-based OCR classifier from a file.
  explicit HOCRCnn(const HString& FileName);

  // read_ocr_class_cnn: Read an CNN-based OCR classifier from a file.
  explicit HOCRCnn(const char* FileName);

#ifdef _WIN32
  // read_ocr_class_cnn: Read an CNN-based OCR classifier from a file.
  explicit HOCRCnn(const wchar_t* FileName);
#endif




  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Clear an CNN-based OCR classifier.
  static void ClearOcrClassCnn(const HOCRCnnArray& OCRHandle);

  // Clear an CNN-based OCR classifier.
  void ClearOcrClassCnn() const;

  // Deserialize a serialized CNN-based OCR classifier.
  void DeserializeOcrClassCnn(const HSerializedItem& SerializedItemHandle);

  // Classify multiple characters with an CNN-based OCR classifier.
  HTuple DoOcrMultiClassCnn(const HRegion& Character, const HImage& Image, HTuple* Confidence) const;

  // Classify multiple characters with an CNN-based OCR classifier.
  HString DoOcrMultiClassCnn(const HRegion& Character, const HImage& Image, double* Confidence) const;

  // Classify a single character with an CNN-based OCR classifier.
  HTuple DoOcrSingleClassCnn(const HRegion& Character, const HImage& Image, const HTuple& Num, HTuple* Confidence) const;

  // Classify a single character with an CNN-based OCR classifier.
  HString DoOcrSingleClassCnn(const HRegion& Character, const HImage& Image, const HTuple& Num, double* Confidence) const;

  // Classify a related group of characters with an CNN-based OCR classifier.
  HTuple DoOcrWordCnn(const HRegion& Character, const HImage& Image, const HString& Expression, Hlong NumAlternatives, Hlong NumCorrections, HTuple* Confidence, HString* Word, double* Score) const;

  // Classify a related group of characters with an CNN-based OCR classifier.
  HString DoOcrWordCnn(const HRegion& Character, const HImage& Image, const HString& Expression, Hlong NumAlternatives, Hlong NumCorrections, double* Confidence, HString* Word, double* Score) const;

  // Classify a related group of characters with an CNN-based OCR classifier.
  HString DoOcrWordCnn(const HRegion& Character, const HImage& Image, const char* Expression, Hlong NumAlternatives, Hlong NumCorrections, double* Confidence, HString* Word, double* Score) const;

#ifdef _WIN32
  // Classify a related group of characters with an CNN-based OCR classifier.
  HString DoOcrWordCnn(const HRegion& Character, const HImage& Image, const wchar_t* Expression, Hlong NumAlternatives, Hlong NumCorrections, double* Confidence, HString* Word, double* Score) const;
#endif

  // Return the parameters of a CNN-based OCR classifier.
  HTuple GetParamsOcrClassCnn(const HTuple& GenParamName) const;

  // Return the parameters of a CNN-based OCR classifier.
  HTuple GetParamsOcrClassCnn(const HString& GenParamName) const;

  // Return the parameters of a CNN-based OCR classifier.
  HTuple GetParamsOcrClassCnn(const char* GenParamName) const;

#ifdef _WIN32
  // Return the parameters of a CNN-based OCR classifier.
  HTuple GetParamsOcrClassCnn(const wchar_t* GenParamName) const;
#endif

  // Get the names of the parameters that can be used in get_params_ocr_class_cnn for a given CNN-based OCR classifier.
  HTuple QueryParamsOcrClassCnn() const;

  // Read an CNN-based OCR classifier from a file.
  void ReadOcrClassCnn(const HString& FileName);

  // Read an CNN-based OCR classifier from a file.
  void ReadOcrClassCnn(const char* FileName);

#ifdef _WIN32
  // Read an CNN-based OCR classifier from a file.
  void ReadOcrClassCnn(const wchar_t* FileName);
#endif

  // Serialize a CNN-based OCR classifier
  HSerializedItem SerializeOcrClassCnn() const;

};

// forward declarations and types for internal array implementation

template<class T> class HSmartPtr;
template<class T> class HHandleBaseArrayRef;

typedef HHandleBaseArrayRef<HOCRCnn> HOCRCnnArrayRef;
typedef HSmartPtr< HOCRCnnArrayRef > HOCRCnnArrayPtr;


// Represents multiple tool instances
class LIntExport HOCRCnnArray : public HHandleBaseArray
{

public:

  // Create empty array
  HOCRCnnArray();

  // Create array from native array of tool instances
  HOCRCnnArray(HOCRCnn* classes, Hlong length);

  // Copy constructor
  HOCRCnnArray(const HOCRCnnArray &tool_array);

  // Destructor
  virtual ~HOCRCnnArray();

  // Assignment operator
  HOCRCnnArray &operator=(const HOCRCnnArray &tool_array);

  // Clears array and all tool instances
  virtual void Clear();

  // Get array of native tool instances
  const HOCRCnn* Tools() const;

  // Get number of tools
  virtual Hlong Length() const;

  // Create tool array from tuple of handles
  virtual void SetFromTuple(const HTuple& handles);

  // Get tuple of handles for tool array
  virtual HTuple ConvertToTuple() const;

protected:

// Smart pointer to internal data container
   HOCRCnnArrayPtr *mArrayPtr;
};

}

#endif
