/**
以教材185页图7.12的有向图为例，设计程序，采用邻接矩阵
的形式存储该图，并通过计算输出顶点D的出度和入度。
*/

#include<iostream>

#define INFINITY 0xFFFFFF
#define N 5

using namespace std;

int graph[N][N] = { {0,10,INFINITY,30,90},
					{INFINITY,0,50,40,INFINITY},
					{INFINITY,INFINITY,0,INFINITY,10},
					{INFINITY,INFINITY,20,0,60},
					{INFINITY,INFINITY,INFINITY,INFINITY,0} };

int inDegree(int i) {
	int in = 0;
	for (int j = 0; j < N; j++) {
		if (graph[j][i] != 0 && graph[j][i] != INFINITY)
			in++;
	}

	return in;
}

int outDegree(int i) {
	int out = 0;
	for (int j = 0; j < N; j++) {
		if (graph[i][j] != 0 && graph[i][j] != INFINITY)
			out++;
	}
	
	return out;

}

int main() {
	cout << "D的入读为：" << inDegree(3) << endl;
	cout << "D的出度为：" << outDegree(3) << endl;

	system("pause");
	return 0;
}