#pragma once
#ifndef HASH_TABLE_2D_H
#define HASH_TABLE_2D_H

#include <iostream>
#include <stdexcept>

class HashTable2D {
private:
    static const int TABLE_ROWS = 100;
    static const int SLOTS_PER_ROW = 5;
    int table[TABLE_ROWS][SLOTS_PER_ROW];
    bool occupied[TABLE_ROWS][SLOTS_PER_ROW];

    // Hash function: x % 100
    int hash(int key) const;

public:
    // Constructor
    HashTable2D();

    ~HashTable2D();

    // Insert method
    int Insert(int value);

    // Search method
    int Search(int value) const;

    // Remove method
    int Remove(int value);

    // Print method
    void Print() const;
};

#endif // HASH_TABLE_2D_H