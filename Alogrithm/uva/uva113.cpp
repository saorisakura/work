#include <cstdio>/*�����ֱ��������ѧ֪ʶд���𰸱��ʽ*/
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