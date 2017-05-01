#include "tcp_handler.h"

void handle_tcp_payload(u_int length, struct tcphdr *tcp) {
    if (length < TCP_HEADER_LENGTH)
    {
        printf(TRUNCATED_STRING, "TCP", length);
        return;
    }
    u_int16_t source_port = ntohs((uint16_t) tcp->source);
    u_int16_t header_length = tcp->doff * 4;
    u_int16_t payload_length = length - header_length;

    printf(SOURCE_PORT_STRING, source_port);
    printf(DESTINATION_PORT_STRING, ntohs((uint16_t) tcp->dest));
    printf("TCP header length: %d\n", header_length);
    printf("TCP payload length: %d\n", payload_length);
    if(source_port == 80 && payload_length > 0) {
        handle_html_payload(payload_length, MOVE_POINTER_BY(tcp, header_length));
    }
}

void handle_html_payload(u_int length, u_char* payload) {
    u_int to_display = (length < HTML_PRINT_LENGTH) ? length : HTML_PRINT_LENGTH;
    payload[to_display] = 0;
    printf("HTML payload: %s\n", payload);
}