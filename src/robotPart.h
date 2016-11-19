#include "std_lib_facilities.h"
#include <FL/Fl.H>  
#include <FL/Fl_Window.H>  
#include <FL/Fl_Box.H>  
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Tiled_Image.H>
#include "torso.h"
#include "arm.h"
#include "head.h"
#include "locomotor.h"
#include "battery.h"

#ifndef ROBOTPART_H
#define ROBOTPART_H

class robotPart {
private:
	vector <string> model_name;
	vector <string> model_number;
	vector <double> price;
	vector <string> robot_torso;
	vector <string> robot_arm;
	vector <string> robot_motor;
	vector <string> robot_head;
	vector <string> robot_battery;
	vector <double> profit;

public:
	robotPart();
	void create(string, string, string, string, string,string, string, string);
	void print();
	//double get_price(string name);
	double get_profit(string name);
};

extern robotPart* robot;
#endif 

#pragma once
