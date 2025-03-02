#include <stdio.h>

int main()
{
    //打开文件
    FILE *ioFILE = fopen("user.txt","r");
    if(ioFILE==NULL)
    {
        printf("无法打开指定文件\n");
    }

    /**
     * FILE *__restrict __stream :打开的文件
     * const char *__restrict __format :带有格式化的字符串(固定格式接收)
     * ...可变参数：填写格式化的字符串(存放数据提前声明的变量)
     * return :成功匹配到的参数的个数 如果匹配失败返回0 报错或文件结束EOF
     * int fscanf (FILE *__restrict __stream,
	 *	   const char *__restrict __format, ...)
     */
    char name[50];
    int age;
    char wife[40];
    int scanR = fscanf(ioFILE,"%s %d %s",name,&age,wife);
    if (scanR!=EOF)
    {
        printf("成功匹配参数为%d\n",scanR);
        printf("%s在%d岁爱上%s\n",name,age,wife);
    }

    while (scanR!=EOF)
    {
        printf("成功匹配参数为%d\n",scanR);
        printf("%s在%d岁爱上%s\n",name,age,wife);
        scanR = fscanf(ioFILE,"%s %d %s",name,&age,wife);
    }
    

    //关闭文件
    int closeR = fclose(ioFILE);
    if(closeR==EOF)
    {
        printf("关闭文件失败");
    }
    return 0;
}