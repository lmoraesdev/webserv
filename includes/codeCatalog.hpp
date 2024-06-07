#ifndef codeCatalog_HPP
#define codeCatalog_HPP

#include "./Libs.hpp"

std::string getStatus(std::string status, map_ss codes);
std::string getTypes(std::string extension, map_ss types);
map_ss setStatus(void);
map_ss setTypes(void);

#endif
