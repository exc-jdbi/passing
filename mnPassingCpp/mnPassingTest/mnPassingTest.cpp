/*
 * Copyright © exc-jdbi 2016
 *
 * © mnPassing 2016
 *
 * mnPassing - www.github.com/exc-jdbi/passing
 *
 * mnPassing is Free and Opensource Software
*/

#include "stdafx.h"
#include <vector>
#include <iostream>
#include "mnPassing.h"
#define IMIN 16
#define IMAX 64

int _tmain(int argc, _TCHAR* argv[]){
	int iSize=10;

	std::vector<int>viA;
	std::vector<std::string>vsA;
	char **bufferA1={0},***pOutA1=&bufferA1;
	const int *bufferLA1=0,**pOutLA1=&bufferLA1;
	int iSizeA1=getPwArrayA(iSize,IMIN,IMAX,pOutA1,pOutLA1);
	if((iSizeA1>0)&&(*pOutA1)&&(*pOutLA1)){
		for(int i=0;i<iSizeA1;i++){
			viA.push_back((*pOutLA1)[i]);
			vsA.push_back((*pOutA1)[i]);
		}
	}
	std::vector<int>viW;
	std::vector<std::wstring>vsW;
	wchar_t **bufferW1={0},***pOutW1=&bufferW1;
	const int *bufferLW1=0,**pOutLW1=&bufferLW1;
	int iSizeW1=getPwArrayW(iSize,IMIN,IMAX,pOutW1,pOutLW1);
	if((iSizeW1>0)&&(*pOutW1)&&(*pOutLW1)){
		for(int i=0;i<iSizeW1;i++){
			viW.push_back((*pOutLW1)[i]);
			vsW.push_back((*pOutW1)[i]);
		}
	}

	closeGarbage();

	return 0;
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