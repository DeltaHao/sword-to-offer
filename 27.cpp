/*字符串的排列
    输入一个字符串， 按字典序打印出该字符串中字符的所有排列。
    输入一个字符串， 长度不超过9（可重复）只包括大小写字母
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    char arr[100] = {0};
    bool vis[100] = {0};
    vector<string> Permutation(string str){
        vector<string> ret;        
        int len = str.length();
        if(!len) return ret;
        sort(str);//将字符串按字典序排序
        dfs(ret, str, 0, len);//深度搜索求全排列
        return ret;
    }
    void dfs(vector<string> &ret, string &str, int i, int n){
        //为第i步寻找元素
        if(i == n){//深度搜索完成
            ret.push_back(arr);//输出路径
        }
        else{
            char last = -1;//最近被选择的元素
            for(int j=0;j<n;j++){//遍历所有元素
                if(!vis[j] && str[j]!=last){//如果这个元素没有被选择过且与上一次选择的不同
                    arr[i] = str[j];//选择它
                    last = str[j];//更新最近被选择的元素
                    vis[j] = true;//标记之
                    dfs(ret, str, i+1, n);//进行下一步深搜
                    vis[j] = false;//深搜完成后回溯
                }
            }
        }
    }
    void sort(string &str){//冒泡排序
        int len = str.length();
        for(int i=0;i<len-1;i++){
            for(int j=0;j<len - i - 1;j++){
                if(str[j]>str[j+1])
                    swap(str[j], str[j+1]);
            }
        }
    }
};
int main(){
    string str = "aab";
    Solution s;
    vector<string> v = s.Permutation(str);
    for(int i=0;i<v.size();i++)
        cout << v[i] << endl;
}