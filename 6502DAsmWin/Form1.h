#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
#include "HelpForm.h"
#include "OffsetInForm.h"
#include "SkipAreaInForm.h"

struct {
	char mnemonic[5];	/* �j�[���j�b�N */
	int oplen;			/* �I�y�R�[�h�� */
	int optype;			/* �^�C�v */
} ope;

typedef struct {
	char Label[32];
	unsigned int adr;
} sLblTbl;

sLblTbl LblTbl[2000];					/* ���x���e�[�u���\�� */
unsigned char dbuf[65536];				/* �o�C�i���f�[�^�i�[�p */
unsigned int sttadr[100], endadr[100];	/* �X�L�b�v�͈͂̃A�h���X */

namespace My6502DAsmWin {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 �̊T�v
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: �����ɃR���X�g���N�^�[ �R�[�h��ǉ����܂�
			//
		}

	protected:
		/// <summary>
		/// �g�p���̃��\�[�X�����ׂăN���[���A�b�v���܂��B
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ �t�@�C��FToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �J��OToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �ۑ�SToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �I��XToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �I�v�V����OToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �I�t�Z�b�g�w��OToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �X�L�b�v�͈͎w��SToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ lIST�\���N���ACToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �t�A�Z���u�����sEToolStripMenuItem;
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
		/// �K�v�ȃf�U�C�i�[�ϐ��ł��B
		/// </summary>
		System::ComponentModel::Container ^components;

	private:
		array< unsigned char >^ dbuf;			/* �o�C�i���f�[�^�i�[�p */
		unsigned int dlen;						/* �o�C�i���f�[�^�̒��� */
		unsigned int ofsadr = 0;				/* �I�t�Z�b�g�A�h���X */
		unsigned int topadr = 0, btmadr = 0;	/* �t�A�Z���u�����̃A�h���X */
		bool f_Lnosave = false;					/* ���ۑ���Assemble�t�@�C�������邩�i�����true�j */
		bool f_Anosave = false;					/* ���ۑ���List�t�@�C�������邩�i�����true�j */
		bool inskip_s = false;			/* �X�L�b�v����A�h���X�͈͂��i�P��A�h���X�̏ꍇ�j */
		bool inskip_m = false;			/* �X�L�b�v����A�h���X�͈͂��i�A���A�h���X�̏ꍇ�j*/
		int skpct = 0;					/* �X�L�b�v����A�h���X�͈͐� */
		unsigned int adrct = 0;			/* �A�h���X�J�E���^ */

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �f�U�C�i�[ �T�|�[�g�ɕK�v�ȃ��\�b�h�ł��B���̃��\�b�h�̓��e��
		/// �R�[�h �G�f�B�^�[�ŕύX���Ȃ��ł��������B
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->�t�@�C��FToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�J��OToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�ۑ�SToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�I��XToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�I�v�V����OToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�I�t�Z�b�g�w��OToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�X�L�b�v�͈͎w��SToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lIST�\���N���ACToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�t�A�Z���u�����sEToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
				this->�t�@�C��FToolStripMenuItem,
					this->�I�v�V����OToolStripMenuItem, this->�t�A�Z���u�����sEToolStripMenuItem, this->aboutAToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(724, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// �t�@�C��FToolStripMenuItem
			// 
			this->�t�@�C��FToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->�J��OToolStripMenuItem,
					this->�ۑ�SToolStripMenuItem, this->�I��XToolStripMenuItem
			});
			this->�t�@�C��FToolStripMenuItem->Name = L"�t�@�C��FToolStripMenuItem";
			this->�t�@�C��FToolStripMenuItem->Size = System::Drawing::Size(67, 20);
			this->�t�@�C��FToolStripMenuItem->Text = L"�t�@�C��(&F)";
			// 
			// �J��OToolStripMenuItem
			// 
			this->�J��OToolStripMenuItem->Name = L"�J��OToolStripMenuItem";
			this->�J��OToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->�J��OToolStripMenuItem->Text = L"�J��(&O)";
			this->�J��OToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�J��OToolStripMenuItem1_Click);
			// 
			// �ۑ�SToolStripMenuItem
			// 
			this->�ۑ�SToolStripMenuItem->Name = L"�ۑ�SToolStripMenuItem";
			this->�ۑ�SToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->�ۑ�SToolStripMenuItem->Text = L"�ۑ�(&S)";
			this->�ۑ�SToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�ۑ�SToolStripMenuItem_Click);
			// 
			// �I��XToolStripMenuItem
			// 
			this->�I��XToolStripMenuItem->Name = L"�I��XToolStripMenuItem";
			this->�I��XToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->�I��XToolStripMenuItem->Text = L"�I��(&X)";
			this->�I��XToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�I��ToolStripMenuItem_Click);
			// 
			// �I�v�V����OToolStripMenuItem
			// 
			this->�I�v�V����OToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->�I�t�Z�b�g�w��OToolStripMenuItem,
					this->�X�L�b�v�͈͎w��SToolStripMenuItem, this->lIST�\���N���ACToolStripMenuItem
			});
			this->�I�v�V����OToolStripMenuItem->Name = L"�I�v�V����OToolStripMenuItem";
			this->�I�v�V����OToolStripMenuItem->Size = System::Drawing::Size(80, 20);
			this->�I�v�V����OToolStripMenuItem->Text = L"�I�v�V����(&O)";
			// 
			// �I�t�Z�b�g�w��OToolStripMenuItem
			// 
			this->�I�t�Z�b�g�w��OToolStripMenuItem->Name = L"�I�t�Z�b�g�w��OToolStripMenuItem";
			this->�I�t�Z�b�g�w��OToolStripMenuItem->Size = System::Drawing::Size(171, 22);
			this->�I�t�Z�b�g�w��OToolStripMenuItem->Text = L"�I�t�Z�b�g�w��(&O)";
			this->�I�t�Z�b�g�w��OToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�I�t�Z�b�g�w��OToolStripMenuItem_Click);
			// 
			// �X�L�b�v�͈͎w��SToolStripMenuItem
			// 
			this->�X�L�b�v�͈͎w��SToolStripMenuItem->Name = L"�X�L�b�v�͈͎w��SToolStripMenuItem";
			this->�X�L�b�v�͈͎w��SToolStripMenuItem->Size = System::Drawing::Size(171, 22);
			this->�X�L�b�v�͈͎w��SToolStripMenuItem->Text = L"�X�L�b�v�͈͎w��(&S)";
			this->�X�L�b�v�͈͎w��SToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�X�L�b�v�͈͎w��SToolStripMenuItem_Click);
			// 
			// lIST�\���N���ACToolStripMenuItem
			// 
			this->lIST�\���N���ACToolStripMenuItem->Name = L"lIST�\���N���ACToolStripMenuItem";
			this->lIST�\���N���ACToolStripMenuItem->Size = System::Drawing::Size(171, 22);
			this->lIST�\���N���ACToolStripMenuItem->Text = L"LIST�\���N���A(&C)";
			this->lIST�\���N���ACToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::lIST�\���N���ACToolStripMenuItem_Click);
			// 
			// �t�A�Z���u�����sEToolStripMenuItem
			// 
			this->�t�A�Z���u�����sEToolStripMenuItem->Name = L"�t�A�Z���u�����sEToolStripMenuItem";
			this->�t�A�Z���u�����sEToolStripMenuItem->Size = System::Drawing::Size(116, 20);
			this->�t�A�Z���u�����sEToolStripMenuItem->Text = L"�t�A�Z���u�����s(&E)";
			this->�t�A�Z���u�����sEToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�t�A�Z���u�����sEToolStripMenuItem_Click);
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
			this->tabpage1->Text = L"List���X�g";
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
			this->tabpage2->Text = L"Assembler���X�g";
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
			this->label1->Text = L"�t�@�C����";
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
			this->label2->Text = L"�X�^�[�g�A�h���X";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(616, 69);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(83, 12);
			this->label3->TabIndex = 6;
			this->label3->Text = L"�I�t�Z�b�g�A�h���X";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(604, 115);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(101, 24);
			this->label4->TabIndex = 7;
			this->label4->Text = L"�X�L�b�v�A�h���X�͈�\r\n�i�폜�͑I������D�j";
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
		f_Lnosave = false;	/* ���ۑ���List�t�@�C���͂Ȃ� */
		f_Anosave = false;	/* ���ۑ���Assemble�t�@�C���͂Ȃ� */
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
				// �\���G���A�̍ĕ\��
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
	private: System::Void �J��OToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
		statusStripClear();
		LoadFileName();
		LoadFile();
		ofsadr = 0;
		// �\���G���A�̍ĕ\��
		txtBoxSttAdr->Text = "$" + topadr.ToString("X4");
		txtBoxOfsAdr->Text = "$" + ofsadr.ToString("X4");
		txtBoxOutList->Clear();
		txtBoxOutAsm->Clear();
	}
	private: System::Void �ۑ�SToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		statusStripClear();
		SaveFile();
	}
	private: System::Void �I��ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		statusStripClear();
		if (f_Lnosave || f_Anosave) {
			if (MessageBox::Show("���ۑ��̃t�@�C��������܂��D\n���̂܂܏I�����Ă��ǂ��ł���", "File Exist !",
				MessageBoxButtons::YesNo, MessageBoxIcon::Asterisk) == System::Windows::Forms::DialogResult::Yes) {
				exit(0);
			}
		}
		else
			exit(0);
	}
	private: System::Void �I�t�Z�b�g�w��OToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		statusStripClear();
		GetOffsetAdr();
	}
	private: System::Void �X�L�b�v�͈͎w��SToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		statusStripClear();
		ListSkipArea();
	}
	private: System::Void lIST�\���N���ACToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		statusStripClear();
		txtBoxOutList->Clear();
	}
	private: System::Void �t�A�Z���u�����sEToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		SetSkipArea();
		Execute();
	}
	private: System::Void aboutAToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		statusStripClear();
		// HelpForm�̐V�����C���X�^���X�𐶐�����
		HelpForm^ HelpForm1 = gcnew HelpForm();
		// Display the new Form
		HelpForm1->ShowDialog();
	}

