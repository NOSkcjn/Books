#pragma once

#include <iostream>
#include "Book.h"
#include "HandwrittenBook.h"
#include "AudioBook.h"
#include "ElectronicBook.h"
#include "BookEditForm.h"

namespace OOP_Kurs {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Runtime::Serialization::Formatters::Binary;
	using namespace System::IO;

	/// <summary>
	/// 
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
		BindingList<Book^>^ books = gcnew BindingList <Book^>;

	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			booksGridView->AutoGenerateColumns = false;
			booksGridView->DataSource = books;

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

			this->comboBoxGenre->SelectedIndex = 0;
			this->comboBoxTypeBook->SelectedIndex = 0;
			this->comboBoxHandwritten->SelectedIndex = 0;

			this->labelSizeEBook->Visible = false;
			this->numericSizeEBook->Visible = false;

			this->labelLengthABook->Visible = false;
			this->numericLengthABook->Visible = false;

			this->btnEdit->Visible = false;
			this->btnDel->Visible = false;

			gridViewSearch->AutoGenerateColumns = false;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnAdd;
	protected:

	private: System::Windows::Forms::Label^  bookNameLabel;
	private: System::Windows::Forms::DataGridView^  booksGridView;


	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::Label^  pagesLabel;
	private: System::Windows::Forms::Label^  authorLabel;
	private: System::Windows::Forms::TextBox^  nameTBox;

	private: System::Windows::Forms::TextBox^  authorTBox;



	private: System::Windows::Forms::TabControl^  booksTabControl;
	private: System::Windows::Forms::TabPage^  tabPageList;
	private: System::Windows::Forms::TabPage^  tabPageAdd;
	private: System::Windows::Forms::Button^  btnDel;
	private: System::Windows::Forms::Button^  btnEdit;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  columnName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  columnAuthor;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  columnPages;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  columnGenre;
	private: System::Windows::Forms::Label^  labelGenre;
	private: System::Windows::Forms::ComboBox^  comboBoxGenre;
	private: System::Windows::Forms::Label^  labelTypeBook;
	private: System::Windows::Forms::ComboBox^  comboBoxTypeBook;
	private: System::Windows::Forms::ComboBox^  comboBoxHandwritten;
	private: System::Windows::Forms::Label^  labelHandwritten;
	private: System::Windows::Forms::NumericUpDown^  numericSizeEBook;
	private: System::Windows::Forms::Label^  labelSizeEBook;

	private: System::Windows::Forms::Label^  labelLengthABook;
	private: System::Windows::Forms::NumericUpDown^  numericLengthABook;
	private: System::Windows::Forms::NumericUpDown^  numericPages;
	private: System::Windows::Forms::Button^  btnSave;
	private: System::Windows::Forms::Button^  btnLoad;
	private: System::Windows::Forms::TabPage^  tabPageSearch;
	private: System::Windows::Forms::DataGridView^  gridViewSearch;


	private: System::Windows::Forms::Button^  buttonSearchOk;
	private: System::Windows::Forms::TextBox^  TBoxAuthorSearch;
	private: System::Windows::Forms::Label^  labelAuthorSearch;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ColumnNameSearch;


