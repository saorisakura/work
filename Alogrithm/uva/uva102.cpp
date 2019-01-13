#include <iostream>  
#include <algorithm>  
#include <cstdio>  //定义
using namespace std;  
int main()  
{  
    int perm[] = {0, 1, 2};  
    int index[] = {0, 1, 2};  
    int data[9];  
    int sum[3];  
    int move;  
    int max;  
//    freopen("102.txt", "r", stdin);  
    while(cin >> data[0] && data[0] != EOF) //当第一个不为空数据时开始读取 
    {  
        for(int i=1; i<9; i++)  
            cin >> data[i];  //读取数据 
        for(int i=0; i<3; i++) 
            sum[i] = 0;      //清零
        for(int i=0; i<3; i++)   //双循环
            for(int j=0; j<3; j++) 
                sum[i]+=data[i+j*3]; //计算三个箱子里一种颜色瓶子的总数：sum[0]='B',sum[1]='G',sum[2]='C'

        max = sum[0] + sum[1] + sum[2]; //计算总的瓶子数 
        do  // do while 语句
        {  
            move = 0;  //赋初值
            for(int i=0; i<3; i++) 
            {  
                if(perm[i] == 0) // 'B'  // perm[] = {0, 1, 2}，data:棕、绿和无色瓶子的数量各是多少
                    move = move + sum[0] - data[i*3];  //将1,2中的B移到0中所需的次数
                else if(perm[i] == 1) // 'C'  
                    move = move + sum[2] - data[i*3+2]; // 将0,2中的C移到1中所需的次数
                else if(perm[i] == 2) // 'G'  
                    move = move + sum[1] - data[i*3+1]; //将0,1中的G移到2中所需的次数 
            }  
            if(move < max)  //move累加保存最终的移动次数，此处判断
            {  
                max = move;//max用来与之后计算所得的move比较  
                for(int i=0; i<3; i++)  
                    index[i] = perm[i];//将保存有箱子颜色排列顺序的数据赋值给index  
            }  
        } while(next_permutation(perm, perm+3));  //实现不同颜色的情况的考虑，并按照字母表的顺序输入第一个字符串最小的一种
        for(int i=0; i<3; i++) //输出字符 
        {  
            if(index[i] == 0)  
                putchar('B');  
            else if(index[i] == 1)  
                putchar('C');  
            else  
                putchar('G');  
        }  
        cout << ' ' << max << endl;  
    }  
    return 0;  
}  