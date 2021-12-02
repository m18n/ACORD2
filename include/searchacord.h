#pragma once
#include "getresource.h"
#include "services.h"
#include <cstring>
#include <codecvt>
#include <locale>
class SearchAcord
{
private:
    service *search;
    int sizeservice;

public:
    SearchAcord()
    {
        search = NULL;
        this->sizeservice = 0;
    }
    SearchAcord(service *arrsearch, int sizeservice)
    {
        InitlService(arrsearch, sizeservice);
    }
    ~SearchAcord()
    {
    }
public:
    void InitlService(service *arrsearch, int sizeservice);
    std::string GetSearchstrGoogle(std::string str);
    void SearchAcords(std::string res);
};
