/*数字在排序数组中出现的次数
    二分查找
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data,  int k){
        int first = GetFirstK(data, k, 0, data.size()-1);//获得第一个k的下标
        int last = GetLastK(data, k, 0, data.size()-1);//获得第二个k的下标
        if(first>-1 && last > -1)//如果能找到k
            return (last - first + 1);
        else return 0;//找不到k
    }
    int GetFirstK(vector<int> data, int k, int l, int r){//使用二分查找 复杂度只有O（log n）
        if(l>r) return -1;
        int m = (l+r)/2;
        if(data[m]<k)
            l = m + 1;
        else if(data[m]>k)
            r = m - 1;
        else{
            if(l == m || data[m-1]!=k)//只有当m为区间第一位或m左边的数不为k是才返回
                return m;
            else r = m - 1;
        }
        return GetFirstK(data, k, l, r);
    }
    int GetLastK(vector<int> data, int k, int l, int r){
        if(l>r) return -1;
        int m = (l+r)/2;
        if(data[m]<k)
            l = m + 1;
        else if(data[m]>k)
            r = m - 1;
        else{
            if(r == m || data[m+1] != k)
                return m;
            else l = m + 1;
        }
        return GetLastK(data, k, l, r);
    }
};

int main(){
    Solution s;
    vector<int> data{1,2,3,3,3,3,4,5};
    s.GetNumberOfK(data, 3);
}