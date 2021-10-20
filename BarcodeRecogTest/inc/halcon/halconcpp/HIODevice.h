/***********************************************************
 * File generated by the HALCON-Compiler hcomp version 19.05
 * Usage: Interface to C++
 *
 * Software by: MVTec Software GmbH, www.mvtec.com
 ***********************************************************/


#ifndef HCPP_HIODEVICE
#define HCPP_HIODEVICE

namespace HalconCpp
{

// Represents an instance of an I/O device.
class LIntExport HIODevice : public HHandle
{

public:

  // Create an uninitialized instance
  HIODevice():HHandle() {}

  // Copy constructor
  HIODevice(const HIODevice& source) : HHandle(source) {}

  // Copy constructor
  HIODevice(const HHandle& handle);

  // Create HIODevice from handle, taking ownership
  explicit HIODevice(Hlong handle);

  bool operator==(const HHandle& obj) const
  {
    return HHandleBase::operator==(obj);
  }

  bool operator!=(const HHandle& obj) const
  {
    return HHandleBase::operator!=(obj);
  }

protected:

  // Verify matching semantic type ('io_device')!
  virtual void AssertType(Hphandle handle) const;

public:



/*****************************************************************************
 * Operator-based class constructors
 *****************************************************************************/

  // open_io_device: Open and configure an I/O device. 
  explicit HIODevice(const HString& IOInterfaceName, const HTuple& IODeviceName, const HTuple& GenParamName, const HTuple& GenParamValue);

  // open_io_device: Open and configure an I/O device. 
  explicit HIODevice(const char* IOInterfaceName, const HTuple& IODeviceName, const HTuple& GenParamName, const HTuple& GenParamValue);

#ifdef _WIN32
  // open_io_device: Open and configure an I/O device. 
  explicit HIODevice(const wchar_t* IOInterfaceName, const HTuple& IODeviceName, const HTuple& GenParamName, const HTuple& GenParamValue);
#endif




  /***************************************************************************
   * Operators                                                               *
   ***************************************************************************/

  // Open and configure I/O channels.
  HIOChannelArray OpenIoChannel(const HTuple& IOChannelName, const HTuple& GenParamName, const HTuple& GenParamValue) const;

  // Open and configure I/O channels.
  HIOChannel OpenIoChannel(const HString& IOChannelName, const HTuple& GenParamName, const HTuple& GenParamValue) const;

  // Open and configure I/O channels.
  HIOChannel OpenIoChannel(const char* IOChannelName, const HTuple& GenParamName, const HTuple& GenParamValue) const;

#ifdef _WIN32
  // Open and configure I/O channels.
  HIOChannel OpenIoChannel(const wchar_t* IOChannelName, const HTuple& GenParamName, const HTuple& GenParamValue) const;
#endif

  // Query information about channels of the specified I/O device. 
  HTuple QueryIoDevice(const HTuple& IOChannelName, const HTuple& Query) const;

  // Query information about channels of the specified I/O device. 
  HTuple QueryIoDevice(const HString& IOChannelName, const HTuple& Query) const;

  // Query information about channels of the specified I/O device. 
  HTuple QueryIoDevice(const char* IOChannelName, const HTuple& Query) const;

#ifdef _WIN32
  // Query information about channels of the specified I/O device. 
  HTuple QueryIoDevice(const wchar_t* IOChannelName, const HTuple& Query) const;
#endif

  // Perform an action on the I/O device.
  HTuple ControlIoDevice(const HString& Action, const HTuple& Argument) const;

  // Perform an action on the I/O device.
  HTuple ControlIoDevice(const HString& Action, const HString& Argument) const;

  // Perform an action on the I/O device.
  HTuple ControlIoDevice(const char* Action, const char* Argument) const;

#ifdef _WIN32
  // Perform an action on the I/O device.
  HTuple ControlIoDevice(const wchar_t* Action, const wchar_t* Argument) const;
#endif

  // Configure a specific I/O device instance.
  void SetIoDeviceParam(const HTuple& GenParamName, const HTuple& GenParamValue) const;

  // Configure a specific I/O device instance.
  void SetIoDeviceParam(const HString& GenParamName, const HString& GenParamValue) const;

