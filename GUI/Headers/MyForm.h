#pragma once

#include "Factorization.h"
#include <msclr\marshal_cppstd.h>
#include "ShellAPI.h"

namespace PolynomFactorization_win {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  bFactorization;
	private: System::Windows::Forms::RadioButton^  rbSqr;
	protected:

	protected:


	private: System::Windows::Forms::RadioButton^  rbKron;
	protected:


	private: System::Windows::Forms::RadioButton^  rbAlg;

	private: System::Windows::Forms::TextBox^  tbFactorization;



	private: System::Windows::Forms::TextBox^  tbPolynom;


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ��������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �����������������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ���������������������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �����������������������������������������ToolStripMenuItem;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Panel^  panel1;

















	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->bFactorization = (gcnew System::Windows::Forms::Button());
			this->rbSqr = (gcnew System::Windows::Forms::RadioButton());
			this->rbKron = (gcnew System::Windows::Forms::RadioButton());
			this->rbAlg = (gcnew System::Windows::Forms::RadioButton());
			this->tbFactorization = (gcnew System::Windows::Forms::TextBox());
			this->tbPolynom = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������������������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->menuStrip1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// bFactorization
			// 
			this->bFactorization->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->bFactorization->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bFactorization->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->bFactorization->Location = System::Drawing::Point(16, 264);
			this->bFactorization->Name = L"bFactorization";
			this->bFactorization->Size = System::Drawing::Size(130, 37);
			this->bFactorization->TabIndex = 11;
			this->bFactorization->Text = L"���������";
			this->bFactorization->UseVisualStyleBackColor = false;
			this->bFactorization->Click += gcnew System::EventHandler(this, &MyForm::bFactorization_Click);
			// 
			// rbSqr
			// 
			this->rbSqr->AutoSize = true;
			this->rbSqr->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->rbSqr->Location = System::Drawing::Point(162, 192);
			this->rbSqr->Name = L"rbSqr";
			this->rbSqr->Size = System::Drawing::Size(437, 33);
			this->rbSqr->TabIndex = 10;
			this->rbSqr->TabStop = true;
			this->rbSqr->Text = L"�� ��������� �� ��������� ���������";
			this->rbSqr->UseVisualStyleBackColor = true;
			// 
			// rbKron
			// 
			this->rbKron->AutoSize = true;
			this->rbKron->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->rbKron->Location = System::Drawing::Point(162, 153);
			this->rbKron->Name = L"rbKron";
			this->rbKron->Size = System::Drawing::Size(342, 33);
			this->rbKron->TabIndex = 9;
			this->rbKron->TabStop = true;
			this->rbKron->Text = L"�� ������������ ���������";
			this->rbKron->UseVisualStyleBackColor = true;
			// 
			// rbAlg
			// 
			this->rbAlg->AutoSize = true;
			this->rbAlg->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->rbAlg->Location = System::Drawing::Point(161, 114);
			this->rbAlg->Name = L"rbAlg";
			this->rbAlg->Size = System::Drawing::Size(288, 33);
			this->rbAlg->TabIndex = 8;
			this->rbAlg->TabStop = true;
			this->rbAlg->Text = L"�� �������� ���������";
			this->rbAlg->UseVisualStyleBackColor = true;
			this->rbAlg->CheckedChanged += gcnew System::EventHandler(this, &MyForm::rbAlg_CheckedChanged);
			// 
			// tbFactorization
			// 
			this->tbFactorization->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->tbFactorization->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbFactorization->Location = System::Drawing::Point(161, 265);
			this->tbFactorization->Name = L"tbFactorization";
			this->tbFactorization->ReadOnly = true;
			this->tbFactorization->Size = System::Drawing::Size(543, 37);
			this->tbFactorization->TabIndex = 7;
			// 
			// tbPolynom
			// 
			this->tbPolynom->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tbPolynom->Location = System::Drawing::Point(162, 51);
			this->tbPolynom->Name = L"tbPolynom";
			this->tbPolynom->Size = System::Drawing::Size(542, 37);
			this->tbPolynom->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(11, 54);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(135, 29);
			this->label3->TabIndex = 14;
			this->label3->Text = L"���������:";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->����ToolStripMenuItem,
					this->�������ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(744, 24);
			this->menuStrip1->TabIndex = 15;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->�����������������������������ToolStripMenuItem,
					this->���������������������������������ToolStripMenuItem, this->�����������������������������������������ToolStripMenuItem
			});
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(100, 20);
			this->����ToolStripMenuItem->Text = L"������������";
			this->����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::����ToolStripMenuItem_Click);
			// 
			// �����������������������������ToolStripMenuItem
			// 
			this->�����������������������������ToolStripMenuItem->Name = L"�����������������������������ToolStripMenuItem";
			this->�����������������������������ToolStripMenuItem->Size = System::Drawing::Size(361, 22);
			this->�����������������������������ToolStripMenuItem->Text = L"���������� �� �������� ���������";
			this->�����������������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::�����������������������������ToolStripMenuItem_Click);
			// 
			// ���������������������������������ToolStripMenuItem
			// 
			this->���������������������������������ToolStripMenuItem->Name = L"���������������������������������ToolStripMenuItem";
			this->���������������������������������ToolStripMenuItem->Size = System::Drawing::Size(361, 22);
			this->���������������������������������ToolStripMenuItem->Text = L"���������� �� ������������ ���������";
			this->���������������������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::���������������������������������ToolStripMenuItem_Click);
			// 
			// �����������������������������������������ToolStripMenuItem
			// 
			this->�����������������������������������������ToolStripMenuItem->Name = L"�����������������������������������������ToolStripMenuItem";
			this->�����������������������������������������ToolStripMenuItem->Size = System::Drawing::Size(361, 22);
			this->�����������������������������������������ToolStripMenuItem->Text = L"���������� �� ��������� �� ��������� ���������";
			this->�����������������������������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::�����������������������������������������ToolStripMenuItem_Click);
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->��������������ToolStripMenuItem });
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->�������ToolStripMenuItem->Text = L"�������";
			// 
			// ��������������ToolStripMenuItem
			// 
			this->��������������ToolStripMenuItem->Name = L"��������������ToolStripMenuItem";
			this->��������������ToolStripMenuItem->Size = System::Drawing::Size(168, 22);
			this->��������������ToolStripMenuItem->Text = L"������� �������";
			this->��������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::��������������ToolStripMenuItem_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(11, 153);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(145, 29);
			this->label1->TabIndex = 12;
			this->label1->Text = L"����������:";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->bFactorization);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->tbFactorization);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->rbAlg);
			this->panel1->Controls->Add(this->rbSqr);
			this->panel1->Controls->Add(this->tbPolynom);
			this->panel1->Controls->Add(this->rbKron);
			this->panel1->Location = System::Drawing::Point(14, 28);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(718, 326);
			this->panel1->TabIndex = 16;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(744, 366);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"���������� �����������";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void bFactorization_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (tbPolynom->Text != "")
		{
			msclr::interop::marshal_context context;
			PolynomZ polZ(context.marshal_as<string>(tbPolynom->Text));

			if (polZ.toString() == "0")
			{
				tbFactorization->Text = "�������� ����";
				return;
			}

			Factorization fact;

			if (rbAlg->Checked)
			{
				fact = polZ.algebraicFact();
				tbFactorization->Text = gcnew String(fact.toString().c_str());
			}
			else if (rbKron->Checked)
			{
				fact = polZ.kroneckerFact();
				tbFactorization->Text = gcnew String(fact.toString().c_str());
			}
			else if (rbSqr->Checked)
			{
				fact = polZ.squaresFreeFact();
				tbFactorization->Text = gcnew String(fact.toString().c_str());
			}
			else
				tbFactorization->Text = "������ ���������";
		}
		else
			tbFactorization->Text = "������� ���������";

	}
private: System::Void rbAlg_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void ����ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void �����������������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	tbPolynom->Text = "x^9 + 16x^8 + 8x^6 + 128x^5";
	rbAlg->Checked = true;
}
private: System::Void ���������������������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	tbPolynom->Text = "x^5 - x^4 + 4x - 4";
	rbKron->Checked = true;
}
		
private: System::Void �����������������������������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	tbPolynom->Text = "x^5 - x^4 - 2x^3 + 2x^2 + x - 1";
	rbSqr->Checked = true;
}

private: System::Void ��������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	system("start HELP.txt");
}
};
}
