#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    static string multiply(const string &s, int times) {
        string res;
        while (times--) res += s;
        return res;
    }

    string decodeString(string s) {
        deque<int> repeat;
        deque<string> elems;
        string elem;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                string num;
                while (s[i] >= '0' && s[i] <= '9') num += s[i++];
                repeat.push_back(stoi(num));
                elems.push_back(elem);
                elem.clear();
            } else if (s[i] == ']') {
                int times = repeat.back();
                repeat.pop_back();
                elem = multiply(elem, times);
                elem.insert(0, elems.back());
                elems.pop_back();
            } else {
                elem += s[i];
            }
        }
        elems.push_back(elem);
        string res;
        while (!elems.empty()) {
            res += elems.front();
            elems.pop_front();
        }
        return res;
    }
};

class Solution2 {
public:
    static string multiply(const string &s, int times) {
        string res;
        res.reserve(s.length() * times);
        while (times--) res += s;
        return res;
    }

    string decodeString(const string &s) {
        if (s.find('[') == string::npos) {
            return s;
        }

        int i = 0;
        while (!(s[i] >= '0' && s[i] <= '9')) i++;
        int ahead = i;

        string num;
        while (s[i] >= '0' && s[i] <= '9') num += s[i++];
        int times = stoi(num);

        i++;
        int midStart = i, midEnd = midStart, l = 0, r = 0;
        while (i < s.length()) {
            if (s[i] == '[') l++;
            if (s[i] == ']') r++;
            if (r == l + 1) {
                midEnd = i;
                break;
            }
            i++;
        }
        string tail = i < s.length() ? decodeString(s.substr(++i)) : "";
        return s.substr(0, ahead) + multiply(decodeString(s.substr(midStart, midEnd - midStart)), times) + tail;
    }
};

int main() {
    string s = "3[2[4[c]e]]";
    cout << Solution2().decodeString(s);
    return 0;
}
