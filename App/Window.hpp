#pragma once

#include <SFML/Graphics.hpp>

namespace {  // Window statistics
const short kFieldAmount{9};
const short kDistance{5};
const short kCharacterSize{20};
}  // namespace

namespace {  // Window size
const uint kDesktopWidth{sf::VideoMode::getDesktopMode().width};

const uint kWindowWidth{static_cast<uint>(kDesktopWidth * 0.35)};
const uint kWindowHeight{static_cast<uint>(kDesktopWidth * 0.43)};

const float kFieldSize{(static_cast<float>(kWindowWidth) - 10.f) / 3};

const float kTurnWindowWidth{2.f * static_cast<float>(kWindowWidth) / 3};
const float kTurnWindowHeight{static_cast<float>(kWindowHeight) - 3 * (kFieldSize + kDistance) - kDistance};
}  // namespace

namespace {  // RGB Colors
const short kDefaultRed{59};
const short kDefaultGreen{59};
const short kDefaultBlue{59};
}  // namespace

namespace {  // Clear Button RGB Colors
const short kClearButtonRed{76};
const short kClearButtonGreen{76};
const short kClearButtonBlue{76};
}  // namespace

namespace {  // Game
const short kMinTurnForWin{5};
const short kMaxTurn{10};

}  // namespace

namespace Window {
void SetIcon(sf::RenderWindow& window);
}
