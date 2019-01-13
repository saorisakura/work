#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool judge(const string &str1, const string &str2);
int main()
{
    string s;
    vector< vector<string> > cards;					//利用双重的vector，便于之后管理每堆牌，还可以利用顺序容器特有的操作简便的实现元素的插入、删除和元素数量的计算

    while(cin >> s && s != "#")
    {
        
		vector<string> temp;					//注意vector不可以直接用cin>>初始化元素
        temp.push_back(s);
        cards.push_back(temp);

        if(cards.size() == 52)
        {
            while(true)
            {
                
				unsigned int i;

                for(i = 0; i != cards.size(); ++i)
                {
                    if(i >=3 && judge(cards[i].back(),cards[i - 3].back()))			//先判断 左3 的位置是否满足条件
                    {
                        cards[i - 3].push_back(cards[i].back());
                        cards[i].pop_back();
                        break;
                    }
                    if(i >= 1 && judge(cards[i].back(), cards[i - 1].back()))		//只有当 左3 不满足时才会判断 左1 是否满足条件
                    {
                        cards[i - 1].push_back(cards[i].back());
                        cards[i].pop_back();
                        break;
                    }
                }
                
				if(i == cards.size())				//当循环判断到最右端的位置时还未有可以移动的牌，则可以输出了
					break;

                else if(cards[i].empty())
                {
                    cards.erase(cards.begin() + i);		//删除没有牌的位置
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
