#pragma once

namespace My6502DAsmWin {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// SkipAreaInForm の概要
	/// </summary>
	public ref class SkipAreaInForm : public System::Windows::Forms::Form
	{
	public:
		SkipAreaInForm(void)
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
		~SkipAreaInForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnOK;
	protected:

	public: System::Windows::Forms::TextBox^  txtBoxSkipAreaIn;
	private: 
	protected: 

	private: System::Windows::Forms::Label^  label1;

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
			this->txtBoxSkipAreaIn = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnOK
			// 
			this->btnOK->Location = System::Drawing::Point(68, 124);
			this->btnOK->Margin = System::Windows::Forms::Padding(2);
			this->btnOK->Name = L"btnOK";
			this->btnOK->Size = System::Drawing::Size(102, 29);
			this->btnOK->TabIndex = 1;
			this->btnOK->Text = L"OK";
			this->btnOK->UseVisualStyleBackColor = true;
			this->btnOK->Click += gcnew System::EventHandler(this, &SkipAreaInForm::btnOK_Click);
			// 
			// txtBoxSkipAreaIn
			// 
			this->txtBoxSkipAreaIn->Location = System::Drawing::Point(49, 92);
			this->txtBoxSkipAreaIn->Margin = System::Windows::Forms::Padding(2);
			this->txtBoxSkipAreaIn->Name = L"txtBoxSkipAreaIn";
			this->txtBoxSkipAreaIn->Size = System::Drawing::Size(139, 19);
			this->txtBoxSkipAreaIn->TabIndex = 0;
			this->txtBoxSkipAreaIn->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &SkipAreaInForm::txtBoxSkipAreaIn_KeyDown);
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(20, 16);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(202, 65);
			this->label1->TabIndex = 2;
			this->label1->Text = L"逆アセンブルをスキップするアドレス範囲を\r\n16進数4桁で\r\n　0000         （単一アドレスの場合）\r\n　0000-0000 （範囲指定の場合）\r\nの"
				L"形式で入力して下さい";
			// 
			// SkipAreaInForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(237, 164);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtBoxSkipAreaIn);
			this->Controls->Add(this->btnOK);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"SkipAreaInForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"スキップ範囲アドレス入力";
			this->Load += gcnew System::EventHandler(this, &SkipAreaInForm::SkipAreaInForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void btnOK_Click(System::Object^ sender, System::EventArgs^ e) {
				this->Close();
			}
	private: System::Void txtBoxSkipAreaIn_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				if (e->KeyCode == Keys::Enter)
					this->Close();
			}
	private: System::Void SkipAreaInForm_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
};
}
