#include <sys/mman.h>

#include <iostream>
#include <cstring>
#include <errno.h>

#include "code_xor.h"

int main() {
    int ret;
    void* exec;

    exec = mmap(0, code_xor_bin_len, PROT_READ|PROT_WRITE, MAP_ANON|MAP_PRIVATE, -1, 0);

    if (exec == MAP_FAILED) {
        std::cerr << "Could not allocate memory: " << strerror(errno) << std::endl;
        return EXIT_FAILURE;
    }

    memcpy(exec, code_xor_bin, code_xor_bin_len);

    for (size_t i = 0; i < code_xor_bin_len; ++i) {
        ((unsigned char*) exec) [i] ^= KEY;
    }

    ret = mprotect(exec, code_xor_bin_len, PROT_EXEC);

    if (ret < 0) {
        std::cerr << "Could not set execute premission: " << strerror(errno) << std::endl;
        return EXIT_FAILURE;
    }

    std::string s;

    std::cout << "Enter a string:" << std::endl;

    std::getline(std::cin, s);

    unsigned int hash = ((unsigned int (*) (const char*)) exec) (s.c_str());

    std::cout << "The line's hash is: " << hash << std::endl;


    ret = munmap(exec, code_xor_bin_len);
    if (ret < 0) {
        std::cerr << "Could not deallocate memory: " << strerror(errno) << std::endl; 
    }

}
