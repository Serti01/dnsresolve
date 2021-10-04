#include "main.hpp"

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "USAGE: %s <HOSTNAME> [HOSTNAME...]\nie: %s www.example.com\n", argv[0], argv[0]);
        exit(EXIT_FAILURE);
    }

    // for every hostname in argv
    for (int i = 1; i < argc; i++) {
        char *host = argv[i];
        struct hostent *hostn = gethostbyname(host);
        
        // <hostname>:\t<ip>
        std::cout << hostn->h_name << ":\t" << strdup(inet_ntoa(
            *((struct in_addr*)hostn->h_addr_list[0])
        )) << std::endl;
    }

    return 0;
}