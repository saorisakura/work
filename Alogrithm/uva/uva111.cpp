#include <iostream>
#include <cstring>

using namespace std;

#define N 20
int aim[N],answer[N],f[N][N];
int max(int a,int b);

int main(void)
{
	int n,i,j,temp;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>temp;
		aim[temp-1]=i;
	}
	while(cin>>temp)
	{
		answer[temp-1]=1;
		for(i=2;i<=n;i++)
		{
			cin>>temp;
			answer[temp-1]=i;
		}

		memset(f,0,sizeof(f));

		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				if(aim[i]==answer[j])
					f[i+1][j+1]=f[i][j]+1;
				else
					f[i+1][j+1]=max(f[i+1][j],f[i][j+1]);
				
			}
		cout<<f[n][n]<<endl;
	}
	return 0;
}
int max(int a,int b)
{
	return (a>b)?a:b;
}