#ifndef XSF_STACK_HPP
#define XSF_STACK_HPP

#include <memory>
#include <stack>
#include "State.hpp"

namespace xsf {
    struct Game;
    struct Stack {
        friend struct Game;
        void push(std::unique_ptr<State>);
        void pop();
        State& top() const;
        bool empty() const;
    private:
        Stack(sf::RenderTarget &);
        std::stack<std::unique_ptr<State>> states;
        sf::RenderTarget *target;
    };
}

#endif /* #ifndef XSF_STACK_HPP */
