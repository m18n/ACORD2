#include<iostream>
#include<cstring>

using namespace std;

int main(){
    cout<<"HELLO\n";
    ACINTERNET::IncilACINTERNET();
    int size=0;
    char* google=ACINTERNET::GetResource("https://www.google.com/search?q=пачка+сигарет+аккорды",size);
    std::cout<<google<<"\n";
    delete [] google;
    ACINTERNET::EndACINTERNET();
    cin.get();
    cin.get();
    return 0;
}