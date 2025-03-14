#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> duplicates;
        int n = nums.size();

        // Rearrange elements to their correct positions
        for (int i = 0; i < n; i++) {
            while (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Find duplicates
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                duplicates.push_back(nums[i]);
            }
        }

        return duplicates;
    }
};



// Explanation:
// Step 1: Rearrange Elements
// Use the fact that numbers are in the range 
// [
// 1
// ,
// 𝑛
// ]
// [1,n].
// Place each number at its "correct position" (i.e., the value nums[i] should be at index nums[i] - 1).