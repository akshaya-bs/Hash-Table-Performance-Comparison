#pragma once
#ifndef HASH_TABLE_1D_H
#define HASH_TABLE_1D_H

#include <iostream>
#include <stdexcept>

class HashTable1D {
private:
    static const int TABLE_SIZE = 500; // Number of slots in the hash table
    int table[TABLE_SIZE];            // Array to store items
    bool occupied[TABLE_SIZE];        // Array to track occupied slots

    // Hash function: h(x) = x % TABLE_SIZE
    int hash(int key) const;

public:
    // Constructor
    HashTable1D();

    // Destructor
    ~HashTable1D();

    // Insert method
    int Insert(int value);

    // Search method
    int Search(int value) const;

    // Remove method
    int Remove(int value);

    // Print method
    void Print() const;
};

#endif // HASH_TABLE_1D_H
