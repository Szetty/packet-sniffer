#ifndef PACKET_SNIFFER_ICMP_HANDLER_H
#define PACKET_SNIFFER_ICMP_HANDLER_H

#include "../../common.h"

void handle_icmp_payload(u_int length, struct icmphdr *icmp);

#endif //PACKET_SNIFFER_ICMP_HANDLER_H
