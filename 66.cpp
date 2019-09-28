/*机器人的运动范围
    地上有个m行和n列的方格。一个机器人从坐标0，0的格子开始移动， 每一次只能向左、右、上、下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子
请问该机器人能达到几个格子？
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    bool isGreater(int i, int j, int threshold){//用于比较thershold和i，j的数位和
        int count = 0;
        while(i>9){
            count += i%10;
            i /= 10;
        }
        while(j>9){
            count += j%10;
            j /= 10;
        }
        count += i+j;
        return (count > threshold);
    } 
    int movingCount(int threshold, int rows, int cols){
        int *vis = new int[rows*cols];//标记数组， 1表示已经走过， 0表示没走过
        for (int i = 0; i < rows * cols; i++) vis[i] = 0;

        int ret = DFS(0, 0, rows, cols, threshold, vis);
        return ret;
    }
    int DFS(int i, int j, int rows, int cols, int threshold, int* &vis){
        if(i<0 || j<0 || i>=rows || j>=cols) return 0;//如果越界，不算
        if(isGreater(i, j, threshold)) return 0;//数位和大于threshold，不算
        if(vis[i*cols+j]) return 0;//已经走过， 不算
        vis[i*cols+j] = 1;//将标记数组中的这一位置1
        return (1+
            DFS(i+1, j, rows, cols, threshold, vis)+
            DFS(i-1, j, rows, cols, threshold, vis)+
            DFS(i, j+1, rows, cols, threshold, vis)+
            DFS(i, j-1, rows, cols, threshold, vis));    
    }
};

int main(){
    Solution s;
    cout << s.movingCount(15, 20, 20);
}