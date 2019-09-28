/*矩阵中的路径
	请设计一个函数， 用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以由矩阵中任何一个格子开始，每一步可以向上、下、左右移动一个格子。如果
一条路径经过了矩阵中某一个格子，则之后不能再次进入。
*/

#include <iostream>

using namespace std;

class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str) {
		int* vis = new int[rows * cols];//标记数组， 1表示已经走过， 0表示没走过
		for (int i = 0; i < rows * cols; i++) vis[i] = 0;

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {//依次遍历maxrix
				if (DFS(matrix, i, j, rows, cols, str, vis)) {
					return true;
				}
			}
		}
		return false;
	}
	bool DFS(char*& matrix, int i, int j, int& rows, int& cols, char* str, int*& vis) {
		if (*str == 0) return true;//若字符串全部匹配， 返回真
		if (i < 0 || j < 0 || i >= rows || j >= cols) return false;//如果越界，返回假
		if (vis[i * cols + j]) return false;//如果已经走过这个阶段， 返回假
		else {
			if (matrix[i * cols + j] == *str) {//如果匹配上
				vis[i * cols + j] = 1;//这个格子已经走过
				if (DFS(matrix, i + 1, j, rows, cols, str + 1, vis)) return true;//继续试探下方的格子
				if (DFS(matrix, i - 1, j, rows, cols, str + 1, vis)) return true;//若不成功，试探上面的格子 
				if (DFS(matrix, i, j + 1, rows, cols, str + 1, vis)) return true;//若不成功，试探右面的格子
				if (DFS(matrix, i, j - 1, rows, cols, str + 1, vis)) return true;//若不成功，试探左面的格子
				vis[i * cols + j] = 0;//若都不成功， 说明这个格子走不成
				return false;//回溯
			}
			else return false;//若匹配不上， 直接回溯
		}
	}
};

int main() {
	Solution s;
	s.hasPath("ABCESFCSADEE", 3, 4, "ABCCED");
}