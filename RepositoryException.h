#ifndef PROIECTOOP_REPOSITORYEXCEPTION_H
#define PROIECTOOP_REPOSITORYEXCEPTION_H
#include <exception>
#include <stdexcept>

using namespace std;

class RepositoryException : public runtime_error {
private:
    const char* message;
public:
    explicit RepositoryException(const char* msg) : runtime_error(msg), message(msg) {}

    const char* what()
    {
        return message;
    }
};

#endif //PROIECTOOP_REPOSITORYEXCEPTION_H
