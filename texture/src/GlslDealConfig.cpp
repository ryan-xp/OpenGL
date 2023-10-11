#include "GlslDealConfig.h"

void GlslDealConfig::ReadGlslFile(const std::string& filename,std::string& glsl)
{
    std::ifstream ifs(filename,std::ios::in);
    if(!ifs.is_open())
    {
        LOGE("open %s failed",filename.c_str());
        return;
    }
    std::ostringstream fs;
    fs << ifs.rdbuf();
    glsl = fs.str();
}
