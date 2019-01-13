#include<stdio.h>

int main()
{
    int n1, n2, n, temp, i, j, c;
    while(scanf("%d %d", &n1, &n2)==2)
	{
		printf("%d %d ", n1, n2);
		if ( n1>n2 )
		{
			temp = n1;
			n1 = n2;
			n2 = temp;
		}
    
		c = 0;
    
		for( i=n1; i<=n2 ;i++)
		{
			j = 0;
			n = i;
			while ( n!=1 )
			{
				if ( n%2==0 )
					n=n/2;
				else 
					n = 3*n + 1;
				j++;
            }
			if(j>c)
				c=j;
        }
		printf("%d\n", c+1);
    }
    return 0;
}
