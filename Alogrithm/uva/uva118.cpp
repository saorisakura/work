#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

struct state
{
	int x;
	int y;
	char face;
};
int X,Y;
int land[60][60];
void move(state &robot,char a);
bool judge(state robot);
int main()										//按照要求模拟机器人运动
{
	
	state robot,robot_b;
	memset(land,0,sizeof(int)*60*60);
	
	cin>>X>>Y;
	
	while(scanf("%d %d %c",&robot.x,&robot.y,&robot.face)==3)
	{

		char order[101];
		int len,flag=0;
		
		cin>>order;
		len=strlen(order);

		for(int i=0;i!=len;++i)
		{
			if(land[robot.x][robot.y]==0)
			{
				robot_b=robot;
				move(robot,order[i]);
				if(judge(robot))
				{
					land[robot_b.x][robot_b.y]=1;
					cout<<robot_b.x<<" "<<robot_b.y<<" "<<robot_b.face<<" LOST"<<endl;
					flag=1;
					break;
				}
			}
		
			else
			{	
				robot_b=robot;
				move(robot,order[i]);
				if(judge(robot))
					robot=robot_b;
			}
		}
		if(flag==0)
			cout<<robot.x<<" "<<robot.y<<" "<<robot.face<<endl;
	}

	return 0;
}
void move(state &robot,char a)
{
	char direction[4]={'E','N','W','S'};

	switch(a)
	{
	case 'L':
		for(int i=0;i!=4;++i)
			if(robot.face==direction[i])
			{
				if(i==3)
					robot.face='E';
				else 
					robot.face=direction[i+1];
				break;
			}
		break;
	case 'R':
		for(int i=3;i!=-1;--i)
			if(robot.face==direction[i])
			{
				if(i==0)
					robot.face='S';
				else 
					robot.face=direction[i-1];
				break;
			}
		break;
	case 'F':
		switch(robot.face)
		{
		case 'N':
			robot.y++;
			break;
		case 'S':
			robot.y--;
			break;
		case 'W':
			robot.x--;
			break;
		case 'E':
			robot.x++;
			break;
		};
		break;
	};
	return robot;
}
bool judge(state robot)
{
	if(robot.x<0 || robot.x>X || robot.y<0 || robot.y>Y)
		return true;
	return false;
}