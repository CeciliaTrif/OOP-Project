#ifndef PROIECTOOP_FILEREPOSITORYEXCEPTION_H
#define PROIECTOOP_FILEREPOSITORYEXCEPTION_H
#include "exception"
#include "cstring"

using namespace std;

class FileRepositoryException : public exception {
private:
    char* message;
public:
    explicit FileRepositoryException(const char* message) {
        this->message = new char[strlen(message) + 1];
        strcpy(this->message, message);
    }

    ~FileRepositoryException() override {
        if (this->message == nullptr)
            return;
        delete[] this->message;
    }

    virtual const char* what()
    {
        return message;
    }
};


#endif //PROIECTOOP_FILEREPOSITORYEXCEPTION_H
