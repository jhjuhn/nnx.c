#include <stdio.h>
int w[] = {0, 0, 0, 0, 0, 0, 0, 0, 3, 8, 1, 2, 4, 6, 7, 0, 5}; int *a = w+8;
int W(int n){int r,s,t;return (t=0x1000/(r=1<<(++n)/3+(n==010))/(s=010<<n%3))|r|s;}
// prints the game board.
void P(int b){ int *c, *e; for(e=(c=a)+2; c-a<9; e+=(*c++==*e)*3){
printf("%c%c", b&1<<*c?88:88-(b&1<<*c+9?9:6*7), *c-*e?0:10);}}

int M(int b, int t){ int r, m, j, *k; for (k = w; k < w+17; ++k) {
if (k-w<010 && (r=3*((b&*k)==*k)|2*((511&(b|b>>9))==511)|((b>>9&*k)==*k))) {
return r<<18; } if (k-w>010-1) { r=(k-w-8)?r:2-2*t<<18;
r=((j=1<<*k)^j&(b|b>>9) && t*(m=M(b|j<<(1+t?0:9),-t))-r*t>0)?3<<022&m|j:r; }
} return r; }

int main(void){
	for (int i = 0; i < 8; ++i) { w[i] = W(i); }
	int b = 0; int t = 1; //1-> user plays X
	char c[2];
	P(b);
	while (scanf("%s", c)) {
		if (('/'-*c)*(*c-'9')>0 &&
		(1<<a[*c-'0'])&~(b|b>>9)) {
			b |= 1<<a[*c-'0']+(t+1?0:9);

			P(b);
			b|=((1<<18)-1)&M(b, -t)<<(t+1?9:0);
			P(b);
		}
	}

	return 0;
}
