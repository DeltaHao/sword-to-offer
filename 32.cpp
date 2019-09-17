/*把数组排成最小的数
    输入一个正整数数组， 把数组中所有数字拼接起来排成一个数， 打印能拼接出的所有数字中最小的一个
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

#define max(a, b) a>b?a:b
class Solution {
public:
    string PrintMinNumber(vector<int> numbers){        
        string ret = "";
        sort(numbers.begin(), numbers.end(), cmp);
        for(int i=0;i<numbers.size();i++){
            ret += to_string(numbers[i]);//这里要注意numbers仍然是整形数组， 要转化为字符串才能加
        }
        return ret;
    }
    static bool cmp(int int_a, int int_b){//比较规则: a和b两个数化为字符串后， 谁放在前面使总字符串最小， 谁就应该排在前面
       string a = to_string(int_a);
       string b = to_string(int_b);
       string ab = a + b;       
       string ba = b + a; 
       return ab < ba;
    }
};

int main(){
    vector<int> numbers{313, 33};
    Solution s;
    string ret = s.PrintMinNumber(numbers);

}