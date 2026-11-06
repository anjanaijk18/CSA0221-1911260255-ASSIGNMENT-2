#include <stdio.h>

unsigned long checks = 0;

int prime_basic(unsigned long n)
{
    checks = 0;
    if(n < 2) return 0;

    for(unsigned long i = 2; i < n; i++)
    {
        checks++;
        if(n % i == 0) return 0;
    }
    return 1;
}

int is_prime(unsigned long n)
{
    checks = 0;
    if(n < 2) return 0;

    for(unsigned long i = 2; i <= n / i; i++)
    {
        checks++;
        if(n % i == 0) return 0;
    }
    return 1;
}

int prime_while(unsigned long n)
{
    checks = 0;
    if(n < 2) return 0;

    unsigned long i = 2;
    while(i <= n / i)
    {
        checks++;
        if(n % i == 0) return 0;
        i++;
    }
    return 1;
}

int prime_do(unsigned long n)
{
    checks = 0;
    if(n < 2) return 0;

    unsigned long i = 2;
    do
    {
        checks++;
        if(n % i == 0) return 0;
        i++;
    } while(i <= n / i);

    return 1;
}

int main()
{
    unsigned long a[] = {97, 100, 7919, 1000003};

    for(int i = 0; i < 4; i++)
    {
        int result = is_prime(a[i]);

        printf("%lu %s divisions=%lu\n",
            a[i], result ? "prime" : "not prime", checks);
    }

    return 0;
}
