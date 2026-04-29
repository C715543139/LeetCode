#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int s1 = nums1.size(), s2 = nums2.size();
        int midIdx = (s1 + s2) / 2;
        int p = 0, q = 0, cur = 0, last = 0;
        while (midIdx >= 0) {
            last = cur;
            if (p == s1 && q < s2) cur = nums2[q++];
            if (q == s2 && p < s1) cur = nums1[p++];
            if (p < s1 && q < s2) {
                if (nums1[p] < nums2[q]) {
                    cur = nums1[p++];
                } else {
                    cur = nums2[q++];
                }
            }
            midIdx--;
        }
        if ((s1 + s2) % 2 == 0) {
            return (last + cur) / 2.0;
        }
        return cur;
    }
};

int main() {
    vector v1 = {1}, v2 = {2, 3, 4};
    cout << Solution().findMedianSortedArrays(v2, v1);
    return 0;
}
