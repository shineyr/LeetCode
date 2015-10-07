#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <stack>
using namespace std;

//class Solution {
//public:
//	bool Search(vector<vector<char> > &board, int &x, int &y, string &word, vector<vector<int> > &isVisited)
//	{
//		if (word.empty())
//			return true;
//
//		//当前字符有4个查找方向上、下、左、右
//		vector<vector<int> > Direction = { { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 } };
//	
//		for (size_t i = 0; i < Direction.size(); ++i)
//		{
//			//要查找的下一个字符
//			int xx = x + Direction[i][0];
//			int yy = y + Direction[i][1];
//			if (xx >= 0 && yy >= 0 && xx < board.size() && yy < board[xx].size() && isVisited[xx][yy] == 0 && board[xx][yy] == word[0])
//			{
//				isVisited[xx][yy] = 1;
//				if (word.length() == 1 || Search(board, xx, yy, word.substr(1), isVisited))
//					return true;
//				isVisited[xx][yy] = 0;
//			}//if
//		}//for
//		return false;
//	}
//
//	bool exist(vector<vector<char>>& board, string word) {
//		if (board.empty() || board[0].empty())
//			return false;
//
//		if (word.empty())
//			return true;
//
//		int m = board.size();
//		int n = board[0].size();
//
//		vector<vector<int> > isVisited(m, vector<int>(n, 0));
//
//		for (int i = 0; i < m; ++i)
//		{
//			for (int j = 0; j < n; ++j)
//			{
//				if (!word.empty() && board[i][j] == word[0])
//				{
//					//修改访问标志为1 代表已访问
//					isVisited[i][j] = 1;
//					if (word.length() == 1 || Search(board, i, j, word.substr(1), isVisited))
//						return true;
//					//若没有找到目标串，则从下一个字符重新查找，将当前字符访问标志改为0
//					isVisited[i][j] = 0;
//				}
//			}//for
//		}//for
//		return false;
//	}	
//};

struct Node
{
	char c;
	int x;
	int y;
	int p;    //next trial is 0-up, 1-down, 2-left, 3-right
	Node(char newc, int newx, int newy, int newp) : c(newc), x(newx), y(newy), p(newp) {}
};

class Solution {
public:
	bool exist(vector<vector<char> > &board, string word) {
		if (board.empty() || board[0].empty())
			return false;
		int m = board.size();
		int n = board[0].size();

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == word[0])
				{// maybe a success
					stack<Node> stk;
					Node curnode(word[0], i, j, 0);
					stk.push(curnode);
					board[curnode.x][curnode.y] = '*';
					int wind = 1;
					if (wind == word.size())
						return true;
					while (!stk.empty())
					{
						if (stk.top().p == 0)
						{
							stk.top().p = 1;
							if (stk.top().x > 0 && board[stk.top().x - 1][stk.top().y] == word[wind])
							{
								Node nextnode(word[wind], stk.top().x - 1, stk.top().y, 0);
								stk.push(nextnode);
								board[nextnode.x][nextnode.y] = '*';
								wind++;
								if (wind == word.size())
									return true;
								continue;
							}
						}
						if (stk.top().p == 1)
						{
							stk.top().p = 2;
							if (stk.top().x < m - 1 && board[stk.top().x + 1][stk.top().y] == word[wind])
							{
								Node nextnode(word[wind], stk.top().x + 1, stk.top().y, 0);
								stk.push(nextnode);
								board[nextnode.x][nextnode.y] = '*';
								wind++;
								if (wind == word.size())
									return true;
								continue;
							}
						}
						if (stk.top().p == 2)
						{
							stk.top().p = 3;
							if (stk.top().y > 0 && board[stk.top().x][stk.top().y - 1] == word[wind])
							{
								Node nextnode(word[wind], stk.top().x, stk.top().y - 1, 0);
								stk.push(nextnode);
								board[nextnode.x][nextnode.y] = '*';
								wind++;
								if (wind == word.size())
									return true;
								continue;
							}
						}
						if (stk.top().p == 3)
						{
							stk.top().p = 4;
							if (stk.top().y < n - 1 && board[stk.top().x][stk.top().y + 1] == word[wind])
							{
								Node nextnode(word[wind], stk.top().x, stk.top().y + 1, 0);
								stk.push(nextnode);
								board[nextnode.x][nextnode.y] = '*';
								wind++;
								if (wind == word.size())
									return true;
								continue;
							}
						}
						//restore
						board[stk.top().x][stk.top().y] = stk.top().c;
						stk.pop();
						wind--;
					}
				}
			}
		}
		return false;
	}
};

int main()
{
	Solution s;
	vector<vector<char>> board = { { 'A' , 'B' , 'C' , 'E' }, { 'S','F','C','S' }, {'A','D','E','E'} };
	vector<vector<char>> board2 = { { 'a' }};

	cout << s.exist(board2, "a") << endl;
	//cout << s.exist(board, "SFCS") << endl;
	//cout << s.exist(board, "ABCB") << endl;

	system("pause");
	return 0;

}