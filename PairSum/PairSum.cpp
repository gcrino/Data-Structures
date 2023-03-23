#include <iostream>
#include <vector>
#include <unordered_set>

bool hasPairWithSum1( const std::vector<int>&, int);
bool hasPairWithSum2(const std::vector<int>&, int);
bool hasPairWithSum3(const std::vector<int>&, int);

int main() {

	std::vector<int> nums = { 1,3,5,7,8,9,12};
	int sum = 12;
	
	hasPairWithSum1(nums, sum); //
	hasPairWithSum2(nums, sum);	//
	hasPairWithSum3(nums, sum);	//
	
}

bool hasPairWithSum1(const std::vector<int>& nums, int sum ) {
	for (int i=0; i < nums.size(); i++)
		for (int j = 0; j < nums.size(); j++) {
			
			if (i != j) {
				if (nums[i] + nums[j] == sum)
					std::cout << "Pairs found: " << nums[i] << " and " << nums[j] << "\n";
				return true;
			}
			else
				return false;
		}
}


bool hasPairWithSum2(const std::vector<int>& nums, int sum) {
	int start = 0;
	int end = nums.size() - 1;

	while (start < end) {
		if (nums[start] + nums[end] == sum) {
			std::cout << "\n" << start << "-" << end << "\n";
			return true;
		}
		else if (nums[start] + nums[end] > sum) {
			end--;
		}
		else {
			start++;
		}
	}
}

bool hasPairWithSum3(const std::vector<int>& nums, int sum) {
	std::unordered_set<int> compliments;					//									   |
															//									   v
	for (int x : nums) {									//								  { 1, 3, 5, 7, 8, 9, 12}
		if (compliments.find(x) != compliments.end()) {		// compliments of given set are: { 11, 9, 7, 5, 4, 3, 0 }
			std::cout << "\n" << "The "
			return true;
		}
		compliments.insert(sum - x);
	}
}
