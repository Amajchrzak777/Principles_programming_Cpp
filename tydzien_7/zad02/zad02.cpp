
// Adam Majchrzak 21.04.2020r.
//
#include <iostream>
#include "GUI.hpp"
#include "std_lib_facilities.hpp"
#include "Simple_window.hpp"    // get access to our window library
#include "Graph.hpp"            // get access to our graphics library facilities

//------------------------------------------------------------------------------
using namespace Graph_lib;   // our graphics facilities are in Graph_lib

struct Lines_window : Graph_lib::Window {          
    Lines_window(Point xy, int w, int h, const string& title);
private:          //data:        
    Open_polyline lines;   
    //widgets:     
    Button next_button;//add (next_x,next_y) to lines      
    Button quit_button;//end program      
    In_box next_x;         
    In_box next_y;      
    Out_box xy_out;      
    //Menu color_menu;   
    //Button menu_button; 
    Button menu_button_red, menu_button_blue, menu_button_black;
    Button menu_button_yellow,menu_button_dashdot,menu_button_dashdotdot,menu_button_solid,
           menu_button_green,menu_button_white,menu_button_magenta,menu_button_cyan;
    Button menu_button_dark_red,menu_button_dark_green,menu_button_dark_yellow,menu_button_dark_blue;
    //Menu line_style_menu;
    Button line_style_button;
    void change(Color c) { lines.set_color(c); }  
    void line_change(Line_style x){lines.set_style(x);}

    
    
    void red_pressed() { change(Color::red); }   
    void blue_pressed() { change(Color::blue);}        
    void black_pressed() { change(Color::black);}     
    void yellow_pressed() {change(Color::yellow);}
    void green_pressed() { change(Color::green); }   
    void white_pressed() { change(Color::white);}        
    void magenta_pressed() { change(Color::magenta);}     
    void cyan_pressed() {change(Color::cyan);}
    void dark_red_pressed() { change(Color::dark_red); }   
    void dark_green_pressed() { change(Color::dark_green);}        
    void dark_yellow_pressed() { change(Color::dark_yellow);}     
    void dark_blue_pressed() {change(Color::dark_blue);}
    void dash_pressed() {line_change(Line_style::dash); }
    void dashdot_pressed() {line_change(Line_style::dashdot);}
    void dashdotdot_pressed() {line_change(Line_style::dashdotdot);}
    void solid_pressed(){line_change(Line_style::solid);}
    
    
    void next();           
    void quit(); 
};

Lines_window::Lines_window(Point xy, int w, int h, const string& title)         
:Window{xy,w,h,title},     
next_button{Point{x_max()-150,0}, 70, 20, "Next point",
    [](Address, Address pw) {reference_to<Lines_window>(pw).next();}
},
quit_button{Point{x_max()-70,0}, 70, 20, "Quit",
    [](Address, Address pw) {reference_to<Lines_window>(pw).next();}
},
next_x{Point{x_max()-310,0}, 50, 20, "next x:"}, 
next_y{Point{x_max()-210,0}, 50, 20, "next y:"},    
xy_out{Point{100,0}, 100, 20, "current (x,y):"}, 

menu_button_red{Point{x_max()-80, 70}, 80,20, "red",
    [](Address, Address pw){
        reference_to<Lines_window>(pw).red_pressed();
    }
},

menu_button_blue{Point{x_max()-80, 90}, 80,20, "blue",
    [](Address, Address pw){
        reference_to<Lines_window>(pw).blue_pressed();
    }
},

menu_button_black{Point{x_max()-80,30}, 80, 20, "black",
    [](Address, Address pw){
        reference_to<Lines_window>(pw).black_pressed();
    }
},

menu_button_yellow{Point{x_max()-160, 30}, 80,20, "yellow",
    [](Address, Address pw){
        reference_to<Lines_window>(pw).yellow_pressed();
    }
},
menu_button_dashdot{Point{x_max()-160, 50}, 80,20, "dashdot",
    [](Address, Address pw){
        reference_to<Lines_window>(pw).dashdot_pressed();
    }
},
menu_button_dashdotdot{Point{x_max()-160, 70}, 80,20, "dashdotdot",
    [](Address, Address pw){
        reference_to<Lines_window>(pw).dashdotdot_pressed();
    }
},
menu_button_solid{Point{x_max()-160, 90}, 80,20, "solid",
    [](Address, Address pw){
        reference_to<Lines_window>(pw).solid_pressed();
    }
},
menu_button_green{Point{x_max()-240, 30}, 80,20, "green",
    [](Address, Address pw){
        reference_to<Lines_window>(pw).green_pressed();
    }
},
menu_button_white{Point{x_max()-240, 50}, 80,20, "white",
    [](Address, Address pw){
        reference_to<Lines_window>(pw).white_pressed();
    }
},
menu_button_magenta{Point{x_max()-240, 70}, 80,20, "magenta",
    [](Address, Address pw){
        reference_to<Lines_window>(pw).magenta_pressed();
    }
},
menu_button_cyan{Point{x_max()-240, 90}, 80,20, "cyan",
    [](Address, Address pw){
        reference_to<Lines_window>(pw).cyan_pressed();
    }
},
menu_button_dark_red{Point{x_max()-320, 30}, 80,20, "dark red",
    [](Address, Address pw){
        reference_to<Lines_window>(pw).dark_red_pressed();
    }
},
menu_button_dark_green{Point{x_max()-320, 70}, 80,20, "dark green",
    [](Address, Address pw){
        reference_to<Lines_window>(pw).dark_green_pressed();
    }
},

menu_button_dark_yellow{Point{x_max()-320, 90}, 80,20, "dark yellow",
    [](Address, Address pw){
        reference_to<Lines_window>(pw).dark_yellow_pressed();
    }
},
menu_button_dark_blue{Point{x_max()-320, 50}, 80,20, "dark blue",
    [](Address, Address pw){
        reference_to<Lines_window>(pw).dark_blue_pressed();
    }
},
line_style_button{Point{x_max()-80,50}, 80,20, "dash",
        [](Address, Address pw){
        reference_to<Lines_window>(pw).dash_pressed();
    }
}

{      
    attach(next_button);       
    attach(quit_button);         
    attach(next_x);      
    attach(next_y);   
    attach(xy_out);          
    xy_out.put("no point");        
    
    attach(menu_button_red);
    attach(menu_button_blue);
    attach(menu_button_black);  
    attach(menu_button_yellow);
    attach(menu_button_dashdot);
    attach(menu_button_dashdotdot);
    attach(menu_button_solid);
    attach(menu_button_green);
    attach(menu_button_dark_blue);
    attach(menu_button_dark_green);
    attach(menu_button_dark_red);
    attach(menu_button_dark_yellow);
    attach(menu_button_cyan);
    attach(menu_button_magenta);
    attach(menu_button_white);
    attach(line_style_button);
    attach(lines);        
}

void Lines_window::quit(){   
    hide();     // curious FLTK idiom to delete window
    
}

void Lines_window::next(){          
    int x = next_x.get_int();     
    int y = next_y.get_int();
     lines.add(Point{x,y});
     //update current position readout:   
     ostringstream ss;         
     ss << '(' << x << ',' << y << ')';   
     xy_out.put(ss.str()); 
     redraw();
}


int main()
try {
    std::cout << x_max();
    Lines_window win {Point{100,100},600,400,"lines"};
    return gui_main();
    
}
    catch(exception& e) {        
        cerr << "exception: " << e.what() << '\n';          
        return 1;
        
    }
    catch (...)
    {         
        cerr << "Some exception\n";  
        return 2;
        
    }

//------------------------------------------------------------------------------
