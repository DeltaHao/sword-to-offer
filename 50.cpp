/*数组中重复的数字
    在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。
    请找出数组中任意一个重复的数字。

**set容器的insert函数：
insert(key_value); 将key_value插入到set中 ，返回值是pair<set<int>::iterator,bool>，
bool标志着插入是否成功，而iterator代表插入的位置，若key_value已经在set中，则iterator表示的key_value在set中的位置。
*/
#include<iostream>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool duplicate(int numbers[], int length, int *duplication){
        unordered_set<int> set;
        for(int i=0; i<length; i++){
            if(numbers[i]<0 || numbers[i]>length-1) return false;
            if(!(set.insert(numbers[i])).second){//如果插入不成功
                *duplication = numbers[i];
                return true;
            }
        }
        return false;
    }
};