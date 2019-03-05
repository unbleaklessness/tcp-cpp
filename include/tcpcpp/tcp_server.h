#pragma once

#include <netinet/in.h>
#include <string>

class tcp_server {
public:
    /**
     * Opens TCP connection on given port at local IP address.
     * @param port Port number.
     */
    explicit tcp_server(uint16_t port);

    /**
     * Start listening and accepting connections.
     */
    void start();

    /**
     * Stop listening and accepting connections.
     */
    void stop();

    /**
     * Read a message from the connection.
     * @param message_size How many bytes to read.
     * @return Received message.
     */
    std::string receive(size_t message_size);

private:
    int sock;
    sockaddr_in sock_address;
    int connection;

    bool started = false;
};

