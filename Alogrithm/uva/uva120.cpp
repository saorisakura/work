#include <iostream>
#include <cstdio>

using namespace std;

#define N 30

void turn(int a);

int cakes[N],s[N];
int length;

int main(void)
{
	int i,j,m,index,max;
	 while(scanf("%d",&cakes[0])!=EOF)
    {
        i=1;
        while(1)
        {
            if(getchar()!=' ')break;
            scanf("%d",&cakes[i++]);
        }
		
		length=i;
		m=length;

		printf("%d",cakes[0]);
		for(i=1;i<length;i++)
			printf(" %d",cakes[i]);
		cout<<endl;
								
		for(i=m-1;i>=0;--i) 
		{
			max=0;
			for(j=0;j<=i;++j)	
			{
				if(cakes[j]>max)
				{
					max=cakes[j];		//�ҳ��޶���Χ�ڵ����ֵ����¼�����ڵ�λ��
					index=j;
				}
			}
			
			if(index==i)
				continue;		//������ֵ���ô������跭ת����λ�ã�������ֱ�ӵ���һѭ��
			if(index==0)		//������ֵ��0����תһ�μ���
			{
				turn(i+1);
				continue;
			}

			turn(index+1);			//�����ֵ����ת������ת������
			turn(i);			//�������ֵת����ѭ���޶��ķ�Χ����ײ�
		}	
		printf("%d",0);
		cout<<endl;
	}
	return 0;
}
void turn(int a)	//��ת no error
{
	int j;
	for(j=a;j>=0;j--)
		s[a-j]=cakes[j-1];
	for(j=0;j<a;j++)
		cakes[j]=s[j];
	printf("%d ",length-a+1);
}
