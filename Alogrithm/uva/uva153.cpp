#include <iostream>
#include <cstring>
#include <iomanip>
#define N 40
using namespace std;

int gcd(int x, int y);				
int main()						//����������л�˳��������ж��ᳬʱ��ֱ�������������Ϊ�Ǵ��������޷���ʾ���������ʾ����̫�鷳�ˡ�����ʹ����Լ�ֵķ�ʽ�ſ���Accept		
{								//ע�⣺ͳ������������Ҫ���Ǹ�����ĸ���ֵĴ������ܵ����г��ȣ�
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
                    factorial[k] = k;					//��ʼ��������������׳�ʱʹ��
                for(k = 0; k != 26; ++k) 
					if(flag[k])
					{
						for(m = 2; m <= flag[k]; ++m)	
						{
							int temp = m;
							for(n = 2; n != len-i; ++n)				
							{
								int g = gcd(temp, factorial[n]);			
								temp /= g;							//�ֱ�������Լ������Լ�ּ򻯱�����ִ���
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
int gcd(int x, int y)			//շת����������Լ��
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