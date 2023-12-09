#include "Player.h"

Player::Player() : health(100), currentLocation(nullptr) {}

int Player::GetHealth() const {
    return health;
}

void Player::TakeDamage(int damage) {
    health -= damage;
}

void Player::MoveToLocation(Location* location) {
    currentLocation = location;
}

void Player::AddItem(Item* item) {
    inventory.push_back(item);
}

const std::vector<Item*>& Player::GetInventory() const {
    return inventory;
}
