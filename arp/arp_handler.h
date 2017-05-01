#ifndef PACKET_SNIFFER_ARP_HANDLER_H
#define PACKET_SNIFFER_ARP_HANDLER_H

#include "../common.h"

void handle_arp_payload(u_int length, struct arphdr* arp);

#endif //PACKET_SNIFFER_ARP_HANDLER_H
