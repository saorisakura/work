#include <iostream>
#include <cstdio>

using namespace std;

#define N 30

void turn(int a);

int cakes[N],s[N];
int length;

int main(void)
{
	int i,j,m,index,max;
	 while(scanf("%d",&cakes[0])!=EOF)
    {
        i=1;
        while(1)
        {
            if(getchar()!=' ')break;
            scanf("%d",&cakes[i++]);
        }
		
		length=i;
		m=length;

		printf("%d",cakes[0]);
		for(i=1;i<length;i++)
			printf(" %d",cakes[i]);
		cout<<endl;
								
		for(i=m-1;i>=0;--i) 
		{
			max=0;
			for(j=0;j<=i;++j)	
			{
				if(cakes[j]>max)
				{
					max=cakes[j];		//找出限定范围内的最大值并记录其所在的位置
					index=j;
				}
			}
			
			if(index==i)
				continue;		//如果最大值正好处在所需翻转到的位置，则跳过直接到下一循环
			if(index==0)		//如果最大值在0；翻转一次即可
			{
				turn(i+1);
				continue;
			}

			turn(index+1);			//从最大值处翻转，将其转至顶处
			turn(i);			//将该最大值转至所循环限定的范围的最底部
		}	
		printf("%d",0);
		cout<<endl;
	}
	return 0;
}
void turn(int a)	//翻转 no error
{
	int j;
	for(j=a;j>=0;j--)
		s[a-j]=cakes[j-1];
	for(j=0;j<a;j++)
		cakes[j]=s[j];
	printf("%d ",length-a+1);
}
