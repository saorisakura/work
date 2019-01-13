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
int main()											//ģ����̵ƵĽ��棬ע��Ч�ʣ�
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
void Simulation(Light l, int seconds, int i)		//ģ�� �̵�->�Ƶ�->��� ��˳�����жϵ������������ÿ���Ƶĳ�ʼ��״̬Ϊ�̵Ƹ���state��ʾ���ǵ�ǰ״̬�����һ�룬��֤��state����second�������Ӧ��״̬��
{
        while(l.state<= seconds)
        {
                if(l.green)							
                {
                        l.state += (l.time+5);			//�̵�->��ƣ������̵���
                        l.green = false;
                }
                else								//���->�̵ƣ������̵���
                {
                        l.state += (l.time-5);		
                        l.green = true;
                }
        }
        L[i] = l;
}