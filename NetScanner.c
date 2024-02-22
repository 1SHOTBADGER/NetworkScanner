#include <pcap.h>
#include<stdio.h>
#include <winsock2.h>
#ifdef _WIN32
#endif
int main() {
    #ifdef _WIN32
    WSADATA wsaData;
    if(WSAStartup(MAKEWORD(2,2), &wsaData) != 0) {
        fprintf(stderr, "WSAStartup failed.\n");
        exit(EXIT_FAILURE);
    }
    #endif

    pcap_if_t *alldevs;
    pcap_if_t *d;
    char errbuf[PCAP_ERRBUF_SIZE];
    int i = 0;

    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
        exit(EXIT_FAILURE);
    }
    
    for (d = alldevs; d != NULL; d = d->next) {
        printf("%d. %s", ++i, d->name);
        if (d->description)
            printf(" (%s)\n", d->description);
        else
            printf(" (No description available)\n");
    }

    if (i == 0) {
        printf("\nNo interfaces found! Make sure WinPcap is installed.\n");
        pcap_freealldevs(alldevs); 
        #ifdef _WIN32
        WSACleanup(); 
        #endif
        return -1;
    }

    pcap_freealldevs(alldevs);

    #ifdef _WIN32
    WSACleanup(); 
    #endif

    return 0;
}