	protected:
		//EditForm^ formEdit;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->bookNameLabel = (gcnew System::Windows::Forms::Label());
			this->booksGridView = (gcnew System::Windows::Forms::DataGridView());
			this->columnName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnAuthor = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnPages = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnGenre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->pagesLabel = (gcnew System::Windows::Forms::Label());
			this->authorLabel = (gcnew System::Windows::Forms::Label());
			this->nameTBox = (gcnew System::Windows::Forms::TextBox());
			this->authorTBox = (gcnew System::Windows::Forms::TextBox());
			this->booksTabControl = (gcnew System::Windows::Forms::TabControl());
			this->tabPageList = (gcnew System::Windows::Forms::TabPage());
			this->btnLoad = (gcnew System::Windows::Forms::Button());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->btnDel = (gcnew System::Windows::Forms::Button());
			this->btnEdit = (gcnew System::Windows::Forms::Button());
			this->tabPageAdd = (gcnew System::Windows::Forms::TabPage());
			this->numericPages = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericLengthABook = (gcnew System::Windows::Forms::NumericUpDown());
			this->labelLengthABook = (gcnew System::Windows::Forms::Label());
			this->numericSizeEBook = (gcnew System::Windows::Forms::NumericUpDown());
			this->labelSizeEBook = (gcnew System::Windows::Forms::Label());
			this->comboBoxHandwritten = (gcnew System::Windows::Forms::ComboBox());
			this->labelHandwritten = (gcnew System::Windows::Forms::Label());
			this->labelTypeBook = (gcnew System::Windows::Forms::Label());
			this->comboBoxTypeBook = (gcnew System::Windows::Forms::ComboBox());
			this->labelGenre = (gcnew System::Windows::Forms::Label());
			this->comboBoxGenre = (gcnew System::Windows::Forms::ComboBox());
			this->tabPageSearch = (gcnew System::Windows::Forms::TabPage());
			this->gridViewSearch = (gcnew System::Windows::Forms::DataGridView());
			this->buttonSearchOk = (gcnew System::Windows::Forms::Button());
			this->TBoxAuthorSearch = (gcnew System::Windows::Forms::TextBox());
			this->labelAuthorSearch = (gcnew System::Windows::Forms::Label());
			this->ColumnNameSearch = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->booksGridView))->BeginInit();
			this->booksTabControl->SuspendLayout();
			this->tabPageList->SuspendLayout();
			this->tabPageAdd->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericPages))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericLengthABook))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericSizeEBook))->BeginInit();
			this->tabPageSearch->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridViewSearch))->BeginInit();
			this->SuspendLayout();
			// 
			// btnAdd
			// 
			this->btnAdd->Location = System::Drawing::Point(209, 296);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(75, 23);
			this->btnAdd->TabIndex = 0;
			this->btnAdd->Text = L"Добавить";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &MainForm::btnAdd_Click);
			// 
			// bookNameLabel
			// 
			this->bookNameLabel->AutoSize = true;
			this->bookNameLabel->Location = System::Drawing::Point(45, 83);
			this->bookNameLabel->Name = L"bookNameLabel";
			this->bookNameLabel->Size = System::Drawing::Size(89, 13);
			this->bookNameLabel->TabIndex = 1;
			this->bookNameLabel->Text = L"Название книги";
			// 
			// booksGridView
			// 
			this->booksGridView->AllowUserToAddRows = false;
			this->booksGridView->AllowUserToDeleteRows = false;
			this->booksGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->booksGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->columnName,
					this->columnAuthor, this->columnPages, this->columnGenre
			});
			this->booksGridView->Location = System::Drawing::Point(7, 16);
			this->booksGridView->MultiSelect = false;
			this->booksGridView->Name = L"booksGridView";
			this->booksGridView->ReadOnly = true;
			this->booksGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->booksGridView->Size = System::Drawing::Size(444, 298);
			this->booksGridView->TabIndex = 2;
			this->booksGridView->RowsAdded += gcnew System::Windows::Forms::DataGridViewRowsAddedEventHandler(this, &MainForm::booksGridView_RowsAdded);
			this->booksGridView->RowsRemoved += gcnew System::Windows::Forms::DataGridViewRowsRemovedEventHandler(this, &MainForm::booksGridView_RowsRemoved);
			// 
			// columnName
			// 
			this->columnName->DataPropertyName = L"Name";
			this->columnName->HeaderText = L"Название";
			this->columnName->Name = L"columnName";
			this->columnName->ReadOnly = true;
			// 
			// columnAuthor
			// 
			this->columnAuthor->DataPropertyName = L"Author";
			this->columnAuthor->HeaderText = L"Автор";
			this->columnAuthor->Name = L"columnAuthor";
			this->columnAuthor->ReadOnly = true;
			// 
			// columnPages
			// 
			this->columnPages->DataPropertyName = L"Pages";
			this->columnPages->HeaderText = L"Количество страниц";
			this->columnPages->Name = L"columnPages";
			this->columnPages->ReadOnly = true;
			// 
			// columnGenre
			// 
			this->columnGenre->DataPropertyName = L"Genre";
			this->columnGenre->HeaderText = L"Жанр";
			this->columnGenre->Name = L"columnGenre";
			this->columnGenre->ReadOnly = true;
			// 
			// pagesLabel
			// 
			this->pagesLabel->AutoSize = true;
			this->pagesLabel->Location = System::Drawing::Point(45, 123);
			this->pagesLabel->Name = L"pagesLabel";
			this->pagesLabel->Size = System::Drawing::Size(110, 13);
			this->pagesLabel->TabIndex = 3;
			this->pagesLabel->Text = L"Количество страниц";
			// 
			// authorLabel
			// 
			this->authorLabel->AutoSize = true;
			this->authorLabel->Location = System::Drawing::Point(42, 165);
			this->authorLabel->Name = L"authorLabel";
			this->authorLabel->Size = System::Drawing::Size(37, 13);
			this->authorLabel->TabIndex = 4;
			this->authorLabel->Text = L"Автор";
			// 
			// nameTBox
			// 
			this->nameTBox->Location = System::Drawing::Point(152, 83);
			this->nameTBox->Name = L"nameTBox";
			this->nameTBox->Size = System::Drawing::Size(100, 20);
			this->nameTBox->TabIndex = 5;
			// 
			// authorTBox
			// 
			this->authorTBox->Location = System::Drawing::Point(116, 158);
			this->authorTBox->Name = L"authorTBox";
			this->authorTBox->Size = System::Drawing::Size(100, 20);
			this->authorTBox->TabIndex = 7;
			// 
			// booksTabControl
			// 
			this->booksTabControl->Controls->Add(this->tabPageList);
			this->booksTabControl->Controls->Add(this->tabPageAdd);
			this->booksTabControl->Controls->Add(this->tabPageSearch);
			this->booksTabControl->Location = System::Drawing::Point(1, 1);
			this->booksTabControl->Name = L"booksTabControl";
			this->booksTabControl->SelectedIndex = 0;
			this->booksTabControl->Size = System::Drawing::Size(496, 437);
			this->booksTabControl->TabIndex = 8;
			// 
			// tabPageList
			// 
			this->tabPageList->Controls->Add(this->btnLoad);
			this->tabPageList->Controls->Add(this->btnSave);
			this->tabPageList->Controls->Add(this->btnDel);
			this->tabPageList->Controls->Add(this->btnEdit);
			this->tabPageList->Controls->Add(this->booksGridView);
			this->tabPageList->Location = System::Drawing::Point(4, 22);
			this->tabPageList->Name = L"tabPageList";
			this->tabPageList->Padding = System::Windows::Forms::Padding(3);
			this->tabPageList->Size = System::Drawing::Size(488, 411);
			this->tabPageList->TabIndex = 0;
			this->tabPageList->Text = L"Список";
			this->tabPageList->UseVisualStyleBackColor = true;
			// 
			// btnLoad
			// 
			this->btnLoad->Location = System::Drawing::Point(277, 374);
			this->btnLoad->Name = L"btnLoad";
			this->btnLoad->Size = System::Drawing::Size(75, 23);
			this->btnLoad->TabIndex = 6;
			this->btnLoad->Text = L"Загрузить";
			this->btnLoad->UseVisualStyleBackColor = true;
			this->btnLoad->Click += gcnew System::EventHandler(this, &MainForm::btnLoad_Click);
			// 
			// btnSave
			// 
			this->btnSave->Location = System::Drawing::Point(127, 375);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(75, 23);
			this->btnSave->TabIndex = 5;
			this->btnSave->Text = L"Сохранить";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &MainForm::btnSave_Click);
			// 
			// btnDel
			// 
			this->btnDel->Location = System::Drawing::Point(277, 330);
			this->btnDel->Name = L"btnDel";
			this->btnDel->Size = System::Drawing::Size(75, 23);
			this->btnDel->TabIndex = 4;
			this->btnDel->Text = L"Удалить";
			this->btnDel->UseVisualStyleBackColor = true;
			this->btnDel->Click += gcnew System::EventHandler(this, &MainForm::btnDel_Click);
			// 
			// btnEdit
			// 
			this->btnEdit->Location = System::Drawing::Point(97, 330);
			this->btnEdit->Name = L"btnEdit";
			this->btnEdit->Size = System::Drawing::Size(105, 23);
			this->btnEdit->TabIndex = 3;
			this->btnEdit->Text = L"Инфо/Изменить";
			this->btnEdit->UseVisualStyleBackColor = true;
			this->btnEdit->Click += gcnew System::EventHandler(this, &MainForm::btnEdit_Click);
			// 
			// tabPageAdd
			// 
			this->tabPageAdd->Controls->Add(this->numericPages);
			this->tabPageAdd->Controls->Add(this->numericLengthABook);
			this->tabPageAdd->Controls->Add(this->labelLengthABook);
			this->tabPageAdd->Controls->Add(this->numericSizeEBook);
			this->tabPageAdd->Controls->Add(this->labelSizeEBook);
			this->tabPageAdd->Controls->Add(this->comboBoxHandwritten);
			this->tabPageAdd->Controls->Add(this->labelHandwritten);
			this->tabPageAdd->Controls->Add(this->labelTypeBook);
			this->tabPageAdd->Controls->Add(this->comboBoxTypeBook);
			this->tabPageAdd->Controls->Add(this->labelGenre);
			this->tabPageAdd->Controls->Add(this->comboBoxGenre);
			this->tabPageAdd->Controls->Add(this->bookNameLabel);
			this->tabPageAdd->Controls->Add(this->btnAdd);
			this->tabPageAdd->Controls->Add(this->authorTBox);
			this->tabPageAdd->Controls->Add(this->pagesLabel);
			this->tabPageAdd->Controls->Add(this->authorLabel);
			this->tabPageAdd->Controls->Add(this->nameTBox);
			this->tabPageAdd->Location = System::Drawing::Point(4, 22);
			this->tabPageAdd->Name = L"tabPageAdd";
			this->tabPageAdd->Padding = System::Windows::Forms::Padding(3);
			this->tabPageAdd->Size = System::Drawing::Size(488, 411);
			this->tabPageAdd->TabIndex = 1;
			this->tabPageAdd->Text = L"Добавить";
			this->tabPageAdd->UseVisualStyleBackColor = true;
			// 
			// numericPages
			// 
			this->numericPages->Location = System::Drawing::Point(177, 119);
			this->numericPages->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1500, 0, 0, 0 });
			this->numericPages->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericPages->Name = L"numericPages";
			this->numericPages->Size = System::Drawing::Size(85, 20);
			this->numericPages->TabIndex = 18;
			this->numericPages->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// numericLengthABook
			// 
			this->numericLengthABook->Location = System::Drawing::Point(326, 116);
			this->numericLengthABook->Name = L"numericLengthABook";
			this->numericLengthABook->Size = System::Drawing::Size(120, 20);
			this->numericLengthABook->TabIndex = 17;
			// 
			// labelLengthABook
			// 
			this->labelLengthABook->AutoSize = true;
			this->labelLengthABook->Location = System::Drawing::Point(323, 83);
			this->labelLengthABook->Name = L"labelLengthABook";
			this->labelLengthABook->Size = System::Drawing::Size(133, 13);
			this->labelLengthABook->TabIndex = 16;
			this->labelLengthABook->Text = L"Длительность в минутах";
			// 
			// numericSizeEBook
			// 
			this->numericSizeEBook->Location = System::Drawing::Point(326, 104);
			this->numericSizeEBook->Name = L"numericSizeEBook";
			this->numericSizeEBook->Size = System::Drawing::Size(120, 20);
			this->numericSizeEBook->TabIndex = 15;
			// 
			// labelSizeEBook
			// 
			this->labelSizeEBook->AutoSize = true;
			this->labelSizeEBook->Location = System::Drawing::Point(323, 75);
			this->labelSizeEBook->Name = L"labelSizeEBook";
			this->labelSizeEBook->Size = System::Drawing::Size(116, 13);
			this->labelSizeEBook->TabIndex = 14;
			this->labelSizeEBook->Text = L"Размер в килобайтах";
			// 
			// comboBoxHandwritten
			// 
			this->comboBoxHandwritten->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(2) { L"Печатная", L"Рукописная" });
			this->comboBoxHandwritten->FormattingEnabled = true;
			this->comboBoxHandwritten->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Печатная", L"Рукописная" });
			this->comboBoxHandwritten->Location = System::Drawing::Point(318, 99);
			this->comboBoxHandwritten->Name = L"comboBoxHandwritten";
			this->comboBoxHandwritten->Size = System::Drawing::Size(121, 21);
			this->comboBoxHandwritten->TabIndex = 13;
			// 
			// labelHandwritten
			// 
			this->labelHandwritten->AutoSize = true;
			this->labelHandwritten->Location = System::Drawing::Point(315, 72);
			this->labelHandwritten->Name = L"labelHandwritten";
			this->labelHandwritten->Size = System::Drawing::Size(83, 13);
			this->labelHandwritten->TabIndex = 12;
			this->labelHandwritten->Text = L"Вид написания";
			// 
			// labelTypeBook
			// 
			this->labelTypeBook->AutoSize = true;
			this->labelTypeBook->Location = System::Drawing::Point(45, 53);
			this->labelTypeBook->Name = L"labelTypeBook";
			this->labelTypeBook->Size = System::Drawing::Size(58, 13);
			this->labelTypeBook->TabIndex = 11;
			this->labelTypeBook->Text = L"Тип книги";
			// 
			// comboBoxTypeBook
			// 
			this->comboBoxTypeBook->FormattingEnabled = true;
			this->comboBoxTypeBook->ImeMode = System::Windows::Forms::ImeMode::Off;
			this->comboBoxTypeBook->Location = System::Drawing::Point(149, 53);
			this->comboBoxTypeBook->Name = L"comboBoxTypeBook";
			this->comboBoxTypeBook->Size = System::Drawing::Size(121, 21);
			this->comboBoxTypeBook->TabIndex = 10;
			this->comboBoxTypeBook->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::comboBoxTypeBook_SelectedIndexChanged);
			// 
			// labelGenre
			// 
			this->labelGenre->AutoSize = true;
			this->labelGenre->Location = System::Drawing::Point(42, 205);
			this->labelGenre->Name = L"labelGenre";
			this->labelGenre->Size = System::Drawing::Size(36, 13);
			this->labelGenre->TabIndex = 9;
			this->labelGenre->Text = L"Жанр";
			// 
			// comboBoxGenre
			// 
			this->comboBoxGenre->FormattingEnabled = true;
			this->comboBoxGenre->Location = System::Drawing::Point(116, 202);
			this->comboBoxGenre->Name = L"comboBoxGenre";
			this->comboBoxGenre->Size = System::Drawing::Size(121, 21);
			this->comboBoxGenre->TabIndex = 8;
			// 
			// tabPageSearch
			// 
			this->tabPageSearch->Controls->Add(this->gridViewSearch);
			this->tabPageSearch->Controls->Add(this->buttonSearchOk);
			this->tabPageSearch->Controls->Add(this->TBoxAuthorSearch);
			this->tabPageSearch->Controls->Add(this->labelAuthorSearch);
			this->tabPageSearch->Location = System::Drawing::Point(4, 22);
			this->tabPageSearch->Name = L"tabPageSearch";
			this->tabPageSearch->Size = System::Drawing::Size(488, 411);
			this->tabPageSearch->TabIndex = 2;
			this->tabPageSearch->Text = L"Поиск";
			this->tabPageSearch->UseVisualStyleBackColor = true;
			// 
			// gridViewSearch
			// 
			this->gridViewSearch->AllowUserToAddRows = false;
			this->gridViewSearch->AllowUserToDeleteRows = false;
			this->gridViewSearch->AllowUserToOrderColumns = true;
			this->gridViewSearch->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gridViewSearch->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->ColumnNameSearch });
			this->gridViewSearch->Location = System::Drawing::Point(85, 112);
			this->gridViewSearch->MultiSelect = false;
			this->gridViewSearch->Name = L"gridViewSearch";
			this->gridViewSearch->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->gridViewSearch->Size = System::Drawing::Size(270, 169);
			this->gridViewSearch->TabIndex = 3;
			// 
			// buttonSearchOk
			// 
			this->buttonSearchOk->Location = System::Drawing::Point(200, 349);
			this->buttonSearchOk->Name = L"buttonSearchOk";
			this->buttonSearchOk->Size = System::Drawing::Size(75, 23);
			this->buttonSearchOk->TabIndex = 2;
			this->buttonSearchOk->Text = L"Искать";
			this->buttonSearchOk->UseVisualStyleBackColor = true;
			this->buttonSearchOk->Click += gcnew System::EventHandler(this, &MainForm::buttonSearchOk_Click);
			// 
			// TBoxAuthorSearch
			// 
			this->TBoxAuthorSearch->Location = System::Drawing::Point(209, 48);
			this->TBoxAuthorSearch->Name = L"TBoxAuthorSearch";
			this->TBoxAuthorSearch->Size = System::Drawing::Size(100, 20);
			this->TBoxAuthorSearch->TabIndex = 1;
			// 
			// labelAuthorSearch
			// 
			this->labelAuthorSearch->AutoSize = true;
			this->labelAuthorSearch->Location = System::Drawing::Point(82, 51);
			this->labelAuthorSearch->Name = L"labelAuthorSearch";
			this->labelAuthorSearch->Size = System::Drawing::Size(94, 13);
			this->labelAuthorSearch->TabIndex = 0;
			this->labelAuthorSearch->Text = L"Поиск по автору:";
			// 
			// ColumnNameSearch
			// 
			this->ColumnNameSearch->DataPropertyName = L"Name";
			this->ColumnNameSearch->HeaderText = L"Название";
			this->ColumnNameSearch->Name = L"ColumnNameSearch";
			this->ColumnNameSearch->Width = 200;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(492, 433);
			this->Controls->Add(this->booksTabControl);
			this->Name = L"MainForm";
			this->Text = L"Книги";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->booksGridView))->EndInit();
			this->booksTabControl->ResumeLayout(false);
			this->tabPageList->ResumeLayout(false);
			this->tabPageAdd->ResumeLayout(false);
			this->tabPageAdd->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericPages))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericLengthABook))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericSizeEBook))->EndInit();
			this->tabPageSearch->ResumeLayout(false);
			this->tabPageSearch->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gridViewSearch))->EndInit();
			this->ResumeLayout(false);

		}

