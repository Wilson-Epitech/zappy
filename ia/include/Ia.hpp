/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** IA
*/

#ifndef IA_HPP_
#define IA_HPP_
#include <string>

namespace Ia {
    class IA {
        public:
            virtual ~IA() = default;
            virtual void ServerConnection(const std::string &ip, int port, const std::string &teamName) = 0;
    };
}

#endif /* !IA_HPP_ */
