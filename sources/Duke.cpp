#include "Duke.hpp"
#include <iostream>

using namespace std;

namespace coup{
Duke::Duke(Game & game,std::string name) : Player(game, name)
{}

void Duke::tax()
{
    this->action = "tax";
    this->value +=3;
    this->_game->next_turn();
}

void Duke::block(Player &player_to_block)
{
    if (player_to_block.action == "foreign_aid")
    {
        player_to_block.value-=2;
    }  
    else
    {
    __throw_invalid_argument("can't block");
    }
}

string Duke::role()
{
    return "Duke";
}

Duke::~Duke(){}
}