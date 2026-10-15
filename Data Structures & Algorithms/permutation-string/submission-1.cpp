class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> str1(26, 0);
        vector<int> str2(26, 0);

        for (int i = 0; i < s1.size(); i++) {
            str1[s1[i] - 'a']++;
        }

        for (int i = 0; i <= s2.size() - s1.size(); i++) {
            fill(str2.begin(), str2.end(), 0);

            for (int j = i; j < i + s1.size(); j++) {
                str2[s2[j] - 'a']++;
            }

            if (str1 == str2) return true;
        }

        return false;
    }
};