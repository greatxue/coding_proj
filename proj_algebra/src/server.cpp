#include <random>
#include <memory>
#include <map>
#include <string>

#include "server.h"

Server::Server() 
{
    // leave blank
}

Server::add_client(std::string id) 
{
    std::uniform_int_distribution<int> dist(1000, 9999);
    std::random_divice rd;
    std::mt19937 rng(rd());

    auto it = clients.find(id);
    while (it != clients.end())
    {
        id += std::to_string(dist(rng()));
        it = clients.find(id);
    }

    auto new_client = std::make_shared<CLient>(id);
    clients[id] = new_client;
    return new_clent;
}