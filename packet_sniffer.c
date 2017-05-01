#include "ip/ip_handler.h"
#include "arp/arp_handler.h"
#include "common.h"

#define WIFI_INTERFACE "wlp2s0"
#define ETHERNET_INTERFACE "enp1s0"
#define LOCAL_INTERFACE "lo"

#define BEGIN_PACKET "------------------------------BEGIN------------------------------\n"
#define END_PACKET "------------------------------END--------------------------------\n"

void handle_ethernet_packet(struct pcap_pkthdr *packet_header, const u_char* packet) {
    struct ether_header *ethernet_header = (struct ether_header *) packet;
    u_int32_t payload_length = packet_header->len - ETHERNET_HEADER_LENGTH;
    u_int16_t packet_type = ntohs ((uint16_t) ethernet_header->ether_type);

    printf("Grabbed packet of length %d\n", packet_header->len);
    printf("Received at ..... %s", ctime((const time_t*)&packet_header->ts.tv_sec));
    printf("Ethernet address length is %d\n", ETHER_HDR_LEN);
    printf("Source MAC Address: %s\n", MAC_TO_STRING(ethernet_header->ether_shost));
    printf("Destination MAC Address: %s\n", MAC_TO_STRING(ethernet_header->ether_dhost));
    if (packet_type == ETHERTYPE_IP) {
        printf("This packet type is IP\n");
        handle_ip_payload(payload_length, (struct ip *) MOVE_POINTER_BY(packet, ETHERNET_HEADER_LENGTH));
    } else if (packet_type == ETHERTYPE_ARP) {
        printf("This packet type is ARP\n");
        handle_arp_payload(payload_length, (struct arphdr*) MOVE_POINTER_BY(packet, ETHERNET_HEADER_LENGTH));
    } else if (packet_type == ETHERTYPE_IPV6){
        printf("This packet type is IPv6\n");
    } else {
        printf("This packet type is unknown(%d)\n", packet_type);
    }
}

int main(int argc, char **argv)
{
    char *dev = WIFI_INTERFACE;
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t* packet_stream;
    const u_char *packet;
    struct pcap_pkthdr packet_header;

    printf("We will sniff packets on device: %s\n",dev);
    packet_stream = pcap_open_live(dev, BUFSIZ, 0, -1, error_buffer);

    if(packet_stream == NULL) {
        printf("pcap_open_live(): %s\n",error_buffer);
        exit(1);
    }
    while(1) {
        packet = pcap_next(packet_stream, &packet_header);
        printf(BEGIN_PACKET);
        if(packet == NULL) {
            printf("Didn't grab packet\n");
            exit(1);
        } else {
            handle_ethernet_packet(&packet_header, packet);
        }
        printf(END_PACKET);
    }

    return 0;
}