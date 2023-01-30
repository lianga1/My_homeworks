#include "bird.h"
#include <utility>

// We have given you the header file `bird.h`.
// You should read class `Bird` carefully
// and implement the member functions in `bird.cpp`.
// TODO: Please implement the member functions of class `Bird`.
/* Your code here */
Bird::Bird(double x, double y, double vx, double vy, double ax, double ay):x(x),y(y),vx(vx),vy(vy),ax(ax),ay(ay){}
void Bird::tick()
{
    x+=vx*1;
    y+=vy*1;
    vy+=ay*1;
    vx+=ax*1;
    if(vx/ax>=0) {ax=0;vx=0;}


    
}
std::pair<int ,int> Bird::get_pos() const
{
    std::pair<int,int > p1;
    p1.first=x;
    p1.second=y;
    return p1;
}
std::pair<double, double> Bird::get_v() const
{
    std::pair<double,double > p1;
    p1.first=vx;
    p1.second=vy;
    return p1;
}
std::pair<double, double> Bird::get_a() const
{
    std::pair<double,double > p1;
    p1.first=ax;
    p1.second=ay;
    return p1;
}
void Bird::set_pos(int _x,int _y)
{
    x=_x;
    y=_y;
    return;
}
void Bird::set_v(double _vx, double _vy)
{
    vx=_vx;
    vy=_vy;
    return;
}
void Bird::set_a(double _ax, double _ay)
{
    ax=_ax;
    ay=_ay;
    return;
}