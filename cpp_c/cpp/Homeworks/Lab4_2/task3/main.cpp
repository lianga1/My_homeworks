#include "../lib/display.h"
#ifndef __SRC_FILE
#define __SRC_FILE
#endif  // !__SRC_FILE
#include <vector>
#include <string>
#include <fstream>
#include <windows.h>


#include "../game/border.h"
#include "../game/movingRectangle.h"
#include "../game/rectangle.h"
#include "../lib/audio.h"

using std::vector;
using ObjPool = vector<Object*>;

using std::to_string;

void summon_keys(ObjPool & keys,Display & d)
{
    int width=d.get_cols();

    int wid=width/12;
    
    int y = d.get_rows()-6;

    int x= 2;

    for(int i=0;i<11;i++)
    {
        MovingRectangle* key= new MovingRectangle(x,y,3,3,0,0);
        x+=wid;
        keys.emplace_back(key);
    }


}


void get_music(vector<int> & music, string filename)
{
    std::fstream file;
    file.open(filename , std::ios::in);
    int x;
    while(file>>x)
    {
        music.push_back(x);
    }
}

void detect_collision(ObjPool& pool) {

    ObjPool::iterator iter1;
    iter1=pool.begin();
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

void add_rectangle(ObjPool& pool, Display& d, int note) {

    int cols=d.get_cols();
    int wid=cols/12;
    int x=2;
    MovingRectangle* flap=new MovingRectangle(x+(note-1)*wid,2,3,3,0,1);

    pool.emplace_back(flap);

    
    

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
    ObjPool keys;

    summon_keys(keys,d);

    Border* border = new Border(0, 0, d.get_cols(), d.get_rows());

    obj_pool.emplace_back(border);



    vector<Audio> piano;
    Audio _1("../audio/piano/1.mp3");
    Audio _2("../audio/piano/2.mp3");
    Audio _3("../audio/piano/3.mp3");
    Audio _4("../audio/piano/4.mp3");
    Audio _5("../audio/piano/5.mp3");
    Audio _6("../audio/piano/6.mp3");
    Audio _7("../audio/piano/7.mp3");
    Audio _8("../audio/piano/8.mp3");
    Audio _9("../audio/piano/9.mp3");
    Audio _10("../audio/piano/10.mp3");
    Audio _11("../audio/piano/11.mp3");
    Audio _101("../audio/piano/101.mp3");
    Audio _91("../audio/piano/91.mp3");
   // piano.emplace_back(_1);
   // piano.emplace_back(_2);
 /*   piano.emplace_back(_3);
    piano.emplace_back(_4);
    piano.emplace_back(_5);
    piano.emplace_back(_6);
    piano.emplace_back(_7);
    piano.emplace_back(_8);
    piano.emplace_back(_9);
    piano.emplace_back(_10);
    piano.emplace_back(_11);*/
  //  Audio bgm("../audio/mountain.mp3");
    
  //  bgm.play_loop();
    vector<int> music;
    get_music(music,"Alice.txt");

    int f=0;

    int times=0;
    while (true) {
        

        // Process keyboard input
        int c = d.get_char(50);
        d.clear();

        if(c=='q')
            break;

        switch (c)
        {
        case '1':
            
            _1.play_once();
            f=1;
            break;
        
        case '2':
            _2.play_once();
            f=2;
            break;

        case '3':
            _3.play_once();
            f=3;
            break;
        case '4':
            _4.play_once();
            f=4;
            break;
        case '5':
            _5.play_once();
f=5;
            break;
        case '6':
            _6.play_once();
 f=6;
            break;
        case '7':
            _7.play_once();
  f=7;
            break;
        case '8':
            _8.play_once();
f=8;
            break;
        case '9':
            _9.play_once();
     f=9;
            break;
        case '0':
        
            _10.play_once();
      f=10;
            break;
        case '-':
            _11.play_once();
 f=11;
            break;
        case 'p':
            _101.play_once();
            break;
        case 'o':
            _91.play_once();
            break;
        default:
            break;
        }
        
        
        // Add new rectangle
  /*      if(times%20==0)
        {
            switch (f)
            {
            case 1:
                _1.stop();
                break;
            case 2:
            _2.stop();
                break;
            case 3:
            _3.stop();
                break;
            case 4:
            _4.stop();
                break;
            case 5:
            _5.stop();
                break;
            case 6:
            _6.stop();
                break;
            case 7:
            _7.stop();
                break;
            case 8:
            _8.stop();
                break;
            case 9:
            _9.stop();
                break;
            case 10:
            _10.stop();
                break;
            case 11:
            _11.stop();
                break;
            
            default:
                break;
            }
        }  */
         if(times%10==0)   
            add_rectangle(obj_pool, d,music[times/10]);
            
        

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
        
        //TODO: Bird collide with border
        /* Your code here */

        // Draw objects
        for (auto& obj : obj_pool) {
            obj->draw(d);
        }
        int num=1;
        for (auto& obj : keys) {
            obj->draw(d);
            d.put_string(obj->getx()+1,obj->gety()+1,to_string(num++));
        }
        d.put_string(1, 1, "Time: " + std::to_string(d.time() / 1000.0));
        d.put_string(1, 2, "Keystrock: " + std::to_string(c));
        d.refresh();
        d.log();
        times++; 
    }

    return 0;
}