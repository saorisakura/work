#include <cstdio>/*此题可直接利用数学知识写出答案表达式*/
#include <cmath>
#include <iostream>
using namespace std;

double n,p;

int main(void)
{
	double answer;

    while(cin>>n>>p)
	{
		answer=pow(p,1/n);

		printf("%.lf\n",answer);
	}

	return 0;
}