#pragma once

#include <string>

class Item {
public:
    Item(const std::string& name);

    std::string GetName() const;

private:
    std::string name;
};
