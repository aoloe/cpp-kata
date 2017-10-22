#include <vector>
#include <iostream>

#include <chrono>
#include <thread>

#include <numeric>

using Row = std::vector<int>;
using World = std::vector<Row>;

/*
World world = {
    {0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
};
*/

/*
World world = {
    {0, 0, 1, 0, 0},
    {1, 0, 1, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
};
*/

World world = {
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
};

void show(World world)
{
    for (Row row: world) {
        for (int cell: row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

World evolve(World world)
{
    int height = world.size();
    int width = world.at(0).size();
    World future(width, Row(height, 0));
    show(future);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int count = 0;
            for (int yy = y - 1; yy <= y + 1; yy++) {
                for (int xx = x - 1; xx <= x + 1; xx++) {
                    if (world.at((yy + height) % height).at((xx + width) % width) == 1) {
                        count++;
                    }
                }
            }
            if (world.at(y).at(x) == 1) {
                count--;
            }
            future.at(y).at(x) = (count == 3 || (count == 2 && world.at(y).at(x) == 1));
        }
    }
    return future;
}

bool hasLife(World world)
{
    return std::accumulate(world.begin(), world.end(), 0, [](int t, Row r) {return t + std::accumulate(r.begin(), r.end(), 0);}) > 0;
}

int main()
{
    while (hasLife(world)) {
        using namespace std::chrono_literals;
        show(world);
        // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::this_thread::sleep_for(1s);
        world = evolve(world);
    }
}
