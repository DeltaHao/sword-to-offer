/*调整数组顺序使奇数位于偶数前面
    输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分， 所有的偶数位于数组的后半部分 ， 
    并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    void reOrderArray(vector<int> array){
        vector<int> odd;
        vector<int> even; 
        for(int i=0;i<array.size();i++){
            if(array[i]%2){
                odd.push_back(array[i]);
            }
            else{
                even.push_back(array[i]);
            }
        }
        for(int i=0;i<odd.size();i++){
            array[i] = odd[i];
        }
        for(int i=0;i<even.size();i++){
            array[i+odd.size()] = even[i];
        }
    }
};