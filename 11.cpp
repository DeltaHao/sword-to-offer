/*二进制中1的个数
    输入一个整数， 输出该二进制表示中1的个数，其中负数用补码表示。
*/
#include<iostream>

using namespace std;
class Solution {
public:

    int NumberOf1_1(int n){//逐位取出来判断
        int len = sizeof(int)*8;
        int count;
        for(int i=0;i<len;i++){
            if(((n>>i) & 1) == 1){
                count++;
            }
        }
        return count;
    }

    int NumberOf1_2(int n){
        int count=0;
        while(n)
        {
            n=n&(n-1);//每执行一次这样的操作，相当于把最右边的一个1置0
            count++;//1的个数增加
        }//当所有1都被置0后，程序结束
        return count;
    }
};
