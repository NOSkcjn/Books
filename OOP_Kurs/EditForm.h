#pragma once

#include "Book.h"
#include "MainForm.h"

namespace OOP_Kurs {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для EditForm
	/// </summary>
	public ref class EditForm : public System::Windows::Forms::Form
	{
	public:
		EditForm(void)
		{
			InitializeComponent();
		}

		EditForm(Book^ bookToEdit)
		{
			InitializeComponent();
			_currentBook = bookToEdit;

			this->nameTBox->Text = bookToEdit->Name;
			this->authorTBox->Text = bookToEdit->Author;
			this->pagesTBox->Text = bookToEdit->Pages.ToString();
			this->comboBoxGenre->Text = bookToEdit->Genre;
		}

		Book^ Edit()
		{
			return _currentBook;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~EditForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		System::Windows::Forms::Button^  btnEditOk;
		System::Windows::Forms::Label^  labelGenre;
		System::Windows::Forms::ComboBox^  comboBoxGenre;
		System::Windows::Forms::Label^  bookNameLabel;
		System::Windows::Forms::TextBox^  authorTBox;
		System::Windows::Forms::Label^  pagesLabel;
		System::Windows::Forms::TextBox^  pagesTBox;
		System::Windows::Forms::Label^  authorLabel;
		System::Windows::Forms::TextBox^  nameTBox;

		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

		Book^ _currentBook;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnEditOk = (gcnew System::Windows::Forms::Button());
			this->labelGenre = (gcnew System::Windows::Forms::Label());
			this->comboBoxGenre = (gcnew System::Windows::Forms::ComboBox());
			this->bookNameLabel = (gcnew System::Windows::Forms::Label());
			this->authorTBox = (gcnew System::Windows::Forms::TextBox());
			this->pagesLabel = (gcnew System::Windows::Forms::Label());
			this->pagesTBox = (gcnew System::Windows::Forms::TextBox());
			this->authorLabel = (gcnew System::Windows::Forms::Label());
			this->nameTBox = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// btnEditOk
			// 
			this->btnEditOk->Location = System::Drawing::Point(174, 252);
			this->btnEditOk->Name = L"btnEditOk";
			this->btnEditOk->Size = System::Drawing::Size(75, 23);
			this->btnEditOk->TabIndex = 0;
			this->btnEditOk->Text = L"Ok";
			this->btnEditOk->UseVisualStyleBackColor = true;
			this->btnEditOk->Click += gcnew System::EventHandler(this, &EditForm::btnEditOk_Click);
			// 
			// labelGenre
			// 
			this->labelGenre->AutoSize = true;
			this->labelGenre->Location = System::Drawing::Point(90, 170);
			this->labelGenre->Name = L"labelGenre";
			this->labelGenre->Size = System::Drawing::Size(36, 13);
			this->labelGenre->TabIndex = 17;
			this->labelGenre->Text = L"Жанр";
			// 
			// comboBoxGenre
			// 
			this->comboBoxGenre->FormattingEnabled = true;
			this->comboBoxGenre->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Роман", L"Фантастика", L"Триллер" });
			this->comboBoxGenre->Location = System::Drawing::Point(164, 167);
			this->comboBoxGenre->Name = L"comboBoxGenre";
			this->comboBoxGenre->Size = System::Drawing::Size(121, 21);
			this->comboBoxGenre->TabIndex = 16;
			// 
			// bookNameLabel
			// 
			this->bookNameLabel->AutoSize = true;
			this->bookNameLabel->Location = System::Drawing::Point(90, 63);
			this->bookNameLabel->Name = L"bookNameLabel";
			this->bookNameLabel->Size = System::Drawing::Size(89, 13);
			this->bookNameLabel->TabIndex = 10;
			this->bookNameLabel->Text = L"Название книги";
			// 
			// authorTBox
			// 
			this->authorTBox->Location = System::Drawing::Point(164, 123);
			this->authorTBox->Name = L"authorTBox";
			this->authorTBox->Size = System::Drawing::Size(100, 20);
			this->authorTBox->TabIndex = 15;
			// 
			// pagesLabel
			// 
			this->pagesLabel->AutoSize = true;
			this->pagesLabel->Location = System::Drawing::Point(90, 101);
			this->pagesLabel->Name = L"pagesLabel";
			this->pagesLabel->Size = System::Drawing::Size(110, 13);
			this->pagesLabel->TabIndex = 11;
			this->pagesLabel->Text = L"Количество страниц";
			// 
			// pagesTBox
			// 
			this->pagesTBox->Location = System::Drawing::Point(223, 94);
			this->pagesTBox->Name = L"pagesTBox";
			this->pagesTBox->Size = System::Drawing::Size(100, 20);
			this->pagesTBox->TabIndex = 14;
			// 
			// authorLabel
			// 
			this->authorLabel->AutoSize = true;
			this->authorLabel->Location = System::Drawing::Point(90, 130);
			this->authorLabel->Name = L"authorLabel";
			this->authorLabel->Size = System::Drawing::Size(37, 13);
			this->authorLabel->TabIndex = 12;
			this->authorLabel->Text = L"Автор";
			// 
			// nameTBox
			// 
			this->nameTBox->Location = System::Drawing::Point(197, 63);
			this->nameTBox->Name = L"nameTBox";
			this->nameTBox->Size = System::Drawing::Size(100, 20);
			this->nameTBox->TabIndex = 13;
			// 
			// EditForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(435, 320);
			this->Controls->Add(this->labelGenre);
			this->Controls->Add(this->comboBoxGenre);
			this->Controls->Add(this->bookNameLabel);
			this->Controls->Add(this->authorTBox);
			this->Controls->Add(this->pagesLabel);
			this->Controls->Add(this->pagesTBox);
			this->Controls->Add(this->authorLabel);
			this->Controls->Add(this->nameTBox);
			this->Controls->Add(this->btnEditOk);
			this->Name = L"EditForm";
			this->Text = L"EditForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnEditOk_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
};
}
