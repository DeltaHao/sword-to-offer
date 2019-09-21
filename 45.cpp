/*扑克牌顺子
    LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张_)…他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,
    如果抽到的话,他决定去买体育彩票,嘿嘿！！“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子…LL不高兴了,他想了想,决定大\小 王可以看成任何数字,
    并且A看作1,J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。LL决定去买体育彩票啦。 现在,要求你使用这幅牌模拟上面的过程,
    然后告诉我们LL的运气如何， 如果牌能组成顺子就输出true，否则就输出false。为了方便起见,你可以认为大小王是0。
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    static bool cmp(int a, int b){
        return a>b;
    }
    bool IsContinuous(vector<int> numbers){
        if(numbers.size()!=5) return false;
        int countOfZero = 0;
        for( auto i:numbers)
            if(!i)
                countOfZero++;//统计大小王的数量        
        sort(numbers.begin(), numbers.end(), cmp);//由大到小排序
        for(int i=0; i<numbers.size()-1; i++){
            if(numbers[i]-1 != numbers[i+1]){//如果这张牌不和下一张牌连续
                if(!countOfZero) return false;//如果没有大小王补位 false
                else{
                    countOfZero--;//减去一张王
                    for(int j=numbers.size()-1;j>i+1;j--){
                        numbers[j] = numbers[j-1];//后面的牌依次后移
                    }
                    numbers[i+1] = numbers[i]-1;//在下一张的位置插上想要的牌
                }
            }
        }
        return true;
    }
};
int main(){
    Solution s;
    vector<int> numbers{1,2,6,4,5};
    cout << s.IsContinuous(numbers);
}