#include <iostream>
#include <cstdio>
#define N 101
using namespace std;

char city[N][5];
void init(char str[],int n);
int main()
{
	
	char str[20];
	while(true)
	{
		int count,Max,result,n=0;
		
		gets(str);
		if(str[0]=='#')
			break;
		init(str,n);
		while((gets(str)) && str[0]!='e')
		{
			++n;
			init(str,n);
		}

		Max=-1;
		for(int i=0;i<=n;++i)
		{
			count=0;
			for(int j=0;j<=n;++j)
				if(i!=j)
					for(int k=0;k!=5;++k)
						if(city[i][k]==city[j][k])
							count++;

			if(count>Max)
			{
				Max=count;
				result=i+1;
			}
		}
		cout<<result<<endl;
	}

	return 0;
}
void init(char str[],int n)
{
	for(int i=0;i!=5;++i)
	{
		if(str[4*i]=='r')
			city[n][0]=str[4*i+2];
		if(str[4*i]=='o')
			city[n][1]=str[4*i+2];
		if(str[4*i]=='y')
			city[n][2]=str[4*i+2];
		if(str[4*i]=='g')
			city[n][3]=str[4*i+2];
		if(str[4*i]=='b')
			city[n][4]=str[4*i+2];
	}
}