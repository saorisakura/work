#include <iostream>
#define N 60
using namespace std;

struct Ball 
{
	int x,y;
	int direction;
	int score;
	int lifetime;
};
struct Point 
{
	bool flag;
	int cost;
	int value;
};
Point point[N][N];
void gameinit(void);
int main()					//模拟弹珠台小游戏
{
	Ball ball; 
	int total=0;

	gameinit();
	while(cin>>ball.x>>ball.y>>ball.direction>>ball.lifetime)
	{
		ball.score=0;
		ball.x--,ball.y--;

		while(ball.lifetime>1)
		{
			int temp_x,temp_y;
			temp_x=ball.x;
			temp_y=ball.y;
			/*cout<<"ball's direction before hit is "<<ball.direction<<endl;
			cout<<" the position is "<<ball.x<<" "<<ball.y<<endl;
			cout<<" ball's lifetime is "<<ball.lifetime<<endl;
			cout<<"ball's score is "<<ball.score<<endl;*/
			switch(ball.direction)
			{
			case 0:
				++ball.x;
				break;
			case 1:
				++ball.y;
				break;
			case 2:
				--ball.x;
				break;
			case 3:
				--ball.y;
			};
			if(point[ball.x][ball.y].flag)
			{
				ball.lifetime-=point[ball.x][ball.y].cost;
				ball.score+=point[ball.x][ball.y].value;
				--ball.direction;
				if(ball.direction==-1)
					ball.direction=3;
				ball.x=temp_x;
				ball.y=temp_y;
			}
			
			--ball.lifetime;
			//cout<<"----------------------------"<<endl;
		}
		cout<<ball.score<<endl;
		total+=ball.score;
	}
	cout<<total<<endl;

	return 0;
}
void gameinit(void)
{
	int m,n,p,cost;

	cin>>m>>n>>cost;
	for(int i=0;i!=n;++i)
	{
		point[0][i].value=point[m-1][i].value=0;
		point[0][i].cost=point[m-1][i].cost=cost;
		point[0][i].flag=point[m-1][i].flag=true;
	}
	for(int i=1;i!=m-1;++i)
	{
		point[i][0].value=point[i][n-1].value=0;
		point[i][0].cost=point[i][n-1].cost=cost;
		point[i][0].flag=point[i][n-1].flag=true;
	}
	for(int i=1;i!=m-1;++i)
		for(int j=1;j!=n-1;++j)
			point[i][j].flag=false;

	cin>>p;
	int x,y;
	for(int i=0;i!=p;++i)
	{
		cin>>x>>y;
		--x,--y;
		cin>>point[x][y].value>>point[x][y].cost;
		point[x][y].flag=true;
	}

}