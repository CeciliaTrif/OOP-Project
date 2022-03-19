#ifndef PROIECTOOP_TESTCAR_H
#define PROIECTOOP_TESTCAR_H


class TestCar {
private:
    static void testImplicitConstructor();
    static void testConstructorWithParameters();
    static void testCopyConstructor();

    static void testSetIsSport();
    static void testSetType();

    static void testAssignmentOperator();
    static void testEqualityOperator();

public:
    static void testAll();
};


#endif //PROIECTOOP_TESTCAR_H
