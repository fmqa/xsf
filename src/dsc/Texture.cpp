#include "Texture.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/InputStream.hpp>

xsf::dsc::Texture::Texture() = default;

xsf::dsc::Texture::Texture(const char *cstr, const sf::IntRect &rectangle) 
    : fn(std::bind(&sf::Texture::loadFromFile, std::placeholders::_1, cstr, rectangle)) {}

xsf::dsc::Texture::Texture(const std::string &str, const sf::IntRect &rectangle) 
    : fn(std::bind(&sf::Texture::loadFromFile, std::placeholders::_1, str, rectangle)) {}
    
xsf::dsc::Texture::Texture(std::string &&str, const sf::IntRect &rectangle) 
    : fn(std::bind(&sf::Texture::loadFromFile, std::placeholders::_1, std::move(str), rectangle)) {}
    
xsf::dsc::Texture::Texture(const void *ptr, std::size_t n, const sf::IntRect &rectangle)
    : fn(std::bind(&sf::Texture::loadFromMemory, std::placeholders::_1, ptr, n, rectangle)) {}

xsf::dsc::Texture::Texture(sf::InputStream &stream, const sf::IntRect &rectangle)
    : fn(std::bind(&sf::Texture::loadFromStream, std::placeholders::_1, std::ref(stream), rectangle)) {}
    
xsf::dsc::Texture::Texture(const sf::Image &img, const sf::IntRect &rectangle)
    : fn(std::bind(&sf::Texture::loadFromImage, std::placeholders::_1, std::cref(img), rectangle)) {}

bool xsf::dsc::Texture::load(sf::Texture &texture) const {
    return fn && fn(texture);
}
