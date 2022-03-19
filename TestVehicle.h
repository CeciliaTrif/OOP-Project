#ifndef PROIECTOOP_TESTVEHICLE_H
#define PROIECTOOP_TESTVEHICLE_H

class TestVehicle {
private:
    static void testImplicitConstructor();
    static void testConstructorWithParameters();
    static void testCopyConstructor();

    static void testSetIdentificationNumber();
    static void testSetBrand();
    static void testSetName();
    static void testSetColor();
    static void testSetRented();
    static void testSetPrice();

    static void testAssignmentOperator();
    static void testEqualityOperator();
public:
    static void testAll();
};


#endif //PROIECTOOP_TESTVEHICLE_H
