#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        vector bucket(2 * 10000 + 1, 0);
        for (const int num: nums) {
            bucket[num + 10000]++;
        }

        multimap<int, int> mp;
        for (int i = 0; i < 2 * 10000 + 1; ++i) {
            if (bucket[i] > 0) {
                mp.insert({bucket[i], i});
            }
        }

        vector<int> res;
        res.reserve(mp.size());
        auto it = mp.rbegin();
        for (int i = 0; i < k; i++) {
            res.push_back(it->second - 10000);
            ++it;
        }
        return res;
    }
};

class Solution2 {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> mp;
        for (const int num: nums) {
            mp[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (auto &[fst, snd] : mp) {
            if (pq.size() < k) {
                pq.emplace(snd, fst);
            } else if (pq.top().first < snd) {
                pq.pop();
                pq.emplace(snd, fst);
            }
        }

        vector<int> res;
        res.reserve(pq.size());
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};

int main() {
    vector nums = {
        5, 3, 1, 1, 1, 3, 73, 1
    };
    Solution2().topKFrequent(nums, 2);
    return 0;
}
