#include <string>
#include <fstream>

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
    Config(string file_name) {

    }

    // Serialized output
    friend std::ostream& operator<<(std::ostream &os, const Config &m)
    {
        // return os << m.value << ' ' << m.factor << ' ' << m.type;
        json j;

        return os;
    }

    // Serialized input
    friend std::istream& operator>>(std::istream &is, Config &m)
    {
        // return is >> m.value >> m.factor >> m.type;
        return is;
    }
};
