#include "Player.hpp"

namespace coup
{
    class Assassin : public Player
    {
        public:
        Assassin(Game & game,std::string name);
        
        void block(Player & player_to_rinse);
        void coup(Player & player_to_rinse);
        static std::string role();

            ~Assassin();
    };

}