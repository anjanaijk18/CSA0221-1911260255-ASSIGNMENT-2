#include <stdio.h>
enum { LIGHT, FAN, AC, HEATER, PUMP };

unsigned char switch_on(unsigned char r, int d) {
return r | (1u << d);
}

unsigned char switch_off(unsigned char r, int d) {
return r & ~(1u << d);
}

unsigned char toggle(unsigned char r, int d) {
return r ^ (1u << d);
}

int is_on(unsigned char r, int d) {
return (r >> d) & 1u;
}

void show(unsigned char r) {
for(int i=7; i>=0; i--)
printf("%d", (r >> i) & 1u);
printf("\n");
}

int main() {
unsigned char reg = 0;

reg = switch_on(reg, LIGHT);
reg = switch_on(reg, AC);
show(reg);

reg = toggle(reg, FAN);
reg = switch_off(reg, LIGHT);
show(reg);

printf("AC is %s, PUMP is %s\n",
is_on(reg, AC) ? "ON" : "OFF",
is_on(reg, PUMP) ? "ON" : "OFF");

return 0;
}
