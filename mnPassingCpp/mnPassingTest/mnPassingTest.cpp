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
	int *bufferLA1=0,**pOutLA1=&bufferLA1;
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
	int *bufferLW1=0,**pOutLW1=&bufferLW1;
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

