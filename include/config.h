#include <string>
#include <fstream>

using std::string;

class Config
{
public:
    string last_user;

public:
    Config() { }
    Config(string file_path);

    bool save(string file_path);
};
