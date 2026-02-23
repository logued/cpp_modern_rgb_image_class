#include <iostream>
#include "Image.h"

int main() {
    std::cout << "Image class manipulation" << std::endl;

    Image image1(30,20);
    // create an Image object, with allocated memory for image pixel data
    // note that when the data vector (of RGB structs) is created,
    // the elements in the vector are not initialized (saving time).

    // assign some specific values to particular pixels
    image1.at(0,0) = RGB(255,255,255);
    std::cout << "Red pixel value: " << static_cast<int>(image1.at(1,1).r) << std::endl;

    // image1.at(0,1) = RGB(255,0,0);
    //

    //image1.at(666,2) = RGB(0,255,0);

     for (auto iter =  image1.begin(); iter != image1.end(); iter++) {
         std::cout << static_cast<int>(iter->r) << " "
                    << static_cast<int>(iter->g) << " "
                    << static_cast<int>(iter->b) << ", ";
     }

    return 0;
}
