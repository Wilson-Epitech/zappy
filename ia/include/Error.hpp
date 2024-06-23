/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** Error
*/

#ifndef ERROR_HPP_
    #define ERROR_HPP_
    #include <iostream>

/**
 * @brief Error handling for the IA
 *
*/
namespace Ia {
    namespace Error {
        /**
         * @brief Class error representing the InvalidArguments
         *
        */
        class InvalidArguments: public std::exception {
            public:
                InvalidArguments() = default;
                const char *what() const noexcept override;
                ~InvalidArguments() = default;
        };
        /**
         * @brief Class error representing the StringPort
         *
        */
        class StringPort: public std::exception {
            public:
                StringPort() = default;
                const char *what() const noexcept override;
                ~StringPort() = default;
        };
        /**
         * @brief Class error representing the InvalidPort
         *
        */
        class WrongServerConnection: public std::exception {
            public:
                WrongServerConnection() = default;
                const char *what() const noexcept override;
                ~WrongServerConnection() = default;
        };
        /**
         * @brief Class error representing the InvalidPort
         *
        */
        class TeamAlreadyConnected: public std::exception {
            public:
                TeamAlreadyConnected() = default;
                const char *what() const noexcept override;
                ~TeamAlreadyConnected() = default;
        };
    };
};

#endif /* !ERROR_HPP_ */
