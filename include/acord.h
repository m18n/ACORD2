#pragma once
#include"getresource.h"
#include"services.h"
#include"searchacord.h"
class ACORD{
public:
    ACORD(){
        ACINTERNET::IncilACINTERNET();
        search.InitlService(&amdm,1);
    }
    ~ACORD(){
        ACINTERNET::EndACINTERNET();
    }
public:
   void SearchAcrod(std::string word){
       search.SearchAcords(word);
   }

private:
    SearchAcord search;
    service amdm;  
};