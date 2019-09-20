/*和为s的两个数字
    输入一个递增排序的数组和一个数字S，在数组中查找两个数， 使得他们的和正好是S, 若有多对数字的和等于S，输出两个数乘积最小的。
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum){
        vector<int> ret;
        int i = 0, j = array.size()-1;//分别指向头和尾
        while(i<j){
            if(array[i]+array[j] == sum){//相等时，根据数学原理知，递增序列中和相同的两个数越分散积越大，所以找到的第一个就可以直接输出
                    ret.push_back(array[i]);
                    ret.push_back(array[j]);
                    return ret;
                }
                else if(array[i]+array[j] < sum){//如果小于sum
                    i++;
                }
                else{
                    j--;
                }
        }        
        return ret;        
    }
};
