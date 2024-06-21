/*
** ZAPPY PROJECT, 2024
** zappy
** File description:
** server
*/


#pragma once

#include <iostream>
#include <boost/asio.hpp>
#include <thread>

class Client
{
public:
    Client(const std::string &host, short port);
    ~Client();

    void start_cli();

private:
    void connect();
    void stop();
    void send(const std::string &message);
    void receive();

    boost::asio::io_context io_context_;
    boost::asio::ip::tcp::socket socket_;
    boost::asio::ip::tcp::endpoint endpoint_;
    boost::asio::streambuf buffer_;
};
