#include "Snake.h"

Snake::Snake(COORD pos, int vel)
{
    this->pos = pos;
    this->vel = vel;

    dir = 'n';
    len = 1;
    body.push_back(pos);
}
void Snake :: direction(char dir)
{
    this->dir = dir;
}
void Snake :: grow()
{
    len++;
}
COORD Snake :: get_pos()
{
    return pos;
}
vector<COORD> Snake :: get_body()
{
    return body;
}
void Snake :: move_snake()
{
    switch(dir)
    {
        case 'w':
            pos.Y -= vel;
            break;
        case 'a':
            pos.X -= vel;
            break;
        case 's':
            pos.Y += vel;
            break;
        case 'd':
            pos.X += vel;
            break;
    }
    body.push_back(pos);
    if(body.size() > len)
    {
        body.erase(body.begin());
    }
}
bool Snake :: check_collision()
{
    if(pos.X == 0 || pos.X == WIDTH+1 || pos.Y == 0 || pos.Y == HEIGHT+1)
    {
        return true;
    }
    for(int i = 0; i < body.size()-1; i++)
    {
        if(pos.X == body[i].X && pos.Y == body[i].Y)
        {
            return true;
        }
    }
    return false;
}
bool Snake :: check_food(COORD food_pos)
{
    if(pos.X == food_pos.X && pos.Y == food_pos.Y)
    {
        return true;
    }
    return false;
}