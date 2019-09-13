/*斐波那契数列
    要求输入一个整数n，请输出斐波那契数列的第n项

**本题用递归会超时， 所以应该使用循环
*/
#include<iostream>

using namespace std;
class Solution {
public:
    int Fibonacci(int n){
        if (n <= 1) return n;
        int n1 = 0, n2 = 1;
        for(int i=2;i<=n;i++){
            int temp = n2;
            n2 = n1 + n2;
            n1 = temp;
        }
        return n2;
    }
};
int main(){
    Solution s;
    cout << s.Fibonacci(39);
}