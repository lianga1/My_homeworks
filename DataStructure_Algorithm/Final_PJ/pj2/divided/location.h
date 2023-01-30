#ifndef __LOCATION_H__
#define __LOCATION_H__
#include <stdlib.h>
#include <math.h>
#define alpha 0.4
#define beta 0.4
#define step 0.05

typedef struct v{
    double x;
    double y;
}vector;

typedef struct l{
    double x;//x coordinate
    double y;//y coordinate
    vector v;//record the comeway of the point
    double value;//record the value of the point
} Location;

Location best_location;//record the location with the best value

double target(Location *loc);//calculate the value of the location
Location get_random_location();//get a random location
Location get_new_location(Location cur);//get a new location by the current location, best location and random location
Location move(Location cur,double x,double y);//do the move operation

#endif