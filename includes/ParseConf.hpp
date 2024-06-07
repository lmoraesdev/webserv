#ifndef ParseConf_HPP
#define ParseConf_HPP

#include "./Libs.hpp"

std::string readFileContents(const std::string &filename);
std::string extractServerParams(const std::string &serverBlock);
std::vector<std::string> extractLocations(const std::string &serverBlock);
std::vector<std::string> separateServerBlocks(const std::string &config);
std::string getFirstWord(const std::string &text, int position);
int countWordOccurrencesLine(const std::string &text, const std::string &word);
std::string getParameterValue(const std::string &text, const std::string &parameter);
bool isNumeric(const std::string &str);
//old data
bool verifyLineEmpty(const std::string &text);
std::vector<std::string> splitTokens(const std::string str);
std::string rmSpaces(const std::string &input);
bool endBlock(const std::string &line);
void allocateServers(conf_servers *stConfServer, int qtLocation);
void deallocateServers(conf_servers *stConfServer, int qtLocation);

#endif
