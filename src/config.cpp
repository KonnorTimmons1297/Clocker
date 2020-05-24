#include <iostream>

#include "config.h"

#include "json.hpp"
#include "util.h"

using json = nlohmann::json;

static const char * KEY_LAST_USER = "LAST_USER";

Config::Config(string file_path)
{
    if (file_path.length() == 0)
    {
        std::cout << "Config::Config() ==> file_path is empty" << std::endl;
        exit(1);
    }

    if (!file_util::exists(file_path.c_str()))
    {
        // file_util::create(file_path);
    }

    string config_data = file_util::read(file_path.c_str());
    
    //Deserialization
    // Config config;
    // auto obj = json::parse(config_data);
    // config.last_user = obj[KEY_LAST_USER];
    // return config;
}

bool Config::save(string file_path)
{
    if(file_path.length() == 0)
    {
        std::cout << "Config::save() => file_path is empty" << std::endl;
        return false;
    }

    //Open the file

    //Serialize the data
    // json obj;
    // obj[KEY_LAST_USER] = last_user;
    // return obj.dump();

    //write to file

    return true;
}