#include <stdio.h>

int main(int argc, char const *argv[])
{
    fopen("nothisfile","r");
    perror("open");
    return 0;
}
