/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** Bot
*/

#ifndef BOT_HPP_
#define BOT_HPP_
#include "Ia.hpp"

namespace Ia {
    class Bot : public IA {
        public:
            Bot() = default;
            ~Bot() = default;
            virtual void ServerConnection(const std::string &ip, int port, const std::string &teamName) override;

        protected:
        private:
    };
}

#endif /* !BOT_HPP_ */
