#pragma once
#include"include/getresource.h"
class ACORD{
public:
    ACORD(){
        ACINTERNET::IncilACINTERNET();
    }
    ~ACORD(){
        ACINTERNET::EndACINTERNET();
    }
public:
    void SearchAcord(std::string search){
        
    }

private:

};