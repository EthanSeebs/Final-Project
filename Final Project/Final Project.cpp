// Final Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

// --- Composition Classes ---
class Diet {
    std::string type;
public:
    Diet(const std::string& type) : type(type) {}
    std::string getType() const { return type; }
};

class Habitat {
    std::string description;
public:
    Habitat(const std::string& description) : description(description) {}
    std::string getDescription() const { return description; }
};

// --- Abstract Base Class ---
class Animal {
protected:
    std::string name;
    int age;
    const std::string species;
    Diet diet;
    Habitat habitat;

public:
    Animal(const std::string& name, int age, const std::string& species,
        const Diet& diet, const Habitat& habitat)
        : name(name), age(age), species(species), diet(diet), habitat(habitat) {
    }

    virtual ~Animal() = default;

    virtual void makeSound() const = 0;
    virtual void eat() const = 0;

    virtual void displayInfo() const final {
        std::cout << "Name: " << name << "\n"
            << "Age: " << age << "\n"
            << "Species: " << species << "\n"
            << "Diet Type: " << diet.getType() << "\n"
            << "Habitat: " << habitat.getDescription() << "\n\n";
    }
};

// --- Derived Animal Classes ---
class Lion : public Animal {
public:
    Lion(const std::string& name, int age, const Diet& diet, const Habitat& habitat)
        : Animal(name, age, "Lion", diet, habitat) {
    }

    void makeSound() const override {
        std::cout << name << " the Lion roars!\n";
    }

    void eat() const override {
        std::cout << name << " eats meat.\n";
    }
};

class Elephant : public Animal {
public:
    Elephant(const std::string& name, int age, const Diet& diet, const Habitat& habitat)
        : Animal(name, age, "Elephant", diet, habitat) {
    }

    void makeSound() const override {
        std::cout << name << " the Elephant trumpets!\n";
    }

    void eat() const override {
        std::cout << name << " eats grass and fruits.\n";
    }
};

class Gnu : public Animal {
public:
    Gnu(const std::string& name, int age, const Diet& diet, const Habitat& habitat)
        : Animal(name, age, "Gnu", diet, habitat) {
    }

    void makeSound() const override {
        std::cout << name << " the Gnu grunts!\n";
    }

    void eat() const override {
        std::cout << name << " grazes on the plains.\n";
    }
};

class Aardvark : public Animal {
public:
    Aardvark(const std::string& name, int age, const Diet& diet, const Habitat& habitat)
        : Animal(name, age, "Aardvark", diet, habitat) {
    }

    void makeSound() const override {
        std::cout << name << " the Aardvark snuffles.\n";
    }

    void eat() const override {
        std::cout << name << " eats ants and termites.\n";
    }
};

// --- Zoo Utilities ---
void makeAllAnimalsSound(const std::vector<Animal*>& zoo) {
    for (const auto& animal : zoo) {
        animal->makeSound();
    }
}

void showAllAnimalInfo(const std::vector<Animal*>& zoo) {
    for (const auto& animal : zoo) {
        animal->displayInfo();
    }
}

// --- Main Zoo Management System ---
int main() {
    std::vector<Animal*> zoo;

    // Shared composition objects
    Diet carnivore("Carnivore");
    Diet herbivore("Herbivore");
    Diet insectivore("Insectivore");

    Habitat savanna("Savanna");
    Habitat jungle("Jungle");
    Habitat burrow("Underground Burrow");

    // Instantiate Animals
    zoo.push_back(new Lion("Leon", 5, carnivore, savanna));
    zoo.push_back(new Lion("Nala", 4, carnivore, savanna));
    zoo.push_back(new Elephant("Dumbo", 10, herbivore, jungle));
    zoo.push_back(new Elephant("Borg", 12, herbivore, jungle));
    zoo.push_back(new Gnu("Ethan", 6, herbivore, savanna));
    zoo.push_back(new Aardvark("Arnold", 7, insectivore, burrow));

    // Demonstrate Polymorphism
    std::cout << "--- All Animal Sounds ---\n";
    makeAllAnimalsSound(zoo);

    std::cout << "\n--- All Animal Info ---\n";
    showAllAnimalInfo(zoo);

    // Cleanup
    for (Animal* animal : zoo) {
        delete animal;
    }

    return 0;
}
