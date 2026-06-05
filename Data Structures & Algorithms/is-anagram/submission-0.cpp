class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> sCharMap;
        // Traverse through first string and count up
        // each char's occurrence
        for (char c : s) {
            // Char not found - add to map
            if (!sCharMap[c]) {
                sCharMap[c] =  1;
            }
            else {
                sCharMap[c]++;
            }
        }
        
        // Now traverse through 2nd string
        // Conditions for equality:
        // - All of the map's values are 0 (catches that we don't have
        //   any chars present in S not present in T)
        // - We don't come across any new chars (catches that we don't
        //   have chars present in T and not in S)
        for (char c : t) {
            if (!sCharMap[c]) {
                // Char not found in orig. string - false
                return false;
            }
            else {
                sCharMap[c]--;
            }
        }

        for (auto& [key, value] : sCharMap) {
            if (value != 0) {
                return false;
            }
        }
        return true;
    }
};
