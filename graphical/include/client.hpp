/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** client
*/

#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <boost/asio.hpp>
#include <thread>
#include <vector>
#include <mutex>
#include "Character.hpp"
#include "Resources.hpp"
#include "Tile.hpp"

class Client {
public:
    Client(const std::string& host, short port);
    ~Client();

    void start_cli();

    const std::vector<Character>& getCharacters() const;
    const std::vector<Resources>& getResources() const;
    int getMapWidth() const;
    int getMapHeight() const;
    int getPinLv() const;
    int getPinFood() const;
    int getPinLinemate() const;
    int getPinDeraumere() const;
    int getPinSibur() const;
    int getPinMendiane() const;
    int getPinPhiras() const;
    int getPinThystame() const;

    std::vector<std::string> getTeamNames() const;

private:
    void connect();
    void stop();
    void send(const std::string& message);
    void receive();
    void get_pnw(std::vector<std::string> tokens);
    void get_ppo(std::vector<std::string> tokens);
    void get_msz(std::vector<std::string> tokens);
    void get_tna(std::vector<std::string> tokens);
    void get_bct(std::vector<std::string> tokens);
    void get_pin(std::vector<std::string> tokens);
    void get_plv(std::vector<std::string> tokens);
    void get_pdi(std::vector<std::string> tokens);

    boost::asio::io_context io_context_;
    boost::asio::ip::tcp::socket socket_;
    boost::asio::ip::tcp::endpoint endpoint_;

    std::vector<Character> characters_;
    mutable std::mutex charactersMutex_;
    std::vector<Resources> resources_;
    mutable std::mutex resourcesMutex_;
    mutable std::mutex boardMutex_;

    int mapWidth;
    int mapHeight;
    std::vector<std::string> teamNames;

    int pinLv;
    int pinFood;
    int pinLinemate;
    int pinDeraumere;
    int pinSibur;
    int pinMendiane;
    int pinPhiras;
    int pinThystame;
};

#endif // CLIENT_HPP
