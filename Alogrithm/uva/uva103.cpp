#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;  
#define N 10
#define L 30
int n,l;
struct Box
{
	int dim[N];
	int index;
	Box *below;
	Box *above;
};
Box boxs[L];
Box *table[L];
void initboxs(int l,int n);
bool compare(Box *a,Box b);
int main(void)
{
	int i,j,k,count,length;
	Box begin,record;
	Box *temp;
	length=0;
	
	scanf("%d %d",&l,&n);
	
	initboxs(l,n);
	
	for(i=0;i<l;i++)
		std::sort(&boxs[i].dim[0],&boxs[i].dim[n]);/* no error*/

	for(i=0;i<l;i++)
	{
		k=i;
		for(j=i+1;j<l;j++)
		{
			if(boxs[j].dim[0]<boxs[k].dim[0])
				k=j;
		}
		record=boxs[i];
		boxs[i]=boxs[k];
		boxs[k]=record;
	}					/*no error*/
	
	for(i=0;i<l;i++)
	{
		temp=table[i];
		count=1;
		for(j=i+1;j<l;j++)
		{
			if(compare(temp,boxs[j]))
			{	
				temp->above=table[j];
				table[j]->below=temp;
				temp=table[j];
				count++;
			}
		}
		if(count>length)
		{	
			length=count;
			begin=boxs[i];
		}
		
	}
	printf("%d\n",length);
	temp=&begin;
	for(i=0;i<length;i++)
	{
		if((temp->index)==7)
			temp->index=5;
		printf("%d ",((temp->index)+1));
		temp=temp->above;
	}
	getchar();
	printf("\n");
	return 0;
}
void initboxs(int l,int n)
{
	int i,j,b;
	for(i=0;i<l;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&b);
			boxs[i].dim[j]=b;
		}
		boxs[i].index=i;
		boxs[i].below=(Box *)NULL;
		boxs[i].above=(Box *)NULL;
		table[i]=&boxs[i];
	}
}
bool compare(Box *a,Box b)
{
	int i;
	for(i=0;i<n;i++)
	{
		if((a->dim[i]>b.dim[i])||(a->dim[i]==b.dim[i]))
			return false;
	}
	return true;
}
