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
#include <process.h>
#include <Windows.h>

#include "garbage.h"

namespace Garbage{
	class myGarbage{
	private:
		int iSize;
		std::vector<int*>vInt;
		std::vector<char*>vChar;
		std::vector<char**>vpChar;
		std::vector<wchar_t*>vwChar;		
		std::vector<wchar_t**>vwpChar;
	private:
		~myGarbage(){}		
		myGarbage(const myGarbage&){}
		myGarbage& operator=(const myGarbage&){}
	private:
		static myGarbage *singleInstance;
	public:
		myGarbage();
	public:
		int getSize();
		bool setNew(int *i);
		bool setNew(char *c);
		bool setNew(char **pc);
		bool setNew(wchar_t *wc);		
		bool setNew(wchar_t **pwc);
		bool DeleteNews();
	public:
		inline bool destroyInstance();
		inline static myGarbage &getInstance();
	};
	myGarbage::myGarbage(){
		vChar.assign(0,0);
		vwChar.assign(0,0);
		iSize=0;
	}
	myGarbage* myGarbage::singleInstance=0;

	myGarbage& myGarbage::getInstance(){
		if(singleInstance==0)
			singleInstance=new myGarbage;
		return *singleInstance;
	}
	bool myGarbage::destroyInstance(){
		if (singleInstance!=0)
			delete singleInstance;
		singleInstance=0;
		if(singleInstance==0)return true;
		return false;
	}
	int myGarbage::getSize(){return iSize;}
	bool myGarbage::setNew(int *i){
		if(i){
			vInt.resize(vInt.size()+1);
			vInt[vInt.size()-1]=i;
			iSize++;
			return true;
		}
		return false;
	}
	bool myGarbage::setNew(char *c){
		if(c){
			vChar.resize(vChar.size()+1);
			vChar[vChar.size()-1]=c;
			iSize++;
			return true;
		}
		return false;
	}
	bool myGarbage::setNew(wchar_t *wc){
		if(wc){
			vwChar.resize(vwChar.size()+1);
			vwChar[vwChar.size()-1]=wc;
			iSize++;
			return true;
		}
		return false;
	}
	bool myGarbage::setNew(char **pc){
		if(pc){
			vpChar.resize(vpChar.size()+1);
			vpChar[vpChar.size()-1]=pc;
			iSize++;
			return true;
		}
		return false;
	}
	bool myGarbage::setNew(wchar_t **pwc){
		if(pwc){
			vwpChar.resize(vwpChar.size()+1);
			vwpChar[vwpChar.size()-1]=pwc;
			iSize++;
			return true;
		}
		return false;
	}
	bool myGarbage::DeleteNews(){
		if(vChar.size()>0){
			char *ptr=0;
			for(int i=0;vChar.size()>0;i++){
				ptr=(char*)vChar[vChar.size()-1];
				if(ptr){
					std::cout<<(void*)&(*vChar[vChar.size()-1])<<" delete ..."<<std::endl;
					try{
						delete [] ptr;ptr=0;
						vChar[vChar.size()-1]=0;
					}catch(std::exception &ex){
						std::cout<<"myGarbage::DeleteNews: "<<ex.what()<<std::endl;						
					}
				}
				vChar.resize(vChar.size()-1);
				iSize--;
			}
		}
		if(vwChar.size()>0){
			wchar_t *ptr=0;
			for(int i=0;vwChar.size()>0;i++){
				ptr=(wchar_t*)vwChar[vwChar.size()-1];
				if(ptr){
					std::cout<<(void*)&(*vwChar[vwChar.size()-1])<<" delete ..."<<std::endl;
					try{
						delete [] ptr;ptr=0;
						vwChar[vwChar.size()-1]=0;
					}catch(std::exception &ex){
						std::cout<<"myGarbage::DeleteNews: "<<ex.what()<<std::endl;						
					}
				}
				vwChar.resize(vwChar.size()-1);
				iSize--;
			}
		}
		if(vpChar.size()>0){
			char **ptr=0;
			for(int i=0;vpChar.size()>0;i++){
				ptr=(char**)vpChar[vpChar.size()-1];
				if(ptr){
					std::cout<<(void*)&(*vpChar[vpChar.size()-1])<<" delete ..."<<std::endl;
					try{
						delete [] ptr;ptr=0;
						vpChar[vpChar.size()-1]=0;
					}catch(std::exception &ex){
						std::cout<<"myGarbage::DeleteNews: "<<ex.what()<<std::endl;						
					}
				}
				vpChar.resize(vpChar.size()-1);
				iSize--;
			}
		}
		if(vwpChar.size()>0){
			wchar_t **ptr=0;
			for(int i=0;vwpChar.size()>0;i++){
				ptr=(wchar_t**)vwpChar[vwpChar.size()-1];
				if(ptr){
					std::cout<<(void*)&(*vwpChar[vwpChar.size()-1])<<" delete ..."<<std::endl;
					try{
						delete [] ptr;ptr=0;
						vwpChar[vwpChar.size()-1]=0;
					}catch(std::exception &ex){
						std::cout<<"myGarbage::DeleteNews: "<<ex.what()<<std::endl;						
					}
				}
				vwpChar.resize(vwpChar.size()-1);
				iSize--;
			}
		}
		if(vInt.size()>0){
			int *ptr=0;
			for(int i=0;vInt.size()>0;i++){
				ptr=(int*)vInt[vInt.size()-1];
				if(ptr){
					std::cout<<(void*)&(*vInt[vInt.size()-1])<<" delete ..."<<std::endl;
					try{
						delete [] ptr;ptr=0;
						vInt[vInt.size()-1]=0;
					}catch(std::exception &ex){
						std::cout<<"myGarbage::DeleteNews: "<<ex.what()<<std::endl;						
					}
				}
				vInt.resize(vInt.size()-1);
				iSize--;
			}
		}
		return true;
	}
	
	bool start(){
		myGarbage &myG=myGarbage::getInstance();
		return true;
	}
	bool close(){
		bool ret=false;
		myGarbage &myG=myGarbage::getInstance();
		myG.DeleteNews();
		myG.destroyInstance();
		ret=true;
		return ret;
	}
	bool setNews(int *i){
		bool ret=false;		
		if(i){
			std::cout<<"SetNews "<<(void*)&(*i)<<std::endl;
			myGarbage &myG=myGarbage::getInstance();
			ret=myG.setNew(i);
		}
		return ret;
	}
	bool setNews(char *c){
		bool ret=false;		
		if(c){
			std::cout<<"SetNews "<<(void*)&(*c)<<std::endl;
			myGarbage &myG=myGarbage::getInstance();
			ret=myG.setNew(c);
		}
		return ret;
	}
	bool setNews(wchar_t *wc){
		bool ret=false;		
		if(wc){
			std::cout<<"SetNews "<<(void*)&(*wc)<<std::endl;
			myGarbage &myG=myGarbage::getInstance();
			ret=myG.setNew(wc);
		}
		return ret;
	}
	bool setNews(char **ppc){
		bool ret=false;		
		if(ppc){
			std::cout<<"SetNews "<<(void*)&(*ppc)<<std::endl;
			myGarbage &myG=myGarbage::getInstance();
			ret=myG.setNew(ppc);
		}
		return ret;
	}
	bool setNews(wchar_t **ppwc){
		bool ret=false;		
		if(ppwc){
			std::cout<<"SetNews "<<(void*)&(*ppwc)<<std::endl;
			myGarbage &myG=myGarbage::getInstance();
			ret=myG.setNew(ppwc);
		}
		return ret;
	}
}