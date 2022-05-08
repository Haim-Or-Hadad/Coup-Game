#include "Player.hpp"

namespace coup
{
    class Captain : public Player
    {
        public:
        Player * robbed;
        Captain(Game & game,std::string name);

        void steal(Player & player);
        void block(Player & player_to_block);
        static std::string role();
        
        ~Captain();
    };
}