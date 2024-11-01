/*
 *  HashTableChained extends a Dictionary as a hash table with chaining.
 *  All objects used as keys must have a valid hashCode() method, which is
 *  used to determine which bucket of the hash table an entry is stored in.
 *  Each object's hashCode() is presumed to return an int between
 *  Integer.MIN_VALUE and Integer.MAX_VALUE.  The HashTableChained class
 *  implements only the compression function, which maps the hash code to
 *  a bucket in the table's range.
 * @陳澤諒
 * @B12505047
 * @Department Engineering Science and Ocean Engineering
 * @Affiliation National Taiwan University
 */

#include "HashTableChained.h"
using namespace std;

/**
 *  Construct a new empty hash table intended to hold roughly sizeEstimate
 *  entries.  (The precise number of buckets is up to you, but we recommend
 *  you use a prime number, and shoot for a load factor between 0.5 and 1.)
 **/
template <typename K, typename V>
HashTableChained<K, V>::HashTableChained(int sizeEstimate) {
    int numBuckets = findNextPrime(sizeEstimate / 0.75);
    buckets.resize(numBuckets);
    SlotSize = numBuckets;
    EntryCount = 0;
}

/**
 *  Construct a new empty hash table with a default size.  Say, a prime in
 *  the neighborhood of 100.
 **/
template <typename K, typename V>
HashTableChained<K, V>::HashTableChained() {
    int numBuckets = findNextPrime(100);
    buckets.resize(numBuckets);
    SlotSize = numBuckets;
    EntryCount = 0;
}

/**
 *  Converts a hash code in the range Integer.MIN_VALUE...Integer.MAX_VALUE
 *  to a value in the range 0...(size of hash table) - 1.
 *
 *  This function should have package protection (so we can test it), and
 *  should be used by insert, find, and remove.
 **/
template <typename K, typename V>
int HashTableChained<K, V>::compFunction(int code) {
    const int a = 31;
    const int b = 17;
    const int p = 10007;
    int N = buckets.size();
    return abs((a * code + b) % p) % N;
}

/**
 *  Returns the number of entries stored in the dictionary.  Entries with
 *  the same key (or even the same key and value) each still count as
 *  a separate entry.
 *  @return number of entries in the dictionary.
 **/
template <typename K, typename V>
int HashTableChained<K, V>::size() {
    return EntryCount;
}

/**
 *  Tests if the dictionary is empty.
 *
 *  @return true if the dictionary has no entries; false otherwise.
 **/
template <typename K, typename V>
bool HashTableChained<K, V>::isEmpty() {
    return EntryCount == 0;
}

/**
 *  Create a new Entry object referencing the input key and associated value,
 *  and insert the entry into the dictionary.
 *  Multiple entries with the same key (or even the same key and
 *  value) can coexist in the dictionary.
 *
 *  This method should run in O(1) time if the number of collisions is small.
 *
 *  @param key the key by which the entry can be retrieved.
 *  @param value an arbitrary object.
 **/
template <typename K, typename V>
void HashTableChained<K, V>::insert(const K& key, const V& value) {
    int bucketidx = compFunction(key->hashCode());
    ListNode* curr = buckets[bucketidx];
    ListNode* newNode = new ListNode(key, value, nullptr);

    newNode->next = curr;
    buckets[bucketidx] = newNode;

    EntryCount++;
    return;
}

/**
 *  Search for an entry with the specified key.  If such an entry is found,
 *  return true; otherwise return false.
 *
 *  This method should run in O(1) time if the number of collisions is small.
 *
 *  @param key the search key.
 *  @return true if an entry containing the key is found, or false if
 *          no entry contains the specified key.
 **/
template <typename K, typename V>
bool HashTableChained<K, V>::find(const K& key) {
    int bucketidx = compFunction(key->hashCode());
    ListNode* curr = buckets[bucketidx];

    while (curr) {
        if constexpr (is_pointer_v<K>) {
            // If K is a pointer, use value comparison
            if (curr->pair.getkey() && key && curr->pair.getkey()->equals(*key)) {
                return true;
            }
        } else {
            // If K is not a pointer, use direct comparison
            if (curr->pair.getkey() == key) {
                return true;
            }
        }
        curr = curr->next;
    }
    return false;
}

/**
 *  Remove an entry with the specified key.  If such an entry is found,
 *  remove it from the table.
 *  If several entries have the specified key, choose one arbitrarily, then
 *  remove it.
 *
 *  This method should run in O(1) time if the number of collisions is small.
 *
 *  @param key the search key.
 */
template <typename K, typename V>
void HashTableChained<K, V>::remove(const K& key) {
    int bucketidx = compFunction(key->hashCode());

    ListNode* curr = buckets[bucketidx];
    ListNode* prev = nullptr;

    while (curr) {
        if (curr->pair.getkey()->equals(*key)) {
            if (prev == nullptr) {
                buckets[bucketidx] = curr->next;
            } else {
                prev->next = curr->next;
            }
            delete curr;
            EntryCount--;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

/**
 *  Remove all entries from the dictionary.
 */
template <typename K, typename V>
void HashTableChained<K, V>::makeEmpty() {
    for (ListNode*& head : buckets) {
        // Traverse and delete each node in the linked list
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }
    EntryCount = 0;
}
