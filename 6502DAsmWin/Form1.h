#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
#include "R65C02dopcode.h"
#include "HelpForm.h"
#include "OffsetInForm.h"
#include "SkipAreaInForm.h"

struct {
	char mnemonic[5];	/* ニーモニック */
	int oplen;			/* オペコード長 */
	int optype;			/* タイプ */
} ope;

typedef struct {
	char Label[32];
	unsigned int adr;
} sLblTbl;

sLblTbl LblTbl[2000];					/* ラベルテーブル構造 */
unsigned char dbuf[65536];				/* バイナリデータ格納用 */
unsigned int sttadr[100], endadr[100];	/* スキップ範囲のアドレス */
unsigned char oprstr[256];				/* FCCのオペランド文字列 */
char outbuf[256], outbuf2[256];				/* 出力文字列作成用 */

namespace My6502DAsmWin {

	using namespace System;
	using namespace System::IO;
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
	private: System::Windows::Forms::TabPage^ tabpage1;
	private: System::Windows::Forms::TabPage^ tabpage2;
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

	private:
		array< unsigned char >^ dbuf;			/* バイナリデータ格納用 */
		unsigned int dlen;						/* バイナリデータの長さ */
		unsigned int ofsadr = 0;				/* オフセットアドレス */
		unsigned int topadr = 0, btmadr = 0;	/* 逆アセンブル時のアドレス */
		bool f_Lnosave = false;					/* 未保存のAssembleファイルがあるか（あればtrue） */
		bool f_Anosave = false;					/* 未保存のListファイルがあるか（あればtrue） */
		bool inskip_s = false;			/* スキップするアドレス範囲か（単一アドレスの場合） */
		bool inskip_m = false;			/* スキップするアドレス範囲か（連続アドレスの場合）*/
		int skpct = 0;					/* スキップするアドレス範囲数 */
		unsigned int adrct = 0;			/* アドレスカウンタ */
		unsigned char opcode;					/* オペコード */
		unsigned char operand1, operand2;		/* オペランド(2bytes) */
		int lblct = 0;							/* ラベルテーブルカウンタ */
		int linect = 0;							/* 行カウンタ */

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
			this->tabpage1 = (gcnew System::Windows::Forms::TabPage());
			this->txtBoxOutList = (gcnew System::Windows::Forms::TextBox());
			this->tabpage2 = (gcnew System::Windows::Forms::TabPage());
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
			this->tabpage1->SuspendLayout();
			this->tabpage2->SuspendLayout();
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
			this->開くOToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->開くOToolStripMenuItem->Text = L"開く(&O)";
			this->開くOToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::開くOToolStripMenuItem1_Click);
			// 
			// 保存SToolStripMenuItem
			// 
			this->保存SToolStripMenuItem->Name = L"保存SToolStripMenuItem";
			this->保存SToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->保存SToolStripMenuItem->Text = L"保存(&S)";
			this->保存SToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::保存SToolStripMenuItem_Click);
			// 
			// 終了XToolStripMenuItem
			// 
			this->終了XToolStripMenuItem->Name = L"終了XToolStripMenuItem";
			this->終了XToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->終了XToolStripMenuItem->Text = L"終了(&X)";
			this->終了XToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::終了ToolStripMenuItem_Click);
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
			this->オフセット指定OToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::オフセット指定OToolStripMenuItem_Click);
			// 
			// スキップ範囲指定SToolStripMenuItem
			// 
			this->スキップ範囲指定SToolStripMenuItem->Name = L"スキップ範囲指定SToolStripMenuItem";
			this->スキップ範囲指定SToolStripMenuItem->Size = System::Drawing::Size(171, 22);
			this->スキップ範囲指定SToolStripMenuItem->Text = L"スキップ範囲指定(&S)";
			this->スキップ範囲指定SToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::スキップ範囲指定SToolStripMenuItem_Click);
			// 
			// lIST表示クリアCToolStripMenuItem
			// 
			this->lIST表示クリアCToolStripMenuItem->Name = L"lIST表示クリアCToolStripMenuItem";
			this->lIST表示クリアCToolStripMenuItem->Size = System::Drawing::Size(171, 22);
			this->lIST表示クリアCToolStripMenuItem->Text = L"LIST表示クリア(&C)";
			this->lIST表示クリアCToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::lIST表示クリアCToolStripMenuItem_Click);
			// 
			// 逆アセンブル実行EToolStripMenuItem
			// 
			this->逆アセンブル実行EToolStripMenuItem->Name = L"逆アセンブル実行EToolStripMenuItem";
			this->逆アセンブル実行EToolStripMenuItem->Size = System::Drawing::Size(116, 20);
			this->逆アセンブル実行EToolStripMenuItem->Text = L"逆アセンブル実行(&E)";
			this->逆アセンブル実行EToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::逆アセンブル実行EToolStripMenuItem_Click);
			// 
			// aboutAToolStripMenuItem
			// 
			this->aboutAToolStripMenuItem->Name = L"aboutAToolStripMenuItem";
			this->aboutAToolStripMenuItem->Size = System::Drawing::Size(68, 20);
			this->aboutAToolStripMenuItem->Text = L"About(&A)";
			this->aboutAToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::aboutAToolStripMenuItem_Click);
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
			this->tabControl1->Controls->Add(this->tabpage1);
			this->tabControl1->Controls->Add(this->tabpage2);
			this->tabControl1->Location = System::Drawing::Point(0, 50);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(600, 370);
			this->tabControl1->TabIndex = 2;
			// 
			// tabpage1
			// 
			this->tabpage1->Controls->Add(this->txtBoxOutList);
			this->tabpage1->Location = System::Drawing::Point(4, 22);
			this->tabpage1->Name = L"tabpage1";
			this->tabpage1->Padding = System::Windows::Forms::Padding(3);
			this->tabpage1->Size = System::Drawing::Size(592, 344);
			this->tabpage1->TabIndex = 0;
			this->tabpage1->Text = L"Listリスト";
			this->tabpage1->UseVisualStyleBackColor = true;
			// 
			// txtBoxOutList
			// 
			this->txtBoxOutList->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtBoxOutList->Location = System::Drawing::Point(3, 3);
			this->txtBoxOutList->Multiline = true;
			this->txtBoxOutList->Name = L"txtBoxOutList";
			this->txtBoxOutList->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtBoxOutList->Size = System::Drawing::Size(586, 338);
			this->txtBoxOutList->TabIndex = 0;
			// 
			// tabpage2
			// 
			this->tabpage2->Controls->Add(this->txtBoxOutAsm);
			this->tabpage2->Location = System::Drawing::Point(4, 22);
			this->tabpage2->Name = L"tabpage2";
			this->tabpage2->Padding = System::Windows::Forms::Padding(3);
			this->tabpage2->Size = System::Drawing::Size(592, 344);
			this->tabpage2->TabIndex = 1;
			this->tabpage2->Text = L"Assemblerリスト";
			this->tabpage2->UseVisualStyleBackColor = true;
			// 
			// txtBoxOutAsm
			// 
			this->txtBoxOutAsm->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtBoxOutAsm->Location = System::Drawing::Point(3, 3);
			this->txtBoxOutAsm->Multiline = true;
			this->txtBoxOutAsm->Name = L"txtBoxOutAsm";
			this->txtBoxOutAsm->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtBoxOutAsm->Size = System::Drawing::Size(586, 338);
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
			this->txtBoxFileName->AllowDrop = true;
			this->txtBoxFileName->Location = System::Drawing::Point(89, 25);
			this->txtBoxFileName->Name = L"txtBoxFileName";
			this->txtBoxFileName->Size = System::Drawing::Size(503, 19);
			this->txtBoxFileName->TabIndex = 4;
			this->txtBoxFileName->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &Form1::txtBoxFileName_DragDrop);
			this->txtBoxFileName->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &Form1::txtBoxFileName_DragEnter);
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
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Cross DisAssembler for 6502  V er 1.0";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabpage1->ResumeLayout(false);
			this->tabpage1->PerformLayout();
			this->tabpage2->ResumeLayout(false);
			this->tabpage2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		f_Lnosave = false;	/* 未保存のListファイルはない */
		f_Anosave = false;	/* 未保存のAssembleファイルはない */
		dbuf = gcnew array< unsigned char >(65536);
	}
	private: System::Void txtBoxFileName_DragDrop(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e) {
		toolStripStatusLabel1->Text = "";
		if (e->Data->GetDataPresent(DataFormats::FileDrop)) {
			if (e->Effect == DragDropEffects::Copy) {
				cli::array<System::String^>^ filename = (cli::array<System::String^>^)(e->Data->GetData(DataFormats::FileDrop));
				txtBoxFileName->Text = filename[0];
				LoadFile();
				ofsadr = 0;
				// 表示エリアの再表示
				txtBoxSttAdr->Text = "$" + topadr.ToString("X4");
				txtBoxOfsAdr->Text = "$" + ofsadr.ToString("X4");
				txtBoxOutList->Clear();
				txtBoxOutAsm->Clear();
			}
		}
	}
	private: System::Void txtBoxFileName_DragEnter(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e) {
		cli::array<System::String^>^ fmts = e->Data->GetFormats();
		if (e->Data->GetDataPresent(DataFormats::FileDrop, false)) {
			e->Effect = DragDropEffects::Copy;
		}
		else {
			e->Effect = DragDropEffects::None;
		}
	}
	private: System::Void 開くOToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
		statusStripClear();
		LoadFileName();
		LoadFile();
		ofsadr = 0;
		// 表示エリアの再表示
		txtBoxSttAdr->Text = "$" + topadr.ToString("X4");
		txtBoxOfsAdr->Text = "$" + ofsadr.ToString("X4");
		txtBoxOutList->Clear();
		txtBoxOutAsm->Clear();
	}
	private: System::Void 保存SToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		statusStripClear();
		SaveFile();
	}
	private: System::Void 終了ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		statusStripClear();
		if (f_Lnosave || f_Anosave) {
			if (MessageBox::Show("未保存のファイルがあります．\nこのまま終了しても良いですか", "File Exist !",
				MessageBoxButtons::YesNo, MessageBoxIcon::Asterisk) == System::Windows::Forms::DialogResult::Yes) {
				exit(0);
			}
		}
		else
			exit(0);
	}
	private: System::Void オフセット指定OToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		statusStripClear();
		GetOffsetAdr();
	}
	private: System::Void スキップ範囲指定SToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		statusStripClear();
		ListSkipArea();
	}
	private: System::Void lIST表示クリアCToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		statusStripClear();
		txtBoxOutList->Clear();
	}
	private: System::Void 逆アセンブル実行EToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		SetSkipArea();
		Execute();
	}
	private: System::Void aboutAToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		statusStripClear();
		// HelpFormの新しいインスタンスを生成する
		HelpForm^ HelpForm1 = gcnew HelpForm();
		// Display the new Form
		HelpForm1->ShowDialog();
	}

