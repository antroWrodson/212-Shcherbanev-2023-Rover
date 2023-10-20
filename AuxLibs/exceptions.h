#pragma once

#include <exception>
#include <format>

class field_error: public std::exception
{
private:
    const char* message; 
public:
    field_error(const char* error_message): message(error_message)
    {}

    const char* what() const noexcept override
    {
        return message;     
    }
};

class controller_error: public std::exception
{
private:
    const char* message; 
public:
    controller_error(const char* error_message): message(error_message)
    {}

    const char* what() const noexcept override
    {
        return message;     
    }
};