/*数据流中的中位数
    如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
    如果从数据流之中读出偶数个数值，那么中位数就是所有值排序之后中间两个数的平均值。我们使用insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
*/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution{
public:
    multiset<int> set;
    void Insert(int num){
        set.insert(num);//利用set可以实现自动排序
    }
    double GetMedian(){
        int size = set.size();
        multiset<int>::iterator it = set.begin();
        if(size%2){//奇数
            for(int i=0; i<size/2; i++)//找到中位数
                ++it;
            return *it;                
        }
        else{//偶数
            for(int i=0; i<size/2; i++)//找到中间靠后的那个数
                ++it;
            return ((double)*it + *(--it)) / 2;//返回它和它之前的数的平均值
        }
    }
};

int main(){
    Solution s;
    int a[9] = {5,2,3,4,1,6,7,0,8};
    for(int i=0; i<9; i++){
        s.Insert(a[i]);
        cout << s.GetMedian()<<" ";
    }
}