//uva151
#include <cstdio>  
  
int n;  
  
int Josephus(int m);  //Լɪ�����⣬�й̶��Ĺ�ʽȷ���رյ����ı��
  
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
    return t;  //�������һ�������任ǰ��λ�ñ��
}  