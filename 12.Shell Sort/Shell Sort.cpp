/**
��ؼ���������{3,17,12,61,8,70,97,75,53,26,54,61}�����ʵ�ֿ��������㷨
����ϣ�������㷨����ʵ�ָùؼ������е������������ÿ�˵���������
*/

#include<iostream>
#include<vector>

using namespace std;

void shellSort(vector<int>& nums){
	int j, gap;
	int count = 1; //��¼�ڼ�������
	int n = nums.size();
	for (gap = n / 2; gap > 0; gap /= 2) {
		for (j = gap; j < n; j++)   //�������gap��Ԫ�ؿ�ʼ
			if (nums[j] < nums[j - gap]) {  //ÿ��Ԫ�����Լ����ڵ����ݽ���ֱ�Ӳ�������      
				int temp = nums[j];
				int k = j - gap;
				while (k >= 0 && nums[k] > temp) {
					nums[k + gap] = nums[k];
					k -= gap;
				}
				nums[k + gap] = temp;
			}
		cout << "��" << count << "������";
		for (int num : nums)
			cout << num << " ";
		cout << endl;
		count++;
	}
}

int main() {
	vector<int> nums = { 3,17,12,61,8,70,97,75,53,26,54,61 };
	shellSort(nums);

	system("pause");
	return 0;
}