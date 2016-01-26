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
#ifndef __MY_GARBAGE_H__
#define __MY_GARBAGE_H__
namespace Garbage{
	bool start();
	bool close();
	bool setNews(int *i);
	bool setNews(char *c);
	bool setNews(wchar_t *wc);
	bool setNews(char **ppc);
	bool setNews(wchar_t **ppwc);
}
#endif