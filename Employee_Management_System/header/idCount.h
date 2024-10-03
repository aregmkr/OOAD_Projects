#pragma once

class ID {
public:
    static int generateId() {
        return ++count;
    }
private:
    static int count;
};

int ID::count = 0;
