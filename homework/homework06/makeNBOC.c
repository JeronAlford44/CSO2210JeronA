#include <stdint.h>
#include <stdio.h>

uint32_t swap_bytes(uint32_t num) {
    return ((num >> 24) & 0xff) |    
           ((num << 8) & 0xff0000) |  
           ((num >> 8) & 0xff00) |   
           ((num << 24) & 0xff000000);
}

uint32_t make_network_byte_order(uint32_t num) {
    unsigned int x = 1;
    char *c = (char*)&x;

    if (*c) {
        return swap_bytes(num); 
    }
    return num; 
}
