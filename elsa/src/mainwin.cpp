#include "mainwin.h"
#include "entrydialog.h"
#include <iostream> //for std::cerr logging
#include <sstream>
#include <fstream>

Mainwin::Mainwin() : store{new Store()}, filename{"untitled.elsa"} { 

	//GUI SETUP//

	set_default_size(800,600);
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

	//save - append to file menu
	Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
	menuitem_save->signal_activate().connect([this] {this->on_save_click();});
	filemenu->append(*menuitem_save);

	//save as - append to file menu
	Gtk::MenuItem *menuitem_saveas = Gtk::manage(new Gtk::MenuItem("_Save As", true));
	menuitem_saveas->signal_activate().connect([this] {this->on_save_as_click();});
	filemenu->append(*menuitem_saveas);

	//open - append to file menu
	Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));
	menuitem_open->signal_activate().connect([this] {this->on_open_click();});
	filemenu->append(*menuitem_open);

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

//FILE//
//file > save
void Mainwin::on_save_click()
{
	try{
		std::ofstream ofs{filename}; //open an output stream
		store->save(ofs);
		set_msg("Saved to " + filename);
		if(!ofs) throw std::runtime_error{"Error writing file"};
	}catch(std::exception& e){
		Gtk::MessageDialog{*this, "Unable to save ELSA"}.run();	
	}
}
//file > save as
void Mainwin::on_save_as_click()
{
	Gtk::FileChooserDialog dialog("Please choose a file", Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
	dialog.set_transient_for(*this);

	//create a filter for .elsa files
	auto filter_elsa = Gtk::FileFilter::create();
	filter_elsa->set_name("ELSA files");
	filter_elsa->add_pattern("*.elsa");
	dialog.add_filter(filter_elsa); //add to filter list

	//create a filter for any file
	auto filter_any = Gtk::FileFilter::create();
	filter_any->set_name("Any files");
	filter_any->add_pattern("*");
	dialog.add_filter(filter_any);

	//set default shown filename on the dialog to untitled.elsa
	dialog.set_filename("untitled.elsa");
	
	//add response buttons to the dialog
	dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
	dialog.add_button("_Save", Gtk::RESPONSE_OK);

	if(dialog.run() == Gtk::RESPONSE_OK)
	{
		filename = dialog.get_filename(); //assign user provided filename as most recently saved file		
		on_save_click();
	}
}
//file > open
void Mainwin::on_open_click()
{
	Gtk::FileChooserDialog dialog("Please choose a file", Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);
	dialog.set_transient_for(*this);
	
	//create a filter for .elsa files
	auto filter_elsa = Gtk::FileFilter::create();
	filter_elsa->set_name("ELSA files");
	filter_elsa->add_pattern("*.elsa");
	dialog.add_filter(filter_elsa);

	//creater a filter for any files
	auto filter_any = Gtk::FileFilter::create();
	filter_any->set_name("Any files");
	filter_any->add_pattern("*");
	dialog.add_filter(filter_any);

	//add response buttons
	dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
	dialog.add_button("_Open", Gtk::RESPONSE_OK);

	if(dialog.run() == Gtk::RESPONSE_OK)
	{
		try{
			delete store; //delete old store
			filename = dialog.get_filename(); //assign user provided filename as most recently opened filename
			std::ifstream ifs{filename}; //open input stream with filename
			store = new Store{ifs}; //construct a new store			
			on_view_desktop_click(); //update display			
			set_msg("Opened " + filename);
		}catch(std::exception& e){
			Gtk::MessageDialog{*this, "Unable to open data for ELSA store"}.run();
		}
	}
	

}
//file > quit
void Mainwin::on_quit_click()
{
	close();
}


//VIEW//
//view > customer
void Mainwin::on_view_customer_click()
{
	std::ostringstream oss;

	if(store->num_customers() <= 0)
	{
		oss << "<span size='14000' weight='bold'>There are currently no customers. To add a customer, click Insert > Customer.</span>";
	}
	else
	{
		oss << "<span size='20000' weight='bold'>Customers</span>\n\n<span size='14000'>";		
		//list all customers
		for(int i=0; i<store->num_customers(); ++i)
		{
			oss << i << ") " << store->customer(i) << "\n";
		}
		oss << "</span>";
	}
	set_data(oss.str());
	set_msg("");
}

//view > peripheral
void Mainwin::on_view_peripheral_click()
{
	std::ostringstream oss;
	
	//if there are currently no options
	if(store->num_options() <= 0)
	{
		oss << "<span size='14000' weight='bold'>There are currently no peripherals. To add a new peripheral, click Insert > Peripheral.</span>";
	}
	else
	{
		oss << "<span size='20000' weight='bold'>Peripherals</span>\n\n<span size='14000'>";
		//list all peripherals
		for(int i=0; i<store->num_options(); ++i)
		{
			oss << i << ") " << store->option(i) << "\n";
		}
		oss << "</span>";
	}

	set_data(oss.str());
	set_msg("");
}

//view > desktop
void Mainwin::on_view_desktop_click()
{
	std::ostringstream oss;

	if(store->num_desktops() <= 0)
	{
		oss << "<span size='14000' weight='bold'>There are currently no products. To add a new product, click Insert > Desktop.</span>";
	}
	else
	{
		oss << "<span size='20000' weight='bold'>Products</span>\n\n<span size='14000'>";
		//list all desktops
		for(int i=0; i<store->num_desktops(); ++i)
		{
			oss << i << ") " << store->desktop(i) << "\n";
		}
		oss << "</span>";
	}

	set_data(oss.str());
	set_msg("");
}

//view > order
void Mainwin::on_view_order_click()
{
	std::ostringstream oss;
	
	if(store->num_orders() <= 0)
	{
		oss << "<span size='14000' weight='bold'>There are currently no orders. To add a new order, click Insert > Order.</span>";
	}
	else
	{
		oss << "<span size='20000' weight='bold'>Order(s)</span>\n\n<span size='14000'>";
		//list out all orders
		for(int i=0; i<store->num_orders(); ++i)
		{
			oss << i << ") " << store->order(i) << '\n';
		}
		oss << "</span>";
	}

	set_data(oss.str());
	set_msg("");
}


//INSERT//
//insert > customer
void Mainwin::on_insert_customer_click()
{
	//for creating custom dialog w/ grid idk this is so many lines i cant see im tired
	Gtk::Dialog dialog{"Insert Customer", *this};
	
	//grid for placing widgets and jazz into the dialog, upper left at (0,0)
	Gtk::Grid grid;

	//respective name, phone, email labels
	Gtk::Label c_name{"Name"};
	Gtk::Label c_phone{"Phone"};
	Gtk::Label c_email{"Email"};

	//name, phone, email entry dialogs to put into the grid
	Gtk::Entry e_name{};
	Gtk::Entry e_phone{};
	Gtk::Entry e_email{};

	//data validation
	e_name.set_placeholder_text("*required*");
	e_phone.set_placeholder_text("xxx-xxx-xxxx");
	e_email.set_placeholder_text("xxx@domain.com");
	
	//add these bad boys to the grid lol
	grid.attach(c_name, 0,0,1,1); //attached at (0,0) single width and single height
	grid.attach(e_name, 1,0,2,1);
	grid.attach(c_phone, 0,1,1,1);
	grid.attach(e_phone, 1,1,2,1);
	grid.attach(c_email, 0,2,1,1);
	grid.attach(e_email, 1,2,2,1);

	//okkkkkkkk let's add teh grid to the dialog's VBox aka content area
	dialog.get_content_area()->add(grid);
	//add the buttons so we can escape properly
	dialog.add_button("Insert", Gtk::RESPONSE_OK);
	dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);	

	//finally, show everything
	dialog.show_all();
	
	while(dialog.run() == Gtk::RESPONSE_OK)
	{
		//data validation
		if(!(e_name.get_text().size()))
		{
			Gtk::MessageDialog{*this, "Please enter a customer name"}.run();
			continue; //onto next iteration
		}
		
		//get the entries
		std::string name = e_name.get_text();
		std::string phone = e_phone.get_text();
		std::string email = e_email.get_text();
		//instance and add the customer to Store::add_customer
		Customer customer{name, phone, email};		
		store->add_customer(customer);

		//call on_view_customer_click to show the new customer that is added to the data area and update status bar
		on_view_customer_click();
		set_msg("Added customer " + name);
		break;
	}
}

