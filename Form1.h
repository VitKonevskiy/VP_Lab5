#pragma once

#define N 7
#include <fstream>
#include <stdio.h>
#include <vcclr.h>
#include <iostream>

namespace ex18 {



	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace System::IO;

	/// <summary>
	/// Summary for MyForm
	/// </summary>

	

				//кол-во вопросов

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		
	//const int N = 7;
	array<String^>^ args;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	public:

		ref struct TMark							//Класс для хранения оценки и ее описания
		{
		public:
			String^ str;
			int Mark;
		};

		ref class TVopros							//Класс описывающий вопрос, ответы на него, кол-во ответов, адрес картинки и т.д.
		{
		public:
			ref struct otvets
			{
				String ^otv;
			};
			int CountAnswer;			//Количесво вариантов ответа
			int TrueAnswer;				//Номер верного ответа
			bool HavePicture;			//есть ли картинка
			String^ vopros;				//Вопрос
			String^ NamePicture;		//Имя картинки
			array <otvets^>^ Answner;

			TVopros()
			{
				Answner = gcnew array<otvets^>(3);
				for (int i = 0; i < 3; i++)
				{
					Answner[i] = gcnew otvets;
				}
			}
		};


		array<TVopros^>^ Question;						//Массив для хранения вопросов


		int *level;			//кол-во правельных ответов
		String^ NameUser;	//Имя Пользователя
		int *otv;			//Номер выбранного ответа
		StreamReader^ stream;				//Для ввода из файла
		int *AnsUser;						//Массив для хранения ответов пользователя
		array<TMark^>^Marks;				//Массив для хранения оценок
		int Result;				//Переменная для вывода результатов
		int Clicker;			//Чтобы помнить, сколько раз мы кликаем по кнопке "Далее"
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label3;
	public:
		int right;			//кол-во правильных ответов
		MyForm(array<String^>^ _args)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			args = _args;
			level = new int[4];
			right = 0;
			stream = File::OpenText("Test.txt");
			otv = new int[N];
			AnsUser = new int[N];
			Question = gcnew array<TVopros^>(N);
			for (int i = 0; i < N; i++)
			{
				Question[i] = gcnew TVopros;
			}

			Marks = gcnew array<TMark^>(4);
			for (int i = 0; i < 4; i++)
			{
				Marks[i] = gcnew TMark;
			}

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(12, 9);
			this->label2->MaximumSize = System::Drawing::Size(620, 200);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(45, 19);
			this->label2->TabIndex = 0;
			this->label2->Text = L"label2";
			this->label2->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 75);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(384, 270);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 554);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Ok";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(16, 368);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(85, 17);
			this->radioButton1->TabIndex = 3;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"radioButton1";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(16, 412);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(85, 17);
			this->radioButton2->TabIndex = 4;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"radioButton2";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton2_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(16, 459);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(85, 17);
			this->radioButton3->TabIndex = 5;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"radioButton3";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton3_CheckedChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(206, 127);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(190, 20);
			this->textBox1->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(73, 131);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(127, 16);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Введите ваше имя";
			// 
			// MyForm
			// 
			this->ClientSize = System::Drawing::Size(634, 589);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label2);
			this->Name = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load_1);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		//Из System String в std::string
		/*void convert(String ^ s, std::string& os) {
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}

		int GetString(FILE *file, std::string * st)
		{
			 char buf[300];			//строка буфер
			//unsigned char *p = buf;			//указатель на строку
			char *estr;
			int n;							//Кол-во прочитанных байт
		//	int len = 0;					//длина строки

			while (feof(file))
			{
				estr = fgets(buf, sizeof(buf), file);
				break;//////

			}
			return 0;
		}
		*/

		private:
			int Parcer(String^ str,int nCh)
			{
				char Ch = str[nCh];
				return str[nCh]-'0';
			}

