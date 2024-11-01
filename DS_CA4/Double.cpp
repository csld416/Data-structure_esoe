/*
 *  A class that stores a variable of type double and generates a hash code for it.
 *
 * @陳澤諒
 * @B12505047
 * @Department Engineering Science and Ocean Engineering
 * @Affiliation National Taiwan University
 */

#include "Double.h"

#include <climits>
#include <cmath>
#include <functional>
using namespace std;
/**
 *  Construct a new Double with the given variable.
 *  @param d the double variable by which the Double stores.
 */
Double::Double(const double& d) { this->d = d; }

/**
 *  Get the value of the double variable.
 *  @return the stored value.
 */
double Double::getvalue() const { return d; }

/**
 *  Returns true if "this" Double and "db" have identical values.
 *  @param db is the second Double.
 *  @return true if the double values are equal, false otherwise.
 */
bool Double::equals(const Double& db) {
    double episilon = 1e-9;
    return fabs(this->d - db.d) < episilon;
}

/**
 *  Returns a hash code for this Double.
 *  @return a number between Integer.MIN_VALUE and Integer.MAX_VALUE.
 */
int Double::hashCode() const {
    hash<double> hashFunction;
    size_t hashValue = hashFunction(d);

    return static_cast<int>(hashValue % INT_MAX);
}
