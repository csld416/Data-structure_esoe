/**
 *  HashTableChained extends a Dictionary as a hash table with chaining.
 *  All objects used as keys must have a valid hashCode() method, which is
 *  used to determine which bucket of the hash table an entry is stored in.
 *  Each object's hashCode() is presumed to return an int between
 *  Integer.MIN_VALUE and Integer.MAX_VALUE.  The HashTableChained class
 *  implements only the compression function, which maps the hash code to
 *  a bucket in the table's range.
 *
 *  DO NOT CHANGE ANY PROTOTYPES IN THIS FILE.
 **/

#ifndef HASHTABLECHAINED_H
#define HASHTABLECHAINED_H

#include <list>
#include <vector>

#include "Dictionary.h"

using namespace std;

template <typename K, typename V>
class HashTableChained : public Dictionary<K, V> {
   private:
    int SlotSize;
    int EntryCount;
    class ListNode {
       public:
        Entry<K, V> pair;
        ListNode* next;

        ListNode(const K& key, const V& value, ListNode* nextNode = nullptr)
            : pair(key, value), next(nextNode) {}
    };

    vector<ListNode*> buckets;

   public:
    HashTableChained(int sizeEstimate);
    HashTableChained();
    int compFunction(int code);
    virtual int size();
    virtual bool isEmpty();
    virtual void insert(const K& key, const V& value);
    virtual bool find(const K& key);
    virtual void remove(const K& key);
    virtual void makeEmpty();
    void printTable() const {
        for (size_t i = 0; i < buckets.size(); i++) {
            ListNode* current = buckets[i];

            // Skip the bucket if it is empty
            if (!current) {
                continue;
            }

            // Print the bucket index followed by entries
            std::cout << "Bucket " << i << ": ";
            while (current) {
                std::cout << "<" << current->pair.getkey() << ", " << current->pair.getvalue()
                          << ">";
                if (current->next) {
                    std::cout << " -> ";
                }
                current = current->next;
            }
            std::cout << std::endl;
        }
    }
};

#endif
