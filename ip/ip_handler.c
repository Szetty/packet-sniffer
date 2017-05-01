#include "ip_handler.h"

void handle_ip_payload(u_int length, struct ip *ip)
{
    if (length < IP_HEADER_LENGTH)
    {
        printf(TRUNCATED_STRING, "IP", length);
        return;
    }
    u_int header_length = (ip->ip_hl) * 4;
    u_int version = ip->ip_v;
    u_int payload_length = length - header_length;
    if(version != 4) {
        printf("Unknown version %d\n", version);
        return;
    }
    if(header_length < 20) {
        printf("Bad ip header length %d\n", header_length);
        return;
    }
    if(length != ntohs(ip->ip_len)) {
        printf("Invalid IP datagram length - expected: %d, actual: %d\n", length, length);
        return;
    }
    printf("IP length: %d\n", length);
    printf("Source address: %s\n", IP_TO_STRING(ip->ip_src));
    printf("Destination address: %s\n", IP_TO_STRING(ip->ip_dst));
    printf("IP payload length: %d\n", payload_length);
    switch (ip->ip_p) {
        case IP_TCP:
            printf(IP_PROTOCOL_STRING_FORMAT, "TCP");
            handle_tcp_payload(payload_length, (struct tcphdr *) MOVE_POINTER_BY(ip, header_length));
            break;
        case IP_UDP:
            printf(IP_PROTOCOL_STRING_FORMAT, "UDP");
            handle_udp_payload(payload_length, (struct udphdr *) MOVE_POINTER_BY(ip, header_length));
            break;
        case IP_ICMP:
            printf(IP_PROTOCOL_STRING_FORMAT, "ICMP");
            handle_icmp_payload(payload_length, (struct icmphdr *) MOVE_POINTER_BY(ip, header_length));
            break;
        default:
            printf(IP_PROTOCOL_STRING_FORMAT, "unknown");
            break;
    }
}