#include "Stud.h"
#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"

// testuojame konstruktorius
TEST_CASE("konstruktorius", "[konstruktorius]") {
    Stud stud;
    REQUIRE(stud.getVardas() == "");
    REQUIRE(stud.getPavarde() == "");
    REQUIRE(stud.getEgz() == 0);
}

//getteriai setteriai
TEST_CASE("getteriai setteriai", "[getteria][setteriai]") {
    Stud stud;
    stud.setVardas("Emilija");
    stud.setPavarde("Abromaityte");
    stud.setEgz(10);

    REQUIRE(stud.getVardas() == "Emilija");
    REQUIRE(stud.getPavarde() == "Abromaityte");
    REQUIRE(stud.getEgz() == 10);
}

// kopijavimo konstruktorius
TEST_CASE("kopijavimo konstruktorius", "[kopijavimo konstruktorius]") {
    Stud stud;
    stud.setVardas("Emilija");
    stud.setPavarde("Abromaityte");
    stud.setOnePaz(10);
    stud.setOnePaz(7);
    stud.setEgz(9);

    Stud stud2 = stud;

    REQUIRE(stud2.getVardas() == stud.getVardas());
    REQUIRE(stud2.getPavarde() == stud.getPavarde());
    REQUIRE(stud2.getNd() == stud.getNd());
    REQUIRE(stud2.getEgz() == stud.getEgz());
}

//kopijavimo priskyrimo operatoriaus
TEST_CASE("kopijavimo priskyrimas", "[kopijavimo priskyrimas]") {
    Stud stud;
    stud.setVardas("Emilija");
    stud.setPavarde("Abromaityte");
    stud.setOnePaz(10);
    stud.setOnePaz(7);
    stud.setEgz(9);

    Stud stud3;
    stud3 = stud;

    REQUIRE(stud3.getVardas() == stud.getVardas());
    REQUIRE(stud3.getPavarde() == stud.getPavarde());
    REQUIRE(stud3.getNd() == stud.getNd());
    REQUIRE(stud3.getEgz() == stud.getEgz());
}


