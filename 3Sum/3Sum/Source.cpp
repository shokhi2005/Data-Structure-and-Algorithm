#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) 
{
	vector<vector<int>> myvector;
	
	int n = nums.size();
	sort(nums.begin(), nums.end());
	
	for (int i = 0; i < n; i++)
	{
		int low = i+1;
		int high = n-1;
		while (low < high)
		{
			
			
			if (nums[i] + nums[low] + nums[high] < 0)
				low++;
			else if(nums[i] + nums[low] + nums[high] > 0)
				high--;
			else
			{
				vector<int> temp;
				temp.push_back(nums[i]);
				temp.push_back(nums[low]);
				temp.push_back(nums[high]);
				myvector.push_back(temp);
				while (low < high && nums[low] == temp[1])low++;
				while (low < high && nums[high] == temp[2])high--;
			}
		}
		while (i + 1 < n && nums[i] == nums[i + 1])
			i++;
	}
	return myvector;
}

int main()
{
	vector<int> nums = { -4,-1,-1,0,1,2};
	vector<vector<int>> res;
	res = threeSum(nums);
	for (auto it = res.begin(); it != res.end(); it++)
	{
		for (auto ij = (*it).begin(); ij != (*it).end(); ij++)
		{
			cout << (*ij) << " ";
		}
		cout << endl;

	}

	return 0;
}