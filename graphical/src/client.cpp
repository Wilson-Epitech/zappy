/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** client
*/

#include "client.hpp"
#include <iostream>

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
        std::thread receive_thread([this]() {io_context_.run();});
        receive_thread.detach();

        std::thread input_thread([this]() {
            while (1) {
                std::string message;
                std::getline(std::cin, message);
                send(message);
            }
        });
        input_thread.detach();

        std::string initial_message = "GRAPHIC";
        send(initial_message);

        while (1) {
            receive();
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

static std::vector<std::string> split(const std::string &str, char delimiter)
{
    std::vector<std::string> tokens;
    std::istringstream iss(str);
    std::string token;

    while (std::getline(iss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

void Client::get_pnw(std::vector<std::string> tokens)
{
    int player_id = std::stoi(tokens[1]);
    int player_pos_x = std::stoi(tokens[2]);
    int player_pos_y = std::stoi(tokens[3]);
    int player_orientation = std::stoi(tokens[4]);
    int player_level = std::stoi(tokens[5]);
    std::string team_name = tokens[6];

    std::lock_guard<std::mutex> lock(charactersMutex_);
    characters_.emplace_back(player_id, player_pos_x, player_pos_y, player_orientation, player_level, team_name);
}

void Client::get_ppo(std::vector<std::string> tokens)
{
    int player_id = std::stoi(tokens[1]);
    int player_pos_x = std::stoi(tokens[2]);
    int player_pos_y = std::stoi(tokens[3]);
    int player_orientation = std::stoi(tokens[4]);

    std::lock_guard<std::mutex> lock(charactersMutex_);
    for (auto& character : characters_) {
        if (character.getId() == player_id) {
            character.setPosX(player_pos_x);
            character.setPosY(player_pos_y);
            character.setOrientation(player_orientation);
            break;
        }
    }
}

void Client::receive()
{
    try {
        boost::asio::streambuf buf;
        boost::asio::read_until(socket_, buf, "\n");
        std::istream is(&buf);
        std::string message;
        std::getline(is, message);
        std::cout << "Server: " << message << std::endl;

        std::vector<std::string> tokens = split(message, ' ');
        if (tokens.size() > 0 && tokens[0] == "pnw")
            get_pnw(tokens);
        if (tokens.size() > 0 && tokens[0] == "ppo")
            get_ppo(tokens);
    } catch (std::exception &e) {
        std::cerr << "Exception in receive: " << e.what() << std::endl;
        return;
    }
}

const std::vector<Character>& Client::getCharacters() const
{
    std::lock_guard<std::mutex> lock(charactersMutex_);
    return characters_;
}
