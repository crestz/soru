#include <vector>

#include <gtest/gtest.h>

#include "soru/intrusive_list.hpp"

namespace {
  struct Node {
    int value;
    Node* link = nullptr;
  };

  using List = soru::IntrusiveList<Node, &Node::link>;
} // namespace

TEST(IntrusiveListTest, EmptyListHasNullHeadAndPopReturnsNullptr) {
  List list;

  EXPECT_EQ(list.Begin(), nullptr);
  EXPECT_EQ(list.End(), nullptr);
  EXPECT_EQ(list.Pop(), nullptr);
}

TEST(IntrusiveListTest, PushAndPopFollowLifoOrder) {
  Node first{.value = 1};
  Node second{.value = 2};
  Node third{.value = 3};
  List list;

  list.Push(&first);
  list.Push(&second);
  list.Push(&third);

  EXPECT_EQ(list.Begin(), &third);

  EXPECT_EQ(list.Pop(), &third);
  EXPECT_EQ(third.link, nullptr);
  EXPECT_EQ(list.Begin(), &second);

  EXPECT_EQ(list.Pop(), &second);
  EXPECT_EQ(second.link, nullptr);
  EXPECT_EQ(list.Begin(), &first);

  EXPECT_EQ(list.Pop(), &first);
  EXPECT_EQ(first.link, nullptr);
  EXPECT_EQ(list.Begin(), nullptr);
  EXPECT_EQ(list.Pop(), nullptr);
}

TEST(IntrusiveListTest, IteratorTraversesFromHeadToTail) {
  Node first{.value = 1};
  Node second{.value = 2};
  Node third{.value = 3};
  List list;

  list.Push(&first);
  list.Push(&second);
  list.Push(&third);

  std::vector<int> values;
  for (const Node& node : list) {
    values.push_back(node.value);
  }

  const std::vector<int> expected{3, 2, 1};
  EXPECT_EQ(values, expected);
}
