#include <stdio.h>

char grade_if(int m)
{
    if(m < 0 || m > 100) return '?';
    else if(m >= 90) return 'S';
    else if(m >= 80) return 'A';
    else if(m >= 70) return 'B';
    else if(m >= 60) return 'C';
    else if(m >= 50) return 'D';
    else return 'F';
}

char grade_switch(int m)
{
    if(m < 0 || m > 100) return '?';

    switch(m / 10)
    {
        case 10: case 9: return 'S';
        case 8: return 'A';
        case 7: return 'B';
        case 6: return 'C';
        case 5: return 'D';
        default: return 'F';
    }
}

int main()
{
    int marks[] = {100, 95, 83, 50, 49, -5};
    int n = 6, i;

    printf("ELSE-IF LADDER:\n");
    for(i = 0; i < n; i++)
        printf("%d = %c\n", marks[i], grade_if(marks[i]));

    printf("\nSWITCH STATEMENT:\n");
    for(i = 0; i < n; i++)
        printf("%d = %c\n", marks[i], grade_switch(marks[i]));

    return 0;
}
