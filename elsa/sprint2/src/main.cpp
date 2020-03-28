#include "mainwin.h"

int main(int argc, char *argv[])
{
	srand(time(NULL));
	auto app = Gtk::Application::create(argc, argv, "elsa.v1_0");
	Mainwin win;
	return app->run(win);
}

