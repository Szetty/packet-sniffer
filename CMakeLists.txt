cmake_minimum_required(VERSION 3.7)
project(packet_sniffer)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        packet_sniffer.c ip/ip_handler.c ip/ip_handler.h common.h arp/arp_handler.c arp/arp_handler.h ip/icmp/icmp_handler.c ip/icmp/icmp_handler.h ip/tcp/tcp_handler.c ip/tcp/tcp_handler.h ip/udp/udp_handler.c ip/udp/udp_handler.h)

add_executable(packet_sniffer ${SOURCE_FILES})
target_link_libraries(packet_sniffer pcap)