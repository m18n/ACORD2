#include<iostream>
#include <fstream> 
#include"include/sslsocket.h"
#include"include/internet.h"
#include"include/parsehtml.h"
using namespace std;

int main(){
    cout<<"HELLO\n";
    sockssl::SOCKSSL acrod;
    acrod.InithlSSl("142.250.201.206");
    GET searchpesn;
    //
    searchpesn.SetALL("/search?q=пачка+сигарет+аккорды","www.google.com");
    acrod.SendGet(searchpesn);
    int size=0;
    char* b=acrod.RecvPacket(size);
    std::ofstream outfile ("new.txt",std::ofstream::binary);
    outfile.write (b,size);
    ParseHtml search(b,size);
    
    std::cout<<"GIT\n";
    int index=search.SearchAtribute("id=\"center_col\"");
    std::cout<<"INDEX: "<<index<<"\n";
    cin.get();
    cin.get();
    return 0;
}