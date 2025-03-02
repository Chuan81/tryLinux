#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>

int main()
{
    /**
     * char *__path: 文件打开的路径
     * int __oflag: 打开文件的模式
     *  (1) O_RDONLY 只读模式
     *  (2) O_WRONLY 只写模式
     *  (3) O_RDWR 读写模式
     *  (4) O_CREAT 如果文件不存在，则创建一个新文件
     *  (5) O_APPEND 将所有写入操作追加到文件的末尾
     *  (6) O_TRUNC 如果文件存在并且以写入模式打开，则截断文件长度为0
     * ...可变参数: mode->仅在使用了O_CREAT一起使用时,用于指定新创建文件的权限位 权限位通常由三位八进制数字组成
     * return 
     *  (1)成功时返回非负的文件描述符
     *  (2)失败时返回-1,并设置全局变量errno以指示错误原因.
     * int open (const char *__path, int __oflag, ...)
     */
    int fd = open("io.txt",O_RDONLY | O_CREAT,0664);
    if(fd==-1)
    {
        printf("打开文件失败\n");
    }
    return 0;
}