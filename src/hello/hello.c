//usr/bin/gcc -o hello.out hello.c && exec ./hello.out

#include <stdio.h>

void hello(const char* name)
{
    printf("Hello, %s!\n", name);
}

int main(int argc, char** argv)
{
    hello("Bob");
    return 0;
}
