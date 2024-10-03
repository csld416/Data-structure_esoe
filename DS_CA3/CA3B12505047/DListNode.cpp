/*
 * This is the constructor for the DListNode class. It initializes a node in a doubly linked list
 * by setting the item it stores, the pointer to the previous node, and the pointer to the next
 * node.
 *
 * @author      陳澤諒
 * @ID          B12505047
 * @Department  Engineering Science and Ocean Engineering
 * @Affiliation National Taiwan University
 */

#include "DListNode.h"

template <typename T>
DListNode<T>::DListNode(const T& i, DListNode<T>* p, DListNode<T>* n) {
    item = i;
    prev = p;
    next = n;
}
/**
 *  @param i the item to store in the node.
 *  @param p the node previous to this node.
 *  @param n the node following this node.
 */