/**
基于栈结构，设计实现中缀表达式转化为后缀表达式、计算后缀表达式
值的算法，计算表达式 10-(3*5)/6 的值。要求使用自定义的栈类实现。
*/

#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>

using namespace std;

template <typename T>
class Stack {
private:
	vector<T> stack;

public:
	void push(T elem) {
		stack.push_back(elem);
	}

	T pop() {
		if (stack.size() == 0)
			return NULL;
		T temp = *(stack.end() - 1);
		stack.erase(stack.end() - 1);
		return temp;
	}

	int size() {
		return stack.size();
	}

	void clear() {
		stack.clear();
	}

	bool isEmpty() {
		return stack.size() == 0;
	}

	T top() {
		if (stack.size() == 0)
			return NULL;
		else
			return *(stack.end() - 1);
	}
};


bool isBiggerThen(const char l, const char r) {
	if (l == '(')
		return false;
	int lValue, rValue;
	switch (l) {
	case '+':
	case '-':
		lValue = 0;
		break;
	case '*':
	case '/':
		lValue = 1;
		break;
	case '(':
		lValue = 2;
		break;
	}
	switch (r) {
	case '+':
	case '-':
		rValue = 0;
		break;
	case '*':
	case '/':
		rValue = 1;
		break;
	case '(':
		rValue = 2;
		break;
	}

	return lValue > rValue;
}

int calculateExec(char opera, int a, int b) {
	switch (opera)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	}
}

//中缀转后缀
string infix2RPN(string infix) {
	Stack<char> operatorStack;
	string RPN;
	for (char i : infix) {
		if (i >= '0'&&i <= '9') {
			RPN += i;
		}
		else {
			RPN += " ";
			if (i != ')') {
				if (operatorStack.isEmpty())
					operatorStack.push(i);
				else if (!isBiggerThen(operatorStack.top(), i))
					operatorStack.push(i);
				else {
					while (!operatorStack.isEmpty() && operatorStack.top() != '(') {
						RPN += operatorStack.pop();
						RPN += " ";
					}
				}
			}
			else {
				char c = operatorStack.pop();
				while (c != '(') {
					RPN += c;
					RPN += " ";
					c = operatorStack.pop();
				}
			}
		}
	}
	while (!operatorStack.isEmpty()) {
		RPN += operatorStack.pop();
		RPN += " ";
	}
	return RPN;
}

int calculateRPN(string RPN) {
	Stack<int> numStack;
	string digital;
	for (char i : RPN) {
		if (i >= '0'&&i <= '9')
			digital += i;
		else {
			if (digital != "") {
				int t = stoi(digital, 0, 10);
				digital = "";
				numStack.push(t);
			}
			if (i == ' ')
				continue;
			else {
				int a = numStack.pop();
				int b = numStack.pop();
				numStack.push(calculateExec(i, b, a));
			}
		}
	}

	return numStack.pop();
}

int main() {
	string input;
	cin >> input;
	string RPN = infix2RPN(input);
	cout << RPN << endl;
	cout << calculateRPN(RPN) << endl;
	system("pause");

	return 0;
}