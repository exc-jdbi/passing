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
using TestDll;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.Collections.Generic;

namespace mnPassingCsTest
{
    class mnPassingCsTest
    {
        static void Main(string[] args)
        {
            csPassing pass = new csPassing();
            int min = 16;
            int max = 64;
            int size = 10;

            List<string> lst = pass.getRndPasswortList(size, min, max);
            pass.Close();
            Debugger.Break();
        }
    }
}
