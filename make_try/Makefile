# Makefile内容通常有以下三部分构成
# <目标文件>:<前置依赖>
# 	\t<需要执行的命令>
# 目标文件的名称由gcc -o 后边的名称决定
# <目标文件>这一行决定make过程中对目标文件的监控，如果存在就不执行第二行命令，反之执行


# 定义变量
object := hello.o \
main.o
# object := hello.o main.o

main: $(object)#hello.o main.o
	gcc hello.o main.o -o main

# main.o:main.c hello.h
# 	gcc -c main.c

#hello.o:hello.c hello.h
hello.o: hello.h
# 	gcc -c hello.c

# ^
#自动推导功能，但是无法监控.h文件变化，所以推荐省略.c文件即可

#显式伪目标声明
# .PHONY : clean
# 声明后不会受同名文件影响make clean的使用
# 否则如果存在./clean文件，make clean将无法使用
#clean属于隐式伪目标
clean:
	-rm main $(object)
# clean:
# 	rm main $(object)
# 加-可以忽略指令的报错
