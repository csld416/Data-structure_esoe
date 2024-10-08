/*
 * This file defines the structure and implementation of a templated doubly-linked list node
 * (DListNode).
 *
 * The DListNode class is a component of the DList (Doubly Linked List) class and is used to store
 * individual elements in the list. Each node contains three main fields:
 *
 * @author      陳澤諒
 * @ID          B12505047
 * @Department  Engineering Science and Ocean Engineering
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
    virtual ~DListNode() {};
};

#endif
/**
 *  item references the item stored in the current node.
 *  prev references the previous node in the DList.
 *  next references the next node in the DList.
 *
 *  DO NOT CHANGE THE FOLLOWING FIELD DECLARATIONS.
 */
