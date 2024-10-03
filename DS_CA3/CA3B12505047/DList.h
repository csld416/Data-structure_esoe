/**
 *  A DList is a mutable doubly-linked list ADT.  Its implementation is
 *  circularly-linked and employs a sentinel (dummy) node at the head
 *  of the list.
 *
 *  DO NOT CHANGE ANY METHOD PROTOTYPES IN THIS FILE.
 */

#ifndef DLIST_H
#define DLIST_H

#include "DListNode.h"

template <typename T>
class DList {
    /**
     *  head references the sentinel node.
     *  size is the number of items in the list.  (The sentinel node does not store an item.)
     *  DO NOT CHANGE THE FOLLOWING FIELD DECLARATIONS.
     */
   protected:
    DListNode<T>* head;
    int size;
    virtual DListNode<T>* newNode(const T& item, DListNode<T>* prev, DListNode<T>* next);

   public:
    DList();
    bool isEmpty();
    int length();
    void insertFront(const T& item);

    void insertBack(const T& item);
    DListNode<T>* front();
    DListNode<T>* back();
    DListNode<T>* next(DListNode<T>* node);
    DListNode<T>* prev(DListNode<T>* node);
    void insertAfter(const T& item, DListNode<T>* node);
    void insertBefore(const T& item, DListNode<T>* node);
    void remove(DListNode<T>* node);
    void toString();
};

#endif
