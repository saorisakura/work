#include <iostream>

using namespace std;

bool tree(int sum,int aim,bool &child);

int main()
{
	
	int aim;
	bool result,child;

	while(cin>>aim)
	{
		result=tree(0,aim,child);

		if(result)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}
bool tree(int sum,int aim,bool &child)
{
	bool flag,rchild,lchild;
	int t;
	char c;
	cin>>c;
	if(cin>>t)
	{
		sum+=t;
		child=true;
		flag=tree(sum,aim,rchild)|tree(sum,aim,lchild);//�ݹ��������������������Ϊ��ʱ��ʼ�ݹ���жϱ�����������������Ҫ���ݹ飡
		cin>>c;
		if(!rchild&&!lchild)//���ݹ��ʱ�ж�ĳ�ڵ����������Ϊ��ʱ���жϸ�·���ĺ��Ƿ���Ŀ��ֵ���
		{
			return sum==aim;
		}
		else
			return flag;//��·���ĺ���Ŀ��ֵ�����ʱ�������ݹ��
	}	
	else			//��������������ĩ��ʱ
	{
		cin.clear();//�������״̬
		cin>>c;
		child=false;//
		return false;
	}
	
}
