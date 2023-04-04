#ifndef GAME_HPP
#define GAME_HPP

#include "card.hpp"
#include "player.hpp"
#include <vector>
#include <string>
#include <array>

namespace ariel
{
    class Game
    {
    private:
        std::vector<Card> deck;
        std::array<Player, 2> players;
        std::string mainLog;
        std::string lastTurn;
        int winner;
        int roundsPlayed;
        void fillCards();
        void shuffle();
        void splitCards();
        void checkWin();

    public:
        Game(Player player1, Player player2);
        Game();
        Game(const Game &other);
        Game &operator=(const Game &other); // copy assignment operator
        ~Game();
        std::string getplayer2();
        std::string getplayer1();
        void playTurn();
        void playAll();
        void printLastTurn();
        void printWiner();
        void printLog();
        void printStats();
        std::string getLog();
        // get winner
        const Player &getWinner() const;
        int getRoundsPlayed() const;
        Game(Game &&other) noexcept;            // move constructor
        Game &operator=(Game &&other) noexcept; // move assignment operator
    };
}

#endif // GAME_HPP
