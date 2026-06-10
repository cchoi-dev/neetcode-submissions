class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Anagrams are defined as words that have the same letters
        // but arranged in different orders (e.g. cat and act).
        // We need a way to identify these words by their anagram groups,
        // and then determine if any new word fits into any pre-identified
        // anagram groups.

        // Right now, one way I can think about implementing this is to
        // have a running list of hash maps that identify each anagram group.
        vector<unordered_map<char, int>> myMaps;
        vector<int> idxToRetVecIdx;
        // First, we need to make maps out of each word
        for (auto word : strs) {
            // printf("%s\n", word.c_str());
            unordered_map<char, int> newWordMap = getWordMapFromString(word);
            if (myMaps.size() == 0) {
                myMaps.push_back(newWordMap);
                idxToRetVecIdx.push_back(0);
                continue;
            }
            bool anagramMapAlreadyExists = false;
            int amapIdx = 0;
            for (auto anagramMap : myMaps) {
                if (areAnagramMapsEquivalent(anagramMap, newWordMap)) {
                    // printf("Prev amap found for %s at idx %d\n", word.c_str(), amapIdx);
                    idxToRetVecIdx.push_back(amapIdx);
                    anagramMapAlreadyExists = true;
                    break;
                }
                amapIdx++;
            }
            if (!anagramMapAlreadyExists) {
                myMaps.push_back(newWordMap);
                idxToRetVecIdx.push_back(amapIdx);
            }
        }

        // Group all words together
        // printf("myMap.size() = %d\n", (int)myMaps.size());
        vector<vector<string>> retVec(myMaps.size(), vector<string>{});
        std::fill(retVec.begin(), retVec.end(), vector<string>{});
        for (int i = 0; i < idxToRetVecIdx.size(); i++) {
            // printf("Sorting word %s\n", strs[i].c_str());
            retVec[idxToRetVecIdx[i]].push_back(strs[i]);
        }
        return retVec;
    }

    unordered_map<char, int> getWordMapFromString(string word) {
        unordered_map<char, int> wordMap;
        for (auto c : word) {
            if (!wordMap.contains(c)) {
                wordMap[c] = 1;
            }
            else {
                wordMap[c] += 1;
            }
        }
        return wordMap;
    }

    bool areAnagramMapsEquivalent(unordered_map<char, int>& anagramMap, unordered_map<char, int>& wordLetterCountMap) {
        if (anagramMap.size() != wordLetterCountMap.size()) {
            return false;
        }

        for (const auto& [letter, count] : wordLetterCountMap) {
            if (!anagramMap.contains(letter)) {
                return false;
            }
            if (anagramMap[letter] != count) {
                return false;
            }
        }
        return true;
    }
};
