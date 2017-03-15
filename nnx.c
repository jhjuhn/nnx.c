#include <stdio.h>
#define R return
int w[]={0,0,0,0,0,0,0,0,3,8,1,2,4,6,7,0,5}; int *a=w+8; int
W(int n){int r,s,t;R(t=0x1000/(r=1<<(++n)/3+(n==010))/(s=010<<n%3))|r|s;}

void P(int b){ int *c,*e; for(e=(c=a)+2; c-a<9; e+=(*c++==*e)*3){
printf("%c%c", b&1<<*c?88:88-(b&1<<*c+9?9:6*7), *c-*e?0:10);}}

int M(int b, int t){ int r,m,j,*k; for(k=w; k<w+17; ++k){ if (k-w<010 &&
(*k=*k?*k:W(k-w)) && (r=3*((b&*k)==*k)|2*((511&(b|b>>9))==511)|((b>>9&*k)==*k))) {
R(r<<18);} (k-w<010)?:(r=(k-w-8)?r:2-2*t<<022)^(r=((j=1<<*k)^j&(b|b>>9) &&
t*(m=M(b|j<<(1+t?0:9),-t))-r*t>0)?3<<18&m|j:r);} R(r);}

int main(int l, char **v){
	int t = (l>1)?-1:1; //1-> user plays X
	int b = 4*(1-t);//(t==1?0:1);
	char c[2];
	P(b);
	while (scanf("%s", c)) {
		if (('/'-*c)*(*c-'9')>0 &&
		(1<<a[*c-'0'])&~(b|b>>9)) {
			b |= 1<<a[*c-'0']+(t+1?0:9);

			P(b);
			int m = M(b, -t);
			b|=((1<<18)-1)&M(b, -t)<<(t+1?9:0);
			P(b);
		}
	}

	return 0;
}
