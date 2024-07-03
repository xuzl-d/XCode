#include <iostream>
#include <vector>

#include "DisjointSetUnion.hxx"


int main() {
    DisjointSetUnion<int> dsu({0,1,2,3,4,5}); // 创建一个有10个元素的并查集
    dsu.unionSets(0, 1);      // 合并元素0和1所在的集合
    dsu.unionSets(2, 3);      // 合并元素2和3所在的集合
    dsu.unionSets(1, 2);      // 合并元素1和2所在集合（此时0,1,2,3已在一个集合中）

    // 查看0和3是否属于同一集合
    if (dsu.find(0) == dsu.find(3)) {
        std::cout << "0 和 3 在同一个集合中." << std::endl;
    }
    else {
        std::cout << "0 和 3 不在同一个集合中." << std::endl;
    }

    using namespace std;
    vector<char> elements = { 'a', 'b', 'c', 'd', 'e', 'f', 'g' };
    DisjointSetUnion<char> dsu2(elements);

    dsu2.unionSets('a', 'b');
    dsu2.unionSets('c', 'd');
    dsu2.unionSets('b', 'c'); // 连接'b'和'c'，进而连接'a', 'b', 'c', 'd'

    if (dsu2.find('a') == dsu2.find('d')) {
        cout << "'a' 和 'd' 在同一个集合中." << endl;
    }
    else {
        cout << "'a' 和 'd' 不在同一个集合中." << endl;
    }
    auto t = dsu2.getAllSets();
    return 0;
}
