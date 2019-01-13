//uva151
#include <cstdio>  
  
int n;  
  
int Josephus(int m);  //约瑟夫环问题，有固定的公式确定关闭地区的编号
  
int main()  
{  
    while (scanf("%d", &n), n)  
    {  
        int i, r;  
        for (i = 1; (r = Josephus(i)) != 11; ++i);  
        printf("%d\n", i);  
    }  
    return 0;  
}  
  
int Josephus(int m)  
{  
    int i, t = 0;  
    for (i = 2; i < n; ++i)  
        t = (t + m) % i;  
    return t;  //返回最后一个地区变换前的位置编号
}  