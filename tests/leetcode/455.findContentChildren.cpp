/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

#include <algorithm>
#include <vector>

#include <gtest/gtest.h>

using namespace std;
// @lc code=start
class Solution {
public:
    int findContentChildren([[maybe_unused]] vector<int>& g, [[maybe_unused]] vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int count = 0;

        auto gt = g.begin();
        auto st = s.begin();

        while(gt != g.end() && st != s.end()) {
            if(*gt <= *st) {
                gt++;
                st++;
                count++;
            } else {
                st++;
            }
        }

        return count;
    }
};
// @lc code=end

TEST(L455_FindContentChildrenTest, T1) {
    vector<int> g {1, 2, 3};
    vector<int> s {1, 1};

    Solution sol;

    EXPECT_EQ(1, sol.findContentChildren(g, s));
}

TEST(L455_FindContentChildrenTest, T2) {
    vector<int> g {1, 2};
    vector<int> s {1, 2, 3};

    Solution sol;

    EXPECT_EQ(2, sol.findContentChildren(g, s));
}
