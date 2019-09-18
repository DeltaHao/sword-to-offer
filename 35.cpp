/*数组中的逆序对
    在数组中的两个数字， 如果前面一个数字大于后面一个数字则这两个数字组成一个逆序对。
    输入一个数组，求出这个数组中逆序对的总数。并将其对1000000007取模的结果输出。

**归并排序
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    long long count = 0;//这里一定要用ll类型， 否则会溢出
    int InversePairs(vector<int> data){
        vector<int> array = data;//建立一个副本以免污染源数组
        mergeSort(array, 0, array.size()-1);
        return count%1000000007;
    }

    void mergeSort(vector<int> &array, int l, int r){//l与r分别是最左边和最右边一位的下标
        int m = (l+r)/2;
        if(l<r){
            mergeSort(array, l, m);
            mergeSort(array, m+1, r);//分成两份分别进行递归
            merge(array, l, r, m);//进行归并
        }
        
    }

    void merge(vector<int> &array, int l, int r, int m){
        vector<int> ret;
        int i=l, j=m+1;
        while(i<=m && j<=r){//将前半段与后半段中的元素逐个进行比较
            if(array[i] <= array[j]) {//将较小的加入备份数组
                ret.push_back(array[i++]);
            }
            else{
                ret.push_back(array[j++]);
                count += (m-i+1);//如果前半段的某个数大于后半段的某个数，则它之后（直到中点）的任何数都和后面的那个数构成逆序对                
            }
        }
        while(i<=m){//如果前半段还没完
            ret.push_back(array[i++]);//直接将其依次加入备份数组
        }
        while(j<=r){
            ret.push_back(array[j++]);
        }
        
        for(int i=l,j=0; i<=r; i++,j++){//用备份数组替换原数组中对应的这一段
            array[i] = ret[j];
        }
    }
};
int main(){
    vector<int> data{1,2,3,4,5,6,7,0};
    Solution s;
    cout <<  s.InversePairs(data);
}