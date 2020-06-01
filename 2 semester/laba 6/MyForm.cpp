#include "MyForm.h"
#include <Windows.h>
#include "funtions.h"
using namespace LabaVI;
std::string a, b, c, op;
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}
