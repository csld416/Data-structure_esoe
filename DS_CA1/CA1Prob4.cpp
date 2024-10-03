#include <iostream>

/*
 * The class provides a constructor for initializing these attributes,
 * along with getter and setter methods to access and modify the flower's properties.
 * @author      陳澤諒
 * @ID          B12505047
 * @Department  Engineering Science and Ocean Engineering
 * @Affiliation National Taiwan University
 */

using namespace std;

class flower {
   private:
    string name;
    int petal;
    double price;

   public:
    // Constructor.
    flower(string n, int pt, double pr) {
        name = n;
        petal = pt;
        price = pr;
    }
    // Set the name of the flower.
    void setName(string n) { this->name = n; }
    // Set the petal number of the flower.
    void setPetal(int pt) { this->petal = pt; }
    // Set the price of the flower.
    void setPrice(double pr) { this->price = pr; }
    // Return the name of the flower.
    string getName() { return this->name; }
    // Return the petal number of the flower.
    int getPetal() { return this->petal; }
    // Return the price of the flower.
    double getPrice() { return this->price; }
};