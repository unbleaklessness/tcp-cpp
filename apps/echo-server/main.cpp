#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>

#include "tcpcpp/tcp_server.h"

int main(int argc, char **argv) {
    if (argc > 1) {
        auto port = static_cast<uint16_t>(strtol(argv[1], nullptr, 10));
        if (port == 0) {
            std::cout << "Wrong port number!" << std::endl;
            return 1;
        }
        auto *server = new tcp_server(port);
        server->start();

        while (1) {
            std::string received = server->receive(64);

            if (received != "") {
                std::cout << received;
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    } else {
        std::cout << "Specify port number as the first parameter!" << std::endl;
        return 1;
    }

    return 0;
}