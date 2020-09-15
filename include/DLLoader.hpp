/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** DLLoader
*/

#pragma once

#include <dlfcn.h>

template <typename T>
class DLLoader
{
     public:
        DLLoader<T>(std::string path)
        {
            _path = path;
            std::cout << "DLLoader : " << path;
            this->_lib = dlopen(path.c_str(), RTLD_LAZY);
            if (this->_lib == nullptr) {
                std::cout << " : dlopen fail" << std::endl;
                std::cout << dlerror() << std::endl;
                throw std::exception();
            }
            std::cout << std::endl;
        }
        ~DLLoader<T>()
        {
            std::cout << "DLLoader : " << _path << " dtor" << std::endl;
            if (this->_lib != nullptr)
                dlclose(this->_lib);
        }
        std::shared_ptr<T> getInstance()
        {
            auto instance = reinterpret_cast<std::shared_ptr<T>(*)()>(dlsym(this->_lib, "entry"));
            if (instance == nullptr) {
                std::cout << " : dlsym fail" << std::endl;
                std::cout << dlerror() << std::endl;
                throw std::exception();
            }
            return (instance());
        }
     private:
        std::string _path;
        void *_lib;
};