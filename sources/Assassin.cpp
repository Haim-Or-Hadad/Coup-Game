#include "Assassin.hpp"
#include "Player.hpp"

using namespace std;
namespace coup{
    Assassin::Assassin(Game & game,std::string name) : Player(game, name)
    {}

    void Assassin::coup(Player & player_to_rinse){
        if(this->value < three)
        {
            throw invalid_argument("assissan havn't money to coup");
        }
        if (!player_to_rinse.is_alive)
        {
            throw invalid_argument("player dead");
        }
        if (this->value >=seven)
        {
            this->value -=seven;
            player_to_rinse.is_alive=  false;
            this->killed = "7-Assassination";
        }
        else
        {
            this->value -=three;
            player_to_rinse.is_alive=  false;
            this->killed = "Assassination";
        }
        this->last_kill = &player_to_rinse;
        this->_game->next_turn();
    }

    string Assassin::role()
    {
        return "Assassin";
    }

    Assassin::~Assassin(){}
}