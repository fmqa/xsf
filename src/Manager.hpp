#ifndef XSF_MANAGER_HPP
#define XSF_MANAGER_HPP

#include <unordered_map>
#include "Loader.hpp"

namespace xsf {
    template <typename Key, typename T, typename L = Loader<T>, typename M = std::unordered_map<Key,T>>
    struct Manager {
        using Descriptor = typename L::Descriptor;
        Manager();
        explicit Manager(const L &);
        explicit Manager(L &&);
        bool load(const Key &, const Descriptor &);
        bool loaded(const Key &) const;
        T& acquire(const Key &);
        const T& acquire(const Key &) const;
        bool release(const Key &);
        L& loader();
        const L& loader() const;
    private:
        struct Compressed : L {
            Compressed() = default;
            Compressed(const L &ldr) : L(ldr), mapping() {}
            Compressed(L &&ldr) : L(std::move(ldr)), mapping() {} 
            M mapping;
        };
        Compressed data;
    };
}

#endif /* #ifndef XSF_MANAGER_HPP */

#include "Manager.inl.hpp"
