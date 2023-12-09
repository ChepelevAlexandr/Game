#include "Enemy.h"
#include <iostream>

Enemy::Enemy(const std::string& name, int health) : name(name), health(health) {}

std::string Enemy::GetName() const {
    return name;
}

void Enemy::Attack() const {
    std::cout << name << " attacks you!" << std::endl;
}
