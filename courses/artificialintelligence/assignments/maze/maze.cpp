#include <iostream>
#include <fstream>
#include <vector>
std::vector<bool> vert, hor, visit;
struct Point2D{ int x, y; };
Point2D limit;
void generateMap(Point2D limits)
{
    vert.resize(limits.x+1 * limits.y+1);
    hor.resize(limits.x+1 * limits.y+1);
    visit.resize(limits.x * limits.y);

    for(int i = 0; i < visit.size(); i++)
    {
        visit[i] = false;
    }
    for(int i = 0; i < hor.size(); i++)
    {
        hor[i] = true;
    }
    for(int i = 0; i < vert.size(); i++)
    {
        vert[i] = true;
    }
}



enum class Direction
{
    UP = 0,
    RIGHT,
    DOWN,
    LEFT
};
void BreakWall(Point2D p, Direction d)
{
    switch(d){
        case Direction::UP:
            hor[limit.x*p.y+p.x] = false;
            break;
        case Direction::RIGHT:
            vert[limit.x*p.y+p.x+1] = false;
            break;
        case Direction::DOWN:
            hor[limit.x*(p.y+1)+p.x] = false;
            break;
        case Direction::LEFT:
            vert[limit.x*p.y+p.x] = false;
            break;
    }
}
bool getWall(Point2D p, Direction d)
{
    switch(d){
        case Direction::UP:
           return hor[limit.x*p.y+p.x];
            break;
        case Direction::RIGHT:
            return vert[limit.x*p.y+p.x+1];
            break;
        case Direction::DOWN:
            return hor[limit.x*(p.y+1)+p.x];
            break;
        case Direction::LEFT:
            return vert[limit.x*p.y+p.x];
            break;
    }
}

bool getVisit(Point2D p)
{
    return visit[limit.x*p.y+p.x];
}

void setVisit(Point2D p, bool state)
{
    visit[limit.x*p.y+p.x] = state;
}

std::vector<Point2D> getVisitable(Point2D p)
{
    if(p.x < 0)
        return true;
    if (p.x > limit.x)
        return true;

}
int main()
{
    int steps;
    std::cin >> limit.x >> limit.y >> steps;
    generateMap(limit);

}

