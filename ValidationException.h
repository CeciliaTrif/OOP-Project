#ifndef PROIECTOOP_VALIDATIONEXCEPTION_H
#define PROIECTOOP_VALIDATIONEXCEPTION_H

#include <utility>

#include "string"
#include "exception"

using namespace std;

class ValidationException : public exception {
private:
    string message;
public:
    ValidationException() : exception() {};
    explicit ValidationException(string msg) : exception() { this->message = move(msg); }
    ~ValidationException() override = default;

    string toString() {
        return message;
    }

    const char *what() const noexcept override {
        return message.c_str();
    }
};


#endif //PROIECTOOP_VALIDATIONEXCEPTION_H
