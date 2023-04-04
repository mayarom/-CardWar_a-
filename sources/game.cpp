/** written by Maya Rom
 * id: 207485251
 * date: 27.03.2023
 */
#include "card.hpp"
#include "player.hpp"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include "game.hpp"

using namespace std;

namespace ariel
{
    //constructors:

    //first constructor - by players:
    Game::Game(Player p1, Player p2) : winner(-1), players{p1, p2}, roundsPlayed(0)
    {
     
        fillCards();
        shuffle();
        splitCards();
    }

    //second constructor - by default:
    Game::Game() : winner(-1), players{Player("Player 1"), Player("Player 2")}
    {
        std::cout << "Filling deck..." << std::endl;
        fillCards();
        std::cout << "Shuffling deck..." << std::endl;
        shuffle();
        std::cout << "Dividing cards..." << std::endl;
        splitCards();
    }
    //third constructor - copy constructor:
    Game::Game(const Game &other) : winner(other.winner), players{other.players[0], other.players[1]}, roundsPlayed(other.roundsPlayed)
    {
        std::cout << "Filling deck..." << std::endl;
        fillCards();
        std::cout << "Shuffling deck..." << std::endl;
        shuffle();
        std::cout << "Dividing cards..." << std::endl;
        splitCards();
    }
    //copy assignment operator:
    Game &Game::operator=(const Game &other)
    {
        if (this != &other)
        {
            winner = other.winner;
            players[0] = other.players[0];
            players[1] = other.players[1];
            roundsPlayed = other.roundsPlayed;
        }
        return *this;
    }
    Game::Game(Game &&other) noexcept
        : deck(std::move(other.deck)),
          players{std::move(other.players[0]), std::move(other.players[1])},
          mainLog(std::move(other.mainLog)),
          lastTurn(std::move(other.lastTurn)),
          winner(other.winner),
          roundsPlayed(other.roundsPlayed)
    {
    }

    Game &Game::operator=(Game &&other) noexcept
    {
        if (this != &other)
        {
            deck = std::move(other.deck);
            players[0] = std::move(other.players[0]);
            players[1] = std::move(other.players[1]);
            mainLog = std::move(other.mainLog);
            lastTurn = std::move(other.lastTurn);
            winner = other.winner;
            roundsPlayed = other.roundsPlayed;
        }
        return *this;
    }

    //destructor:
    Game::~Game() {}

    //filling the deck with cards:
    void Game::fillCards()
    {

        std::cout << "Number of cards in the deck: " << deck.size() << std::endl;
    }

    //printing the deck:
    std::string printCard(const Card &card)
    {
        return card.toString();
    }

    //shuffling the deck:
    void Game::shuffle()
    {
        cout << "Shuffling deck..." << endl;
    }

    //splitting the deck between the players:
    void Game::splitCards()
    {
        std::cout << "Player 1 cards: " << players[0].getStats() << std::endl;
        std::cout << "Player 2 cards: " << players[1].getStats() << std::endl;
    }

    //playing a turn:
    void Game::playTurn()
    {
        cout << "playTurn " << endl;
    }

    //playing all the turns:
    void Game::playAll()
    {
        cout << "playAll " << endl;
    }

    //printing the last turn:
    void Game::printLastTurn()
    {
        cout << "printLastTurn " << endl;
    }

    //printing the winner:
    void Game::printWiner()
    {
        cout << "The winner is: " << getWinner().getName() << endl;
    }

    //printing the log:
    void Game::printLog()
    {
        std::cout << mainLog;
    }
    //getters:

    const Player &Game::getWinner() const
    {
        return players[static_cast<std::size_t>(winner)];
    }

    //printing the stats:
    void Game::printStats()
    {
        std::cout << players[0].getName() << " has " << players[0].getCards().size() << " cards left.\n";
        std::cout << players[1].getName() << " has " << players[1].getCards().size() << " cards left.\n";
    }

    //returning the log:
    std::string Game::getLog()
    {
        return mainLog;
    }

    //checking if the game is over:
    void Game::checkWin()
    {
       cout << "checkWin " << endl;
    }

    //returning the player1 name:
    std::string Game::getplayer1()
    {
        return players[0].getName();
    }

    //returning the player2 name:
    std::string Game::getplayer2()
    {
        return players[1].getName();
    }

    //returning the number of rounds played:
    int Game::getRoundsPlayed() const
    {
        return 1;
    }

}
