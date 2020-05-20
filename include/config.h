#include <string>
#include <fstream>

using std::string;

class Config
{
private:

public:
    bool read(string);
    bool write(string);
};