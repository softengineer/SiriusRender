#include "log.h"


void  Log::debug(std::string msg) 
{
    std::cout <<"DEBUG :" << msg << std::endl;
}

void  Log::info (std::string  msg)
{
    std::cout <<"INFO :" << msg << std::endl;
}

void  Log::error (std::string  msg)
{
    std::cout <<"ERROR :" << msg << std::endl;
}

void  Log::fatal(std::string  msg)
{
    std::cout <<"FATAL :" << msg << std::endl;
}