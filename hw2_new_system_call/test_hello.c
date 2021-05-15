#include <unistd.h>
#Include <stdio.h>

#define __NR_hello 436

int main() {
    int n=0;
    n = syscall(__NR_hello, 9, 7);
    printf("return value: %d\n", n);

    return 0;
}