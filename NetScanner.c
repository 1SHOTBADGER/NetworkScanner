#include <stdio.h>
#include <pcap.h>
#include <winsock2.h>
#ifdef _WIN32
    WSADATA wsaData;
    if(WSAStartup(MAKEWORD(2,2), &wsaData) != 0){
        fprintf(stderr, "WSAStartup failed.\n");
        exit(EXIT_FAILURE);    
    }


int main(){





    return 0;
}