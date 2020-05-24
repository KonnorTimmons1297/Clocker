#include <string>
#include <fstream>

#include "json.hpp"
#include "util.h"

using std::string;

class Config
{
public:
    string last_user;

private:
    bool write(string);
    bool read(string);
    bool create(string);

public:
    Config(string file_path)
    {
        if (!file_util::exists(file_path.c_str()))
        {
            create(file_path);
        }
    }

    // Serialized output
    friend std::ostream &operator<<(std::ostream &os, const Config &m)
    {
        return os;
    }

    // Serialized input
    friend std::istream &operator>>(std::istream &is, Config &m)
    {
        // return is >> m.value >> m.factor >> m.type;
        return is;
    }
};
