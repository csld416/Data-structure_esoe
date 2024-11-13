#include "BinaryTree.h"
using namespace std;

template <typename K, typename V>
BinaryTree<K, V>::BinaryTree() {
    makeEmpty();
}

/**
 *  Returns the number of entries stored in the dictionary.  Entries with
 *  the same key (or even the same key and value) each still count as
 *  a separate entry.
 *  @return number of entries in the dictionary.
 **/
template <typename K, typename V>
int BinaryTree<K, V>::size() {
    return tsize;
}

/**
 *  Tests if the dictionary is empty.
 *
 *  @return true if the dictionary has no entries; false otherwise.
 **/
template <typename K, typename V>
bool BinaryTree<K, V>::isEmpty() {
    return size() == 0;
}

template <typename K, typename V>
void BinaryTree<K, V>::insertHelper(Entry<K, V>* entry, const K& key, BinaryTreeNode<K, V>* node) {
    if (key.compareTo(node->entry->getkey()) <= 0) {
        if (node->leftChild == NULL) {
            node->leftChild = new BinaryTreeNode<K, V>(entry, node);
        } else {
            insertHelper(entry, key, node->leftChild);
        }
    } else {
        if (node->rightChild == NULL) {
            node->rightChild = new BinaryTreeNode<K, V>(entry, node);
        } else {
            insertHelper(entry, key, node->rightChild);
        }
    }
}

/**
 *  Create a new Entry object referencing the input key and associated value,
 *  and insert the entry into the dictionary.
 *  Multiple entries with the same key (or even the same key and
 *  value) can coexist in the dictionary.
 *
 *  @param key the key by which the entry can be retrieved.
 *  @param value an arbitrary object.
 **/
template <typename K, typename V>
void BinaryTree<K, V>::insert(const K& key, const V& value) {
    Entry<K, V>* entry = new Entry<K, V>(key, value);
    if (root == NULL) {
        root = new BinaryTreeNode<K, V>(entry);
    } else {
        insertHelper(entry, key, root);
    }
    tsize++;
}

/**
 *  Search for a node with the specified key, starting from "node".  If a
 *  matching key is found (meaning that key1.compareTo(key2) == 0), return
 *  a node containing that key.  Otherwise, return null.
 *
 *  Be sure this method returns null if node == null.
 **/
template <typename K, typename V>
BinaryTreeNode<K, V>* BinaryTree<K, V>::findHelper(const K& key, BinaryTreeNode<K, V>* node) {
    if (node == NULL) {
        return NULL;
    }
    if (key.compareTo(node->entry->getkey()) == 0) {
        return node;
    }
    BinaryTreeNode<K, V>* foundNode = findHelper(key, node->leftChild);
    if (foundNode != NULL) {
        return foundNode;
    }
    return findHelper(key, node->rightChild);
}

/**
 *  Search for an entry with the specified key.  If such an entry is found,
 *  return true; otherwise return false.
 *
 *  @param key the search key.
 *  @return an entry containing the key and an associated value, or null if
 *          no entry contains the specified key.
 **/
template <typename K, typename V>
Entry<K, V>* BinaryTree<K, V>::find(const K& key) {
    BinaryTreeNode<K, V>* node = findHelper(key, root);
    if (node != NULL) {
        return node->entry;
    } else {
        return NULL;
    }
}

/**
 *  Remove an entry with the specified key.  If such an entry is found,
 *  remove it from the table.
 *  If several entries have the specified key, choose one arbitrarily, then
 *  remove it.
 *
 *  @param key the search key.
 */
template <typename K, typename V>
void BinaryTree<K, V>::remove(const K& key) {
    root = removeHelper(key, root);
}

template <typename K, typename V>
BinaryTreeNode<K, V>* BinaryTree<K, V>::removeHelper(const K& key, BinaryTreeNode<K, V>* node) {
    if (node == nullptr) {
        return nullptr;
    }
    if (key.compareTo(node->entry->getkey()) < 0) {
        node->leftChild = removeHelper(key, node->leftChild);
    } else if (key.compareTo(node->entry->getkey()) > 0) {
        node->rightChild = removeHelper(key, node->rightChild);
    } else {
        if (node->leftChild != nullptr && node->rightChild != nullptr) {
            BinaryTreeNode<K, V>* minNode = findMin(node->rightChild);
            node->entry = new Entry<K, V>(minNode->entry->getkey(), minNode->entry->getvalue());
            node->rightChild = removeHelper(minNode->entry->getkey(), node->rightChild);
        } else {
            BinaryTreeNode<K, V>* child =
                (node->leftChild != nullptr) ? node->leftChild : node->rightChild;
            delete node->entry;
            node->entry = nullptr;
            delete node;
            node = nullptr;
            tsize--;
            return child;
        }
    }
    return node;
}

template <typename K, typename V>
BinaryTreeNode<K, V>* BinaryTree<K, V>::findMin(BinaryTreeNode<K, V>* node) {
    // Traverse to the leftmost node
    while (node->leftChild != nullptr) {
        node = node->leftChild;
    }
    return node;
}

/**
 *  Remove all entries from the dictionary.
 */
template <typename K, typename V>
void BinaryTree<K, V>::makeEmpty() {
    makeEmptyHelper(root);
    root = nullptr;
    tsize = 0;
}

template <typename K, typename V>
void BinaryTree<K, V>::makeEmptyHelper(BinaryTreeNode<K, V>* node) {
    if (node != nullptr) {
        makeEmptyHelper(node->leftChild);
        makeEmptyHelper(node->rightChild);
        delete node->entry;
        node->entry = nullptr;
        delete node;
    }
}

/**
 *  Convert the tree into a string.
 **/
template <typename K, typename V>
std::string BinaryTree<K, V>::toString() {
    if (root == NULL) {
        return "";
    } else {
        return root->toString();
    }
}
