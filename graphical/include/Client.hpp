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

class Character;

/**
 * @brief
 * 
 */
class Client {
public:
    /**
     * @brief Construct a new Client object
     * 
     * @param host 
     * @param port 
     */
    Client(const std::string& host, short port);
    ~Client();

    /**
     * @brief 
     * 
     */
    void start_cli();

    /**
     * @brief Get the Characters object
     * 
     * @return const std::vector<Character>& 
     */
    const std::vector<Character>& getCharacters() const;
    /**
     * @brief Get the Resources object
     * 
     * @return const std::vector<Resources>& 
     */
    const std::vector<Resources>& getResources() const;
    /**
     * @brief Get the Map Width object
     * 
     * @return int 
     */
    int getMapWidth() const;
    /**
     * @brief Get the Map Height object
     * 
     * @return int 
     */
    int getMapHeight() const;
    /**
     * @brief Get the Pin Lv object
     * 
     * @return int 
     */
    int getPinLv() const;
    /**
     * @brief Get the Pin Food object
     * 
     * @return int 
     */
    int getPinFood() const;
    /**
     * @brief Get the Pin Linemate object
     * 
     * @return int 
     */
    int getPinLinemate() const;
    /**
     * @brief Get the Pin Deraumere object
     * 
     * @return int 
     */
    int getPinDeraumere() const;
    /**
     * @brief Get the Pin Sibur object
     * 
     * @return int 
     */
    int getPinSibur() const;
    /**
     * @brief Get the Pin Mendiane object
     * 
     * @return int 
     */
    int getPinMendiane() const;
    /**
     * @brief Get the Pin Phiras object
     * 
     * @return int 
     */
    int getPinPhiras() const;
    /**
     * @brief Get the Pin Thystame object
     * 
     * @return int 
     */
    int getPinThystame() const;

    /**
     * @brief Get the Team Names object
     * 
     * @return std::vector<std::string> 
     */
    std::vector<std::string> getTeamNames() const;
    /**
     * @brief 
     * 
     * @param message 
     */
    void send(const std::string& message);

private:
    void connect();
    void stop();
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