//=============================================================================
//***** subroutine ***** 

void Execute()
{
	int bct = 0;		// バイナリデータのカウンタ 
	int ct = 0;			//
	int svofsadr;		//

	// 初期設定
	try {
		svofsadr = Convert::ToInt16(txtBoxOfsAdr->Text->Substring(1), 16) & 0xffff;
	}
	catch (Exception^) {
		svofsadr = 0;
	}
	txtBoxOutList->Clear();
	txtBoxOutAsm->Clear();
	// ファイル読み込み
	if (LoadFile() == -1)
		return;
	ofsadr = svofsadr;

	/* リスト表示用txtBoxを非表示に */
//	txtBoxOutList->Visible = false;
//	txtBoxOutAsm->Visible = false;
	/* リスト表示用txtBoxをクリア */
	f_Lnosave = false;	/* 未保存のデータはない */
	f_Anosave = false;	/* 未保存のデータはない */

	/*------------------------------------------------------*/
	/*		Pass 1 ラベルを登録								*/
	/*------------------------------------------------------*/

   ////////////////////////////////////////////////////////////
   /* for debug */
   DispData();
   ////////////////////////////////////////////////////////////

	adrct = topadr + ofsadr;	/* アドレスは先頭アドレスとオフセットアドレスの和 */
	bct = topadr;				/* 逆アセンブルするデータは先頭アドレスからに入っている */
	try {
		while ((unsigned int)bct <= btmadr) {
			/* アドレスのスキップ範囲のチェック */
//			CheckSkipArea();

			/* 1文字ずつ読みながら処理 */
			Pass1(&bct);

			/* 行カウンタ更新 */
			linect++;
//			toolStripProgressBar1->Value = bct - 1 - topadr;

		}
	}
	catch (Exception^) {
//		toolStripStatusLabel1->Text = "Disassemble (Pass 1) is failed!";
		statusStrip1->Update();
		return;
	}

////////////////////////////////////////////////////////////////////
DispLabel();
return;
////////////////////////////////////////////////////////////////////


	/*------------------------------------------------------*/
	/*		Pass 2											*/
	/*------------------------------------------------------*/
	Pass2();
	
}

