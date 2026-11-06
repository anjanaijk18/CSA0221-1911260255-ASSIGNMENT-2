#include <stdio.h>
int main()
{
double price, qty, senior, total, net;
double p[]={100,250,150}, q[]={2,5,8};
int s[]={1,1,0};

for(int i=0;i<3;i++)
{
    price=p[i];
    qty=q[i];
    senior=s[i];

    total=price*qty;
    if(senior)
        total-=total*15/100;

    total+=total*5/100;
    net=(total>1000)?total-20:total;

    printf("Bill %d: Total=%.2f Net=%.2f\n",
           i+1,total,net);
}
return 0;
}
