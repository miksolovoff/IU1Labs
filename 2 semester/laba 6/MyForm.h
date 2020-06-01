#pragma once
#include <string>
#include <sstream>
#include <math.h>
namespace LabaVI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ operand_a_box;
	protected:

	protected:

	protected:
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ operand_a_name;
	private: System::Windows::Forms::Label^ res_name;
	private: System::Windows::Forms::TextBox^ res_box;
	private: System::Windows::Forms::Button^ res_button;
	private: System::Windows::Forms::Label^ operand_b_name;
	private: System::Windows::Forms::TextBox^ operand_b_box;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ operation_type_box;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ operation_type1_name;
	private: System::Windows::Forms::TextBox^ res1_box;
	private: System::Windows::Forms::Button^ res1_button;
	private: System::Windows::Forms::TextBox^ operation_type1_box;
	private: System::Windows::Forms::TextBox^ operand_x_box;
	private: System::Windows::Forms::Label^ res1_name;
	private: System::Windows::Forms::Label^ operand_x_name;


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
			this->operand_a_box = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->res_name = (gcnew System::Windows::Forms::Label());
			this->res_box = (gcnew System::Windows::Forms::TextBox());
			this->res_button = (gcnew System::Windows::Forms::Button());
			this->operand_b_name = (gcnew System::Windows::Forms::Label());
			this->operand_b_box = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->operation_type_box = (gcnew System::Windows::Forms::TextBox());
			this->operand_a_name = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->res1_name = (gcnew System::Windows::Forms::Label());
			this->operand_x_name = (gcnew System::Windows::Forms::Label());
			this->operation_type1_name = (gcnew System::Windows::Forms::Label());
			this->res1_box = (gcnew System::Windows::Forms::TextBox());
			this->res1_button = (gcnew System::Windows::Forms::Button());
			this->operation_type1_box = (gcnew System::Windows::Forms::TextBox());
			this->operand_x_box = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// operand_a_box
			// 
			this->operand_a_box->Location = System::Drawing::Point(6, 19);
			this->operand_a_box->Name = L"operand_a_box";
			this->operand_a_box->Size = System::Drawing::Size(118, 20);
			this->operand_a_box->TabIndex = 0;
			this->operand_a_box->TextChanged += gcnew System::EventHandler(this, &MyForm::operand_a_box_TextChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->res_name);
			this->groupBox1->Controls->Add(this->res_box);
			this->groupBox1->Controls->Add(this->res_button);
			this->groupBox1->Controls->Add(this->operand_b_name);
			this->groupBox1->Controls->Add(this->operand_b_box);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->operation_type_box);
			this->groupBox1->Controls->Add(this->operand_a_name);
			this->groupBox1->Controls->Add(this->operand_a_box);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 203);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Два операнда";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &MyForm::groupBox1_Enter);
			// 
			// res_name
			// 
			this->res_name->AutoSize = true;
			this->res_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->res_name->Location = System::Drawing::Point(130, 168);
			this->res_name->Name = L"res_name";
			this->res_name->Size = System::Drawing::Size(19, 18);
			this->res_name->TabIndex = 8;
			this->res_name->Text = L"C";
			// 
			// res_box
			// 
			this->res_box->Location = System::Drawing::Point(6, 166);
			this->res_box->Name = L"res_box";
			this->res_box->Size = System::Drawing::Size(118, 20);
			this->res_box->TabIndex = 7;
			this->res_box->TextChanged += gcnew System::EventHandler(this, &MyForm::res_box_TextChanged);
			// 
			// res_button
			// 
			this->res_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->res_button->Location = System::Drawing::Point(27, 126);
			this->res_button->Name = L"res_button";
			this->res_button->Size = System::Drawing::Size(75, 23);
			this->res_button->TabIndex = 6;
			this->res_button->Text = L"=";
			this->res_button->UseVisualStyleBackColor = true;
			this->res_button->Click += gcnew System::EventHandler(this, &MyForm::res_button_Click);
			// 
			// operand_b_name
			// 
			this->operand_b_name->AutoSize = true;
			this->operand_b_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->operand_b_name->Location = System::Drawing::Point(130, 91);
			this->operand_b_name->Name = L"operand_b_name";
			this->operand_b_name->Size = System::Drawing::Size(18, 18);
			this->operand_b_name->TabIndex = 5;
			this->operand_b_name->Text = L"B";
			// 
			// operand_b_box
			// 
			this->operand_b_box->Location = System::Drawing::Point(6, 89);
			this->operand_b_box->Name = L"operand_b_box";
			this->operand_b_box->Size = System::Drawing::Size(118, 20);
			this->operand_b_box->TabIndex = 4;
			this->operand_b_box->TextChanged += gcnew System::EventHandler(this, &MyForm::operand_b_box_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(130, 59);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(65, 15);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Операция";
			// 
			// operation_type_box
			// 
			this->operation_type_box->Location = System::Drawing::Point(6, 54);
			this->operation_type_box->Name = L"operation_type_box";
			this->operation_type_box->Size = System::Drawing::Size(118, 20);
			this->operation_type_box->TabIndex = 2;
			this->operation_type_box->TextChanged += gcnew System::EventHandler(this, &MyForm::operation_type_box_TextChanged);
			// 
			// operand_a_name
			// 
			this->operand_a_name->AutoSize = true;
			this->operand_a_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->operand_a_name->Location = System::Drawing::Point(130, 21);
			this->operand_a_name->Name = L"operand_a_name";
			this->operand_a_name->Size = System::Drawing::Size(17, 18);
			this->operand_a_name->TabIndex = 1;
			this->operand_a_name->Text = L"A";
			this->operand_a_name->Click += gcnew System::EventHandler(this, &MyForm::operand_a_name_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->res1_name);
			this->groupBox2->Controls->Add(this->operand_x_name);
			this->groupBox2->Controls->Add(this->operation_type1_name);
			this->groupBox2->Controls->Add(this->res1_box);
			this->groupBox2->Controls->Add(this->res1_button);
			this->groupBox2->Controls->Add(this->operation_type1_box);
			this->groupBox2->Controls->Add(this->operand_x_box);
			this->groupBox2->Location = System::Drawing::Point(230, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(200, 203);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Один операнд";
			// 
			// res1_name
			// 
			this->res1_name->AutoSize = true;
			this->res1_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->res1_name->Location = System::Drawing::Point(129, 168);
			this->res1_name->Name = L"res1_name";
			this->res1_name->Size = System::Drawing::Size(17, 18);
			this->res1_name->TabIndex = 6;
			this->res1_name->Text = L"Y";
			// 
			// operand_x_name
			// 
			this->operand_x_name->AutoSize = true;
			this->operand_x_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->operand_x_name->Location = System::Drawing::Point(129, 82);
			this->operand_x_name->Name = L"operand_x_name";
			this->operand_x_name->Size = System::Drawing::Size(18, 18);
			this->operand_x_name->TabIndex = 5;
			this->operand_x_name->Text = L"X";
			// 
			// operation_type1_name
			// 
			this->operation_type1_name->AutoSize = true;
			this->operation_type1_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->operation_type1_name->Location = System::Drawing::Point(129, 41);
			this->operation_type1_name->Name = L"operation_type1_name";
			this->operation_type1_name->Size = System::Drawing::Size(65, 15);
			this->operation_type1_name->TabIndex = 4;
			this->operation_type1_name->Text = L"Операция";
			// 
			// res1_box
			// 
			this->res1_box->Location = System::Drawing::Point(6, 166);
			this->res1_box->Name = L"res1_box";
			this->res1_box->Size = System::Drawing::Size(118, 20);
			this->res1_box->TabIndex = 3;
			this->res1_box->TextChanged += gcnew System::EventHandler(this, &MyForm::res1_box_TextChanged);
			// 
			// res1_button
			// 
			this->res1_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->res1_button->Location = System::Drawing::Point(32, 126);
			this->res1_button->Name = L"res1_button";
			this->res1_button->Size = System::Drawing::Size(75, 23);
			this->res1_button->TabIndex = 2;
			this->res1_button->Text = L"=";
			this->res1_button->UseVisualStyleBackColor = true;
			this->res1_button->Click += gcnew System::EventHandler(this, &MyForm::res1_button_Click);
			// 
			// operation_type1_box
			// 
			this->operation_type1_box->Location = System::Drawing::Point(6, 36);
			this->operation_type1_box->Name = L"operation_type1_box";
			this->operation_type1_box->Size = System::Drawing::Size(118, 20);
			this->operation_type1_box->TabIndex = 1;
			this->operation_type1_box->TextChanged += gcnew System::EventHandler(this, &MyForm::operation_type1_box_TextChanged);
			// 
			// operand_x_box
			// 
			this->operand_x_box->Location = System::Drawing::Point(6, 80);
			this->operand_x_box->Name = L"operand_x_box";
			this->operand_x_box->Size = System::Drawing::Size(118, 20);
			this->operand_x_box->TabIndex = 0;
			this->operand_x_box->TextChanged += gcnew System::EventHandler(this, &MyForm::operand_x_box_TextChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(514, 230);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"MyForm";
			this->Text = L"Калькулятор";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
		void MarshalString(String^ s, std::string& os) {
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}
		std::string TypeToStr(const double& rhs) {
			std::stringstream ss;
			ss << rhs;
			return ss.str();
		}
		bool DoubleChecker(std::string num) {
			bool flag = true;
			int points = 0;
			if (num[0] != '-' && (num[0] < '0' || num[0]>'9')) flag = false;
			else {
				for (int i = 1; i < num.size(); i++) {
					if (num[i] == ',') {
						points++;
						if (points > 1) {
							flag = false;
							break;
						}
					}
					else if (num[i] < '0' || num[i]>'9') {
						flag = false;
						break;
					}
				}
			}
			return flag;
		}
		bool OperationChecker(std::string o) {
			return o == "+" || o == "-" || o == "*" || o == ":" || o == "^" ? true : false;
		}
#pragma endregion
	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void operand_a_name_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void operand_a_box_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void operand_b_box_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void operation_type_box_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void res_box_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void res_button_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string a, b, op;
	MarshalString(operand_a_box->Text, a);
	MarshalString(operand_b_box->Text, b);
	MarshalString(operation_type_box->Text, op);
	if (!DoubleChecker(a) || !DoubleChecker(b) || !OperationChecker(op)) {
		MessageBox::Show("Error!\nCheck the textbox for correctness!");
	}
	else {
		double a_d = Convert::ToDouble(operand_a_box->Text);
		double b_d = Convert::ToDouble(operand_b_box->Text);
		if (op == "+") {
			res_box->Text = gcnew System::String(TypeToStr(a_d + b_d).c_str());
		}
		if (op == "-") {
			res_box->Text = gcnew System::String(TypeToStr(a_d - b_d).c_str());
		}
		if (op == "*") {
			res_box->Text = gcnew System::String(TypeToStr(a_d * b_d).c_str());
		}
		if (op == ":") {
			if (b_d==0.) MessageBox::Show("Error!\nСheck textbox for operand B for 0!");
			else res_box->Text = gcnew System::String(TypeToStr(a_d/b_d).c_str());
		}
		if (op == "^") {
			double c_d = pow(a_d, b_d);
			if (errno == EDOM) MessageBox::Show("Error!\nCheck the textbox for correctness:\nA<=0!");
			else res_box->Text = gcnew System::String(TypeToStr(c_d).c_str());
		}
	}
}
private: System::Void operation_type1_box_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void operand_x_box_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void res1_box_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void res1_button_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string x, op;
	MarshalString(operand_x_box->Text, x);
	MarshalString(operation_type1_box->Text, op);
	if (!DoubleChecker(x) || (op != "sin" && op != "cos" && op != "exp")) {
		MessageBox::Show("Error!\nCheck the textbox for correctness!");
	}
	else {
		double x_d = Convert::ToDouble(operand_x_box->Text);
		if (op == "sin") {
			res1_box->Text = gcnew System::String(TypeToStr(sin(x_d)).c_str());
		}
		if (op == "cos") {
			res1_box->Text = gcnew System::String(TypeToStr(cos(x_d)).c_str());
		}
		if (op == "exp") {
			res1_box->Text = gcnew System::String(TypeToStr(exp(x_d)).c_str());
		}
	}
}
};
}
