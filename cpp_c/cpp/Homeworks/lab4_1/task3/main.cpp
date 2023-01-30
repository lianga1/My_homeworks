#include "../lib/display.h"
#include "bird.h"
const double g = 0.1;
const double v_tap_up = -1;
const double v_tap_left = -1;
const double a_tap_left = 1;
const double v_tap_right = 1;
const double a_tap_right = -1;

void show_game_over(Display &display, double second,int score) {
    display.clear();
    display.put_string(display.get_cols() / 2 - 7, display.get_rows() / 2 - 1, "Game Over");
    display.put_string(display.get_cols() / 2 - 14, display.get_rows() / 2,
                       "Bird survives " + std::to_string(second) + " seconds");
    display.put_string(display.get_cols() / 2 - 14, display.get_rows() / 2 + 1,"Your score is "+std::to_string(score));
    display.put_string(display.get_cols() / 2 - 13, display.get_rows() / 2 + 2, "Press any key to exit");
    display.refresh();
    display.sleep(200);
    display.get_char();
}

int main() {
    Display d;

    Bird bird(d.get_cols() / 2, d.get_rows() / 2, 0, 0, 0, g);
    int c;
    int lines = d.get_rows();
    int cols = d.get_cols();
    srand(time(NULL));
    auto line=lines/2+1;
    auto col=cols/2+1;
    d.put_string(col, line, "#");
    d.refresh();
    int score=0;
    while (true) {
        d.put_string(col, line, "#");
        c = d.get_char(50);
        d.clear();
        auto pos = bird.get_pos();
        auto v = bird.get_v();
        auto a = bird.get_a();
        // You should read notes carefully and think what operation you should do to make sure it flies successfully.
        // Press `q` will quit the game. Press ` `(aka space) will make the bird fly up.
        // Press `x` will make the bird fly right while `z` will make the bird fly left.
        // hint: you should probably read task1 first to get to know how to control your bird.      
        //TODO:小鸟大一点，跳的矮一点，设置几档难度
        
        
        switch (c)
        {
        case 'z'://move left
            bird.set_v(v_tap_left,v.second);
            bird.set_a(a_tap_left,g);
            break;
        case 'x'://move right
            bird.set_v(v_tap_right,v.second);
            bird.set_a(a_tap_right,g);
            break;
        case ' '://jump
            bird.set_v(v.first,v_tap_up);
            bird.set_a(a.first,g);
            break;
        case 'q':
            return 0;
            break;
        case 'a':
            bird.set_v(v_tap_left,v.second);
            bird.set_a(0.1,g);
            break;
        case 's':
            bird.set_v(v_tap_right,v.second);
            bird.set_a(-0.1,g);
            break;
        default:
            break;
        }

        d.put_string(0, 0, "Time: " + std::to_string(d.time() / 1000.0));
        d.put_string(0, 1, "Keystrock: " + std::to_string(c));
        d.put_string(0, 2, "Pos: " + std::to_string(pos.first) + "," + std::to_string(pos.second));
        d.put_string(0, 3, "Speed: " + std::to_string(v.first) + "," + std::to_string(v.second));
        d.put_string(0, 4, "Acceleration: " + std::to_string(a.first) + "," + std::to_string(a.second));
        d.put_string(0, 5, "score: "+std::to_string(score));
        d.put_string(pos.first, pos.second, "@");

        d.refresh();

        if (pos.second <= 0 || pos.second >= d.get_rows() - 1 || pos.first <= 0 || pos.first >= d.get_cols() - 1) {
            show_game_over(d, d.time() / 1000.0,score);
            break;
        }

        bird.tick();

        if(pos.first==col&&pos.second==line)
        {
            score+=1;
            line=5+rand()%(lines-10);
            col=5+rand()%(cols-10);
            d.put_string(col, line, "#");
            d.refresh();
        }



    }




    
}
