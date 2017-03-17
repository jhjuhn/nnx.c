#include <stdio.h>
#define R return
int w[]={0, 0, 0, 0, 0, 0, 0, 0, 3, 8, 1, 2, 4, 6, 7, 0, 5}; int *a=w+8; int
W(int n){int r,s,t;return (t=0x1000/(r=1<<(++n)/3+(n==010))/(s=010<<n%3))|r|s;}

void P(int b){int *c, *e; for(e=(c=a)+2; c-a<9; e+=(*c++==*e)*3){
printf("%c%c", b&1<<*c?88:88-(b&1<<*c+9?9:6*7), *c-*e?0:10);}}

int M(int b, int t){int m,j,*k,r; for(r=0,k=w; k-w<022; ++k){ r=(k-w<8)?((b&(*k
=(*k?*k:W(k-w))))==*k)*7|3*((b>>9&*k)==*k):(511==((b|b>>9)&511))?5:(k-w-8)?r:
(1-t)<<20;if((k-w<8)&&r||!(k-w-8)&&r==5){ R(r<<18);} r=((k-w>7)&& ((j=1<<*k)
^j&(b|b>>9)&& t*(m=M(b|j<<(1+t?0:9),-t))-r*t>0))?(6<<18)&m|j:r;} R(r);}

int main(int n, char **v){
	int x = 2*(!(*v[n-1]-'x'))-1;
	int b = 4-4*x;
	char c[2];
	P(b);
	int m=0;
	while (scanf("%s", c)) {

		if (('/'-*c)*(*c-'9')>0 &&
		(1<<a[*c-'0'])&~(b|b>>9)) {

			b |= ((1<<18)-1)&M(
			(b |= 1<<a[*c-'0']+(x+1?0:9))
			, -x)<<(x+1?9:0);

			P(b);
			if (M(b, x)&(1<<18)) { b = 0; P(b); }
		}
	}

	return 0;
}
