#include <FL/Fl_Menu_Bar.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Widget.H>
#include "robotPart.h"
#include "order.h"

Fl_Window *win;
Fl_Input* name = new Fl_Input(150, 60, 150, 30, "name");
Fl_Input* part_number = new Fl_Input(150, 100, 150, 30, "part number");
Fl_Input* weight = new Fl_Input(150, 140, 150, 30, "weight");
Fl_Input* cost = new Fl_Input(150, 180, 150, 30, "cost");
Fl_Input* desp = new Fl_Input(150, 220, 150, 50, "description");
Fl_Input* battery_count;
Fl_Input* power_consumed;
Fl_Input* max_speed;
Fl_Input* energy;
Fl_Button* doneT;
Fl_Button* doneA;
Fl_Button* doneH;
Fl_Button* doneM;
Fl_Button* doneB;
Fl_Button* quit;
Fl_Menu_Bar *menubar;
Fl_Window *dialog;

torso body;
arm hand;
head mind;
locomotor motor;
battery bin;
robotPart* robot; //only need to declared in one file when use it for multiple files
customerOrder* order;

void display_input()
{
	dialog->add(name);
	dialog->add(part_number);
	dialog->add(weight);
	dialog->add(cost);
	dialog->add(desp);
	quit = new Fl_Button(300, 350, 100, 30, "Cancel");
}

void closeCB(Fl_Widget *w, void* p)
{
	//if (fl_choice("Unsaved file, exit anyway", fl_no, fl_yes, 0) == 1)
	//{
		win->hide();
	//}
}

void applyTorsoCB(Fl_Widget *w, void* p)
{
	string nam, number, wgt, des, ct, count, power, speed, ener;
	double fee;
	int amount, spd;

	nam = name->value();
	number = part_number->value();
	wgt = weight->value();
	des = desp->value();
	ct = cost->value();
	fee = atof(ct.c_str());

	count = battery_count->value();
	amount = atoi(count.c_str());
	body.create(nam, number, wgt, des, fee, amount);
	
}

void applyArmCB(Fl_Widget *w, void* p)
{
	string nam, number, wgt, des, ct, count, power, speed, ener;
	double fee;
	int amount, spd;

	nam = name->value();
	number = part_number->value();
	wgt = weight->value();
	des = desp->value();
	ct = cost->value();
	fee = atof(ct.c_str());

	power = power_consumed->value();
	amount = atoi(power.c_str());
	hand.create(nam, number, wgt, des, fee, amount);
}

void applyHeadCB(Fl_Widget *w, void* p)
{
	string nam, number, wgt, des, ct, count, power, speed, ener;
	double fee;
	int amount, spd;

	nam = name->value();
	number = part_number->value();
	wgt = weight->value();
	des = desp->value();
	ct = cost->value();
	fee = atof(ct.c_str());

	mind.create(nam, number, wgt, des, fee);
}

void applyMotorCB(Fl_Widget *w, void* p)
{
	string nam, number, wgt, des, ct, count, power, speed, ener;
	double fee;
	int amount, spd;

	nam = name->value();
	number = part_number->value();
	wgt = weight->value();
	des = desp->value();
	ct = cost->value();
	fee = atof(ct.c_str());

	power = power_consumed->value();
	amount = atoi(power.c_str());
	speed = max_speed->value();
	spd = atoi(speed.c_str());
	motor.create(nam, number, wgt, des, fee, amount, spd);
}

void applyBinCB(Fl_Widget *w, void* p)
{
	string nam, number, wgt, des, ct, count, power, speed, ener;
	double fee;
	int amount, spd;

	nam = name->value();
	number = part_number->value();
	wgt = weight->value();
	des = desp->value();
	ct = cost->value();
	fee = atof(ct.c_str());

	ener = energy->value();
	amount = atoi(ener.c_str());
	bin.create(nam, number, wgt, des, fee, amount);
}

void quitCB(Fl_Widget *w, void* p)
{
	dialog->hide();
}

void torsoCB(Fl_Widget *w, void* p)
{
	dialog = new Fl_Window(100, 100, 500, 500, "torso");
	display_input();
	battery_count = new Fl_Input(150, 280, 150, 30, "battery count");
	doneT = new Fl_Button(150, 350, 100, 30, "Apply");

	doneT->callback(applyTorsoCB);
	quit->callback(quitCB);

	dialog->end();
	dialog->show();
}

void headCB(Fl_Widget *w, void* p)
{
	dialog = new Fl_Window(150, 100, 500, 500, "head");
	display_input();
	doneH = new Fl_Button(150, 350, 100, 30, "Apply");
	
	doneH->callback(applyHeadCB);
	quit->callback(quitCB);

	dialog->end();
	dialog->show();
}

