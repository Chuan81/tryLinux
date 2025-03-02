#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
    int fd = open("io123.txt", O_RDONLY);

    if(fd == -1)
    {
        perror("打开文件失败");
        _exit(1);
    }

    char buffer[1024];
    ssize_t byte_read;
    /**
     * return: ssize_t -> long int : 读取到的数据的字节长度 成功大于1 失败-1
     */
    while(byte_read = read(fd,buffer,sizeof(buffer)))
    {
        write(STDOUT_FILENO,buffer,byte_read);
    }

    if(byte_read==-1)
    {
        perror("读取文件错误");
        close(fd);
        exit(EXIT_FAILURE);
    }

    close(fd);
    return 0;
}