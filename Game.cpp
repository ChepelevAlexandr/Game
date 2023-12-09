
#include "Game.h"
#include <iostream>

Game::Game() {
    InitializeGame();
}

void Game::Start() {
    currentLocation = &locations[0];
    RunGameLoop();
}

void Game::InitializeGame() {
    // Инициализация локаций, предметов и врагов
    locations.push_back(Location("Start"));
    locations.back().SetDescription("You find yourself in a mysterious forest");

    Item* key = new Item("Key");
    locations.back().AddItem(key);

    Enemy* goblin = new Enemy("Goblin", 20);
    locations.back().AddEnemy(goblin);
}

void Game::RunGameLoop() {
    while (true) {
        DisplayCurrentLocation();
        DisplayPlayerStatus();
        DisplayAvailableCommands();

        std::cout << "Enter a command: ";
        std::string command;
        std::getline(std::cin, command);

        if (command == "quit") {
            std::cout << "Thanks for playing! Goodbye." << std::endl;
            break;
        }
        else if (command == "look") {
            DisplayCurrentLocation();
        }
        else if (command == "inventory") {
            DisplayInventory();
        }
        else if (command == "move") {
            HandleMoveCommand();
        }
        else if (command == "attack") {
            HandleAttackCommand();
        }
        else if (command == "take") {
            HandleTakeCommand();
        }
        else if (command == "location around") {
            DisplayAvailableLocations();
        }
        else if (command == "help") {
            DisplayAvailableCommands();
        }
        else {
            std::cout << "Invalid command. Try again." << std::endl;
        }

        // Проверка условий победы и поражения
        if (player.GetHealth() <= 0) {
            std::cout << "You were defeated. Game over!" << std::endl;
            break;
        }
        else if (currentLocation->GetName() == "TreasureRoom") {
            std::cout << "Congratulations! You found the treasure and won the game!" << std::endl;
            break;
        }
    }
}

void Game::DisplayCurrentLocation() const {
    std::cout << "Current Location: " << currentLocation->GetName() << std::endl;
    std::cout << currentLocation->GetDescription() << std::endl;

    // Вывод предметов в локации
    std::cout << "Items in this location:" << std::endl;
    for (const auto& item : currentLocation->GetItems()) {
        std::cout << "- " << item->GetName() << std::endl;
    }

    // Вывод врагов в локации
    std::cout << "Enemies in this location:" << std::endl;
    for (const auto& enemy : currentLocation->GetEnemies()) {
        std::cout << "- " << enemy->GetName() << std::endl;
    }

    std::cout << std::endl;
}

void Game::DisplayPlayerStatus() const {
    std::cout << "Player: " << player.GetHealth() << " health" << std::endl;
}

void Game::DisplayInventory() const {
    std::cout << "Player Inventory:" << std::endl;
    for (const auto& item : player.GetInventory()) {
        std::cout << "- " << item->GetName() << std::endl;
    }
    std::cout << std::endl;
}

void Game::HandleMoveCommand() {
    std::cout << "Enter the name of the location to move to: ";
    std::string destinationName;
    std::getline(std::cin, destinationName);

    Location* destination = FindLocation(destinationName);

    if (destination != nullptr) {
        player.MoveToLocation(destination);
    }
    else {
        std::cout << "Invalid location. Try again." << std::endl;
    }
}

void Game::HandleAttackCommand() {
    std::cout << "Enter the name of the enemy to attack: ";
    std::string enemyName;
    std::getline(std::cin, enemyName);

    Enemy* enemy = FindEnemy(enemyName);

    if (enemy != nullptr) {
        player.TakeDamage(10);
        enemy->Attack();
    }
    else {
        std::cout << "Invalid enemy. Try again." << std::endl;
    }
}

void Game::HandleTakeCommand() {
    std::cout << "Enter the name of the item to take: ";
    std::string itemName;
    std::getline(std::cin, itemName);

    Item* item = FindItem(itemName);

    if (item != nullptr) {
        player.AddItem(item);
        currentLocation->RemoveItem(item);
        std::cout << "You took the " << item->GetName() << std::endl;
    }
    else {
        std::cout << "Invalid item. Try again." << std::endl;
    }
}

void Game::DisplayAvailableLocations() const {
    std::cout << "Available locations to move:" << std::endl;
    for (const auto& location : locations) {
        std::cout << "- " << location.GetName() << std::endl;
    }
    std::cout << std::endl;
}

void Game::DisplayAvailableCommands() const {
    std::cout << "Available commands:" << std::endl;
    std::cout << "- look: Display current location" << std::endl;
    std::cout << "- inventory: Display player inventory" << std::endl;
    std::cout << "- move: Move to a different location" << std::endl;
    std::cout << "- attack: Attack an enemy in the current location" << std::endl;
    std::cout << "- take: Take an item from the current location" << std::endl;
    std::cout << "- location around: Display available locations to move" << std::endl;
    std::cout << "- help: Display available commands" << std::endl;
    std::cout << "- quit: Quit the game" << std::endl;
    std::cout << std::endl;
}

Location* Game::FindLocation(const std::string& name) {
    for (auto& location : locations) {
        if (location.GetName() == name) {
            return &location;
        }
    }
    return nullptr;
}

Enemy* Game::FindEnemy(const std::string& name) {
    for (auto& enemy : currentLocation->GetEnemies()) {
        if (enemy->GetName() == name) {
            return enemy;
        }
    }
    return nullptr;
}

Item* Game::FindItem(const std::string& name) {
    for (auto& item : currentLocation->GetItems()) {
        if (item->GetName() == name) {
            return item;
        }
    }
    return nullptr;
}
