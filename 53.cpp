/*表示数值的字符串
    请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。


** E/e将字符串分为两个部分 前半部分底数是一个实数，后半部分指数是一个整数
** 空字符串不合法
** 第一位是+ -合法 
** 出现多个.不合法 .出现在第一位或最后一位也不合法
*/

#include<iostream>
#include<cstring>
using namespace std;

class Solution {
public:
    bool isNumeric(char* string){       
        if(*string == 0) return false;       
        int countOfE = 0;
        char *string2;
        for(int i=0; i<strlen(string); i++){            
            if(string[i] == 'e' || string[i] == 'E'){//检查是不是科学计数,若是，记录E的位置,并将string分为底数和指数
                countOfE++;
                string[i] = 0;
                string2 = &string[i+1];
            }           
        }
        if(countOfE>1) return false;//若有多个e，不合法
        else if(countOfE == 1){//是科学计数
            return (isIntegerOrRealNumeric(string, 1) && isIntegerOrRealNumeric(string2, 0));
        }
        else{//不是科学计数
            return isIntegerOrRealNumeric(string, 1);//判断是不是实数
        }
    }
    bool isIntegerOrRealNumeric(char* string, int argu){//判断是不是整数/实数    argu为1时判断实数，为0时判断整数                 
        if(*string == 0) return false;
        int len = strlen(string);
        if(string[0] == '.' || string[len-1] == '.') return false;
        int countOfdot = 0;
        for(int i=0; i<len; i++){                        
            if(string[i] == '.') countOfdot++;//检查小数点的数量           
        }
        if(countOfdot > argu) return false;
        for(int i=0; i<len; i++){
            if(!i && (string[i] == '-' || string[i] == '+')) continue;//如果第一位是+或-，合法， 跳过   
            if(string[i] == '.') continue;//跳过小数点（如果有）
            if(string[i] > '9' || string[i] < '0') return false;//检查是不是数字
        }
        return true;
    }
};

int main(){
    Solution s;
    char string[] = "-1.2e+-54";
    cout << s.isNumeric(string);
}