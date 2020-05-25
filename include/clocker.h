#include <vector>

#include "config.h"
#include "user.h"

using std::vector;

enum class ClockAction {
    In,
    Out
};

class ClockerConfig : public Config {
public:
    bool first_open = false;
    vector<User> users;

    string last_user;

public:
    ClockerConfig();

    bool save() override;

protected:
    string serialize();

    void deserialize(const string &);
};