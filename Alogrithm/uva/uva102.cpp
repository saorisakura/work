#include <iostream>  
#include <algorithm>  
#include <cstdio>  //����
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
    while(cin >> data[0] && data[0] != EOF) //����һ����Ϊ������ʱ��ʼ��ȡ 
    {  
        for(int i=1; i<9; i++)  
            cin >> data[i];  //��ȡ���� 
        for(int i=0; i<3; i++) 
            sum[i] = 0;      //����
        for(int i=0; i<3; i++)   //˫ѭ��
            for(int j=0; j<3; j++) 
                sum[i]+=data[i+j*3]; //��������������һ����ɫƿ�ӵ�������sum[0]='B',sum[1]='G',sum[2]='C'

        max = sum[0] + sum[1] + sum[2]; //�����ܵ�ƿ���� 
        do  // do while ���
        {  
            move = 0;  //����ֵ
            for(int i=0; i<3; i++) 
            {  
                if(perm[i] == 0) // 'B'  // perm[] = {0, 1, 2}��data:�ء��̺���ɫƿ�ӵ��������Ƕ���
                    move = move + sum[0] - data[i*3];  //��1,2�е�B�Ƶ�0������Ĵ���
                else if(perm[i] == 1) // 'C'  
                    move = move + sum[2] - data[i*3+2]; // ��0,2�е�C�Ƶ�1������Ĵ���
                else if(perm[i] == 2) // 'G'  
                    move = move + sum[1] - data[i*3+1]; //��0,1�е�G�Ƶ�2������Ĵ��� 
            }  
            if(move < max)  //move�ۼӱ������յ��ƶ��������˴��ж�
            {  
                max = move;//max������֮��������õ�move�Ƚ�  
                for(int i=0; i<3; i++)  
                    index[i] = perm[i];//��������������ɫ����˳������ݸ�ֵ��index  
            }  
        } while(next_permutation(perm, perm+3));  //ʵ�ֲ�ͬ��ɫ������Ŀ��ǣ���������ĸ���˳�������һ���ַ�����С��һ��
        for(int i=0; i<3; i++) //����ַ� 
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