/*==========================================================*/
/*		Pass 1 - Register Label								*/
/*==========================================================*/
int Pass1(int *binct)
{
	int i;
	unsigned int operand = 0;
	unsigned int absadr;		/* Relative命令の絶対アドレス */
	char s[256];				/* FCB,FCC化した複数バイト数の4倍必要 */

	opcode = dbuf[(*binct)++];
	if (inskip_s) {
		strcpy_s(ope.mnemonic, sizeof(ope.mnemonic), "FCB");		/* スキップしたコードはFCB扱い */
		ope.oplen = 1;						/* そのオペコード長は1 */
		ope.optype = 0;						/* タイプは0に */
	}
	else if (inskip_m) {
		(*binct)--;
		if (dbuf[(*binct)] >= 0x20 && dbuf[(*binct)] <= 0x7F) {
			strcpy_s(ope.mnemonic, sizeof(ope.mnemonic), "FCC");	/* スキップしたコードはFCC扱い */
			oprstr[0] = '/';
			for (i = 0; i < ope.oplen; i++) {
				oprstr[i + 1] = dbuf[(*binct)++];
			}
			oprstr[i + 1] = '/';
			oprstr[i + 2] = '\0';
		}
		else {
			strcpy_s(ope.mnemonic, sizeof(ope.mnemonic), "FCB");	/* スキップしたコードはFCB扱い */
			oprstr[0] = '\0';
			for (i = 0; i < ope.oplen; i++) {
				sprintf_s(s, sizeof(s), "$%02X,", dbuf[(*binct)++]);
				strcat_s((char*)oprstr, sizeof(oprstr), s);
			}
			oprstr[i * 4 - 1] = '\0';
		}
		ope.optype = 0;						/* タイプは0に */
	}
	else {					// no skip area
		/* ニーモニックテーブルからニーモニック,オペランド長,オペコードタイプを読み取る */
		strcpy_s(ope.mnemonic, sizeof(ope.mnemonic), OpcodeTbl[opcode].mnemonic);
		ope.oplen = OpcodeTbl[opcode].oplen;
		ope.optype = OpcodeTbl[opcode].optype;
	}
	
	/* オペランド長(ope.oplen-1)に従ってオペランドを読み込む */
	operand1 = 0;
	operand2 = 0;
	switch (ope.oplen) {
	case 0:
	case 1:
			break;
	case 2:
			operand1 = dbuf[(*binct)++];
			operand = operand1;
			break;
	case 3:
			operand1 = dbuf[(*binct)++];
			operand2 = dbuf[(*binct)++];
			operand = (operand2 * 0x100 + operand1) & 0xffff;
			break;
	}
	
	/* ラベル作成 */
	switch (ope.optype) {
	case  0: /* (no opcode)                                    oplen-1  */
	case  6: /*  6:Accumulator							 6:A		0	*/
	case  7: /*  7:Immediate							 7:#		1	*/
	case  8: /*  8:Implied								 8:i		0	*/
	case 10: /* 10:Stack								10:s 		0	*/
		break;
	case 11: /* 11:Zero page							11:zp 		1	*/
	case 12: /* 12:Zero page Indexed Indirect			12:(zp,x) 	1	*/
	case 13: /* 13:Zero page Indexed with X				13:zp,x 	1	*/
	case 14: /* 14:Zero page Indexed with Y				14:zp,y 	1	*/
	case 15: /* 15:Zero Page Indirect					15:(zp) 	1	*/
	case 16: /* 16:Zero Page Indirect Indexed with Y	16:(zp),y 	1	*/
			MakeLabel(operand & 0xff);
		break;
	case  1: /*  1:Absolute								 1:a		2	*/
	case  2: /*  2:Absolute Indexed Indirect			 2:(a,x)	2	*/
	case  3: /*  3:Absolute Indexed with X				 3:a,x		2	*/
	case  4: /*  4:Absolute Indexed with Y				 4:a,y		2	*/
	case  5: /*  5:Absolute Indirect					 5:(a)		2	*/
			MakeLabel(operand & 0xffff);
		break;
	case  9: /*  9:Program Counter Relative				 9:r		1	*/
			/* Relative命令かどうか */
			if (((opcode & 0x1f) == 0x10) || (opcode == 0x80)) {
				/* 絶対アドレスを求めて */
				absadr = adrct + operand + ope.oplen;
				if (operand >= 0x80)
					absadr -= 0x100;
				MakeLabel(absadr & 0xffff);
			}
			break;
	}

	/* アドレス更新 */
	if (ope.oplen == 0)
		adrct++;			/* 命令コードでなくてもカウントアップ */
	else
		adrct += ope.oplen;

	return 0;
}

