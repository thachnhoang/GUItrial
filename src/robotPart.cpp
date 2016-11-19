#include "robotPart.h"

//these input widgets used for create robot model
Fl_Input* gui_name;
Fl_Input* gui_part_number;
Fl_Input* gui_robot_torso;
Fl_Input* gui_robot_head;
Fl_Input* gui_robot_arm;
Fl_Input* gui_robot_motor;
Fl_Input* gui_robot_bin;
Fl_Input* gui_price;
Fl_Output* gui_cost;

extern torso body;
extern arm hand;
extern head mind;
extern locomotor motor;
extern battery bin;
double total_cost;

void costCB(Fl_Widget *w, void* p)
{
	int n = body.get_battery(gui_robot_torso->value());
	total_cost = body.get_cost(gui_robot_torso->value()) + 2 * hand.get_cost(gui_robot_arm->value()) + mind.get_cost(gui_robot_head->value()) + motor.get_cost(gui_robot_motor->value()) + n*bin.get_cost(gui_robot_bin->value());
	ostringstream of;
	of << total_cost;
	gui_cost->value((of.str()).c_str());
}

void createCB(Fl_Widget *w, void* p)
{
	//name, part number, torso, head, arm, motor, battery, price
	(*robot).create(gui_name->value(), gui_part_number->value(), gui_robot_torso->value(), gui_robot_head->value(), gui_robot_arm->value(), gui_robot_motor->value(), gui_robot_bin->value(), gui_price->value());

}

robotPart::robotPart()
{
	Fl_Multiline_Output* my_output_torso = new Fl_Multiline_Output(100, 10, 400, 100, "Torso list:");
	my_output_torso->value(body.print().c_str());
	Fl_Multiline_Output* my_output_head = new Fl_Multiline_Output(100, 120, 400, 100, "Head list:");
	my_output_head->value(mind.print().c_str());
	Fl_Multiline_Output* my_output_arm = new Fl_Multiline_Output(100, 240, 400, 100, "Arm list:");
	my_output_arm->value(hand.print().c_str());
	Fl_Multiline_Output* my_output_motor = new Fl_Multiline_Output(100, 360, 400, 100, "Locomotor list:");
	my_output_motor->value(motor.print().c_str());
	Fl_Multiline_Output* my_output_battery = new Fl_Multiline_Output(100, 480, 400, 100, "Battery list:");
	my_output_battery->value(bin.print().c_str());

	gui_cost = new Fl_Output(650, 430, 80, 30, "Total cost");

	Fl_Box* box = new Fl_Box(680, 10, 100, 30, "Enter robot model");
	gui_name = new Fl_Input(650, 50, 150, 30, "robot name");
	gui_part_number = new Fl_Input(650, 100, 150, 30, "part number");
	gui_robot_torso = new Fl_Input(650, 150, 150, 30, "torso robot");
	gui_robot_head = new Fl_Input(650, 200, 150, 30, "head robot");
	gui_robot_arm = new Fl_Input(650, 250, 150, 30, "arm robot");
	gui_robot_motor = new Fl_Input(650, 300, 150, 30, "motor robot");
	gui_robot_bin = new Fl_Input(650, 350, 150, 30, "battery robot");
	gui_price = new Fl_Input(820, 430, 100, 30, "setup price");

	Fl_Button* parts_cost = new Fl_Button(650, 390, 70, 30, "part's cost");
	Fl_Button* create = new Fl_Button(650, 500, 100, 30, "create");

	create->callback(createCB);
	parts_cost->callback(costCB);
}

void robotPart::create(string name, string number, string robot_tor, string robot_he, string robot_ar, string robot_mo, string robot_ba, string final_price)
{
	robot_torso.push_back(robot_tor);
	robot_head.push_back(robot_he);
	robot_arm.push_back(robot_ar);
	robot_motor.push_back(robot_mo);
	robot_battery.push_back(robot_ba);
	model_name.push_back(name);
	model_number.push_back(number);
	price.push_back(atof(final_price.c_str()));

	double earned_money = atof(final_price.c_str()) - total_cost;
	profit.push_back(earned_money);
}

void robotPart::print()
{
	int n = model_name.size();
	int ship_cost = 5;
	//Fl_Button* robot_button[10]; //maximum is 10
	//string image_file[5] = {"robot1.jpg", "robot2.jpg","robot3.jpg","robot4.jpg"};
	
	for (int i = 0; i < n; i++)
	{
		ostringstream of;
		of << (i + 1) << ". " << model_name[i] << ", #" << model_number[i] << ", $" << price[i] << "\n"
			<< "shipping cost: " << ship_cost << "\n" << "Features: \n"
			<< "\t -" << mind.print_feature(robot_head[i])
			<< "\t -" << body.print_feature(robot_torso[i])
			<< "\t -" << motor.print_feature(robot_motor[i])
			<< "\t -" << hand.print_feature(robot_arm[i])
			<< "\t -" << bin.print_feature(robot_battery[i]);

		Fl_Multiline_Output* catalog_output = new Fl_Multiline_Output(50, 10 + i * 160, 400, 150, "robot:");
		catalog_output->value((of.str()).c_str());

		//Fl_JPEG_Image *jpg = new Fl_JPEG_Image(image_file[i].c_str());
		//Fl_Box *box = new Fl_Box(500, 10+ i*160, 150, 150);
		//box->image(*jpg);

		//robot_button[i] = new Fl_Button(500, 120 + i * 140, 100, 30, (*robot).model_name[i].c_str());
	}
}


/*
double robotPart::get_price(string name)
{
	int size = model_name.size();
	for (int i = 0; i < size; i++)
	{
		if (model_name[i] == name)
		{
			return price[i];
		}
	}
	return 0;
}
*/

double robotPart::get_profit(string name)
{
	int size = model_name.size();
	for (int i = 0; i < size; i++)
	{
		if (model_name[i] == name)
		{
			return profit[i];
		}
	}
	return 0;
}
