#pragma once
#include <iostream>
#include <string>

class Pet {
public:
    explicit Pet(const std::string& name, int age);
    Pet(const Pet&) = delete;
    Pet(Pet&&) = delete;
    Pet& operator=(const Pet&) = delete;
    Pet& operator=(Pet&&) = delete;
    virtual ~Pet() = default;
    virtual void makeSound() = 0;
    virtual void eat() = 0;
    void displayInfo() const;
private:
    std::string name_;
    int age_;    
};