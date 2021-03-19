#include <string>
#include "Direction.hpp"


namespace ariel {
	class Board{
        private:
            uint rows, cols;


        public:
            Board() {}
            ~Board () {}
            void post(int row, int col, Direction direction, std::string&& message);
            std::string static read(int row, int col, Direction direction, int length);
            void show();
    };
};
