#include <stdio.h>
// counts # of 1 bits in r
int N(int r){ int n; for (n=r&&1; r-=r&-r; ++n); return n; }
int M(int *b, int m){ return m&~(*b|*b<<9|*b>>9)?*b|=m:0; }
// computers the nth win layout
int W(int n){int u,v,w;w=0x1000/(u=1<<(++n)/3+(n==8))/(v=010<<n%3);return u|v|w;}
// computer plays the lower bits.
int S(int *b){
	// win or block win
	int u, v, w, m, o;

	for (int i = 0; i < 16; ++i) {
		m=W(i%8);
		if (N(m&*b>>(i/8?9:0))==2 && M(b, m^m&(*b|*b>>9))) {
			return 1;
		}
	}

	// fork or block fork
	
	// centre
	// opposite corner
	// corner
	// edge


	//first available move:
	for (int i = 1; i<1<<18; i <<= 1) {
		if (M(b,i)){ return 1; }
	}
	return 0;
}
int a[]={3,8,1,2,4,6,7,0,5};
// X=88, O=79, .=46
void P(int b){
	int *c, *e; for(e=(c=a)+2; c-a<9; e+=(*c++==*e)*3){
	printf("%c%c", b&1<<*c?88:88-(b&1<<*c+9?9:6*7), *c-*e?0:10);}
}

int main(void){
	int b=0; char c[2];
	while (scanf("%s", c)) {
		if ('/'<*c && *c<'9' && M(&b,1<<a[*c-'0']+9)) {
			P(b);
			if(!S(&b)){ puts("BORK."); break; }
			P(b);
		}
	}

	return 0;
}
