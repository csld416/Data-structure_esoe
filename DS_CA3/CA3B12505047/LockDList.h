/*
 * This file defines the interface for the LockDList class, which extends the functionality
 * of the DList class by adding support for node locking.
 *
 * LockDList is a templated doubly-linked list that provides additional functionality to lock
 * individual nodes. Once a node is locked, it cannot be removed from the list, thus preventing
 * accidental modifications to critical data. This is achieved by overriding the base class
 * remove method to check for locked nodes.
 *
 * The class also overrides the newNode method to ensure that LockDListNode, an extended node
 * with lock capabilities, is used instead of the standard DListNode.
 *
 * Key functionalities of LockDList include:
 * - Locking a node to prevent its removal.
 * - Inserting and managing nodes as in a standard doubly-linked list.
 * - Ensuring locked nodes are not removed by overriding the remove method.
 *
 * This class inherits from DList, extending its behavior while maintaining compatibility
 * with standard doubly-linked list operations.
 *
 * @陳澤諒
 * @B12505047
 * @Department of Engineering Science and Ocean Engineering
 * @Affiliation National Taiwan University
 */

#ifndef LOCKDLIST_H
#define LOCKDLIST_H

#include "DList.h"
#include "LockDListNode.h"

// LockDList extends DList
template <typename T>
class LockDList : public DList<T> {
   protected:
    // Override newNode to use LockDListNode instead of DListNode
    virtual DListNode<T>* newNode(const T& item, DListNode<T>* prev, DListNode<T>* next) override;

   public:
    // Method to lock a node
    void lockNode(DListNode<T>* node);

    // Override remove to prevent removing locked nodes
    void remove(DListNode<T>* node);
};

#endif