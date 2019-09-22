/*不用加减乘除做加法
    写一个函数，求两个整数之和， 要求在函数体内不能使用+，-，*， /四则运算符号
*/
#include<iostream>
using namespace std;

class Solution {
public:
    int add(int num1, int num2){
        int carry = 1;//进位值
        int sum = 0;//不考虑进位的各位相加值
        while(carry){//当有进位时
            sum = num1 ^ num2;//不考虑进位的各位相加值等于各位异或
            carry = (num1 & num2) << 1;//进位值等于各位与后左移一位
            num1 = sum;//如果有进位时将两值相加，重复以上两步
            num2 = carry;
        }
        return sum;
    }
};

int main(){
    Solution s;
    cout << s.add(5, 7);
}