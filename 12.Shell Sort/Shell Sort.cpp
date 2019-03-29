/**
设关键字序列是{3,17,12,61,8,70,97,75,53,26,54,61}，设计实现快速排序算法
（或希尔排序算法），实现该关键字序列的升序排序，输出每趟的排序结果。
*/

#include<iostream>
#include<vector>

using namespace std;

void shellSort(vector<int>& nums){
	int j, gap;
	int count = 1; //记录第几趟排序
	int n = nums.size();
	for (gap = n / 2; gap > 0; gap /= 2) {
		for (j = gap; j < n; j++)   //从数组第gap个元素开始
			if (nums[j] < nums[j - gap]) {  //每个元素与自己组内的数据进行直接插入排序      
				int temp = nums[j];
				int k = j - gap;
				while (k >= 0 && nums[k] > temp) {
					nums[k + gap] = nums[k];
					k -= gap;
				}
				nums[k + gap] = temp;
			}
		cout << "第" << count << "趟排序：";
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