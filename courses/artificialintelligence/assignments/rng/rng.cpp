#include <cstdint>
#include <fstream>
int main()
{
    int seed;
    int numbers;
    int rangeMin;
    int rangeMax;
    std::fstream fin;
    fin.open("test-a.in");
    fin >> seed >> numbers >> rangeMin >> rangeMax;
    seed << 13;
    seed xor (seed << 13);
    seed >> 17;
    seed xor(seed >> 17);
}