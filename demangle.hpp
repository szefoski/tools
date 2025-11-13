#pragma once

#ifndef SZEFOSKI_HIDE

#include <cxxabi.h>
#include <memory>
#include <typeinfo>
#include <iostream>
#include <string_view>

namespace szefoski
{
namespace tools
{

template<typename T>
std::string demangle(const T &t) {
    int status;
    std::unique_ptr<char, void(*)(void*)> res{
        abi::__cxa_demangle(typeid(T).name(), nullptr, nullptr, &status),
        std::free
    };
    return (status == 0) ? res.get() : typeid(T).name();
}

template<typename T>
void demangle_print(const T &t, const std::string_view name = "Type") {
    std::cout << name << ": " << demangle(t) << std::endl;
}

}
}

#else

namespace szefoski
{
namespace tools
{

template<typename T>
std::string demangle(const T &t) {
    return {};
}

template<typename T>
void demangle_print(const T &t, const std::string_view name = "Type") {
}

}
}


#endif
