/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** IA
*/

#ifndef IA_HPP_
    #define IA_HPP_
    #include <string>

/**
 * @brief Interface for the IA
 *
*/
namespace Ia {
    class IA {
        public:
            /**
             * @brief Construct a new IA object
             *
            */
            virtual ~IA() = default;
            /**
             * @brief Server Connection
             *
             * @param ip 
             * @param port 
             * @param teamName 
            */
            virtual void ServerConnection(const std::string &ip, int port, const std::string &teamName) = 0;
    };
}

#endif /* !IA_HPP_ */
