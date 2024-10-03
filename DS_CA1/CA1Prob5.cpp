#include <iostream>

/*
 * The class provides methods for setting and getting these attributes, while automatically
 * calculating the perimeter and area whenever the dimensions are modified.
 *
 * @author      陳澤諒
 * @ID          B12505047
 * @Department  Engineering Science and Ocean Engineering
 * @Affiliation National Taiwan University
 */

using namespace std;

class rectangle {
   private:
    double width;
    double length;
    double perimeter;
    double area;

    // Private method to update perimeter and area whenever width or length changes.
    void updatePerimeterAndArea() {
        perimeter = 2 * (width + length);
        area = width * length;
    }

   public:
    // Constructor, automatically compute the perimeter and area once it is initialized.
    rectangle(double wd, double lg) : width(wd), length(lg) { updatePerimeterAndArea(); }

    // Set the dimensions and automatically update the perimeter and area.
    void setDimension(double wd, double lg) {
        width = wd;
        length = lg;
        updatePerimeterAndArea();
    }

    // Set the width and automatically update the perimeter and area.
    void setWidth(double wd) {
        width = wd;
        updatePerimeterAndArea();
    }

    // Set the length and automatically update the perimeter and area.
    void setLength(double lg) {
        length = lg;
        updatePerimeterAndArea();
    }

    // Return the width of the rectangle.
    double getWidth() { return width; }

    // Return the length of the rectangle.
    double getLength() { return length; }

    // Return the perimeter of the rectangle.
    double getPerimeter() { return perimeter; }

    // Return the area of the rectangle.
    double getArea() { return area; }

    // True, if width = length.
    bool isSquare() { return width == length; }
};