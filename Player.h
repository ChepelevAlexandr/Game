#pragma once

#include <string>
#include <vector>
#include "Item.h"
#include "Location.h"

class Player {
public:
    Player();

    int GetHealth() const;
    void TakeDamage(int damage);
    void MoveToLocation(Location* location);

    void AddItem(Item* item);
    const std::vector<Item*>& GetInventory() const;

private:
    int health;
    Location* currentLocation;
    std::vector<Item*> inventory;
};
