#pragma once
#include "getresource.h"
#include "services.h"
#include<vector>
#include <cstring>
#include <codecvt>
#include"parsesite.h"
#include <locale>
#include"acr.h"
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
    acr ParseHeaderGoogle(char* html,int size,int number);
    void InitlService(service *arrsearch, int sizeservice);
    std::string GetSearchstrGoogle(std::string str);
    std::vector<acr>& SearchAcords(std::string res);
};
