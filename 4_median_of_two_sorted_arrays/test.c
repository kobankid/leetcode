#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    int i = 0;

    for (i = 0; i < 10; i++) {
        if (i == 5) {
            break;
        }
    }
    printf("i=%d\n",i);
}