#include <iostream>  
#include <string>  
using namespace std;  

#define N 15  

int main()  
{  
  
    int n,get[N],money[N],num,i,j,k,l;
    string name[N],giver,geter;  
  
	while(cin>>n)
	{
		for(i=0; i<n; i++)  
		{  
			cin>>name[i];  
			get[i]=0;  
			money[i]=0;  
	    }  
  
		for(j=0; j<n; j++)  
		{  
			cin>>giver;  
			for(k=0; k<n; k++)  
			    if(name[k]==giver)  
				    break;  
      
		    cin>>money[k]>>num;  
			for(l=0; l<num; l++)  
			{  
				cin>>geter;  
				for(i=0; i<n; i++)  
					if(name[i]==geter)  
						break;  
  
			    get[i]+=money[k]/num; 
  
		    }  
		    if(num)  
			    money[k]=(money[k]/num)*num;  

	    }  
		for(i=0;i<n;i++)  
			cout<<name[i]<<" "<<get[i]-money[i]<<endl;  
	}

    return 0;  
  
}  