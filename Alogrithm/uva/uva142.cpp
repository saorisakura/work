#include <iostream>
#include <vector>
#include <iomanip>
#define Max 500001
using namespace std;

struct Point
{
	int x;
	int y;
};
struct Rect
{
	Point lb;
	Point rt;
};
bool Inside(Point &p,Rect &l)
{
	return (p.x>=l.lb.x && p.x<=l.rt.x && p.y>=l.lb.y && p.y<=l.rt.y);
}
int Distance(Point &a,Point &b)
{
	return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()													//模拟鼠标点击的识别
{
	vector<Point> icons,clicks;
	vector<Rect> regions;
	char Tag;

	while(cin>>Tag && Tag!='#')
	{
		Rect temp;
		switch(Tag)
		{
		case 'I':
			cin>>temp.lb.x>>temp.lb.y;
			icons.push_back(temp.lb);
			break;
		case 'R':
			cin>>temp.lb.x>>temp.lb.y>>temp.rt.x>>temp.rt.y;
			regions.push_back(temp);
			break;
		case 'M':
			cin>>temp.lb.x>>temp.lb.y;
			clicks.push_back(temp.lb);
			break;
		};
	}


		for(int i=0;i!=icons.size();++i)
			for(int j=0;j!=regions.size();++j)
				if(Inside(icons[i],regions[j]))
				{
					icons[i].x=Max;
					icons[i].y=Max;
				}

		for(int i=0;i!=clicks.size();++i)
		{
			int index_r;
			bool flag=false;

			for(int j=0;j!=regions.size();++j)
				if(Inside(clicks[i],regions[j]))
				{
					flag=true;
					index_r=j;
				}
			if(flag)
			{
				cout<<(char)(index_r+'A')<<endl;	
				continue;
			}

			int Min=Max;

			vector<int> index_i;
			for(int j=0;j!=icons.size();++j)
			{
				int d=Distance(clicks[i],icons[j]);
		
				if(d<Min)
				{
					Min=d;
					index_i.clear();
					index_i.push_back(j+1);
				}
				else if(d==Min)
					index_i.push_back(j+1);
			}

			for(int k=0;k!=index_i.size();++k)
				cout<<setw(3)<<index_i[k];

			index_i.clear();
			cout<<endl;
		}

	return 0;
}