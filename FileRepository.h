#ifndef PROIECTOOP_FILEREPOSITORY_H
#define PROIECTOOP_FILEREPOSITORY_H
#include "Repository.h"
#include <string>
using namespace std;

class FileRepository : public Repository {
private:
    string fileName;
public:
    FileRepository();
    explicit FileRepository(string);
    ~FileRepository() override;

    void addVehicle(Vehicle *) noexcept(false) override;
    void deleteVehicle(Vehicle *) noexcept(false) override;
    void updateVehicle(Vehicle *, Vehicle *) noexcept(false) override;

    void setFileName(string);
    void loadFromFile() noexcept(false);
    void saveToFile();
};


#endif //PROIECTOOP_FILEREPOSITORY_H
