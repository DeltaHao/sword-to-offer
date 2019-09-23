/*把字符串转换为整数
    将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。数值为0或字符串不合法时返回0
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int StrToInt(string  str){
        if(str[0] == '0') return 0;
        int ret = 0;
        int exponent = 0;
        if(str[0]=='+' ){
            for( int i=str.size()-1; i>0; i--){
                if(str[i]>'9' || str[i]<'0') return 0;
                ret += (str[i]-'0') * pow(10, exponent++); 
            }
            return ret;
        }
        else if(str[0]=='-'){
            for( int i=str.size()-1; i>0; i--){
                if(str[i]>'9' || str[i]<'0') return 0;
                ret += (str[i]-'0') * pow(10, exponent++); 
            }
            return -ret;
        }
        else{
            for( int i=str.size()-1; i>=0; i--){
                if(str[i]>'9' || str[i]<'0') return 0;
                ret += (str[i]-'0') * pow(10, exponent++); 
            }
            return ret;
        }        
    }
};