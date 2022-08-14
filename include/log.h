#ifndef LOG_H
#define LOG_H


#include <iostream>
#include <string>

class Log {

    public :
        void static debug(std::string msg);
        void static info (std::string  msg);
        void static error (std::string  msg);
        void static fatal(std::string  msg);

};




#endif