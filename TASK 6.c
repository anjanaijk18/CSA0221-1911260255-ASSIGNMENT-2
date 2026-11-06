#include <stdio.h>

int main()
{
    float balance = 10000;
    float rate = 2, payment = 2000;
    float interest, total = 0;
    int month = 0;

    if(payment <= balance * rate / 100)
    {
        printf("Payment is too low!\n");
        return 0;
    }

    printf("Month\tInterest\tPayment\tBalance\n");

    while(balance > 0.005 && month < 360)
    {
        month++;
        interest = balance * rate / 100;
        total += interest;
        balance += interest;

        float paid = payment;
        if(paid > balance)
            paid = balance;

        balance -= paid;

        printf("%d\t%.2f\t\t%.2f\t%.2f\n",
               month, interest, paid, balance);
    }

    printf("\nLoan repaid in %d months\n", month);
    printf("Total interest = Rs. %.2f\n", total);

    return 0;
}
