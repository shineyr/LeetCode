#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>

using namespace std;

class Queue {
public:
	// Push element x to the back of queue.
	void push(int x) {
		inStack.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void) {
		if (outStack.empty())
		{
			while (!inStack.empty())
			{
				outStack.push(inStack.top());
				inStack.pop();
			}
		}
		outStack.pop();
	}

	// Get the front element.
	int peek(void) {
		if (outStack.empty())
		{
			while (!inStack.empty())
			{
				outStack.push(inStack.top());
				inStack.pop();
			}
		}
		return outStack.top();
	}

	// Return whether the queue is empty.
	bool empty(void) {
		if (outStack.empty() && inStack.empty())
			return true;
		return false;
	}

private:
	stack<int> inStack;
	stack<int> outStack;
};

int main()
{
	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);

	cout << q.peek() << endl;
	q.pop();
	cout << q.peek() << endl;

	system("pause");
	return 0;
}