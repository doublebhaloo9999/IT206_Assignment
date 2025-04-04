#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }
        
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> maxHeap(cmp);
        
        for (auto& entry : freqMap) {
            maxHeap.push(entry);
        }
        
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(maxHeap.top().first);
            maxHeap.pop();
        }
        
        return result;
    }
};