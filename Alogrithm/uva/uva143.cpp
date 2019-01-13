#include <iostream>
#include <cstdio>
using namespace std;

struct Coord
{
	int x;
	int y;
};
int main() 
{
    while(true)								//����֮��Ĺ�ϵ�����⣬���Կ������������й�֪ʶ�����
	{ 
        Coord p[3], Tree; 
		int Minx,Miny,Maxx,Maxy;

		Minx=10000;
		Miny=10000;
		Maxx=0;
		Maxy=0;

        for (int i = 0; i < 3; ++i) 
		{ 
            float X,Y;
            if (!(cin >>X >>Y))
                return 0;

            p[i].x = (int)(X * 100+0.5);		//���������㱣֤����
            p[i].y = (int)(Y * 100+0.5);			
            
            if (p[i].x < Minx)			
                Minx =p[i].x;
            if (p[i].y < Miny)
                Miny = p[i].y;

            if (p[i].x > Maxx)			
                Maxx = p[i].x;
            if (p[i].y > Maxy)
                Maxy = p[i].y;

        }

        if (p[0].x == 0 && p[0].y == 0 && p[1].x == 0 && p[1].y == 0 && p[2].x == 0 && p[2].y == 0)
            break;

		Coord V[3] = {{p[1].x -p[0].x,p[1].y - p[0].y},{p[2].x -p[1].x,p[2].y -p[1].y},{p[0].x -p[2].x,p[0].y - p[2].y}};		//������ߵ�������ʾ
      
        if (V[0].x * V[1].y - V[1].x * V[0].y > 0) 
		{
            swap(p[0],p[1]);

            V[0].x =p[1].x -p[0].x;
            V[0].y =p[1].y - p[0].y;
            V[1].x =p[2].x - p[1].x;
            V[1].y = p[2].y -p[1].y;
            V[2].x =p[0].x -p[2].x;
            V[2].y = p[0].y - p[2].y;
        }
   
        if (Minx % 100 != 0)					//��Сֵ����ȡ��
            Minx = (Minx / 100 + 1) * 100;
        if (Miny % 100 != 0) 
            Miny = (Miny / 100 + 1) * 100;

        if (Maxx % 100 != 0)					//���ֵ����ȡ��
            Maxx = Maxx / 100 * 100;
        if (Maxy % 100 != 0)
            Maxy = Maxy / 100 * 100;
       
        if (Minx < 100)						//ע����Ŀ����ľ������ķ�Χ
            Minx = 100;
        if (Miny < 100)
            Miny = 100;
        if (Maxx > 9900) 
            Maxx = 9900;
        if (Maxy > 9900) 
            Maxy = 9900;

        int count = 0, i;
       
        for (Tree.y = Miny; Tree.y <= Maxy; Tree.y += 100)
            for (Tree.x = Minx; Tree.x <= Maxx; Tree.x += 100)
			{
                for (i = 0; i < 3; ++i) 
				{
                     Coord Vt = {p[i].x - Tree.x,p[i].y - Tree.y};
					 if (Vt.x * V[i].y - Vt.y * V[i].x > 0)
                        break;
                }
                 if(i == 3)
					count++;
            }
       printf("%4d\n",count);
    }
    return 0;
}