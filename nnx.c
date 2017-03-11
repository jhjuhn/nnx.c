#include <stdio.h>
// counts # of 1 bits in r
int N(int r){ int n; for (n=r&&1; r-=r&-r; ++n); return n; }
int O(int b){ return b<<9; }
// computes the ith winning position.
int W(int n){int r,s,t;return (t=0x1000/(r=1<<(++n)/3+(n==010))/(s=010<<n%3))|r|s;}
// computer plays the lower bits.
int S(int *b){
	// win or block win.
	int w;
	for (int i = 0; i < 8; ++i) {
		w = W(i);
		if (N(w&*b) == 2 && N(w&(*b|*b>>9)) == 2) {
			puts("win.");
			return *b|= w^w&*b>>9;
		}
	}
	for (int i = 0; i < 8; ++i) {
		w = W(i);
		if (N(w&*b>>9) == 2 && N(w&(*b|*b>>9)) == 2) {
			puts("blk.");
			return *b|= w^w&*b>>9;
		}
	}
	// fork or block fork
	for (int i = 0; i < 8; ++i) {
	for (int j = 0; j < 8; ++j) { w = W(i)|W(j);
		if (N(w&*b) == 2 && N(w&(*b|*b>>9)) == 2 && W(i)&W(j)) {
			printf("frk %d %d\n", W(i), W(j));
			return *b|=W(i)&W(j);
		}
	}}
	for (int i = 0; i < 8; ++i) {
	for (int j = 0; j < 8; ++j) { w = W(i)|W(j);
		if (N(w&*b>>9) == 2 && N(w&(*b|*b>>9)) == 2 && W(i)&W(j)) {
			printf("bfk %d %d\n", W(i), W(j));
			return *b|=W(i)&W(j);
		}
	}}
	
		
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
	//int b=0;
	int b = 4<<9|1<<9|8|32;
	char c[2];
	P(b);
	while (scanf("%s", c)) {
		if (('/'-*c)*(*c-'9')>0 &&
		(1<<a[*c-'0'])&~(b|b>>9)) {
			b |= 1<<9+a[*c-'0'];
			P(b);
			S(&b);
			P(b);
			// valid input, try to play.

		}
	}

	return 0;
}
