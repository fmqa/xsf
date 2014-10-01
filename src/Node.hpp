#ifndef XSF_NODE_HPP
#define XSF_NODE_HPP

#include <memory>
#include <unordered_map>
#include <functional>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderStates.hpp>

namespace sf {
    class RenderTarget;
}

namespace xsf {
    struct Node : sf::Drawable, sf::Transformable {
        template <typename T> 
        using Message = std::function<T(Node &, sf::Time)>;
        Node();
        void attach(std::unique_ptr<Node>);
        std::unique_ptr<Node> detach(const Node &);
        void update(sf::Time);
        void send(const Message<void> &, sf::Time);
        bool send(const Message<bool> &, sf::Time);
        sf::Transform wtransform() const;
    private:
        virtual void updateNode(sf::Time) = 0;
        virtual void drawNode(sf::RenderTarget &, sf::RenderStates) const = 0;
        void draw(sf::RenderTarget &, sf::RenderStates) const final override;
        Node *parent;
        std::unordered_map<const Node *,std::unique_ptr<Node>> children;
    };
}

#endif /* #ifndef XSF_NODE_HPP */
