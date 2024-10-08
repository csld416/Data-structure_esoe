/*
 * This file implements the `LockDListNode` class, which extends `DListNode` by adding a locking
 * mechanism. Locked nodes, once locked via `lock()`, cannot be removed or modified. The `locked()`
 * method checks the lock status. The class is templated to handle different data types, with
 * explicit instantiations for `int` and `std::string`.
 *
 * @陳澤諒
 * @B12505047
 * @Department Engineering Science and Ocean Engineering
 * @Affiliation National Taiwan University
 */

#include "LockDListNode.h"

// Constructor definition
template <typename T>
LockDListNode<T>::LockDListNode(const T& i, DListNode<T>* p, DListNode<T>* n)
    : DListNode<T>(i, p, n), isLocked(false) {
    // Call base class constructor and initialize isLocked
}

// Method to lock the node
template <typename T>
void LockDListNode<T>::lock() {
    isLocked = true;
}

// Method to check if the node is locked
template <typename T>
bool LockDListNode<T>::locked() const {
    return isLocked;
}

// Explicit template instantiations (you need to add types for T as needed)
template class LockDListNode<int>;
template class LockDListNode<std::string>;