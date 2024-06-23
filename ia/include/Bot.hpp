/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** Bot
*/

#ifndef BOT_HPP_
    #define BOT_HPP_
    #include "Ia.hpp"
    #include <iostream>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <unistd.h>

/**
 * @brief Bot class
 *
*/
namespace Ia {
    class Bot : public IA {
        public:
            /**
             * @brief Construct a new Bot object
             *
            */
            Bot() = default;
            /**
             * @brief Destroy the Bot object
             *
            */
            ~Bot() = default;
            /**
             * @brief Server Connection
             *
             * @param ip 
             * @param port 
             * @param teamName 
            */
            virtual void ServerConnection(const std::string &ip, int port, const std::string &teamName) override;

        protected:
        private:
            int sock = 0;
    };
}

#endif /* !BOT_HPP_ */
