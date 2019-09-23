/*正则表达式匹配
    请实现一个函数用来匹配包括'.'和'*'的正则表达式。'.'表示任意一个字符， 而'*'表示它前面的字符可出现任意次(包括0次)。

**面对分支选择的情况时， 要使用递归！！
*/
#include<iostream>
#include<cstring>
using namespace std;
class Solution {
public:
    bool match(char* str, char* pattern){
        if(*str == 0 && *pattern == 0) return true;//如果str和pattern都已为空
        if(*str != 0 && *pattern == 0) return false;//如果str未空， pattern已空

        if(*(pattern+1) == '*'){//如果pattern中下一个字符为*
            if((*pattern == '.' && *str != 0) || *pattern == *str){//如果字符匹配。
                return match(str, pattern+2)||match(str+1, pattern);//str中的字符不被抵消  或者  str中的这个字符被抵消掉，继续看下一个字符是否被抵消
            }                                                           /*这里产生了树状平行世界，只要有一条路径匹配成功即可成功*/
            else{//如果字符不匹配
                return match(str, pattern+2);//str中的字符不被抵消
            }
        }
        else{//如果表达式中下一个字符不为*
            if((*pattern == '.' && *str != 0) || *pattern == *str){//如果字符匹配。
                return match(str+1, pattern+1);//继续匹配下一个字符
            }
            else return false;
        }
    }
};
int main(){
    Solution s;
    char a[] = "aaa";
    char b[] = "a*aaaa";
    cout << s.match(a, b);
}