#include <stdio.h>
#include <math.h>
int main()
{
	double n,p,k,temp,answer;

	scanf("%lf",&n);
	scanf("%lf",&p);
	for(k=0;;k++)
	{
		temp=pow(k,n);
		if(fabs(temp-p)<1e-12y)
		{
			answer=k;
			break;
		}		
			
	}
	printf("%lf",answer);
	return 0;
}