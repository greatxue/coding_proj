#ifndef SERVER_H
#define SERVER_H

#include "crypto.h"

/* Class: Server
 * ----------------------------------------------------
 * A centralized server managing Client connections, transactions, and mining. 
 */
class Server
{
public:
    /* Constructor for Server class. */
    Server();

    /* Method: add_client
     * ----------------------------------------------------
     * 
     * Adds a client with the given ID or appends a unique identifier if ID already exists.
     * Each client is assigned with a starting balance of 5 coins.
     * 
     */
	std::shared_ptr<Client> add_client(std::string id);

    /* Method: get_client
     * ----------------------------------------------------
     * 
     * Retrieves a shared pointer to the client with the specified ID.
     *
     */
	std::shared_ptr<Client> get_client(std::string id);

    /* Method: get_wallet
     * ----------------------------------------------------
     * 
     * Returns the wallet balance of the client with the given ID.
     *
     */
	double get_wallet(std::string id);

    /* Method: parse_trx
     * ----------------------------------------------------
     *
     * Parses a transaction string and extracts sender, receiver, and value.
     * Throws a runtime error if the string format is incorrect.
     * 
     */
	bool parse_trx(std::string trx, std::string sender, std::string receiver, double value);
	
    /* Method: add_pending_trx
     * ----------------------------------------------------
     * 
     * Adds a transaction to the pending list if the sender's signature is authentic
     * and if the sender has sufficient balance.
     * 
     */
    bool add_pending_trx(std::string trx, std::string signature);
	
    /* Method: mine
     * ----------------------------------------------------
     *
     * Performs the mining process on the pending transactions.
     * Returns the nonce that results in a valid hash.
     *
     */
    size_t mine();


private:

    /* Maps a shared_ptr of the Client to its balance. */
	std::map<std::shared_ptr<Client>, double> clients;
};

#endif //SERVER_H