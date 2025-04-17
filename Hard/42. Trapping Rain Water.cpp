class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> leftMax(height.size());
        vector<int> rightMax(height.size());
        int lmax = 0, rmax = 0;
        for (int i = 0; i < height.size(); i++){
            leftMax[i] = lmax;
            rightMax[height.size() - i - 1] = rmax;
            if (height[i] > lmax) lmax = height[i];
            if (height[height.size() - i - 1] > rmax) rmax = height[height.size() - i - 1];
        }
        int result = 0;
        for (int i = 0; i < height.size(); i++){
            result += max((min(leftMax[i], rightMax[i]) - height[i]), 0);
        }
        return result;
    }
};