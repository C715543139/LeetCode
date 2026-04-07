#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector res{string{}};
        unordered_map<char, string> map{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        for (const auto &digit: digits) {
            const auto &str = map[digit];
            vector<string> temp;
            for (const auto &c : str) {
                for (auto elem: res) {
                    elem += c;
                    temp.push_back(elem);
                }
            }
            res = std::move(temp);
        }
        return res;
    }
};

int main() {
    return 0;
}
