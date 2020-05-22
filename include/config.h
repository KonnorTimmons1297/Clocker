#include <string>
#include <fstream>

using std::string;

class Config
{
private:
    string serialize();
    Config deserialize(string);
public:
    string last_user;
    
    bool create(string);
    bool read(string);
    bool write(string);
};
