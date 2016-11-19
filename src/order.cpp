#include "order.h"

Fl_Input* customer_name;
Fl_Input* customer_add;
Fl_Input* customer_phone;
Fl_Input* customer_email;
Fl_Input* orderN;
Fl_Input* date;
Fl_Input* order_robot;
Fl_Input* amount;
Fl_Input* saleman_name;

void create_orderCB(Fl_Widget *w, void* p)
{
	double money = (*robot).get_profit(order_robot->value());
	string convert = amount->value();
	//order: name, address, phone#, email, robot, order#, date, saleman, quantity, profit
	return (*order).set_order(customer_name->value(), customer_add->value(), customer_phone->value(), customer_email->value(), order_robot->value(),
		orderN->value(), date->value(), saleman_name->value(), atof(convert.c_str()), money);
}

customerOrder::customerOrder()
{
	customer_name = new Fl_Input(100,10,200,30, "name");
	customer_add = new Fl_Input(100, 50, 200, 30, "address");
	customer_phone = new Fl_Input(100, 90, 200, 30, "phone");
	customer_email = new Fl_Input(100, 130, 200, 30, "email");
	order_robot = new Fl_Input(100, 170, 200, 30, "ordered robot");
	orderN = new Fl_Input(100, 210, 200, 30, "order number");
	date = new Fl_Input(100, 250, 200, 30, "date");
	amount = new Fl_Input(100, 290, 200, 30, "quantity");
	saleman_name = new Fl_Input(100, 330, 200, 30, "saleman name");

	Fl_Button* create = new Fl_Button(100, 400, 100, 30, "Ok");
	create->callback(create_orderCB);
}

//record order of customer
void customerOrder::set_order(string nameC, string address, string phone, string email, string robotOrder, string number, string day, string sa, double count, double money)
{
	BC_name.push_back(nameC);
	BC_address.push_back(address);
	BC_phone.push_back(phone);
	BC_email.push_back(email);
	order_number.push_back(number);
	sale_date.push_back(day);
	robot_ordered.push_back(robotOrder);
	quantity.push_back(count);
	saleman.push_back(sa);
	profit.push_back(count*money);

	//cout << nameC << "," << address << "," << phone << "," << email << "," << robotOrder << "," << number << "," << day << "," << sa << "," << count << "," << money << endl;
}

void customerOrder::customer_info()
{
	int n = BC_name.size();
	for (int i = 0; i < n; i++)
	{
		ostringstream of;
		of << (i + 1) << ". " << BC_name[i] << "\n " << BC_address[i] << "\n phone#: " << BC_phone[i] << "\n email: " << BC_email[i] << "\n bought robot: "
			<< robot_ordered[i] << ", quantity: " << quantity[i] << endl;

		Fl_Multiline_Output* customer_output = new Fl_Multiline_Output(100, 10 + i * 160, 400, 150, "customer:");
		customer_output->value((of.str()).c_str());
	}
}

void customerOrder::sale_info()
{
	int n = BC_name.size();
	for (int i = 0; i < n; i++)
	{
		ostringstream of;
		of << (i + 1) << ". " << saleman[i] << "\n sold robot: " << robot_ordered[i] << ", quantity: " << quantity[i] << endl;

		Fl_Multiline_Output* associate_output = new Fl_Multiline_Output(50, 10 + i * 160, 400, 150, "sale:");
		associate_output->value((of.str()).c_str());
	}
}

/*
void customerOrder::print(string name)
{
	int sum = 0;
	int size = saleman.size();

	cout << name << ": \n";
	for (int i = 0; i < size; i++)
	{
		if (name == saleman[i])
		{
			sum += profit[i];
			cout << "\t sold " << robot_ordered[i] << ", quantity " << quantity[i] <<endl;
		}
	}
	cout << "\t profit: $" << sum << endl;
}

double customerOrder::total_profit()
{
	int sum = 0;
	int size = profit.size();
	for (int i = 0; i < size; i++)
	{
		sum += profit[i];
	}
	return sum;
}

//write data into text file
void customerOrder::save()
{
	int size = BC_name.size();
	fstream dataFile;
	dataFile.open("data.txt", ios::out | ios::app);

	for (int i = 0; i < size; i++)
	{
		dataFile << saleman[i] << " sold " << robot_ordered[i] << ", #" << order_number[i] << ", " << sale_date[i]
			<< ", quantity: " << quantity[i] << ", profit: " << profit[i] << endl;
	}
	dataFile.close();
}

//customer can see their order
void customerOrder::customer_order(string name)
{
	int size = BC_name.size();
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		if (BC_name[i] == name)
		{
			cout << robot_ordered[i] << ", quantity " << quantity[i] << ", " << price[i] << endl;
			sum += price[i];
		}
	}
	cout << "Total price: " << sum << endl;
}

//customer can see bill
void customerOrder::customer_bill(string name)
{
	int size = BC_name.size();
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		if (BC_name[i] == name)
		{
			sum += price[i];
		}
	}
	cout << "Your bill: " << sum << endl;
}

*/