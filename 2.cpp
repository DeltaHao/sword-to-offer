/*替换空格
    实现一个函数，将一个字符串中的每个空格替换成“%20”。
*/
#include<iostream>
using namespace std;

class Solution{
public:
    void replaceSpace(char *str, int length){
        char dest[1024];
        int count = 0;
        for(int i=0;i<length;i++){//遍历原字符串
            if(str[i] == ' '){//若为空格将“%20”加入新字符串
                dest[count++] = '%';
                dest[count++] = '2';
                dest[count++] = '0';
            }
            else{//不为空格原样不动
                dest[count++] = str[i];
            }
        }
        dest[count++] = 0;//结束新字符串
        length = count;//更新字符串的长度
        for(int i=0;i<length;i++){//将新字符串赋给原字符串
            str[i] = dest[i];
        }
    }
};

int main(){
    Solution s;
    char str[] = "hello world !!";
    s.replaceSpace(str, 13);
    cout << str << endl;
}