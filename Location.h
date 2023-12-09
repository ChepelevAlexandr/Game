#pragma once
#pragma once

#include <string>
#include <vector>
#include "Item.h"
#include "Enemy.h"

class Location {
public:
    Location(const std::string& name);

    std::string GetName() const;
    std::string GetDescription() const;
    void SetDescription(const std::string& description);

    void AddItem(Item* item);
    void RemoveItem(Item* item);
    const std::vector<Item*>& GetItems() const;

    void AddEnemy(Enemy* enemy);
    void RemoveEnemy(Enemy* enemy);
    const std::vector<Enemy*>& GetEnemies() const;

private:
    std::string name;
    std::string description;
    std::vector<Item*> items;
    std::vector<Enemy*> enemies;
};
