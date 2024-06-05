/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** Main
*/

#include "Args.hpp"
#include "Error.hpp"
#include "Bot.hpp"


/**
 * @brief This is the main function for the Artificial Intelligence
 * @param argc int: The number of arguments
 * @param argv char*[]: An array of those arguments
 * @return int
*/

int main(int argc, const char *argv[])
{
    try {
        Ia::Args args;
        Ia::Bot ia;

        args.store(argc, argv);
        ia.ServerConnection(args.getMachineName(), args.getPort(), args.getTeamName());
        return 0;
    } catch(const Ia::Error::InvalidArguments &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    } catch(const Ia::Error::StringPort &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}
