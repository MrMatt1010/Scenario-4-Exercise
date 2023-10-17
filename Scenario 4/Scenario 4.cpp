#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

class Alien {
private:
    double weight;
    double height;
    char gender;

public:
    Alien() : weight(0.0), height(0.0), gender('0') {} // Default constructor

    Alien(double w, double h, char g) : weight(w), height(h), gender(g) {}

    double getWeight() const {
        return weight;
    }

    double getHeight() const {
        return height;
    }

    char getGender() const {
        return gender;
    }

    double getPrestige() const {
        return height * weight * (gender == '1' ? 2 : 3);
    }

    Alien operator+(const Alien& other) {
        double newWeight = (weight + other.getWeight()) / 2;
        double newHeight = (height + other.getHeight()) / 2;
        char newGender = (rand() % 2 == 0) ? '1' : '0';
        return Alien(newWeight, newHeight, newGender);
    }

    // Comparison operators
    bool operator==(const Alien& other) const {
        return getPrestige() == other.getPrestige();
    }

    bool operator!=(const Alien& other) const {
        return getPrestige() != other.getPrestige();
    }

    bool operator>(const Alien& other) const {
        return getPrestige() > other.getPrestige();
    }

    bool operator<(const Alien& other) const {
        return getPrestige() < other.getPrestige();
    }

    bool operator>=(const Alien& other) const {
        return getPrestige() >= other.getPrestige();
    }

    bool operator<=(const Alien& other) const {
        return getPrestige() <= other.getPrestige();
    }
};

// Function to compare the prestige of offspring
void comparePrestige(const std::vector<Alien>& _offspring) {
    if (_offspring.size() < 2) {
        std::cout << "2 or more offspring are required to compare prestige\n";
        return;
    }

    for (int i = 0; i < _offspring.size(); i += 2) {
        std::cout << "Alien Offspring " << i << " == Alien Offspring " << i + 1 << "? " << (_offspring[i] == _offspring[i + 1] ? "true" : "false") << "\n";
        std::cout << "Alien Offspring " << i << " != Alien Offspring " << i + 1 << "? " << (_offspring[i] != _offspring[i + 1] ? "true" : "false") << "\n";
        std::cout << "Alien Offspring " << i << " > Alien Offspring " << i + 1 << "? " << (_offspring[i] > _offspring[i + 1] ? "true" : "false") << "\n";
        std::cout << "Alien Offspring " << i << " >= Alien Offspring " << i + 1 << "? " << (_offspring[i] >= _offspring[i + 1] ? "true" : "false") << "\n";
        std::cout << "Alien Offspring " << i << " < Alien Offspring " << i + 1 << "? " << (_offspring[i] < _offspring[i + 1] ? "true" : "false") << "\n";
        std::cout << "Alien Offspring " << i << " <= Alien Offspring " << i + 1 << "? " << (_offspring[i] <= _offspring[i + 1] ? "true" : "false") << "\n";
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    Alien alien1(70.5, 180.0, '1'); // Male
    Alien alien2(55.0, 160.0, '0'); // Female
    Alien alien3(75.0, 175.0, '1'); // Male
    Alien alien4(60.0, 170.0, '0'); // Female

    int choice;
    std::vector<Alien> offspring;

    do {
        std::cout << "Menu:\n";
        std::cout << "1. Create Alien 5 (offspring of Alien 1 and Alien 2)\n";
        std::cout << "2. Create Alien 6 (offspring of Alien 3 and Alien 4)\n";
        std::cout << "3. Compare Alien 5 and Alien 6 Prestige\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            offspring.push_back(alien1 + alien2);
            std::cout << "Alien 5 created from Alien 1 and Alien 2.\n";
            break;
        case 2:
            offspring.push_back(alien3 + alien4);
            std::cout << "Alien 6 created from Alien 3 and Alien 4.\n";
            break;
        case 3:
            comparePrestige(offspring);
            break;
        }
    } while (choice != 0);

    return 0;
}








