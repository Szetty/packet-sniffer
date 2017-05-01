#ifndef PACKET_SNIFFER_UDP_HANDLER_H
#define PACKET_SNIFFER_UDP_HANDLER_H

#include "../../common.h"

void handle_udp_payload(u_int length, struct udphdr *udp);

#endif //PACKET_SNIFFER_UDP_HANDLER_H
