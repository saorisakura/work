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
          cout<<n-final(n,k)+2<<endl;  //finalΪ�ӵ�һ���˿�ʼ�������������µ��Ǹ��˵ı��i���й��ɷ���֪�����n-final+2��ʼ�����Ϊ1�Ҵ�
       }
    }
   return 0;
}

int final(int n,int k)
{
      vector<int>people;
      int p=-1,p2,i;  //����ӵ�0����ʼ����������pȡ-1
      for(i=0;i<n;i++)
	  {
         people.push_back(i+1);
      }
      while(people.size()>1)
	  {
         p=(p+k)%people.size();//�ҵ���K����,pΪԭ���ı��

         for(i=0,p2=p;i<k;i++)
		 {
           p2=(p2+1)%people.size();//�ٴ���һ����ʼ������p2Ϊԭ���ı�ţ�������k���ˣ��ҵ���һ��ɱ������
           if(p2==p) 
			   i--;  //p�Ѿ���ɾ�������Բ�����
         }
         people[p]=people[p2];  //��p2����p

         people.erase(people.begin()+p2);  //ɾ���ڵ�
         if(p>p2) 
			 p--;  //��ʱ���ĸ�size��1�ˣ����p>p2,ɾ����p2��p��ֵҲҪ��1
      }
      return people[0];
}