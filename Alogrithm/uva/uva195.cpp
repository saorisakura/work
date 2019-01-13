#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <cstring>
#define N 100
using namespace std;

char s[N]={'A','a','B','b','C','c','D','d','E','e','F','f','G','g','H','h','I','i','J','j','K','k','L','l','M','m','N','n','O','o','P','p','Q','q','R','r','S','s','T','t','U','u','V','v','W','w','X','x','Y','y','Z','z'};
map<char,int> table;
int Cmp(const void *a,const void *b);
void Swap(char *a,char *b);
void Reverse(char *a,char *b);
bool Perm_next(char str[]);
int main()						//利用map容器将比较函数按照要求转换，然后用非递归顺次输出按照所给次序大小的排列即可
{
	char str[N];
	int n;
	for(int i=0;i!=N;++i)
		table[s[i]]=(i+1);

	cin>>n;
	while(n--)
	{
		cin>>str;

		qsort(str,strlen(str),sizeof(str[0]),Cmp);
		cout<<str<<endl;

		while(Perm_next(str))
			cout<<str<<endl;
	}

	return 0;
}
int Cmp(const void *a,const void *b)
{
	return (table[*(char*)a]-table[*(char*)b]);
}
void Swap(char *a,char *b)
{
	char temp=*a;
	*a=*b;
	*b=temp;
}
void Reverse(char *a,char *b)
{
	while(a<b)
		Swap(a++,b--);
}
bool Perm_next(char str[])
{
	char *pEnd=str+strlen(str);
	if(str==pEnd)
		return false;
	char *p,*q,*pFind;
	--pEnd;
	p=pEnd;
	while(p!=str)
	{
		q=p;
		--p;
		if(table[*p]<table[*q])
		{
			pFind=pEnd;
			while(table[*pFind]<=table[*p])
				--pFind;
			Swap(pFind,p);
			Reverse(q,pEnd);
			return true;
		}
	}
	Reverse(p,pEnd);
	return false;
}