#include "Game.hpp"
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

xsf::Game::Game(sf::RenderWindow &wnd, sf::Time timepf) : Stack(wnd), timeperframe(timepf) {}

sf::RenderWindow& xsf::Game::window() {
    return static_cast<sf::RenderWindow&>(*target);
}

xsf::Stack& xsf::Game::states() {
    return *this;
}

sf::Time xsf::Game::tpf() const {
    return timeperframe;
}

void xsf::Game::tpf(sf::Time value) {
    timeperframe = value;
}

void xsf::Game::process() {
    sf::Event event;
    while (window().pollEvent(event)) {
        top().handle(event);
    }
}

void xsf::Game::run() {
    sf::Clock clock;
    sf::Time lastupdt;
    
    while (window().isOpen()) {
        sf::Time dt = clock.restart();
        lastupdt += dt;
        while (lastupdt > timeperframe) {
            lastupdt -= timeperframe;
            process();
            top().update(timeperframe);
            if (empty()) {
                window().close();
            }
        }
    }
}
