/**
 *  BinaryTree implements a Dictionary as a binary tree (unbalanced).
 *
 *  DO NOT CHANGE ANY PROTOTYPES IN THIS FILE.
 **/
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "BinaryTreeNode.cpp"
#include "BinaryTreeNode.h"
#include "Dictionary.h"

template <typename K, typename V>
class BinaryTree : public Dictionary<K, V> {
   private:
    BinaryTreeNode<K, V>* removeHelper(const K& key, BinaryTreeNode<K, V>* node);
    BinaryTreeNode<K, V>* findMin(BinaryTreeNode<K, V>* node);
    void makeEmptyHelper(BinaryTreeNode<K, V>* node);
    /**
     *  size is the number of items stored in the dictionary.
     *  root is the BinaryTreeNode that serves as root of the tree.  If there
     *  are no items (size is zero), root is null.
     **/
   protected:
    int tsize;
    BinaryTreeNode<K, V>* root;

   public:
    BinaryTree();
    virtual int size();
    virtual bool isEmpty();
    virtual void insert(const K& key, const V& value);
    virtual Entry<K, V>* find(const K& key);
    virtual void remove(const K& key);
    virtual void makeEmpty();
    std::string toString();

   private:
    void insertHelper(Entry<K, V>* entry, const K& key, BinaryTreeNode<K, V>* node);
    BinaryTreeNode<K, V>* findHelper(const K& key, BinaryTreeNode<K, V>* node);
};

#endif
