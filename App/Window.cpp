#include "Window.hpp"

namespace Window {
void SetIcon(sf::RenderWindow& window) {
    sf::Image icon;

    if (!icon.loadFromFile("../WindowFiles/Icon.png")) {
        throw std::runtime_error("Icon image could not be found");
    }

    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}
}  // namespace Window
