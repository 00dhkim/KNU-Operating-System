#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define __NR_hello 436
#define __NR_swrite 437
#define __NR_sread 438

#define BUFSIZE 100

void to_binary(char* buf) {
    unsigned char p;

    for(int j=0; j<strlen(buf); j++) {
        p = 0x80;
        for(int i=0; i<8; i++) {
            if(buf[j] & p) printf("1");
            else printf("0");
            p = p>>1;
        }
        printf(" ");
    }
    printf("\n");
}

int main() {
    char *temp1;
    char *temp2;
    int fd;
    temp1 = (char*)calloc(100, sizeof(char));
    temp2 = (char*)calloc(100, sizeof(char));
    
    printf("Input data: ");
    scanf("%s", temp1);
    printf("Input binary data: ");
    to_binary(temp1);

    if(0 < (fd = open("./test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644))) {
        syscall(__NR_swrite, fd, temp1, strlen(temp1));
        close(fd);
    }
    else {
        printf("open error\n");
        exit(-1);
    }

    if(0 < (fd=open("./test.txt", O_RDONLY, 0644))) {
        read(fd, temp2, BUFSIZE);
        close(fd);
    }
    else {
        printf("Open error\n");
        exit(-1);
    }

    printf("sys_read() data: %s\n", temp2);
    printf("sys_read() binary data: ");
    to_binary(temp2);


    return 0;
}