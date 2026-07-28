// gcc -o fibonacci.out fibonacci.c && ./fibonacci.out

#include <stdio.h>

void fibonacci(int limit)
{
    printf("Fibonnaci to %d is [", limit);

    int a = 0;
    int b = 1;
    while (a < limit) {
        printf(" %d", a);
        int temp = a;
        a = b;
        b = a + temp;
    }

    printf(" ]\n");
}

int main(void)
{
    fibonacci(100);
    return 0;
}
