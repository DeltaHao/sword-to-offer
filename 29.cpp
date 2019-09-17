/*最小的k个数
    输入n个整数，找出其中最小的k个数。 

 
**  sort：自带的冒泡排序， 头文件是<algorithm>
sort(begin, end, cmp)，其中begin为指向待sort()的数组的第一个元素的指针，end为指向待sort()的数组的最后一个元素的下一个位置的指针
cmp参数为排序准则，这是一个函数， 需要自定义。  如果没有的话，默认以非降序排序。 示例：
bool cmp(int x, int y){//以此为参数的sort函数将以非增序排序
    if(x>y)
        return true;
    else 
        return false;
}

** <set>:set和multiset会根据特定的排序准则，自动将元素进行排序。不同的是后者允许元素重复而前者不允许。
使用搜索二叉树实现
*/

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class Solution{
public:
    vector<int> GetLeastNumbers_1(vector<int> input, int k){//使用内置函数 sort
        vector<int> ret;
        sort(input.begin(), input.end());
        if(k>input.size()) return ret;
        input.resize(k);
        return input;
    }
    vector<int> GetLeastNumbers_2(vector<int> input, int k){//使用<set>中的multiset容器
        if(k>input.size()){
            vector<int> ret;
            return ret;
        }
        multiset<int> mset(input.begin(), input.end());//multiset将自动将元素以搜索二叉树的形式存储
        vector<int> ret(mset.begin(), mset.end());//将排好序的mset赋给ret
        ret.resize(k);//重新调整ret长度，将k位以后截断
        return ret;
    }
};