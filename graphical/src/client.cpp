/*
** ZAPPY PROJECT, 2024
** backup_start_server_graphic
** File description:
** client
*/

#include "../include/client.hpp"
#include <iostream>
#include <boost/bind/bind.hpp>

using boost::asio::ip::tcp;

Client::Client(const std::string& host, short port)
    : socket_(io_service_)
{
    tcp::resolver resolver(io_service_);
    tcp::resolver::query query(host, std::to_string(port));
    tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);

    boost::asio::connect(socket_, endpoint_iterator);
    std::cout << "Connected to " << host << ":" << port << std::endl;
}

void Client::start()
{
    do_read();

    std::string message;
    while (true) {
        if (std::getline(std::cin, message)) {
            do_write(message);
        } else {
            break;
        }
    }

    io_service_.run();
}

void Client::do_read()
{
    boost::asio::async_read_until(socket_, response_buffer_, "\n",
        boost::bind(&Client::handle_read, this,
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
}

void Client::handle_read(const boost::system::error_code& error, std::size_t /*bytes_transferred*/)
{
    if (!error) {
        std::istream is(&response_buffer_);
        std::string response;
        std::getline(is, response);
        std::cout << "Server response: " << response << std::endl;

        do_read();
    } else {
        std::cerr << "Error reading from server: " << error.message() << std::endl;
    }
}

void Client::do_write(const std::string& message)
{
    boost::asio::async_write(socket_, boost::asio::buffer(message + "\n"),
        boost::bind(&Client::handle_write, this,
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
}

void Client::handle_write(const boost::system::error_code& error, std::size_t /*bytes_transferred*/)
{
    if (error) {
        std::cerr << "Error writing to server: " << error.message() << std::endl;
    }
}
