#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#define __NR_hello 436
#define __NR_swrite 437
#define __NR_sread 438

int main() {
    // int n=0;
    // n = syscall(__NR_hello, 9, 7);
    // printf("return value: %d\n", n);

    char buf[1024];
    int fdin = open("input.txt", O_RDONLY);

    // read(fdin, buf, 11);
    syscall(__NR_sread, fdin, buf, 7);
    
    for(int i=0;i<7;i++) {
        printf("[%d]%d %c\n",i,buf[i],buf[i]);
    }
    printf("\n--------\n\n");

    for(int i=0;i<7;i++) {
        buf[i] = ~buf[i];
    }

    for(int i=0;i<7;i++) {
        printf("[%d]%d %c\n",i,buf[i],buf[i]);
    }

    return 0;
}