#include <string>

using std::string;

class Config {
public:
    Config(const string &config_dir, const string &file_name);

    virtual bool save() = 0;

protected:
    string config_dir;
    string file_name;
};
