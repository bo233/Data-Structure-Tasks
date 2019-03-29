/**
设目标串是“acabbabbabc”，模式串是“abbabc”，设计实现串的 Brute-Force 模
式匹配算法，完成串的匹配。要求基于自定义的字符串类实现，返回匹配趟数、
比较次数和匹配位置。
*/

#include<iostream>
#include<vector>

using namespace std;

class MyString {
private:
	vector<char> string;

public:
	MyString(char* s) {
		int i = 0;
		while (s[i])
			string.push_back(s[i++]);
	}

	MyString() {

	}

	int length() {
		return string.size();
	}

	char charAt(int index) {
		return string[index];
	}

	void append(char* s) {
		int i = 0;
		while (!s[i])
			string.push_back(s[i++]);
	}

	void append(char c) {
		string.push_back(c);
	}

	void append(MyString myS) {
		int i = 0;
		while (i < myS.length())
			string.push_back(myS.charAt(i));
	}

	MyString subString(int begin, int end) {
		MyString temp;
		int i = begin;
		while (i < end)
			temp.append(string[i++]);
		return temp;
	}
};

int BFMatch(MyString s, MyString p){
	int i, j;
	i = 0;
	while (i < s.length()){
		j = 0;
		while (j < p.length() && i < s.length() && s.charAt(i) == p.charAt(j)){
			i++;
			j++;
		}

		if (p.length() == j)
			return i - p.length();

		i = i - j + 1;                // 指针i回溯
	}

	return -1;
}

int main() {
	char a[100], b[100];
	gets_s(a);
	gets_s(b);
	MyString s1(a);
	MyString s2(b);
	cout << "匹配的起始位置：" << BFMatch(s1, s2) << endl;
	system("pause");
	return 0;
}