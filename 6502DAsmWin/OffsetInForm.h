#pragma once

namespace My6502DAsmWin {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// OffsetInForm の概要
	/// </summary>
	public ref class OffsetInForm : public System::Windows::Forms::Form
	{
	public:
		OffsetInForm(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~OffsetInForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnOK;
	protected:


	public: System::Windows::Forms::TextBox^  txtBoxOffsetIn;
	private: 
	protected: 

	private: System::Windows::Forms::Label^  label1;

	protected: 

	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnOK = (gcnew System::Windows::Forms::Button());
			this->txtBoxOffsetIn = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnOK
			// 
			this->btnOK->Location = System::Drawing::Point(62, 119);
			this->btnOK->Margin = System::Windows::Forms::Padding(2);
			this->btnOK->Name = L"btnOK";
			this->btnOK->Size = System::Drawing::Size(102, 29);
			this->btnOK->TabIndex = 1;
			this->btnOK->Text = L"OK";
			this->btnOK->UseVisualStyleBackColor = true;
			this->btnOK->Click += gcnew System::EventHandler(this, &OffsetInForm::btnOK_Click);
			// 
			// txtBoxOffsetIn
			// 
			this->txtBoxOffsetIn->Location = System::Drawing::Point(45, 82);
			this->txtBoxOffsetIn->Margin = System::Windows::Forms::Padding(2);
			this->txtBoxOffsetIn->Name = L"txtBoxOffsetIn";
			this->txtBoxOffsetIn->Size = System::Drawing::Size(139, 19);
			this->txtBoxOffsetIn->TabIndex = 0;
			this->txtBoxOffsetIn->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &OffsetInForm::txtBoxOffsetIn_KeyDown);
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(9, 32);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(214, 30);
			this->label1->TabIndex = 2;
			this->label1->Text = L"オフセットアドレス（逆アセンブル開始アドレス）を16進数で入力してください";
			// 
			// OffsetInForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(223, 164);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtBoxOffsetIn);
			this->Controls->Add(this->btnOK);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"OffsetInForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"オフセットアドレス入力";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void btnOK_Click(System::Object^ sender, System::EventArgs^ e) {
				this->Close();
			}

	private: System::Void txtBoxOffsetIn_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				if (e->KeyCode == Keys::Enter)
					this->Close();
			}
};
}
