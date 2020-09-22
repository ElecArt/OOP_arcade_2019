/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

#include "Core.hpp"
#include "include.hpp"

int main(int argc, char **argv)
{
    std::unique_ptr<Core> core;

    if (argc != 2) {
        std::cout << "Usage: ./arcade lib_path" << std::endl;
        return (84);
    }
    if (file_is_good(argv[1]) == false)
        return (84);
    try {
        core = std::make_unique<Core>(argv[1]);
        core->start();
    }
    catch (const std::exception &ex) {
        std::cout << ex.what() << std::endl;
        return (84);
    }
    return (0);
}

bool file_is_good(std::string filename)
{
    std::ifstream infile(filename);
    int i;

    if (infile.good() == false) {
        std::cout << "Lib does not exist!" << std::endl;
        return (false);
    }
    else {
        infile.read((char*)&i, sizeof(int));
        if (i != 0x464C457F) {
            std::cout << "Lib is not an ELF binary!" << std::endl;
            return (false);
        }
        else
            return (true);
    }
}