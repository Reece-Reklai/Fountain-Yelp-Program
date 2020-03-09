/*************************************************************************
 *
 * Project III: Start testing here.
 *
 * File Name:       test_driver.cpp
 * Name(s):         ?
 * Course:          CPTR 142
 * Date:            ?
 *
 */
#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include <iostream>
#include <string>
#include "Fountain.h"
#include "User.h"

TEST_CASE("Create a Fountain", "[fountain]") {
    // Setup
    Fountain* theFountain("69420nice", "Mordor", "Literally Sauron");

    SECTION("Details are correct") {
        REQUIRE(theFountain->getId() == "69420nice");
        REQUIRE(theFountain->getName() == "Literally Sauron");
    }

    // Create a review
    Review* theReview(
        "Not a good place for a date",
        "I asked my girlfriend to join me but she never showed up", 0);
    User* theUser("007", "James Bond", "yesthisisanothermovie")
        theReview->assignUser(theUser);
    theReview->assignFountain(theFountain)

        SECTION("Adding a review works") {
        REQUIRE(theReview->getUser().getId() == "007");
        REQUIRE(theReview->getUser().getName() == "James Bond");
        REQUIRE(theReview->getUser().getPasscode() == "yesthisisanothermovie");
        REQUIRE(theReview->getFountain() == theFountain);
    }
    theFountain->addReview(theReview);
    theFountain->printReviews();

    // Teardown
}

TEST_CASE("Professor Carman's Quote", "[quote]") {
    // Setup
    Quotes myQuote(9);

    Quote quote = myQuote.getQuote(15);

    SECTION("Get Quote") {
        REQUIRE(quote.student == "Preston Carman");
        REQUIRE(quote.quote == "Talk is cheap. Show me the code.");
        REQUIRE(quote.author == "Linus Torvalds");
    }

    // Teardown
}

TEST_CASE("Professor Carman's Quote", "[quote]") {
    // Setup
    Quotes myQuote(9);

    Quote quote = myQuote.getQuote(15);

    SECTION("Get Quote") {
        REQUIRE(quote.student == "Preston Carman");
        REQUIRE(quote.quote == "Talk is cheap. Show me the code.");
        REQUIRE(quote.author == "Linus Torvalds");
    }

    // Teardown
}