//=============================================================================
//***** subroutine ***** 

void Execute()
{

   ////////////////////////////////////////////////////////////
   /* for debug */
   DispData();
   ////////////////////////////////////////////////////////////


}

/*==========================================================*/
/*		Get Load FileName									*/
/*==========================================================*/
int LoadFileName()
{
   txtBoxOutList->Clear();
   txtBoxOutAsm->Clear();
   this->Update();		// Form�S�̂��ĕ`��
   openFileDialog1->Title = "���̓t�@�C����";
   if (openFileDialog1->ShowDialog() != System::Windows::Forms::DialogResult::OK)
	   return -1;
   // �t�@�C������\��
   txtBoxFileName->Text = openFileDialog1->FileName;
   return 0;
}

/*==========================================================*/
/*		Load Binary / Hex / S File							*/
/*==========================================================*/
int LoadFile()
{
   int result = -1;

   //�t�@�C���̓ǂݍ���
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
	   if (MessageBox::Show("�g���q��BIN,HEX,MOT,S�̂�����ł�����܂���D\nBIN�t�@�C���Ƃ݂Ȃ��ėǂ��ł����D", "Confirm File type",
		   MessageBoxButtons::YesNo, MessageBoxIcon::Asterisk) == System::Windows::Forms::DialogResult::Yes) {
		   result = LoadBinFile(txtBoxFileName->Text);
	   }
	   else {
		   return -1;
	   }
   }
   //	// �\���G���A�̍ĕ\��
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
   statusStrip1->Update();		// statusStrip���ĕ`��

   //Load
   try {	//in System::IO
	   FileStream^ fs = gcnew FileStream(FileName, FileMode::Open);
	   BinaryReader^ br = gcnew BinaryReader(fs);
	   try {
		   cli::array< unsigned char >^ data = gcnew cli::array< unsigned char >((int)fs->Length);
		   //�ǂݍ���
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
	   MessageBox::Show("����ȃt�@�C���`���ł͂Ȃ����߁C�ǂݍ��߂܂���ł����D\n�t�@�C�����m�F���Ă��������D", "File error!",
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
   this->Update();		// Form�S�̂��ĕ`��

   //���̓X�g���[���̐ݒ�
   try {
	   FileStream^ fs = gcnew FileStream(FileName, FileMode::Open);
	   StreamReader^ sr = gcnew StreamReader(fs, System::Text::Encoding::GetEncoding("ascii"));
	   rdlen = 0;
	   do {
		   csum = 0;
		   //��s�ǂݍ���
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
				   //					if (adr < topadr)	/* adr�̍ŏ��l�������� */
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
				   MessageBox::Show("�g���R�[�h���܂܂�Ă��܂��D\n���̃v���O�����͊g���A�h���X�ɑΉ����Ă��܂���D", "Invalid record warning",
					   MessageBoxButtons::OK, MessageBoxIcon::Warning);
				   sr->Close();
				   return -5;
			   }
			   if (rtype == 03) {		//03:Entry address record
				   EntryLineTmp = gcnew String(buf);
				   result = 0;
			   }
			   if (rtype < 0 || rtype > 3) {
				   MessageBox::Show("��" + ct.ToString() + "�s�̃��R�[�h�^�C�v������������܂���D\n�t�@�C�����m�F���Ă��������D", "Record type error!",
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
				   if (btmadr < adr + len)	/* �ŏI�A�h���X�̍ő�l�������� */
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
				   if (MessageBox::Show("��" + (ct + 1).ToString() + "�s�̃`�F�b�N�T���͌���Ă��܂��D\n���̂܂ܓǂݑ����܂����H", "Check sum error!",
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
	   MessageBox::Show("�t�@�C�������݂��Ȃ����C���邢�̓t�@�C���`�����Ⴂ�܂��D\n�t�@�C�����m�F���Ă��������D", "File error !",
		   MessageBoxButtons::OK, MessageBoxIcon::Error);
	   return -1;
   }
   if (dlen != 0) {
   }
   else {
	   MessageBox::Show("����ȃt�@�C���`���ł͂Ȃ����߁C�ǂݍ��߂܂���ł����D\n�t�@�C�����m�F���Ă��������D", "File error !",
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
   this->Update();		// Form�S�̂��ĕ`��

   //���̓X�g���[���̐ݒ�
   try {
	   FileStream^ fs = gcnew FileStream(FileName, FileMode::Open);
	   StreamReader^ sr = gcnew StreamReader(fs, System::Text::Encoding::GetEncoding("ascii"));
	   rdlen = 0;
	   do {
		   csum = 0;
		   //��s�ǂݍ���
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
				   //					if (adr < topadr)	/* adr�̍ŏ��l�������� */
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
			   if (btmadr < adr + len)	/* �ŏI�A�h���X�̍ő�l�������� */
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
				   if (MessageBox::Show("��" + ct.ToString() + "�s�̃`�F�b�N�T���͌���Ă��܂��D\n���̂܂ܓǂݑ����܂����H", "Check sum error!",
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
			   MessageBox::Show("�R,�S�o�C�g�A�h���X�ɂ͑Ή����Ă��܂���D\n�t�@�C�����m�F���Ă��������D", "Invalid record error !",
				   MessageBoxButtons::OK, MessageBoxIcon::Error);
			   return -8;
			   break;
		   case 7:	//4,3,2bytes entry address
		   case 8:
		   case 9:
			   EntryLineTmp = gcnew String(buf);
			   break;
		   default:
			   MessageBox::Show("S�t�H�[�}�b�g�t�@�C���ł͂���܂���D\n�t�@�C�����m�F���Ă��������D", "File format error !",
				   MessageBoxButtons::OK, MessageBoxIcon::Error);
			   return -9;
		   }
		   ct++;
	   } while (sr->Peek() != -1);
	   sr->Close();
	   dlen = rdlen;
	   if (dlen == 0) {
		   MessageBox::Show("����ȃt�@�C���`���ł͂Ȃ����߁C�ǂݍ��߂܂���ł����D\n�t�@�C�����m�F���Ă��������D", "File error !",
			   MessageBoxButtons::OK, MessageBoxIcon::Error);
		   return -10;
	   }

   }
   catch (Exception^) {
	   MessageBox::Show("�t�@�C�������݂��Ȃ����C���邢�̓t�@�C���`�����Ⴂ�܂��D\n�t�@�C�����m�F���Ă��������D", "File error !",
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

	// OffsetInForm�̐V�����C���X�^���X�𐶐��E�\��
	OffsetInForm^ OffsetInForm1 = gcnew OffsetInForm();
	OffsetInForm1->ShowDialog();

	std::string ss = "0000";
	if (OffsetInForm1->txtBoxOffsetIn->Text == "")
		ofsadr = 0;
	else {
		MarshalString(OffsetInForm1->txtBoxOffsetIn->Text, ss);
		ofsadr = (unsigned int)strtol(ss.c_str(), &eptr, 16);
	}
	//���͌��ʂ�Form1��textBox�ɃZ�b�g
	if (ss[0] == '-')	/* �����̂ݕ����\���� */
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

	// SkipAreaInForm�̐V�����C���X�^���X�𐶐��E�\��
	SkipAreaInForm^ SkipAreaInForm1 = gcnew SkipAreaInForm();
	SkipAreaInForm1->ShowDialog();

	/* Convert to string */
	std::string ss = "0000";
	MarshalString(SkipAreaInForm1->txtBoxSkipAreaIn->Text, ss);
	/* �X�^�[�g�A�G���h�A�h���X���擾 */
	p = strtok_s((char*)ss.c_str(), "-", &context);
	if (p)
		sadr = (int)strtol(p, &eptr, 16);
	p = strtok_s(NULL, "-", &context);
	if (p)
		eadr = (int)strtol(p, &eptr, 16);
	else
		eadr = sadr;

	if (eadr - sadr >= 32) {
		if (MessageBox::Show("�X�L�b�v�͈͂��傫�����܂��D\n32�o�C�g�ɏk�����ėǂ��ł����D", "Confirm skip area size",
			MessageBoxButtons::YesNo, MessageBoxIcon::Asterisk) == System::Windows::Forms::DialogResult::Yes) {
			eadr = sadr + 32 - 1;
		}
		else {
			return;
		}
	}

	/* ���X�g�{�b�N�X�ɒǉ� */
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

	/* ���ڐ����擾 */
	skpct = lstBoxSkipArea->Items->Count;
	/* ���ڐ����̔z��𐶐� */
	cli::array<String^>^ StrArray = gcnew cli::array<String^>(skpct);
	/* �S���ڎ擾 */
	for (i = 0; i < skpct; i++) {
		StrArray[i] = lstBoxSkipArea->Items[i]->ToString();
	}
	/* �A�h���X�ɕϊ� */
	for (i = 0; i < skpct; i++) {
		/* �擪����($)���폜���� */
		StrArray[i] = StrArray[i]->Replace("$", "");
		/* �X�y�[�X���폜���� */
		StrArray[i] = StrArray[i]->Replace(" ", "");
		/* string�ɕϊ����Ă��� */
		ss = "000000000";
		MarshalString(StrArray[i], ss);
		/* �X�^�[�g�A�G���h�A�h���X���擾 */
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
   statusStrip1->Update();		// statusStrip���ĕ`��
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

   // �Ƃ肠�����m�F�̂��߂ɓǂݍ��񂾃f�[�^��\�������Ă݂�
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

};
}

