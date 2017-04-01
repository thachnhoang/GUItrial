#include <panel.h>
void window2();
//void window1(char* str_user[80]);
int main()
{	
	//char* str_user[80];
	//window1(str_user);
	window2();
	
	endwin();
	return 0;
}


void window2()
{
	WINDOW *my_wins[4];
	PANEL  *my_panels[4];
	//int lines = 25, cols = 110, y = 1, x = 4, i;
	int i;
	char str_msg[100];
	

	initscr();
	cbreak();
	echo();
	start_color(); // type this first in order to use color;

	/* Initialize all the colors */
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);

	/* Create windows for the panels */
	//              (lines, cols, y, x);
	//my_wins[0] = newwin(34, 109, y, x); // layout window
	my_wins[0] = newwin(20, 70, 0 ,0); // public chat window
	my_wins[1] = newwin(3, 48, 16, 1); // enter text window
	my_wins[2] = newwin(9, 19.5, 1, 50); // chat room window
	my_wins[3] = newwin(9, 19.5, 10, 50); // user window
	//my_wins[5] = newwin(15, 24, 18, 87);
	//my_wins[1] = newwin(lines, cols, y + 1, x + 5);
	//my_wins[2] = newwin(lines, cols, y + 2, x + 10);

	/* 
	 * Create borders around the windows so that you can see the effect
	 * of panels
	 */
	for(i = 0; i < 4; ++i) {
		wattron(my_wins[i],COLOR_PAIR(1)); //turn on window border color = yellow
		box(my_wins[i], 0, 0);
		wattroff(my_wins[i],COLOR_PAIR(1)); // turn off color
	}

	/* Attach a panel to each window */

	//my_panels[0] = new_panel(my_wins[0]); // layout window
	
	my_panels[0] = new_panel(my_wins[0]); // chat window
	my_panels[1] = new_panel(my_wins[1]); // enter text window
	my_panels[2] = new_panel(my_wins[2]); // chat room window
	my_panels[3] = new_panel(my_wins[3]); // user window
	//my_panels[5] = new_panel(my_wins[5]);	/* Push 1, order: stdscr-0-1 */
	//my_panels[2] = new_panel(my_wins[2]); 	/* Push 2, order: stdscr-0-1-2 */

	/* Update the stacking order. 2nd panel will be on top */
	update_panels();
-
	/* Show it on the screen */
	doupdate();

	
	mvprintw(2, 55, "Chat Room"); // print text "Chat Room" at this location
	mvprintw(11, 57, "Users"); // print text "Users" at this location

	// Enter puclic chat text here at this location inside panel[2]
	mvprintw(17, 2, "Msg>");
	//mvgetstr(39,6, str);
	int show_msg = 1;//new msg will be show under previous msg
	int second_run = 0; // 
	 while(1)
	{   
		
		mvgetstr(17,6, str_msg);
		mvprintw(17,6, "                                         ");
		if(second_run > 0)
			mvprintw(show_msg+1, 2,"%s",str_msg);
		else
			mvprintw(show_msg, 2,"%s",str_msg);
		show_msg++;//the next msg will show under a pre.msg

		if(show_msg == 14)
			{
			show_msg = 1;
			int new_show_msg;
			for(new_show_msg = 1; new_show_msg < 15; new_show_msg++)
			mvprintw(new_show_msg,2, "                           ");
		    mvprintw(show_msg,2,"%s",str_msg);
		    second_run ++;
			}
	    
    }
	
	refresh();
	getch();
	endwin();
	
}