
#include "gtest/gtest.h"
#include "studentai/Stud.h"  
#include <googletest-main/googletest/include/gtest/gtest.h>
#include <gtest.h>

//testuojamas konstruktorius
TEST(studentai, konstruktorius) {
    Stud stud;
    EXPECT_EQ(stud.getVardas(), "");
    EXPECT_EQ(stud.getEgz(), 0);
}

//testuojami getteriai ir setteriai
TEST(studentai, getteriaiSetteriai) {
    Stud stud;
    stud.setVardas("Emilija");
    stud.setPavarde("Abromaityte");
    stud.setEgz(10);
    EXPECT_EQ(stud.getVardas(), "Emilija");
    EXPECT_EQ(stud.getPavarde(), "Abromaityte");
    EXPECT_EQ(stud.getEgz(), 10);
}

//testuojamas kopijavimo konstruktorius
TEST(studentai, kopijavimoKonstruktorius) {
    Stud stud;
    stud.setVardas("Emilija");
    stud.setPavarde("Abromaityte");
    stud.setOnePaz(10);
    stud.setOnePaz(7);
    stud.setEgz(9);

    Stud stud2 = stud;
    EXPECT_TRUE(stud2.getVardas() == stud.getVardas());
    EXPECT_TRUE(stud2.getPavarde() == stud.getPavarde());
    EXPECT_TRUE(stud2.getNd() == stud.getNd());
    EXPECT_TRUE(stud2.getEgz() == stud.getEgz());
}

//testuojamas kopijavimo priskyrimo konstruktorius
TEST(studentai, kopijavimoPriskyrimoKonstruktorius) {
    Stud stud;
    stud.setVardas("Emilija");
    stud.setPavarde("Abromaityte");
    stud.setOnePaz(10);
    stud.setOnePaz(7);
    stud.setEgz(9);

    Stud stud3;
    stud3 = stud;
    EXPECT_TRUE(stud3.getVardas() == stud.getVardas());
    EXPECT_TRUE(stud3.getPavarde() == stud.getPavarde());
    EXPECT_TRUE(stud3.getNd() == stud.getNd());
    EXPECT_TRUE(stud3.getEgz() == stud.getEgz());
}    
