
#include "rotate.h"

#include <algorithm>
#include <forward_list>
#include <iterator>
#include <list>
#include <vector>

#include <gtest/gtest.h>

TEST(test_algorithm, test_rotate) {
  // 前向迭代器
  {
    std::forward_list<int> forward_list_1 = {7, 8, 0, 1, 2, 3, 4};
    std::forward_list<int> forward_list_2 = {7, 8, 0, 1, 2, 3, 4};

    liuyunbin::rotate(forward_list_1.begin(),
                      std::next(forward_list_1.begin(), 2),
                      forward_list_1.end());
    liuyunbin::rotate(forward_list_2.begin(),
                      std::next(forward_list_2.begin(), 2),
                      forward_list_2.end());
    EXPECT_EQ(forward_list_1, forward_list_2);
  }

  // 双向迭代器
  {
    std::list<int> list_1 = {7, 8, 0, 1, 2, 3, 4};
    std::list<int> list_2 = {7, 8, 0, 1, 2, 3, 4};

    std::rotate(list_1.begin(), std::next(list_1.begin(), 2), list_1.end());
    liuyunbin::rotate(list_2.begin(), std::next(list_2.begin(), 2),
                      list_2.end());
    EXPECT_EQ(list_1, list_2);
  }

  // 随机迭代器
  {
    std::vector<int> vector_1 = {7, 8, 0, 1, 2, 3, 4};
    std::vector<int> vector_2 = {7, 8, 0, 1, 2, 3, 4};

    std::rotate(vector_1.begin(), std::next(vector_1.begin(), 2),
                vector_1.end());
    liuyunbin::rotate(vector_2.begin(), std::next(vector_2.begin(), 2),
                      vector_2.end());
    EXPECT_EQ(vector_1, vector_2);
  }
}