#pragma endregion
	private: System::Void MyForm_Load_1(System::Object^  sender, System::EventArgs^  e) {
		String ^tmp;
		this->Text = stream->ReadLine();
		this->label2->Text = stream->ReadLine();
		/*Считываем из файла название теста, оценки, сообщения для соответствующих оценок*/
		for (int i = 0; i < 4; i++)
		{
			Marks[i]->Mark = Convert::ToInt32(stream->ReadLine());
			Marks[i]->str = stream->ReadLine();
		}
		/*Считываем вопросы и все данные по ним(картинку и т.п.)*/
		for (int i = 0; i < N; i++)
		{
			Question[i]->vopros= stream->ReadLine();
			tmp= stream->ReadLine();
			Question[i]->CountAnswer = Parcer(tmp, 0);
			Question[i]->TrueAnswer = Parcer(tmp, 2);
			Question[i]->HavePicture = Parcer(tmp, 4);
			if (Question[i]->HavePicture)
			{
				Question[i]->NamePicture= stream->ReadLine();
			}
			for (int j = 0; j < Question[i]->CountAnswer; j++)
			{
				Question[i] ->Answner[j]->otv= stream->ReadLine();
			}
			
		}
		/*Прячем кнопки выбора*/
		this->radioButton1->Visible = false;
		this->radioButton2->Visible = false;
		this->radioButton3->Visible = false;
		this->radioButton1->Checked = false;
		this->radioButton2->Checked = false;
		this->radioButton3->Checked = false;
		Clicker = 0;

	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	/*Переименовывеваем кнопку ОК в "Далее"*/
	button1->Text = L"Далее";
	Image^ img;
	/*Если нажали на нее первый раз и при этом не было введено имя пользователя:*/
	if (Clicker == 0)
	{
		if (this->textBox1->Text == "")
		{
			MessageBox::Show("Вы не ввели имя пользователя!\n Будет использовано имя Unknown_User", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
			NameUser = "Unknown_User";
		}
		NameUser = this->textBox1->Text;
		this->label3->Visible = false;
		this->textBox1->Visible = false;
	}


	/*Запоминаем ответы пользователя для последующего вывода в файл*/
	if (this->radioButton1->Checked)
		AnsUser[Clicker-1] = 1;
	else if (this->radioButton2->Checked)
		AnsUser[Clicker-1] = 2;
	else if (this->radioButton3->Checked)
		AnsUser[Clicker-1] = 3;

	/*Если дошли до конца, то прячем варианты ответа для последнего вопроса, посчитываем кол-во правильно данных ответов, выводим результат*/
	if (Clicker == 7)
	{
		this->radioButton1->Visible = false;
		this->radioButton2->Visible = false;
		this->radioButton3->Visible = false;

		
		for (int i = 0; i < N; i++)
		{
			if (AnsUser[i] == Question[i]->TrueAnswer)
				Result++;
		}
		double PrecentResult = Result*100/7;
		MessageBox::Show("Тест Завершен. Поздравляем! Успешно выполнено: " + Convert::ToString(PrecentResult)+"%\n       Вы дали "+ Convert::ToString(Result)+" правильных ответа из 7", "Тест Завершен", MessageBoxButtons::OK, MessageBoxIcon::Information);

		if (Result == Marks[0]->Mark)
			this->label2->Text = Marks[0]->str;
		if (Result == Marks[1]->Mark)
			this->label2->Text = Marks[1]->str;
		if (Result == Marks[2]->Mark)
			this->label2->Text = Marks[2]->str;
		if (Result < Marks[3]->Mark+1)
			this->label2->Text = Marks[3]->str;
		/*Выводим данные о результате в файл*/
		StreamWriter^ sw = gcnew StreamWriter("Output.txt");
		String^ out;
		for (int i = 0; i < N; i++)
		{
			out += " " + Convert::ToString(AnsUser[i]) + " ";
		}
		sw->Write("Ответы, данные пользователем с именем: "+NameUser);
		sw->WriteLine(out);
		out = "";
		for (int i = 0; i < N; i++)
		{
			out += " " + Convert::ToString(Question[i]->TrueAnswer)+" ";
		}
		
		sw->Write("Верные ответы: ");
		sw->WriteLine(out);
		sw->WriteLine("Верно дали "+ Convert::ToString(Result) + " правильных ответа из 7. (" + Convert::ToString(PrecentResult) + "%)");
		sw->Close();
	}
	else
		/*Если это не последний клик и не первый, то выполняем само тестирование:*/
	{
		/*Берем первый вопрос*/
		this->label2->Text = Question[Clicker]->vopros;
		/*Имеет ли от картинку? Если да - отрисовываем, если нет - скрываем поле с картинкой с глаз пользователя*/
		if (Question[Clicker]->HavePicture)
		{
			img = Image::FromFile(Question[Clicker]->NamePicture);
			this->pictureBox1->Image = img;
			this->pictureBox1->Visible = true;
		}
		else
		{
			this->pictureBox1->Visible = false;
		}
		/*Выводим варианты ответа*/
		this->radioButton1->Text = Question[Clicker]->Answner[0]->otv;
		this->radioButton2->Text = Question[Clicker]->Answner[1]->otv;
		if (Question[Clicker]->CountAnswer == 3)
		{
			this->radioButton3->Text = Question[Clicker]->Answner[2]->otv;
			this->radioButton3->Visible = true;
		}
		else
		{
			this->radioButton3->Visible = false;
		}
		this->radioButton1->Visible = true;
		this->radioButton2->Visible = true;
		
		this->radioButton1->Checked = false;
		this->radioButton2->Checked = false;
		this->radioButton3->Checked = false;
		this->button1->Enabled = false;
		Clicker++;
	}


}
private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	this->button1->Enabled = true;
}
private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	this->button1->Enabled = true;
}
private: System::Void radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	this->button1->Enabled = true;
}
};



}




