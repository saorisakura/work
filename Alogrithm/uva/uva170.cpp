#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

struct card
{
	char position;
	int count;
	string value[5];
};
card c[14];
bool initcards(void);

int main()
{
	char chosenumber,chosecolor,tempnumber,tempcolor,lastnumber,lastcolor;
	
	while(1)
	{
loop:
		
		int i;
		if(!initcards())
			break;
	
		chosenumber=c[13].value[0][0];
		chosecolor=c[13].value[0][1];
		for(i=0;i!=3;++i)
		{
			c[13].value[i][0]=c[13].value[i+1][0];
			c[13].value[i][1]=c[13].value[i+1][1];
		}

		while(1)
		{
			lastnumber=chosenumber;
			lastcolor=chosecolor;

				for(i=1;i!=14;++i)
				{
					if(chosenumber==c[i].position)
					{
						if(chosenumber!='K')
						{
							tempnumber=c[i].value[0][0];
							tempcolor=c[i].value[0][1];
							for(int j=0;j!=3;++j)
							{
								c[i].value[j][0]=c[i].value[j+1][0];
								c[i].value[j][1]=c[i].value[j+1][1];
							}
					
							c[i].value[3][0]=chosenumber;
							c[i].value[3][1]=chosecolor;

							chosenumber=tempnumber;
							chosecolor=tempcolor;
							c[i].count++;
						
							if(c[i].count==5)
							{
								int sum=0;
								for(int l=1;l<=13;++l)
									sum+=c[l].count;
								printf("%02d,%c%c\n", sum-1, lastnumber, lastcolor);
								goto loop;
							}
							break;
						}
						else
						{
							tempnumber=c[13].value[0][0];
							tempcolor=c[13].value[0][1];
							for(int j=0;j!=2;++j)
							{
								c[13].value[j][0]=c[13].value[j+1][0];
								c[13].value[j][1]=c[13].value[j+1][1];
							}	
							c[13].value[2][0]=chosenumber;
							c[13].value[2][1]=chosecolor;
				
							chosenumber=tempnumber;
							chosecolor=tempcolor;
							c[13].count++;
					
							if(c[13].count==5)
							{
								int sum=0;
								for(int l=1;l<=13;++l)
									sum+=c[l].count;
								printf("%02d,%c%c\n", sum-1, lastnumber, lastcolor);
								goto loop;
							}
							break;
						}
					}
				}
		}
	}
	return 0;
}
bool initcards(void)		// no error
{
	for(int i=0;i<4;i++)
		for(int j=13;j!=0;--j)
		{
			c[j].count=0;
			
			if( cin>>c[j].value[i] && c[j].value[i][0]=='#' )
				return false;
		}
		
		c[2].position='2';
		c[3].position='3';
		c[4].position='4';
		c[5].position='5';
		c[6].position='6';
		c[7].position='7';
		c[8].position='8';
		c[9].position='9';
		c[1].count=0;
		c[1].position='A';
		c[10].count=0;
		c[10].position='T';
		c[11].count=0;
		c[11].position='J';
		c[12].count=0;
		c[12].position='Q';
		c[13].count=1;
		c[13].position='K';

		return true;
}
