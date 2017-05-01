#include "icmp_handler.h"

void handle_icmp_payload(u_int length, struct icmphdr *icmp) {
    if(length < ICMP_HEADER_LENGTH) {
        printf(TRUNCATED_STRING, "ICMP", length);
        return;
    }
    switch (icmp->type) {
        case ICMP_ECHO:
            printf("ICMP type: Echo Request\n");
            break;
        case ICMP_ECHOREPLY:
            printf("ICMP type: Echo Reply\n");
            break;
        default:
            printf("ICMP type: unknown\n");
            break;
    }
    printf("ICMP code: %d\n", icmp->code);
    printf("ICMP payload: %s\n", (u_char*) icmp + ICMP_HEADER_LENGTH);
}