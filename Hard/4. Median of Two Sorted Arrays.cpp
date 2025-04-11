class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result = 0.0;
        int size = nums1.size() + nums2.size();
        vector<int> nums(size);
        int l = 0, r = 0, index = 0;
        while (l < nums1.size() && r < nums2.size()){
            if (nums1[l] <= nums2[r]){
                nums[index] = nums1[l++];
            } else {
                nums[index] = nums2[r++];
            }
            index++;
        }
        while (l < nums1.size()) nums[index++] = nums1[l++];
        while (r < nums2.size()) nums[index++] = nums2[r++];
        size--;
        if (size % 2 == 1) {
            result = (nums[size / 2] + nums[(size / 2) + 1]);
            result /= 2;
        }
        else result = nums[size / 2];
        return result;
    }
};