#include <cstdio>
#include <cstring>

#define N 100

bool prime(int a);

int main()
{
	int i,n,count,temp;
	int primes[N];
	count=0;
	
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		count=0;
		memset(primes,0,sizeof(primes));
		for(i=2;i<=n;i++)
			if(prime(i))
			{
				temp=n;
				while(temp/i)
				{
					primes[i]+=temp/i;
					temp=temp/i;
				}
				
			}
		printf("%3d! =",n);
		for(i=2;i<=n;i++)
			if(prime(i))
			{
				if(count==15)
				{
					printf( "\n      " );
					
				}
				printf("%3d",primes[i]);
				count++;
			}
		printf("\n");
	}
	
	return 0;

}
bool prime(int a)
{
	int i;
	bool flag=true;
	
	for(i=2;i<a;++i)
		if(a%i==0)
		{
			flag=false;
			break;
		}
	return flag;
}