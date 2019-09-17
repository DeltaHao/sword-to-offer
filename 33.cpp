/*丑数
    把只包含质因子2、3、5的数称作丑数。1是第一个丑数
    求第n个

**每个丑数都可以由前面的某个丑数*2或3或5得到，只需要将它们按照顺序列出来即可
*/
#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int min(int x, int y, int z){
        if(x<y)
            return x<z?x:z;
        else
            return y<z?y:z;
    }
    int GetUglyNumber_Solution(int index){
        vector<int>uglys(index+1); 
        uglys[1] = 1;//第一个丑数是1
        int pos2 = 1, pos3 = 1, pos5 = 1;//这三个下标指向的丑数将分别与2、3、5相乘
        for(int i=2; i<=index; i++){
            uglys[i] = min(uglys[pos2]*2, uglys[pos3]*3, uglys[pos5]*5);//取与之前丑数乘得的最小丑数加入数组
            if(uglys[pos2]*2 == uglys[i]) pos2++;
            if(uglys[pos3]*3 == uglys[i]) pos3++;
            if(uglys[pos5]*5 == uglys[i]) pos5++;//如果某一个下标乘出来的丑数已经被加入，将它向前移一位
        }
        return uglys[index];
    }
    
};
int main(){
    Solution s;
    for(int i=1; i<20; i++)
        cout <<  s.GetUglyNumber_Solution(i) << endl;
   
}