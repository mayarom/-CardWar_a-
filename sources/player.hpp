/** written by Maya Rom
 * id: 207485251
 * date: 27.03.2023
 */

#ifndef WAR_PLAYER_H
#define WAR_PLAYER_H
#include <string>
#include <vector>

#include "card.hpp"

namespace ariel
{
    struct PlayerStats
    {
        int cardsLeft = 0;
        int turnsPlayed = 0;
        int turnsWon = 0;
        int turnsLost = 0;
        int turnsDraw = 0;
    };

    class Player
    {
        std::vector<Card> stack;
        PlayerStats stats;
        std::string name;

    public:
        // default constructor
        Player() = default;

        Player(const Player &other);
        Player &operator=(const Player &other);
        Player(std::string name); 
        void addCard(const Card &card);
        void addCardToStart(const Card &card);
        void addCardToEnd(const Card &card);
        Card playCard();
        int cardsLeft() const;
        std::string getName() const;
        std::vector<Card> getCards() const;
        void addTurnWon();
        void addTurnLost();
        void addTurnDraw();
        std::string getStats() const;
        int stacksize() const;
        int getTurnsWon() const;
        int getTurnsLost() const;
        int getTurnsDraw() const;
        int cardesTaken() const;
        // destructor
        ~Player();
        Player(Player &&other) noexcept;            // move constructor
        Player &operator=(Player &&other) noexcept; // move assignment operator
    };
} // namespace ariel

#endif // WAR_PLAYER_H
