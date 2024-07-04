#pragma once

#include <vector>
#include <set>
#include <unordered_map>

//并查集
template <typename T>
class DisjointSetUnion {
public:
    explicit DisjointSetUnion(const std::vector<T>& elements)
        : parent(elements.size()), rank(elements.size(), 0) {
        for (size_t i = 0; i < elements.size(); ++i) {
            indexMap[elements[i]] = i;
            parent[i] = elements[i];
        }
    }

    template <typename U = T, typename std::enable_if<std::is_same<U, int>::value, int>::type * = nullptr>
    explicit DisjointSetUnion(int size) : parent(size), rank(size, 0) {
        for (size_t i = 0; i < size; ++i) {
            indexMap[i] = i;
            parent[i] = i;
        }
    }

    T find(const T& x) {
        int index = indexMap[x];
        if (parent[index] != x) {
            parent[index] = find(parent[index]); // 路径压缩
        }
        return parent[index];
    }

    void unionSets(const T& x, const T& y) {
        T rootX = find(x);
        T rootY = find(y);
        if (rootX != rootY) {
            int indexX = indexMap[rootX];
            int indexY = indexMap[rootY];
            if (rank[indexX] < rank[indexY]) {
                parent[indexX] = rootY;
            }
            else if (rank[indexX] > rank[indexY]) {
                parent[indexY] = rootX;
            }
            else {
                parent[indexY] = rootX;
                rank[indexX]++;
            }
        }
    }

    // 返回所有分好的集合
    std::vector<std::set<T>> getAllSets() {
        std::vector<std::set<T>> allSets;
        std::set<T> visited;

        for (const auto& pair : indexMap) {
            T root = find(pair.first);
            if (visited.find(root) == visited.end()) {
                std::set<T> currentSet;
                for (const auto& innerPair : indexMap) {
                    if (find(innerPair.first) == root) {
                        currentSet.insert(innerPair.first);
                        visited.insert(root);
                    }
                }
                allSets.push_back(currentSet);
            }
        }

        return allSets;
    }
private:
    std::vector<T> parent; // 存储每个元素的父节点
    std::vector<int> rank;   // 存储每个集合的秩（高度）
    std::unordered_map<T, int> indexMap; // 存储元素与其索引的映射
};


