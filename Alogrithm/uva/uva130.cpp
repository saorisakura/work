#include <iostream>
#include <vector>
using namespace std;

int final(int n,int k);

int main()
{
    int n,k;
    while(cin>>n>>k && k*n!=0)
	{
       if(n==1)
           cout<<1<<endl;
       else{
          cout<<n-final(n,k)+2<<endl;  //final为从第一个人开始计数，返回留下的那个人的编号i，有归纳法可知，需从n-final+2开始，最后为1幸存
       }
    }
   return 0;
}

int final(int n,int k)
{
      vector<int>people;
      int p=-1,p2,i;  //数组从第0个开始计数，所以p取-1
      for(i=0;i<n;i++)
	  {
         people.push_back(i+1);
      }
      while(people.size()>1)
	  {
         p=(p+k)%people.size();//找到第K个人,p为原来的编号

         for(i=0,p2=p;i<k;i++)
		 {
           p2=(p2+1)%people.size();//再从下一个开始计数，p2为原来的编号，数到第k个人，找到下一个杀掉的人
           if(p2==p) 
			   i--;  //p已经被删除，所以不计数
         }
         people[p]=people[p2];  //用p2代替p

         people.erase(people.begin()+p2);  //删除节点
         if(p>p2) 
			 p--;  //这时环的个size减1了，如果p>p2,删除了p2后，p的值也要减1
      }
      return people[0];
}