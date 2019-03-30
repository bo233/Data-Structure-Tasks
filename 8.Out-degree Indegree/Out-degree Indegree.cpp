/**
�Խ̲�185ҳͼ7.12������ͼΪ������Ƴ��򣬲����ڽӾ���
����ʽ�洢��ͼ����ͨ�������������D�ĳ��Ⱥ���ȡ�
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
	cout << "D�����Ϊ��" << inDegree(3) << endl;
	cout << "D�ĳ���Ϊ��" << outDegree(3) << endl;

	system("pause");
	return 0;
}