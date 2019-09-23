/*构建乘积数组
    给定一个数组A[0,1,2,...,n-1]，请构建一个数组B[0,1,2,...,n-1]，其中B中的元素B[i] = A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1] 不能使用除法
*/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> multiply(const  vector<int> &A){
        int len = A.size();
        vector<int> front(len), back(len), B(len);//front[i] 保存A[0]*A[1]*...*A[i]， back[i]保存A[i]*...*A[n-1]

        int product = 1;
        for(int i=0; i<len; i++){//构建front
            product *= A[i];
            front[i] = product;
        }
        product = 1;
        for(int i=len-1; i>=0; i--){//构建back
            product *= A[i];
            back[i] = product;
        }
        B[0] = back[1];
        for(int i=1; i<len-1; i++){//计算B
            B[i] = front[i-1] * back[i+1];
        }
        B[len-1] = front[len-2];
        return B;
    }
};
int main(){
    vector<int> A{1,2,3,4,5};
    Solution s;
    s.multiply(A);
}