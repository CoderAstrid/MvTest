/*
 * .Net Wrapping of RecogEngine.h
 */

using System;
using System.Drawing;
using System.Runtime.InteropServices;

namespace RecogCSharp
{
    [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi)]
    public struct RECT
    {
        public int left;
        public int top;
        public int right;
        public int bottom;
    }

    [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi)]
    public struct CodeRecogRes
    {
        public RECT rcRoi;
        public int iOrientation;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 128)]
        public char[] sText;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 64)]
        public char[] sType;

        // if all same mode, have several regions.  [8/18/2021 Jewel]
        public int countRegion;                // code-rectangle count

        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 16)]
        public int[] corner_x;   // code-rectangle x corner

        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 16)]
        public int[] corner_y;	// code-rectangle y corner
    };

    [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi)]
    public struct SvBarRecParams
    {
        public int thrMag;             // edge magnitude threshold, def: 30
        public int smoothWinSz;
        public int minEdgeT;
        public int localBlockSz;
        public double minDensityEdgeT;
        public int maxDistLines;

        [MarshalAs(UnmanagedType.I1)] 
        public bool isSmallProc;       // at 1st try with small image, default: true
        [MarshalAs(UnmanagedType.I1)]
        public bool isFisrtFound;      // if found the 1st result, stop
        [MarshalAs(UnmanagedType.I1)]
        public bool isFastMode;        // fast mode(no try for failed regions)
        [MarshalAs(UnmanagedType.I1)]
        public bool isAllSame;         // if all codes are same	
        [MarshalAs(UnmanagedType.I1)]
        public bool isShowMidRes;      // if true, show middle results

        public int marginROI;
        public int minStringLength;

        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 128)]
        public char[] charset;
    };


    class RecogEngine2SDK
    {
        const string DLL_NAME = "RecogEngine2d.dll";

        [DllImport(DLL_NAME, EntryPoint = "sv_engine_init_v2", CharSet = CharSet.Ansi)]
        public static extern Int32 SvEngineInit();

        [DllImport(DLL_NAME, EntryPoint = "sv_engine_close_v2", CharSet = CharSet.Ansi)]
        public static extern Int32 SvEngineClose();

        [DllImport(DLL_NAME, CallingConvention = CallingConvention.Cdecl, EntryPoint = "sv_engine_rec_v2", CharSet = CharSet.Ansi)]
        public static extern Int32 _SvEngineRec(byte[] buf, int _w, int _h, int _bpp, int _codeType, [Out] out IntPtr _outRes);

        [DllImport(DLL_NAME, EntryPoint = "sv_get_param_v2", CharSet = CharSet.Ansi)]
        public static extern Int32 SvEngineGetParam(ref SvBarRecParams param);

        [DllImport(DLL_NAME, EntryPoint = "sv_set_param_v2", CharSet = CharSet.Ansi)]
        public static extern Int32 SvEngineSetParam(SvBarRecParams param);

        public static Int32 SvEngineRec(Bitmap frame, int _codeType, ref CodeRecogRes[] _outRes)
        {
            IntPtr outArrayReceiver = IntPtr.Zero;

            // Lock the bitmap's bits. 
            Rectangle rect = new Rectangle(0, 0, frame.Width, frame.Height);
            System.Drawing.Imaging.BitmapData bmpData = frame.LockBits(
                rect,
                System.Drawing.Imaging.ImageLockMode.ReadOnly,
                frame.PixelFormat);

            // Get the address of the first line.
            IntPtr ptrBuf = bmpData.Scan0;

            // Declare an array to hold the bytes of the bitmap.
            int bytes = bmpData.Stride * frame.Height;
            byte[] rgbValues = new byte[bytes];

            // Copy the RGB values into the array.
            Marshal.Copy(ptrBuf, rgbValues, 0, bytes); frame.UnlockBits(bmpData);

            Int32 iRes = _SvEngineRec(rgbValues, frame.Width, frame.Height, 24, _codeType, out outArrayReceiver);

            if (iRes > 0 && outArrayReceiver != null)
            {
                int iOneSize = Marshal.SizeOf(typeof(CodeRecogRes));
                _outRes = new CodeRecogRes[iRes];
                IntPtr ptr = outArrayReceiver;
                for (int i = 0; i < iRes; i++)
                {
                    _outRes[i] = Marshal.PtrToStructure<CodeRecogRes>(ptr);
                    Marshal.DestroyStructure(ptr, typeof(CodeRecogRes));
                    ptr = ptr + iOneSize;
                }
            }

            Marshal.FreeCoTaskMem(outArrayReceiver);
            outArrayReceiver = IntPtr.Zero;
            rgbValues = null;

            return iRes;
        }

        public static Int32 SvEngineRecFromBuffer(byte[] _buf, int _w, int _h, int _codeType, ref CodeRecogRes[] _outRes)
        {
            IntPtr outArrayReceiver = IntPtr.Zero;

            Int32 iRes = _SvEngineRec(_buf, _w, _h, 24, _codeType, out outArrayReceiver);

            if (iRes > 0 && outArrayReceiver != null)
            {
                int iOneSize = Marshal.SizeOf(typeof(CodeRecogRes));
                _outRes = new CodeRecogRes[iRes];
                IntPtr ptr = outArrayReceiver;
                for (int i = 0; i < iRes; i++)
                {
                    _outRes[i] = (CodeRecogRes)Marshal.PtrToStructure(ptr, typeof(CodeRecogRes));
                    Marshal.DestroyStructure(ptr, typeof(CodeRecogRes));
                    ptr = ptr + iOneSize;
                }
            }            
            
            Marshal.FreeCoTaskMem(outArrayReceiver);
            outArrayReceiver = IntPtr.Zero;
            
            return iRes;
        }

        [DllImport("kernel32.dll", SetLastError = true)]
        public static extern int QueryPerformanceCounter(out Int64 iCount);

        [DllImport("kernel32.dll", SetLastError = true)]
        public static extern int QueryPerformanceFrequency(out Int64 iFrequency);

        private static Int64 m_iPerfFrequency = -1;
        
        /// <summary>
        /// for test performance
        /// </summary>
        /// <returns>millisecond of double</returns>
        public static double GetPerfCounter()
        {
            // see if we need to get the frequency
            if (m_iPerfFrequency < 0)
            {
                if (QueryPerformanceFrequency(out m_iPerfFrequency) == 0)
                {
                    return 0.0;
                }
            }

            Int64 iCount = 0;
            if (QueryPerformanceCounter(out iCount) == 0)
            {
                return 0.0;
            }

            return (double)iCount * 1000.0 / (double)m_iPerfFrequency;
        }
    }
}
//.EOF