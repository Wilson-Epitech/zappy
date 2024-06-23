/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** main
*/

#include "Client.hpp"
#include "GameLoop.hpp"
#include <thread>

void print_usage(const std::string& program_name) {
    std::cerr << "USAGE: " << program_name << " -p port -h machine" << std::endl;
    std::cerr << "option description" << std::endl;
    std::cerr << "-p port port number" << std::endl;
    std::cerr << "-h machine hostname of the server" << std::endl;
}

int main(int argc, char *const *argv) {
    if (argc != 5) {
        print_usage(argv[0]);
        return 84;
    }

    std::string host;
    short port = 0;

    for (int i = 1; i < argc; i += 2) {
        std::string option = argv[i];
        if (option == "-p") {
            port = std::atoi(argv[i + 1]);
        } else if (option == "-h") {
            host = argv[i + 1];
        } else {
            print_usage(argv[0]);
            return 84;
        }
    }

    if (port == 0 || host.empty()) {
        print_usage(argv[0]);
        return 84;
    }

    Client client(host, port);

    std::thread client_thread([&client]() {
        client.start_cli();
    });

    gameLoop(client);

    client_thread.join();

    return 0;
}
