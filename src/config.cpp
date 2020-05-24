#include "config.h"

#include "json.hpp"
#include "util.h"

// string Config::serialize() {
//     json config_json;

//     config_json[""] = last_user;

//     return config_json.dump();
// }

// Config Config::deserialize(string config_json) {
//     auto json = json::parse(config_json);
//     Config test;
//     return test;
// }

bool Config::create(string file_path)
{
    return false;
}

bool Config::read(string file_path)
{
    if (file_path.length() == 0)
        return false;

    string config_data = file_util::read(file_path.c_str());
    string config_json(file_data);
    Config config = deserialize(config_json);

    return true;
}

bool Config::write(string file_name)
{
    return true;
}
