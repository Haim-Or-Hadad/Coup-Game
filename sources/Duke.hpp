#include "Player.hpp"


namespace coup
{
    class Duke : public Player
    {

    public:
        Duke(Game & game,std::string name);

        void tax();
        static void block(Player &player_to_block); 
        static std::string role();

        ~Duke();
    };
}