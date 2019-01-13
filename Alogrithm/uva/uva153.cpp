#include <iostream>
#include <cstring>
#include <iomanip>
#define N 40
using namespace std;

int gcd(int x, int y);				
int main()						//求出各个排列或顺次求出排列都会超时，直接算出排列数因为是大数所以无法表示，用数组表示计算太麻烦了。。。使用逐步约分的方式才可以Accept		
{								//注意：统计排列数最主要的是各个字母出现的次数和总得序列长度！
    char str[N];
    while(cin>>str) 
	{
        if(str[0] == '#')
            break;
		long long temp,result = 0;
		int i, j, k, m, n;
        int factorial[N],flag[26],len = strlen(str);
		memset(flag,0,sizeof(flag));
       
        for(i = 0; i!=len; i++) 
		{
            ++flag[str[i]-'a'];
        }
        
        for(i = 0; i!=len; ++i) 
		{
            for(j = 0;j!=(str[i]-'a'); ++j) 
			{
                if(flag[j] == 0) 
					continue;

                --flag[j];			
                for(k = 2; k !=N; ++k)
                    factorial[k] = k;					//初始化以用来后续求阶乘时使用
                for(k = 0; k != 26; ++k) 
					if(flag[k])
					{
						for(m = 2; m <= flag[k]; ++m)	
						{
							int temp = m;
							for(n = 2; n != len-i; ++n)				
							{
								int g = gcd(temp, factorial[n]);			
								temp /= g;							//分别除以最大公约数，以约分简化避免出现大数
								factorial[n] /= g;	
							}
						}
					}
                temp = 1;
                for(k = 2; k != len-i; ++k)		
                    temp *=factorial[k];
                result += temp;
                ++flag[j];
            }
            --flag[str[i]-'a'];			
        }
       cout<<setiosflags(ios::right)<<setw(10)<<result+1<<endl;
    }

    return 0;
}
int gcd(int x, int y)			//辗转相除法求最大公约数
{
    int temp;
    while(x%y) 
	{
        temp=x;
		x=y;
		y=temp%y;
    }
    return y;
}