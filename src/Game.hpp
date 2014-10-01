#ifndef XSF_GAME_HPP
#define XSF_GAME_HPP

#include <SFML/System/Time.hpp>
#include "Stack.hpp"

namespace sf {
    class RenderWindow;
}

namespace xsf {
    struct Game : private Stack {
        Game(sf::RenderWindow &, sf::Time);
        sf::RenderWindow& window();
        Stack& states();
        sf::Time tpf() const;
        void tpf(sf::Time);
        void process();
        void run();
    private:
        sf::Time timeperframe;
    };
}

#endif /* #ifndef XSF_GAME_HPP */
