/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

#include <numeric>
#include <vector>

#include <gtest/gtest.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int candy([[maybe_unused]] vector<int>& ratings) {
        if(ratings.size() == 0) return 0;
        if(ratings.size() == 1) return 1;

        vector<int> candies(ratings.size(), 1);
        candies[0] = 1;
        for (int i = 1; i < ratings.size(); i++) {
            if(ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1] + 1;
            }
        }

        for (int i = ratings.size()-2; i >= 0; i--) {
            if(ratings[i] > ratings[i+1] && candies[i] <= candies[i+1]) {
                candies[i] = candies[i+1] + 1;
            }
        }

        return accumulate(candies.begin(), candies.end(), 0);
    }
};
// @lc code=end

TEST(L135_Candy, T1) {
    vector<int> r {1, 0, 2};

    Solution sol;

    EXPECT_EQ(5, sol.candy(r));   
}

TEST(L135_Candy, T2) {
    vector<int> r {1, 2, 2};

    Solution sol;

    EXPECT_EQ(4, sol.candy(r));   
}