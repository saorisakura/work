#include <iostream>
#include <cstdio>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

void Produce_str(string &str, int &n, int L);		//Ҳ���Բ��õݹ�
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
void Produce_str(string &str, int &n, int L)			//��������ʵ�α�������ֱ�Ӹı�str��n��ֵ������Ҫ��
{
    
    int len= str.length(), len_half = (str.length() + 1) / 2,flag;
    
    for (int i = 'A'; i!=(L +'A'); ++i) 
	{
        str.push_back((char)i); 
		flag=1;
        for (int m = 1; m <= len_half; ++m) 
            if (equal(str.end() - m, str.end(), str.end() -m * 2))	//equal(first1,last1,first2,compare) �ж����������Ƿ����
			{
                flag=0; 
                break; 
            }
        if (flag != 0) 
		{    
            if ((--n)== 0) 
				return;
            Produce_str(str, n, L);
            if (n == 0)					//��ֹ�ݹ����ʱ�ƻ��Ѿ��ﵽҪ����ַ���
				return;
        } 
		str.erase(str.begin()+len); 
    }
}