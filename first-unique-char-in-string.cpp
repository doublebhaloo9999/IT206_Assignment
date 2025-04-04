#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);
        
        // Count the frequency of each character
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        // Find the first character with frequency 1
        for (int i = 0; i < s.size(); ++i) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }
        
        return -1;
    }
};