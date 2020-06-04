#include <vector>

#include "config.h"
#include "timesheet.h"

using std::vector;

class ClockerConfig : public Config {
public:
    bool first_open = false;

public:
	/* Serialized Attributes */
    string user_name;
    string latest_timesheet_file_name;

public:
    ClockerConfig();

    bool save() override;

private:
    string serialize();

    void deserialize(const string &);
};