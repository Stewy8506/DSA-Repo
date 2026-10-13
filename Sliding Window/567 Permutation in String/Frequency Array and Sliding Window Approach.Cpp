class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        int freqs1[26] = {}, freqs2[26] = {}, left = 0;
        for (char c : s1){
            freqs1[ c - 'a']++;
        }
        for (int right = 0; right < s2.size(); right++){
            freqs2[s2[right] - 'a']++;
            if (right - left + 1 == s1.size()){
                if (equal(freqs1, freqs1 + 26, freqs2)) return true;
                freqs2[s2[left] - 'a']--;
                left++;
            }
        }
        return false;
    }
};