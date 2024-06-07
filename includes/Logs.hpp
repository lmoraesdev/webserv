#pragma once

#ifndef LOGS_HPP
#define LOGS_HPP

#include "./Libs.hpp"

class Logs{

	public:
		enum typeLog{
			INFO,
			WARNING,
			ERROR,
			VERBOSE
		};

		Logs(void);
		~Logs(void);
		static void	printLog(typeLog type, int numberLog, std::string message);

	private:
		static	std::string _fullData;
		static 	std::string	_getFullData(void);

};

# endif
