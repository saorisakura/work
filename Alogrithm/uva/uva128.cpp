#include <iostream>
#include <string>
#define M 34943
using namespace std;

int main()							//本题处理 的数太大了，不可以直接处理，需要用大数的处理方法
{
	string s;
	int len;
	long long ans;

	while(getline(cin,s))
	{
		ans=0;
		len=s.length();

		if(len == 0) 
		{  
            cout << "00 00" << endl;  
            continue;  
        }  
        if(s[0] == '#') 
			break;  
		
		for(int i = 0; i < len; i++)
        {
            ans = ((ans<<8)+s[i])%M;				//大数除法
        }
        ans =(ans<<16)%M;

		ans=M-ans%M;

		s="0000";
		int i = 3;  
        while(ans != 0)
		{  
            int res;
			res = ans % 16; 
			ans /= 16;  
            if(res < 10)  
                s[i--] = res + '0';  
            else  
                s[i--] = res - 10 + 'A';  
            
        }  
        cout << s[0] << s[1] << " " << s[2] << s[3] << endl;  
    }  
    return 0;  

}