#ifndef XSF_STATE_HPP
#define XSF_STATE_HPP

#include <SFML/System/Time.hpp>

namespace sf {
    class Event;
    class RenderTarget;
}

namespace xsf {
    struct Stack;
    struct State {
        virtual void handle(const sf::Event &) = 0;
        virtual void update(sf::Time) = 0;
        virtual void render(sf::RenderTarget &) const = 0;
        virtual void activate(Stack &, sf::RenderTarget &);
        virtual void deactivate();
        virtual ~State() = 0;
    }; 
}
    
#endif /* #ifndef XSF_STATE_HPP */
