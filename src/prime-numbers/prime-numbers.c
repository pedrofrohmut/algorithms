// prime-numbers.c

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* arr;
    int size;
    int capacity;
} Primes;

bool is_prime(const int n)
{
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

Primes* get_primes(const int limit)
{
    if (limit < 2) {
        printf("Limit can only be an integer bigger than 2");
        exit(1);
    }

    Primes* primes = (Primes*) malloc(sizeof(Primes));
    primes->arr = (int*) malloc(sizeof(int) * limit);
    primes->size = 0;
    primes->capacity = limit;

    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            primes->arr[primes->size] = i;
            primes->size++;
        }
    }

    return primes;
}

void print_primes(const Primes* primes, const int limit)
{
    printf("Primes from 2 to %d -> [ ", limit);

    for (int i = 0; i < primes->size; i++) {
        printf("%d", primes->arr[i]);

        if (i < primes->size - 1) {
            printf(", ");
        }
    }

    printf(" ]\n");
}

int main(void)
{
    const int limit = 100;
    Primes* primes = get_primes(limit);
    print_primes(primes, limit);
    return 0;
}
