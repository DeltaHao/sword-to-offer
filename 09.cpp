/*变态跳台阶
    一只青蛙一次可以跳上1阶台阶， 也可以跳上2阶，……也可跳上n阶。求该青蛙跳上n级台阶有几种跳法

**数学题，归纳找规律
*/
#include<iostream>

using namespace std;
class Solution {
public:
    int jumpFloorII(int number){
        return pow(2, number-1);
    }
};