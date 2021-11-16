#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include "internet.h"
namespace sockssl
{
    class SOCKSSL
    {
    private:
        bool CheckArrsChars(const char* buffer1,const char* buffer2,int allsize);
        bool CheckPacketEnd(char* buffer,int size);
    public:
        char *RecvPacket(int& size);
        int SendPacket(const char *buf);
        static void log_ssl();
        int InithlSSl(std::string ipsite);
        void SendGet(GET get);

    private:
        int sock;
        SSL *ssl;
    };

}