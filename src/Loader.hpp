#ifndef XSF_LOADER_HPP
#define XSF_LOADER_HPP

namespace sf {
    class Texture;
    class Image;
}

namespace xsf {
    namespace ldr {
        struct Texture;
        struct Image;
    }
    
    template <typename> struct LoaderType;
    
    template <>
    struct LoaderType<sf::Texture> {
        using T = xsf::ldr::Texture;
    };
    
    template <>
    struct LoaderType<sf::Image> {
        using T = xsf::ldr::Image;
    };
    
    template <typename T>
    using Loader = typename LoaderType<T>::T;
}

#endif /* #ifndef XSF_LOADER_HPP */
