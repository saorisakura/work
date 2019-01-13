#include <iostream>
#include <cstdio>
using namespace std;

struct Point 
{
    double x, y;
};
struct Segment 
{
    Point s, e;
};
double belong(double a, double b, double c);
bool on(Segment a, Point b);
double cross(Point a, Point b, Point c);
bool judge(Segment a, Segment b);
int main()										//利用几何学中的向量叉积的情况来判断量线段是否相交，不会容易漏判断一些情况；也可以用直接的直线方程的方法求解，不过容易遗漏一些特殊的情况
{
    int n;
	double x_left, y_top,x_right, y_bottom, temp;
	bool flag1,flag2,flag3,flag4;
	Segment line, edge;

    cin>>n;
    while(n--) 
	{
		flag1=flag2=flag3=flag4=false; 

		cin>>line.s.x>>line.s.y>>line.e.x>>line.e.y;
	
        cin>>x_left>>y_top>>x_right>> y_bottom;

        if(x_left > x_right)
            temp = x_left, x_left = x_right, x_right = temp;
        if(y_top<  y_bottom)
            temp =y_top,y_top = y_bottom,  y_bottom = temp;
        
        if(belong(x_left, x_right, line.s.x) && belong(y_bottom,y_top, line.s.y))
            cout<<"T"<<endl;
        else if(belong(x_left,x_right, line.e.x) && belong(y_bottom,y_top, line.e.y))
            cout<<"T"<<endl;
        else 
		{
            
            edge.s.x = x_left, edge.s.y = y_top, edge.e.x = x_left, edge.e.y = y_bottom;		//分别判断每条边与线段的相交情况
            flag1 =judge(edge, line);

            edge.s.x =x_right, edge.s.y = y_top, edge.e.x = x_right, edge.e.y = y_bottom;
            flag2 =judge(edge, line);

            edge.s.x =x_left, edge.s.y = y_bottom, edge.e.x =x_right, edge.e.y =  y_bottom;
            flag3 =judge(edge, line);

            edge.s.x =x_left, edge.s.y =y_top, edge.e.x =x_right, edge.e.y =y_top;
            flag4 =judge(edge, line);

            if(flag1 || flag2 || flag3 || flag4)
                cout<<"T"<<endl;
            else
                cout<<"F"<<endl;
        }
    }
    return 0;
}
double belong(double a, double b, double c)			
{
	if(c >= a && c <= b)
		return true;
	return false;
}
bool on(Segment a, Point b)
{
    double minx, maxx, miny, maxy;
    minx = min(a.s.x, a.e.x);
    maxx = max(a.s.x, a.e.x);
    miny = min(a.s.y, a.e.y);
    maxy = max(a.s.y, a.e.y);
    if(belong(minx, maxx, b.x) && belong(miny, maxy, b.y))
	{
        if((a.s.x-a.e.x)*(b.y-a.s.y) == (a.s.y-a.e.y)*(b.x-a.s.x)) 
		{
            return true;
        }
    }
    return false;
}
double cross(Point a, Point b, Point c) 
{
    double ans;

	ans=(b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
	return ans;
}
bool judge(Segment a, Segment b) 
{
    double ans1,ans2,ans3,ans4;

	ans1=cross(a.s, a.e, b.s)*cross(a.s, a.e, b.e); 
	ans2=cross(a.e, a.s, b.s)*cross(a.e, a.s, b.e);
	ans3=cross(b.s, b.e, a.s)*cross(b.s, b.e, a.e);
	ans4=cross(b.e, b.s, a.s)*cross(b.e, b.s, a.e); 

	if(on(a, b.s) || on(a, b.e) || on(b, a.s) || on(b, a.e))
        return true;
    if(ans1< 0 &&  ans2< 0 && ans3< 0 && ans4< 0)
        return true;
    return false;
}