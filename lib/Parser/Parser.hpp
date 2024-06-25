#pragma once

#include <string>

namespace deadnotxaa {

    struct Arguments {
        std::string path;
    };

    Arguments ParseArgs();

} // deadnotxaa
