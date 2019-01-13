#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define N 500
using namespace std;

struct Coord
{
	int x;
	int y;
	int index;
};
int cmp(const void *i, const void *j) 
{
    Coord *x, *y;
    x = (Coord *)i, y = (Coord *)j;
    if(x->x != y->x)
        return x->x - y->x;
    if(x->y != y->y)
        return x->y - y->y;
	return x->index - y->index;
}
bool judge(Coord a,Coord b,Coord c)
{
	return ((b.y-a.y)*(c.x-b.x)==(c.y-b.y)*(b.x-a.x));
}
int main()
{
	Coord points[N];

	while(cin>>points[0].x>>points[0].y)
	{
		if(!points[0].x && !points[0].y)
			break;

		int n=1,i,j,k;
		points[0].index=n;
		while(cin>>points[n].x>>points[n].y)
		{
			if(!points[n].x && !points[n].y)
				break;
			++n;
			points[n].index=n;
			
		}
		
		qsort((void *)&points[0],n,sizeof(Coord),cmp);
		int map[N][N]={0},flag = 0;
		for(i=0;i!=n;++i)
			for(j=i+1;j!=n;++j)
			{
				if(map[i][j]==0)
				{
					map[i][j] = 1;
                    int ans[301], count = 2;
                    ans[0] = i, ans[1] = j;
					for(k=j+1;k!=n;++k)
					{
							if(judge(points[i],points[j],points[k]))
								ans[count++] = k;
					}
					if(count>2)
					{
						if(!flag)
                            cout<<"The following lines were found:"<<endl;
                        flag = 1;
                        for(int n = 0; n!=count; ++n)
                            for(int m= 0;m!=count;++m)
                                map[ans[n]][ans[m]] = 1;
                        for(int n = 0; n!= count; ++n)
							printf("(%4d,%4d)", points[ans[n]].x,points[ans[n]].y);
						cout<<endl;
					}


				}
			}
			 if(!flag)
            cout<<"No lines were found"<<endl;
 
	}

	return 0;
}