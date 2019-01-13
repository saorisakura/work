#include <cstdio>
 
int main()
{
    int x[20],y[20];	//直接求佩尔方程就可以了
						
	x[0]=3;
	y[0]=2;

	for (int i = 1; i <= 10; i++)	//搜索输出十组，太耗时了
    {
        x[i] = x[0] * x[i-1] + 2 * y[0] * y[i-1];
        y[i] = x[i-1] * y[0] + y[i-1] * x[0];
       
		printf("%10d%10d\n", y[i] / 2, (x[i] - 1) / 2 );
    }
    return 0;
}