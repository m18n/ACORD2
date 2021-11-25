#include"include/getresource.h"
char details::buffer[1000000];
int details::sizewrite;
CURL* ACINTERNET::curl;
size_t details::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
    {
        size_t realsize = size * nmemb;
        std::memcpy(&buffer[sizewrite], contents, realsize);

        sizewrite += realsize;
        return realsize;
    }
void ACINTERNET::IncilACINTERNET(){
    curl=curl_easy_init();
}
char* ACINTERNET::GetResource(std::string resource,int& size){
    curl_easy_setopt(curl,CURLOPT_URL,resource.c_str());
    curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,details::WriteCallback);
    CURLcode response=curl_easy_perform(curl);
    char* res=new char[details::sizewrite];
    std::memcpy(res,details::buffer,details::sizewrite);
    size=details::sizewrite;
    return res;
 }
void ACINTERNET::EndACINTERNET(){
    curl_easy_cleanup(curl);
}