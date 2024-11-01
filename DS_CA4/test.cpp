/*
 * test
 *
 * @陳澤諒
 * @B12505047
 * @Department Engineering Science and Ocean Engineering
 * @Affiliation National Taiwan University
 */

#include <climits>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "Dictionary.h"
#include "Double.cpp"
#include "String.cpp"
//----------------------------------------------------------------
#include "CheckerBoard.cpp"
#include "CheckerBoard.h"
#include "Double.h"
#include "Entry.h"
#include "HashTableChained.cpp"
#include "HashTableChained.h"
#include "Integer.h"
#include "String.h"

using namespace std;

static Double randomDouble();
static String randomString();
static CheckerBoard* randomCheckerBoard();

template <typename K, typename V>
static void initTableDouble(HashTableChained<K, V>* table, int numBoards);
template <typename K, typename V>
static void initTableString(HashTableChained<K, V>* table, int numBoards);
template <typename K, typename V>
static void initTableCheckerBoard(HashTableChained<K, V>* table, int numBoards);

int main() {
    const int numBoards = 100;

    srand(time(NULL));

    cout << "--- table_double ---" << endl;
    HashTableChained<Double*, Integer*> table_double(numBoards);
    initTableDouble(&table_double, numBoards);
    table_double.printTable();
    cout << endl;

    cout << "--- table_string ---" << endl;
    HashTableChained<String*, Integer*> table_string(numBoards);
    initTableString(&table_string, numBoards);
    table_string.printTable();
    cout << endl;

    cout << "--- table_checkerboard ---" << endl;
    HashTableChained<CheckerBoard*, Integer*> table_checkerboard(numBoards);
    initTableCheckerBoard(&table_checkerboard, numBoards);
    table_checkerboard.printTable();
    cout << endl;
}

static Double randomDouble() { return Double(rand() / (double)RAND_MAX); }
static String randomString() {
    string s;

    for (int i = 0; i < 8; ++i) s += (char)('a' + rand() % 26);
    return String(s);
}
static CheckerBoard* randomCheckerBoard() {
    CheckerBoard* board;

    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            board->setElementAt(x, y, rand());
        }
    }
    return board;
}

template <typename K, typename V>
static void initTableDouble(HashTableChained<K, V>* table, int numBoards) {
    table->makeEmpty();
    for (int i = 0; i < numBoards; i++) {
        table->insert(new Double(randomDouble()), new Integer(i));
    }
}
template <typename K, typename V>
static void initTableString(HashTableChained<K, V>* table, int numBoards) {
    table->makeEmpty();
    for (int i = 0; i < numBoards; i++) {
        table->insert(new String(randomString()), new Integer(i));
    }
}
template <typename K, typename V>
static void initTableCheckerBoard(HashTableChained<K, V>* table, int numBoards) {
    table->makeEmpty();
    for (int i = 0; i < numBoards; i++) {
        table->insert(randomCheckerBoard(), new Integer(i));
    }
}
