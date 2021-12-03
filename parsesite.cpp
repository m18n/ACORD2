#include"include/parsesite.h"
void ParseSite::GetTagAttribute(char* html,int size,int start){
    for(int i=start;i>=0;i--){
        
    }
}
int ParseSite::SearchAtribute(char* html,int size,std::string nameatribute,std::string value){
    std::string res=nameatribute+"=\""+value+"\"";
    int r=SearchWord(html,size,res.c_str());
    return r;
}