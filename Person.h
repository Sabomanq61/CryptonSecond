//
// Created by saba on 29.07.2021.
//

#include <string>
#include <vector>

#pragma once

/// @brief Структура для хранения информации о личнонсти за исключением имени
struct Person
{
public:
    using Persons = std::vector<Person>;

    uint        requestPerHour{0};
    int         totalRequest{0};
    int         totalHours{0};
    std::string additional;
};



