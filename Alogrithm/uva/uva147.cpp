#include <cstdio>
#include <cstring>

#define N 30001
long long f[N];

int main()
{
    int moneykind[12]={0,5,10,20,50,100,200,500,1000,2000,5000,10000};
	int m,a,b,n=11;
	double money;

    while(scanf("%d.%d",&a,&b)==2)
    {
		m=a*100+b;
        if(!m)
			break;
		memset(f,0,sizeof(f));
		f[0]=1;
       for(int i=1;i<=n;i++)			//dp
          for(int j=1;j<=m;j++)
          {
			if(j>=moneykind[i]) 
				f[j]+=f[j-moneykind[i]];
          }

	   money=m/100.0; 

       printf("%6.2lf",money);
       printf("%17lld\n",f[m]);
	}

    return 0;
}
