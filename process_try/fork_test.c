#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>

int main(int argc,char *argv[])
{
    //调用fork之前 代码都在父进程中运行
    printf("海哥教老学员%d春暖花开\n",getpid());
    // while (1)
    // {
    //     /* code */
    // }
    /**
     *  不需要传参
     *  return: int 进程号
     *      (1):-1 出错
     *      (2):父进程中显示子进程的PID
     *      (3):子进程中显示为0;
     *  __pid_t fork (void);
     */
    pid_t/*int*/ pid = fork();//fork之后的代码将被父进程与子进程各执行一遍
    printf("%d\n",pid);//将打印两遍pid,一份为子进程的pid，一份为0
    //fork创建子进程
    if(pid < 0)
    {
        printf("子进程创建失败");
    }
    else if(pid==0)
    {
        printf("子进程创建成功,这里是子进程\n子进程PID为%d,父进程是%d\n",getpid(),getppid());
    }
    else
    {
        printf("此处为父进程,子进程的PID为%d\n父进程自身的PID为%d\n",pid,getpid());
    }
    return 0;
}