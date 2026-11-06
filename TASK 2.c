#include <stdio.h>
int calls = 0, audit[1000], count = 0;

int verify(int id, int card)
{
calls++;
audit[count++] = id;
return card;
}

int main()
{
int senior, eligible, card, grant;
int total1 = 0, total2 = 0;

// Order 1: Cheap conditions first
for(int i = 0; i < 1000; i++)
{
    senior = (i % 4 == 0);
    eligible = (i % 3 != 0);
    card = (i % 10 == 0);

    if((senior && eligible) || verify(i, card))
        total1++;
}

printf("Order 1:\n");
printf("Concessions = %d\n", total1);
printf("Server calls = %d\n", calls);

// Reset counters
calls = 0;
count = 0;

// Order 2: Slow condition first
for(int i = 0; i < 1000; i++)
{
    senior = (i % 4 == 0);
    eligible = (i % 3 != 0);
    card = (i % 10 == 0);

    if(verify(i, card) || (senior && eligible))
        total2++;
}

printf("\nOrder 2:\n");
printf("Concessions = %d\n", total2);
printf("Server calls = %d\n", calls);

return 0;
}
