#include <cstdio>
#include <cmath>

int main(void)
{
	double a,b,c,d,e,x1,y1,x2,y2,x3,y3;
	double h,k,r,A,B,C;
	char f1,f2,f3,f4,f5;

	while(scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3)!= EOF)
	{
		a=x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2);
		b=(pow(x1,2)+pow(y1,2)-pow(x2,2)-pow(y2,2))/2;
		c=(pow(x1,2)+pow(y1,2)-pow(x3,2)-pow(y3,2))/2;
		d=b*(y1-y3)-c*(y1-y2);
		e=c*(x1-x2)-b*(x1-x3);

		h=-d/a;
		k=-e/a;
		r=sqrt((d/a-x1)*(d/a-x1)+(e/a-y1)*(e/a-y1));
		
		A=2*h;
		B=2*k;
		C=h*h+k*k-r*r;
		if(h>0)
			f1='+';
		else
		{
			f1='-';
			h=-h;
		}

		if(k>0)
			f2='+';
		else
		{
			f2='-';
			k=-k;
		}
		if(A>0)
			f3='+';
		else
		{
			f3='-';
			A=-A;
		}
		if(B>0)
			f4='+';
		else
		{
			f4='-';
			B=-B;
		}
		if(C>0)
			f5='+';
		else
		{
			f5='-';
			C=-C;
		}
		
		
		printf("(x %c %.3lf)^2 + (y %c %.3lf)^2 = %.3lf^2\n",f1,h,f2,k,r);
		printf("x^2 + y^2 %c %.3lfx %c %.3lfy %c %.3lf = 0\n",f3,A,f4,B,f5,C);

	}
	
	return 0;

}