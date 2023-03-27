/** written by Maya Rom
 * id: 207485251
 * date: 27.03.2023
 */
#ifndef CARD_HPP
#define CARD_HPP
#include <iostream>
#include <string>

namespace ariel
{
    enum class Suit
    {
        HEARTS,
        SPADES,
        DIAMONDS,
        CLUBS
    };

    class Card
    {
    public:
        Card(int rank, Suit suit);
        std::string toString() const;
        int compare(const Card &other) const;
        int getRank() const { return rank; }
        Suit getSuit() const { return suit; }

    private:
        int rank;
        Suit suit;
    };

} // namespace ariel

#endif // CARD_HPP
