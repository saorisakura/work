#include <stdio.h>
#define MAX 100
struct block
{
	block *above;
	block *below;
	int index;
};
int num;
block blocks[MAX];
block *table[MAX];

void initblocks(void);
block *topblock(int n);
int iswrong(int a ,int b);
void clearabove(int n);
void moveover(int a,int b);
void moveonto(int a,int b);
void pileover(int a,int b);
void pileonto(int a,int b);
int main()
{
	char w1[10],w2[10];
	int a,b,i;
	int flag=1;
	block* bottom;
	scanf("%d\n",&num);
	initblocks();
	while(flag)
	{
		scanf("%s",w1);
		if(w1[0]=='q')
		{
			flag=0;
			continue;
		}
    scanf(" %d %s %d\n",&a,w2,&b);

		if((iswrong(a,b))||(iswrong(b,a)))
			continue;
		switch(w1[0])
		{
			case'm':
				switch(w2[1])
				{
					case'v':
						moveover(a,b);
						break;
					case'n':
						moveonto(a,b);
						break;
					default:
						printf("illegal input \n");
				}
				break;
			case'p':
				switch(w2[1])
				{
					case'v':
						pileover(a,b);
						break;
					case'n':
						pileonto(a,b);
						break;
					default:
						printf("illegal input \n");
				}
				break;
		}
	}
	for(i=0;i<num;i++)
	{
		printf("%d:",i);
		if (table[i]->below!=(block *) NULL)
		{
			printf("\n");
		}

		else
		{
			bottom = table[i];
			while (bottom)
			{
				printf(" %d",bottom->index);
				bottom = bottom->above;
			}
			printf("\n");

		}
	}
	return 0;
	
}
void initblocks(void)
{
	int i;
	for(i=0;i<num;i++)
	{
		blocks[i].above=(block *)NULL;
        blocks[i].below=(block *)NULL;
		blocks[i].index=i;
		table[i]=&blocks[i];
	}
}


block *topblocks(int n)
{
	block *temp = table[n];

    while (temp->above != (block *) NULL)
	{
		temp = temp->above;
    }
    return temp;
}

int iswrong(int a,int b)
{
	int flag;
	flag=0;
	block *temp;
	temp=table[b];
	if(a==b)
		flag=1;
	else
	{
		while(temp)
		{
			if(temp==(table[a]))
				flag=1;
			temp=temp->above;
		}
	}
	return flag;
}

void clearabove(int n)
{
	block *top;
	block *next;
	top=topblocks(n);
	while(top!=table[n])
	{
		next=top->below;
		top->above=(block *)NULL;
		top->below=(block *)NULL;
		top=next;
	}
	table[n]->above=(block *)NULL;
}
void moveover(int a,int b)
{
	block *top;
	top=topblocks(b);
	clearabove(a);
	top->above=table[a];
	if (table[a]->below)              /* be safe when relinking */
    table[a]->below->above = (block *) NULL;

	table[a]->below=top;
}
void moveonto(int a,int b)
{
	clearabove(a);
	clearabove(b);
	table[b]->above=table[a];
	if (table[a]->below)           
    table[a]->below->above = (block *) NULL;

	table[a]->below=table[b];
}
void pileover(int a,int b)
{
	block *top;
	top=topblocks(b);
	top->above=table[a];
	if (table[a]->below)              
    table[a]->below->above = (block *) NULL;

	table[a]->below=top;
}
void pileonto(int a,int b)
{
	clearabove(b);
	table[b]->above=table[a];
	if (table[a]->below)             
    table[a]->below->above = (block *) NULL;

	table[a]->below=table[b];
}