/*==========================================================*/
/*		Pass 2									*/
/*==========================================================*/
int Pass2()
{
	return 0;
}

/*==========================================================*/
/*		Make Label											*/
/*==========================================================*/
void MakeLabel(unsigned int absadr)
{
	char lbuf[16];
	sLblTbl* lpt;
	
	/* ラベル作成 */
	sprintf_s(lbuf, "L_%04X\0", absadr & 0xffff);

	/* ラベルが登録済みかを調べ、登録済みならアドレスを更新してリターン */
	lpt = (sLblTbl*)bsearch(lbuf, LblTbl, lblct, sizeof(sLblTbl), cmp_str);
	if (lpt) {
		/* ラベルが登録済みならアドレスを更新してリターン */
		lpt->adr = absadr & 0xffff;
		return;
	}

	/* ラベルが未登録なら */
	/* とりあえず末尾に追加して */
	strcpy_s(LblTbl[lblct].Label, lbuf);
	LblTbl[lblct].adr = absadr & 0xffff;
	lblct++;

	/* qsortで並べ替える */
	qsort(LblTbl, lblct, sizeof(sLblTbl), cmp_str);

	return;
}

static int cmp_str(const void* p1, const void* p2)
{
	sLblTbl* cmp1 = (sLblTbl*)p1;
	sLblTbl* cmp2 = (sLblTbl*)p2;

	return _stricmp((const char*)(cmp1->Label), (const char*)(cmp2->Label));
}

/*==========================================================*/
/*		Get Load FileName									*/
/*==========================================================*/
int LoadFileName()
{
   txtBoxOutList->Clear();
   txtBoxOutAsm->Clear();
   this->Update();		// Form全体を再描画
   openFileDialog1->Title = "入力ファイル名";
   if (openFileDialog1->ShowDialog() != System::Windows::Forms::DialogResult::OK)
	   return -1;
   // ファイル名を表示
   txtBoxFileName->Text = openFileDialog1->FileName;
   return 0;
}

/*==========================================================*/
/*		Load Binary / Hex / S File							*/
/*==========================================================*/
int LoadFile()
{
   int result = -1;

   //ファイルの読み込み
   if (IO::Path::GetExtension(txtBoxFileName->Text)->ToUpper() == ".BIN") {
	   result = LoadBinFile(txtBoxFileName->Text);
   }
   else if (IO::Path::GetExtension(txtBoxFileName->Text)->ToUpper() == ".HEX") {
	   result = LoadHexFile(txtBoxFileName->Text);
   }
   else if (IO::Path::GetExtension(txtBoxFileName->Text)->ToUpper() == ".MOT"
	   || IO::Path::GetExtension(txtBoxFileName->Text)->ToUpper() == ".S") {
	   result = LoadSFile(txtBoxFileName->Text);
   }
   if (result != 0) {
	   if (MessageBox::Show("拡張子がBIN,HEX,MOT,Sのいずれでもありません．\nBINファイルとみなして良いですか．", "Confirm File type",
		   MessageBoxButtons::YesNo, MessageBoxIcon::Asterisk) == System::Windows::Forms::DialogResult::Yes) {
		   result = LoadBinFile(txtBoxFileName->Text);
	   }
	   else {
		   return -1;
	   }
   }
   //	// 表示エリアの再表示
   //	txtBoxSttAdr->Text = "$" + topadr.ToString("X4");
   //	txtBoxOfsAdr->Text = "$" + ofsadr.ToString("X4");
   return 0;
}

