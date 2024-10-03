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
    virtual ~DListNode() {}
};

#endif
/**
 *  item references the item stored in the current node.
 *  prev references the previous node in the DList.
 *  next references the next node in the DList.
 *
 *  DO NOT CHANGE THE FOLLOWING FIELD DECLARATIONS.
 */
