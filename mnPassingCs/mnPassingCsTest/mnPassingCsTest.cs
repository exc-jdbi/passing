﻿/*
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

/*
OUTPUT
******

Start GarbageStart ...
... Exit GarbageStart.

SetNews 00ABCD01
SetNews 00ABCD02
SetNews 00ABCD03
SetNews 00ABCD04
SetNews 00ABCD05
SetNews 00ABCD06
SetNews 00ABCD07
SetNews 00ABCD08
SetNews 00ABCD09
SetNews 00ABCD10
SetNews 00ABCD11
SetNews 00ABCD12
SetNews 00ABCD13
SetNews 00ABCD14
SetNews 00ABCD15
SetNews 00ABCD16
SetNews 00ABCDA1
SetNews 00ABCDA2
SetNews 00ABCDA3
SetNews 00ABCDA4
SetNews 00ABCDA5
SetNews 00ABCDA6
SetNews 00ABCDA7
SetNews 00ABCDA8

Start GarbageClose ...
00ABCDA8 delete ...
00ABCDA7 delete ...
00ABCDA6 delete ...
00ABCDA5 delete ...
00ABCDA4 delete ...
00ABCDA3 delete ...
00ABCDA2 delete ...
00ABCDA1 delete ...
00ABCD16 delete ...
00ABCD15 delete ...
00ABCD14 delete ...
00ABCD13 delete ...
00ABCD12 delete ...
00ABCD11 delete ...
00ABCD10 delete ...
00ABCD09 delete ...
00ABCD08 delete ...
00ABCD07 delete ...
00ABCD06 delete ...
00ABCD05 delete ...
00ABCD04 delete ...
00ABCD03 delete ...
00ABCD02 delete ...
00ABCD01 delete ...
... Exit GarbageClose.
*/