/*==========================================================*/
/*		Load Binary File									*/
/*==========================================================*/
int LoadBinFile(String^ FileName)
{
   //	int stadr = 0, edadr = 0;
   int n = 0;
   String^ EntryLineTmp = "";

   toolStripStatusLabel1->Text = "Binary file loading ...";
   statusStrip1->Update();		// statusStripを再描画

   //Load
   try {	//in System::IO
	   FileStream^ fs = gcnew FileStream(FileName, FileMode::Open);
	   BinaryReader^ br = gcnew BinaryReader(fs);
	   try {
		   cli::array< unsigned char >^ data = gcnew cli::array< unsigned char >((int)fs->Length);
		   //読み込み
		   while (n < fs->Length) {
			   data = br->ReadBytes(1);
			   dbuf[(n++) & 0xffff] = data[0];
		   }
	   }
	   finally {
		   br->Close();
		   fs->Close();
	   }
   }
   catch (Exception^) {
	   toolStripStatusLabel1->Text = "Binary file load failed!";
	   return -1;
   }
   dlen = n;
   if (dlen == 0) {
	   MessageBox::Show("正常なファイル形式ではないため，読み込めませんでした．\nファイルを確認してください．", "File error!",
		   MessageBoxButtons::OK, MessageBoxIcon::Error);
	   return -1;
   }
   topadr = 0;
   btmadr = n - 1;
   toolStripStatusLabel1->Text = "Binary file loaded. ( $" + n.ToString("X4") + "bytes, $"
	   + topadr.ToString("X4") + " - $" + btmadr.ToString("X4") + " )";
   statusStrip1->Update();

   return 0;
}

/*==========================================================*/
/*		Load Hex File										*/
/*==========================================================*/
int LoadHexFile(String^ FileName)
{
   String^ buf = "";
   String^ ss;
   String^ EntryLineTmp = "";
   char sc[5], hexdata[32];
   unsigned int len, adr, maxadr = 0;
   unsigned int stadr, edadr;
   int rtype, sum, csum;
   int rdlen, result = 0;
   int ct = 0;

   topadr = 0;
   btmadr = 0;
   toolStripStatusLabel1->Text = "Hex-format file loading ...";
   this->Update();		// Form全体を再描画

   //入力ストリームの設定
   try {
	   FileStream^ fs = gcnew FileStream(FileName, FileMode::Open);
	   StreamReader^ sr = gcnew StreamReader(fs, System::Text::Encoding::GetEncoding("ascii"));
	   rdlen = 0;
	   do {
		   csum = 0;
		   //一行読み込む
		   buf = sr->ReadLine();
		   //':'check
		   if (buf[0] != ':') {
			   toolStripStatusLabel1->Text = "File is no hex-format file!";
			   statusStrip1->Update();
			   result = -1;
			   break;
		   }

		   //Length check
		   sc[0] = (unsigned char)buf[1];
		   sc[1] = (unsigned char)buf[2];
		   sc[2] = '\0';
		   ss = gcnew String(sc);
		   try {
			   len = Convert::ToUInt16(ss, 16);
		   }
		   catch (Exception^) {
			   toolStripStatusLabel1->Text = "Read data length error!";
			   statusStrip1->Update();
			   result = -2;
			   break;
		   }
		   if (len > 0) {		// len=0 : end line
			   csum += len;
			   //Address check
			   sc[0] = (unsigned char)buf[3];
			   sc[1] = (unsigned char)buf[4];
			   sc[2] = (unsigned char)buf[5];
			   sc[3] = (unsigned char)buf[6];
			   sc[4] = '\0';
			   ss = gcnew String(sc);
			   try {
				   adr = Convert::ToUInt16(ss, 16);
				   //					if (adr < topadr)	/* adrの最小値を見つける */
				   //						topadr = adr;
				   if (ct == 0) {
					   stadr = adr;
					   topadr = adr;
				   }
			   }
			   catch (Exception^) {
				   toolStripStatusLabel1->Text = "Read address error!";
				   statusStrip1->Update();
				   result = -3;
				   break;
			   }
			   csum += ((adr >> 8) & 0xff) + (adr & 0xff);
			   //Record Type check
			   sc[0] = (unsigned char)buf[7];
			   sc[1] = (unsigned char)buf[8];
			   sc[2] = '\0';
			   ss = gcnew String(sc);
			   try {
				   rtype = Convert::ToUInt16(ss, 16);
			   }
			   catch (Exception^) {
				   toolStripStatusLabel1->Text = "Read record type error!";
				   statusStrip1->Update();
				   result = -4;
				   break;
			   }
			   if (rtype == 02) {		//02:Extended record
				   MessageBox::Show("拡張コードが含まれています．\nこのプログラムは拡張アドレスに対応していません．", "Invalid record warning",
					   MessageBoxButtons::OK, MessageBoxIcon::Warning);
				   sr->Close();
				   return -5;
			   }
			   if (rtype == 03) {		//03:Entry address record
				   EntryLineTmp = gcnew String(buf);
				   result = 0;
			   }
			   if (rtype < 0 || rtype > 3) {
				   MessageBox::Show("第" + ct.ToString() + "行のレコードタイプが正しくありません．\nファイルを確認してください．", "Record type error!",
					   MessageBoxButtons::OK, MessageBoxIcon::Error);
				   toolStripStatusLabel1->Text = "Invalid record type error!";
				   sr->Close();
				   return -6;
			   }
			   csum += rtype;
			   //data read
			   if (rtype == 0) {		//00:data record
				   for (unsigned int i = 0; i < len; i++) {
					   sc[0] = (unsigned char)buf[9 + i * 2];
					   sc[1] = (unsigned char)buf[10 + i * 2];
					   sc[2] = '\0';
					   ss = gcnew String(sc);
					   try {
						   hexdata[i] = (unsigned char)Convert::ToUInt16(ss, 16);
					   }
					   catch (Exception^) {
						   toolStripStatusLabel1->Text = "Read data error!";
						   statusStrip1->Update();
						   result = -7;
						   break;
					   }
					   csum += hexdata[i];
				   }
				   rdlen += len;
				   if (btmadr < adr + len)	/* 最終アドレスの最大値を見つける */
					   btmadr = adr + len;
			   }
			   csum = (~(csum & 0xff) + 1) & 0xff;
			   //Check Sum check
			   sc[0] = (unsigned char)buf[9 + (len) * 2];
			   sc[1] = (unsigned char)buf[10 + (len) * 2];
			   sc[2] = '\0';
			   String^ ss = gcnew String(sc);
			   try {
				   sum = Convert::ToUInt16(ss, 16);
			   }
			   catch (Exception^) {
				   toolStripStatusLabel1->Text = "Read check sum error!";
				   statusStrip1->Update();
				   result = -8;
				   break;
			   }
			   //Check Sum compare
			   if ((sum != csum)) {
				   if (MessageBox::Show("第" + (ct + 1).ToString() + "行のチェックサムは誤っています．\nこのまま読み続けますか？", "Check sum error!",
					   MessageBoxButtons::YesNo, MessageBoxIcon::Question) != System::Windows::Forms::DialogResult::Yes) {
					   toolStripStatusLabel1->Text = "Invalid check sum error!";
					   sr->Close();
					   return -9;
				   }
				   result = 0;
			   }
			   //data set with offset
			   //Adr,Adr+1, ..., Adr+(len-1) <- data
			   for (unsigned int i = 0; i < len; i++) {
				   dbuf[(adr + i) & 0xffff] = hexdata[i] & 0xff;
			   }
			   //Size check
			   if (maxadr < (adr + len)) {
				   maxadr = adr + len - 1;
			   }
			   if (edadr < maxadr)
				   edadr = maxadr;
			   else if (stadr > adr)
				   stadr = adr;
			   ct++;
		   }
	   } while (sr->Peek() != -1);
	   sr->Close();
	   dlen = rdlen;
   }
   catch (Exception^) {
	   MessageBox::Show("ファイルが存在しないか，あるいはファイル形式が違います．\nファイルを確認してください．", "File error !",
		   MessageBoxButtons::OK, MessageBoxIcon::Error);
	   return -1;
   }
   if (dlen != 0) {
   }
   else {
	   MessageBox::Show("正常なファイル形式ではないため，読み込めませんでした．\nファイルを確認してください．", "File error !",
		   MessageBoxButtons::OK, MessageBoxIcon::Error);
	   return -1;
   }
   toolStripStatusLabel1->Text = "Hex-format file loaded. ( Size = $" + rdlen.ToString("X4") + "bytes, $"
	   + topadr.ToString("X4") + " - $" + btmadr.ToString("X4") + " )";
   statusStrip1->Update();
   if (result != 0)
	   return -1;
   return 0;
}