//insert > peripheral
void Mainwin::on_insert_peripheral_click()
{
	//ok last thing to do
	//create dialog for customization
	Gtk::Dialog dialog{"Insert Peripheral", *this};
	
	//lets put everything in here
	Gtk::Grid grid;

	Gtk::Label radio_select{"Select a peripheral type:"};
	Gtk::Label name{"Peripheral Name"};
	Gtk::Label cost{"Cost"};
	Gtk::Label size{"RAM Size"};

	Gtk::Entry e_name{};
	Gtk::Entry e_cost{};
	Gtk::Entry e_size{};
	
	e_name.set_placeholder_text("*required*");
	e_cost.set_placeholder_text("*required*");
	e_size.set_placeholder_text("*required for RAM*");

	//lets make a radio button group bc i wanna practice it
	Gtk::RadioButton ram_radio{"RAM"};
	Gtk::RadioButton other_radio{"Other"};

	grid.attach(radio_select, 0,0,1,1);
	grid.attach(ram_radio, 0,1,2,1);
	grid.attach(other_radio, 0,2,2,1);

	ram_radio.join_group(other_radio);

	grid.attach(name, 0,4,1,1);
	grid.attach(e_name, 1,4,2,1);
	grid.attach(cost, 0,5,1,1);
	grid.attach(e_cost, 1,5,2,1);
	grid.attach(size, 0,6,1,1);
	grid.attach(e_size, 1,6,2,1);

	dialog.get_content_area()->add(grid);

	dialog.add_button("Insert", Gtk::RESPONSE_OK);
	dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);

	//show everything
	dialog.show_all();

	//for noting which one is toggled
	int selected_radio;

	while(dialog.run() == Gtk::RESPONSE_OK)
	{
		//see which one is toggled when the user presses insert		
		if(ram_radio.get_active())
			selected_radio = 1;
		else
			selected_radio = 2; //other peripheral type will be set by default if they dont selected anything
		
		//data validation
		if(!(e_name.get_text().size()) || !(e_cost.get_text().size()) || (!(e_size.get_text().size()) && selected_radio == 1))
		{
			Gtk::MessageDialog{*this, "Please fill in the required fields"}.run();
			continue;
		}

		//get the entries
		std::string name = e_name.get_text();
		double cost = std::stod(e_cost.get_text());

		//add new peripheral to list in store depending on type
		if(selected_radio == 1)
		{
			int size = std::stoi(e_size.get_text());
			Ram ram{name, cost, size};
			store->add_option(ram);
		}
		else
		{
			Options option{name, cost};
			store->add_option(option);
		}
		
		on_view_peripheral_click();
		set_msg("Added peripheral " + std::to_string((store->num_options())-1));
		break;
	}
}

