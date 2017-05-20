#pragma once

#include "Book.h"
#include "EditForm.h"

namespace OOP_Kurs {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::TextBox^  pagesTBox;
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

	protected:

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
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->pagesLabel = (gcnew System::Windows::Forms::Label());
			this->authorLabel = (gcnew System::Windows::Forms::Label());
			this->nameTBox = (gcnew System::Windows::Forms::TextBox());
			this->pagesTBox = (gcnew System::Windows::Forms::TextBox());
			this->authorTBox = (gcnew System::Windows::Forms::TextBox());
			this->booksTabControl = (gcnew System::Windows::Forms::TabControl());
			this->tabPageList = (gcnew System::Windows::Forms::TabPage());
			this->btnDel = (gcnew System::Windows::Forms::Button());
			this->btnEdit = (gcnew System::Windows::Forms::Button());
			this->tabPageAdd = (gcnew System::Windows::Forms::TabPage());
			this->columnName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnAuthor = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnPages = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->columnGenre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->comboBoxGenre = (gcnew System::Windows::Forms::ComboBox());
			this->labelGenre = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->booksGridView))->BeginInit();
			this->booksTabControl->SuspendLayout();
			this->tabPageList->SuspendLayout();
			this->tabPageAdd->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnAdd
			// 
			this->btnAdd->Location = System::Drawing::Point(223, 307);
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
			this->bookNameLabel->Location = System::Drawing::Point(65, 52);
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
			this->booksGridView->Size = System::Drawing::Size(464, 295);
			this->booksGridView->TabIndex = 2;
			// 
			// pagesLabel
			// 
			this->pagesLabel->AutoSize = true;
			this->pagesLabel->Location = System::Drawing::Point(65, 90);
			this->pagesLabel->Name = L"pagesLabel";
			this->pagesLabel->Size = System::Drawing::Size(110, 13);
			this->pagesLabel->TabIndex = 3;
			this->pagesLabel->Text = L"Количество страниц";
			// 
			// authorLabel
			// 
			this->authorLabel->AutoSize = true;
			this->authorLabel->Location = System::Drawing::Point(65, 119);
			this->authorLabel->Name = L"authorLabel";
			this->authorLabel->Size = System::Drawing::Size(37, 13);
			this->authorLabel->TabIndex = 4;
			this->authorLabel->Text = L"Автор";
			// 
			// nameTBox
			// 
			this->nameTBox->Location = System::Drawing::Point(172, 52);
			this->nameTBox->Name = L"nameTBox";
			this->nameTBox->Size = System::Drawing::Size(100, 20);
			this->nameTBox->TabIndex = 5;
			// 
			// pagesTBox
			// 
			this->pagesTBox->Location = System::Drawing::Point(198, 83);
			this->pagesTBox->Name = L"pagesTBox";
			this->pagesTBox->Size = System::Drawing::Size(100, 20);
			this->pagesTBox->TabIndex = 6;
			// 
			// authorTBox
			// 
			this->authorTBox->Location = System::Drawing::Point(139, 112);
			this->authorTBox->Name = L"authorTBox";
			this->authorTBox->Size = System::Drawing::Size(100, 20);
			this->authorTBox->TabIndex = 7;
			// 
			// booksTabControl
			// 
			this->booksTabControl->Controls->Add(this->tabPageList);
			this->booksTabControl->Controls->Add(this->tabPageAdd);
			this->booksTabControl->Location = System::Drawing::Point(1, 1);
			this->booksTabControl->Name = L"booksTabControl";
			this->booksTabControl->SelectedIndex = 0;
			this->booksTabControl->Size = System::Drawing::Size(588, 484);
			this->booksTabControl->TabIndex = 8;
			// 
			// tabPageList
			// 
			this->tabPageList->Controls->Add(this->btnDel);
			this->tabPageList->Controls->Add(this->btnEdit);
			this->tabPageList->Controls->Add(this->booksGridView);
			this->tabPageList->Location = System::Drawing::Point(4, 22);
			this->tabPageList->Name = L"tabPageList";
			this->tabPageList->Padding = System::Windows::Forms::Padding(3);
			this->tabPageList->Size = System::Drawing::Size(580, 458);
			this->tabPageList->TabIndex = 0;
			this->tabPageList->Text = L"Список";
			this->tabPageList->UseVisualStyleBackColor = true;
			// 
			// btnDel
			// 
			this->btnDel->Location = System::Drawing::Point(249, 368);
			this->btnDel->Name = L"btnDel";
			this->btnDel->Size = System::Drawing::Size(75, 23);
			this->btnDel->TabIndex = 4;
			this->btnDel->Text = L"Удалить";
			this->btnDel->UseVisualStyleBackColor = true;
			this->btnDel->Click += gcnew System::EventHandler(this, &MainForm::btnDel_Click);
			// 
			// btnEdit
			// 
			this->btnEdit->Location = System::Drawing::Point(99, 368);
			this->btnEdit->Name = L"btnEdit";
			this->btnEdit->Size = System::Drawing::Size(75, 23);
			this->btnEdit->TabIndex = 3;
			this->btnEdit->Text = L"Изменить";
			this->btnEdit->UseVisualStyleBackColor = true;
			this->btnEdit->Click += gcnew System::EventHandler(this, &MainForm::btnEdit_Click);
			// 
			// tabPageAdd
			// 
			this->tabPageAdd->Controls->Add(this->labelGenre);
			this->tabPageAdd->Controls->Add(this->comboBoxGenre);
			this->tabPageAdd->Controls->Add(this->bookNameLabel);
			this->tabPageAdd->Controls->Add(this->btnAdd);
			this->tabPageAdd->Controls->Add(this->authorTBox);
			this->tabPageAdd->Controls->Add(this->pagesLabel);
			this->tabPageAdd->Controls->Add(this->pagesTBox);
			this->tabPageAdd->Controls->Add(this->authorLabel);
			this->tabPageAdd->Controls->Add(this->nameTBox);
			this->tabPageAdd->Location = System::Drawing::Point(4, 22);
			this->tabPageAdd->Name = L"tabPageAdd";
			this->tabPageAdd->Padding = System::Windows::Forms::Padding(3);
			this->tabPageAdd->Size = System::Drawing::Size(580, 458);
			this->tabPageAdd->TabIndex = 1;
			this->tabPageAdd->Text = L"Добавить";
			this->tabPageAdd->UseVisualStyleBackColor = true;
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
			// comboBoxGenre
			// 
			this->comboBoxGenre->FormattingEnabled = true;
			this->comboBoxGenre->Location = System::Drawing::Point(139, 156);
			this->comboBoxGenre->Name = L"comboBoxGenre";
			this->comboBoxGenre->Size = System::Drawing::Size(121, 21);
			this->comboBoxGenre->TabIndex = 8;
			this->comboBoxGenre->Items->Add("Роман");
			this->comboBoxGenre->Items->Add("Фантастика");
			this->comboBoxGenre->Items->Add("Триллер");
			// 
			// labelGenre
			// 
			this->labelGenre->AutoSize = true;
			this->labelGenre->Location = System::Drawing::Point(65, 159);
			this->labelGenre->Name = L"labelGenre";
			this->labelGenre->Size = System::Drawing::Size(36, 13);
			this->labelGenre->TabIndex = 9;
			this->labelGenre->Text = L"Жанр";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(653, 538);
			this->Controls->Add(this->booksTabControl);
			this->Name = L"MainForm";
			this->Text = L"Книги";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->booksGridView))->EndInit();
			this->booksTabControl->ResumeLayout(false);
			this->tabPageList->ResumeLayout(false);
			this->tabPageAdd->ResumeLayout(false);
			this->tabPageAdd->PerformLayout();
			this->ResumeLayout(false);

		}

#pragma endregion


	private:

		System::Void btnAdd_Click(System::Object^  sender, System::EventArgs^  e) {
			Book^ newBook = gcnew Book();
			int pages = 0;
			pages = Convert::ToInt32(pagesTBox->Text);
			newBook->input(pages, nameTBox->Text, authorTBox->Text, comboBoxGenre->Text);
			books->Add(newBook);
			pagesTBox->Text = "";
			nameTBox->Text = "";
			authorTBox->Text = "";
			comboBoxGenre->Text = "";
		}

		System::Void btnEdit_Click(System::Object^  sender, System::EventArgs^  e) {
			Book^ book = (Book^)booksGridView->CurrentRow->DataBoundItem;
			EditForm^ formEdit = gcnew EditForm(book);
			formEdit->ShowDialog();
			formEdit->Edit();
		}

		System::Void btnDel_Click(System::Object^  sender, System::EventArgs^  e) {
			booksGridView->Rows->Remove(booksGridView->CurrentRow);
		}
	};
}