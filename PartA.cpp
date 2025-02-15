#include "PartA.h"
#include <cstdlib>

// Constructor
HashTable1D::HashTable1D() {
    // Initialize all slots as unoccupied
    for (int i = 0; i < TABLE_SIZE; ++i) {
        occupied[i] = false;
        table[i] = 0;
    }
}

// Destructor
HashTable1D::~HashTable1D() {
    // Clear the table and occupied arrays
    for (int i = 0; i < TABLE_SIZE; ++i) {
        occupied[i] = false;
        table[i] = 0;
    }
}

// Hash function
int HashTable1D::hash(int key) const {
    return std::abs(key) % TABLE_SIZE;
}

// Insert method
int HashTable1D::Insert(int value) {
    int index = hash(value);
    int slots_checked = 0;

    // Check each slot in the table
    for (int i = 0; i < TABLE_SIZE; ++i) {
        slots_checked++;
        if (!occupied[index]) {
            // Found an empty slot
            table[index] = value;
            occupied[index] = true;

            if (slots_checked == 1) {
                std::cout << "The value " << value << " was inserted." << std::endl;
            }
            return slots_checked;
        }
        index = (index + 1) % TABLE_SIZE; // Linear probing
    }

    // Table is full
    std::cout << "The value " << value << " cannot be inserted." << std::endl;
    return slots_checked;
}

// Search method
int HashTable1D::Search(int value) const {
    int index = hash(value);
    int slots_checked = 0;

    // Check each slot in the table
    for (int i = 0; i < TABLE_SIZE; ++i) {
        slots_checked++;

        if (occupied[index] && table[index] == value) {
            std::cout << "The value " << value << " can be found." << std::endl;
            return slots_checked;
        }

        if (!occupied[index]) {
            // Empty slot means value not in table
            break;
        }

        index = (index + 1) % TABLE_SIZE; // Linear probing
    }

    std::cout << "The value " << value << " cannot be found." << std::endl;
    return slots_checked;
}

// Remove method
int HashTable1D::Remove(int value) {
    int index = hash(value);
    int slots_checked = 0;

    // Check each slot in the table
    for (int i = 0; i < TABLE_SIZE; ++i) {
        slots_checked++;

        if (occupied[index] && table[index] == value) {
            // Mark slot as unoccupied
            occupied[index] = false;

            // Reinsert subsequent elements to handle repositioning
            int next_index = (index + 1) % TABLE_SIZE;
            while (occupied[next_index]) {
                int reposition_value = table[next_index];
                occupied[next_index] = false;
                Insert(reposition_value); // Reinsert value
                next_index = (next_index + 1) % TABLE_SIZE;
            }

            std::cout << "The value " << value << " was removed." << std::endl;
            return slots_checked;
        }

        if (!occupied[index]) {
            // Empty slot means value not in table
            break;
        }

        index = (index + 1) % TABLE_SIZE; // Linear probing
    }

    std::cout << "The value " << value << " cannot be removed." << std::endl;
    return slots_checked;
}

// Print method
void HashTable1D::Print() const {
    std::cout << "Hash Table Contents:" << std::endl;
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (occupied[i]) {
            std::cout << "Slot " << i << ": " << table[i] << std::endl;
        }
        else {
            std::cout << "Slot " << i << ": [Empty]" << std::endl;
        }
    }
}
