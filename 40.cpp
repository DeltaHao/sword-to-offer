/*数组中只出现一次的数字
    一个整型数组里除了两个数字之外，其他的数字都出现了偶数次。请找出这两个只出现一次的数字
*/
#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution{
public:
    void FindNumsAppearOnce(vector<int> data, int* num1, int* num2){
        map<int, int> hash;
        for(auto item: data){//遍历data ，用哈希表记录每一个数字的出现次数
            hash[item]++;
        }
        bool flag = 1;
        for(auto item: hash){//遍历哈希表， 找出次数为1的两个数字
            if(item.second == 1){
                if(flag){
                    *num1 = item.first;
                    flag = 0;
                }
                else{
                    *num2 = item.first;
                }
            }                               
        }
    }
};