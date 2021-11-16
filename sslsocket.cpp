#include "include/sslsocket.h"
bool sockssl::SOCKSSL::CheckArrsChars(const char *buffer1, const char *buffer2, int allsize)
{
    std::cout << "BUFFER: " << buffer1 << "\n";
    for (int i = 0; i < allsize; i++)
    {
        if (buffer1[i] != buffer2[i])
            return false;
    }
    return true;
}
bool sockssl::SOCKSSL::CheckPacketEnd(char *buffer, int size)
{

    return CheckArrsChars(&buffer[size - 4], "\r\n\r\n", 4);
}
char *sockssl::SOCKSSL::RecvPacket(int& size)
{
    int len = 100;
    static char buf[10000];
    static char buffer[10000000];
    int allsize = 0;
    int count = 0;
    do
    {
        len = SSL_read(ssl, buf, 100);

        mempcpy(&buffer[allsize], buf, len);

        allsize += len;
        buffer[allsize + 1] = '\0';

        if (buffer[allsize - 1] == '\n')
        {

            bool checkend = CheckPacketEnd(buffer, allsize);
            std::cout << buffer << "\n";
            if (checkend == true)
            {
                break;
            }
        }

        //        fprintf(fp, "%s",buf);
    } while (len > 0);
    if (len < 0)
    {
        int err = SSL_get_error(ssl, len);
        if (err == SSL_ERROR_WANT_READ)
            return 0;
        if (err == SSL_ERROR_WANT_WRITE)
            return 0;
        if (err == SSL_ERROR_ZERO_RETURN || err == SSL_ERROR_SYSCALL || err == SSL_ERROR_SSL)
            return 0;
    }
    size=allsize;
    return buffer;
}

int sockssl::SOCKSSL::SendPacket(const char *buf)
{
    std::cout << "SENDPACKET\n"
              << buf;
    int len = SSL_write(ssl, buf, strlen(buf));
    if (len < 0)
    {
        int err = SSL_get_error(ssl, len);
        switch (err)
        {
        case SSL_ERROR_WANT_WRITE:
            return 0;
        case SSL_ERROR_WANT_READ:
            return 0;
        case SSL_ERROR_ZERO_RETURN:
        case SSL_ERROR_SYSCALL:
        case SSL_ERROR_SSL:
        default:
            return -1;
        }
    }
}
void sockssl::SOCKSSL::SendGet(GET get)
{
    SendPacket(get.GetReq().c_str());
}
void sockssl::SOCKSSL::log_ssl()
{
    int err;
    while (err = ERR_get_error())
    {
        char *str = ERR_error_string(err, 0);
        if (!str)
            return;
        printf(str);
        printf("\n");
        fflush(stdout);
    }
}
int sockssl::SOCKSSL::InithlSSl(std::string ipsite)
{
    int s;
    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s < 0)
    {
        printf("Error creating socket.\n");
        return -1;
    }
    struct sockaddr_in sa;
    memset(&sa, 0, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr(ipsite.c_str()); // address of google.ru
    sa.sin_port = htons(443);
    socklen_t socklen = sizeof(sa);
    if (connect(s, (struct sockaddr *)&sa, socklen))
    {
        printf("Error connecting to server.\n");
        return -1;
    }
    SSL_library_init();
    SSLeay_add_ssl_algorithms();
    SSL_load_error_strings();

    const SSL_METHOD *meth = TLSv1_2_client_method();
    SSL_CTX *ctx = SSL_CTX_new(meth);
    ssl = SSL_new(ctx);
    if (!ssl)
    {

        printf("Error creating SSL.\n");

        return -1;
    }
    sock = SSL_get_fd(ssl);
    SSL_set_fd(ssl, s);
    int err = SSL_connect(ssl);
    if (err <= 0)
    {
        printf("Error creating SSL connection.  err=%x\n", err);
        log_ssl();

        fflush(stdout);
        return -1;
    }
    printf("SSL connection using %s\n", SSL_get_cipher(ssl));
}