  // Configure a specific I/O device instance.
  void SetIoDeviceParam(const char* GenParamName, const char* GenParamValue) const;

#ifdef _WIN32
  // Configure a specific I/O device instance.
  void SetIoDeviceParam(const wchar_t* GenParamName, const wchar_t* GenParamValue) const;
#endif

  // Query settings of an I/O device instance. 
  HTuple GetIoDeviceParam(const HTuple& GenParamName) const;

  // Query settings of an I/O device instance. 
  HTuple GetIoDeviceParam(const HString& GenParamName) const;

  // Query settings of an I/O device instance. 
  HTuple GetIoDeviceParam(const char* GenParamName) const;

#ifdef _WIN32
  // Query settings of an I/O device instance. 
  HTuple GetIoDeviceParam(const wchar_t* GenParamName) const;
#endif

  // Close the specified I/O device. 
  void CloseIoDevice() const;

  // Open and configure an I/O device. 
  void OpenIoDevice(const HString& IOInterfaceName, const HTuple& IODeviceName, const HTuple& GenParamName, const HTuple& GenParamValue);

  // Open and configure an I/O device. 
  void OpenIoDevice(const char* IOInterfaceName, const HTuple& IODeviceName, const HTuple& GenParamName, const HTuple& GenParamValue);

#ifdef _WIN32
  // Open and configure an I/O device. 
  void OpenIoDevice(const wchar_t* IOInterfaceName, const HTuple& IODeviceName, const HTuple& GenParamName, const HTuple& GenParamValue);
#endif

  // Perform an action on the I/O interface.
  static HTuple ControlIoInterface(const HString& IOInterfaceName, const HString& Action, const HTuple& Argument);

  // Perform an action on the I/O interface.
  static HTuple ControlIoInterface(const HString& IOInterfaceName, const HString& Action, const HString& Argument);

  // Perform an action on the I/O interface.
  static HTuple ControlIoInterface(const char* IOInterfaceName, const char* Action, const char* Argument);

#ifdef _WIN32
  // Perform an action on the I/O interface.
  static HTuple ControlIoInterface(const wchar_t* IOInterfaceName, const wchar_t* Action, const wchar_t* Argument);
#endif

  // Query information about the specified I/O device interface.
  static HTuple QueryIoInterface(const HString& IOInterfaceName, const HTuple& Query);

  // Query information about the specified I/O device interface.
  static HTuple QueryIoInterface(const HString& IOInterfaceName, const HString& Query);

  // Query information about the specified I/O device interface.
  static HTuple QueryIoInterface(const char* IOInterfaceName, const char* Query);

#ifdef _WIN32
  // Query information about the specified I/O device interface.
  static HTuple QueryIoInterface(const wchar_t* IOInterfaceName, const wchar_t* Query);
#endif

};

// forward declarations and types for internal array implementation

template<class T> class HSmartPtr;
template<class T> class HHandleBaseArrayRef;

typedef HHandleBaseArrayRef<HIODevice> HIODeviceArrayRef;
typedef HSmartPtr< HIODeviceArrayRef > HIODeviceArrayPtr;


// Represents multiple tool instances
class LIntExport HIODeviceArray : public HHandleBaseArray
{

public:

  // Create empty array
  HIODeviceArray();

  // Create array from native array of tool instances
  HIODeviceArray(HIODevice* classes, Hlong length);

  // Copy constructor
  HIODeviceArray(const HIODeviceArray &tool_array);

  // Destructor
  virtual ~HIODeviceArray();

  // Assignment operator
  HIODeviceArray &operator=(const HIODeviceArray &tool_array);

  // Clears array and all tool instances
  virtual void Clear();

  // Get array of native tool instances
  const HIODevice* Tools() const;

  // Get number of tools
  virtual Hlong Length() const;

  // Create tool array from tuple of handles
  virtual void SetFromTuple(const HTuple& handles);

  // Get tuple of handles for tool array
  virtual HTuple ConvertToTuple() const;

protected:

// Smart pointer to internal data container
   HIODeviceArrayPtr *mArrayPtr;
};

}

#endif
