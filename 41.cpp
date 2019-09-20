/*和为S的连续正数序列
    找出所有和为S的连续正数序列
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> FindContinuousSequence(int sum){
        vector<vector<int>> ret;        
        if(sum<3) return ret;//1和2都没有
        int l = 1, r = 2;//l与r分别表示序列最左边和最右边的数        
        while(r <= sum/2 + 1){//当有数比sum的一半还大1时，不可能
            vector<int> arr;
            int temp = 0;
            for(int i=l; i<=r; i++){
                arr.push_back(i);
                temp+=i;//计算序列和
            }
            if(temp == sum){//等于sum时输出序列
                ret.push_back(arr);
                r++;//最右侧的数后移一位
            }
            else if(temp < sum){//序列和小于sum    
                r++;//左边的数后移一位
            }
            else{//大于sum
                l++;//右边的数后移一位
            }
        }
        return ret;
    }
 };