#include <bits/stdc++.h>
using namespace std;

int findKth(vector<int>& nums1, int start1, vector<int>& nums2, int start2, int K) {
    int len1 = nums1.size() - start1;
    int len2 = nums2.size() - start2;
    if (len1 > len2) return findKth(nums2, start2, nums1, start1, K);
    if (len1 == 0) return nums2[start2 + K - 1];
    if (K == 1) return min(nums1[start1], nums2[start2]);
    int i = start1 + min(len1, K / 2) - 1;
    int j = start2 + min(len2, K / 2) - 1;
    if (nums1[i] < nums2[j]) {
        return findKth(nums1, i + 1, nums2, start2, K - (i - start1 + 1));
    } else {
        return findKth(nums1, start1, nums2, j + 1, K - (j - start2 + 1));
    }
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int len1 = nums1.size(), len2 = nums2.size();
    int K1 = (len1 + len2 + 1) / 2;
    int K2 = (len1 + len2 + 2) / 2;
    return 0.5 * (findKth(nums1, 0, nums2, 0, K1) + findKth(nums1, 0, nums2, 0, K2));
}
int main()
{
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}