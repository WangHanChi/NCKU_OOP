// OOP HW3 ����ҺӤ@ N16110158 ���~�R
// Tick_Tac_Toe.cpp

#include "Tick_Tac_Toe.h"

using namespace System::Windows::Forms;
using namespace System;
using namespace HW3;

int main(array<System::String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew Tick_Tac_Toe());

	return 0;
}

