#include "main.hpp"

int main(int argc, char **argv) {
    // get hostname from args
    if (argc < 2) {
        fprintf(stderr, "USAGE: %s <HOSTNAME> [HOSTNAME...]\nie: %s www.example.com\n", argv[0], argv[0]);
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++) {
        char *host = argv[i];
        struct hostent *hostn = gethostbyname(host);
        
        std::cout << hostn->h_name << ":\t" << strdup(inet_ntoa(
            *((struct in_addr*)hostn->h_addr_list[0])
        )) << std::endl;
    }

    return 0;
}