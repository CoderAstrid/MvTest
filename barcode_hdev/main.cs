//
// File generated by HDevelop for HALCON/.NET (C#) Version 19.05.0.0
// Non-ASCII strings in this file are encoded in UTF-8.
// 
// Please note that non-ASCII characters in string constants are exported
// as octal codes in order to guarantee that the strings are correctly
// created on all systems, independent on any compiler settings.
// 
// Source files with different encoding should not be mixed in one project.
//

using HalconDotNet;

public partial class HDevelopExport
{
#if !(NO_EXPORT_MAIN || NO_EXPORT_APP_MAIN)
  public HDevelopExport()
  {
    // Default settings used in HDevelop
    HOperatorSet.SetSystem("width", 512);
    HOperatorSet.SetSystem("height", 512);
    if (HalconAPI.isWindows)
      HOperatorSet.SetSystem("use_window_thread","true");
    action();
  }
#endif

  // Procedures 
#if !NO_EXPORT_MAIN
  // Main procedure 
  private void action()
  {


    // Local iconic variables 

    HObject ho_Image, ho_SymbolRegions;

    // Local control variables 

    HTuple hv_BarCodeHandle = new HTuple(), hv_WindowHandle = new HTuple();
    HTuple hv_DecodedDataStrings = new HTuple(), hv_res = new HTuple();
    HTuple hv_Area = new HTuple(), hv_Row = new HTuple(), hv_Column = new HTuple();
    // Initialize local and output iconic variables 
    HOperatorSet.GenEmptyObj(out ho_Image);
    HOperatorSet.GenEmptyObj(out ho_SymbolRegions);
    try
    {
      //Read bar codes of type Code 128
      //
      hv_BarCodeHandle.Dispose();
      HOperatorSet.CreateBarCodeModel(new HTuple(), new HTuple(), out hv_BarCodeHandle);
      if (HDevWindowStack.IsOpen())
      {
        HOperatorSet.CloseWindow(HDevWindowStack.Pop());
      }
      HOperatorSet.SetWindowAttr("background_color","black");
      HOperatorSet.OpenWindow(0,0,600,600,0,"visible","",out hv_WindowHandle);
      HDevWindowStack.Push(hv_WindowHandle);
      set_display_font(hv_WindowHandle, 16, "mono", "true", "false");
      if (HDevWindowStack.IsOpen())
      {
        HOperatorSet.SetDraw(HDevWindowStack.GetActive(), "margin");
      }
      if (HDevWindowStack.IsOpen())
      {
        HOperatorSet.SetColor(HDevWindowStack.GetActive(), "green");
      }
      if (HDevWindowStack.IsOpen())
      {
        HOperatorSet.SetLineWidth(HDevWindowStack.GetActive(), 3);
      }
      ho_Image.Dispose();
      HOperatorSet.ReadImage(out ho_Image, "F:/Data/Barcode/test_error/20210817062009009.jpg");
      dev_resize_window_fit_image(ho_Image, 0, 0, -1, -1);
      ho_SymbolRegions.Dispose();hv_DecodedDataStrings.Dispose();
      HOperatorSet.FindBarCode(ho_Image, out ho_SymbolRegions, hv_BarCodeHandle, 
          "auto", out hv_DecodedDataStrings);
      hv_res.Dispose();
      HOperatorSet.GetBarCodeResult(hv_BarCodeHandle, 0, "decoded_types", out hv_res);
      hv_Area.Dispose();hv_Row.Dispose();hv_Column.Dispose();
      HOperatorSet.AreaCenter(ho_SymbolRegions, out hv_Area, out hv_Row, out hv_Column);
      if (HDevWindowStack.IsOpen())
      {
        HOperatorSet.DispObj(ho_Image, HDevWindowStack.GetActive());
      }
      if (HDevWindowStack.IsOpen())
      {
        HOperatorSet.DispObj(ho_SymbolRegions, HDevWindowStack.GetActive());
      }
      if (HDevWindowStack.IsOpen())
      {
        using (HDevDisposeHelper dh = new HDevDisposeHelper())
        {
        HOperatorSet.DispText(HDevWindowStack.GetActive(), hv_DecodedDataStrings, 
            "image", hv_Row-30, hv_Column-90, "black", "box_color", "#fce9d4cc");
        }
      }


    }
    catch (HalconException HDevExpDefaultException)
    {
      ho_Image.Dispose();
      ho_SymbolRegions.Dispose();

      hv_BarCodeHandle.Dispose();
      hv_WindowHandle.Dispose();
      hv_DecodedDataStrings.Dispose();
      hv_res.Dispose();
      hv_Area.Dispose();
      hv_Row.Dispose();
      hv_Column.Dispose();

      throw HDevExpDefaultException;
    }
    ho_Image.Dispose();
    ho_SymbolRegions.Dispose();

    hv_BarCodeHandle.Dispose();
    hv_WindowHandle.Dispose();
    hv_DecodedDataStrings.Dispose();
    hv_res.Dispose();
    hv_Area.Dispose();
    hv_Row.Dispose();
    hv_Column.Dispose();

  }

#endif


}
#if !(NO_EXPORT_MAIN || NO_EXPORT_APP_MAIN)
public class HDevelopExportApp
{
  static void Main(string[] args)
  {
    new HDevelopExport();
  }
}
#endif

