#include <iostream> 
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstdlib>
#define N 60
using namespace std;

int cmp(const void *a,const void *b)
{ 
     return *(char *)a>*(char *)b?1:0; 
 } 
 
 int main(void)
 { 
     int n,i,j; 
  
	 char s[N],t[N];
     while(cin>>s>>t)
	 {
		  n=strlen(s);
		  printf("%d",n);
		  qsort(s,n,sizeof(s[0]),cmp);
		  sort(t,t+n);
         break;            
     } 
          printf("%s*%s",s,t);
		  system("pause");
       
     return 0; 
 }