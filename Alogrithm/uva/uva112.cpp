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
		flag=tree(sum,aim,rchild)|tree(sum,aim,lchild);//递归遍历左子树至到左子树为空时开始递归回判断遍历右子树，这句很重要，递归！
		cin>>c;
		if(!rchild&&!lchild)//当递归回时判断某节点的左右子树为空时，判断该路径的和是否与目标值相等
		{
			return sum==aim;
		}
		else
			return flag;//该路径的和与目标值不相等时，继续递归回
	}	
	else			//当遍历至该子树末端时
	{
		cin.clear();//清除错误状态
		cin>>c;
		child=false;//
		return false;
	}
	
}
