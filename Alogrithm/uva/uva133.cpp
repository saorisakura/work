#include <iostream>  
#include <iomanip>  
using namespace std;  
  
int main()  
{  
    int N,k,m;  
    while (cin >> N >> k >> m && (N || k || m))					//模拟双向循环数数
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
				i = (i + 1) % N;			//逆时针方向数一次
                  
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
				j = (j-1+ N) % N;			//顺时针方向数一次，加N使当数的人数的下标小于0时，顺时针循环
            }  
            state[i] = true;  
            state[j] = true;  
            if (i != j)  
            {  
                flag+=2; 
                cout << setw(3) << (i + 1)  << setw(3) << (j + 1);  //人的编号比下标大1
  
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
				i = (i + 1) % N;  //找到i的下一个起始点 
              
            j = (j-1+N) % N;  
            while (state[j]) 
				j = (j -1+ N) % N;  //找到j的下一个起始点 
        }  
        cout << endl;  
    }  
    return 0;  
}  