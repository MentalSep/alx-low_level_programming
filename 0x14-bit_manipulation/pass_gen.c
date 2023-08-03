#include <stdio.h>
#include "main.h"
#include <fcntl.h>
#include <unistd.h>

unsigned int generate_password(int index);

int main(void)
{
    int fd = open("101-password", O_CREAT | O_RDWR, 0644);

    dprintf(fd, "%c", generate_password(0));
    dprintf(fd, "%c", generate_password(1));
    dprintf(fd, "%c", generate_password(2));
    dprintf(fd, "%c", generate_password(3));
    
    close(fd);
}
unsigned int generate_password(int index)
{
    return ((unsigned int)(0x46c6f48 >> ((unsigned char)index << 3 & 0xff) & 0xff));
}