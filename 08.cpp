/*跳台阶
    一只青蛙一次可以跳上1级台阶， 也可以跳上两级。求该青蛙跳上一个n级的台阶总共有多少中跳法
*/
#include<iostream>
using namespace std;
class Solution {
public:
    int jumpFloor (int number){
        if (number <= 2) return number;
        
        else return jumpFloor(number-1) + jumpFloor(number-2);
    }
};
