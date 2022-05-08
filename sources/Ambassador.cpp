#include "Ambassador.hpp"
#include <iostream>
#include "Player.hpp"

using namespace std;

namespace coup{ 
    Ambassador::Ambassador(Game & game,std::string  name) : Player(game, name)
    { }
    void Ambassador::transfer(Player & take , Player & give){
        if (!take.is_alive||!give.is_alive)
        {
            throw invalid_argument("one of the players is dead");
        }
        if(take.value <=0)
        {
            throw invalid_argument("not money to transfer");
        }
        take.value-=1;
        give.value+=1;
        this->action = "transfer";
        this->_game->next_turn();
    }

   void Ambassador::block(Player & p){
        if(p.action == "steal"){
            p.last_kill->value += 2;
            p.value -=2;
        }
    }

    string Ambassador::role(){
        return "Ambassador";
    }
    Ambassador::~Ambassador(){}
}