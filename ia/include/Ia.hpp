/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** Ia
*/

#ifndef IA_HPP_
#define IA_HPP_
    #include <iostream>

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

#endif /* !IA_HPP_ */
