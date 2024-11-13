/**
 *  BinaryTreeNode represents a node in a binary tree.
 *
 *  DO NOT CHANGE THIS FILE.
 **/

#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include "Entry.h"

template <typename K, typename V>
class BinaryTreeNode {
    /**
     *  entry is the key/value pair stored in this node.
     *  parent is the parent of this node.
     *  leftChild and rightChild are the children of this node.
     **/
   protected:
   public:
    Entry<K, V>* entry;
    BinaryTreeNode<K, V>* parent;
    BinaryTreeNode<K, V>* leftChild;
    BinaryTreeNode<K, V>* rightChild;
    BinaryTreeNode(Entry<K, V>* e) : entry(e), parent(NULL), leftChild(NULL), rightChild(NULL) {}

    BinaryTreeNode(Entry<K, V>* e, BinaryTreeNode<K, V>* p)
        : entry(e), parent(p), leftChild(NULL), rightChild(NULL) {}

    BinaryTreeNode(Entry<K, V>* e, BinaryTreeNode<K, V>* p, BinaryTreeNode<K, V>* l,
                   BinaryTreeNode<K, V>* r)
        : entry(e), parent(p), leftChild(l), rightChild(r) {}

    ~BinaryTreeNode() { delete entry; }

    string toString() {
        stringstream ss;
        string str;
        if (this->leftChild != NULL) {
            ss << '(' << this->leftChild->toString() << ')';
        }
        ss << entry->getkey().getvalue() << entry->getvalue().getvalue();
        if (rightChild != NULL) {
            ss << '(' << this->rightChild->toString() << ')';
        }
        ss >> str;
        return str;
    }
};

#endif
