#include <stdio.h>
#include <stdint.h>

struct test{
    // put your varables here
    uint32_t var1;
    uint8_t var2;
    uint8_t var3;
    uint8_t var4;
};

int main(){
    // fill values in t1 accoudingly
    struct test t1 = {0xaa, 0xbb, 0xcc, 0xdd};
    char *p = (char *)&t1;

    for(unsigned long long i=0; i<sizeof(struct test); i++){
        printf("%p\t%x\n", p, *p);
        if(i!=0 && (i+1)%4==0)
            printf("-----------------------------------------------\n");
        p++;
    }
    return 0;
}