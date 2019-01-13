#include <iostream>  
#include <algorithm>       
#include <cstring>  
#include <ctype.h>  
using namespace std;  
  
struct WORD  
{  
    char words [100];  
    char bwords[100];  
    int  len;  
    bool flag;  
};  
  
void change(WORD sentence[], int n);
bool cmp(WORD str1, WORD str2);
  
int main()  
{  
    int i,j,n;   
    WORD sentence[1000]; 

	i=0;
  
    while(cin>>sentence[i].words)  
    {  
        if(sentence[i].words[0]=='#')  
            break;  
        sentence[i].len=strlen(sentence[i].words);  
        sentence[i].flag=true;  
        i++;  
    }  
    change(sentence, i);  
  
    for(j=0; j<i; j++)  
        sort(sentence[j].bwords, sentence[j].bwords+sentence[j].len);  //将副本的每个字符排序，便于之后的比较
  
    for(j=0; j<=i; j++)  
    {  
        for(n=0; n<=i; n++)  
        {  
            if(n!=j && sentence[j].flag)
			{
				if(!strcmp(sentence[j].bwords,sentence[n].bwords))  
				{  
					sentence[j].flag=sentence[n].flag=false;  
			    }  
			}
        }  
          
    }  
  
    sort(sentence, sentence+i, cmp);			//排序输出
    for(j=0; j<i; j++)  
    {  
        if(sentence[j].flag)  
            cout<<sentence[j].words<<endl;  
    }  
      
    return 0;  
} 
bool cmp(WORD str1, WORD str2)  
{  
    return strcmp(str1.words,str2.words)<0;  //升序排列
}  

void change(WORD sentence[], int n)  
{  
    int i, j;  
    for(i=0; i<n; i++)  
    {  
        for(j=0; j<sentence[i].len; j++)  
        {  
            sentence[i].bwords[j]=tolower(sentence[i].words[j]);  //将word的副本转为小写，便于处理
        }  
        sentence[i].bwords[j]='\0';			//注意字符串以空字符结尾
    }  
}  