#pragma once
#include<iostream>
#include <cstring>
class ParseHtml
{
private:
    int SearchWord(const char* word);
private:
    char* html;
    int sizehtml;
public:
    
    ParseHtml(char* html,int size);
    int SearchAtribute(const char* name){
        return SearchWord(name);
    }
    void SetHtml(char* html,int size){
        this->html=html;
        this->sizehtml=size;
    }
    
    ~ParseHtml();
};

