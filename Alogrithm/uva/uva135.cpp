#include <iostream>
using namespace std;

int main() 
{
    
    int k,flag = 1;

	while( cin >> k)			
	{
    
        if (flag == 0)			//��һ�������Ҫ���У�����ڶ����໻�лᵼ�¶໻��һ��
            cout << endl;
        
		int m=k-1;
        
        for (int i = 0; i< k; ++i) 
		{
            cout << 1;				//�����һ����Ԫ�ĵ�һ������λ�ü� 1
            for (int j = 1; j < k; ++j)
                cout << ' ' << i * m + j + 1;		//�����һ����Ԫ
            cout << endl;
        }
        for (int i = 0; i < m; ++i) 
		{
            for (int j = 0; j < m; ++j)
			{
                cout << i + 2;			//��Ӧ��һ�������λ��
                for (int s = 0; s < m; ++s)
                    cout << ' ' << (j + (s * i)) % m + s * m + k + 1;		// �ο� ���Ƶõ����й�ʽ���
                cout << endl;
            }
        }
		 flag = 0;
    }
    return 0;
}