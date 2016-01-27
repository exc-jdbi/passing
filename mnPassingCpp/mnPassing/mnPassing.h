/*
 * Copyright © exc-jdbi 2016
 *
 * © mnPassing 2016
 *
 * mnPassing - www.github.com/exc-jdbi/passing
 *
 * mnPassing is Free and Opensource Software
*/
#pragma once
#ifndef __MY_PASSING_H__
#define __MY_PASSING_H__
#define EXP32 extern "C" __declspec(dllexport)

//Widestrings
EXP32 int get_PwArrayW(int const iSize,int const iMin,int const iMax,wchar_t ***ppOut,const int **xLen);
EXP32 int _stdcall getPwArrayW(int const iSize,int const iMin,int const iMax,wchar_t ***ppOut,const int **xLen);

//Ansistrings
EXP32 int get_PwArrayA(int const iSize,int const iMin,int const iMax,char ***ppOut,const int **xLen);
EXP32 int _stdcall getPwArrayA(int const iSize,int const iMin,int const iMax,char ***ppOut,const int **xLen);

//Passing Array to .Net
EXP32 int _stdcall getPwArray(int const iSize,int const iMin,int const iMax,void **ppOut,const int **xLen);

//Garbage
EXP32 bool start_Garbage();
EXP32 bool _stdcall startGarbage();

EXP32 bool close_Garbage();
EXP32 bool _stdcall closeGarbage();

#endif