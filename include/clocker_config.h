#include <vector>

#include "config.h"
#include "timesheet.h"

using std::vector;

class ClockerConfig : public Config {
public:
    bool first_open = false;

public:
    //Serialized members
    string user_name;
    vector<Timesheet> timesheets;

public:
    ClockerConfig();

    bool save() override;

private:
    string serialize();

    void deserialize(const string &);
};