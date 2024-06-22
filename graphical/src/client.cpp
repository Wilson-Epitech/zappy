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
        send("msz");
        send("mct");

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

void Client::get_msz(std::vector<std::string> tokens)
{
    int map_width = std::stoi(tokens[1]);
    int map_height = std::stoi(tokens[2]);
    std::lock_guard<std::mutex> lock(boardMutex_);
    mapWidth = map_width;
    mapHeight = map_height;
}

void Client::get_tna(std::vector<std::string> tokens)
{
    std::vector<std::string> teamNames;
    for (size_t i = 1; i < tokens.size(); ++i) {
        std::string teamName = tokens[i];
        teamName.erase(std::remove(teamName.begin(), teamName.end(), '\n'), teamName.end());
        teamName.erase(std::remove(teamName.begin(), teamName.end(), '\r'), teamName.end());
        size_t tnaPos = teamName.rfind("tna");
        if (tnaPos != std::string::npos) {
            teamName = teamName.substr(0, tnaPos);
        }
        teamNames.push_back(teamName);
    }

    std::lock_guard<std::mutex> lock(boardMutex_);
    this->teamNames = teamNames;
}

void Client::get_bct(std::vector<std::string> tokens)
{
    int x = std::stoi(tokens[1]);
    int y = std::stoi(tokens[2]);
    int food = std::stoi(tokens[3]);
    int linemate = std::stoi(tokens[4]);
    int deraumere = std::stoi(tokens[5]);
    int sibur = std::stoi(tokens[6]);
    int mendiane = std::stoi(tokens[7]);
    int phiras = std::stoi(tokens[8]);
    int thystame = std::stoi(tokens[9]);

    std::lock_guard<std::mutex> lock(resourcesMutex_);

    bool found = false;
    for (auto& resources : resources_) {
        if (resources.getX() == x && resources.getY() == y) {
            resources.setFood(food);
            resources.setLinemate(linemate);
            resources.setDeraumere(deraumere);
            resources.setSibur(sibur);
            resources.setMendiane(mendiane);
            resources.setPhiras(phiras);
            resources.setThystame(thystame);
            found = true;
            break;
        }
    }
    if (!found) {
        resources_.emplace_back(x, y, food, linemate, deraumere, sibur, mendiane, phiras, thystame);
    }
}

void Client::get_pin(std::vector<std::string> tokens)
{
    int player = std::stoi(tokens[1]);
    int x = std::stoi(tokens[2]);
    int y = std::stoi(tokens[3]);
    int food = std::stoi(tokens[4]);
    int linemate = std::stoi(tokens[5]);
    int deraumere = std::stoi(tokens[6]);
    int sibur = std::stoi(tokens[7]);
    int mendiane = std::stoi(tokens[8]);
    int phiras = std::stoi(tokens[9]);
    int thystame = std::stoi(tokens[10]);
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
        if (tokens.size() > 0 && tokens[0] == "bct")
            get_bct(tokens);
        if (tokens.size() > 0 && tokens[0] == "pin")
            get_pin(tokens);
        if (tokens.size() > 0 && tokens[0] == "msz")
            get_msz(tokens);
        if (tokens.size() > 0 && tokens[0] == "tna")
            get_tna(tokens);
    } catch (std::exception &e) {
        std::cerr << "Exception in receive: " << e.what() << std::endl;
        return;
    }
}

const std::vector<Resources>& Client::getResources() const
{
    std::lock_guard<std::mutex> lock(resourcesMutex_);
    return resources_;
}

const std::vector<Character>& Client::getCharacters() const
{
    std::lock_guard<std::mutex> lock(charactersMutex_);
    return characters_;
}

int Client::getMapWidth() const
{
    return mapWidth;
}

int Client::getMapHeight() const
{
    return mapHeight;
}

std::vector<std::string> Client::getTeamNames() const
{
    return teamNames;
}
