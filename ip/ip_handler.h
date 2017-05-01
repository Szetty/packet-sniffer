#ifndef PACKET_SNIFFER_IP_HANDLER_H
#define PACKET_SNIFFER_IP_HANDLER_H

#include "../common.h"
#include "tcp/tcp_handler.h"
#include "udp/udp_handler.h"
#include "icmp/icmp_handler.h"

#define IP_PROTOCOL_STRING_FORMAT "IP protocol: %s\n"

#define IP_ICMP 1
#define IP_TCP 6
#define IP_UDP 17

void handle_ip_payload(u_int length, struct ip *ip);

#endif //PACKET_SNIFFER_IP_HANDLER_H
