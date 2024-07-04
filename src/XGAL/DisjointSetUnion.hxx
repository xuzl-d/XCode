#pragma once

#include <vector>
#include <set>
#include <unordered_map>

//���鼯
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
            parent[index] = find(parent[index]); // ·��ѹ��
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

    // �������зֺõļ���
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
    std::vector<T> parent; // �洢ÿ��Ԫ�صĸ��ڵ�
    std::vector<int> rank;   // �洢ÿ�����ϵ��ȣ��߶ȣ�
    std::unordered_map<T, int> indexMap; // �洢Ԫ������������ӳ��
};


