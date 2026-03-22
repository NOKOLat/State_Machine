#ifndef LOG_HPP
#define LOG_HPP

#include <iostream>

#pragma once
#include <iostream>

#ifdef PC_DEBUG
#define LOG(x) std::cout << x << std::endl
#else
#define LOG(x)
#endif

#endif /* LOG_HPP */