#include "bird.h"

#include <cmath>

const double g = 0.1;
const double v_tap_up = -1;
const double v_tap_left = -1;
const double a_tap_left = 0.1;
const double v_tap_right = 1;
const double a_tap_right = -0.1;

Bird::Bird(double x, double y, double vx, double vy, double ax, double ay)
    : x(x), y(y), vx(vx), vy(vy), ax(ax), ay(ay) {}

std::pair<int, int> Bird::get_pos() const {
    return std::make_pair((int)std::round(x), (int)std::round(y));
}
std::pair<double, double> Bird::get_v() const { return std::make_pair(vx, vy); }
std::pair<double, double> Bird::get_a() const { return std::make_pair(ax, ay); }
void Bird::set_pos(int _x, int _y) {
    x = _x;
    y = _y;
}

void Bird::set_v(double _vx, double _vy) {
    vx = _vx;
    vy = _vy;
}

void Bird::set_a(double _ax, double _ay) {
    ax = _ax;
    ay = _ay;
}

void Bird::draw(Display& display) const {
    
    int width=display.get_cols();
    int height=display.get_rows();
    if(this->x > 0 &&this->y >0 && this->x < width-1 && this->y < height-1)

    display.put_string(x,y,"@");

    // TODO: draw the bird on the display
    // hint: you should check if the bird is inside the display
    /* Your code here */
}

bool Bird::is_inside(int x, int y) const {
    
    if(this->x==x &&this->y==y)
        return true;
    else
        return false;
    // TODO: check if position (x, y) is inside bird
    /* Your code here */
        

}

void Bird::tick(int key) {
    
    switch (key)//get the c and choose what to do 
        {
        case 'z'://move left
            vx=-1;
            ax=0.1;
            break;
        case 'x'://move right
            vx=1;
            ax=-0.1;
            break;
        case ' '://jump
            vy=-1;
            break;
        case 'q'://quit
            return ;
            break;
        default:
            break;
        }    
    x+=vx*1;
    y+=vy*1;
    vy+=ay*1;
    vx+=ax*1;
    if(vx/ax>=0) {ax=0;vx=0;}


    
    // TODO: update the bird's properties according to key input
    /* Your code here */
}

bool Bird::detect_collide(Object& obj) {
    
    if(obj.is_inside(this->x,this->y))
    {
        valid=false;
        return true;
    }
    return false;
    // TODO: detect collision with the specified object
    /* Your code here */
}