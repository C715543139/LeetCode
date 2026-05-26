#include <algorithm>
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

class Solution2 {
    // 合并区间
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int, int>> mp;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (mp.count(c) == 0) {
                mp.emplace(c, make_pair(i, i));
            } else {
                mp[c].second = i;
            }
        }

        vector<pair<int, int>> v;
        v.reserve(mp.size());
        for (auto &[fst, snd]: mp) {
            v.push_back(snd);
        }
        sort(v.begin(), v.end());

        int begin = v[0].first, end = v[0].second;
        vector res{end - begin + 1};
        for (int i = 1; i < v.size(); ++i) {
            int newBegin = v[i].first, newEnd = v[i].second;
            if (newBegin < end) {
                end = max(end, newEnd);
                res.back() = end - begin + 1;
            } else {
                begin = newBegin;
                end = newEnd;
                res.push_back(end - begin + 1);
            }
        }
        return res;
    }
};

class Solution3 {
public:
    vector<int> partitionLabels(string s) {
        vector lastPos(128, 0);
        for (int i = 0; i < s.size(); ++i) {
            lastPos[s[i]] = i;
        }

        int begin = 0, end = 0;
        vector<int> res;
        for (int i = 0; i < s.size(); ++i) {
            end = max(end, lastPos[s[i]]);
            if (i == end) {
                res.push_back(end - begin + 1);
                begin = end + 1;
            }
        }
        return res;
    }
};

int main() {
    string s = {"ababcbacadefegdehijhklij"};
    Solution3().partitionLabels(s);
    return 0;
}
