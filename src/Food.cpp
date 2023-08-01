#include "Food.h"

void Food::gen_food()
{
    food_pos.X = rand() % WIDTH + 1;
    food_pos.Y = rand() % HEIGHT + 1;
}
COORD Food::get_pos()
{
    return food_pos;
}
