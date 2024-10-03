#include <cassert>
#include <iostream>

#include "DList.cpp"
#include "DList.h"
#include "DListNode.cpp"
#include "DListNode.h"
#include "LockDList.cpp"
#include "LockDList.h"
#include "LockDListNode.h"

int main() {
    cout << "========================" << endl;
    cout << "Part 2 Testing LockDList" << endl;
    cout << "========================" << endl;
    LockDList<int> ld1;
    ld1.insertFront(2);
    ld1.insertBack(3);
    ld1.insertAfter(5, ld1.next(ld1.front()));
    ld1.insertBefore(4, ld1.back());
    ld1.insertFront(1);
    ld1.toString();
    cout << "Lock the node 1 and the node 5." << endl;
    ld1.lockNode(ld1.back());
    ld1.lockNode(ld1.front());
    cout << "Remove all nodes." << endl;
    DListNode<int>* ld1backNode = ld1.back();
    int ld1length = ld1.length();
    for (int i = 0; i < ld1length; i++) {
        DListNode<int>* temp = ld1.prev(ld1backNode);
        ld1.remove(temp);
        temp = ld1backNode;
    }
    assert(ld1.front()->item == 1 && ld1.back()->item == 5);
    ld1.toString();
    return 0;
}