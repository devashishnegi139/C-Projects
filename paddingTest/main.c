#include <stdio.h>
#include <stdint.h>

struct test{
    uint32_t var1;
    uint8_t var2;
    uint16_t var3;
    char var4;
};

int main(){
    struct test t1 = {0xaa, 0xbb, 0xcc, 0xdd};
    
    return 0;
}