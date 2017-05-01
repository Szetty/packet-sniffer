#include "arp_handler.h"

void handle_arp_payload(u_int length, struct arphdr* arp) {
    uint16_t protocol_type;
    int hardware_address_length, protocol_address_length;
    u_char *source_hardware_address, *source_protocol_address;
    u_char *destination_hardware_address, *destination_protocol_address;
    if(length < ARP_HEADER_LENGTH) {
        printf(TRUNCATED_STRING, "ARP", length);
        return;
    }
    protocol_type = ntohs(arp->ar_pro);
    if(protocol_type != 0x800) {
        printf("Invalid arp protocol type\n");
        return;
    }
    switch (ntohs(arp->ar_op)) {
        case ARPOP_REQUEST:
            printf("Operation: REQUEST\n");
            break;
        case ARPOP_REPLY:
            printf("Operation: REPLY\n");
            break;
        default:
            printf("Operation: other\n");
    }
    hardware_address_length = arp->ar_hln;
    printf("MAC address length: %d\n", hardware_address_length);
    protocol_address_length = arp->ar_pln;
    printf("IP address length: %d\n", protocol_address_length);
    source_hardware_address = ((u_char*)arp + ARP_HEADER_LENGTH);
    source_protocol_address = source_hardware_address + hardware_address_length;
    destination_hardware_address = source_protocol_address + protocol_address_length;
    destination_protocol_address = destination_hardware_address + hardware_address_length;
    printf("Sender MAC address: %s\n", MAC_TO_STRING(source_hardware_address));
    printf("Sender IP address: %s\n", IP_TO_STRING(*((struct in_addr*)source_protocol_address)));
    printf("Target MAC address: %s\n", MAC_TO_STRING(destination_hardware_address));
    printf("Target IP address: %s\n", IP_TO_STRING(*((struct in_addr*)destination_protocol_address)));
}