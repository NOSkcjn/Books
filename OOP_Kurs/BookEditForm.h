#pragma once

#include "Book.h"
#include "HandwrittenBook.h"
#include "AudioBook.h"
#include "ElectronicBook.h"
#include "Constants.h"

namespace OOP_Kurs {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для BookEditForm
	/// </summary>
	public ref class BookEditForm : public System::Windows::Forms::Form
	{
	public:
		BookEditForm(void)
		{
			InitializeComponent();
		}

		BookEditForm(Book^ bookToEdit)
		{
			InitializeComponent();
			_currentBook = bookToEdit;

			this->nameTBox->Text = bookToEdit->Name;
			this->authorTBox->Text = bookToEdit->Author;
			this->numericPages->Value = bookToEdit->Pages;

			this->comboBoxGenre->Items->AddRange(gcnew cli::array< System::Object^  >(3)
			{
				gcnew String(FANTASTIC),
					gcnew String(NOVEL),
					gcnew String(THRILLER)
			});

			this->comboBoxTypeBook->Items->AddRange(gcnew cli::array< System::Object^  >(3)
			{
				gcnew String(HANDWRITTENBOOK),
					gcnew String(AUDIOBOOK),
					gcnew String(ELECTRONICBOOK)
			});

			this->comboBoxGenre->Text = bookToEdit->Genre;

			this->comboBoxTypeBook->SelectedItem = bookToEdit->ToString();

			if (comboBoxTypeBook->Text == gcnew String(AUDIOBOOK))
			{
				AudioBook^ newBook = (AudioBook^)_currentBook;
				numericLengthABook->Value = newBook->Length;
			}
			else if (comboBoxTypeBook->Text == gcnew String(ELECTRONICBOOK))
			{
				ElectronicBook^ newBook = (ElectronicBook^)_currentBook;
				numericSizeEBook->Value = newBook->Size;
			}
			else
			{
				HandwrittenBook^ newBook = (HandwrittenBook^)_currentBook;
				comboBoxHandwritten->SelectedIndex = Convert::ToInt32(newBook->Handwritten);
			}
		}

		Book^ Edit()
		{
			return _currentBook;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~BookEditForm()
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

		System::Windows::Forms::Label^  authorLabel;
		System::Windows::Forms::TextBox^  nameTBox;

		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Label^  labelTypeBook;
	private: System::Windows::Forms::ComboBox^  comboBoxTypeBook;
	private: System::Windows::Forms::NumericUpDown^  numericLengthABook;
	private: System::Windows::Forms::Label^  labelLengthABook;
	private: System::Windows::Forms::NumericUpDown^  numericSizeEBook;
	private: System::Windows::Forms::Label^  labelSizeEBook;
	private: System::Windows::Forms::ComboBox^  comboBoxHandwritten;
	private: System::Windows::Forms::Label^  labelHandwritten;
	private: System::Windows::Forms::NumericUpDown^  numericPages;

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
				 this->authorLabel = (gcnew System::Windows::Forms::Label());
				 this->nameTBox = (gcnew System::Windows::Forms::TextBox());
				 this->labelTypeBook = (gcnew System::Windows::Forms::Label());
				 this->comboBoxTypeBook = (gcnew System::Windows::Forms::ComboBox());
				 this->numericLengthABook = (gcnew System::Windows::Forms::NumericUpDown());
				 this->labelLengthABook = (gcnew System::Windows::Forms::Label());
				 this->numericSizeEBook = (gcnew System::Windows::Forms::NumericUpDown());
				 this->labelSizeEBook = (gcnew System::Windows::Forms::Label());
				 this->comboBoxHandwritten = (gcnew System::Windows::Forms::ComboBox());
				 this->labelHandwritten = (gcnew System::Windows::Forms::Label());
				 this->numericPages = (gcnew System::Windows::Forms::NumericUpDown());
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericLengthABook))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericSizeEBook))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericPages))->BeginInit();
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
				 this->btnEditOk->Click += gcnew System::EventHandler(this, &BookEditForm::btnEditOk_Click);
				 // 
				 // labelGenre
				 // 
				 this->labelGenre->AutoSize = true;
				 this->labelGenre->Location = System::Drawing::Point(31, 185);
				 this->labelGenre->Name = L"labelGenre";
				 this->labelGenre->Size = System::Drawing::Size(36, 13);
				 this->labelGenre->TabIndex = 17;
				 this->labelGenre->Text = L"Жанр";
				 // 
				 // comboBoxGenre
				 // 
				 this->comboBoxGenre->FormattingEnabled = true;
				 this->comboBoxGenre->Location = System::Drawing::Point(105, 182);
				 this->comboBoxGenre->Name = L"comboBoxGenre";
				 this->comboBoxGenre->Size = System::Drawing::Size(121, 21);
				 this->comboBoxGenre->TabIndex = 16;
				 // 
				 // bookNameLabel
				 // 
				 this->bookNameLabel->AutoSize = true;
				 this->bookNameLabel->Location = System::Drawing::Point(31, 78);
				 this->bookNameLabel->Name = L"bookNameLabel";
				 this->bookNameLabel->Size = System::Drawing::Size(89, 13);
				 this->bookNameLabel->TabIndex = 10;
				 this->bookNameLabel->Text = L"Название книги";
				 // 
				 // authorTBox
				 // 
				 this->authorTBox->Location = System::Drawing::Point(105, 138);
				 this->authorTBox->Name = L"authorTBox";
				 this->authorTBox->Size = System::Drawing::Size(100, 20);
				 this->authorTBox->TabIndex = 15;
				 // 
				 // pagesLabel
				 // 
				 this->pagesLabel->AutoSize = true;
				 this->pagesLabel->Location = System::Drawing::Point(31, 116);
				 this->pagesLabel->Name = L"pagesLabel";
				 this->pagesLabel->Size = System::Drawing::Size(110, 13);
				 this->pagesLabel->TabIndex = 11;
				 this->pagesLabel->Text = L"Количество страниц";
				 // 
				 // authorLabel
				 // 
				 this->authorLabel->AutoSize = true;
				 this->authorLabel->Location = System::Drawing::Point(31, 145);
				 this->authorLabel->Name = L"authorLabel";
				 this->authorLabel->Size = System::Drawing::Size(37, 13);
				 this->authorLabel->TabIndex = 12;
				 this->authorLabel->Text = L"Автор";
				 // 
				 // nameTBox
				 // 
				 this->nameTBox->Location = System::Drawing::Point(138, 78);
				 this->nameTBox->Name = L"nameTBox";
				 this->nameTBox->Size = System::Drawing::Size(100, 20);
				 this->nameTBox->TabIndex = 13;
				 // 
				 // labelTypeBook
				 // 
				 this->labelTypeBook->AutoSize = true;
				 this->labelTypeBook->Location = System::Drawing::Point(31, 42);
				 this->labelTypeBook->Name = L"labelTypeBook";
				 this->labelTypeBook->Size = System::Drawing::Size(58, 13);
				 this->labelTypeBook->TabIndex = 19;
				 this->labelTypeBook->Text = L"Тип книги";
				 // 
				 // comboBoxTypeBook
				 // 
				 this->comboBoxTypeBook->FormattingEnabled = true;
				 this->comboBoxTypeBook->ImeMode = System::Windows::Forms::ImeMode::Off;
				 this->comboBoxTypeBook->Location = System::Drawing::Point(135, 42);
				 this->comboBoxTypeBook->Name = L"comboBoxTypeBook";
				 this->comboBoxTypeBook->Size = System::Drawing::Size(121, 21);
				 this->comboBoxTypeBook->TabIndex = 18;
				 this->comboBoxTypeBook->SelectedIndexChanged += gcnew System::EventHandler(this, &BookEditForm::comboBoxTypeBook_SelectedIndexChanged);
				 // 
				 // numericLengthABook
				 // 
				 this->numericLengthABook->Location = System::Drawing::Point(288, 86);
				 this->numericLengthABook->Name = L"numericLengthABook";
				 this->numericLengthABook->Size = System::Drawing::Size(120, 20);
				 this->numericLengthABook->TabIndex = 25;
				 // 
				 // labelLengthABook
				 // 
				 this->labelLengthABook->AutoSize = true;
				 this->labelLengthABook->Location = System::Drawing::Point(285, 53);
				 this->labelLengthABook->Name = L"labelLengthABook";
				 this->labelLengthABook->Size = System::Drawing::Size(133, 13);
				 this->labelLengthABook->TabIndex = 24;
				 this->labelLengthABook->Text = L"Длительность в минутах";
				 // 
				 // numericSizeEBook
				 // 
				 this->numericSizeEBook->Location = System::Drawing::Point(298, 74);
				 this->numericSizeEBook->Name = L"numericSizeEBook";
				 this->numericSizeEBook->Size = System::Drawing::Size(120, 20);
				 this->numericSizeEBook->TabIndex = 23;
				 // 
				 // labelSizeEBook
				 // 
				 this->labelSizeEBook->AutoSize = true;
				 this->labelSizeEBook->Location = System::Drawing::Point(295, 45);
				 this->labelSizeEBook->Name = L"labelSizeEBook";
				 this->labelSizeEBook->Size = System::Drawing::Size(116, 13);
				 this->labelSizeEBook->TabIndex = 22;
				 this->labelSizeEBook->Text = L"Размер в килобайтах";
				 // 
				 // comboBoxHandwritten
				 // 
				 this->comboBoxHandwritten->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(2) { L"Печатная", L"Рукописная" });
				 this->comboBoxHandwritten->FormattingEnabled = true;
				 this->comboBoxHandwritten->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Печатная", L"Рукописная" });
				 this->comboBoxHandwritten->Location = System::Drawing::Point(291, 69);
				 this->comboBoxHandwritten->Name = L"comboBoxHandwritten";
				 this->comboBoxHandwritten->Size = System::Drawing::Size(121, 21);
				 this->comboBoxHandwritten->TabIndex = 21;
				 // 
				 // labelHandwritten
				 // 
				 this->labelHandwritten->AutoSize = true;
				 this->labelHandwritten->Location = System::Drawing::Point(288, 42);
				 this->labelHandwritten->Name = L"labelHandwritten";
				 this->labelHandwritten->Size = System::Drawing::Size(83, 13);
				 this->labelHandwritten->TabIndex = 20;
				 this->labelHandwritten->Text = L"Вид написания";
				 // 
				 // numericPages
				 // 
				 this->numericPages->Location = System::Drawing::Point(165, 112);
				 this->numericPages->Name = L"numericPages";
				 this->numericPages->Size = System::Drawing::Size(84, 20);
				 this->numericPages->TabIndex = 26;
				 this->numericPages->Minimum = 1;
				 this->numericPages->Maximum = 1500;
				 // 
				 // BookEditForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(435, 320);
				 this->Controls->Add(this->numericPages);
				 this->Controls->Add(this->numericLengthABook);
				 this->Controls->Add(this->labelLengthABook);
				 this->Controls->Add(this->numericSizeEBook);
				 this->Controls->Add(this->labelSizeEBook);
				 this->Controls->Add(this->comboBoxHandwritten);
				 this->Controls->Add(this->labelHandwritten);
				 this->Controls->Add(this->labelTypeBook);
				 this->Controls->Add(this->comboBoxTypeBook);
				 this->Controls->Add(this->labelGenre);
				 this->Controls->Add(this->comboBoxGenre);
				 this->Controls->Add(this->bookNameLabel);
				 this->Controls->Add(this->authorTBox);
				 this->Controls->Add(this->pagesLabel);
				 this->Controls->Add(this->authorLabel);
				 this->Controls->Add(this->nameTBox);
				 this->Controls->Add(this->btnEditOk);
				 this->Name = L"BookEditForm";
				 this->Text = L"BookEditForm";
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericLengthABook))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericSizeEBook))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericPages))->EndInit();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	private:

		System::Void btnEditOk_Click(System::Object^  sender, System::EventArgs^  e) {
			if (comboBoxTypeBook->Text == gcnew String(AUDIOBOOK))
			{
				AudioBook^ newBook = gcnew AudioBook(_currentBook->ID);
				newBook->Length = (int)numericLengthABook->Value;
				_currentBook = newBook;
			}
			else if (comboBoxTypeBook->Text == gcnew String(ELECTRONICBOOK))
			{
				ElectronicBook^ newBook = gcnew ElectronicBook(_currentBook->ID);
				newBook->Size = (int)numericSizeEBook->Value;
				_currentBook = newBook;
			}
			else
			{
				HandwrittenBook^ newBook = gcnew HandwrittenBook(_currentBook->ID);
				newBook->Handwritten = Convert::ToBoolean(comboBoxHandwritten->SelectedIndex);
				_currentBook = newBook;
			}
			_currentBook->Name = this->nameTBox->Text;
			_currentBook->Author = this->authorTBox->Text;
			_currentBook->Pages = Convert::ToInt32(this->numericPages->Value);
			_currentBook->Genre = this->comboBoxGenre->Text;
			this->Close();
	}
	private: System::Void comboBoxTypeBook_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		switch (comboBoxTypeBook->SelectedIndex)
		{
		case 0:
			this->labelHandwritten->Visible = true;
			this->comboBoxHandwritten->Visible = true;

			this->labelSizeEBook->Visible = false;
			this->numericSizeEBook->Visible = false;

			this->labelLengthABook->Visible = false;
			this->numericLengthABook->Visible = false;
			break;
		case 1:
			this->labelHandwritten->Visible = false;
			this->comboBoxHandwritten->Visible = false;

			this->labelSizeEBook->Visible = false;
			this->numericSizeEBook->Visible = false;

			this->labelLengthABook->Visible = true;
			this->numericLengthABook->Visible = true;
			break;
		case 2:
			this->labelHandwritten->Visible = false;
			this->comboBoxHandwritten->Visible = false;

			this->labelSizeEBook->Visible = true;
			this->numericSizeEBook->Visible = true;

			this->labelLengthABook->Visible = false;
			this->numericLengthABook->Visible = false;
			break;
		}
	}
	};
}
