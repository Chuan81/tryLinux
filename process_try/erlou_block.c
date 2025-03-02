#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char const *argv[])
{
    if(argc<2)
    {
        printf("参数不足,不能上二楼\n");
    }
    printf("我是%s 编号%d,我上二楼了\n",argv[1],getpid());
    sleep(100);
    return 0;
}
