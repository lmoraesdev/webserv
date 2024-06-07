#ifndef postMethod_HPP
#define postMethod_HPP

#include "./Libs.hpp"

class PostMethod {

    private:
        Request         _req;
        responseData    _res;
        bool            _file;
        size_t          _bodySize;
        map_ss          _formData;

    public:
        PostMethod();
        PostMethod(Request request);
        ~PostMethod();

        responseData    handleMethod(void);
        bool            verifyLimit(void);
        bool            handleMultipart(void);
        void            handleForm(void);
        void            print(void);
        void            saveFile(std::string &fileName, const std::string &value);
        void            parseMultipartFormData(size_t pos, size_t endPos);
        bool            created;

};

responseData    getJson(std::string body, int status);
std::string     getDir(void);

#endif
