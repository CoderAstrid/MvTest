/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 19.05
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HDRAWINGOBJECT
#define HCPP_HDRAWINGOBJECT

namespace HalconCpp
{

// Represents an instance of a drawing object.
class LIntExport HDrawingObject : public HHandle
{

public:

  // Create an uninitialized instance
  HDrawingObject():HHandle() {}

  // Copy constructor
  HDrawingObject(const HDrawingObject& source) : HHandle(source) {}

  // Copy constructor
  HDrawingObject(const HHandle& handle);

  // Create HDrawingObject from handle, taking ownership
  explicit HDrawingObject(Hlong handle);

  bool operator==(const HHandle& obj) const
  {
    return HHandleBase::operator==(obj);
  }

  bool operator!=(const HHandle& obj) const
  {
    return HHandleBase::operator!=(obj);
  }

protected:

  // Verify matching semantic type ('drawing_object')!
  virtual void AssertType(Hphandle handle) const;

public:



/*****************************************************************************
 * Operator-based class constructors
 *****************************************************************************/

  // create_drawing_object_circle: Create a circle which can be modified interactively.
  explicit HDrawingObject(double Row, double Column, double Radius);

  // create_drawing_object_rectangle2: Create a rectangle of any orientation which can be modified interactively.
  explicit HDrawingObject(double Row, double Column, double Phi, double Length1, double Length2);

  // create_drawing_object_rectangle1: Create a rectangle parallel to the coordinate axis which can be modified interactively.
  explicit HDrawingObject(double Row1, double Column1, double Row2, double Column2);




  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Add a callback function to a drawing object.
  void SetDrawingObjectCallback(const HTuple& DrawObjectEvent, const HTuple& CallbackFunction) const;

  // Add a callback function to a drawing object.
  void SetDrawingObjectCallback(const HString& DrawObjectEvent, void* CallbackFunction) const;

  // Add a callback function to a drawing object.
  void SetDrawingObjectCallback(const char* DrawObjectEvent, void* CallbackFunction) const;

#ifdef _WIN32
  // Add a callback function to a drawing object.
  void SetDrawingObjectCallback(const wchar_t* DrawObjectEvent, void* CallbackFunction) const;
#endif

  // Detach the background image from a HALCON window.
  static void DetachBackgroundFromWindow(const HWindow& WindowHandle);

  // Attach a background image to a HALCON window.
  static void AttachBackgroundToWindow(const HImage& Image, const HWindow& WindowHandle);

  // Create a text object which can be moved interactively.
  void CreateDrawingObjectText(Hlong Row, Hlong Column, const HString& String);

  // Create a text object which can be moved interactively.
  void CreateDrawingObjectText(Hlong Row, Hlong Column, const char* String);

#ifdef _WIN32
  // Create a text object which can be moved interactively.
  void CreateDrawingObjectText(Hlong Row, Hlong Column, const wchar_t* String);
#endif

  // Return the iconic object of a drawing object.
  HObject GetDrawingObjectIconic() const;

  // Delete drawing object.
  void ClearDrawingObject() const;

  // Set the parameters of a drawing object.
  void SetDrawingObjectParams(const HTuple& GenParamName, const HTuple& GenParamValue) const;

  // Set the parameters of a drawing object.
  void SetDrawingObjectParams(const HString& GenParamName, double GenParamValue) const;

  // Set the parameters of a drawing object.
  void SetDrawingObjectParams(const char* GenParamName, double GenParamValue) const;

#ifdef _WIN32
  // Set the parameters of a drawing object.
  void SetDrawingObjectParams(const wchar_t* GenParamName, double GenParamValue) const;
#endif

  // Get the parameters of a drawing object.
  HTuple GetDrawingObjectParams(const HTuple& GenParamName) const;

  // Get the parameters of a drawing object.
  HTuple GetDrawingObjectParams(const HString& GenParamName) const;

  // Get the parameters of a drawing object.
  HTuple GetDrawingObjectParams(const char* GenParamName) const;

#ifdef _WIN32
  // Get the parameters of a drawing object.
  HTuple GetDrawingObjectParams(const wchar_t* GenParamName) const;
#endif

  // Set the contour of an interactive draw XLD.
  void SetDrawingObjectXld(const HXLDCont& Contour) const;

