/**
使用邻接表存储教材197页图7.22的无向图，基于栈结构实现该
图的深度优先搜索算法，输出一个深度优先搜索遍历序列。
*/

#include<iostream>
#include<vector>

#define INFINITY 0xFFFFFF
#define N 6

using namespace std;

template <typename T>
class Stack {
private:
	vector<T> stack;

public:
	void push(T elem) {	stack.push_back(elem);}

	T pop() {
		if (stack.size() == 0)
			return NULL;
		T temp = *(stack.end() - 1);
		stack.erase(stack.end() - 1);
		return temp;
	}

	int size() {return stack.size();}

	void clear() {stack.clear();}

	bool isEmpty() {return stack.size() == 0;}

	T top() {
		if (stack.size() == 0)
			return NULL;
		else
			return *(stack.end() - 1);
	}
};

class Graph {
private:
	vector<vector<int>> graph;
	vector<string> names;
	int size;

public:
	Graph(vector<string> names) {
		this->names = names;
		size = names.size();
	}

};

Stack<int> s;
int graph[N][N] = { {0,1,1,1,INFINITY,INFINITY},
					{1,0,1,INFINITY,1,INFINITY},
					{1,1,0,1,1,INFINITY},
					{1,INFINITY,1,0,1,1},
					{INFINITY,1,1,1,0,INFINITY},
					{INFINITY,INFINITY,INFINITY,1,INFINITY,0} };
int vis[N];

void dfs() {
	int top = s.top();
	s.pop();
	printf("%d ", top);

	for (int i = 1; i <= N; i++) {
		if (!vis[i] && graph[i][top] == 1) {
			vis[i] = 1;
			s.push(i);
		}
	}

	if (!s.isEmpty()) {
		dfs();
	}
}

int main() {
	dfs();
	system("pause");
	return 0;
}