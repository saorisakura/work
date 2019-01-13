#include <iostream>
#include <cstdio>

using namespace std;

int cs[1500];
int pcs =0;
int main()
{
    cs[pcs++]=1;
    int *p2 = cs;
    int *p3 = cs;
    int *p5 = cs;
    while(pcs<1500)
    {
        int mnum = min((*p2)*2,(*p3)*3);
        mnum=min(mnum,(*p5)*5);
        cs[pcs++]=mnum;
        while((*p2)*2<=cs[pcs-1])
            p2++;
        while((*p3)*3<=cs[pcs-1])
            p3++;
        while((*p5)*5<=cs[pcs-1])
            p5++;
    }
    cout<<"The 1500'th ugly number is "<<cs[1499]<<"."<<endl;
    return 0;
}