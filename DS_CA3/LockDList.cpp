/*
 * This code defines the LockDList class, which extends the DList class by adding lockable
 * functionality to the doubly linked list nodes. The LockDList class overrides certain methods to
 * work with LockDListNode, a subclass of DListNode that includes the ability to lock nodes,
 * preventing them from being removed.
 *
 * @author      陳澤諒
 * @ID          B12505047
 * @Department  Engineering Science and Ocean Engineering
 * @Affiliation National Taiwan University
 */

#include "LockDList.h"

// Override newNode() to create LockDListNode instead of DListNode
template <typename T>
DListNode<T>* LockDList<T>::newNode(const T& item, DListNode<T>* prev, DListNode<T>* next) {
    return new LockDListNode<T>(item, prev, next);  // Use LockDListNode
}

// lockNode() casts DListNode to LockDListNode and locks it
template <typename T>
void LockDList<T>::lockNode(DListNode<T>* node) {
    LockDListNode<T>* lockNode = static_cast<LockDListNode<T>*>(node);
    if (lockNode) {
        lockNode->lock();
    }
}

// Override remove() to prevent removing locked nodes
template <typename T>
void LockDList<T>::remove(DListNode<T>* node) {
    LockDListNode<T>* lockNode = static_cast<LockDListNode<T>*>(node);

    // Only remove the node if it's not locked
    if (lockNode && !lockNode->locked()) {
        DList<T>::remove(node);  // Call base class remove if not locked
    }
    // Do nothing if the node is locked
}