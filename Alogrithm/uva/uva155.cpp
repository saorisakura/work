#include <iostream>
#include <cstdio>
using namespace std;

int count,x,y;
void judge(int a,int b,int l);
int main()
{
	int a,b,n,l;

	a=1024;
	b=1024;
	count=0;

	while(true)
	{
		cin>>l>>x>>y;

		if(l==0 && x==0 && y==0)
			break;
		
		while(l>=1)
		{
			
			judge(a,b,l);

			if(x<=a && y<=b)
				n=1;
			if(x>=a && y<=b)
				n=2;
			if(x<=a && y>=b)
				n=3;
			if(x>=a && y>=b)
				n=4;

			switch(n)
			{
				case 1:
					a-=l;-
					b-=l;
					l/=2;
					break;
				case 2:
					a+=l;
					b-=l;
					l/=2;
					break;
				case 3:
					a-=l;
					b+=l;
					l/=2;
					break;
				case 4:
					a+=l;
					b+=l;
					l/=2;
					break;
			}
		}
	
		printf("%3d\n",count);
		
		a=1024;
		b=1024;
		count=0;
	}
	return 0;
}
void judge(int a,int b,int l)
{
	if((a-l)<=x && x<=(a+l) && (b-l)<=y && y<=(b+l))
		count++;
}