/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** main
*/

#include "GameLoop.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <thread>
#include "client.hpp"

void print_usage(const std::string& program_name) {
    std::cerr << "USAGE: " << program_name << " -p port -h machine" << std::endl;
    std::cerr << "option description" << std::endl;
    std::cerr << "-p port port number" << std::endl;
    std::cerr << "-h machine hostname of the server" << std::endl;
}

int client_start(int argc, char *const *argv)
{
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

    try {
        Client client(host, port);
        client.start_cli();
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}

int main(int argc, char *const *argv)
{
    std::thread t1(client_start, argc, argv);
    std::thread t2(gameLoop);
    t1.join();
    t2.join();
    return 0;
}