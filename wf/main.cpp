#include "MyForm.h"
#include "RegisterForm.h"
#include "price_main.h"
#include "Output.h"

[System::STAThreadAttribute]
int main(array<System::String^>^ args) {
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
	System::Windows::Forms::Application::EnableVisualStyles();
	wf::MyForm form;
	System::Windows::Forms::Application::Run(% form);
}
