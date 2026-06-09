class Solution {
public:
    bool isPalindrome(string s) {
        // To determine whether an input is a palindrome, one way we could go about this is
        // to have two pointers that continue until they're equal or 'past' each other.
        for (auto& c : s) {
            c = std::tolower(static_cast<unsigned char>(c));
        }
        auto start = s.begin();
        auto end = s.end();
        end--;
        if (!std::isalnum(*start)) {
            iterateUntilAlphanumeric(start, true);
        }
        if (!std::isalnum(*end)) {
            iterateUntilAlphanumeric(end, false);
        }
        while (start <= end) {
            // Compare values and continue if the characters are the same
            printf("%c - %c", *start, *end);
            if (*start != *end) {
                return false;
            }
            iterateUntilAlphanumeric(start, true);
            iterateUntilAlphanumeric(end, false);
        }

        return true;
    }

    void iterateUntilAlphanumeric(string::iterator& it, bool iterateForward) {
        // printf("Started at %c, iterating ", *it);
        // printf("%s.\n", iterateForward ? "forwards" : "backwards");
        do {
            if (iterateForward) {
                it++;
            }
            else {
                it--;
            }
        } while (!std::isalnum(*it));
        // printf("Ended at %c\n", *it);
    }
};
