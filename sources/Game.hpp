#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>


namespace coup{
    enum numbers 
{  
    seven = 7, 
    three =3,
    six = 6,
    zero = 0, 
    ten =10,
};

class Player;
class Game
{
    public:
        /* data structures to save the players*/
        std::vector<std::string> players_list;
        std::vector<Player*> Players_data;

        /*save the current player that plays now*/
        uint current_player;
        uint num_of_players;

        /*empty constructor of game*/
        Game();

        
        std::string turn() const;
        std::vector<std::string> players() const;
        std::string winner() const;
        

        
        void next_turn();
        void add_player(Player* player);
        void check_one_player() const;

        ~Game();
    };
};
#endif