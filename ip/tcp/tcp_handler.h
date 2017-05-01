#ifndef PACKET_SNIFFER_TCP_HANDLER_H
#define PACKET_SNIFFER_TCP_HANDLER_H

#include "../../common.h"

#define HTML_PRINT_LENGTH 200

void handle_html_payload(u_int length, u_char* payload);
void handle_tcp_payload(u_int length, struct tcphdr *tcp);

#endif //PACKET_SNIFFER_TCP_HANDLER_H
