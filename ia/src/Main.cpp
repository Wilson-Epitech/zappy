/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** Main
*/

#include "Ia.hpp"
#include "Error.hpp"


/**
 * @brief This is the main function for the Artificial Intelligence
 *
 * @return int
*/

int main(int argc, const char *argv[])
{
    try {
        Ia::Args args;

        args.store(argc, argv);
        return 0;
    } catch(const Ia::Error::InvalidArguments &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}
