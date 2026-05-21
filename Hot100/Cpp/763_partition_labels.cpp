#include <deque>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> res;
    unordered_map<char, deque<int>> mp;

    vector<int> partitionLabels(string s) {
        for (int i = 0; i < s.size(); ++i) {
            mp[s[i]].push_back(i);
        }

        for (int i = 0; i < s.size();) {
            int start = i;
            auto &pos = mp[s[i]];
            res.push_back(pos.back() - i + 1);
            i = pos.back() + 1;

            for (int j = start; j < i; j++) {
                int checkIdx = findChar(s[j]);
                if (checkIdx != -1) {
                    merge(checkIdx);
                }
            }
        }
        return res;
    }

    void merge(int idx) {
        int sum = 0;
        for (int j = res.size() - 1; j >= idx; j--) {
            sum += res[j];
            res.pop_back();
        }
        if (sum) {
            res.push_back(sum);
        }
    }

    int findChar(char c) {
        int start = 0;
        for (int i = 0; i < res.size(); ++i) {
            int idx = mp[c].front();
            if (idx >= start && idx < start + res[i]) {
                return i;
            }
            start += res[i];
        }
        return -1;
    }
};

int main() {
    string s = {"qiejxqfnqceocmy"};
    Solution().partitionLabels(s);
    return 0;
}
