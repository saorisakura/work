#include <iostream>
#include <cstdio>
using namespace std;
 
struct Light
{
        bool green;
        int time;		
        int state;		
};
Light L[100];
 
void Simulation(Light l, int second, int i);
int main()											//模拟红绿灯的交替，注意效率！
{
        int a,b,c,k,begin,len,second,minute,hour;

        while(true)
        {
                scanf("%d %d %d", &a, &b, &c);
                if(a == 0 && b == 0 && c == 0) 
					break;
                L[0].green = true;
                L[1].green = true;
                L[0].time = a;
                L[1].time = b;
                L[0].state = a-5;
                L[1].state = b-5;
                k = 2;
                begin = min(L[0].state, L[1].state);
                while(c)
                {
                        L[k].green = true;
                        L[k].time =c;
                        L[k].state =c-5;
                        begin= min(begin, L[k].state);
                        k++;
                        scanf("%d", &c);
                }
				len=k;
                second = begin;
                while(second <= 18000)
                {
                        for(int i = 0; i < len; ++i)
                        {
                                Simulation(L[i], second, i);
                        }
                        bool flag = true;
                        for(int i = 0; i < len; ++i)	
                        {
                                if(!L[i].green)
                                {
                                        flag = false;
                                        break;
                                }
                        }
                        if(flag) 
							break;
                        else 
							second++;
                }
                if(second > 18000) 
					cout<<"Signals fail to synchronise in 5 hours"<<endl;
                else
                {
                        hour=second/3600;
						minute=(second-hour*3600)/60;
						second=second-hour*3600-minute*60;
						printf("%02d:%02d:%02d\n",hour,minute,second);
                }
        }
	return 0;
}
void Simulation(Light l, int seconds, int i)		//模拟 绿灯->黄灯->红灯 的顺序到所判断的秒数的情况，每个灯的初始的状态为绿灯刚灭，state表示的是当前状态的最后一秒，保证当state大于second处于其对应的状态内
{
        while(l.state<= seconds)
        {
                if(l.green)							
                {
                        l.state += (l.time+5);			//绿灯->红灯，处于绿灯外
                        l.green = false;
                }
                else								//红灯->绿灯，处于绿灯内
                {
                        l.state += (l.time-5);		
                        l.green = true;
                }
        }
        L[i] = l;
}