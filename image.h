#ifndef IMAGE_H
#define IMAGE_H

#include <cstdint>
#include <vector>
#include "interval.h"

using std::vector;

struct pixel{
    uint8_t red{};
    uint8_t blue{};
    uint8_t green{};
};

class image{
    public:
    image(int _image_width, int _image_height)
    : image_width{_image_width}, image_height{_image_height}, image_w_idx{}, image_h_idx{} {
        vector<pixel> temp;
        for(int j{};j<image_height;j++){
            for(int i{};i<image_width;i++){
                temp.push_back({0,0,0});
            }
            image_file.push_back(temp);
            temp.clear();
        }
    }

    void write_pixel_next(const uint8_t& red, const uint8_t& blue, const uint8_t& green){
        image_file[image_h_idx][image_w_idx] = {red,blue,green};
    }

    void write_pixel_range(int h_low, int w_low, int h_high, int w_high,const uint8_t& red, const uint8_t& blue, const uint8_t& green){
        for(int j{h_low};j<h_high;j++){
            for(int i{w_low};i<w_high;i++){
                image_file[j][i].red    = red;
                image_file[j][i].blue   = blue;
                image_file[j][i].green  = green;
            }
        }
    }

    pixel get_pixel_color(int width, int height){
        return image_file[height][width];
    }

    private:
        int image_width;
        int image_height;
        int image_w_idx;
        int image_h_idx;
        vector<vector<pixel>> image_file;
};


#endif