void armCB(Fl_Widget *w, void* p)
{
	dialog = new Fl_Window(100, 100, 500, 500, "arm");
	display_input();
	power_consumed = new Fl_Input(150, 280, 150, 30, "consumption (W)");
	doneA = new Fl_Button(150, 350, 100, 30, "Apply");
	
	doneA->callback(applyArmCB);
	quit->callback(quitCB);

	dialog->end();
	dialog->show();
}

void locomotorCB(Fl_Widget *w, void* p)
{
	dialog = new Fl_Window(100, 100, 500, 500, "locomotor");
	display_input();
	max_speed = new Fl_Input(150, 280, 150, 30, "max. speed (mph)");
	power_consumed = new Fl_Input(150, 310, 150, 30, "consumption (W)");
	doneM = new Fl_Button(150, 350, 100, 30, "Apply");

	doneM->callback(applyMotorCB);
	quit->callback(quitCB);

	dialog->end();
	dialog->show();
}

void batteryCB(Fl_Widget *w, void* p)
{
	dialog = new Fl_Window(100, 100, 500, 500, "battery");
	display_input();
	energy = new Fl_Input(150, 280, 150, 30, "energy (kW/h)");
	doneB = new Fl_Button(150, 350, 100, 30, "Apply");

	doneB->callback(applyBinCB);
	quit->callback(quitCB);

	dialog->end();
	dialog->show();
}

void newCB(Fl_Widget *w, void* p)
{}

void openCB(Fl_Widget *w, void* p)
{}

void saveCB(Fl_Widget *w, void* p)
{}

void orderCB(Fl_Widget *w, void* p)
{
	dialog = new Fl_Window(20, 20, 700, 500, "order");
	order = new customerOrder{};

	quit = new Fl_Button(250, 400, 100, 30, "Cancel");
	quit->callback(quitCB);
	dialog->end();
	dialog->show();
}

void customerCB(Fl_Widget *w, void* p)
{
	dialog = new Fl_Window(20, 20, 700, 500, "customer");
	(*order).customer_info();
	
	quit = new Fl_Button(250, 400, 100, 30, "Cancel");
	quit->callback(quitCB);
	dialog->end();
	dialog->show();
}

void saleCB(Fl_Widget *w, void* p)
{
	dialog = new Fl_Window(20, 20, 700, 500, "sale associate");
	(*order).sale_info();

	quit = new Fl_Button(250, 400, 100, 30, "Cancel");
	quit->callback(quitCB);
	dialog->end();
	dialog->show();
}

void robotModelCB(Fl_Widget *w, void* p)
{
	dialog = new Fl_Window(20, 20, 1000, 700, "robot model");
	dialog->color(FL_GREEN);
	robot = new robotPart{};
	quit = new Fl_Button(780, 500, 100, 30, "Cancel");
	quit->callback(quitCB);

	dialog->end();
	dialog->show();
}

void catalogCB(Fl_Widget *w, void* p)
{
	dialog = new Fl_Window(20, 20, 1000, 700, "catalog robot");
	(*robot).print();
	quit = new Fl_Button(780, 500, 100, 30, "Cancel");
	quit->callback(quitCB);

	dialog->end();
	dialog->show();
}

Fl_Menu_Item menuitems[] = {
	{ "&File", 0,0,0,FL_SUBMENU },
	{ "&New", FL_ALT + 'n', (Fl_Callback*)newCB },
	{ "&Open", FL_ALT + 'o', (Fl_Callback*)openCB },
	{ "&Save", FL_ALT + 's', (Fl_Callback*)saveCB },
	{ "&Quit", FL_ALT + 'q', (Fl_Callback*)closeCB },
	{ 0 },
	{ "&Edit",0,0,0, FL_SUBMENU },
	{ 0 },
	{ "&Create",0,0,0,FL_SUBMENU },
	{ "&Order",0,(Fl_Callback*)orderCB },
	{ "&Customer",0,(Fl_Callback*)customerCB },
	{ "&Sale Associate",0,(Fl_Callback*)saleCB },
	{ "&Robot Part",0,0,0, FL_SUBMENU },
	{ "&torso",0, (Fl_Callback*)torsoCB },
	{ "&head",0, (Fl_Callback*)headCB },
	{ "&arm",0, (Fl_Callback*)armCB },
	{ "&locomotor",0, (Fl_Callback*)locomotorCB },
	{ "&battery",0, (Fl_Callback*)batteryCB },
	{ 0 },
	{ "&Robot Model",0,(Fl_Callback*)robotModelCB },
	{ 0 },
	{ "&View",0,0,0,FL_SUBMENU },
	{ "&Robot catalog",0, (Fl_Callback*)catalogCB},
	{ 0 },
};

int main()
{
	win = new Fl_Window(0,0, 640, 640, "Robot Shop");
	win->color(FL_WHITE);
	menubar = new Fl_Menu_Bar(0, 0, 640, 30);
	menubar->menu(menuitems);
	win->callback(closeCB);

	win->end();
	win->show();
	return(Fl::run());
}

