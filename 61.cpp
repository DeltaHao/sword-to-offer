/*序列化二叉树
	请实现两个函数，分别用来序列化和反序列化二叉树
	二叉树的序列化是指：把一颗二叉树按照某种遍历方式的结果以某种格式保存为字符串，从而使得内存中建立起来的二叉树可以持久保存，序列化可以基于先序，中序后序层序的二叉树
遍历方式来进行修改，序列化的结果是一个字符串，序列化时通过某种符号表示空结点（#），以！表示一个结点值的结束(value!)。
	反序列化是指：根据某种遍历顺序得到的序列化字符串str，重构二叉树。

    
*/

#include<iostream>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :
		val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	char* Serialize(TreeNode* root) {
		string str;
		vector<string> vals;
		Preorder(root, vals);//将前序遍历的结果存放在数组里
		for (auto val : vals) {//输出到str
			str += val;
		}       
        //下面我想了俩小时也没想通为啥这么做才能成功返回char*类型
        //我直接把string 用c_str()转成const char*再转成char*返回不行吗
        //char* ret = const_cast<char*>(str.c_str());
        //return ret;

        //都有string了，char*这种东西就该被丢到垃圾桶
        //在这种无意义的，早就被抛弃的东西上浪费了俩小时 他妈的！        
		char *ret = new char[str.length() + 1];
        strcpy(ret,str.c_str());
        return ret;
	}
	void Preorder(TreeNode* root, vector<string>& vals) {//前序遍历 序列化二叉树
		if (!root) {//如果为空指针
			vals.push_back("#");//向数组中加入#
			return;
		}
		string tmp = to_string(root->val);
		tmp += "!";
		vals.push_back(tmp);//向数组中加入数字和！
		Preorder(root->left, vals);
		Preorder(root->right, vals);
	}
	TreeNode* Deserialize(char* str) {
		string tmp;
		TreeNode* ret = nullptr;
		vector <int> vals;//将字符串转化为数字数组进行保存
		for (int i = 0; i < strlen(str); ++i) {//遍历字符串
			if (str[i] == '#') {//如果为空指针
				vals.push_back(-1);//用-1替代
				continue;//看下一个字符
			}
			if (str[i] != '!') {//如果一个数字没有结束
				tmp += str[i];//加入临时字符串，看下一个字符
			}
			else {//如果数字结束
				int val = atoi(tmp.c_str());//将临时字符串转化为数字
				tmp = "";//清空之
				vals.push_back(val);//加入数字数组
			}
		}
		int i = 0;
		ret = Preorder(vals, i);//用前序遍历构造数组
		return ret;
	}
	TreeNode* Preorder(vector<int> vals, int& i) {

		TreeNode* node = nullptr;
		if (vals[i] != -1)//如果对应的数字数组不是-1
			node = new TreeNode(vals[i]);//构建一个新节点
		else //若是，返回
			return node;
		node->left = Preorder(vals, ++i);//继续构建左节点
		node->right = Preorder(vals, ++i);//继续构建右节点
		return node;
	}
};

int main() {
	Solution s;
	char str[] = "1!2!##3!#4!5!###";
	TreeNode* root;
	root = s.Deserialize(str);
	cout << s.Serialize(root);
	return 0;
}