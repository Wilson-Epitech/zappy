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
 *
 * @return void
*/

void Ia::Args::setPort(int port)
{
    this->_port = port;
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
 *
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
 *
 * @return void
*/

void Ia::Args::setMachineName(std::string machineName)
{
    this->_machineName = machineName;
}

/**
 * @brief Stores arguments
 *
 * @return void
*/

void Ia::Args::store(int argc, const char *argv[])
{
    if (argc != 4) {
        throw Ia::Error::InvalidArguments();
    }
    this->setPort(std::stoi(argv[1]));
    this->setTeamName(argv[2]);
    this->setMachineName(argv[3]);
    std::cout << "port: " << this->getPort() << "\nTeam Name: " << this->getTeamName()
    << "\nMachine Name: " << this->getMachineName() << '\n';
}