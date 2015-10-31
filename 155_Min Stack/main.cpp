#include <iostream>
#include <cstdlib>
#include <stack>

using namespace std;

class MinStack {
public:
	void push(int x) {
		data.push(x);
		if (minData.empty())
			minData.push(x);
		else{
			if (minData.top() > x)
				minData.push(x);
			else
				minData.push(minData.top());
		}
	}

	void pop() {
		data.pop();
		minData.pop();
	}

	int top() {
		return data.top();
	}

	int getMin() {
		return minData.top();
	}

private:
	stack<int> data;
	stack<int> minData;
};

int main()
{
	MinStack s;
	s.push(2);
	cout << s.top() << "\t" << s.getMin() << endl;

	s.push(3);
	cout << s.top() << "\t" << s.getMin() << endl;

	s.push(1);
	cout << s.top() << "\t" << s.getMin() << endl;

	system("pause");
	return 0;
}