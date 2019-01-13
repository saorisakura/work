#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define N 5000

struct Tree
{
	int x;
	int y;
	int z;
};
Tree t[N]; 

int main()
{
	int result[11];
	int a, b, c;
	int count;
	
	memset(t, 0, sizeof(t));
	memset(result, 0, sizeof(result));
	
	count = 0;	
	
	while(cin>>a>>b>>c && a + b + c != 0)
	{
		t[count].x = a; 
		t[count].y = b; 
	 	t[count].z = c; 
	 	count++; 
	}
 	
	for(int i=0;i<count;++i) 
	{
		int min = 500;
		for(int j=0;j<count;j++) 
		{
			if(i!=j)
			{ 
				int d;
				d=(int)sqrt((t[i].x-t[j].x)*(t[i].x-t[j].x)+(t[i].y-t[j].y)*(t[i].y-t[j].y)+(t[i].z-t[j].z)*(t[i].z-t[j].z));
				
				if(d< min)
				{
					min=d;
				}
			} 
		}
		if(min< 10)
			result[min]++;
	}
	
	for(int i = 0; i < 10; i++)
	{
		printf("%4d", result[i]);
	}
	cout<<endl;
	return 0;
}