//insert > desktop
void Mainwin::on_insert_desktop_click()
{
	//let's create a new product
	int desktop = store->new_desktop();
	on_view_desktop_click();
	set_msg("Added desktop " + std::to_string(desktop));
	
	//for the prompt	
	std::ostringstream oss;
	for(int i=0; i<store->num_options(); ++i)
	{
		oss << i << ") " << store->option(i) << '\n';
	}
	oss << "\nAdd which peripheral?";

	int option;	
	do{
		option = get_int(oss.str());

		if(option >= 0 && option < store->num_options())
		{
			store->add_option(option,desktop);
			on_view_desktop_click();
			set_msg("Added peripheral " + std::to_string(option) + " to desktop " + std::to_string(desktop));
		}
		else if(option != -1)
		{
			std::cerr << "Invalid option" << std::endl;
		}
	}while(option != -1);
}

//insert > order
void Mainwin::on_insert_order_click()
{
	int customer = -1;
	int order = -1;
	int desktop = -1;

	if(store->num_desktops() <= 0 || store->num_customers() <= 0)
	{
		set_data("<span size='14000' weight='bold'>There are currently either no customers or no products to create an order.\n\nTo add a new customer, click Insert > Customer.\nTo add a new product, click Insert > Desktop.</span>");
		return;
	}
	
	//for prompt
	std::ostringstream oss;

	for(int i=0; i<store->num_customers(); ++i)
	{
		oss << i << ") " << store->customer(i) << '\n';
	}
	oss << "\nCustomer? ";
	customer = get_int(oss.str());
	
	if(customer >= 0 && customer < store->num_customers())
	{
		try{
			order = store->new_order(customer);
			desktop = 0;
		}catch(std::exception& e){
			std::cerr << "Unable to create order for customer " << customer << std::endl;
		}

		on_view_order_click();
		set_msg("Added order " + std::to_string(order));

		//for next prompt
		oss.str("");	
		oss.clear();
		for(int i=0; i<store->num_desktops(); ++i)
		{
			oss << i << ") " << store->desktop(i) << "\n";
		}
		oss << "\nAdd which desktop to the order?";

		do{
			desktop = get_int(oss.str());
			
			if(desktop >= 0 && desktop < store->num_desktops())
			{
				try{
					store->add_desktop(desktop, order);
				}catch(std::exception& e){
					std::cerr << "Unable to add desktop " << desktop << " to order " << order << std::endl;
				}

				on_view_order_click();
				set_msg("Added desktop " + std::to_string(desktop) + " to order " + std::to_string(order));
			}
			else if(desktop != -1)
			{
				std::cerr << "Invalid desktop" << std::endl;
			}
		}while(desktop != -1);
	}
}


//ABOUT//
//about > help
void Mainwin::on_about_click()
{
	Gtk::AboutDialog dialog;

	dialog.set_transient_for(*this); //avoid the discouraging warning;
	dialog.set_program_name("Exceptional Laptops and Supercomputers Always (ELSA)");
	dialog.set_version("Version 1.0");
	dialog.set_copyright("Copyright 2019-2020");
	dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
	std::vector<Glib::ustring> authors = {"Hoang Ho"};
	dialog.set_authors(authors);
	dialog.set_comments("A management system for the ELSA store which manages customer, peripheral, product, and order information.");
	dialog.run();
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
	double num;

	try{
		num = std::stod(get_string(prompt));
		return num;
	}catch(std::exception& e){
		return -1.0;
	}
}
int Mainwin::get_int(std::string prompt)
{
	int num;	
	try{
		num = std::stoi(get_string(prompt));
		return num;
	}catch(std::exception& e){
		return -1;
	}
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
