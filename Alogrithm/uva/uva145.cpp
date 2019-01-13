#include <iostream>
#include<iomanip>
#include <cstdio>
using namespace std;

struct call
{
	char step;
	char number[20];
	int start;
	int end;
};
int D,E,N;
int calculate(int t1,int t2);
int main()							//简单的话费计算，注意格式输出
{
	call state;
	while(true)
	{
		double fee;
		int hour_s,hour_e,minute_s,minute_e;
		cin>>state.step;
				
		if(state.step=='#')
			break;

		scanf("%s %d %d %d %d",&state.number,&hour_s,&minute_s,&hour_e,&minute_e);

		state.start=hour_s*60+minute_s;
		state.end=hour_e*60+minute_e;
		calculate(state.start,state.end);

		switch(state.step)
		{
		case 'A':
			fee=0.10*D+0.06*E+0.02*N;
			cout << setw(10) <<state.number<<setw(6)<<D<<setw(6)<<E<<setw(6)<<N<<setw(3)<<state.step<<setw(8);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout<<fee<<endl;
			break;
		case 'B':
			fee=0.25*D+0.15*E+0.05*N;
			cout << setw(10) <<state.number<<setw(6)<<D<<setw(6)<<E<<setw(6)<<N<<setw(3)<<state.step<<setw(8);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout<<fee<<endl;
			break;
		case 'C':
			fee=0.53*D+0.33*E+0.13*N;
			cout << setw(10) <<state.number<<setw(6)<<D<<setw(6)<<E<<setw(6)<<N<<setw(3)<<state.step<<setw(8);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout<<fee<<endl;
			break;
		case 'D':
			fee=0.87*D+0.47*E+0.17*N;
			cout << setw(10) <<state.number<<setw(6)<<D<<setw(6)<<E<<setw(6)<<N<<setw(3)<<state.step<<setw(8);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout<<fee<<endl;
			break;
		case 'E':
			fee=1.44*D+0.80*E+0.30*N;
			cout << setw(10) <<state.number<<setw(6)<<D<<setw(6)<<E<<setw(6)<<N<<setw(3)<<state.step<<setw(8);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout<<fee<<endl;
			break;
		};
	}

	return 0;
}
int calculate(int t1,int t2)
{
	int sum;
	
	if(t1==t2)
	{
		D=600,E=240,N=600;
		return 0;
	}
	if(t1<t2)
	{
		if(t2<=480)					//no error
		{
			N=t2-t1,D=0,E=0;
			return 0;
		}
		if(t2>480 && t2<=1080)			//no error
		{
			sum=0;
			for(int i=t1;i<=t2;++i)
			{
				if(i==480)
				{
					N=sum,E=0,D=t2-480;
					return 0;
				}
				sum++;
			}
			D=sum-1,N=0,E=0;
			return 0;
		}
		if(t2>1080 && t2<=1320)				//no error
		{
			sum=0,N=0,D=0;
			for(int i=t1;i<=t2;++i)
			{
				if(i==480)
					N=sum,sum=0;
				if(i==1080)
					D=sum,sum=0;
				sum++;
			}
			E=sum-1;
			return 0;
		}
		if(t2>1320)				//no error
		{
			sum=0,N=0,D=0,E=0;
			for(int i=t1;i<=t2;++i)
			{
				if(i==480)
					N=sum,sum=0;
				if(i==1080)
					D=sum,sum=0;
				if(i==1320)
					E=sum,sum=0;
				sum++;
			}
			N=N+sum-1;
			return 0;
		}
	}
	if(t1>t2)
	{
		int N1,N2,D1,D2,E1,E2;

		if(t2<=480)
			N2=t2,D2=0,E2=0;
		if(t2>480 && t2<=1080)
			N2=480,D2=t2-480,E2=0;
		if(t2>1080 && t2<=1320)
			D2=600,N2=480,E2=t2-1080;
		if(t2>1320)
			D2=600,E2=240,N2=t2-840;
		
		
		if(t1<=480)
			N1=600-t1,D1=600,E1=240;
		if(t1>480 && t1<=1080)
			N1=120,D1=1080-t1,E1=240;
		if(t1>1080 && t1<=1320)
			N1=120,D1=0,E1=1320-t1;
		if(t1>1320)
			N1=1440-t1,D1=0,E1=0;
		D=D1+D2,E=E1+E2,N=N1+N2;
		return 0;
	}

}