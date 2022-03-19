#ifndef PROIECTOOP_TESTUTILITYVEHICLE_H
#define PROIECTOOP_TESTUTILITYVEHICLE_H


class TestUtilityVehicle {
private:
    static void testImplicitConstructor();
    static void testConstructorWithParameters();
    static void testCopyConstructor();

    static void testSetIsStreetLegal();
    static void testSetType();

    static void testAssignmentOperator();
    static void testEqualityOperator();
public:
    static void testAll();
};


#endif //PROIECTOOP_TESTUTILITYVEHICLE_H
