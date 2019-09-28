/*滑动窗口的最大值
    给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，
    他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
    {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int max1(int l, int r, const vector<int> &num){
        int ret = num[l];
        for(int i=l; i<r; i++){
            if(num[i]>ret) ret = num[i];
        }
        return ret;
    }
    vector<int> maxInWindows(const vector<int> &num, unsigned int size){
        vector<int> ret;
        if(!size) return ret;
        int l = 0;
        int r = size;
        for(int i=0; i<num.size()-size+1; i++){
            ret.push_back(max1(l++, r++, num));
        }
        return ret;
    }
};

int main(){
    Solution s;
    vector<int> num = {2,3,4,2,6,2,5,1};
    vector <int> ret = s.maxInWindows(num, 3);
    for (auto i: ret)
    {
        cout << i << " ";
    }
    
}