#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cctype>
using namespace std;

int rank;
char cards[10][3];
char ranks[9][20]={"straight-flush","four-of-a-kind","full-house","flush","straight","three-of-a-kind","two-pairs","one-pair","highest-card"};
struct Card
{
    int num;
    char color;
};
Card ans[10];
int cmp(const void *a,const void *b)
{
    Card *i=(Card *)a;
    Card *j=(Card *)b;
    return (i->num)-(j->num);
}
int judge_rank();				//no error
void Copy(int m,int n);
void dfs(int m,int n);			//递归枚举
int main()						//模拟+枚举
{
    while(true)
	{
        int i=1; 
		rank=10;
		if(scanf("%s",cards[0])==EOF)
			break;
		for(i=1;i!=10;i++)
			cin>>cards[i];
		cout<<"Hand: ";
		for(i=0;i<5;i++)
			cout<<cards[i]<<" ";
		cout<<"Deck: ";
		for(i=5;i<10;i++)
			cout<<cards[i]<<" ";
		cout<<"Best hand: ";
        dfs(0,5);
		cout<<ranks[rank]<<endl;
    }

    return 0;
}
int judge_rank()								//no error
{
	Card b[10];
	int mark[20]={},count[20]={},count_b[5]={},flag1=1,flag2=1,i,j;
    for(i=0;i<5;i++)
        b[i]=ans[i];
    qsort(b,5,sizeof(b[0]),cmp);
	
	for(i=0;i!=5;++i)
		for(j=0;j!=5;++j)
			if(b[i].num==b[j].num && !mark[i])
			{
				mark[i]=1;
				count[b[i].num]++;
			}
	for(i=0;i!=14;++i)
		if(count[i])
		{
			count_b[count[i]]++;
		}
	for(i=1;i!=5;++i)
	{
		if(b[i].color!=b[0].color)
			flag1=0;
		if(b[i].num!=(b[0].num+i))
			flag2=0;
	}
	if(b[0].num==1 && b[1].num==10 && b[2].num==11 && b[3].num==12 && b[4].num==13)
		flag2=1;
	if(b[0].num==1 && b[1].num==2 && b[2].num==11 && b[3].num==12 && b[4].num==13)
		flag2=0;

	if(flag1 && flag2)
		return 0;
	if(count_b[1]==1 && count_b[4]==1)
		return 1;
	if(count_b[2]==1 && count_b[3]==1)
		return 2;
	if(flag1 && !flag2)
		return 3;
	if(!flag1 && flag2)
		return 4;
	if(!flag1 && count_b[1]==2 && count_b[3]==1)
		return 5;
	if(!flag1 && count_b[1]==1 && count_b[2]==2)
		return 6;
	if(!flag1 && count_b[1]==3 && count_b[2]==1)
		return 7;
	return 8;
}
void Copy(int m,int n)				//将cards[n] copy 到ans[m]中
{
	int k=n?n:m;
    char temp=cards[k][0];

	if(isalpha(temp))
	{
		switch(temp)
		{
		case'A':
	        ans[m].num=1;
			break;
		case'T':
	        ans[m].num=10;
			break;
		case'J':
	        ans[m].num=11;
			break;
		case'Q':
			ans[m].num=12;
			break;
		case'K':
			ans[m].num=13;
		
		}
	}
    else
        ans[m].num=temp-'0';
    ans[m].color=cards[k][1];
}
void dfs(int m,int n)			//递归枚举
{                 
    int t;
    if(m==5)
	{
        t=judge_rank();
        if(rank>t)
            rank=t;
        return ;
    }
    Copy(m,0);                   
    dfs(m+1,n);
    Copy(m,n);                   
    dfs(m+1,n+1);
}