#ifndef IMAGE_H
#define IMAGE_H

#include <cstdint>
#include <vector>
#include "interval.h"

using std::vector;

struct pixel{
    int red{};
    int blue{};
    int green{};
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

    void write_pixel_next(const pixel& pix_write){
        image_file[image_h_idx][image_w_idx] = pix_write;
    }

    void write_pixel_idx(int width, int height, const pixel& pix_write){
        image_file[height][width] = pix_write;
    }

    void write_pixel_range(int h_low, int w_low, int h_high, int w_high,const pixel& pix_write){
        for(int j{h_low};j<h_high;j++){
            for(int i{w_low};i<w_high;i++){
                image_file[j][i].red    = pix_write.red;
                image_file[j][i].blue   = pix_write.blue;
                image_file[j][i].green  = pix_write.green;
            }
        }
    }

    pixel get_pixel_color(int width, int height){
        return image_file[height][width];
    }

    void output_image(std::ostream &out){
        
        std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

        for (int j = 0; j < image_height; ++j) {
            for (int i = 0; i < image_width; ++i) {
                out << image_file[j][i].red << ' '
                    << image_file[j][i].blue << ' '
                    << image_file[j][i].green << '\n';
            }
        }
    }
    private:
        int image_width;
        int image_height;
        int image_w_idx;
        int image_h_idx;
        vector<vector<pixel>> image_file;
};


#endif