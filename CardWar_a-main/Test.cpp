/** written by Maya Rom
 * id: 207485251
 * date: 27.03.2023
 */

#include "doctest.h"
#include "sources/player.hpp"
#include "sources/card.hpp"
#include "sources/game.hpp"

TEST_SUITE("CardWar Game Tests")
{
    TEST_CASE("Player class tests")
    {
        ariel::Player player1("Alice");
        ariel::Player player2("Bob");

        SUBCASE("Empty stack")
        {
            CHECK(player1.getCards().empty());
            CHECK(player1.cardsLeft() == 0);

            CHECK_THROWS_AS(player1.playCard(), std::runtime_error);
        }

        SUBCASE("Adding cards")
        {
            ariel::Card card1(2, ariel::Suit::HEARTS);
            ariel::Card card2(3, ariel::Suit::DIAMONDS);

            player1.addCard(card1);
            CHECK(player1.getCards().size() == 1);
            CHECK(player1.cardsLeft() == 1);

            player1.addCard(card2);
            CHECK(player1.getCards().size() == 2);
            CHECK(player1.cardsLeft() == 2);
        }

        SUBCASE("Playing cards")
        {
            ariel::Card card1(2, ariel::Suit::HEARTS);
            ariel::Card card2(3, ariel::Suit::DIAMONDS);

            player1.addCard(card1);
            player1.addCard(card2);

            CHECK(player1.getCards().size() == 2);
            CHECK(player1.cardsLeft() == 2);

            ariel::Card playedCard = player1.playCard();
            CHECK(playedCard.compare(card1) == 0);
            CHECK(player1.getCards().size() == 1);
            CHECK(player1.cardsLeft() == 1);

            playedCard = player1.playCard();
            CHECK(playedCard.compare(card2) == 0);
            CHECK(player1.getCards().size() == 0);
            CHECK(player1.cardsLeft() == 0);

            CHECK_THROWS_AS(player1.playCard(), std::runtime_error);
        }

        SUBCASE("Statistics")
        {
            CHECK(player1.getTurnsWon() == 0);
            CHECK(player1.getTurnsLost() == 0);
            CHECK(player1.getTurnsDraw() == 0);
            CHECK(player1.cardesTaken() == 0);

            player1.addTurnWon();
            CHECK(player1.getTurnsWon() == 1);
            CHECK(player1.getTurnsLost() == 0);
            CHECK(player1.getTurnsDraw() == 0);
            CHECK(player1.cardesTaken() == 0);

            player1.addTurnLost();
            CHECK(player1.getTurnsWon() == 1);
            CHECK(player1.getTurnsLost() == 1);
            CHECK(player1.getTurnsDraw() == 0);
            CHECK(player1.cardesTaken() == 0);
        }
    }
    TEST_CASE("Game with uneven number of cards")
    {
        ariel::Player player1("Player 1");
        ariel::Player player2("Player 2");

        // Player 1 has one more card than Player 2
        player1.addCard(ariel::Card(10, ariel::Suit::HEARTS));
        player1.addCard(ariel::Card(9, ariel::Suit::SPADES));
        player1.addCard(ariel::Card(8, ariel::Suit::DIAMONDS));

        player2.addCard(ariel::Card(7, ariel::Suit::CLUBS));
        player2.addCard(ariel::Card(6, ariel::Suit::HEARTS));
        player2.addCard(ariel::Card(5, ariel::Suit::SPADES));
        ariel::Game game(player1, player2);

        SUBCASE("Playing turns")
        {
            game.playAll();
            CHECK(game.getRoundsPlayed() == 3);
        }
    }
}
