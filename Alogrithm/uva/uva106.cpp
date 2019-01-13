#include <iostream>
#include <math.h>
using namespace std;

int main(void) 
{
	int N, m, n, nmax, mmax,count;
    for (count= 0;cin >> N;count = 0) 
	{
        bool flag[1000000] = {false};
        for (m = 2, mmax = (int)sqrt((float)N - 1); m <= mmax; ++m) 
		{
             nmax = (int)sqrt((float)N - m * m);
            nmax = nmax >= m ? m - 1 : nmax;
            for (n = 1; n <= nmax; ++n) 
			{
                if (n % 2 != m % 2) 
				{
                    int a = m, b = n, c;
                    for(int r; (r = a % b) != 0; a = b, b = r);
                    if (b == 1) 
					{
                        ++count;                      
                        a = m * m - n * n, b = 2 * m * n, c = m * m + n * n;
                        for (int k = 0; c * k <= N; ++k)
						{
                            flag[a * k] = flag[b * k] = flag[c * k] = 1;
                        }
                    }
                }
            }
        }
        cout <<count<< ' ';
        for (count= 0, m = 1; m <= N; count+= !flag[m++]);
			cout << count<< endl;
    }
    return 0;
}
