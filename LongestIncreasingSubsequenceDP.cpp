#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int getLengthOfLIS(vector<int>& nums, int index, vector<int>& flag) {
	if (flag[index] >= 0) {
		return flag[index];
	}
	int maxAns = 0;
	for (int i = index+1; i < nums.size(); i++) {
		if (nums[i] > nums[index]) {
			maxAns =max(maxAns, getLengthOfLIS(nums, i, flag));
		}
	}
	flag[index] = maxAns + 1;
	return flag[index];
}

int main() {
	int a,n;
	vector<int>vs;
	vector<int>flag;
	cout << "Enter Size:" << "\n";
	cin >> n;
	cout << "Enter Array:" << "\n";
	for (int i = 0; i < n; i++) {
		cin >> a;
		vs.push_back(a);
		flag.push_back(-1);
	}
	int maxLis = 0;
	for (int i = 0; i < vs.size(); i++) {
		 maxLis = max(maxLis, getLengthOfLIS(vs, i, flag));
		//cout << getLengthOfLIS(vs, i) << "\n";
	}
	cout<< "lis:" << maxLis <<"\n";
	return 0;
}
