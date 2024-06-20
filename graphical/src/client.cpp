/*
** ZAPPY PROJECT, 2024
** backup_start_server_graphic
** File description:
** client
*/

#include "../include/client.hpp"

Client::Client(const std::string &host, short port)
    : io_context_(), socket_(io_context_), endpoint_(boost::asio::ip::address::from_string(host), port)
{
    connect();
}

Client::~Client()
{
    stop();
}

void Client::start_cli()
{
    try {
        std::thread t([this]() {io_context_.run();});
        t.detach();

        while (1) {
            receive();

            std::string message;
            std::getline(std::cin, message);
            send(message);
        }
    } catch (std::exception &e) {
        std::cerr << "Exception in start_cli: " << e.what() << "\n";
    }
}

void Client::connect()
{
    socket_.connect(endpoint_);
    std::cout << "Connected to the server." << std::endl;
}

void Client::stop()
{
    socket_.close();
}

void Client::send(const std::string &message)
{
    boost::asio::write(socket_, boost::asio::buffer(message + "\n"));
}


void Client::receive()
{
    boost::asio::streambuf buf;
    boost::asio::read_until(socket_, buf, "\n");
    std::istream is(&buf);
    std::string message;
    std::getline(is, message);
    std::cout << "Server: " << message << std::endl;
}
