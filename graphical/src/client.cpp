/*
** ZAPPY PROJECT, 2024
** backup_start_server_graphic
** File description:
** client
*/

#include "client.hpp"

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

void get_pnw(std::vector<std::string> tokens)
{
    int player_id = std::stoi(tokens[1]);
    std::cout << "player id : " << player_id << std::endl;
    int player_pos_x = std::stoi(tokens[2]);
    std::cout << "x : " << player_pos_x << std::endl;
    int player_pos_y = std::stoi(tokens[3]);
    std::cout << "y : " << player_pos_y << std::endl;
    int player_orientation = std::stoi(tokens[4]);
    std::cout << "orientation : " << player_orientation << std::endl;
    int player_level = std::stoi(tokens[5]);
    std::cout << "level : " << player_level << std::endl;
    std::string team_name = tokens[6];
    std::cout << "Team name : " << team_name << std::endl;
}

void get_ppo(std::vector<std::string> tokens)
{
    int player_id = std::stoi(tokens[1]);
    std::cout << "player id : " << player_id << std::endl;
    int player_pos_x = std::stoi(tokens[2]);
    std::cout << "x : " << player_pos_x << std::endl;
    int player_pos_y = std::stoi(tokens[3]);
    std::cout << "y : " << player_pos_y << std::endl;
    int player_orientation = std::stoi(tokens[4]);
    std::cout << "orientation : " << player_orientation << std::endl;
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
        // if (message.substr(0, 3) == "ppo")
        //     std::cout << "New pos" << std::endl;
        // if (message.substr(0, 3) == "plv")
        //     std::cout << "Player lvl !!!" << std::endl;
        // if (message.substr(0, 3) == "pin")
        //     std::cout << "Player's Inventory !!!" << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception in receive: " << e.what() << std::endl;
        return;
    }
    return;
}


// void Client::receive()
// {
//     try {
//         boost::asio::streambuf buf;
//         boost::asio::read_until(socket_, buf, "\n");
//         std::istream is(&buf);
//         std::string message;
//         std::getline(is, message);
//         std::cout << "Server: " << message << std::endl;
//         if (message.substr(0, 3) == "pnw")
//             std::cout << "New player !!!" << std::endl;
//         if (message.substr(0, 3) == "ppo")
//             std::cout << "New pos" << std::endl;
//         if (message.substr(0, 3) == "plv")
//             std::cout << "Player lvl !!!" << std::endl;
//         if (message.substr(0, 3) == "pin")
//             std::cout << "Player's Inventory !!!" << std::endl;
//     } catch (std::exception &e) {
//         std::cerr << "Exception in receive: " << e.what() << std::endl;
//     }
// }

// void Client::receive()
// {
//     boost::asio::streambuf buf;
//     boost::asio::read_until(socket_, buf, "\n");
//     std::istream is(&buf);
//     std::string message;
//     std::getline(is, message);
//     std::cout << "Server: " << message << std::endl;
// }
