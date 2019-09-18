/*第一个只出现一次的字符
    在一个字符串，全部由字母组成中找到第一个只出现一次的字符，并返回它的位置，如果没有则返回-1
*/
#include<iostream>
#include<unordered_map>//无序键值对， 即哈希表
using namespace std;
class Solution {
public:
    int FirstNotRepeatingChar(string str){
        unordered_map<char, int> char_counts;
        int the_once=0;
        for(int i=0;i<str.size();i++){//O(n)
            char_counts[str[i]]++;//更新哈希表中该字符的出现次数            
        }
        while(char_counts[str[the_once]] > 1 && the_once < str.size()){//O(26+26)
            the_once++;
        }
        if(the_once>=str.size()) return -1;
        else return the_once;
    }
};
