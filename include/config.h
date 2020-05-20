#include <string>
#include <fstream>

using std::string;

class Config
{
private:
    string serialize();
public:
    bool create(string);
    bool read(string);
    bool write(string);
};
