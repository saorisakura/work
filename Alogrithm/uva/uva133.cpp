#include <iostream>  
#include <iomanip>  
using namespace std;  
  
int main()  
{  
    int N,k,m;  
    while (cin >> N >> k >> m && (N || k || m))					//ģ��˫��ѭ������
    {  
        bool state[21]={false};  
        int count,flag=0,i=0,j=N-1;
         
        while(flag <= N)				
        {    
			count= 0;  
            while(true)					
            {  
                if (!state[i])   
                {  
                    count++;  
                    if (count== k)			
						break;  
                }  
				i = (i + 1) % N;			//��ʱ�뷽����һ��
                  
            }  
           count= 0;  
            while(true)						
            {  
                if (!state[j])  
                {  
                    count++;  
                    if (count== m)			
						break;  
                }  
				j = (j-1+ N) % N;			//˳ʱ�뷽����һ�Σ���Nʹ�������������±�С��0ʱ��˳ʱ��ѭ��
            }  
            state[i] = true;  
            state[j] = true;  
            if (i != j)  
            {  
                flag+=2; 
                cout << setw(3) << (i + 1)  << setw(3) << (j + 1);  //�˵ı�ű��±��1
  
            }  
            else  
            {  
                flag++;  
                cout << setw(3) << (i+1);  
            }  
            if (flag != N)  
                cout << ",";  
            else 
				break;  
  
            i = (i + 1) % N;  
            while (state[i]) 
				i = (i + 1) % N;  //�ҵ�i����һ����ʼ�� 
              
            j = (j-1+N) % N;  
            while (state[j]) 
				j = (j -1+ N) % N;  //�ҵ�j����һ����ʼ�� 
        }  
        cout << endl;  
    }  
    return 0;  
}  