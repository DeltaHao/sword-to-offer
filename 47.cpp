/*求1+2+3+...+n
    要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句
*/
//使用递归，利用 && 的短路特性！
#include<iostream>

using namespace std;

class Solution {
public:
    int Sum_solution(int n){
        int ans = n;
        ans && (ans += Sum_solution(n-1));//如果ans==0，这段语句就不会被执行！
        return ans;
    }
};