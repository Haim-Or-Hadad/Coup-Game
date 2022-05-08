
#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Game.hpp"
#include <iostream>


namespace coup{
class Player
{
public: 
    Game *_game;
    std::string _name;
    int value;
    bool is_alive;
    std::string action;
    int losser_pos;
    std::string killed;
    Player *last_kill;
 
    Player(Game &game, std::string & name);

    void income();
    void foreign_aid();
    void coup(Player &other_player);

    std::string get_name()const;
    int coins() const;

    void set_mood(bool flag){
        is_alive = flag;
    }

    bool get_mood(){
        return is_alive;
    }
    
    void more_then_10()const;

     ~Player();

};
};

#endif
