/*旋转数组的最小数字
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。

最有效率的方法：O(1)~O(n/2)
    旋转数组分为左区和右区，左区  右区都是非递减，可从中间数开始找临界点，右侧临界点即为最小元素 

**注意： 判断是否在右区时要和左侧元素比较大小，否则右临界点也会被归类到右区中
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray){
        int i = rotateArray.size() / 2;
        while(i>0 & i<rotateArray.size()){
            if(rotateArray[i] > rotateArray[rotateArray.size()-1] && rotateArray[i] <= rotateArray[i+1]){//在左区内
                i++;//右移
            }
            else if(rotateArray[i] < rotateArray[0] && rotateArray[i] >= rotateArray[i-1]){//在右区内
                i--;//左移
            }
            else {
                if(rotateArray[i]>rotateArray[i+1]) return rotateArray[i+1];//若是左侧临界点
                else return rotateArray[i];//若是右侧临界点
            }
        }        
    }
};