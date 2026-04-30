class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, int> freqs;
        for (int i = 1; i <= n; ++i) {
            freqs[i] = 0;
        }

        for (int i = 0; i < trust.size(); ++i) {
            freqs[trust[i][0]]++;
            freqs[trust[i][1]]--;
        }

        if (freqs.size() < 1) return -1;

        for (auto i : freqs) {
            if (i.second == -1 * (n - 1)) return i.first;
        }
        return -1;
    }
};