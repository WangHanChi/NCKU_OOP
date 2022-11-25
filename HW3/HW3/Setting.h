#pragma once

namespace HW3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Setting 的摘要
	/// </summary>
	public ref class Setting : public System::Windows::Forms::Form
	{
	public:
		Setting(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~Setting()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label_Player1_Name;
	protected:
	private: System::Windows::Forms::Label^ label_Player2_Name;
	private: System::Windows::Forms::TextBox^ textBox_Player1;
	private: System::Windows::Forms::TextBox^ textBox_Player2;



	private: System::Windows::Forms::GroupBox^ groupBox_Who_O;
	private: System::Windows::Forms::RadioButton^ radioButton_Player2_O;
	private: System::Windows::Forms::RadioButton^ radioButton_Player1_O;
	private: System::Windows::Forms::Button^ button_back;
	private: System::Windows::Forms::Button^ button_reset;


	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Setting::typeid));
			this->label_Player1_Name = (gcnew System::Windows::Forms::Label());
			this->label_Player2_Name = (gcnew System::Windows::Forms::Label());
			this->textBox_Player1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Player2 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox_Who_O = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton_Player2_O = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_Player1_O = (gcnew System::Windows::Forms::RadioButton());
			this->button_back = (gcnew System::Windows::Forms::Button());
			this->button_reset = (gcnew System::Windows::Forms::Button());
			this->groupBox_Who_O->SuspendLayout();
			this->SuspendLayout();
			// 
			// label_Player1_Name
			// 
			this->label_Player1_Name->AutoSize = true;
			this->label_Player1_Name->Font = (gcnew System::Drawing::Font(L"新細明體", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_Player1_Name->Location = System::Drawing::Point(40, 46);
			this->label_Player1_Name->Name = L"label_Player1_Name";
			this->label_Player1_Name->Size = System::Drawing::Size(203, 21);
			this->label_Player1_Name->TabIndex = 0;
			this->label_Player1_Name->Text = L"請輸入玩家1的名字 : ";
			// 
			// label_Player2_Name
			// 
			this->label_Player2_Name->AutoSize = true;
			this->label_Player2_Name->Font = (gcnew System::Drawing::Font(L"新細明體", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_Player2_Name->Location = System::Drawing::Point(40, 110);
			this->label_Player2_Name->Name = L"label_Player2_Name";
			this->label_Player2_Name->Size = System::Drawing::Size(203, 21);
			this->label_Player2_Name->TabIndex = 1;
			this->label_Player2_Name->Text = L"請輸入玩家2的名字 : ";
			// 
			// textBox_Player1
			// 
			this->textBox_Player1->Font = (gcnew System::Drawing::Font(L"新細明體", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox_Player1->Location = System::Drawing::Point(249, 43);
			this->textBox_Player1->Name = L"textBox_Player1";
			this->textBox_Player1->Size = System::Drawing::Size(255, 33);
			this->textBox_Player1->TabIndex = 2;
			this->textBox_Player1->TextChanged += gcnew System::EventHandler(this, &Setting::textBox_Player1_TextChanged);
			// 
			// textBox_Player2
			// 
			this->textBox_Player2->Font = (gcnew System::Drawing::Font(L"新細明體", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox_Player2->Location = System::Drawing::Point(249, 107);
			this->textBox_Player2->Name = L"textBox_Player2";
			this->textBox_Player2->Size = System::Drawing::Size(255, 33);
			this->textBox_Player2->TabIndex = 3;
			this->textBox_Player2->TextChanged += gcnew System::EventHandler(this, &Setting::textBox_Player2_TextChanged);
			// 
			// groupBox_Who_O
			// 
			this->groupBox_Who_O->Controls->Add(this->radioButton_Player2_O);
			this->groupBox_Who_O->Controls->Add(this->radioButton_Player1_O);
			this->groupBox_Who_O->Font = (gcnew System::Drawing::Font(L"新細明體", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->groupBox_Who_O->Location = System::Drawing::Point(44, 179);
			this->groupBox_Who_O->Name = L"groupBox_Who_O";
			this->groupBox_Who_O->Size = System::Drawing::Size(414, 145);
			this->groupBox_Who_O->TabIndex = 5;
			this->groupBox_Who_O->TabStop = false;
			this->groupBox_Who_O->Text = L"誰要選圈\? (另外一個就是叉)";
			// 
			// radioButton_Player2_O
			// 
			this->radioButton_Player2_O->AutoSize = true;
			this->radioButton_Player2_O->Location = System::Drawing::Point(6, 94);
			this->radioButton_Player2_O->Name = L"radioButton_Player2_O";
			this->radioButton_Player2_O->Size = System::Drawing::Size(80, 25);
			this->radioButton_Player2_O->TabIndex = 1;
			this->radioButton_Player2_O->TabStop = true;
			this->radioButton_Player2_O->Text = L"玩家2";
			this->radioButton_Player2_O->UseVisualStyleBackColor = true;
			// 
			// radioButton_Player1_O
			// 
			this->radioButton_Player1_O->AutoSize = true;
			this->radioButton_Player1_O->Location = System::Drawing::Point(6, 43);
			this->radioButton_Player1_O->Name = L"radioButton_Player1_O";
			this->radioButton_Player1_O->Size = System::Drawing::Size(80, 25);
			this->radioButton_Player1_O->TabIndex = 0;
			this->radioButton_Player1_O->TabStop = true;
			this->radioButton_Player1_O->Text = L"玩家1";
			this->radioButton_Player1_O->UseVisualStyleBackColor = true;
			this->radioButton_Player1_O->CheckedChanged += gcnew System::EventHandler(this, &Setting::radioButton_Player1_O_CheckedChanged);
			// 
			// button_back
			// 
			this->button_back->Font = (gcnew System::Drawing::Font(L"新細明體", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button_back->Location = System::Drawing::Point(482, 179);
			this->button_back->Name = L"button_back";
			this->button_back->Size = System::Drawing::Size(119, 55);
			this->button_back->TabIndex = 6;
			this->button_back->Text = L"設定完成";
			this->button_back->UseVisualStyleBackColor = true;
			this->button_back->Click += gcnew System::EventHandler(this, &Setting::button_back_Click);
			// 
			// button_reset
			// 
			this->button_reset->Font = (gcnew System::Drawing::Font(L"新細明體", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button_reset->Location = System::Drawing::Point(482, 258);
			this->button_reset->Name = L"button_reset";
			this->button_reset->Size = System::Drawing::Size(119, 55);
			this->button_reset->TabIndex = 7;
			this->button_reset->Text = L"清除重設";
			this->button_reset->UseVisualStyleBackColor = true;
			this->button_reset->Click += gcnew System::EventHandler(this, &Setting::button_reset_Click);
			// 
			// Setting
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(613, 365);
			this->Controls->Add(this->button_reset);
			this->Controls->Add(this->button_back);
			this->Controls->Add(this->groupBox_Who_O);
			this->Controls->Add(this->textBox_Player2);
			this->Controls->Add(this->textBox_Player1);
			this->Controls->Add(this->label_Player2_Name);
			this->Controls->Add(this->label_Player1_Name);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Setting";
			this->Text = L"Setting";
			this->groupBox_Who_O->ResumeLayout(false);
			this->groupBox_Who_O->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		static System::String^ Player1_name;
		static System::String^ Player2_name;
		static System::String^ Player1_O_or_X;
		static System::String^ Player2_O_or_X;
		static System::String^ Who_First;
	public:
		static System::String^ get_Player1_name()
		{
			return Player1_name;
		}
		static System::String^ get_Player1_O_or_X()
		{
			return Player1_O_or_X;
		}
		static System::String^ get_Player2_name()
		{
			return Player2_name;
		}
		static System::String^ get_Player2_O_or_X()
		{
			return Player2_O_or_X;
		}
		static System::String^ get_Who_First()
		{
			return Who_First;
		}
	

	private: System::Void textBox_Player1_TextChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		TextBox^ name = safe_cast<TextBox^>(sender);	//因為sender是最原本的物件, 將它轉型才可以使用
		Player1_name = name->Text;	// 設定名字
		radioButton_Player1_O->Text = "Player1 : " + Player1_name;
	}
	private: System::Void textBox_Player2_TextChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		TextBox^ name = safe_cast<TextBox^>(sender);	//因為sender是最原本的物件, 將它轉型才可以使用
		Player2_name = name->Text;	// 設定名字
		radioButton_Player2_O->Text = "Player2 : " + Player2_name;
	}
	private: System::Void radioButton_Player1_First_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{// 手殘按到
	}

	private: System::Void radioButton_Player1_O_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		if (radioButton_Player1_O->Checked)
		{
			Player1_O_or_X = "O";
			Player2_O_or_X = "X";
		}
		else if (radioButton_Player2_O->Checked)
		{
			Player1_O_or_X = "X";
			Player2_O_or_X = "O";
		}
	}
	private: System::Void button_reset_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		textBox_Player1->Text = "";
		textBox_Player2->Text = "";
		radioButton_Player1_O->Text = L"玩家1";
		radioButton_Player2_O->Text = L"玩家2";
		Player1_name = "";
		Player2_name = "";
		Player1_O_or_X = "";
		Player2_O_or_X = "";
		Who_First = "";
		radioButton_Player1_O->Checked = false;
		radioButton_Player2_O->Checked = false;
	}
	private: System::Void button_back_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if ( textBox_Player1->Text == "" || textBox_Player2->Text == "" || Player1_name == "" || Player2_name == "")
		{
			MessageBox::Show("Please enter BOTH the name of Player1 and Player2!!", "NAME ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else if (Player1_name == Player2_name)
		{
			MessageBox::Show("The names cannot be the same", "NAME ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else if (radioButton_Player1_O->Checked == false && radioButton_Player2_O->Checked == false)
		{
			MessageBox::Show("Please check the one who will use O!!", "CHECK ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else	// 沒有錯誤, 就準備回到遊戲介面Tick_Tac_Toe.h
		{
			Setting::Close();
		}
	}
};
}
