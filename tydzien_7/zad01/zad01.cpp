
//
// This is example code from Chapter 12.3 "A first example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
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
    Menu color_menu;   
    Button menu_button;      
    Menu line_style_menu;
    Button line_style_button;
    void change(Color c) { lines.set_color(c); }  
    //style
    void line_change(Line_style x){lines.set_style(x);}
    void hide_menu() { color_menu.hide(); menu_button.show(); }
    //style
    void hide_menu_line() {line_style_menu.hide(); line_style_button.show();}
    void next();           
    void quit(); 
    
             
    void red_pressed() { change(Color::red); hide_menu(); }   
    void blue_pressed() { change(Color::blue); hide_menu(); }        
    void black_pressed() { change(Color::black); hide_menu(); }      
    void menu_pressed() { menu_button.hide(); color_menu.show(); }   
    //style
    void menu_line_pressed() {line_style_button.hide(); line_style_menu.show();}
    void dash_pressed() {line_change(Line_style::dash); hide_menu_line(); }
    /*
    static void cb_red(Address, Address);   
    static void cb_blue(Address, Address);          
    static void cb_black(Address, Address);        
    static void cb_menu(Address, Address);        
    static void cb_next(Address, Address);        
    static void cb_quit(Address, Address);
    */
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
color_menu{Point{x_max()-70,30},70,20,Menu::vertical,"color"},  
menu_button{Point{x_max()-80,30}, 80, 20, "color menu",
    [](Address, Address pw){
        reference_to<Lines_window>(pw).menu_pressed();
    }
},

//style
line_style_menu{Point{x_max()-70,60}, 70,20, Menu::vertical, "line"},
line_style_button{Point{x_max()-80,60}, 80,20, "line menu",
        [](Address, Address pw){
        reference_to<Lines_window>(pw).menu_line_pressed();
    }
}

{      
    attach(next_button);       
    attach(quit_button);         
    attach(next_x);      
    attach(next_y);   
    attach(xy_out);          
    xy_out.put("no point");        
    color_menu.attach(new Button{Point{0,0},0,0,"red",
                      [](Address, Address pw){
                reference_to<Lines_window>(pw).red_pressed();
    }}); 

    color_menu.attach(new Button{Point{0,0},0,0,"blue",
                      [](Address, Address pw){
                reference_to<Lines_window>(pw).blue_pressed();
    }});  
    color_menu.attach(new Button{Point{0,0},0,0,"black",
                      [](Address, Address pw){
                reference_to<Lines_window>(pw).black_pressed();
    }}); 
    line_style_menu.attach(new Button{Point{0, 0},0,0,"dash",
                      [](Address, Address pw){
                reference_to<Lines_window>(pw).dash_pressed();
    }}); 

    
    attach(color_menu);
    color_menu.hide();   
    attach(menu_button);  
    attach(line_style_menu);
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
