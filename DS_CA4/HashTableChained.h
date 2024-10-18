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
    vector<list<pair<K, V>>> buckets;
    int size;

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
};

#endif