/*==========================================================*/
/*		Load Motorola S File								*/
/*==========================================================*/
int LoadSFile(String^ FileName)
{
   String^ buf;
   String^ ss;
   String^ HeaderLineTmp = "";
   String^ EntryLineTmp = "";
   char sc[5], sdata[255];
   unsigned int len, adr, maxadr = 0;
   unsigned int stadr, edadr;
   int rtype, sum, csum;
   int rdlen, result = 0;
   int ct = 0;

   topadr = 0;
   btmadr = 0;
   toolStripStatusLabel1->Text = "S-format file loading ...";
   this->Update();		// Form全体を再描画

   //入力ストリームの設定
   try {
	   FileStream^ fs = gcnew FileStream(FileName, FileMode::Open);
	   StreamReader^ sr = gcnew StreamReader(fs, System::Text::Encoding::GetEncoding("ascii"));
	   rdlen = 0;
	   do {
		   csum = 0;
		   //一行読み込む
		   buf = sr->ReadLine();
		   //'S'check
		   if (buf[0] != 'S') {
			   toolStripStatusLabel1->Text = "File is no S-format file!";
			   statusStrip1->Update();
			   result = -1;
			   break;
		   }
		   //Record Type check
		   sc[0] = (unsigned char)buf[1];
		   sc[1] = '\0';
		   ss = gcnew String(sc);
		   try {
			   rtype = Convert::ToUInt16(ss, 16);
		   }
		   catch (Exception^) {
			   toolStripStatusLabel1->Text = "Read record type error!";
			   statusStrip1->Update();
			   result = -2;
			   break;
		   }
		   switch (rtype) {
		   case 0:		//Header
			   HeaderLineTmp = gcnew String(buf);
			   break;
		   case 1:		//2bytes load address
			   //Length check
			   sc[0] = (unsigned char)buf[2];
			   sc[1] = (unsigned char)buf[3];
			   sc[2] = '\0';
			   ss = gcnew String(sc);
			   try {
				   len = Convert::ToUInt16(ss, 16);	//include addres(2) and CSum(1)
			   }
			   catch (Exception^) {
				   toolStripStatusLabel1->Text = "Read data length error!";
				   statusStrip1->Update();
				   result = -3;
				   break;
			   }
			   csum = len;							//check sum start
			   if (len <= 3)						// without data
				   break;
			   //Address check
			   sc[0] = (unsigned char)buf[4];
			   sc[1] = (unsigned char)buf[5];
			   sc[2] = (unsigned char)buf[6];
			   sc[3] = (unsigned char)buf[7];
			   sc[4] = '\0';
			   ss = gcnew String(sc);
			   try {
				   adr = Convert::ToUInt16(ss, 16);
				   //					if (adr < topadr)	/* adrの最小値を見つける */
				   //						topadr = adr;
				   if (ct == 0) {
					   stadr = adr;
					   topadr = adr;
				   }
			   }
			   catch (Exception^) {
				   toolStripStatusLabel1->Text = "Read address error!";
				   statusStrip1->Update();
				   result = -4;
				   break;
			   }

			   csum += ((adr >> 8) & 0xff) + (adr & 0xff);
			   //data read
			   for (unsigned int i = 0; i < len - 3; i++) {
				   sc[0] = (unsigned char)buf[8 + i * 2];
				   sc[1] = (unsigned char)buf[9 + i * 2];
				   sc[2] = '\0';
				   ss = gcnew String(sc);
				   try {
					   sdata[i] = (unsigned char)Convert::ToUInt16(ss, 16);
				   }
				   catch (Exception^) {
					   toolStripStatusLabel1->Text = "Read data error!";
					   statusStrip1->Update();
					   result = -5;
					   break;
				   }
				   csum += sdata[i];
			   }
			   rdlen += len - 3;
			   if (btmadr < adr + len)	/* 最終アドレスの最大値を見つける */
				   btmadr = adr + len;
			   csum = (~(csum & 0xff) & 0xff);
			   //Check Sum check
			   sc[0] = (unsigned char)buf[8 + (len - 3) * 2];
			   sc[1] = (unsigned char)buf[9 + (len - 3) * 2];
			   sc[2] = '\0';
			   ss = gcnew String(sc);
			   try {
				   sum = Convert::ToUInt16(ss, 16);
			   }
			   catch (Exception^) {
				   toolStripStatusLabel1->Text = "Read check sum error!";
				   statusStrip1->Update();
				   result = -6;
				   break;
			   }
			   //Check Sum compare
			   if ((sum != csum)) {
				   if (MessageBox::Show("第" + ct.ToString() + "行のチェックサムは誤っています．\nこのまま読み続けますか？", "Check sum error!",
					   MessageBoxButtons::YesNo, MessageBoxIcon::Question) != System::Windows::Forms::DialogResult::Yes) {
					   toolStripStatusLabel1->Text = "Invalid check sum error!";
					   return -7;
				   }
				   result = 0;
			   }
			   //data set
			   //Adr,Adr+1, ..., Adr+(len-1) <- data
			   for (unsigned int i = 0; i < len - 3; i++) {
				   dbuf[(adr + i) & 0xffff] = sdata[i] & 0xff;
			   }
			   //Size check
			   if (maxadr < (adr + len - 3)) {
				   maxadr = adr + len - 3;
			   }
			   if (edadr < maxadr)
				   edadr = maxadr;
			   else if (stadr > adr)
				   stadr = adr;
			   break;
		   case 2:	//3,4bytes load address
		   case 3:
			   MessageBox::Show("３,４バイトアドレスには対応していません．\nファイルを確認してください．", "Invalid record error !",
				   MessageBoxButtons::OK, MessageBoxIcon::Error);
			   return -8;
			   break;
		   case 7:	//4,3,2bytes entry address
		   case 8:
		   case 9:
			   EntryLineTmp = gcnew String(buf);
			   break;
		   default:
			   MessageBox::Show("Sフォーマットファイルではありません．\nファイルを確認してください．", "File format error !",
				   MessageBoxButtons::OK, MessageBoxIcon::Error);
			   return -9;
		   }
		   ct++;
	   } while (sr->Peek() != -1);
	   sr->Close();
	   dlen = rdlen;
	   if (dlen == 0) {
		   MessageBox::Show("正常なファイル形式ではないため，読み込めませんでした．\nファイルを確認してください．", "File error !",
			   MessageBoxButtons::OK, MessageBoxIcon::Error);
		   return -10;
	   }

   }
   catch (Exception^) {
	   MessageBox::Show("ファイルが存在しないか，あるいはファイル形式が違います．\nファイルを確認してください．", "File error !",
		   MessageBoxButtons::OK, MessageBoxIcon::Error);
	   return -10;
   }
   toolStripStatusLabel1->Text = "S-format file loaded. ( $" + rdlen.ToString("X4") + "bytes, $"
	   + topadr.ToString("X4") + " - $" + btmadr.ToString("X4") + " )";
   if (result != 0)
	   return -1;
   return 0;
}

