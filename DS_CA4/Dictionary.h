/**
 *  An abstract class for (unordered) dictionary ADTs.
 *
 *  DO NOT CHANGE THIS FILE.
 **/

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "Entry.h"

template <typename K, typename V>
class Dictionary {
   public:
    virtual int size() = 0;
    virtual bool isEmpty() = 0;
    virtual void insert(const K& key, const V& value) = 0;
    virtual bool find(const K& key) = 0;
    virtual void remove(const K& key) = 0;
    virtual void makeEmpty() = 0;
};

#endif
