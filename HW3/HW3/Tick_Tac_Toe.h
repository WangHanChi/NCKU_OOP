#pragma once
// OOP HW3 機械所碩一 N16110158 王漢祺
// Tick_Tac_Toe.h
#include "Setting.h"
#include "Result.h"

namespace HW3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Tick_Tac_Toe 的摘要
	/// </summary>
	public ref class Tick_Tac_Toe : public System::Windows::Forms::Form
	{
	public:
		Tick_Tac_Toe(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

		// 自己加的變數
		static int sec = 0, min = 0;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel_Which_block;
	public:
		bool Gaming_mode = 0;	// 判斷現在是哪個mode
		bool whos_turn = 0;		// 判斷現在是誰的回合
		bool symbol = 0;		// 判斷現在該放O還是X, 0 -> O, 1 -> X 
		static System::String^ First;
		static System::String^ winner;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel_whos_turn;
	public:
		int count = 0;
	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~Tick_Tac_Toe()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  PlayGround;
	private: System::Windows::Forms::Button^ block3_3;
	protected:

	private: System::Windows::Forms::Button^ block3_2;

	private: System::Windows::Forms::Button^ block3_1;

	private: System::Windows::Forms::Button^ block2_3;

	private: System::Windows::Forms::Button^ block2_2;

	private: System::Windows::Forms::Button^ block2_1;

	private: System::Windows::Forms::Button^ block1_3;

	private: System::Windows::Forms::Button^ block1_2;

	private: System::Windows::Forms::Button^  block1_1;
	private: System::Windows::Forms::GroupBox^  Set_Who_First;
	private: System::Windows::Forms::RadioButton^  radioButton_Player2;
	private: System::Windows::Forms::RadioButton^  radioButton_Player1;
	private: System::Windows::Forms::StatusStrip^  statusStrip_position;
	private: System::Windows::Forms::Timer^  timer_count;


	private: System::Windows::Forms::Label^  Timer;
	private: System::Windows::Forms::Label^  Timer_text;
	private: System::Windows::Forms::Button^  button_start_stop;
	private: System::Windows::Forms::Button^  button_setting;

	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Tick_Tac_Toe::typeid));
			this->PlayGround = (gcnew System::Windows::Forms::GroupBox());
			this->block3_3 = (gcnew System::Windows::Forms::Button());
			this->block3_2 = (gcnew System::Windows::Forms::Button());
			this->block3_1 = (gcnew System::Windows::Forms::Button());
			this->block2_3 = (gcnew System::Windows::Forms::Button());
			this->block2_2 = (gcnew System::Windows::Forms::Button());
			this->block2_1 = (gcnew System::Windows::Forms::Button());
			this->block1_3 = (gcnew System::Windows::Forms::Button());
			this->block1_2 = (gcnew System::Windows::Forms::Button());
			this->block1_1 = (gcnew System::Windows::Forms::Button());
			this->Set_Who_First = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton_Player2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_Player1 = (gcnew System::Windows::Forms::RadioButton());
			this->statusStrip_position = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel_Which_block = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel_whos_turn = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->timer_count = (gcnew System::Windows::Forms::Timer(this->components));
			this->Timer = (gcnew System::Windows::Forms::Label());
			this->Timer_text = (gcnew System::Windows::Forms::Label());
			this->button_start_stop = (gcnew System::Windows::Forms::Button());
			this->button_setting = (gcnew System::Windows::Forms::Button());
			this->PlayGround->SuspendLayout();
			this->Set_Who_First->SuspendLayout();
			this->statusStrip_position->SuspendLayout();
			this->SuspendLayout();
			// 
			// PlayGround
			// 
			this->PlayGround->Controls->Add(this->block3_3);
			this->PlayGround->Controls->Add(this->block3_2);
			this->PlayGround->Controls->Add(this->block3_1);
			this->PlayGround->Controls->Add(this->block2_3);
			this->PlayGround->Controls->Add(this->block2_2);
			this->PlayGround->Controls->Add(this->block2_1);
			this->PlayGround->Controls->Add(this->block1_3);
			this->PlayGround->Controls->Add(this->block1_2);
			this->PlayGround->Controls->Add(this->block1_1);
			this->PlayGround->Font = (gcnew System::Drawing::Font(L"新細明體", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->PlayGround->Location = System::Drawing::Point(12, 24);
			this->PlayGround->Name = L"PlayGround";
			this->PlayGround->Size = System::Drawing::Size(368, 378);
			this->PlayGround->TabIndex = 0;
			this->PlayGround->TabStop = false;
			this->PlayGround->Text = L"遊戲區";
			// 
			// block3_3
			// 
			this->block3_3->Enabled = false;
			this->block3_3->Font = (gcnew System::Drawing::Font(L"新細明體", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->block3_3->Location = System::Drawing::Point(229, 260);
			this->block3_3->Name = L"block3_3";
			this->block3_3->Size = System::Drawing::Size(100, 100);
			this->block3_3->TabIndex = 8;
			this->block3_3->UseVisualStyleBackColor = true;
			this->block3_3->Click += gcnew System::EventHandler(this, &Tick_Tac_Toe::block_Click);
			this->block3_3->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Tick_Tac_Toe::block_MouseMove);
			// 
			// block3_2
			// 
			this->block3_2->Enabled = false;
			this->block3_2->Font = (gcnew System::Drawing::Font(L"新細明體", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->block3_2->Location = System::Drawing::Point(123, 260);
			this->block3_2->Name = L"block3_2";
			this->block3_2->Size = System::Drawing::Size(100, 100);
			this->block3_2->TabIndex = 7;
			this->block3_2->UseVisualStyleBackColor = true;
			this->block3_2->Click += gcnew System::EventHandler(this, &Tick_Tac_Toe::block_Click);
			this->block3_2->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Tick_Tac_Toe::block_MouseMove);
			// 
			// block3_1
			// 
			this->block3_1->Enabled = false;
			this->block3_1->Font = (gcnew System::Drawing::Font(L"新細明體", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->block3_1->Location = System::Drawing::Point(17, 260);
			this->block3_1->Name = L"block3_1";
			this->block3_1->Size = System::Drawing::Size(100, 100);
			this->block3_1->TabIndex = 6;
			this->block3_1->UseVisualStyleBackColor = true;
			this->block3_1->Click += gcnew System::EventHandler(this, &Tick_Tac_Toe::block_Click);
			this->block3_1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Tick_Tac_Toe::block_MouseMove);
			// 
			// block2_3
			// 
			this->block2_3->Enabled = false;
			this->block2_3->Font = (gcnew System::Drawing::Font(L"新細明體", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->block2_3->Location = System::Drawing::Point(229, 154);
			this->block2_3->Name = L"block2_3";
			this->block2_3->Size = System::Drawing::Size(100, 100);
			this->block2_3->TabIndex = 5;
			this->block2_3->UseVisualStyleBackColor = true;
			this->block2_3->Click += gcnew System::EventHandler(this, &Tick_Tac_Toe::block_Click);
			this->block2_3->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Tick_Tac_Toe::block_MouseMove);
			// 
			// block2_2
			// 
			this->block2_2->Enabled = false;
			this->block2_2->Font = (gcnew System::Drawing::Font(L"新細明體", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->block2_2->Location = System::Drawing::Point(123, 154);
			this->block2_2->Name = L"block2_2";
			this->block2_2->Size = System::Drawing::Size(100, 100);
			this->block2_2->TabIndex = 4;
			this->block2_2->UseVisualStyleBackColor = true;
			this->block2_2->Click += gcnew System::EventHandler(this, &Tick_Tac_Toe::block_Click);
			this->block2_2->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Tick_Tac_Toe::block_MouseMove);
			// 
			// block2_1
			// 
			this->block2_1->Enabled = false;
			this->block2_1->Font = (gcnew System::Drawing::Font(L"新細明體", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->block2_1->Location = System::Drawing::Point(17, 154);
			this->block2_1->Name = L"block2_1";
			this->block2_1->Size = System::Drawing::Size(100, 100);
			this->block2_1->TabIndex = 3;
			this->block2_1->UseVisualStyleBackColor = true;
			this->block2_1->Click += gcnew System::EventHandler(this, &Tick_Tac_Toe::block_Click);
			this->block2_1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Tick_Tac_Toe::block_MouseMove);
			// 
			// block1_3
			// 
			this->block1_3->Enabled = false;
			this->block1_3->Font = (gcnew System::Drawing::Font(L"新細明體", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->block1_3->Location = System::Drawing::Point(229, 48);
			this->block1_3->Name = L"block1_3";
			this->block1_3->Size = System::Drawing::Size(100, 100);
			this->block1_3->TabIndex = 2;
			this->block1_3->UseVisualStyleBackColor = true;
			this->block1_3->Click += gcnew System::EventHandler(this, &Tick_Tac_Toe::block_Click);
			this->block1_3->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Tick_Tac_Toe::block_MouseMove);
			// 
			// block1_2
			// 
			this->block1_2->Enabled = false;
			this->block1_2->Font = (gcnew System::Drawing::Font(L"新細明體", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->block1_2->Location = System::Drawing::Point(123, 48);
			this->block1_2->Name = L"block1_2";
			this->block1_2->Size = System::Drawing::Size(100, 100);
			this->block1_2->TabIndex = 1;
			this->block1_2->UseVisualStyleBackColor = true;
			this->block1_2->Click += gcnew System::EventHandler(this, &Tick_Tac_Toe::block_Click);
			this->block1_2->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Tick_Tac_Toe::block_MouseMove);
			// 
			// block1_1
			// 
			this->block1_1->Enabled = false;
			this->block1_1->Font = (gcnew System::Drawing::Font(L"新細明體", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->block1_1->Location = System::Drawing::Point(17, 48);
			this->block1_1->Name = L"block1_1";
			this->block1_1->Size = System::Drawing::Size(100, 100);
			this->block1_1->TabIndex = 0;
			this->block1_1->UseVisualStyleBackColor = true;
			this->block1_1->Click += gcnew System::EventHandler(this, &Tick_Tac_Toe::block_Click);
			this->block1_1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Tick_Tac_Toe::block_MouseMove);
			// 
			// Set_Who_First
			// 
			this->Set_Who_First->Controls->Add(this->radioButton_Player2);
			this->Set_Who_First->Controls->Add(this->radioButton_Player1);
			this->Set_Who_First->Font = (gcnew System::Drawing::Font(L"新細明體", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Set_Who_First->Location = System::Drawing::Point(401, 36);
			this->Set_Who_First->Name = L"Set_Who_First";
			this->Set_Who_First->Size = System::Drawing::Size(398, 186);
			this->Set_Who_First->TabIndex = 1;
			this->Set_Who_First->TabStop = false;
			this->Set_Who_First->Text = L"誰要先手";
			this->Set_Who_First->Enter += gcnew System::EventHandler(this, &Tick_Tac_Toe::Set_Who_First_Enter);
			// 
			// radioButton_Player2
			// 
			this->radioButton_Player2->AutoSize = true;
			this->radioButton_Player2->Enabled = false;
			this->radioButton_Player2->Location = System::Drawing::Point(21, 108);
			this->radioButton_Player2->Name = L"radioButton_Player2";
			this->radioButton_Player2->Size = System::Drawing::Size(87, 28);
			this->radioButton_Player2->TabIndex = 1;
			this->radioButton_Player2->Text = L"玩家2";
			this->radioButton_Player2->UseVisualStyleBackColor = true;
			this->radioButton_Player2->CheckedChanged += gcnew System::EventHandler(this, &Tick_Tac_Toe::First_CheckedChanged);
			// 
			// radioButton_Player1
			// 
			this->radioButton_Player1->AutoSize = true;
			this->radioButton_Player1->Checked = true;
			this->radioButton_Player1->Enabled = false;
			this->radioButton_Player1->Location = System::Drawing::Point(21, 36);
			this->radioButton_Player1->Name = L"radioButton_Player1";
			this->radioButton_Player1->Size = System::Drawing::Size(87, 28);
			this->radioButton_Player1->TabIndex = 0;
			this->radioButton_Player1->TabStop = true;
			this->radioButton_Player1->Text = L"玩家1";
			this->radioButton_Player1->UseVisualStyleBackColor = true;
			this->radioButton_Player1->CheckedChanged += gcnew System::EventHandler(this, &Tick_Tac_Toe::First_CheckedChanged);
			// 
			// statusStrip_position
			// 
			this->statusStrip_position->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripStatusLabel_Which_block,
					this->toolStripStatusLabel_whos_turn
			});
			this->statusStrip_position->Location = System::Drawing::Point(0, 438);
			this->statusStrip_position->Name = L"statusStrip_position";
			this->statusStrip_position->Size = System::Drawing::Size(811, 22);
			this->statusStrip_position->TabIndex = 2;
			this->statusStrip_position->Text = L"statusStrip_position";
			// 
			// toolStripStatusLabel_Which_block
			// 
			this->toolStripStatusLabel_Which_block->Name = L"toolStripStatusLabel_Which_block";
			this->toolStripStatusLabel_Which_block->Size = System::Drawing::Size(83, 17);
			this->toolStripStatusLabel_Which_block->Text = L"(NULL, NULL)";
			// 
			// toolStripStatusLabel_whos_turn
			// 
			this->toolStripStatusLabel_whos_turn->Name = L"toolStripStatusLabel_whos_turn";
			this->toolStripStatusLabel_whos_turn->Size = System::Drawing::Size(62, 17);
			this->toolStripStatusLabel_whos_turn->Text = L"No Player";
			// 
			// timer_count
			// 
			this->timer_count->Interval = 1000;
			this->timer_count->Tick += gcnew System::EventHandler(this, &Tick_Tac_Toe::timer_count_Tick);
			// 
			// Timer
			// 
			this->Timer->AutoSize = true;
			this->Timer->Font = (gcnew System::Drawing::Font(L"新細明體", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Timer->Location = System::Drawing::Point(568, 237);
			this->Timer->Name = L"Timer";
			this->Timer->Size = System::Drawing::Size(71, 27);
			this->Timer->TabIndex = 3;
			this->Timer->Text = L"00:00";
			// 
			// Timer_text
			// 
			this->Timer_text->AutoSize = true;
			this->Timer_text->Font = (gcnew System::Drawing::Font(L"新細明體", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Timer_text->Location = System::Drawing::Point(396, 237);
			this->Timer_text->Name = L"Timer_text";
			this->Timer_text->Size = System::Drawing::Size(141, 27);
			this->Timer_text->TabIndex = 4;
			this->Timer_text->Text = L"經過時間 : ";
			this->Timer_text->Click += gcnew System::EventHandler(this, &Tick_Tac_Toe::Timer_text_Click);
			// 
			// button_start_stop
			// 
			this->button_start_stop->Enabled = false;
			this->button_start_stop->Font = (gcnew System::Drawing::Font(L"新細明體", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button_start_stop->Location = System::Drawing::Point(401, 353);
			this->button_start_stop->Name = L"button_start_stop";
			this->button_start_stop->Size = System::Drawing::Size(133, 49);
			this->button_start_stop->TabIndex = 5;
			this->button_start_stop->Text = L"start";
			this->button_start_stop->UseVisualStyleBackColor = true;
			this->button_start_stop->Click += gcnew System::EventHandler(this, &Tick_Tac_Toe::button_start_stop_Click);
			// 
			// button_setting
			// 
			this->button_setting->Font = (gcnew System::Drawing::Font(L"新細明體", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button_setting->Location = System::Drawing::Point(555, 353);
			this->button_setting->Name = L"button_setting";
			this->button_setting->Size = System::Drawing::Size(133, 49);
			this->button_setting->TabIndex = 6;
			this->button_setting->Text = L"setting";
			this->button_setting->UseVisualStyleBackColor = true;
			this->button_setting->Click += gcnew System::EventHandler(this, &Tick_Tac_Toe::button_setting_Click);
			// 
			// Tick_Tac_Toe
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(811, 460);
			this->Controls->Add(this->button_setting);
			this->Controls->Add(this->button_start_stop);
			this->Controls->Add(this->Timer_text);
			this->Controls->Add(this->Timer);
			this->Controls->Add(this->statusStrip_position);
			this->Controls->Add(this->Set_Who_First);
			this->Controls->Add(this->PlayGround);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Tick_Tac_Toe";
			this->Text = L"Tick_Tac_Toe";
			this->PlayGround->ResumeLayout(false);
			this->Set_Who_First->ResumeLayout(false);
			this->Set_Who_First->PerformLayout();
			this->statusStrip_position->ResumeLayout(false);
			this->statusStrip_position->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Set_Who_First_Enter(System::Object^  sender, System::EventArgs^  e) 
	{
		// 手殘按到
	}
	

	private: System::Void button_setting_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		// 當按下Setting後
		Setting^ new_window = gcnew Setting();
		this->Hide();	// Let the setting window upper
		new_window->ShowDialog();
		this->Show();
		radioButton_Player1->Text = L"玩家1 : " + Setting::get_Player1_name() + L"\n\t使用 -> " + Setting::get_Player1_O_or_X();
		radioButton_Player2->Text = L"玩家2 : " + Setting::get_Player2_name() + L"\n\t使用 -> " + Setting::get_Player2_O_or_X();
		button_start_stop->Enabled = true;
		radioButton_Player1->Enabled = true;
		radioButton_Player2->Enabled = true;
	}

	private: System::Void Timer_text_Click(System::Object^ sender, System::EventArgs^ e) {
		// 手殘按到
	}
	private: System::Void timer_count_Tick(System::Object^ sender, System::EventArgs^ e) 
	{
		sec++;
		if (sec == 60)
		{
			min++;
			sec = 0;
		}
		System:String^ Time = Convert::ToString(min) + " : " + Convert::ToString(sec);
		Timer->Text = Time;
	}
	private: System::Void button_start_stop_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (Gaming_mode == false)	// setting mode to gameing mode
		{
			Gaming_mode = true;
			button_setting->Enabled = false;
			button_start_stop->Text = "Stop";
			this->timer_count->Enabled = true;
			count = min = sec = 0;
			Change_Block_Mode();
			Clear_Block();
			if (First == Setting::get_Player1_name() && Setting::get_Player1_O_or_X() == "O")	symbol = 0;
			else if (First == Setting::get_Player1_name() && Setting::get_Player1_O_or_X() == "X")	symbol = 1;
			else if (First == Setting::get_Player2_name() && Setting::get_Player2_O_or_X() == "X")	symbol = 1;
			else if (First == Setting::get_Player2_name() && Setting::get_Player2_O_or_X() == "O")	symbol = 0;
			if (radioButton_Player1->Checked == 1)	whos_turn = 0;
			else whos_turn = 1;
			toolStripStatusLabel_whos_turn->Text = whos_turn ? L"玩家2" : L"玩家1";
			Set_Who_First->Enabled = false;
		}
		else if (Gaming_mode == true)	// gameing mode to setting mode
		{
			Gaming_mode = false;
			button_setting->Enabled = true;
			Set_Who_First->Enabled = true;
			button_start_stop->Text = "Start";
			this->timer_count->Enabled = false;
			Change_Block_Mode();
			Clear_Block();
			min = sec = 0;
		}
	}
	private:void Change_Block_Mode()
	{
		block1_1->Enabled = Gaming_mode & 1;
		block1_2->Enabled = Gaming_mode & 1;
		block1_3->Enabled = Gaming_mode & 1;
		block2_1->Enabled = Gaming_mode & 1;
		block2_2->Enabled = Gaming_mode & 1;
		block2_3->Enabled = Gaming_mode & 1;
		block3_1->Enabled = Gaming_mode & 1;
		block3_2->Enabled = Gaming_mode & 1;
		block3_3->Enabled = Gaming_mode & 1;
	}
	private: void Clear_Block()
	{
		block1_1->Text = "";
		block1_2->Text = "";
		block1_3->Text = "";
		block2_1->Text = "";
		block2_2->Text = "";
		block2_3->Text = "";
		block3_1->Text = "";
		block3_2->Text = "";
		block3_3->Text = "";
	}
	private: System::Void block_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
	{
		Button^ which_button = safe_cast<Button^>(sender);
		if (which_button == block1_1)	toolStripStatusLabel_Which_block->Text = "(1, 1)";
		else if(which_button == block1_2)	toolStripStatusLabel_Which_block->Text = "(1, 2)";
		else if (which_button == block1_3)	toolStripStatusLabel_Which_block->Text = "(1, 3)";
		else if (which_button == block2_1)	toolStripStatusLabel_Which_block->Text = "(2, 1)";
		else if (which_button == block2_2)	toolStripStatusLabel_Which_block->Text = "(2, 2)";
		else if (which_button == block2_3)	toolStripStatusLabel_Which_block->Text = "(2, 3)";
		else if (which_button == block3_1)	toolStripStatusLabel_Which_block->Text = "(3, 1)";
		else if (which_button == block3_2)	toolStripStatusLabel_Which_block->Text = "(3, 2)";
		else if (which_button == block3_3)	toolStripStatusLabel_Which_block->Text = "(3, 3)";
	}
	private: bool Win_or_lose()
	{
		int result = -1;

		if (block1_1->Text == "X" && block1_2->Text == "X" && block1_3->Text == "X")	result = 0;
		else if (block2_1->Text == "X" && block2_2->Text == "X" && block2_3->Text == "X") result = 0;
		else if (block3_1->Text == "X" && block3_2->Text == "X" && block3_3->Text == "X") result = 0;
		else if (block1_1->Text == "X" && block2_1->Text == "X" && block3_1->Text == "X") result = 0;
		else if (block1_2->Text == "X" && block2_2->Text == "X" && block3_2->Text == "X") result = 0;
		else if (block1_3->Text == "X" && block2_3->Text == "X" && block3_3->Text == "X") result = 0;
		else if (block1_1->Text == "X" && block2_2->Text == "X" && block3_3->Text == "X") result = 0;
		else if (block1_3->Text == "X" && block2_2->Text == "X" && block3_1->Text == "X") result = 0;
		else if (block1_1->Text == "O" && block1_2->Text == "O" && block1_3->Text == "O") result = 1;
		else if (block2_1->Text == "O" && block2_2->Text == "O" && block2_3->Text == "O") result = 1;
		else if (block3_1->Text == "O" && block3_2->Text == "O" && block3_3->Text == "O") result = 1;
		else if (block1_1->Text == "O" && block2_1->Text == "O" && block3_1->Text == "O") result = 1;
		else if (block1_2->Text == "O" && block2_2->Text == "O" && block3_2->Text == "O") result = 1;
		else if (block1_3->Text == "O" && block2_3->Text == "O" && block3_3->Text == "O") result = 1;
		else if (block1_1->Text == "O" && block2_2->Text == "O" && block3_3->Text == "O") result = 1;
		else if (block1_3->Text == "O" && block2_2->Text == "O" && block3_1->Text == "O") result = 1;
		if (Setting::get_Player1_O_or_X() == "X" && result == 0)
		{
			winner = Setting::get_Player1_name();
			return 1;
		}
		else if (Setting::get_Player1_O_or_X() == "O" && result == 1)
		{
			winner = Setting::get_Player1_name();
			return 1;
		}
		else if (Setting::get_Player2_O_or_X() == "X" && result == 0)
		{
			winner = Setting::get_Player2_name();
			return 1;
		}
		else if (Setting::get_Player2_O_or_X() == "O" && result == 1)
		{
			winner = Setting::get_Player2_name();
			return 1;
		}
		return 0;
	}
	private: bool Tie_or_not()
	{
		return (Win_or_lose() == 0 && count == 9) ? 1 : 0;
	}


	private: System::Void First_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		if (radioButton_Player1->Checked == 1)	First = Setting::get_Player1_name();
		else if (radioButton_Player2->Checked == 1) First = Setting::get_Player2_name();
	}
	private: System::Void block_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		Button^ which_button = safe_cast<Button^>(sender);

		if (which_button == block1_1)	block1_1->Text = (symbol ? "X" : "O");
		else if(which_button == block1_2)	block1_2->Text = (symbol ? "X" : "O");
		else if (which_button == block1_3)	block1_3->Text = (symbol ? "X" : "O");
		else if (which_button == block2_1)	block2_1->Text = (symbol ? "X" : "O");
		else if (which_button == block2_2)	block2_2->Text = (symbol ? "X" : "O");
		else if (which_button == block2_3)	block2_3->Text = (symbol ? "X" : "O");
		else if (which_button == block3_1)	block3_1->Text = (symbol ? "X" : "O");
		else if (which_button == block3_2)	block3_2->Text = (symbol ? "X" : "O");
		else if (which_button == block3_3)	block3_3->Text = (symbol ? "X" : "O");

		++count;
		symbol ^= 1;
		whos_turn ^= 1;
		if (Tie_or_not())
		{
			this->timer_count->Enabled = false;
			Result^ res = gcnew Result();
			res->ShowDialog();
			Clear();
		}
		if (Win_or_lose())
		{
			this->timer_count->Enabled = false;
			Result^ res = gcnew Result(winner, min, sec);
			res->ShowDialog();
			Clear();
		}
		toolStripStatusLabel_whos_turn->Text = whos_turn ? L"玩家2" : L"玩家1";
	}

	private: void Clear()
	{
		button_start_stop->Enabled = true;
		button_setting->Enabled = true;
		Set_Who_First->Enabled = true;
		button_start_stop->Text = "Start";
		Clear_Block();
		Gaming_mode = 0;
		Change_Block_Mode();
	}
};
}