/*==========================================================*/
/*		Save File										*/
/*==========================================================*/
int SaveFile()
{
   return 0;
}

/*==========================================================*/
/*		Save List File										*/
/*==========================================================*/
int SaveListFile(void)
{
   return 0;
}

/*==========================================================*/
/*		Save Asm File										*/
/*==========================================================*/
int SaveAsmFile(void)
{
   return 0;
}

/*==========================================================*/
/*		Get Offset Address									*/
/*==========================================================*/
void GetOffsetAdr(void)
{
	char* eptr;

	// OffsetInFormの新しいインスタンスを生成・表示
	OffsetInForm^ OffsetInForm1 = gcnew OffsetInForm();
	OffsetInForm1->ShowDialog();

	std::string ss = "0000";
	if (OffsetInForm1->txtBoxOffsetIn->Text == "")
		ofsadr = 0;
	else {
		MarshalString(OffsetInForm1->txtBoxOffsetIn->Text, ss);
		ofsadr = (unsigned int)strtol(ss.c_str(), &eptr, 16);
	}
	//入力結果をForm1のtextBoxにセット
	if (ss[0] == '-')	/* 負数のみ負数表示で */
		txtBoxOfsAdr->Text = "-$" + (0x10000 - ofsadr).ToString("X4");
	else
		txtBoxOfsAdr->Text = "$" + ofsadr.ToString("X4");
	return;
}

