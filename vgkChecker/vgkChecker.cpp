#include <iostream>
#include "../noVanguard/Services.h"

int main()
{
	SetConsoleTitle(L"vgkChecker");

	if (!utilities::is_process_elevated())
	{
		MessageBox(nullptr, L"Process requires elevation.", L"vgkChecker", MB_ICONERROR | MB_OK);
		return -1;
	}

	if (!service_controller::find_manager())
	{
		MessageBox(nullptr, L"A fatal error occured and the program cannot continue.", L"vgkChecker", MB_ICONERROR | MB_OK);
		return -1;
	}

	const int query = service_controller::do_query_svc();

	if (service_controller::get_vgk_status() == SERVICE_RUNNING)
	{
		utilities::log_type(0);
		std::cout << "Vanguard driver is running" << (query == SERVICE_DISABLED ? ", and is set to not auto-start.\n" : ", and is set to auto-start.\n");
	}
	else
	{
		utilities::log_type(0);
		std::cout << "Vanguard driver is not running" << (query == SERVICE_DISABLED ? ", and is set to not auto-start.\n" : ", and is set to auto-start.\n");
	}

	service_controller::close_manager();
	utilities::log_type(0);
	std::cout << "Press enter to close app.\n";
	std::cin.get();
	return 0;
}