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
EXP32 int get_PwArrayW(int iSize,int iMin,int iMax,wchar_t ***ppOut,int **xLen);
EXP32 int _stdcall getPwArrayW(int iSize,int iMin,int iMax,wchar_t ***ppOut,int **xLen);

//Ansistrings
EXP32 int get_PwArrayA(int iSize,int iMin,int iMax,char ***ppOut,int **xLen);
EXP32 int _stdcall getPwArrayA(int iSize,int iMin,int iMax,char ***ppOut,int **xLen);

//Passing Array to .Net
EXP32 int _stdcall getPwArray(int iSize,int iMin,int iMax,void **ppOut,int **xLen);

//Garbage
EXP32 bool start_Garbage();
EXP32 bool _stdcall startGarbage();

EXP32 bool close_Garbage();
EXP32 bool _stdcall closeGarbage();

#endif