/*
 * LockDListNode is a templated class that inherits from DListNode and adds a boolean field,
 * `isLocked`, to track whether a node is locked. If a node is locked, it cannot be removed from the
 * list, as this lock status is used by the LockDList class to safeguard nodes.
 *
 * @author      陳澤諒
 * @ID          B12505047
 * @Department  Engineering Science and Ocean Engineering
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
    // Constructor declaration
    LockDListNode(const T& i, DListNode<T>* p, DListNode<T>* n);

    // Lock the node
    void lock();

    // Check if the node is locked
    bool locked() const;
};

#endif  // LOCKDLISTNODE_H