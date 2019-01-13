#include <iostream>
using namespace std;

int main() 
{
    
    int k,flag = 1;

	while( cin >> k)			
	{
    
        if (flag == 0)			//第一次输出不要换行，否则第二次亦换行会导致多换了一行
            cout << endl;
        
		int m=k-1;
        
        for (int i = 0; i< k; ++i) 
		{
            cout << 1;				//输出第一个单元的第一个交点位置即 1
            for (int j = 1; j < k; ++j)
                cout << ' ' << i * m + j + 1;		//输出第一个单元
            cout << endl;
        }
        for (int i = 0; i < m; ++i) 
		{
            for (int j = 0; j < m; ++j)
			{
                cout << i + 2;			//对应第一个交点的位置
                for (int s = 0; s < m; ++s)
                    cout << ' ' << (j + (s * i)) % m + s * m + k + 1;		// 参考 已推得的现有公式输出
                cout << endl;
            }
        }
		 flag = 0;
    }
    return 0;
}