#include "Player.hpp"
#include "Game.hpp"

using namespace std;

namespace coup
{
    Player::Player(Game &game, std::string & name)
    { 
        this->value = 0;
        this->_game = &game;
        this->_name = name;
        this->is_alive = true;
        this->killed = "no Assassination";
        this->losser_pos = 0;
        this->last_kill = nullptr;
          if (this->_game->num_of_players == six)
     {
         throw invalid_argument("too-much players");
     }
     bool flag=false;
        for (uint i = 0; i < this->_game->num_of_players; i++)
        {
            if (this->_game->Players_data.at(i)->value != 0)
            {
                flag = true;
            }
        }
        if(flag)
        {
            __throw_invalid_argument("can't add Player In Middle Of Game");
        }
        this->_game->add_player(this);
    }

    void Player::more_then_10()const
    {
    if (this->coins() >=ten)
    {
         throw invalid_argument("must coup");
    }
        
    }
    void Player::income()
    {
        this->_game->check_one_player();
        this->more_then_10();
        this->action = "income";
        if( this->_game->turn() != this->_name){
            __throw_invalid_argument("not your turn");
        }
        this->value++;
        this->_game->next_turn();
    }

    void Player::foreign_aid()
    {
        this->_game->check_one_player();
        this->more_then_10();
        if( this->_game->turn() != this->_name){
            __throw_invalid_argument("not your turn");
        }
        this->action = "foreign_aid";
        this->value += 2;
        this->_game->next_turn();
    }

    void Player::coup(Player &other_player)
    {
        this->_game->check_one_player();
        if(!other_player.is_alive)
        {
            __throw_invalid_argument("player dead");
        }
        if(this->value < seven)
        {
            __throw_invalid_argument("not enough money to coup");
        }
        else 
        {
            this->value -=seven;
            other_player.is_alive = false;
            this->killed = "Assassination";
            this->last_kill = &other_player;  
        }
        this->_game->next_turn();
    }

    int Player::coins() const{return this->value;}
    std::string Player::get_name()const{
        return this->_name;
    };

    Player::~Player(){}

};
