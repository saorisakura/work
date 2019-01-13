#include <iostream>
using namespace std;

int place(float x, float y); 

int main(void)
{

	float x, y;
	int way1,way2,answer;
	while(cin>>x>>y)
	{
		way1= (int)x * (int)y;
		way2=max(place(x, y), place(y, x));

		answer=max(way1, way2);

		cout << answer<< (way1>=way2? " grid" : " skew")<<endl;

	}

	return 0;

}

int place(float x, float y) 
{

	const float t_high=0.8660254f;
	
	int Rownum,number;

	if(y<1)
		Rownum=0;
	else
		Rownum= 1 + (int)((y - 1) /t_high);

	if(x - (int)x < 0.5f)
	{
		if(Rownum%2==0)
			number=Rownum * (int)x-(Rownum/2);
		else
			number=Rownum * (int)x-((Rownum-1)/2);

	}
	else
		number=Rownum * (int)x;
	return number;

}
