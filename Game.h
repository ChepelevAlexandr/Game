#pragma once

#include <vector>
#include "Location.h"
#include "Player.h"

class Game {
public:
    Game();
    void Start();

private:
    std::vector<Location> locations;
    Player player;
    Location* currentLocation;

    void InitializeGame();
    void RunGameLoop();
    void DisplayCurrentLocation() const;
    void DisplayPlayerStatus() const;
    void DisplayInventory() const;
    void HandleMoveCommand();
    void HandleAttackCommand();
    void HandleTakeCommand();
    void DisplayAvailableLocations() const;
    void DisplayAvailableCommands() const;

    Location* FindLocation(const std::string& name);
    Enemy* FindEnemy(const std::string& name);
    Item* FindItem(const std::string& name);
};
