

#include "../inc/shell.h"


char *ft_memcpy(char *dst , char *source , size_t size){

    size_t i = 0;
    while(i<size){
        *(unsigned char*)(dst + i) = *(unsigned char *)(source + i);
        i++;
    }
    return dst;
}

