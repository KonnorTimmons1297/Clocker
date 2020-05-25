#include "user.h"

#include <utility>

User::User(string user_name) {
    name = std::move(user_name);
}
