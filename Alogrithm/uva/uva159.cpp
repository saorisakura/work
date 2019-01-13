#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int min(int a,int b)
{
	return a<b ? a:b;
}
int main()								//格式化输出
{
	char str1[11],str2[11],str3[11],str4[11];
	bool flag=false;
	while(scanf("%s",str1))
	{
		if(str1[0]=='#')
			break;
		scanf("%s %s %s",str2,str3,str4);
		int len1,len2,len3,len4,pnum1,pnum2;
		int pair1_h,pair1_v,pair2_h,pair2_v;
		bool flag1=false,flag2=false;
		
		
		len1=strlen(str1);
		len2=strlen(str2);//SDKJANFU TUDNNKU DSVJDN TUVDSJK
		len3=strlen(str3);
		len4=strlen(str4);
		for(int i=0;i!=len1;++i)
			for(int j=0;j!=len2;++j)
				if(str1[i]==str2[j])
				{
					pair1_h=i+1,pair1_v=j+1;
					flag1=true;
					goto loop1;
				}
loop1:
		if(!flag1)
		{
			if(flag)
				cout<<endl;
			cout<<"Unable to make two crosses"<<endl;
			continue;
		}
		for(int i=0;i!=len3;++i)
			for(int j=0;j!=len4;++j)
				if(str3[i]==str4[j])
				{
					pair2_h=i+1,pair2_v=j+1;
					flag2=true;
					goto loop2;
				}
loop2:
		if(!flag2)
		{
			if(flag)
				cout<<endl;
			cout<<"Unable to make two crosses"<<endl;
			continue;
		}
		if(flag)
			cout<<endl;
		pnum1=0,pnum2=0;
		
		if((pair1_v-pair2_v)>0)
		{
			for(int i=1;i<=(pair1_v-pair2_v);++i)
			{
				for(int j=1;j<=(pair1_h-1);++j)
					cout<<" ";
				cout<<str2[pnum1]<<endl;
				++pnum1;
			}
		}
		else if((pair1_v-pair2_v)<0)
		{
			for(int i=1;i<=(pair2_v-pair1_v);++i)
			{
				for(int j=1;j<=(len1+pair2_h+2);++j)
					cout<<" ";
				cout<<str4[pnum2]<<endl;
				++pnum2;
			}
		}
		for(int i=1;i<=(min(pair2_v-1,pair1_v-1));++i)
		{
			for(int j=1;j<=(pair1_h-1);++j)
				cout<<" ";
			cout<<str2[pnum1];
			++pnum1;
			for(int k=1;k<=(len1-pair1_h+pair2_h+2);++k)
				cout<<" ";
			cout<<str4[pnum2]<<endl;
			++pnum2;
		}

		cout<<str1<<"   "<<str3<<endl;

		++pnum2,++pnum1;
		
		
		for(int i=1;i<=min(len2-pair1_v,len4-pair2_v);++i)
		{
			for(int j=1;j<=(pair1_h-1);++j)
				cout<<" ";
			cout<<str2[pnum1];
			++pnum1;
			for(int k=1;k<=(len1-pair1_h+pair2_h+2);++k)
				cout<<" ";
			cout<<str4[pnum2]<<endl;
			++pnum2;
		}
		if((len2-pair1_v)<(len4-pair2_v))
		{
			for(int i=1;i<=((len4-pair2_v)-(len2-pair1_v));++i)
			{
				for(int j=1;j<=(len1+pair2_h+2);++j)
					cout<<" ";
				cout<<str4[pnum2]<<endl;
				++pnum2;
			}
		}
		else if((len2-pair1_v)>(len4-pair2_v))
		{
			for(int i=1;i<=((len2-pair1_v)-(len4-pair2_v));++i)
			{
				for(int j=1;j<=(pair1_h-1);++j)
					cout<<" ";
				cout<<str2[pnum1]<<endl;
				++pnum1;
			}
		}
		
		flag=true;

	}

	return 0;
}