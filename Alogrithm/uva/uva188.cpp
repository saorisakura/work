#include <iostream>
#include <cstdio>
#include <cstring>
#include<algorithm>
using namespace std;

int n,C,W[100];
int min(int x,int y);
bool judge(void);
int main()
{     
    char s[100];    
    int i,len;    
    while(gets(s)!=NULL)
	{    
        n=0;    
		memset(W,0,sizeof(W));
		len=strlen(s);
        for(i=0; i<=len; ++i)				//处理读取的一句话
		{    
            if(s[i]==' ' || s[i]=='\0')
			{                
                ++n;    
                while(s[i+1]==' ')
					++i; 
            }    
            else   
                W[n] = (W[n]<<5)+(s[i]-'a'+1);    //用移位进行32进制转换
                
        }    
        sort(W,W+n); 
        C = W[0];  
		 while(!judge())	
			 ;
		cout<<s<<endl;
		cout<<C<<endl;
		cout<<endl;
	}

return 0;
}
int min(int x,int y)
{
    return x<y?x:y;    
}
bool judge(void)
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if((C/W[i])%n==(C/W[j])%n)
            {
                C=min((C/W[i]+1)*W[i],(C/W[j]+1)*W[j]);
                return false;
            }
    return true;
}