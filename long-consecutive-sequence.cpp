#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int max_length = 0;

        for (int num : num_set) {
            // Check if it's the start of a sequence
            if (num_set.find(num - 1) == num_set.end()) {
                int current_num = num;
                int current_length = 1;

                // Expand the sequence to the right
                while (num_set.find(current_num + 1) != num_set.end()) {
                    current_num++;
                    current_length++;
                }

                max_length = max(max_length, current_length);
            }
        }

        return max_length;
    }
};