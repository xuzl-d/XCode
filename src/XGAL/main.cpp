#include <iostream>
#include <vector>

#include "DisjointSetUnion.hxx"


int main() {
    DisjointSetUnion<int> dsu({0,1,2,3,4,5}); // ����һ����10��Ԫ�صĲ��鼯
    dsu.unionSets(0, 1);      // �ϲ�Ԫ��0��1���ڵļ���
    dsu.unionSets(2, 3);      // �ϲ�Ԫ��2��3���ڵļ���
    dsu.unionSets(1, 2);      // �ϲ�Ԫ��1��2���ڼ��ϣ���ʱ0,1,2,3����һ�������У�

    // �鿴0��3�Ƿ�����ͬһ����
    if (dsu.find(0) == dsu.find(3)) {
        std::cout << "0 �� 3 ��ͬһ��������." << std::endl;
    }
    else {
        std::cout << "0 �� 3 ����ͬһ��������." << std::endl;
    }

    using namespace std;
    vector<char> elements = { 'a', 'b', 'c', 'd', 'e', 'f', 'g' };
    DisjointSetUnion<char> dsu2(elements);

    dsu2.unionSets('a', 'b');
    dsu2.unionSets('c', 'd');
    dsu2.unionSets('b', 'c'); // ����'b'��'c'����������'a', 'b', 'c', 'd'

    if (dsu2.find('a') == dsu2.find('d')) {
        cout << "'a' �� 'd' ��ͬһ��������." << endl;
    }
    else {
        cout << "'a' �� 'd' ����ͬһ��������." << endl;
    }
    auto t = dsu2.getAllSets();
    return 0;
}
