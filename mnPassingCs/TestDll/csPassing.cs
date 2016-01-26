/*
 * Copyright © exc-jdbi 2016
 *
 * © mnPassing 2016
 *
 * mnPassing - www.github.com/exc-jdbi/passing
 *
 * mnPassing is Free and Opensource Software
*/
using System;
using System.Linq;
using System.Text;
using System.Collections.Generic;
using System.Runtime.InteropServices;
namespace TestDll
{
    public class csPassing
    {
        public bool Open()
        {
            return dll.startGarbage();
        }
        public bool Close()
        {
            return dll.closeGarbage();
        }
        public List<string> getRndPasswortList(int size, int min, int max)
        {
            List<string> ret = null;
            IntPtr p1 = IntPtr.Zero;
            IntPtr p2 = IntPtr.Zero;
            try {
                List<string> lst;
                int resSize = dll.getPwArray(size, min, max, ref p1, ref p2);
                if (resSize > 0) {
                    lst = new List<string>(resSize);
                    char[] s = {};
                    IntPtr p0 = IntPtr.Zero;
                    IntPtr p00 = IntPtr.Zero;
                    IntPtr pT = IntPtr.Zero;
                    for (int i = 0; i <= resSize - 1; i++) {
                        p0 = Marshal.ReadIntPtr(p1, i * Marshal.SizeOf(typeof(IntPtr)));
                        p00 = Marshal.ReadIntPtr(p2, i * Marshal.SizeOf(typeof(int)));

                        s = new char[p00.ToInt32()];
                        Marshal.Copy(p0, s, 0, p00.ToInt32());
                        lst.Add(new string(s));
                        //Marshal.FreeCoTaskMem(p0);
                        Marshal.FreeCoTaskMem(p00);
                    }
                    return lst;
                }
            } catch (Exception ex) {
                Console.Write("Error: " + ex.Message);
            } finally {
                //Marshal.FreeHGlobal(p1);
                //Marshal.FreeHGlobal(p2);
            }
            return ret;
        }
        private abstract class dll
        {
            const string dllPathConfDebug = "../../../../mnPassingCpp/mnPassingTest/Debug/mnPassing.dll";
            const string dllPathConfRelease = "../../../../mnPassingCpp/mnPassingTest/Release/mnPassing.dll";
            
            const string dllPath = dllPathConfDebug;
            [DllImport(dllPath)]
            public static extern bool startGarbage();
            [DllImport(dllPath)]
            public static extern bool closeGarbage();
            [DllImport(dllPath, CharSet = CharSet.Unicode, CallingConvention = CallingConvention.StdCall)]
            public static extern int getPwArray(int iSize, int iMin, int iMax, ref IntPtr pPw, ref IntPtr pXlen);
        }
    }
}
