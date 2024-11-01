/*
 * A class that stores a string and generates a hash code for it.
 *
 * @陳澤諒
 * @B12505047
 * @Department Engineering Science and Ocean Engineering
 * @Affiliation National Taiwan University
 */
#include "String.h"

#include <climits>
#include <functional>
using namespace std;

/**
 *  Construct a new String with the given variable.
 *  @param str the string by which the String stores.
 */
String::String(const string& str) { this->str = str; }

/**
 *  Get the value of the string variable.
 *  @return the stored value.
 */
string String::getvalue() const { return str; }

/**
 *  Returns true if "this" String and "strg" have identical values.
 *  @param strg is the second String.
 *  @return true if the string values are equal, false otherwise.
 */
bool String::equals(const String& strg) { return str == strg.str; }

/**
 *  Returns a hash code for this String.
 *  @return a number between Integer.MIN_VALUE and Integer.MAX_VALUE.
 */
int String::hashCode() const {
    size_t hashValue = hash<string>{}(str);
    return static_cast<int>(hashValue % INT_MAX);
}
