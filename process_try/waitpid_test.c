#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    //fork之前
    printf("老学员在校区");
    int subprocess_status;
    pid_t pid = fork();
    if(pid<0)
    {
        perror("fork");
        return 1;
    }
    else if (pid==0)
    {
        char *args[]={"/usr/sbin/ping","-c","6","www.baidu.com",NULL};
        char *envs[]={NULL};
        printf("新学员打开百度6次\n");
        int exR = execve(args[0],args,envs);
        if(exR < 0)
        {
            perror("execve");
            return 1;
        }
    }
    else
    {
        printf("老学员%d等待新学员%d登录百度\n",getpid(),pid);
        waitpid(pid,&subprocess_status,0);
    }
    
    printf("老学员等待完毕\n");

    return 0;
}
