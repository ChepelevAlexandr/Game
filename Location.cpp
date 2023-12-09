#include "Location.h"

Location::Location(const std::string& name) : name(name) {}

std::string Location::GetName() const {
    return name;
}

std::string Location::GetDescription() const {
    return description;
}

void Location::SetDescription(const std::string& newDescription) {
    description = newDescription;
}

void Location::AddItem(Item* item) {
    items.push_back(item);
}

void Location::RemoveItem(Item* item) {
    // Реализация удаления элемента из вектора
}

const std::vector<Item*>& Location::GetItems() const {
    return items;
}

void Location::AddEnemy(Enemy* enemy) {
    enemies.push_back(enemy);
}

void Location::RemoveEnemy(Enemy* enemy) {
    // Реализация удаления врага из вектора
}

const std::vector<Enemy*>& Location::GetEnemies() const {
    return enemies;
}
