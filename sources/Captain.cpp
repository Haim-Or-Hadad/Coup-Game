#include "Captain.hpp"
#include "Player.hpp"

using namespace std;

namespace coup{
    Captain::Captain(Game & game,std::string name) : Player(game, name)
    {
            this->robbed = nullptr;
    }

    void Captain::steal(Player & player)
    {
         if( this->_game->turn() != this->_name)
         {
            __throw_invalid_argument("not your turn");
         }
        this->action = "steal";
        this->robbed = &player;
        if (player.value >=2)
        {
            player.value -=2;
            this->value +=2;
            this->last_kill = &player;
        }
        else if(player.value == 1)
        {
            player.value -=1;
            this->value +=1;
            this->last_kill = &player;
        }
        else{
            cout << "not enough money to steal" <<endl;
        }
        this->_game->next_turn();
    };

    void Captain::block(Player & player_to_block){
        if (player_to_block.action != "steal")
        {
            __throw_invalid_argument("can't block");
        }
        else
        {
        this->robbed->value+=2;
        player_to_block.value-=2;
        this->robbed = nullptr;    
        }
    }

    string Captain::role(){
        return "Captain";
    }

    Captain::~Captain(){}

}