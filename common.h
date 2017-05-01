#ifndef PACKET_SNIFFER_COMMON_H
#define PACKET_SNIFFER_COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#include <time.h>
#include <netinet/ip.h>
#include <net/if_arp.h>
#include <net/ethernet.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>
#include <netinet/ether.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <netinet/ip_icmp.h>

#define MOVE_POINTER_BY(pointer, offset) ((u_char*) pointer + offset)

#define ETHERNET_HEADER_LENGTH sizeof(struct ether_header)
#define IP_HEADER_LENGTH sizeof(struct ip)
#define TCP_HEADER_LENGTH sizeof(struct tcphdr)
#define UDP_HEADER_LENGTH sizeof(struct udphdr)
#define ARP_HEADER_LENGTH sizeof(struct arphdr)
#define ICMP_HEADER_LENGTH sizeof(struct icmphdr)

#define MAC_TO_STRING(mac) ether_ntoa((struct ether_addr*)mac)
#define IP_TO_STRING(ip) inet_ntoa((struct in_addr) ip)

#define TRUNCATED_STRING "Truncated %s %d\n"
#define SOURCE_PORT_STRING "Source port: %d\n"
#define DESTINATION_PORT_STRING "Destination port: %d\n"

#endif //PACKET_SNIFFER_COMMON_H
