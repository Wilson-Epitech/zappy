/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** server
*/

#include <iostream>
#include <netinet/ip.h>
#include <boost/asio.hpp>

#pragma once

class Client
{
    public:
        Client(const std::string &host, short port);
        void start();

    private:
        void do_read();
        void handle_read(const boost::system::error_code &error, std::size_t bytes_transferred);
        void do_write(const std::string& message);
        void handle_write(const boost::system::error_code &error, std::size_t bytes_transferred);

        boost::asio::io_service io_service_;
        boost::asio::ip::tcp::socket socket_;
        boost::asio::streambuf response_buffer_;
};
