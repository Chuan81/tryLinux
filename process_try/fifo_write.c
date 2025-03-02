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
    if(mkfifo(pipe_path,0664)!=0)
    {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    //对有名管道的特殊文件名
    fd = open(pipe_path,O_WRONLY);
    if(fd==-1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }
    char buf[100];
    ssize_t read_num;
    while((read_num=read(STDIN_FILENO,buf,100))>0)
    {
        write(fd,buf,read_num);
    }
    if(read_num < 0)
    {
        perror("read");
        close(fd);
        exit(EXIT_FAILURE);
    }
    printf("发送数据到管道完成");
    
    //释放管道
    if(unlink(pipe_path)==-1)
    {
        perror("unlink");
    }
    close(fd);
    return 0;
}
