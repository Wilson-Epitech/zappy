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
            /**
             * @brief Get the Port object
             *
             * @return int
            */
            int getPort() const;
            /**
             * @brief Set the Port object
             *
             * @param port
            */
            void setPort(std::string port);
            /**
             * @brief Get the Team Name object
             *
             * @return std::string
            */
            std::string getTeamName() const;
            /**
             * @brief Set the Team Name object
             *
             * @param teamName
            */
            void setTeamName(std::string teamName);
            /**
             * @brief Get the Machine Name object
             *
             * @return std::string
            */
            std::string getMachineName() const;
            /**
             * @brief Set the Machine Name object
             *
             * @param machineName
            */
            void setMachineName(std::string machineName);
            /**
             * @brief Store the arguments
             *
             * @param argc 
             * @param argv 
            */
            void store(int argc, const char *argv[]);
        private:
            int _port;
            std::string _teamName;
            std::string _machineName;
    };
};

#endif /* !ARGS_HPP_ */
