#ifndef SNAKE_H
#define SNAKE_H

#include <windows.h>
#include <vector>

#define WIDTH 50
#define HEIGHT 25

using namespace std;

class Snake
{
    private:
    COORD pos;
    int vel;
    char dir;
    int len;
    vector<COORD> body;
    public:
    Snake(COORD pos, int vel);
    void direction(char dir);
    void grow();
    COORD get_pos();
    vector<COORD> get_body();
    void move_snake();
    bool check_collision();
    bool eaten(COORD food);
};
#endif