/*
 * This file defines the LockDListNode class, which extends the functionality of the standard
 * DListNode by adding a locking mechanism to prevent certain nodes from being modified or removed.
 *
 * LockDListNode is a templated class that inherits from DListNode and adds a boolean field,
 * `isLocked`, to track whether a node is locked. If a node is locked, it cannot be removed from the
 * list, as this lock status is used by the LockDList class to safeguard nodes.
 *
 * Key functionalities of LockDListNode include:
 * - Locking a node to prevent modifications.
 * - Checking whether a node is locked.
 *
 * The class also includes a constructor that initializes the node's item and links to previous
 * and next nodes, as well as a method to lock the node.
 *
 * This class is intended to be used with LockDList, providing extended node capabilities
 * within a doubly-linked list.
 *
 * @陳澤諒
 * @B12505047
 * @Department of Engineering Science and Ocean Engineering
 * @Affiliation National Taiwan University
 */
#ifndef LOCKDLISTNODE_H
#define LOCKDLISTNODE_H

#include "DListNode.h"  // Include DListNode for inheritance

// LockDListNode extends DListNode
template <typename T>
class LockDListNode : public DListNode<T> {
   protected:
    bool isLocked;  // Indicates if the node is locked

   public:
    // Constructor declaration and definition all in one place
    LockDListNode(const T& i, DListNode<T>* p, DListNode<T>* n)
        : DListNode<T>(i, p, n), isLocked(false) {
        // Call base class constructor and initialize isLocked
    }

    // Lock the node
    void lock() { isLocked = true; }

    // Check if the node is locked
    bool locked() const { return isLocked; }
};

#endif