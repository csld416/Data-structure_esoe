#ifndef LOCKDLIST_H
#define LOCKDLIST_H

#include "DList.h"
#include "LockDListNode.h"

// LockDList extends DList
template <typename T>
class LockDList : public DList<T> {
   protected:
    // Override newNode to use LockDListNode instead of DListNode
    virtual DListNode<T>* newNode(const T& item, DListNode<T>* prev, DListNode<T>* next);

   public:
    // Method to lock a node
    void lockNode(DListNode<T>* node);

    // Override remove to prevent removing locked nodes
    void remove(DListNode<T>* node);
};

#endif