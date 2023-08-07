#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "log.h"

class GlslDealConfig
{
    public:
        GlslDealConfig() {}
        ~GlslDealConfig() {}
    
    public:
        void ReadGlslFile(const std::string& filename,std::string& glsl);

};