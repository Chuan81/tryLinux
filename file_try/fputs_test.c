#include <stdio.h>

int main()
{   
    /**
     * char *__restrict __文件名(字符串)，表示要打开的文件名称
     * const char *__restrict __访问模式(字符串)
     *      (1) r: 只读模式 如果文件不存在会报错
     *      (2) w: 只写模式 如果文件存在清空文件 如果文件不存在会创建该文件
     *      (3) a: 只追加写模式 如果文件存在则在末尾追加写 如果文件不存在会创建该文件
     *      (4) r+: 读写模式 文件必须存在 写入是从头覆盖
     *      (5) w+: 读写模式 如果文件存在清空文件 如果文件不存在会创建该文件 
     *      (6) a+: 读追加写模式 如果文件存在末尾追加写 如果不存在创建新文件
     * return: FILE* 结构体指针 表示一个文件
     *      报错返回NULL
     * FILE *fopen (const char *__restrict __filename,
		    const char *__restrict __modes)
     */
    char* filename = "io.txt";
    FILE* ioFile = fopen(filename, "w");
    if (ioFile==NULL)
    {
        printf("failed 打开文件失败\n");
    }
    else
    {
        printf("success 打开文件成功\n");
    }
    
    /**
     *  const char *__restrict :需要写入的字符串
     *  FILE *__restrict :需要写入的文件
     *  return 成功返回非负整数(一般为0或1，不做区分)
     *      失败返回EOF(-1)
     *  int fputs (const char *__restrict __s, FILE *__restrict __stream)
     */
    if(fputs("Hello,world",ioFile)>=0)
    {
        printf("写入成功\n");
    }
    else
    {
        printf("写入失败\n");
    }

    /**
     * FILE *__stream: 需要关闭的文件
     * return: 成功返回0 失败(不报错的情况下)返回EOF(负数)
     *      通常关闭失败都会直接报错
     * int fclose (FILE *__stream);
     */
    int result = fclose(ioFile);
    if(result==0)
    {
        printf("关闭成功\n");
    }
    else
    {
        printf("关闭失败 EOF!!\n");
    }
    return 0;
}