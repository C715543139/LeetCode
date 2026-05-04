#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size(), res = 0;
        vector<int> st, leftFirstSmall(n), rightFirstSmall(n);
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && heights[st.back()] >= heights[i]) {
                st.pop_back();
            }
            leftFirstSmall[i] = st.empty() ? -1 : st.back();
            st.push_back(i);
        }
        st.clear();
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && heights[st.back()] >= heights[i]) {
                st.pop_back();
            }
            rightFirstSmall[i] = st.empty() ? n : st.back();
            st.push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            res = max(res, (rightFirstSmall[i] - leftFirstSmall[i] - 1) * heights[i]);
        }
        return res;
    }
};

int main() {
    vector hs = {5, 5, 1, 7, 1, 1, 5, 2, 7, 6};
    cout << Solution().largestRectangleArea(hs) << endl;
    return 0;
}
