/*
 * This file defines the interface for a templated doubly-linked list (DList) class.
 * The DList class represents a circular doubly-linked list that employs a sentinel node.
 * The sentinel node simplifies list operations by removing the need to handle edge cases
 * for empty lists, insertions at the front or back, and deletions of the first or last elements.
 *
 * The class is designed for extensibility and can be inherited to add additional functionality.
 *
 * @author      陳澤諒
 * @ID          B12505047
 * @Department  Engineering Science and Ocean Engineering
 * @Affiliation National Taiwan University
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