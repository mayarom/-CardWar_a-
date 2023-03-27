
/** written by Maya Rom
 * id: 207485251
 * date: 27.03.2023
*/


#include <stdexcept>
#include "player.hpp"
#include "card.hpp"

using namespace std;
using namespace ariel;

//first constructor - by cards:
void Player::addCard(const Card &card)
{
    stack.push_back(card);
}

//second constructor - shallow copy constructor:
Player::Player(const Player &other)
{
    name = other.name;
    stack = other.stack;
    stats = other.stats;
}

//third constructor- deep copy constructor:
Player &Player::operator=(const Player &other)
{
    if (this != &other)
    {
        name = other.name;
        stack = other.stack;
        stats = other.stats;
    }
    return *this;
}
//constructor
Player::Player(string name) : name(name), stats{0, 0, 0, 0, 0}
{
}
Player::Player(Player &&other) noexcept
{
    stack = std::move(other.stack);
    stats = other.stats;
    name = std::move(other.name);
}

Player &Player::operator=(Player &&other) noexcept
{
    if (this != &other)
    {
        stack = std::move(other.stack);
        stats = other.stats;
        name = std::move(other.name);
    }
    return *this;
}

//destructor
Player::~Player()
{
}


//this function adds a card to the start of the player's stack
void Player::addCardToStart(const Card &card)
{
    stack.insert(stack.begin(), card);
}

//this function adds a card to the end of the player's stack
void Player::addCardToEnd(const Card &card)
{
    stack.push_back(card);
}

//return the card at the top of the player's stack
Card Player::playCard()
{
    if (stack.empty())
    {
        throw runtime_error("Player has no cards left!");
    }
    Card card = stack.front();
    stack.erase(stack.begin());
    return card;
}

//return the number of cards that the player has left
int Player::cardsLeft() const
{
    return stack.size();
}

string Player::getName() const
{
    return name;
}

//return the player's stack
vector<Card> Player::getCards() const
{
    return stack;
}

//counting the turns that the player won and play 
void Player::addTurnWon()
{
    stats.turnsPlayed++;
    stats.turnsWon++;
}

//counting the turns that the player lost and play
void Player::addTurnLost()
{
    stats.turnsPlayed++;
    stats.turnsLost++;
}

//counting the turns that the player draw and play
void Player::addTurnDraw()
{
    stats.turnsPlayed++;
    stats.turnsDraw++;
}

//return the player's stats
string Player::getStats() const
{
    string statsStr = "Player " + name + " stats:\n";
    statsStr += "Cards left: " + to_string(stats.cardsLeft) + "\n";
    statsStr += "Turns played: " + to_string(stats.turnsPlayed) + "\n";
    statsStr += "Turns won: " + to_string(stats.turnsWon) + "\n";
    statsStr += "Turns lost: " + to_string(stats.turnsLost) + "\n";
    statsStr += "Turns draw: " + to_string(stats.turnsDraw) + "\n";
    return statsStr;
}

//return the number of cards that the player has left
int Player::stacksize() const
{
    return stack.size();
}

//return the number of turns that the player won
int Player::getTurnsWon() const
{
    return stats.turnsWon;
}

//return the number of turns that the player lost
int Player::getTurnsLost() const
{
    return stats.turnsLost;
}

//return the number of turns that ended in a draw
int Player::getTurnsDraw() const
{
    return stats.turnsDraw;
}

// return the amount of cards this player has won.
int Player::cardesTaken() const
{
    return stats.cardsLeft;
}


 // Path: sources/game.cpp
