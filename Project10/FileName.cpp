#include <iostream>

using namespace std;

class Pet
{
protected:
    char name[50];

public:
    Pet(const char* petName) 
    {
        strncpy_s(name, sizeof(name), petName, sizeof(name) - 1);
        name[sizeof(name) - 1] = '\0';
    }

    void setName(const char* newName) 
    {
        strncpy_s(name, sizeof(name), newName, sizeof(name) - 1);
        name[sizeof(name) - 1] = '\0';
    }

    void printInfo() const 
    {
        cout << "Pet: " << name << endl;
    }
};

class Dog : public Pet 
{
private:
    char breed[50];

public:
    Dog(const char* dogName, const char* dogBreed) : Pet(dogName) 
    {
        strncpy_s(breed, sizeof(breed), dogBreed, sizeof(breed) - 1);
        breed[sizeof(breed) - 1] = '\0';
    }

    void printInfo() const 
    {
        cout << "Dog: " << name << ", Breed: " << breed << endl;
    }
};

class Cat : public Pet 
{
private:
    int age;

public:
    Cat(const char* catName, int catAge) : Pet(catName), age(catAge) 
    {}

    void printInfo() const 
    {
        cout << "Cat: " << name << ", Age: " << age << " years" << endl;
    }
};


class Parrot : public Pet 
{
private:
    char color[50];

public:
    Parrot(const char* parrotName, const char* parrotColor) : Pet(parrotName)
    {
        strncpy_s(color, sizeof(color), parrotColor, sizeof(color) - 1);
        color[sizeof(color) - 1] = '\0';
    }

    void printInfo() const 
    {
        cout << "Parrot: " << name << ", Color: " << color << endl;
    }
};

int main()
{
    Dog dog("Bud", "Husky");
    Cat cat("Kitty", 5);
    Parrot parrot("Polly", "Blue");

    dog.printInfo();
    cat.printInfo();
    parrot.printInfo();

    return 0;
}