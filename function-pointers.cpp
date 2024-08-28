#include <stdio.h>

void *ex_memcpy(void *dst, void *src, int size);
void *headtotail(void *dst, void *src, int size);
void *tailtohead(void *dst, void *src, int size);
                              
int main(int argc, char **argv)
{                                
        int first = atoi(argv[1]), second = atoi(argv[2]);
                 
        ex_memcpy((void *)first, (void *)second, 100);
                
        return 0;
}

void *ex_memcpy(void *dst, void *src, int size)
{                                              
        void * (*x[])(void *, void *, int) = { headtotail, tailtohead };
        return x[dst > src](dst, src, size);
}

void *headtotail(void *dst, void *src, int size)
{       
        printf("stubbed:  do a head to tail copy");
        return dst;
}
                                              
void *tailtohead(void *dst, void *src, int size)
{                               
        printf("stubbed:  do a tail to head copy");
        return dst;
}
