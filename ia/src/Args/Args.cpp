/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** Args
*/

#include "Ia.hpp"
#include "Error.hpp"

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
 * @return void
*/

void Ia::Args::setPort(std::string port)
{
    //faut faire des verifs sur le port
    this->_port = std::stoi(port);
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
 * @return void
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
 * @return void
*/

void Ia::Args::setMachineName(std::string machineName)
{
    this->_machineName = machineName;
}

/**
 * @brief Stores arguments. Should be called in the first place in the main function
 * @param argc The number of arguments same as main
 * @param argv An array of those arguments same as main
 * @return void
*/

void Ia::Args::store(int argc, const char *argv[])
{
    if (argc != 7) {
        throw Ia::Error::InvalidArguments();
    }
    if (argv[1] == "-p") {
        this->setPort(argv[2]);
    }
    if (argv[3] == "-n") {
        this->setTeamName(argv[4]);
    }
    if (argv[5] == "-h") {
        this->setMachineName(argv[6]);
    }
    std::cout << "port: " << this->getPort() << "\nTeam Name: " << this->getTeamName()
    << "\nMachine Name: " << this->getMachineName() << '\n';
}