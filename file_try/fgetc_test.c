#include <stdio.h>

int main()
{
    //打开文件
    FILE *ioFILE = fopen("io.txt","r");
    if(ioFILE==NULL)
    {
        printf("无法打开指定文件\n");
    }

    //读取文件内容
    /**
     *  FILE *__stream :需要打开的文件
     *  return :成功返回读取的1个字节
     *      出错或读取文件末尾返回EOF
     *  int fgetc (FILE *__stream);
     */
    char a = fgetc(ioFILE);
    while (a!=EOF)
    {
        printf("%c",a);
        a = fgetc(ioFILE);
    }
    printf("\n");
    
    // printf("%c\n",a);
    // a = fgetc(ioFILE);
    // printf("%c\n",a);

    //关闭文件
    int closeR = fclose(ioFILE);
    if(closeR==EOF)
    {
        printf("关闭文件失败");
    }
    return 0;
}