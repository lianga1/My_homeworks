#include "../lib/display.h"
#ifndef __SRC_FILE
#define __SRC_FILE
#endif  // !__SRC_FILE
#include <vector>
#include <string>

#include "../game/border.h"
#include "../game/movingRectangle.h"
#include "../game/rectangle.h"
#include "../lib/audio.h"
#include "bird.h"

using std::vector;
using ObjPool = vector<Object*>;

void detect_collision(ObjPool& pool) {

    ObjPool::iterator iter1,iter2;
    iter1=pool.begin();
    for(iter1=pool.begin()+2;iter1!=pool.end();iter1++)
    {   
        (**iter1).detect_collide(*pool[1]);
    }
    for(iter1=pool.begin()+1;iter1!=pool.end();iter1++)
    {
        (*pool[0]).detect_collide(**iter1);
    }

    // : detect collision between each pair of objects
    /* Your code here */
}

void show_game_over(Display& display, double second) {
    display.clear();
    display.put_string(display.get_cols() / 2 - 7, display.get_rows() / 2 - 1,
                       "Game Over");
    display.put_string(display.get_cols() / 2 - 14, display.get_rows() / 2,
                       "Bird survives " + std::to_string(second) + " seconds");
    display.put_string(display.get_cols() / 2 - 13, display.get_rows() / 2 + 1,
                       "Press any key to exit");
    display.refresh();
    display.get_char();
}
void add_rectangle(ObjPool& pool, Display& d) {

    int cols=d.get_cols();
     int rows=d.get_rows();
    srand(time(NULL));
    int y=rand()%(rows-10)-5;
    int width=1+rand()%5;
    MovingRectangle* barrier =new MovingRectangle(cols-width-2,y,width,rand()%((rows-y)*2/3),-1,0);
    pool.emplace_back(barrier);

    
    
    // : add a moving_rectangle to the pool
    /* Your code here */
}


int main() {
    
    Display d0;
    d0.put_string(d0.get_cols() / 2 - 7, d0.get_rows() / 2 ,
                       "flappy bird");
    d0.put_string(d0.get_cols() / 2 - 7, d0.get_rows() / 2 - 1,
                       "Tap any button to start");
    d0.get_char();

    Display d("log.txt");
    string audio_dir = "../audio/";
    ObjPool obj_pool;
    Bird* bird = new Bird(d.get_cols() / 2, d.get_rows() / 2, 0, 0, 0, 0.1);
    Border* border = new Border(0, 0, d.get_cols(), d.get_rows());
    obj_pool.emplace_back(bird);
    obj_pool.emplace_back(border);
    int pre_c=0;
    Audio flap("../audio/flap.mp3");
    Audio collide("../audio/biu~.wav");
    Audio applause("../audio/end.mp3");
    Audio bgm("../audio/mountain.mp3");
    bgm.play_loop();
    int times=0;
    while (true) {
        
        // Process keyboard input
        int c = d.get_char(50);
        d.clear();
        if (c == 'q') {
            break;
        } else if (c == ' '&&pre_c!=' ') {flap.play_once();
        }
        
        
        // Add new rectangle
        if(times%40==0)
        add_rectangle(obj_pool, d);

        // Update object state
        for (auto& obj : obj_pool) {
            obj->tick(c);
        }
        
        
        // Detect collision
        detect_collision(obj_pool);

        for(auto iter1=obj_pool.begin();iter1!=obj_pool.end();iter1++)
        {
            if(((*iter1)->get_valid()==false) && ((*iter1)->type()==Type::Rectangle))
            {
                delete(*iter1);
                iter1=obj_pool.erase(iter1);
                iter1--;
            }
        }
       
        

        //TODO: Process invalid object
        /* Your code here */
        

        if(bird->get_valid()==false)
            
        {
            bgm.stop();
            collide.play_once();
            applause.play_once();
            obj_pool.clear();
            show_game_over(d,d.time()/1000);

        }
        //TODO: Bird collide with border
        /* Your code here */

        // Draw objects
        for (auto& obj : obj_pool) {
            obj->draw(d);
        }
        d.put_string(1, 1, "Time: " + std::to_string(d.time() / 1000.0));
        d.put_string(1, 2, "Keystrock: " + std::to_string(c));
        d.refresh();
        d.log();
        pre_c=c;
        times++; 
    }

    return 0;
}