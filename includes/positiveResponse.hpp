#ifndef positiveResponse_HPP
#define positiveResponse_HPP

#include "./Libs.hpp"

class Request;

responseData    processResponse(Request &request);
bool            verifyServerName(Request &request);
responseData    verifyRedirection(Request &request);//Não esta correto
int             resolveOption(std::string method);
bool            methodAllowed(Request &request);

responseData    getHandler(Request &request);
responseData    postHandler(Request &request);
responseData    deleteHandler(Request &request);
responseData    handleMethodDelete(Request &request);
responseData    handleMethodPost(Request &request);

responseData autoIndex(std::string root, std::string path, std::string port, Request request);

#endif
