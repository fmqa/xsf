#ifndef XSF_LDR_IMAGE_HPP
#define XSF_LDR_IMAGE_HPP

#include "../dsc/Image.hpp"

namespace sf {
    class Image;
}

namespace xsf {
    namespace ldr {
        struct Image {
            using Descriptor = xsf::dsc::Image;
            bool load(const Descriptor &, sf::Image &) const;
        };
    }
}

#endif /* #ifndef XSF_LDR_IMAGE_HPP */

