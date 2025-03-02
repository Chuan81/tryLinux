#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    __pid_t cpid;
    int pipefd[2];
    //将程序传递进来的命令行参数，通过匿名管道传输给子进程
    if(argc!=2)
    {
        fprintf(stderr,"%s:请填写需要传递的信息\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    //创建管道
    if(pipe(pipefd)==-1)
    {
        perror("创建管道失败");
        exit(EXIT_FAILURE);
    }
    cpid = fork();
    if(cpid==-1)
    {
        perror("邀请新学员失败\n");
        exit(EXIT_FAILURE);
    }
    else if(cpid==0)
    {
        //子进程 读取管道的数据 打印到控制台
        close(pipefd[1]);
        printf("新学员接受信息ing\n");
        char str[100]={""};
        while(read(pipefd[0],&str,1)>0)
        {
            write(STDOUT_FILENO,&str,1);
        }
        write(STDOUT_FILENO,"\n",1);
        close(pipefd[0]);
    }
    else
    {
        //父进程 写入管道数据，提供给子进程
        close(pipefd[0]);
        printf("老学员%d对新学员%d传递信息\n",getpid(),cpid);
        write(pipefd[1],argv[1],strlen(argv[1]));
        close(pipefd[1]);
        waitpid(cpid,NULL,0);
        exit(EXIT_SUCCESS);
    }
    return 0;
}
