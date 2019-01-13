#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define N 200
using namespace std;
int n,ans;
bool map[N][N], mark[N];
int temp[N], result[N];

void dfs( int cur);
int main()
{
    int num;
	cin>>num;
    while(num--)
    {
        int a, b,k,count;
		ans = 0;
        memset(mark,false,sizeof(mark));		//��ʼ��Ϊ��ɫ
		memset(map,false,sizeof(map));
		memset(temp,0,sizeof(temp));
		memset(result,0,sizeof(result));
		
        cin>>n>>k;
		for( int i = 0; i < k; i ++)
		{
			cin>>a>>b;
			map[a][b] = map[b][a] = true;
		}

        dfs(1);

        cout<<ans<<endl;
        count = 0;
        for( int i = 1; i <= n; i ++)
        {
            if( result[i]) 
			{
				count++;
                if( count< ans)
                    cout<<i<<" ";
                else
                    cout<<i<<endl;
            }
        }
    }

    return 0;
}
void dfs( int cur)
{
    if( cur > n)
    {
        int num = 0;
        for( int i = 1; i <= n; i ++)
            if( temp[i]) 
				num++;
        if( num > ans)
        {
            ans = num;
            memcpy( result, temp, sizeof temp); 
        }
		return;
    }

    bool flag = false;
    for( int i = 1; i <= n; i ++)
    if( map[cur][i] && map[i][cur] && mark[i])
    {
		flag = true;
        break;
    }
    if(flag) 
		dfs( cur + 1);
    else					//�������
	{
        mark[cur] = true;  //Ⱦ�ɺ�ɫ��������һ��ݹ�
        temp[cur] = 1;
        dfs( cur + 1);
        mark[cur] = false; //Ⱦ�ɰ�ɫ(����Ⱦɫ)��������һ��ݹ�
        temp[cur] = 0;
        dfs( cur + 1);
    }

}