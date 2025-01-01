#include <gtest/gtest.h>
#include "Graph.hpp"

// 测试Graph类的构造函数
TEST(GraphTest, Constructor) {
    Graph g(5);
    EXPECT_EQ(g.V, 5);
    for (const auto& row : g.adj_matrix) {
        for (int val : row) {
            EXPECT_EQ(val, 0);
        }
    }
}

// 测试添加边
TEST(GraphTest, AddEdge) {
    Graph g(5);
    g.add_edge(1, 2);
    EXPECT_EQ(g.adj_matrix[1][2], 1);
    EXPECT_EQ(g.adj_matrix[2][1], 1);
}

// 测试删除边
TEST(GraphTest, RemoveEdge) {
    Graph g(5);
    g.add_edge(1, 2);
    g.remove_edge(1, 2);
    EXPECT_EQ(g.adj_matrix[1][2], 0);
    EXPECT_EQ(g.adj_matrix[2][1], 0);
}

// 测试检查边的存在
TEST(GraphTest, HasEdge) {
    Graph g(5);
    g.add_edge(1, 2);
    EXPECT_TRUE(g.has_edge(1, 2));
    EXPECT_TRUE(g.has_edge(2, 1));
    EXPECT_FALSE(g.has_edge(1, 3));
}

// 测试获取邻居节点
TEST(GraphTest, GetNeighbors) {
    Graph g(5);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    std::vector<int> expected_neighbors = {2, 3};
    std::vector<int> actual_neighbors = g.get_neighbors(1);
    EXPECT_EQ(actual_neighbors, expected_neighbors);
}

// 测试打印图（由于是矩阵形式，需要输出整个矩阵进行验证）
TEST(GraphTest, PrintGraph) {
    // 由于此函数输出到控制台，需要重定向输出到字符串流以测试输出格式
    // 此处略去具体实现，需要结合Graph类的实际实现来完成
}
