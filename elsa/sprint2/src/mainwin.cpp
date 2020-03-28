#include "mainwin.h"
#include "entrydialog.h"
#include <iostream> //for std::cerr logging

Mainwin::Mainwin() : store{new Store()} { 

	//GUI SETUP//

	set_default_size(400,200);
	set_title("Exceptional Laptops and Supercomputer Always (ELSA) Store");
	
	//put vertical box container as the window contents for nesting later
	Gtk::Box *vbox = Gtk::manage(new Gtk::VBox); //manage will automatically delete all widgets from the heap if window closes
	add(*vbox);

	//MENU BAR//
	//add a menu bar as top item of the vbox
	Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
	vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
	//alternatively, vbox->add(*menubar)

	//FILE//
	//create file menu item and add to menu bar w/ accelerator to allow Alt+F
	Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
	menubar->append(*menuitem_file);

	//create menu drop down within menu item
	Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
	menuitem_file->set_submenu(*filemenu);

	//quit - append to file menu
	Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
	//watch for when clicked
	menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
	filemenu->append(*menuitem_quit);

	//--------------

	//VIEW//
	//create view menu item and add to menu bar
	Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
	menubar->append(*menuitem_view);

	//create submenus with customer, peripheral, desktop, order menuitems added
	Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
	menuitem_view->set_submenu(*viewmenu);

	//customer - append to view menu
	Gtk::MenuItem *menuitem_view_customer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
	menuitem_view_customer->signal_activate().connect([this] {this->on_view_customer_click();});
	viewmenu->append(*menuitem_view_customer);

	//peripheral - append to view menu
	Gtk::MenuItem *menuitem_view_peripheral = Gtk::manage(new Gtk::MenuItem("_Peripheral", true));
	menuitem_view_peripheral->signal_activate().connect([this] {this->on_view_peripheral_click();});
	viewmenu->append(*menuitem_view_peripheral);

	//desktop - append to view menu
	Gtk::MenuItem *menuitem_view_desktop = Gtk::manage(new Gtk::MenuItem("_Desktop", true));
	menuitem_view_desktop->signal_activate().connect([this] {this->on_view_desktop_click();});
	viewmenu->append(*menuitem_view_desktop);

	//order - append to view menu
	Gtk::MenuItem *menuitem_view_order = Gtk::manage(new Gtk::MenuItem("_Order", true));
	menuitem_view_order->signal_activate().connect([this] {this->on_view_order_click();});
	viewmenu->append(*menuitem_view_order);

	//--------------

	//INSERT//
	//create insert menuitem and append to menubar
	Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
	menubar->append(*menuitem_insert);

	//create submenu
	Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
	menuitem_insert->set_submenu(*insertmenu);

	//customer - append to insert menu
	Gtk::MenuItem *menuitem_insert_customer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
	menuitem_insert_customer->signal_activate().connect([this] {this->on_insert_customer_click();});
	insertmenu->append(*menuitem_insert_customer);

	//peripheral - insert menu
	Gtk::MenuItem *menuitem_insert_peripheral = Gtk::manage(new Gtk::MenuItem("_Peripheral", true));
	menuitem_insert_peripheral->signal_activate().connect([this] {this->on_insert_peripheral_click();});
	insertmenu->append(*menuitem_insert_peripheral);

	//desktop - insert menu
	Gtk::MenuItem *menuitem_insert_desktop = Gtk::manage(new Gtk::MenuItem("_Desktop", true));
	menuitem_insert_desktop->signal_activate().connect([this] {this->on_insert_desktop_click();});
	insertmenu->append(*menuitem_insert_desktop);

	//order - insert menu
	Gtk::MenuItem *menuitem_insert_order = Gtk::manage(new Gtk::MenuItem("_Order", true));
	menuitem_insert_order->signal_activate().connect([this] {this->on_insert_order_click();});
	insertmenu->append(*menuitem_insert_order);

	//--------------	

	//HELP//
	//create help menu item and add to menubar
	Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
	menubar->append(*menuitem_help);

	//create submenu
	Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
	menuitem_help->set_submenu(*helpmenu);

	//about - help menu
	Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
	menuitem_about->signal_activate().connect([this] {this->on_about_click();});
	helpmenu->append(*menuitem_about);

	//--------------

	//DISPLAY//

	data = Gtk::manage(new Gtk::Label());
	data->set_hexpand(true);
	data->set_vexpand(true);
	vbox->pack_start(*data, Gtk::PACK_SHRINK, 0);
	
	//status bar
	msg = Gtk::manage(new Gtk::Label());
	msg->set_hexpand(true);
	vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);

	//make the box and everything in it visible
	vbox->show_all();
}
Mainwin::~Mainwin() {}

//methods

//FILE > QUIT//
void Mainwin::on_quit_click()
{
	close();
}


//VIEW//
//view > customer
void Mainwin::on_view_customer_click()
{
	
}

//view > peripheral
void Mainwin::on_view_peripheral_click()
{
}

//view > desktop
void Mainwin::on_view_desktop_click()
{
}

//view > order
void Mainwin::on_view_order_click()
{
}


//INSERT//
//insert > customer
void Mainwin::on_insert_customer_click()
{
	//call get_string to open up an entry dialog that asks for customer's name
	std::string name = get_string("Customer name? ");
	
	if(name.size())
	{
		//get phone and email
		std::string phone = get_string("Customer phone (xxx-xxx-xxxx)? ");
		std::string email = get_string("Customer email (xxx@domain.com)?");
		//instance and add the customer to Store::add_customer
		Customer customer{name, phone, email};		
		store->add_customer(customer);

		//update status bar and call on_view_customer_click to show the new customer that is added to the data area
		set_msg("Added customer" + name);
		on_view_customer_click();
	}
}

//insert > peripheral
void Mainwin::on_insert_peripheral_click()
{
}

//insert > desktop
void Mainwin::on_insert_desktop_click()
{
}

//insert > order
void Mainwin::on_insert_order_click()
{
}


//ABOUT//
//about > help
void Mainwin::on_about_click()
{
}


//UTILITY METHODS//
//getters
std::string Mainwin::get_string(std::string prompt)
{
	EntryDialog ed{*this, prompt};
	ed.run();

	return ed.get_text();
}
double Mainwin::get_double(std::string prompt)
{
	return std::stod(get_string(prompt));
}
int Mainwin::get_int(std::string prompt)
{
	return std::stoi(get_string(prompt));
}

//setters
void Mainwin::set_data(std::string s)
{
	data->set_markup(s);
}
void Mainwin::set_msg(std::string s)
{
	msg->set_markup(s);
}
