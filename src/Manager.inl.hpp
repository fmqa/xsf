#ifndef XSF_MANAGER_INL_HPP
#define XSF_MANAGER_INL_HPP

namespace xsf {
    template <typename Key, typename T, typename L, typename M>
    Manager<Key,T,L,M>::Manager() = default;
    
    template <typename Key, typename T, typename L, typename M>
    Manager<Key,T,L,M>::Manager(const L &ldr) : data(ldr) {}
    
    template <typename Key, typename T, typename L, typename M>
    Manager<Key,T,L,M>::Manager(L &&ldr) : data(std::move(ldr)) {}
    
    template <typename Key, typename T, typename L, typename M>
    bool Manager<Key,T,L,M>::load(const Key &key, const Descriptor &desc) {
        T asset;
        if (loader().load(desc, asset)) {
            data.mapping[key] = std::move(asset);
            return true;
        }
        return false;
    }
    
    template <typename Key, typename T, typename L, typename M>
    bool Manager<Key,T,L,M>::loaded(const Key &key) const {
        return data.mapping.count(key);
    }
    
    template <typename Key, typename T, typename L, typename M>
    T& Manager<Key,T,L,M>::acquire(const Key &key) {
        return data.mapping.find(key)->second;
    }
    
    template <typename Key, typename T, typename L, typename M>
    const T& Manager<Key,T,L,M>::acquire(const Key &key) const {
        return data.mapping[key];
    }
    
    template <typename Key, typename T, typename L, typename M>
    bool Manager<Key,T,L,M>::release(const Key &key) {
        typename M::iterator cursor = data.mapping.find(key);
        
        if (cursor == data.mapping.end()) {
            return false;
        }
        
        data.mapping.erase(cursor);
        return true;
    }
    
    template <typename Key, typename T, typename L, typename M>
    L& Manager<Key,T,L,M>::loader() {
        return data;
    }
    
    template <typename Key, typename T, typename L, typename M>
    const L& Manager<Key,T,L,M>::loader() const {
        return data;
    }
}

#endif /* #ifndef XSF_MANAGER_INL_HPP */
