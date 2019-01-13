#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool judge(const string &str1, const string &str2);
int main()
{
    string s;
    vector< vector<string> > cards;					//����˫�ص�vector������֮�����ÿ���ƣ�����������˳���������еĲ�������ʵ��Ԫ�صĲ��롢ɾ����Ԫ�������ļ���

    while(cin >> s && s != "#")
    {
        
		vector<string> temp;					//ע��vector������ֱ����cin>>��ʼ��Ԫ��
        temp.push_back(s);
        cards.push_back(temp);

        if(cards.size() == 52)
        {
            while(true)
            {
                
				unsigned int i;

                for(i = 0; i != cards.size(); ++i)
                {
                    if(i >=3 && judge(cards[i].back(),cards[i - 3].back()))			//���ж� ��3 ��λ���Ƿ���������
                    {
                        cards[i - 3].push_back(cards[i].back());
                        cards[i].pop_back();
                        break;
                    }
                    if(i >= 1 && judge(cards[i].back(), cards[i - 1].back()))		//ֻ�е� ��3 ������ʱ�Ż��ж� ��1 �Ƿ���������
                    {
                        cards[i - 1].push_back(cards[i].back());
                        cards[i].pop_back();
                        break;
                    }
                }
                
				if(i == cards.size())				//��ѭ���жϵ����Ҷ˵�λ��ʱ��δ�п����ƶ����ƣ�����������
					break;

                else if(cards[i].empty())
                {
                    cards.erase(cards.begin() + i);		//ɾ��û���Ƶ�λ��
                }
            }

            cout << cards.size() << (cards.size() == 1 ? " pile remaining:" : " piles remaining:");

            for(unsigned int i = 0; i != cards.size(); ++i) 
				cout << ' ' << cards[i].size();
            cout << endl;

            cards.clear();			
        }
    }
    return 0;
}
bool judge(const string &str1, const string &str2)
{
    return str1[0] == str2[0] || str1[1] == str2[1];
}
