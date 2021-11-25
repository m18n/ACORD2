#pragma once
#include<iostream>
#include<cstring>
#include "../curl/include/curl/curl.h"
namespace details{
    extern char buffer[1000000];
    extern int sizewrite;
    size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
    void InicilDetail();
};
namespace ACINTERNET
{
    extern CURL* curl;
    char* GetResource(std::string resource,int& size);
    void IncilACINTERNET();
    void EndACINTERNET();
}