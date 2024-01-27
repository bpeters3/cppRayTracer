#include "color.h"
#include "vec3.h"

#include <iostream>


int main(){

    // Image

    int image_width = 256;
    int image_height = 256;

    // Render

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for(size_t j{}; j<image_height; j++){
        for(size_t i{};i<image_width;i++){
            std::clog <<"\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
            auto pixel_color = color(double(i)/(image_width-1), double(j)/(image_height-1),0);
            write_color(std::cout, pixel_color);
        }
    }
    std::clog <<"\rDone.                     \n";
}