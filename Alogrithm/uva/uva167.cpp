#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define N 10
#define num 8
int ans;
int board[N][N],x[N];

bool judge(int k);
void putchess(int t);

int main()				//即八皇后问题的求和
{
	int n;
	
	cin>>n;
	while(n--)
	{
		ans=0;
		for(int i=1;i<=num;++i)
			for(int j=1;j<=num;++j)
				cin>>board[i][j];
		memset(x,0,sizeof(x));
		putchess(1);
		printf("%5d\n",ans);
	}

	return 0;
}
bool judge(int k)
{
	for(int i=1;i<k;++i)
		if((abs(x[k]-x[i])==(k-i)) || (x[k]==x[i]))
			return false;
	return true;
}

void putchess(int t)			//递归
{
	if(t>num)
	{
		int sum;
		sum=0;
		for(int i=1;i<=num;++i)
			sum+=board[i][x[i]];
		if(sum>ans)
			ans=sum;
	}
	else
	{
		for(int i=1;i<=num;++i)
		{
			x[t]=i;
			if(judge(t))
				putchess(t+1);
		}
	}
}