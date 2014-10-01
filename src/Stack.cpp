#include "Stack.hpp"

xsf::Stack::Stack(sf::RenderTarget &tgt) : target(&tgt) {}

void xsf::Stack::push(std::unique_ptr<State> state) {
    states.push(std::move(state));
    top().activate(*this, *target);
}

void xsf::Stack::pop() {
    top().deactivate();
    states.pop();
}

xsf::State& xsf::Stack::top() const {
    return *states.top();
}

bool xsf::Stack::empty() const {
    return states.empty();
}
