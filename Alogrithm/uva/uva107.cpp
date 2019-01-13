#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double H,M, N,i;

	while (cin>>H>>M)
	{
		if (H==0 || M==0) 
			break;

			N =1;

		while (abs(log(N)/log(N+1) -log(M)/log(H)) >1e-10)
			++N;

		i=int(0.5+log(H)/log(N+1));

		if (int(N) ==1) 
			cout<<int(i);
		else
			cout<<int(0.5+ (1-pow(N,i)) / (1- N) );

		cout<<' '<<int(0.5+ (1-pow(N/(N+1),i+1)) * (N+1) *H ) <<endl;
	}
	return 0;
}