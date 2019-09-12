/*二维数组中的查找
    在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序， 每一列都按照从上到下递增的顺序排序。
    请完成一个函数，输入这样的一个二维数组和一个整数， 判断数组中是否含有该整数。
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    bool Find(vector<vector<int>> array, int target){
        int i = 0, j = array.size()-1;//初始由右上角开始查询，行号为0， 列号为数组的宽-1
        while(i<array[0].size()-1 || j>=0){
            if(array[i][j] > target){//如果比目标大，这一列都比目标大，删除这一列
                j--;
            }
            else if(array[i][j] < target){//如果比目标小，这一行都比目标小，删除这一行
                i++;
            }
            else{//如果相等， 返回是
                return true;
            }
        }
        return false;
    }   
};
