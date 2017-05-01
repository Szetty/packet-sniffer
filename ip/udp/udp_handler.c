#include "udp_handler.h"

void handle_udp_payload(u_int length, struct udphdr *udp) {
    if (length < UDP_HEADER_LENGTH)
    {
        printf(TRUNCATED_STRING, "UDP", length);
        return;
    }
    printf(SOURCE_PORT_STRING, ntohs((uint16_t) udp->source));
    printf(DESTINATION_PORT_STRING, ntohs((uint16_t) udp->dest));
}