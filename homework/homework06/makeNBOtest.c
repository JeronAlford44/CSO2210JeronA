#include <stdio.h>
#include <stdint.h>

extern uint32_t make_network_byte_order(uint32_t num);

int main() {
    uint32_t test_num = 0x12345678;
    uint32_t result = make_network_byte_order(test_num);
    printf("Original: 0x%x, Network Byte Order: 0x%x\n", test_num, result);
    return 0;
}