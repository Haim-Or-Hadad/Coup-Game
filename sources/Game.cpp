#include "Game.hpp"
#include "Player.hpp"

using namespace std;

namespace coup{

    Game::Game()
    {
        
        this->current_player = 0;
        this->num_of_players = 0;
    }

    string Game::turn() const
    {
        return this->Players_data.at(this->current_player)->_name;
    }


    vector<string> Game::players() const
    {
        vector<string> list;
        for (Player *player : this->Players_data)
        {
        if (player->is_alive)
            {
            list.push_back(player->_name);
            }
        }
        return list;
    }
    

    string Game::winner() const
    {
        if(this->num_of_players<2)
        {
            __throw_invalid_argument("the game doesn't starting");
        }
        if (this->players().size() > 1)
        {
            __throw_invalid_argument("the game is active");
        }
        for (uint i = 0; i < this->Players_data.size(); i++)
        {
            if (this->Players_data.at(i)->is_alive)
            {
                return this->Players_data.at(i)->_name;
            }  
        }
         return "no winner";
    }

    void Game::next_turn()
    {
        this->current_player = (this->current_player+1)%this->Players_data.size();
        while (!this->Players_data.at(this->current_player)->is_alive)
        {
            this->current_player = (this->current_player+1)%this->Players_data.size();    
        }
    }

    void Game::add_player(Player* player)
    {   
        this->num_of_players++; 
        this->players_list.push_back(player->_name);
        this->Players_data.push_back(player);
    }

    void Game::check_one_player() const
    {
        if (this->num_of_players < 2)
        {
            __throw_invalid_argument("only one player");
        }       
    }
    
    Game::~Game(){}
    
};