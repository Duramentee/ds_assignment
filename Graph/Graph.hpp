//
// Created by lsx31 on 24-12-10.
//

#pragma once

#include <ostream>
#include <vector>
#include <iostream>

struct Graph {
    int V;
    std::vector<std::vector<int>> adj_matrix;

    Graph(int vertices) {
        V = vertices;
        adj_matrix.resize(V, std::vector<int>(V, 0));
    }

    void add_edge(int u, int v) {
        if (u >= 0 && u < V && v >= 0 && v < V) {
            adj_matrix[u][v] = 1;
            adj_matrix[v][u] = 1;
        } else {
            std::cout << "边顶点超出范围！" << std::endl;
        }
    }

    void remove_edge(int u, int v) {
        if (u >= 0 && u < V && v >= 0 && v < V) {
            adj_matrix[u][v] = 0;
            adj_matrix[v][u] = 0;
        } else {
            std::cout << "边顶点超出范围!" << std::endl;
        }
    }

    bool has_edge(int u, int v) {
        if (u >= 0 && u < V && v >= 0 && v < V) {
            return adj_matrix[u][v] == 1;
        } else {
            std::cout << "边顶点超出范围!" << std::endl;
            return false;
        }
    }

    std::vector<int> get_neighbors(int u) {
        std::vector<int> neighbors;
        if (u >= 0 && u < V) {
            for (int v = 0; v < V; ++v) {
                if (adj_matrix[u][v] == 1) {
                    neighbors.push_back(v);
                }
            }
        } else {
            std::cout << "顶点超出范围！" << std::endl;
        }
        return neighbors;
    }

    void print_graph() {
        std::cout << "用邻接矩阵表示的图：" << std::endl;
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                std::cout << adj_matrix[i][j];
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};