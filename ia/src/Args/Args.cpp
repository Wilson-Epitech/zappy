/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** Args
*/

#include "Args.hpp"
#include "Error.hpp"
#include <cstring>

/**
 * @brief Returns the port
 *
 * @return int
*/
int Ia::Args::getPort() const
{
    return this->_port;
}

/**
 * @brief Sets the port
 * @param port The port to enter when compiling
*/
void Ia::Args::setPort(std::string port)
{
    int convertedPort = 0;

    convertedPort = std::atoi(port.c_str());
    if (convertedPort <= 0) {
        throw Ia::Error::StringPort();
    }
    this->_port = convertedPort;
}

/**
 * @brief Returns the team name
 *
 * @return std::string
*/
std::string Ia::Args::getTeamName() const
{
    return this->_teamName;
}

/**
 * @brief Sets the team name
 * @param teamName The team name to enter when compiling
*/
void Ia::Args::setTeamName(std::string teamName)
{
    this->_teamName = teamName;
}

/**
 * @brief Returns the machine name
 *
 * @return std::string
*/
std::string Ia::Args::getMachineName() const
{
    return this->_machineName;
}

/**
 * @brief Sets the machine name
 * @param machineName The machine name to enter when compiling
*/
void Ia::Args::setMachineName(std::string machineName)
{
    this->_machineName = machineName;
}

/**
 * @brief Stores arguments. Should be called in the first place in the main function
 * @param argc The number of arguments same as main
 * @param argv An array of those arguments same as main
*/
void Ia::Args::store(int argc, const char *argv[])
{
    if (argc != 7) {
        throw Ia::Error::InvalidArguments();
    }
    for (int i = 0; i < argc; ++i) {
        if (strcmp(argv[i], "-p") == 0 && argv[i + 1] != NULL) {
            this->setPort(argv[i + 1]);
        }
        if (strcmp(argv[i], "-n") == 0 && argv[i + 1] != NULL) {
            this->setTeamName(argv[i + 1]);
        }
        if (strcmp(argv[i], "-h") == 0 && argv[i + 1] != NULL) {
            this->setMachineName(argv[i + 1]);
        }
    }
    std::cout << "port: " << this->getPort() << "\nTeam Name: " << this->getTeamName()
    << "\nMachine Name: " << this->getMachineName() << '\n';
}