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
#include <time.h>
#include <vector>
#include <iostream>

#include "garbage.h"
#include "mnPassing.h"

time_t t;
int random=0;
bool bRnd=false;

inline bool activateSRand(){
	time (&t);
	srand((unsigned int)t);;
	bRnd=true;
	return true;
}

inline bool checkLen(int const &max,int const &min){
	if((max>0)&&(min>0)&&(max>min))return true;
	return false;
};
int createPwArrayW(const int &iSize,const int &iMin,const int &iMax,wchar_t ***ppOut,const int **xLen){
	int ret=-1;
	try{
		if((iSize>0)&&(checkLen(iMax,iMin))&&(ppOut)&&(xLen)){
			wchar_t alphanum[]=L"0123456789"
							   L"*-+$/€"
							   L"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
							   L"abcdefghijklmnopqrstuvwxyz";
			if(!bRnd){activateSRand();}
			int iAlphanum=std::wcslen(alphanum);
			
			wchar_t **pOut=new wchar_t*[iSize];
			memset(pOut,0,iSize);//thats right!!
			Garbage::setNews(pOut);

			int *pXlen=new int[iSize];
			memset(pXlen,0,iSize);
			Garbage::setNews(pXlen);

			int i=0;
			int itemLen=0;
			for(;i<iSize;++i){
				itemLen=(rand()%(iMax-iMin))+iMin;
				if((itemLen>=iMin)&&(itemLen<iMax)){
					pOut[i]=new wchar_t[itemLen+1];
					wmemset(pOut[i],0,itemLen+1);
					Garbage::setNews(pOut[i]);
					pXlen[i]=itemLen;
					for(int j=0;j<itemLen;++j){
						random=(rand()%iAlphanum);
						if(random>=iAlphanum){j-=1;continue;}
						if(random<0){j-=1;continue;}
						pOut[i][j]=alphanum[random];
						if(pOut[i][j]==0){j-=1;}
					}					
				}else{i-=1;continue;}
			}
			if((pOut)&&(i>0)){
				*ppOut=pOut;
				*xLen=pXlen;
				ret=i;
			}
		}
		return ret;
	}
	catch(std::exception &ex){
		std::cout<<"createPwArrayW: "<<ex.what()<<std::endl;
		return ret;
	}
}
int createPwArrayA(const int &iSize,const int &iMin,const int &iMax,char ***ppOut,const int **xLen){
	int ret=-1;
	try{
		if((iSize>0)&&(checkLen(iMax,iMin))&&(ppOut)&&(xLen)){
			char alphanum[]="0123456789"
							"*-+$/€"
							"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
							"abcdefghijklmnopqrstuvwxyz";
			if(!bRnd){activateSRand();}
			int iAlphanum=std::strlen(alphanum);			

			char **pOut=new char*[iSize];
			memset(pOut,0,iSize);
			Garbage::setNews(pOut);

			int *pXlen=new int[iSize];
			memset(pXlen,0,iSize);
			Garbage::setNews(pXlen);

			int i=0;
			int itemLen=0;
			for(;i<iSize;++i){
				itemLen=(rand()%(iMax-iMin))+iMin;
				if((itemLen>=iMin)&&(itemLen<iMax)){
					pOut[i]=new char[itemLen+1];
					memset(pOut[i],0,itemLen+1);
					Garbage::setNews(pOut[i]);
					pXlen[i]=itemLen;
					for(int j=0;j<itemLen;++j){
						random=(rand()%iAlphanum);
						if(random>=iAlphanum){j-=1;continue;}
						if(random<0){j-=1;continue;}
						pOut[i][j]=alphanum[random];
						if(pOut[i][j]==0){j-=1;}
					}
				}else{i-=1;continue;}
			}
			if((pOut)&&(i>0)){
				*ppOut=pOut;
				*xLen=pXlen;
				ret=i;
			}
			
		}
		return ret;
	}
	catch(std::exception &ex){
		std::cout<<"createPwArrayA: "<<ex.what()<<std::endl;
		return ret;
	}
}
int createPwArray(const int &iSize,const int &iMin,const int &iMax,void **ppOut,const int **xLen){
	int ret=-1;
	try{
		if((iSize>0)&&(checkLen(iMax,iMin))&&(ppOut)&&(xLen)){
			wchar_t **bufferW1={0},***pOutW1=&bufferW1;
			const int *bufferLW1=0,**pOutLW1=&bufferLW1;
			int iSizeW1=createPwArrayW(iSize,iMin,iMax,pOutW1,pOutLW1);			
			if((iSizeW1>0)&&(*pOutW1)&&(*pOutLW1)){
				*ppOut=*pOutW1;
				*xLen=*pOutLW1;
				ret=iSizeW1;
			}
		}
		return ret;
	}
	catch(std::exception &ex){
		std::cout<<"createPwArray: "<<ex.what()<<std::endl;
		return ret;
	}
}

/* ------------------------- ------------------------- ------------------------- ------------------------- */
/* ------------------------- ------------------------- ------------------------- ------------------------- */
/* ------------------------- ------------------------- ------------------------- ------------------------- */
/* ------------------------- ------------------------- ------------------------- ------------------------- */
int get_PwArrayW(int const iSize,int const iMin,int const iMax,wchar_t ***ppOut,const int **xLen){
	return getPwArrayW(iSize,iMin,iMax,ppOut,xLen);
}
int _stdcall getPwArrayW(int const iSize,int const iMin,int const iMax,wchar_t ***ppOut,const int **xLen){
	return createPwArrayW(iSize,iMin,iMax,ppOut,xLen);
}
int get_PwArrayA(int const iSize,int const iMin,int const iMax,char ***ppOut,const int **xLen){
	return getPwArrayA(iSize,iMin,iMax,ppOut,xLen);
}
int _stdcall getPwArrayA(int const iSize,int const iMin,int const iMax,char ***ppOut,const int **xLen){
	return createPwArrayA(iSize,iMin,iMax,ppOut,xLen);
}
int _stdcall getPwArray(int const iSize,int const iMin,int const iMax,void **ppOut,const int **xLen){
	return createPwArray(iSize,iMin,iMax,ppOut,xLen);
}
/* ------------------------- ------------------------- ------------------------- ------------------------- */
/* ------------------------- ------------------------- ------------------------- ------------------------- */
/* ------------------------- ------------------------- ------------------------- ------------------------- */
/* ------------------------- ------------------------- ------------------------- ------------------------- */