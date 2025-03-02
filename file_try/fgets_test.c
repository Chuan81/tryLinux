#include <stdio.h>

int main()
{
    //打开文件
    FILE *ioFILE = fopen("io.txt","r");
    if(ioFILE==NULL)
    {
        printf("无法打开指定文件\n");
    }

    /**
     * char *__restrict __s:用来存放读取的字符串
     * int __n :接收字符串长度
     * FILE *__restrict __stream:需要读取的文件
     * return :成功返回字符串 失败返回NULL
     * char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     */
    char buffer[1000];
    while (fgets(buffer,sizeof(buffer),ioFILE))
    {
        printf("%s",buffer);
    }
    
    
    //关闭文件
    int closeR = fclose(ioFILE);
    if(closeR==EOF)
    {
        printf("关闭文件失败");
    }
    return 0;
}