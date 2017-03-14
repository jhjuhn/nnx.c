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

int M(int b, int t){
	int u = 3<<18;
	for (int i = 0; i < 8; ++i) {
		if (N(b&w[i])==3) { return 3<<18; }
		if (N(b>>9&w[i])==3) { return 1<18; }
	}
	if (N(b)==9) { return 2<<18; }

	int r, x, m;
	if (t == 1) {
		r = 0; x = 0;
		for (int j = 1; j < 1<<9; j*=2) {
			if(j^j&(b|b>>9)) {
				m = M(b|j, -1);
				if (m > r) {
					r = u&m|j;
					x = j;
				}
			}
		}
	}

	if (t == -1) {
		r = 4<<18; x = 0;
		for (int j = 1; j < 1<<9; j*=2) {
			if(j^j&(b|b>>9)) {
				m = M(b|j<<9, 1);
				if (m < r) {
					r = u&m|j;
					x = j<<9;
				}
			}
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
			b |= 1<<9+a[*c-'0'];

			P(b);
			//b=S(b);
			b|=((1<<18)-1)&M(b, 1);
			P(b);
		}
	}

	return 0;
}
