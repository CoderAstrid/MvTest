///////////////////////////////////////////////////////////////////////////////
// File generated by HDevelop for HALCON/C++ Version 19.05.0.0
// Non-ASCII strings in this file are encoded in UTF-8.
// 
// Please note that non-ASCII characters in string constants are exported
// as octal codes in order to guarantee that the strings are correctly
// created on all systems, independent on any compiler settings.
// 
// Source files with different encoding should not be mixed in one project.
///////////////////////////////////////////////////////////////////////////////




#ifndef __APPLE__
#  include "HalconCpp.h"
#  include "HDevThread.h"
#else
#  ifndef HC_LARGE_IMAGES
#    include <HALCONCpp/HalconCpp.h>
#    include <HALCONCpp/HDevThread.h>
#  else
#    include <HALCONCppxl/HalconCpp.h>
#    include <HALCONCppxl/HDevThread.h>
#  endif
#endif



using namespace HalconCpp;


// Chapter: Graphics / Text
// Short Description: Set font independent of OS 
void set_display_font (HTuple hv_WindowHandle, HTuple hv_Size, HTuple hv_Font, HTuple hv_Bold, 
    HTuple hv_Slant)
{

  // Local iconic variables

  // Local control variables
  HTuple  hv_OS, hv_Fonts, hv_Style, hv_Exception;
  HTuple  hv_AvailableFonts, hv_Fdx, hv_Indices;

  //This procedure sets the text font of the current window with
  //the specified attributes.
  //
  //Input parameters:
  //WindowHandle: The graphics window for which the font will be set
  //Size: The font size. If Size=-1, the default of 16 is used.
  //Bold: If set to 'true', a bold font is used
  //Slant: If set to 'true', a slanted font is used
  //
  GetSystem("operating_system", &hv_OS);
  if (0 != (HTuple(int(hv_Size==HTuple())).TupleOr(int(hv_Size==-1))))
  {
    hv_Size = 16;
  }
  if (0 != (int((hv_OS.TupleSubstr(0,2))==HTuple("Win"))))
  {
    //Restore previous behaviour
    hv_Size = (1.13677*hv_Size).TupleInt();
  }
  else
  {
    hv_Size = hv_Size.TupleInt();
  }
  if (0 != (int(hv_Font==HTuple("Courier"))))
  {
    hv_Fonts.Clear();
    hv_Fonts[0] = "Courier";
    hv_Fonts[1] = "Courier 10 Pitch";
    hv_Fonts[2] = "Courier New";
    hv_Fonts[3] = "CourierNew";
    hv_Fonts[4] = "Liberation Mono";
  }
  else if (0 != (int(hv_Font==HTuple("mono"))))
  {
    hv_Fonts.Clear();
    hv_Fonts[0] = "Consolas";
    hv_Fonts[1] = "Menlo";
    hv_Fonts[2] = "Courier";
    hv_Fonts[3] = "Courier 10 Pitch";
    hv_Fonts[4] = "FreeMono";
    hv_Fonts[5] = "Liberation Mono";
  }
  else if (0 != (int(hv_Font==HTuple("sans"))))
  {
    hv_Fonts.Clear();
    hv_Fonts[0] = "Luxi Sans";
    hv_Fonts[1] = "DejaVu Sans";
    hv_Fonts[2] = "FreeSans";
    hv_Fonts[3] = "Arial";
    hv_Fonts[4] = "Liberation Sans";
  }
  else if (0 != (int(hv_Font==HTuple("serif"))))
  {
    hv_Fonts.Clear();
    hv_Fonts[0] = "Times New Roman";
    hv_Fonts[1] = "Luxi Serif";
    hv_Fonts[2] = "DejaVu Serif";
    hv_Fonts[3] = "FreeSerif";
    hv_Fonts[4] = "Utopia";
    hv_Fonts[5] = "Liberation Serif";
  }
  else
  {
    hv_Fonts = hv_Font;
  }
  hv_Style = "";
  if (0 != (int(hv_Bold==HTuple("true"))))
  {
    hv_Style += HTuple("Bold");
  }
  else if (0 != (int(hv_Bold!=HTuple("false"))))
  {
    hv_Exception = "Wrong value of control parameter Bold";
    throw HException(hv_Exception);
  }
  if (0 != (int(hv_Slant==HTuple("true"))))
  {
    hv_Style += HTuple("Italic");
  }
  else if (0 != (int(hv_Slant!=HTuple("false"))))
  {
    hv_Exception = "Wrong value of control parameter Slant";
    throw HException(hv_Exception);
  }
  if (0 != (int(hv_Style==HTuple(""))))
  {
    hv_Style = "Normal";
  }
  QueryFont(hv_WindowHandle, &hv_AvailableFonts);
  hv_Font = "";
  {
  HTuple end_val48 = (hv_Fonts.TupleLength())-1;
  HTuple step_val48 = 1;
  for (hv_Fdx=0; hv_Fdx.Continue(end_val48, step_val48); hv_Fdx += step_val48)
  {
    hv_Indices = hv_AvailableFonts.TupleFind(HTuple(hv_Fonts[hv_Fdx]));
    if (0 != (int((hv_Indices.TupleLength())>0)))
    {
      if (0 != (int(HTuple(hv_Indices[0])>=0)))
      {
        hv_Font = HTuple(hv_Fonts[hv_Fdx]);
        break;
      }
    }
  }
  }
  if (0 != (int(hv_Font==HTuple(""))))
  {
    throw HException("Wrong value of control parameter Font");
  }
  hv_Font = (((hv_Font+"-")+hv_Style)+"-")+hv_Size;
  SetFont(hv_WindowHandle, hv_Font);
  return;
}
