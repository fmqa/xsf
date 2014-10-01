#include "Node.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

xsf::Node::Node() : sf::Drawable(), sf::Transformable(), parent(), children() {}

void xsf::Node::attach(std::unique_ptr<Node> child) {
    child->parent = this;
    children.emplace(&*child, std::move(child));
}

std::unique_ptr<xsf::Node> xsf::Node::detach(const Node &node) {
    auto cursor = children.find(&node);
    if (cursor != children.end()) {
        std::unique_ptr<Node> detached = std::move(cursor->second);
        detached->parent = nullptr;
        children.erase(cursor);
        return detached;
    }
    return nullptr;
}

void xsf::Node::update(sf::Time dt) {
    updateNode(dt);
    for (const auto &child : children) {
        child.second->update(dt);
    }
}

void xsf::Node::send(const Message<void> &msg, sf::Time dt) {
    if (msg) {
        msg(*this, dt);
        for (const auto &child : children) {
            msg(*child.second, dt);
        }
    }
}

bool xsf::Node::send(const Message<bool> &msg, sf::Time dt) {
    if (msg && msg(*this, dt)) {
        for (const auto &child : children) {
            if (!msg(*child.second, dt)) {
                return false;
            }
        }
    }
    return static_cast<bool>(msg);
}

sf::Transform xsf::Node::wtransform() const {
    sf::Transform transform;
    
    for (const Node *cursor = this; cursor; cursor = cursor->parent) {
        transform = cursor->getTransform() * transform;
    }
    
    return transform;
}

void xsf::Node::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    drawNode(target, states);
    for (const auto &child : children) {
        child.second->draw(target, states);
    }
}
