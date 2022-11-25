#pragma once

namespace HW3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Result 的摘要
	/// </summary>
	public ref class Result : public System::Windows::Forms::Form
	{
	public:
		Result(void)
		{
			InitializeComponent();
			this->label_Result->Text = L"哎呀! 平手了呢!";
			pictureBox_tie->Visible = true;
		}
		Result(System::String^ win, int m, int s)
		{
			InitializeComponent();
			this->label_Result->Text = L"恭喜 " + win + L" 獲得勝利, \n總共用時 : " + m + L" 分 " + s + L" 秒";
			pictureBox_result->Visible = true;
		}
	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~Result()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label_Result;
	private: System::Windows::Forms::PictureBox^ pictureBox_result;
	private: System::Windows::Forms::PictureBox^ pictureBox_tie;

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Result::typeid));
			this->label_Result = (gcnew System::Windows::Forms::Label());
			this->pictureBox_result = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox_tie = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_result))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_tie))->BeginInit();
			this->SuspendLayout();
			// 
			// label_Result
			// 
			this->label_Result->AutoSize = true;
			this->label_Result->Font = (gcnew System::Drawing::Font(L"新細明體", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_Result->Location = System::Drawing::Point(31, 63);
			this->label_Result->Name = L"label_Result";
			this->label_Result->Size = System::Drawing::Size(83, 29);
			this->label_Result->TabIndex = 0;
			this->label_Result->Text = L"result:";
			// 
			// pictureBox_result
			// 
			this->pictureBox_result->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_result.Image")));
			this->pictureBox_result->Location = System::Drawing::Point(91, 162);
			this->pictureBox_result->Name = L"pictureBox_result";
			this->pictureBox_result->Size = System::Drawing::Size(243, 208);
			this->pictureBox_result->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox_result->TabIndex = 1;
			this->pictureBox_result->TabStop = false;
			this->pictureBox_result->Visible = false;
			// 
			// pictureBox_tie
			// 
			this->pictureBox_tie->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox_tie.Image")));
			this->pictureBox_tie->Location = System::Drawing::Point(91, 120);
			this->pictureBox_tie->Name = L"pictureBox_tie";
			this->pictureBox_tie->Size = System::Drawing::Size(243, 250);
			this->pictureBox_tie->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox_tie->TabIndex = 2;
			this->pictureBox_tie->TabStop = false;
			this->pictureBox_tie->Visible = false;
			// 
			// Result
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(452, 382);
			this->Controls->Add(this->pictureBox_tie);
			this->Controls->Add(this->pictureBox_result);
			this->Controls->Add(this->label_Result);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Result";
			this->Text = L"Result";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_result))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox_tie))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
