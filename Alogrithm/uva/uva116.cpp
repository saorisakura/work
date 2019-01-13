#include <iostream> 
#include <cstdio>
#include <cstring>
using namespace std;
 
int route[ 11 ][ 101 ]; 
void output( int rows, int cols, int m );
int main() 
{ 
	int m,n,map[ 11 ][ 101 ],sum[ 11 ][ 101 ];  

    while (cin>>n>>m) 
	{ 
		int down,up,Min =10000000,temp= 1;
        memset( sum, 0, sizeof(sum) );
		memset( map, 0, sizeof(map) );
		memset( route, 0, sizeof(route) );

        for ( int i = 1 ; i <= n ; ++ i ) 
			for ( int j = 1 ; j <= m ; ++ j )
				cin>>map[i][j]; 
                
        for ( int i = m ; i >= 1 ; -- i )			//从后向前遍历所有的点，判断记录其对应三种情况的下一个点的最小值的行数
			for ( int j = 1 ; j <= n ; ++ j ) 
			{ 
				sum[j][i] = sum[j][i+1]+map[j][i];			//水平向前
				route[j][i] = j; 

				down = j+1;									//斜向下
				if ( down > n ) 
					down = 1; 
				if ( sum[j][i] == sum[down][i+1]+map[j][i] ) 
			        if ( route[j][i] > down ) 
						route[j][i] = down; 
				if ( sum[j][i] > sum[down][i+1]+map[j][i] ) 
				{ 
					sum[j][i] = sum[down][i+1]+map[j][i]; 
					route[j][i] = down; 
				} 

				up = j-1;									//斜向上
				if ( up < 1 ) 
					up = n; 
				if ( sum[j][i] == sum[up][i+1]+map[j][i] )
					if ( route[j][i] > up ) 
						route[j][i] = up; 
				if ( sum[j][i] > sum[up][i+1]+map[j][i] ) 
				{ 
					sum[j][i] = sum[up][i+1]+map[j][i]; 
					route[j][i] = up; 
				} 
			} 

		for ( int i = 1 ; i <= n ; ++ i ) 
			if (sum[i][1]<Min) 
			{ 
				Min = sum[i][1]; 
				temp= i; 
			} 
             
		output( temp, 1, m ); 
		cout<<Min<<endl; 
    } 

    return 0; 
} 
 void output( int rows, int cols, int m ) 
{ 
    if ( cols < m ) 
	{ 
        cout<<rows<<" ";
        output( route[rows][cols], cols+1, m ); 
    }
	else
        cout<<rows<<endl; 
} 

