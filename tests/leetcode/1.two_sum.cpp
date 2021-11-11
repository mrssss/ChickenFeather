/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

#include <vector>
#include <unordered_map>

#include <gtest/gtest.h>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum([[maybe_unused]] vector<int>& nums, [[maybe_unused]] int target) {
        unordered_map<int, int> hashtable;

        for (int i=0; i < nums.size(); i++) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return vector<int>{it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return vector<int>{};
    }
};
// @lc code=end

TEST(L1_TwoSum, T1) {
    vector<int> nums = {2,7,11,15};
    int target = 9;

    Solution sol;
    vector<int> res{0, 1};

    EXPECT_EQ(res, sol.twoSum(nums, target));
}

TEST(L1_TwoSum, T2) {
    vector<int> nums = {3, 2, 4};
    int target = 6;

    Solution sol;
    vector<int> res{1, 2};
    
    EXPECT_EQ(res, sol.twoSum(nums, target));
}

TEST(L1_TwoSum, T3) {
    vector<int> nums = {3, 3};
    int target = 6;

    Solution sol;
    vector<int> res{0, 1};
    
    EXPECT_EQ(res, sol.twoSum(nums, target));
}