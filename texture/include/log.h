#pragma once

#include <iostream>
#include <string>
#include <map>

#include <cstdio>
#include <libgen.h>

#define __FILENAME__ basename((char *)__FILE__)

#define MAX_MESSAGE_LEN 1024

#define _LOG(level, format, args...)                                                                                                                  \
    {                                                                                                                                                 \
        char msg[MAX_MESSAGE_LEN] = {0};                                                                                                              \
        std::string log_src = std::string(__FILENAME__) + std::string(" ") + std::string(__FUNCTION__) + std::string(" ") + std::to_string(__LINE__); \
        snprintf(msg, MAX_MESSAGE_LEN - 1, format, ##args);                                                                                           \
        if (std::string(level) == "<DEBUG>")                                                                                                          \
        {                                                                                                                                             \
            std::cout << "\033[33m" << level << " " << log_src << " 行: " << msg << "\033[0m " << std::endl;                                          \
        }                                                                                                                                             \
        if (std::string(level) == "<ERROR>")                                                                                                          \
        {                                                                                                                                             \
            std::cout << "\033[31m" << level << " " << log_src << " 行: " << msg << "\033[0m " << std::endl;                                          \
        }                                                                                                                                             \
        if (std::string(level) == "<INFO >")                                                                                                          \
        {                                                                                                                                             \
            std::cout << "\033[36m" << level << " " << log_src << " 行: " << msg << "\033[0m " << std::endl;                                          \
        }                                                                                                                                             \
    }

#define LOGD(format, args...) _LOG("<DEBUG>", format, ##args);
#define LOGE(format, args...) _LOG("<ERROR>", format, ##args);
#define LOGI(format, args...) _LOG("<INFO >", format, ##args);

