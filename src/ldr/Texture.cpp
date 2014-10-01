#include "Texture.hpp"
#include "../dsc/Texture.hpp"

bool xsf::ldr::Texture::load(const Descriptor &dsc, sf::Texture &texture) const {
    return dsc.load(texture);
}
