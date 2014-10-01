#ifndef XSF_DSC_TEXTURE_HPP
#define XSF_DSC_TEXTURE_HPP

#include <string>
#include <functional>
#include <SFML/Graphics/Rect.hpp>

namespace sf {
    class Texture;
    class InputStream;
    class Image;
}

namespace xsf {
    namespace dsc {
        struct Texture {
            Texture();
            Texture(const char *, const sf::IntRect & = sf::IntRect());
            Texture(const std::string &, const sf::IntRect & = sf::IntRect());
            Texture(std::string &&, const sf::IntRect & = sf::IntRect());
            Texture(const void *, std::size_t, const sf::IntRect & = sf::IntRect());
            Texture(sf::InputStream &, const sf::IntRect & = sf::IntRect());
            Texture(const sf::Image &, const sf::IntRect & = sf::IntRect());
            bool load(sf::Texture &) const;
        private:
            std::function<bool(sf::Texture &)> fn;
        };
    }
}

#endif /* #ifndef XSF_DSC_TEXTURE_HPP */
