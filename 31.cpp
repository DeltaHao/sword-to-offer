/*从1到n中1出现的次数
*/
#include<iostream>
using namespace std;

class Solution {
public:
    int NumberOf1Between1AndN(int n){
        int count = 0 ;
        for(int i=1;i<=n;i++){
            int temp = i;
            while(temp>9){
                if(temp%10 == 1) count++;
                temp /= 10; 
            }
            if(temp==1) count++;
        }
        return count; 
    }
};