#ifndef XSF_DSC_IMAGE_HPP
#define XSF_DSC_IMAGE_HPP

#include <string>
#include <functional>

namespace sf {
    class Image;
    class InputStream;
}

namespace xsf {
    namespace dsc {
        struct Image {
            Image();
            Image(const char *);
            Image(const std::string &);
            Image(std::string &&);
            Image(const void *, std::size_t);
            Image(sf::InputStream &);
            bool load(sf::Image &) const;
        private:
            std::function<bool(sf::Image &)> fn;
        };
    }
}

#endif /* #ifndef XSF_DSC_IMAGE_HPP */