#pragma endregion


	private:

		void InputBook(Book^ newBook)
		{
			int pages = 0;
			pages = Convert::ToInt32(numericPages->Value);
			newBook->Input(pages, authorTBox->Text, nameTBox->Text, comboBoxGenre->Text);
			books->Add(newBook);
			numericPages->Value = 1;
			nameTBox->Text = "";
			authorTBox->Text = "";
			//comboBoxGenre->Text = "";
		}

		System::Void btnAdd_Click(System::Object^  sender, System::EventArgs^  e) {
			if (comboBoxTypeBook->Text == gcnew String(AUDIOBOOK))
			{
				AudioBook^ newBook = gcnew AudioBook();
				newBook->Length = (int)numericLengthABook->Value;
				InputBook(newBook);
			}
			else if (comboBoxTypeBook->Text == gcnew String(ELECTRONICBOOK))
			{
				ElectronicBook^ newBook = gcnew ElectronicBook();
				newBook->Size = (int)numericSizeEBook->Value;
				InputBook(newBook);
			}
			else
			{
				HandwrittenBook^ newBook = gcnew HandwrittenBook();
				newBook->Handwritten = Convert::ToBoolean(comboBoxHandwritten->SelectedIndex);
				InputBook(newBook);
			}
		}

		System::Void btnEdit_Click(System::Object^  sender, System::EventArgs^  e) {
			Book^ book = (Book^)booksGridView->CurrentRow->DataBoundItem;
			BookEditForm^ formEdit = gcnew BookEditForm(book);
			formEdit->ShowDialog();
			book = formEdit->Edit();
			BindingList<Book^>^ newBooks = gcnew BindingList <Book^>();
			for each (Book^ cur in books)
			{
				if (cur->ID == book->ID)
				{
					//cur->Input(book);
					cur = book;
					//break;
				}
				newBooks->Add(cur);
			}
			books = newBooks;
			this->booksGridView->DataSource = newBooks;
			booksGridView->Refresh();
		}

		System::Void btnDel_Click(System::Object^  sender, System::EventArgs^  e) {
			booksGridView->Rows->Remove(booksGridView->CurrentRow);
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

	private: System::Void booksGridView_RowsAdded(System::Object^  sender, System::Windows::Forms::DataGridViewRowsAddedEventArgs^  e) {
		if (!this->btnEdit->Visible)
		{
			this->btnEdit->Visible = true;
			this->btnDel->Visible = true;
		}
	}

	private: System::Void booksGridView_RowsRemoved(System::Object^  sender, System::Windows::Forms::DataGridViewRowsRemovedEventArgs^  e) {
		if (booksGridView->Rows->Count < 1)
		{
			if (this->btnEdit->Visible)
			{
				this->btnEdit->Visible = false;
				this->btnDel->Visible = false;
			}
		}
	}

	private: System::Void btnSave_Click(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			FileStream^ fileStream = gcnew FileStream(gcnew String(FILENAME), FileMode::OpenOrCreate);
			BinaryFormatter^ formatter = gcnew BinaryFormatter();
			
			formatter->Serialize(fileStream, books);
			
			fileStream->Close();
			MessageBox::Show("Список сохранен в файл");
		}
		catch (Exception ^ ex)
		{
			MessageBox::Show("Ошибка при записи!");
		}
	}
	private: System::Void btnLoad_Click(System::Object^  sender, System::EventArgs^  e) {
		try
		{
			FileStream^ fileStream = gcnew FileStream(gcnew String(FILENAME), FileMode::Open);
			BinaryFormatter^ formatter = gcnew BinaryFormatter();
			
			BindingList<Book ^> ^ ob = (BindingList<Book ^> ^)formatter
				->Deserialize(fileStream);
			booksGridView->DataSource = ob;
			books = ob;
			booksGridView->Refresh();
			Book::AddID(books->Count);
			
			fileStream->Close();
			MessageBox::Show("Список загружен");
		}
		catch (Exception ^ ex)
		{
			MessageBox::Show("Ошибка при загрузке!");
		}
	}
	private: System::Void buttonSearchOk_Click(System::Object^  sender, System::EventArgs^  e) {
		BindingList<Book^>^ found = gcnew BindingList<Book^>;

		for each (Book^ cur in books)
		{
			if (cur->Author == TBoxAuthorSearch->Text)
			{
				found->Add(cur);
			}
		}

		gridViewSearch->DataSource = found;
		gridViewSearch->Refresh();
	}
};
}