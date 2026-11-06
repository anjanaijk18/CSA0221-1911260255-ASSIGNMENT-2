#include <stdio.h>

int old_prime(unsigned long n, int *count)
{
    *count = 0;
    if(n < 2) return 0;

    for(unsigned long i = 2; i <= n / i; i++)
    {
        (*count)++;
        if(n % i == 0) return 0;
    }
    return 1;
}

int new_prime(unsigned long n, int *count)
{
    *count = 0;
    if(n < 2) return 0;
    if(n == 2) return 1;

    (*count)++;
    if(n % 2 == 0) return 0;

    for(unsigned long i = 3; i <= n / i; i += 2)
    {
        (*count)++;
        if(n % i == 0) return 0;
    }
    return 1;
}

int main()
{
    unsigned long a[] = {97, 100, 7919, 1000003};
    int old_count, new_count;

    printf("Number  Result      Old Checks  New Checks\n");

    for(int i = 0; i < 4; i++)
    {
        int result = old_prime(a[i], &old_count);
        new_prime(a[i], &new_count);

        printf("%lu    %-10s  %-10d  %d\n",
               a[i], result ? "Prime" : "Not Prime",
               old_count, new_count);
    }

    return 0;
}
