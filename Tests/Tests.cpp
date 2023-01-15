#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../LList/LList.cpp"

TEST_CASE("testing list agg last")
{
    LList<double> list;
    list.push_back(2);
    list.push_back(24);
    list.push_back(3);
    list.push_back(1);

    CHECK(list.agg_last() == 1);
}

TEST_CASE("testing list agg avg")
{
    LList<double> list;
    list.push_back(2);
    list.push_back(24);
    list.push_back(3);
    list.push_back(1);

    CHECK(list.agg_average() == 7.5);
}

TEST_CASE("testing list agg product")
{
    LList<double> list;
    list.push_back(2);
    list.push_back(24);
    list.push_back(3);
    list.push_back(1);

    CHECK(list.agg_product() == 144);
}

TEST_CASE("testing list agg sum")
{
    LList<double> list;
    list.push_back(2);
    list.push_back(24);
    list.push_back(3);
    list.push_back(1);

    CHECK(list.agg_summation() == 30);
}

TEST_CASE("testing list agg first")
{
    LList<double> list;
    list.push_back(2);
    list.push_back(24);
    list.push_back(3);
    list.push_back(1);

    CHECK(list.agg_first() == 2);
}

TEST_CASE("testing list reverse")
{
    LList<double> list;
    list.push_back(2);
    list.push_back(24);
    list.push_back(3);
    list.push_back(1);


    LList<double> sndList;
    sndList.push_back(1);
    sndList.push_back(3);
    sndList.push_back(24);
    sndList.push_back(2);

    list.reverse();

    CHECK(list == sndList);
}


TEST_CASE("testing list map increment")
{
    LList<double> list;
    list.push_back(2);
    list.push_back(24);
    list.push_back(3);
    list.push_back(1);


    LList<double> sndList;
    sndList.push_back(3);
    sndList.push_back(25);
    sndList.push_back(4);
    sndList.push_back(2);

    list.map_increment(1);

    CHECK(list == sndList);
}


TEST_CASE("testing list map multiply")
{
    LList<double> list;
    list.push_back(2);
    list.push_back(24);
    list.push_back(3);
    list.push_back(1);


    LList<double> sndList;
    sndList.push_back(4);
    sndList.push_back(48);
    sndList.push_back(6);
    sndList.push_back(2);

    list.map_multiply(2);

    CHECK(list == sndList);
}

TEST_CASE("testing list srt slice")
{
    LList<double> list;
    list.push_back(2);
    list.push_back(24);
    list.push_back(3);
    list.push_back(1);


    LList<double> sndList;
    sndList.push_back(3);
    sndList.push_back(1);

    list.srt_slc(2);

    CHECK(list == sndList);
}

TEST_CASE("testing list rmv duplicates")
{
    LList<double> list;
    list.push_back(2);
    list.push_back(24);
    list.push_back(3);
    list.push_back(3);
    list.push_back(1);


    LList<double> sndList;
    sndList.push_back(2);
    sndList.push_back(24);
    sndList.push_back(3);
    sndList.push_back(1);

    list.remove_duplicates();

    CHECK(list == sndList);
}