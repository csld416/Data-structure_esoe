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
        : DListNode<T>(i, p, n),
          isLocked(false) {  // Call base class constructor and initialize isLocked
    }

    // Lock the node
    void lock() { isLocked = true; }

    // Check if the node is locked
    bool locked() const { return isLocked; }
};

#endif