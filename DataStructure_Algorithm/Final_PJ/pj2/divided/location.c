#include "location.h"

double target(Location *loc)
{
    return loc->x*loc->x*(1-loc->y)+loc->y;
}
Location get_random_location()
{
    Location loc;
    loc.x=rand()/((double)RAND_MAX+1.0);
    loc.y=rand()/((double)RAND_MAX+1.0);
    loc.value=target(&loc);
    return loc;
}
Location get_new_location(Location cur)
{
    Location new_loc;

    double x=alpha*cur.v.x+beta*(best_location.x-cur.x)+(1-alpha-beta)*(rand()*2/(double)(RAND_MAX+1)-1);
    double y=alpha*cur.v.y+beta*(best_location.y-cur.y)+(1-alpha-beta)*(rand()*2/(double)(RAND_MAX+1)-1);//get the new vector
    x=x/sqrt(x*x+y*y)*step;
    y=y/sqrt(x*x+y*y)*step;//normalize the vector
    new_loc=move(cur,x,y);//

    return new_loc;
}
Location move(Location cur,double x,double y)
{
    Location new_loc;
    new_loc.x=cur.x+x;
    new_loc.y=cur.y+y;
    new_loc.v.x=x;
    new_loc.v.y=y;
    if(new_loc.x<0)    //check if new_loc is out of the range
    {
        new_loc.x=-new_loc.x;
    }
    else if(new_loc.x>1)
    {
        new_loc.x=(new_loc.x-1)*(-1)+1;
    }
    if(new_loc.y<0)
    {
        new_loc.y=-new_loc.y;
    }
    else if(new_loc.y>1)
    {
        new_loc.y=(new_loc.y-1)*(-1)+1;
    }

    new_loc.value=target(&new_loc);
    return new_loc;
}

