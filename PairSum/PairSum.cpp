#include <iostream>
#include <vector>
#include <unordered_set>

bool hasPairWithSum( const std::vector<int>&, int);

int main() {

	std::vector<int> nums = { 1,3,5,7,8,8,9,12,13 };
	int sum = 12;
	
	std::cout << hasPairWithSum(nums, sum);


	/*if (hasPairWithSum(nums, 12) == true) {
		std::cout << "The vector contains the pair that results in sum! \n";

	}
	else
		std::cout << "no pair found.";*/
}

bool hasPairWithSum(const std::vector<int>& nums, int sum ) {
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
