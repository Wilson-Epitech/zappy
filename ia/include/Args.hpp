/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** Args
*/

#ifndef ARGS_HPP_
    #define ARGS_HPP_
    #include <iostream>

/**
 * @brief Args class for the IA
 *
*/
namespace Ia {
    class Args {
        public:
            int getPort() const;
            void setPort(std::string port);
            std::string getTeamName() const;
            void setTeamName(std::string teamName);
            std::string getMachineName() const;
            void setMachineName(std::string machineName);
            void store(int argc, const char *argv[]);
        private:
            int _port;
            std::string _teamName;
            std::string _machineName;
    };
};

#endif /* !ARGS_HPP_ */