/*==========================================================*/
/*		List Skip Area										*/
/*==========================================================*/
void ListSkipArea(void)
{
	char* p, * eptr;
	unsigned int sadr = 0, eadr = 0;
	char* context;

	// SkipAreaInFormの新しいインスタンスを生成・表示
	SkipAreaInForm^ SkipAreaInForm1 = gcnew SkipAreaInForm();
	SkipAreaInForm1->ShowDialog();

	/* Convert to string */
	std::string ss = "0000";
	MarshalString(SkipAreaInForm1->txtBoxSkipAreaIn->Text, ss);
	/* スタート、エンドアドレスを取得 */
	p = strtok_s((char*)ss.c_str(), "-", &context);
	if (p)
		sadr = (int)strtol(p, &eptr, 16);
	p = strtok_s(NULL, "-", &context);
	if (p)
		eadr = (int)strtol(p, &eptr, 16);
	else
		eadr = sadr;

	if (eadr - sadr >= 32) {
		if (MessageBox::Show("スキップ範囲が大きすぎます．\n32バイトに縮小して良いですか．", "Confirm skip area size",
			MessageBoxButtons::YesNo, MessageBoxIcon::Asterisk) == System::Windows::Forms::DialogResult::Yes) {
			eadr = sadr + 32 - 1;
		}
		else {
			return;
		}
	}

	/* リストボックスに追加 */
	lstBoxSkipArea->Items->Add("$" + sadr.ToString("X4") + " - $" + eadr.ToString("X4"));
	skpct++;
	return;
}

/*==========================================================*/
/*		Set Skip Area										*/
/*==========================================================*/
void SetSkipArea(void)
{
	int i;
	char* p, * eptr;
	std::string ss;
	char* context;

	/* 項目数を取得 */
	skpct = lstBoxSkipArea->Items->Count;
	/* 項目数分の配列を生成 */
	cli::array<String^>^ StrArray = gcnew cli::array<String^>(skpct);
	/* 全項目取得 */
	for (i = 0; i < skpct; i++) {
		StrArray[i] = lstBoxSkipArea->Items[i]->ToString();
	}
	/* アドレスに変換 */
	for (i = 0; i < skpct; i++) {
		/* 先頭文字($)を削除して */
		StrArray[i] = StrArray[i]->Replace("$", "");
		/* スペースも削除して */
		StrArray[i] = StrArray[i]->Replace(" ", "");
		/* stringに変換してから */
		ss = "000000000";
		MarshalString(StrArray[i], ss);
		/* スタート、エンドアドレスを取得 */
		p = strtok_s((char*)ss.c_str(), "-", &context);
		if (p)
			sttadr[i] = (int)strtol(p, &eptr, 16);
		p = strtok_s(NULL, "-", &context);
		if (p)
			endadr[i] = (int)strtol(p, &eptr, 16);
	}
	return;
}

/*==========================================================*/
/*		Check Skip Area										*/
/*==========================================================*/
void CheckSkipArea(void)
{
	int i;

	inskip_s = false;
	inskip_m = false;
	for (i = 0; i < skpct; i++) {
		if (adrct >= sttadr[i] && adrct <= endadr[i]) {
			if (sttadr[i] == endadr[i]) {
				inskip_s = true;
				ope.oplen = 1;
			}
			else {
				inskip_m = true;
				ope.oplen = endadr[i] - sttadr[i] + 1;
			}
		}
	}
}

/*==========================================================*/
/*		status bar clear									*/
/*==========================================================*/
void statusStripClear()
{
   toolStripStatusLabel1->Text = "";
   toolStripProgressBar1->Value = 0;
   statusStrip1->Update();		// statusStripを再描画
}

/*==========================================================*/
/*		Convert from String^ to string						*/
/*==========================================================*/
void MarshalString(String^ s, std::string& os)
{
	using namespace Runtime::InteropServices;
	const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}

//////////////////////////////////////////////////////////////
/* for debug */
void DispData(void)
{
   int dcnt = 0;
   int i = 0;
   char dstr[10];
   char outbuf[256];

   // とりあえず確認のために読み込んだデータを表示させてみる
   outbuf[0] = '\0';
   while (dcnt < dlen) {
	   sprintf_s(dstr, "%02X ", dbuf[topadr + dcnt + i++]);
	   strcat(outbuf, dstr);
	   if (i == 16 || dcnt + i >= dlen) {
		   strcat(outbuf, "\r\n");
		   txtBoxOutList->AppendText(gcnew String(outbuf));
		   outbuf[0] = '\0';
		   dcnt += i;
		   i = 0;
	   }
   }
}

void DispLabel(void)
{
	char outbuf[16];

	for (int i = 0; i < lblct; i++) {
		sprintf_s(outbuf, "%04X %s\r\n", LblTbl[i].adr & 0xffff, LblTbl[i].Label);
		txtBoxOutAsm->AppendText(gcnew String(outbuf));
	}
}

};
}

