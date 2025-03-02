#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <sys/types.h> 
 
int main(int argc, char const *argv[])
{
    //邀请之前
    char *name = "老学员";

    printf("%s %d继续在一楼精进\n",name,getpid());

    //邀请新学员
    __pid_t pid = fork();
    if(pid == -1)
    {
        printf("邀请新学员失败\n");
        return 1;
    }
    else if(pid==0)
    {
        //新学员
        char *new_name = "ergou";
        char *args[]={"/root/tryLinux/process_try/erlou",new_name,NULL};
        char *envs[]={NULL};
        printf("新学员父进程为%d\n",getppid());
        int exR = execve(args[0],args,envs);
        if(exR==-1)
        {
            printf("新学员上二楼失败\n");
            return 1;
        }
    }
    else
    {
        printf("老学员%d邀请完%d之后还是在一楼学习\n",getpid(),pid);
        sleep(1);
    }
    return 0;
}
