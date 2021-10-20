/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 19.05
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HDLCLASSIFIER
#define HCPP_HDLCLASSIFIER

namespace HalconCpp
{

// Represents an instance of a Deep Neural Network.
class LIntExport HDlClassifier : public HHandle
{

public:

  // Create an uninitialized instance
  HDlClassifier():HHandle() {}

  // Copy constructor
  HDlClassifier(const HDlClassifier& source) : HHandle(source) {}

  // Copy constructor
  HDlClassifier(const HHandle& handle);

  // Create HDlClassifier from handle, taking ownership
  explicit HDlClassifier(Hlong handle);

  bool operator==(const HHandle& obj) const
  {
    return HHandleBase::operator==(obj);
  }

  bool operator!=(const HHandle& obj) const
  {
    return HHandleBase::operator!=(obj);
  }

protected:

  // Verify matching semantic type ('dl_classifier')!
  virtual void AssertType(Hphandle handle) const;

public:

  // Deep copy of all data represented by this object instance
  HDlClassifier Clone() const;



/*****************************************************************************
 * Operator-based class constructors
 *****************************************************************************/

  // read_dl_classifier: Read a deep-learning-based classifier from a file.
  explicit HDlClassifier(const HString& FileName);

  // read_dl_classifier: Read a deep-learning-based classifier from a file.
  explicit HDlClassifier(const char* FileName);

#ifdef _WIN32
  // read_dl_classifier: Read a deep-learning-based classifier from a file.
  explicit HDlClassifier(const wchar_t* FileName);
#endif




  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Infer the class affiliations for a set of images using a  deep-learning-based classifier.
  HDlClassifierResult ApplyDlClassifier(const HImage& Images) const;

  // Clear a deep-learning-based classifier.
  static void ClearDlClassifier(const HDlClassifierArray& DLClassifierHandle);

  // Clear a deep-learning-based classifier.
  void ClearDlClassifier() const;

  // Deserialize a deep-learning-based classifier.
  void DeserializeDlClassifier(const HSerializedItem& SerializedItemHandle);

  // Return the parameters of a deep-learning-based classifier.
  HTuple GetDlClassifierParam(const HTuple& GenParamName) const;

  // Return the parameters of a deep-learning-based classifier.
  HTuple GetDlClassifierParam(const HString& GenParamName) const;

  // Return the parameters of a deep-learning-based classifier.
  HTuple GetDlClassifierParam(const char* GenParamName) const;

#ifdef _WIN32
  // Return the parameters of a deep-learning-based classifier.
  HTuple GetDlClassifierParam(const wchar_t* GenParamName) const;
#endif

  // Read a deep-learning-based classifier from a file.
  void ReadDlClassifier(const HString& FileName);

  // Read a deep-learning-based classifier from a file.
  void ReadDlClassifier(const char* FileName);

#ifdef _WIN32
  // Read a deep-learning-based classifier from a file.
  void ReadDlClassifier(const wchar_t* FileName);
#endif

  // Serialize a deep-learning-based classifier.
  HSerializedItem SerializeDlClassifier() const;

  // Set the parameters of a deep-learning-based classifier.
  void SetDlClassifierParam(const HTuple& GenParamName, const HTuple& GenParamValue) const;

  // Set the parameters of a deep-learning-based classifier.
  void SetDlClassifierParam(const HString& GenParamName, const HString& GenParamValue) const;

  // Set the parameters of a deep-learning-based classifier.
  void SetDlClassifierParam(const char* GenParamName, const char* GenParamValue) const;

#ifdef _WIN32
  // Set the parameters of a deep-learning-based classifier.
  void SetDlClassifierParam(const wchar_t* GenParamName, const wchar_t* GenParamValue) const;
#endif

  // Write a deep-learning-based classifier in a file.
  void WriteDlClassifier(const HString& FileName) const;

  // Write a deep-learning-based classifier in a file.
  void WriteDlClassifier(const char* FileName) const;

#ifdef _WIN32
  // Write a deep-learning-based classifier in a file.
  void WriteDlClassifier(const wchar_t* FileName) const;
#endif

};

// forward declarations and types for internal array implementation

template<class T> class HSmartPtr;
template<class T> class HHandleBaseArrayRef;

typedef HHandleBaseArrayRef<HDlClassifier> HDlClassifierArrayRef;
typedef HSmartPtr< HDlClassifierArrayRef > HDlClassifierArrayPtr;


// Represents multiple tool instances
class LIntExport HDlClassifierArray : public HHandleBaseArray
{

public:

  // Create empty array
  HDlClassifierArray();

  // Create array from native array of tool instances
  HDlClassifierArray(HDlClassifier* classes, Hlong length);

  // Copy constructor
  HDlClassifierArray(const HDlClassifierArray &tool_array);

  // Destructor
  virtual ~HDlClassifierArray();

  // Assignment operator
  HDlClassifierArray &operator=(const HDlClassifierArray &tool_array);

  // Clears array and all tool instances
  virtual void Clear();

  // Get array of native tool instances
  const HDlClassifier* Tools() const;

  // Get number of tools
  virtual Hlong Length() const;

  // Create tool array from tuple of handles
  virtual void SetFromTuple(const HTuple& handles);

  // Get tuple of handles for tool array
  virtual HTuple ConvertToTuple() const;

protected:

// Smart pointer to internal data container
   HDlClassifierArrayPtr *mArrayPtr;
};

}

#endif
