/**
 *  BinaryTreeNode represents a node in a binary tree.
 *
 *  DO NOT CHANGE THIS FILE.
 **/

#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H

#include <string>

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
    BinaryTreeNode(Entry<K, V>* e);
    BinaryTreeNode(Entry<K, V>* e, BinaryTreeNode<K, V>* p);
    BinaryTreeNode(Entry<K, V>* e, BinaryTreeNode<K, V>* p, BinaryTreeNode<K, V>* l,
                   BinaryTreeNode<K, V>* r);
    ~BinaryTreeNode();
    std::string toString();
};

#endif
