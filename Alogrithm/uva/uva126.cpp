#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
#define N 100
using namespace std;

struct Item
{
	int coe;
	int x_power;
	int y_power;
};
Item t[N];
int num,count;
bool cmp(const Item &t1,const Item &t2);				//使用顺序容器时，注意结束时清除容器，以免影响下一次对容器的使用！！！
int init(char str[]);
int main()
{
	char str[N];
	char ans1[N],ans2[N];
	Item t1[N],t2[N];
	vector<Item> result;

	while(gets(str) && str[0] != '#' ) 
	{
		int n1,n2,len;
	
		n1=init(str);
		for(int i=0;i!=n1;++i)
			t1[i]=t[i];
		
		gets(str);
		n2=init(str);
		for(int i=0;i!=n2;++i)
			t2[i]=t[i];

		Item temp;
		for(int i=0;i!=n1;++i)
			for(int j=0;j!=n2;++j)
			{
				temp.coe=t1[i].coe*t2[j].coe;
				temp.x_power=t1[i].x_power+t2[j].x_power;
				temp.y_power=t1[i].y_power+t2[j].y_power;
				result.push_back(temp);
			}

		sort(result.begin(),result.end(),cmp);
		
		memset(&ans1[0], &ans1[N], ' ');
		memset(&ans2[0], &ans2[N], ' ');
		 vector<Item>::iterator i,j;
		 num=0;
		 for (i = result.begin(); i != result.end(); ++i) 
		 {
            
				for (j = i + 1; j <result.end() && i->x_power == j->x_power && i->y_power == j->y_power;) 
				{
					i->coe += j->coe;
					j =result.erase(j);
				}
                if (i->coe != 0) 
				{
					if (num > 0) 
					{ 
						++num; 
						ans2[num++] = i->coe > 0 ? '+' : '-';
						ans2[num++] = ' ';
					}
					else 
					{					
						ans2[0] = '-';
						num+= (i->coe < 0);
					}
             
					i->coe = abs(i->coe);
					if (i->coe != 1 || (i->x_power == 0 && i->y_power == 0)) 
					{
						num += sprintf(&ans2[num], "%d", i->coe);
                  
						ans2[num] = ' ';
					}
               
					if (i->x_power > 0) 
					{
						 ans2[num++] = 'x';
						 if (i->x_power > 1) 
						{
							num += sprintf(&ans1[num], "%d", i->x_power);
							ans1[num] = ' ';
						}
					} 
					if (i->y_power > 0) 
					{
						ans2[num++] = 'y';
						if (i->y_power > 1) 
						{
							num += sprintf(&ans1[num], "%d", i->y_power);
							ans1[num] = ' ';
						}
					}
				}
            }
        
        
        if (num == 0) 
		{
            ans2[num++] = '0';
        }
       
        ans1[num] = ans2[num] = '\0';
        cout << ans1 << '\n' <<ans2 << endl;
	
		result.clear();

	}
	return 0;
}
bool cmp(const Item &t1,const Item &t2)
{
	return (t1.x_power>t2.x_power || (t1.x_power == t2.x_power && t1.y_power<t2.y_power));
}
int init(char str[])
{
	int sign,n=-1,i=0;
	for(int i=0;i!=N;++i)
		t[i].coe=t[i].x_power=t[i].y_power=0;
	
	while(true)
	{
		int coe=0;
		if(str[i]=='-')
			sign=-1;
		else
			sign=1;
		++n;
	
		if((str[0]=='x' || str[0]=='y') && n==0)
		{
			t[0].coe=1;
		}
		else 
		{
			while(str[i+1]>='1' && str[i+1]<='9')
			{
				++i;
				t[n].coe=t[n].coe*10+(str[i]-'1'+1);
			}
			if(t[n].coe!=0)
				t[n].coe*=sign;
			else
				t[n].coe=sign;

			++i;
		}
		if(n==0 && str[0]!='-' &&str[0]!='+' && str[0]!='x' && str[0]!='y')
		{
			int m=0;
			while(str[m]>='1' && str[m]<='9')
			{
				coe=coe*10+(str[m]-'1'+1);
				++m;
			}
			t[0].coe=coe;
		}
		if(str[i]=='\0')
			break;
		if(str[i]=='x')
		{
			while(str[i+1]>='1' && str[i+1]<='9')
			{
				++i;
				t[n].x_power=t[n].x_power*10+(str[i]-'1'+1);
			}
			if(t[n].x_power==0)
				t[n].x_power=1;
			++i;
			if(str[i]=='\0')
				break;
			if(str[i]=='y')
			{
				while(str[i+1]>='1' && str[i+1]<='9')
				{
					++i;
					t[n].y_power=t[n].y_power*10+(str[i]-'1'+1);
				}
				if(t[n].y_power==0)
					t[n].y_power=1;
				++i;
				if(str[i]=='\0')
					break;
			}
		}
		else if(str[i]=='y')
		{
			while(str[i+1]>='1' && str[i+1]<='9')
			{
				++i;
				t[n].y_power=t[n].y_power*10+(str[i]-'1'+1);
			}
			if(t[n].y_power==0)
				t[n].y_power=1;
			++i;
			if(str[i]=='\0')
				break;
			if(str[i]=='x')
			{
				while(str[i+1]>='1' && str[i+1]<='9')
				{
					++i;
					t[n].x_power=t[n].x_power*10+(str[i]-'1'+1);
				}
				if(t[n].x_power==0)
					t[n].x_power=1;
				++i;
				if(str[i]=='\0')
					break;
			}
		}
		else
		{
			t[n].x_power=0;
			t[n].y_power=0;
		}
		
	}

	return (n+1);
}