#include "Image.hpp"

bool xsf::ldr::Image::load(const Descriptor &dsc, sf::Image &img) const {
    return dsc.load(img);
}

