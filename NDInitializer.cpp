// NDInitializer.cpp
#include "NDInitializer.h"
#include <iostream>

// Constructeur pour une liste de doubles (feuille)
NDInitializer::NDInitializer(std::initializer_list<double> list) : data(list) {
    shape.push_back(list.size());
}

// Constructeur pour une liste imbriquée de NDInitializer
NDInitializer::NDInitializer(std::initializer_list<NDInitializer> list) {
    if (list.size() == 0) return;

    const auto& first = *list.begin();
    shape = first.shape;
    shape.insert(shape.begin(), list.size());

    size_t expected_size = first.data.size();
    for (const auto& init : list) {
        if (init.data.size() != expected_size) {
            std::cerr << "ValueError: inconsistent shapes in nested initializer lists" << std::endl;
            exit(1);
        }
        data.insert(data.end(), init.data.begin(), init.data.end());
    }
}
