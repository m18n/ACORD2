#include "include/searchacord.h"
void SearchAcord::InitlService(service *arrsearch, int sizeservice)
{
    search = arrsearch;
    this->sizeservice = sizeservice;
}
std::string SearchAcord::GetSearchstrGoogle(std::string str){
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::wstring wide = converter.from_bytes(str);
    for(int i=0;i<wide.length();i++){
        std::cout<<"STR: "<<wide[i]<<"\n";
        if(wide[i]==L' '){
            wide[i]=L'+';
        }
    }
    std::string str2=converter.to_bytes(wide);
    return str2;
    
}
acr SearchAcord::ParseHeaderGoogle(char* html,int size,int number){
    int div=ParseSite::SearchAtribute(html,size,"id","main");
    std::cout<<"DIV: "<<div<<"  "<<html[div]<<"\n";
}
std::vector<acr>& SearchAcord::SearchAcords(std::string res){
    std::cout<<"Start Search\n";
    int size=0;
    std::string res2=GetSearchstrGoogle(res);
    int start=clock();
    char* search=ACINTERNET::GetResource("https://www.google.com/search?q="+res2+"+аккорды+site:amdm.ru",size);
    int end=clock();
    
    std::cout<<"Zapros: "<<end-start<<"\n";
     std::cout<<search<<"\n";
    ParseHeaderGoogle(search,size,1);
   
    delete [] search;
}