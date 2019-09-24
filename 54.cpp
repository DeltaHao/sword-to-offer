/*字符流中第一个不重复的字符
    请实现一个函数用来找出字符流中第一个只出现一次的字符。
*/

#include<iostream>

using namespace std;

class Solution{
public:
    string s;
    char hash[256]{0};
    void Insert(char ch){
        s += ch;
        ++hash[ch];
    }
    char FirstAppearingOnce(){
        for(int i=0; i<s.size(); i++){
            if(hash[s[i]] == 1) return s[i];
        }
        return '#';
    }
};
