#include "Image.hpp"
#include <SFML/Graphics/Image.hpp>

xsf::dsc::Image::Image() = default;

xsf::dsc::Image::Image(const char *cstr)
    : fn(std::bind(&sf::Image::loadFromFile, std::placeholders::_1, cstr)) {}

xsf::dsc::Image::Image(const std::string &str)
    : fn(std::bind(&sf::Image::loadFromFile, std::placeholders::_1, str)) {}
    
xsf::dsc::Image::Image(std::string &&str)
    : fn(std::bind(&sf::Image::loadFromFile, std::placeholders::_1, std::move(str))) {}
    
xsf::dsc::Image::Image(const void *ptr, std::size_t n)
    : fn(std::bind(&sf::Image::loadFromMemory, std::placeholders::_1, ptr, n)) {}
    
xsf::dsc::Image::Image(sf::InputStream &stream)
    : fn(std::bind(&sf::Image::loadFromStream, std::placeholders::_1, std::ref(stream))) {}

bool xsf::dsc::Image::load(sf::Image &image) const {
    return fn && fn(image);
}

