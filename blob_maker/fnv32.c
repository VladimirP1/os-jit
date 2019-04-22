unsigned int fnv32(char const* str) {
    unsigned int hash = 0x811c9dc5;
    while (*str)
    {
        hash *= 0x01000193;
        hash ^= (unsigned int)*(str++);
    }
    return hash;
}

void _start() {}
