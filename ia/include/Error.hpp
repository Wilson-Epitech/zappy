/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_
#include <iostream>

namespace Ia {
    namespace Error {
        class InvalidArguments: public std::exception {
            public:
                InvalidArguments() = default;
                const char *what() const noexcept override;
                ~InvalidArguments() = default;
        };
        class StringPort: public std::exception {
            public:
                StringPort() = default;
                const char *what() const noexcept override;
                ~StringPort() = default;
        };
        class WrongServerConnection: public std::exception {
            public:
                WrongServerConnection() = default;
                const char *what() const noexcept override;
                ~WrongServerConnection() = default;
        };
    };
};

#endif /* !ERROR_HPP_ */
