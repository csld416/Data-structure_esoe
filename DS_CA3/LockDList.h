/*
 * This file defines the `LockDList` class, extending `DList` by adding node locking functionality.
 * Locked nodes cannot be removed, and `LockDListNode` is used for node creation via `newNode()`.
 * The `remove()` method is overridden to prevent removal of locked nodes.
 *
 * @author      陳澤諒
 * @ID          B12505047
 * @Department  Engineering Science and Ocean Engineering
 * @Affiliation National Taiwan University
 */

#ifndef LOCKDLIST_H
#define LOCKDLIST_H

#include <string>

#include "DList.h"
#include "LockDListNode.h"

using namespace std;

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