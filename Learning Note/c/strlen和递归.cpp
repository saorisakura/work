#include <stdio.h>
int main(){
	int func(int);
	void han(int,char,char,char);
	han(10,'A','B','C');
	
}

int strlwr(char a[]){
	for(int i=0;a[i]!='\0';i++){
		if(a[i]>='A'&&a[i]<='Z')
			a[i]=a[i]+32;
	}
}
//F(n)=F(n-1)+F(n-2),n>2;F(1)=1,F(2)=1;
int func(int n){
	if(n==1||n==2)
		return 1;
	else{
		return func(n-1)+func(n-2);
	}
}

void han(int n,char from,char temp,char to){
	if(n==1)
		printf("%c -> %c\n",from,to);
	else
	{
		han(n-1,from,to,temp);
		printf("%c -> %c\n",from,to);
		han(n-1,temp,from,to);
	}
}


