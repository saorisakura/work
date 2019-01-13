#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctype.h>
#define N 100
using namespace std;

int num,map[N][N],nodes[N],len;
void Swap(char *a, char *b);  
void Reverse(char *a, char *b);  
bool Perm_next(char a[]);   
int QsortCmp(const void *pa, const void *pb);  
int calculate(char band[]);
int main()											//按照定义计算带宽
{
	char str[N],band[N],result[N];
	int width,flag[N]={0},temp;
		
	while(cin>>str)
	{
		if(str[0]=='#')
			break;
		
		len=strlen(str);

		for(int i=0;i!=len;++i)
		{	
			if(str[i]==':' || str[i]==';')
				continue;
			else if(str[i+1]==':')
			{
				nodes[str[i]-'A']=1;
				temp=(str[i]-'A');
				flag[str[i]-'A']++;
				continue;
			}
			else
			{
				flag[str[i]-'A']++;
				map[temp][str[i]-'A']=1;
			}
			
			
		}

		num=0;

		for(int i=0;i!=26;++i)
			if(flag[i])
			{
				band[num]=(char)(i+'A');
				num++;
			}
		band[num]='\0';

		//cout<<"the band has been read is "<<band<<endl;

		//cout<<"the result before calculate is "<<result<<endl;

		qsort(band, num, sizeof(band[0]), QsortCmp);

		int t;
		width=10;
		do
		{
			t=calculate(band);
			if(t<width)
			{
				width=t;
				strcpy(result,band);
				if(width==1)
					break;
			}
		}while(Perm_next(band));
		cout<<result[0];
		for(int i=1;i!=num;++i)
			cout<<" "<<result[i];
		cout<<" -> "<<width<<endl;
		memset(map,0,(N*N)*sizeof(int));
		memset(nodes,0,N*sizeof(int));
		memset(flag,0,N*sizeof(int));
	}

	return 0;
}
void Swap(char *a, char *b)  
{  
	    char t= *a;  
	    *a=*b;  
	    *b=t;  
}  
void Reverse(char *a, char *b)  
{  
	while(a < b)  
	     Swap(a++,b--);  
}  
bool Perm_next(char a[])  
{  
    char *pEnd =a+strlen(a);  
	if (a==pEnd)  
		return false;  
	char *p,*q,*pFind;  
	pEnd--;  
	p=pEnd;  
	while(p != a)  
	{  
	    q=p;  
	    --p;  
	    if (*p< *q) 
        {       
            pFind = pEnd;  
	        while(*pFind <= *p)  
                --pFind;  
	        Swap(pFind, p);  
            Reverse(q, pEnd);  
            return true;  
        }  
	}  
	Reverse(p, pEnd);
    return false;  
}  
int QsortCmp(const void *pa, const void *pb)  
{  
    return *(char*)pa - *(char*)pb;  
}  
int calculate(char band[])
{
	int Max=0;
	for(int i=0;i!=num;++i)
		if(nodes[band[i]-'A'])
			for(int j=0;j!=num;++j)
				if(map[band[i]-'A'][band[j]-'A'])
				{
					if(abs(i-j)>Max)
						Max=abs(i-j);
					if(Max==(len-1))
						return Max;
				}
	return Max;
}