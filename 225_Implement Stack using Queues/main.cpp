
#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

class Stack {
public:
	// Push element x onto stack.
	void push(int x) {
		que[flag].push(x);
	}

	// Removes the element on top of the stack.
	void pop() {
		while (que[flag].size() > 1)
		{
			que[1 - flag].push(que[flag].front());
			que[flag].pop();
		}//while
		que[flag].pop();
		flag = 1 - flag;
	}

	// Get the top element.
	int top() {
		while (que[flag].size() > 1)
		{
			que[1 - flag].push(que[flag].front());
			que[flag].pop();
		}//while
		int ret = que[flag].front();
		que[1 - flag].push(que[flag].front());
		que[flag].pop();

		flag = 1 - flag;

		return ret;
	}

	// Return whether the stack is empty.
	bool empty() {
		return que[flag].empty();
	}

private:
	queue<int> que[2];
	int flag = 0; //作为存储队列
};

int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout << s.top() << endl;

	s.pop();
	cout << s.top() << endl;

	system("pause");
	return 0;
}