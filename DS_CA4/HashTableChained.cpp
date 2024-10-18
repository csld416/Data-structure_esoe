/**
 *  HashTableChained extends a Dictionary as a hash table with chaining.
 *  All objects used as keys must have a valid hashCode() method, which is
 *  used to determine which bucket of the hash table an entry is stored in.
 *  Each object's hashCode() is presumed to return an int between
 *  Integer.MIN_VALUE and Integer.MAX_VALUE.  The HashTableChained class
 *  implements only the compression function, which maps the hash code to
 *  a bucket in the table's range.
 *
 **/

#include "HashTableChained.h"
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int findNextPrime(int n) {
    while (!isPrime(n)) {
        ++n;
    }
    return n;
}

/**
 *  Construct a new empty hash table intended to hold roughly sizeEstimate
 *  entries.  (The precise number of buckets is up to you, but we recommend
 *  you use a prime number, and shoot for a load factor between 0.5 and 1.)
 **/
template <typename K, typename V>
HashTableChained<K, V>::HashTableChained(int sizeEstimate) {
    int numBuckets = findNextPrime(sizeEstimate / 0.75);
    buckets.resize(numBuckets);
    size = 0;
}

/**
 *  Construct a new empty hash table with a default size.  Say, a prime in
 *  the neighborhood of 100.
 **/
template <typename K, typename V>
HashTableChained<K, V>::HashTableChained() {
    int numBuckets = findNextPrime(100);
    buckets.resize(numBuckets);
    size = 0;
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
    return abs((a * hashCode + b) % p) % N;
}

/**
 *  Returns the number of entries stored in the dictionary.  Entries with
 *  the same key (or even the same key and value) each still count as
 *  a separate entry.
 *  @return number of entries in the dictionary.
 **/
template <typename K, typename V>
int HashTableChained<K, V>::size() {
    return size;
}

/**
 *  Tests if the dictionary is empty.
 *
 *  @return true if the dictionary has no entries; false otherwise.
 **/
template <typename K, typename V>
bool HashTableChained<K, V>::isEmpty() {
    return this->size == 0;
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
    hash<K> hasher;
    int hashCode = hasher(key);
    int bucketidx = compFunction(hashCode);
    auto& bucket = buckets[bucketidx];
    bucket.push_back(make_pair(key, value));
    this->size++;
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
    hash<K> hasher;
    int hashCode = hasher(key);
    int bucketidx = compFunction(hashCode);
    const auto& bucket = buckets[bucketidx];
    for (const auto& entry : bucket) {
        if (entry.first == key) {
            return true;
        }
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
    hash<K> hasher;
    int hashCode = hasher(key);
    int bucketidx = compFunction(hashCode);
    auto& bucket = buckets[bucketidx];
    for (auto it = bucket.begin(); it != bucket.end(); it++) {
        if (it->first == key) {
            bucket.erase(it);
            this->size--;
            return;
        }
    }
}

/**
 *  Remove all entries from the dictionary.
 */
template <typename K, typename V>
void HashTableChained<K, V>::makeEmpty() {
    for (int i = 0; i < buckets.size(); i++) {
        buckets[i].clear();
    }
    this->size = 0;
}
