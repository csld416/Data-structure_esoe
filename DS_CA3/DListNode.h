/*
 * This file defines the structure and implementation of a templated doubly-linked list node
 * (DListNode).
 *
 * The DListNode class is a component of the DList (Doubly Linked List) class and is used to store
 * individual elements in the list. Each node contains three main fields:
 *
 * - `item`: The data stored in the node.
 * - `prev`: A pointer to the previous node in the list.
 * - `next`: A pointer to the next node in the list.
 *
 * The DListNode class is templated to allow for flexibility, enabling it to store any data type.
 * It is designed to be used within the DList class, with DList declared as a friend class
 * to allow it access to the node’s private and protected members.
 *
 * Note: The node construction allows specifying the item to store and the pointers to the previous
 * and next nodes, thus facilitating the linking of nodes in the doubly-linked list.
 *
 * @陳澤諒
 * @B12505047
 * @Department of Engineering Science and Ocean Engineering
 * @Affiliation National Taiwan University
 */
#ifndef DLISTNODE_H
#define DLISTNODE_H

template <typename T>
class DList;

template <typename T>
class DListNode {
   protected:
    DListNode<T>* prev;
    DListNode<T>* next;
    friend class DList<T>;

   public:
    T item;
    DListNode(const T& i, DListNode<T>* p, DListNode<T>* n);
    /**
     *  @param i the item to store in the node.
     *  @param p the node previous to this node.
     *  @param n the node following this node.
     */
};

#endif
/**
 *  item references the item stored in the current node.
 *  prev references the previous node in the DList.
 *  next references the next node in the DList.
 *
 *  DO NOT CHANGE THE FOLLOWING FIELD DECLARATIONS.
 */
