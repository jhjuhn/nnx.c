#include <stdio.h>
// counts # of 1 bits in r
int N(int r){ int n; for (n=r&&1; r-=r&-r; ++n); return n; }
// computes the ith winning position.
int a[]={3,8,1,2,4,6,7,0,5};
int w[8];

int W(int n){int r,s,t;return (t=0x1000/(r=1<<(++n)/3+(n==010))/(s=010<<n%3))|r|s;}

// prints the game board.
void P(int b){ int *c, *e; for(e=(c=a)+2; c-a<9; e+=(*c++==*e)*3){
printf("%c%c", b&1<<*c?88:88-(b&1<<*c+9?9:6*7), *c-*e?0:10);}}

int M(int b, int t){ int r, m, *k, u = 3<<18;
	for (k = w; k < w+8; ++k) {
		if (r=3*((b&*k)==*k)|2*((511&(b|b>>9))==511)|((b>>9&*k)==*k)) { return r<<18; }
	}

	r = 2-2*t<<18;
	for (int j = 1; j < 1<<9; j*=2) {
		if(j^j&(b|b>>9) && t*(m=M(b|j<<(1+t?0:9),-t))-r*t>0) {
				r = u&m|j;
		}
	}

	return r;
}

int main(void){
	for (int i = 0; i < 8; ++i) { w[i] = W(i); }
	int b = 0;
	char c[2];
	P(b);
	while (scanf("%s", c)) {
		if (('/'-*c)*(*c-'9')>0 &&
		(1<<a[*c-'0'])&~(b|b>>9)) {
			b |= 1<<a[*c-'0'];

			P(b);
			b|=((1<<18)-1)&M(b, -1)<<9;
			P(b);
		}
	}

	return 0;
}
