#include "Contessa.hpp"
#include "Player.hpp"

using namespace std;

namespace coup{
    Contessa::Contessa(Game & game,std::string name) : Player(game, name)
    {}

    void Contessa::block(Player & player_to_block)
    {
        if (player_to_block.killed != "Assassination")
        {
            __throw_invalid_argument("no Assassination");
        }
        if(player_to_block.killed == "7-Assassination" )
        {
            __throw_invalid_argument("why");
        }
        player_to_block.last_kill->is_alive = true;
        uint po = (uint)this->losser_pos;
        this->_game->Players_data.at(po)->is_alive = true;
        
        
    }

    string Contessa::role(){
        return "Contessa";
    }
    Contessa::~Contessa(){}
}