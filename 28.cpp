/*数组中出现次数超过一半的数字
数组中有一个数字出现的次数超过数组长度的一半， 请找出这个数字。
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers){//使用哈希表，实际上是可能有漏洞的
        int len = numbers.size();//求数组长
        vector<int> hash(101, 0);//建立哈希表，初始值为0，长度为一个质数；hash[n]代表n这个数出现的次数
        for(int i=0;i<len;i++){
            hash[numbers[i]%101]++;//用numbers[i]%101以缩小其范围，以免哈希表过大；
            if(hash[numbers[i]%101]>len/2) return numbers[i];
        }
        return 0;
    }
};