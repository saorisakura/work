#include<iostream>
using namespace std;

#define D 100

int mat[D][D],psum[D*D];

int main()
{
	int N;
	int sum=0,max=-128;

	cin>>N;
	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin>>mat[i][j];

	for(int rowbeg=0;rowbeg<N;rowbeg++)
		for(int rowend=rowbeg;rowend<N;rowend++)
		{
			
			for(int j=0;j<N;j++)
			{
				for(int i=rowbeg;i<=rowend;i++)
					sum=sum+mat[i][j];
				psum[j]=sum;
				sum=0;
			}
			for(int colbeg=0;colbeg<N;colbeg++)
				for(int colend=colbeg;colend<N;colend++)
				{
					for(int i=colbeg;i<=colend;i++)
						sum=sum+psum[i];
					if(sum>max)
						max=sum;
					sum=0;
				}
		}
	
	cout<<max<<endl;
	return 0;
}