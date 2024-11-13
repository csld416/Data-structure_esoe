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
    findHelper(key, node->leftChild);
    findHelper(key, node->rightChild);
    return NULL;
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
    if (node == NULL) {
        return NULL;
    }

    // Locate the node to remove
    if (key.compareTo(node->entry->getkey()) < 0) {
        node->leftChild = removeHelper(key, node->leftChild);
    } else if (key.compareTo(node->entry->getkey()) > 0) {
        node->rightChild = removeHelper(key, node->rightChild);
    } else {
        // Node found
        if (node->leftChild == NULL && node->rightChild == NULL) {
            // Case 1: No children
            delete node;
            node = NULL;
        } else if (node->leftChild == NULL) {
            // Case 2: One child (right)
            BinaryTreeNode<K, V>* temp = node;
            node = node->rightChild;
            delete temp;
        } else if (node->rightChild == NULL) {
            // Case 2: One child (left)
            BinaryTreeNode<K, V>* temp = node;
            node = node->leftChild;
            delete temp;
        } else {
            // Case 3: Two children
            BinaryTreeNode<K, V>* temp = findMin(node->rightChild);
            node->entry = temp->entry;
            node->rightChild = removeHelper(temp->entry->getkey(), node->rightChild);
        }
    }
    return node;
}

template <typename K, typename V>
BinaryTreeNode<K, V>* BinaryTree<K, V>::findMin(BinaryTreeNode<K, V>* node) {
    while (node->leftChild != NULL) {
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
    root = NULL;
    tsize = 0;
}

template <typename K, typename V>
void BinaryTree<K, V>::makeEmptyHelper(BinaryTreeNode<K, V>* node) {
    if (node != NULL) {
        // Recursively delete left and right subtrees
        makeEmptyHelper(node->leftChild);
        makeEmptyHelper(node->rightChild);
        // Delete the current node
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
