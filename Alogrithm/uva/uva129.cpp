#include <iostream>
#include <cstdio>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

void Produce_str(string &str, int &n, int L);		//也可以不用递归
int main() 
{
	int n, L;
    while(cin >> n >> L)
	{ 
		if(n==0 && L==0)
			break;
        string str; 
        Produce_str(str, n, L);
        int len= str.length();
		char temp;
        for (int i = 4;i<str.length(); i+= 5) 
		{ 
            if(i==79)
				temp='\n';
			else 
				temp=' ';
            str.insert(str.begin()+i,temp);
        } 
        cout <<str<<endl<<len<<endl;
    }
    return 0;
}
void Produce_str(string &str, int &n, int L)			//函数调用实参本身，函数直接改变str和n的值，很重要！
{
    
    int len= str.length(), len_half = (str.length() + 1) / 2,flag;
    
    for (int i = 'A'; i!=(L +'A'); ++i) 
	{
        str.push_back((char)i); 
		flag=1;
        for (int m = 1; m <= len_half; ++m) 
            if (equal(str.end() - m, str.end(), str.end() -m * 2))	//equal(first1,last1,first2,compare) 判断两个容器是否相等
			{
                flag=0; 
                break; 
            }
        if (flag != 0) 
		{    
            if ((--n)== 0) 
				return;
            Produce_str(str, n, L);
            if (n == 0)					//防止递归回溯时破坏已经达到要求的字符串
				return;
        } 
		str.erase(str.begin()+len); 
    }
}