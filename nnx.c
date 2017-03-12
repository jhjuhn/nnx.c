#include <stdio.h>
// counts # of 1 bits in r
int N(int r){ int n; for (n=r&&1; r-=r&-r; ++n); return n; }
int O(int b){ return b<<9; }
// computes the ith winning position.
int w[8];
int W(int n){int r,s,t;return (t=0x1000/(r=1<<(++n)/3+(n==010))/(s=010<<n%3))|r|s;}
// computer plays the lower bits.
int S(int *b){
	int f, x;
	int i, j;
	// win or block win.
	for (int k = 0; k < 16; ++k) { j = k%8;
		f = w[j]; x = (w)[j]^(j)[w]&*b>>9;
		if (N(f&*b>>(k>7?9:0)) == 2 && N(f&(*b|*b>>9)) == 2) {
			return *b|= x;
		}
	}
	// fork or block fork
	for (int k = 0; k < 128; ++k) { i = k%64/8; j = k%64%8;
		f = w[i]|w[j]; x = w[i]&w[j];
		if (N(f&*b>>(k>63?9:0)) == 2 && N(f&(*b|*b>>9)) == 2 && x) {
			return *b|=x;
		}
	}

		
	// centre
	// opposite corner
	// corner
	// edge


	//first available move:
	puts("confused.");
	for (int i = 1; i<1<<9; i <<= 1) {
		if (!(i&(*b|*b>>9))) { return *b|=i; }
	}
	return 0;
}
int a[]={3,8,1,2,4,6,7,0,5};

// prints the game board.
void P(int b){ int *c, *e; for(e=(c=a)+2; c-a<9; e+=(*c++==*e)*3){
printf("%c%c", b&1<<*c?88:88-(b&1<<*c+9?9:6*7), *c-*e?0:10);}}

int main(void){
	for (int i = 0; i < 8; ++i) { w[i] = W(i); }
	int b = 512<<1|1<<6;
	//int b = 0;
	char c[2];
	P(b);
	while (scanf("%s", c)) {
		if (('/'-*c)*(*c-'9')>0 &&
		(1<<a[*c-'0'])&~(b|b>>9)) {
			b |= 1<<9+a[*c-'0'];
			P(b);
			S(&b);
			P(b);
		}
	}

	return 0;
}
