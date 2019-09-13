/*数值的整数次方
    给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
*/
#include<iostream>

using namespace std;
class Solution{
public:
    double Power(double base, int exponent){
        double ret = 1.0;
        if(exponent == 0) ret = 1;
        else if(exponent > 0){
            for(int i=0;i<exponent;i++){
                ret *= base;
            }
        }
        else{
            for(int i=0;i<-exponent;i++){
                ret *= base;
            }
            ret = 1.0/ret;
        }
        return ret;
    }
};