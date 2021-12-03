#pragma once
#include<iostream>
#include"StrParse.h"
class ParseSite{
private:
    static void GetTagAttribute(char* html,int size,int start);
public:
    static int SearchAtribute(char* html,int size,std::string nameatribute,std::string value);
private:
    char* html;
    int size;
};