  // Create a XLD contour which can be modified interactively.
  void CreateDrawingObjectXld(const HTuple& Row, const HTuple& Column);

  // Create a circle sector which can be modified interactively.
  void CreateDrawingObjectCircleSector(double Row, double Column, double Radius, double StartAngle, double EndAngle);

  // Create an elliptic sector which can be modified interactively.
  void CreateDrawingObjectEllipseSector(double Row, double Column, double Phi, double Radius1, double Radius2, double StartAngle, double EndAngle);

  // Create a line which can be modified interactively.
  void CreateDrawingObjectLine(double Row1, double Column1, double Row2, double Column2);

  // Create a circle which can be modified interactively.
  void CreateDrawingObjectCircle(double Row, double Column, double Radius);

  // Create an ellipse which can be modified interactively.
  void CreateDrawingObjectEllipse(double Row, double Column, double Phi, double Radius1, double Radius2);

  // Create a rectangle of any orientation which can be modified interactively.
  void CreateDrawingObjectRectangle2(double Row, double Column, double Phi, double Length1, double Length2);

  // Create a rectangle parallel to the coordinate axis which can be modified interactively.
  void CreateDrawingObjectRectangle1(double Row1, double Column1, double Row2, double Column2);

  // Send an event to a buffer window signaling a mouse double click event.
  static HString SendMouseDoubleClickEvent(const HWindow& WindowHandle, const HTuple& Row, const HTuple& Column, Hlong Button);

  // Send an event to a buffer window signaling a mouse double click event.
  static HString SendMouseDoubleClickEvent(const HWindow& WindowHandle, Hlong Row, Hlong Column, Hlong Button);

  // Send an event to a window buffer signaling a mouse down event.
  static HString SendMouseDownEvent(const HWindow& WindowHandle, const HTuple& Row, const HTuple& Column, Hlong Button);

  // Send an event to a window buffer signaling a mouse down event.
  static HString SendMouseDownEvent(const HWindow& WindowHandle, Hlong Row, Hlong Column, Hlong Button);

  // Send an event to a buffer window signaling a mouse drag event.
  static HString SendMouseDragEvent(const HWindow& WindowHandle, const HTuple& Row, const HTuple& Column, Hlong Button);

  // Send an event to a buffer window signaling a mouse drag event.
  static HString SendMouseDragEvent(const HWindow& WindowHandle, Hlong Row, Hlong Column, Hlong Button);

  // Send an event to a buffer window signaling a mouse up event.
  static HString SendMouseUpEvent(const HWindow& WindowHandle, const HTuple& Row, const HTuple& Column, Hlong Button);

  // Send an event to a buffer window signaling a mouse up event.
  static HString SendMouseUpEvent(const HWindow& WindowHandle, Hlong Row, Hlong Column, Hlong Button);

};

// forward declarations and types for internal array implementation

template<class T> class HSmartPtr;
template<class T> class HHandleBaseArrayRef;

typedef HHandleBaseArrayRef<HDrawingObject> HDrawingObjectArrayRef;
typedef HSmartPtr< HDrawingObjectArrayRef > HDrawingObjectArrayPtr;


// Represents multiple tool instances
class LIntExport HDrawingObjectArray : public HHandleBaseArray
{

public:

  // Create empty array
  HDrawingObjectArray();

  // Create array from native array of tool instances
  HDrawingObjectArray(HDrawingObject* classes, Hlong length);

  // Copy constructor
  HDrawingObjectArray(const HDrawingObjectArray &tool_array);

  // Destructor
  virtual ~HDrawingObjectArray();

  // Assignment operator
  HDrawingObjectArray &operator=(const HDrawingObjectArray &tool_array);

  // Clears array and all tool instances
  virtual void Clear();

  // Get array of native tool instances
  const HDrawingObject* Tools() const;

  // Get number of tools
  virtual Hlong Length() const;

  // Create tool array from tuple of handles
  virtual void SetFromTuple(const HTuple& handles);

  // Get tuple of handles for tool array
  virtual HTuple ConvertToTuple() const;

protected:

// Smart pointer to internal data container
   HDrawingObjectArrayPtr *mArrayPtr;
};

}

#endif
