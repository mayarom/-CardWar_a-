/** written by Maya Rom
 * id: 207485251
 * date: 27.03.2023
 */

#include "card.hpp"
#include <iostream>
#include <sstream>

using namespace std;

namespace ariel
{

    Card::Card(int rank, Suit suit) : rank(rank), suit(suit) {}

    std::string Card::toString() const
    {
        std::stringstream out;
        return out.str();
    }

    int Card::compare(const Card &other) const
    {
        return 1;
    }

} // namespace ariel
