#include <fcntl.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <sys/stat.h> 
#include <stdlib.h> 
#include <string.h> 
#include <errno.h> 
 
int main(int argc, char const *argv[])
{
    int fd;
    char *pipe_path = "/tmp/myfifo";
    //对有名管道的特殊文件名
    fd = open(pipe_path,O_RDONLY);
    if(fd==-1)
    {
        perror("open");
        if(errno!=17)
        {
            exit(EXIT_FAILURE);
        }
    }
    char buf[100];
    ssize_t read_num;
    while ((read_num=read(fd,buf,100))>0)
    {
        write(STDOUT_FILENO,buf,read_num);
    }
    
    if(read_num <= 0)
    {
        perror("read");
        close(fd);
        exit(EXIT_FAILURE);
    }
    printf("接受管道数据完成");
    close(fd);
    //释放管道
    if(unlink(pipe_path)==-1)
    {
        perror("unlink");
    }
    return 0;
}
