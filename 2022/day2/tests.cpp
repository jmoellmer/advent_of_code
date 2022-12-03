#define CATCH_CONFIG_MAIN // provides main(); this line is required in only one .cpp file
#include "catch2/catch_all.hpp"
#include "Day2.h"

TEST_CASE( "Data Structures" ) {
    hand h;
    h = R;
    REQUIRE(R == 1);
    h = P;
    REQUIRE(h == 2);
    h = S;
    REQUIRE(S == 3);

    bonus b;
    b = LOSE;
    REQUIRE(b == 0);
    b = DRAW;
    REQUIRE(b == 3);
    b = WIN;
    REQUIRE(b == 6);
}

TEST_CASE("Pop score") {
    Day2 d2("../input");
    REQUIRE(d2.pop_score() == 9); // S + WIN = 9
    REQUIRE(d2.pop_score() == 2); // P + LOSE = 2
    REQUIRE(d2.pop_score() == 9); // S + WIN = 9
}
