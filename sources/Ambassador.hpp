
#include "Player.hpp"


namespace coup
{
    class Ambassador : public Player
    {
        public:
        Ambassador(Game & game,std::string  name);

        void transfer(Player & take , Player & give);
        static void block(Player & p);
        static std::string role();
        
        ~Ambassador();
    };
}