class Solution {
public:
void update(vector<int>& bit, int idx, int val) {
    while (idx < bit.size()) {
        bit[idx] += val;
        idx += idx & -idx;
    }
}

// 树状数组查询前缀和操作
int query(vector<int>& bit, int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += bit[idx];
        idx -= idx & -idx;
    }
    return sum;
}

long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    // 记录 nums2 中每个元素的索引
    vector<int> index(n);
    for (int i = 0; i < n; ++i) {
        index[nums2[i]] = i;
    }

    vector<int> bit(n + 1, 0);
    vector<int> left_smaller(n);

    // 计算每个元素左边比它小的元素数量
    for (int i = 0; i < n; ++i) {
        int pos = index[nums1[i]] + 1;
        left_smaller[i] = query(bit, pos);
        update(bit, pos, 1);
    }

    fill(bit.begin(), bit.end(), 0);
    vector<int> right_larger(n);

    // 计算每个元素右边比它大的元素数量
    for (int i = n - 1; i >= 0; --i) {
        int pos = index[nums1[i]] + 1;
        right_larger[i] = query(bit, n) - query(bit, pos);
        update(bit, pos, 1);
    }

    long long count = 0;
    // 计算好三元组数量
    for (int i = 0; i < n; ++i) {
        count += (long long)left_smaller[i] * right_larger[i];
    }

    return count;
}
};