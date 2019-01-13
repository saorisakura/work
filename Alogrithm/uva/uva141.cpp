#include <iostream>
#include <cstring>
#define N 51
using namespace std; 

int state[600][N][N], S[N][N];		//注意状态数组设置太小，会运行错误
int num;
bool compare(int k, int n);
bool judge(int n);
int main()								//旋转棋盘，保存状态，之后比较
{
    int n, x, y, flag;
    char op;
    while(cin>>n)
    {
		if(n==0)
			break;

        num=0,flag = 1;
        memset(S, 0, sizeof(S));
        memset(state, 0, sizeof(state)); 

        for(int i = 0; i!=2 * n;++i)
        {
            cin>>x>>y>>op;
            x--,y--;
            if(op == '+') 
				S[x][y] = 1;
            else 
				S[x][y] = 0;
            
			if(!flag)			
				continue;
            
			if(judge(n))
            {
                flag = 0;
                cout<<"Player "<<((i%2==1) ? 1 : 2)<<" wins on move "<<(i + 1)<<endl;;
            }
        }
        if(flag) 
			cout<<"Draw"<<endl;
    }

    return 0;
}
bool compare(int k, int n)
{
    for(int i = 0; i!= n;++i)
		for(int j = 0; j != n; ++j)
			if(state[k][i][j] != S[i][j])
				return false;
    return true;
}

bool judge(int n)
{
    for(int k = 0; k != num; ++k)
        if(compare(k, n)) 
			return true;

    for(int i = 0; i !=n; ++i)
		for(int j = 0; j != n; ++j)
        state[num][i][j] = S[i][j];    
    num++;

    for(int i = 0; i != n; ++i)
		for(int j = 0; j != n;++j)
        state[num][i][j] = S[n - j - 1][n - i - 1];
    num++;

    for(int i = 0; i != n; ++i)
		for(int j = 0; j != n;++j)
        state[num][i][j] = S[j][i];
    num++;

    for(int i = 0; i !=n; ++i)
		for(int j = 0; j != n; ++j)
        state[num][i][j] = S[i][n - j - 1];
    num++;

    for(int i = 0; i!= n;++i)
		for(int j = 0; j!= n; ++j)
			state[num][i][j] = S[n - i - 1][j];
    num++;
    return 0;
}
