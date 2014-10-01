#ifndef XSF_LDR_TEXTURE_HPP
#define XSF_LDR_TEXTURE_HPP

#include "../dsc/Texture.hpp"

namespace sf {
    class Texture;
}

namespace xsf {
    namespace ldr {
        struct Texture {
            using Descriptor = xsf::dsc::Texture;
            bool load(const Descriptor &, sf::Texture &) const;
        };
    };
}

#endif /* #ifndef XSF_LDR_TEXTURE_HPP */

