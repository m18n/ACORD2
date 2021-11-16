#pragma once
#include<iostream>
class GET
{
public:
    GET(){
        req="GET";
    }
    void SetALL(std::string link,std::string host){
        SetLink(link);
        SetHost(host);
        End();
    }
    void SetLink(std::string link){
        req+=" "+link+" HTTP/1.1\r\n";
        
    }
    void SetHost(std::string host){
        req+="HOST: "+host+"\r\n";
    }
    void End(){
        req+="\r\n";
    }
    std::string GetReq(){
        return req;
    }
private:
std::string req;
};
