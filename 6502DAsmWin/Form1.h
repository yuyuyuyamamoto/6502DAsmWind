#pragma once

namespace My6502DAsmWin {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 の概要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ファイルFToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ 開くOToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ 保存SToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ 終了XToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ オプションOToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ オフセット指定OToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ スキップ範囲指定SToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ lIST表示クリアCToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ 逆アセンブル実行EToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutAToolStripMenuItem;
	private: System::Windows::Forms::StatusStrip^ statusStrip1;
	private: System::Windows::Forms::ToolStripProgressBar^ toolStripProgressBar1;
	private: System::Windows::Forms::ToolStripStatusLabel^ toolStripStatusLabel1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::TextBox^ txtBoxOutList;
	private: System::Windows::Forms::TextBox^ txtBoxOutAsm;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtBoxFileName;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txtBoxSttAdr;
	private: System::Windows::Forms::TextBox^ txtBoxOfsAdr;
	private: System::Windows::Forms::ListBox^ lstBoxSkipArea;


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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ファイルFToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->開くOToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->保存SToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->終了XToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->オプションOToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->オフセット指定OToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->スキップ範囲指定SToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lIST表示クリアCToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->逆アセンブル実行EToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutAToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripProgressBar1 = (gcnew System::Windows::Forms::ToolStripProgressBar());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->txtBoxOutList = (gcnew System::Windows::Forms::TextBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->txtBoxOutAsm = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtBoxFileName = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtBoxSttAdr = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxOfsAdr = (gcnew System::Windows::Forms::TextBox());
			this->lstBoxSkipArea = (gcnew System::Windows::Forms::ListBox());
			this->menuStrip1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->ファイルFToolStripMenuItem,
					this->オプションOToolStripMenuItem, this->逆アセンブル実行EToolStripMenuItem, this->aboutAToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(724, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ファイルFToolStripMenuItem
			// 
			this->ファイルFToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->開くOToolStripMenuItem,
					this->保存SToolStripMenuItem, this->終了XToolStripMenuItem
			});
			this->ファイルFToolStripMenuItem->Name = L"ファイルFToolStripMenuItem";
			this->ファイルFToolStripMenuItem->Size = System::Drawing::Size(67, 20);
			this->ファイルFToolStripMenuItem->Text = L"ファイル(&F)";
			// 
			// 開くOToolStripMenuItem
			// 
			this->開くOToolStripMenuItem->Name = L"開くOToolStripMenuItem";
			this->開くOToolStripMenuItem->Size = System::Drawing::Size(113, 22);
			this->開くOToolStripMenuItem->Text = L"開く(&O)";
			// 
			// 保存SToolStripMenuItem
			// 
			this->保存SToolStripMenuItem->Name = L"保存SToolStripMenuItem";
			this->保存SToolStripMenuItem->Size = System::Drawing::Size(113, 22);
			this->保存SToolStripMenuItem->Text = L"保存(&S)";
			// 
			// 終了XToolStripMenuItem
			// 
			this->終了XToolStripMenuItem->Name = L"終了XToolStripMenuItem";
			this->終了XToolStripMenuItem->Size = System::Drawing::Size(113, 22);
			this->終了XToolStripMenuItem->Text = L"終了(&X)";
			// 
			// オプションOToolStripMenuItem
			// 
			this->オプションOToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->オフセット指定OToolStripMenuItem,
					this->スキップ範囲指定SToolStripMenuItem, this->lIST表示クリアCToolStripMenuItem
			});
			this->オプションOToolStripMenuItem->Name = L"オプションOToolStripMenuItem";
			this->オプションOToolStripMenuItem->Size = System::Drawing::Size(80, 20);
			this->オプションOToolStripMenuItem->Text = L"オプション(&O)";
			// 
			// オフセット指定OToolStripMenuItem
			// 
			this->オフセット指定OToolStripMenuItem->Name = L"オフセット指定OToolStripMenuItem";
			this->オフセット指定OToolStripMenuItem->Size = System::Drawing::Size(171, 22);
			this->オフセット指定OToolStripMenuItem->Text = L"オフセット指定(&O)";
			// 
			// スキップ範囲指定SToolStripMenuItem
			// 
			this->スキップ範囲指定SToolStripMenuItem->Name = L"スキップ範囲指定SToolStripMenuItem";
			this->スキップ範囲指定SToolStripMenuItem->Size = System::Drawing::Size(171, 22);
			this->スキップ範囲指定SToolStripMenuItem->Text = L"スキップ範囲指定(&S)";
			// 
			// lIST表示クリアCToolStripMenuItem
			// 
			this->lIST表示クリアCToolStripMenuItem->Name = L"lIST表示クリアCToolStripMenuItem";
			this->lIST表示クリアCToolStripMenuItem->Size = System::Drawing::Size(171, 22);
			this->lIST表示クリアCToolStripMenuItem->Text = L"LIST表示クリア(&C)";
			// 
			// 逆アセンブル実行EToolStripMenuItem
			// 
			this->逆アセンブル実行EToolStripMenuItem->Name = L"逆アセンブル実行EToolStripMenuItem";
			this->逆アセンブル実行EToolStripMenuItem->Size = System::Drawing::Size(116, 20);
			this->逆アセンブル実行EToolStripMenuItem->Text = L"逆アセンブル実行(&E)";
			// 
			// aboutAToolStripMenuItem
			// 
			this->aboutAToolStripMenuItem->Name = L"aboutAToolStripMenuItem";
			this->aboutAToolStripMenuItem->Size = System::Drawing::Size(68, 20);
			this->aboutAToolStripMenuItem->Text = L"About(&A)";
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripProgressBar1,
					this->toolStripStatusLabel1
			});
			this->statusStrip1->Location = System::Drawing::Point(0, 419);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(724, 22);
			this->statusStrip1->TabIndex = 1;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripProgressBar1
			// 
			this->toolStripProgressBar1->Name = L"toolStripProgressBar1";
			this->toolStripProgressBar1->Size = System::Drawing::Size(120, 16);
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->AutoSize = false;
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(550, 17);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(0, 50);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(600, 370);
			this->tabControl1->TabIndex = 2;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->txtBoxOutList);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(592, 344);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Listリスト";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// txtBoxOutList
			// 
			this->txtBoxOutList->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtBoxOutList->Location = System::Drawing::Point(3, 3);
			this->txtBoxOutList->Name = L"txtBoxOutList";
			this->txtBoxOutList->Size = System::Drawing::Size(586, 19);
			this->txtBoxOutList->TabIndex = 2;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->txtBoxOutAsm);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(592, 344);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Assemblerリスト";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// txtBoxOutAsm
			// 
			this->txtBoxOutAsm->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtBoxOutAsm->Location = System::Drawing::Point(3, 3);
			this->txtBoxOutAsm->Name = L"txtBoxOutAsm";
			this->txtBoxOutAsm->Size = System::Drawing::Size(586, 19);
			this->txtBoxOutAsm->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(33, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 12);
			this->label1->TabIndex = 3;
			this->label1->Text = L"ファイル名";
			// 
			// txtBoxFileName
			// 
			this->txtBoxFileName->Location = System::Drawing::Point(89, 25);
			this->txtBoxFileName->Name = L"txtBoxFileName";
			this->txtBoxFileName->Size = System::Drawing::Size(503, 19);
			this->txtBoxFileName->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(616, 28);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(76, 12);
			this->label2->TabIndex = 5;
			this->label2->Text = L"スタートアドレス";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(616, 69);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(83, 12);
			this->label3->TabIndex = 6;
			this->label3->Text = L"オフセットアドレス";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(604, 115);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(101, 24);
			this->label4->TabIndex = 7;
			this->label4->Text = L"スキップアドレス範囲\r\n（削除は選択してD）";
			// 
			// txtBoxSttAdr
			// 
			this->txtBoxSttAdr->Location = System::Drawing::Point(616, 43);
			this->txtBoxSttAdr->Name = L"txtBoxSttAdr";
			this->txtBoxSttAdr->Size = System::Drawing::Size(76, 19);
			this->txtBoxSttAdr->TabIndex = 8;
			// 
			// txtBoxOfsAdr
			// 
			this->txtBoxOfsAdr->Location = System::Drawing::Point(616, 84);
			this->txtBoxOfsAdr->Name = L"txtBoxOfsAdr";
			this->txtBoxOfsAdr->Size = System::Drawing::Size(76, 19);
			this->txtBoxOfsAdr->TabIndex = 9;
			// 
			// lstBoxSkipArea
			// 
			this->lstBoxSkipArea->FormattingEnabled = true;
			this->lstBoxSkipArea->ItemHeight = 12;
			this->lstBoxSkipArea->Location = System::Drawing::Point(606, 142);
			this->lstBoxSkipArea->Name = L"lstBoxSkipArea";
			this->lstBoxSkipArea->Size = System::Drawing::Size(110, 244);
			this->lstBoxSkipArea->TabIndex = 10;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(724, 441);
			this->Controls->Add(this->lstBoxSkipArea);
			this->Controls->Add(this->txtBoxOfsAdr);
			this->Controls->Add(this->txtBoxSttAdr);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtBoxFileName);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Cross DisAssembler for 6502  V er 1.0";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}

