#pragma once

#include <string>

class Enemy {
public:
    Enemy(const std::string& name, int health);

    std::string GetName() const;
    void Attack() const;

private:
    std::string name;
    int health;
};
