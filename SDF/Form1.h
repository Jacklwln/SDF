#pragma once

#include "ModelController.h"
#include "OpenGL.h"

namespace SDF {

	using namespace System;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace OpenGLForm;
	using namespace Controller;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			MController = new ModelController();
			InitializeComponent();
			OpenGL = gcnew COpenGL(this->panel1, MController);

			this->timer1->Enabled = true;
			MController->logInfo("Form Fully Loaded");
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
				delete OpenGL;
				delete MController;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		ModelController* MController;
		COpenGL^ OpenGL;

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  souborToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  otev��tToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator;
	private: System::Windows::Forms::ToolStripMenuItem^  ulo�itToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ulo�itjakoToolStripMenuItem;



	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
	private: System::Windows::Forms::ToolStripMenuItem^  ukon�itToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  upravitToolStripMenuItem;








	private: System::Windows::Forms::ToolStripMenuItem^  n�strojeToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  mo�nostiToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  n�pov�daToolStripMenuItem;




	private: System::Windows::Forms::ToolStripMenuItem^  oproduktuToolStripMenuItem;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::TextBox^  TB_Filename;
	private: System::Windows::Forms::Label^  LBL_Filename;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  LBL_SDF;
	private: System::Windows::Forms::TextBox^  TB_Triangle;
	private: System::Windows::Forms::Label^  LBL_Triangle;
	private: System::Windows::Forms::TextBox^  TB_Total;
	private: System::Windows::Forms::Label^  LBL_Total;

	private: System::Windows::Forms::ToolStripMenuItem^  vypo��tajSDFToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  octreeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sDFHodnotyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  wireframeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  normalToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pickingHodnotyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::ComponentModel::IContainer^  components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->souborToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->otev��tToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->ulo�itToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ulo�itjakoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->ukon�itToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->upravitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->normalToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->wireframeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sDFHodnotyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pickingHodnotyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->octreeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->n�strojeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->vypo��tajSDFToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mo�nostiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->n�pov�daToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->oproduktuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->TB_Total = (gcnew System::Windows::Forms::TextBox());
			this->LBL_Total = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->LBL_SDF = (gcnew System::Windows::Forms::Label());
			this->TB_Triangle = (gcnew System::Windows::Forms::TextBox());
			this->LBL_Triangle = (gcnew System::Windows::Forms::Label());
			this->TB_Filename = (gcnew System::Windows::Forms::TextBox());
			this->LBL_Filename = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->souborToolStripMenuItem, 
				this->upravitToolStripMenuItem, this->n�strojeToolStripMenuItem, this->n�pov�daToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(784, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// souborToolStripMenuItem
			// 
			this->souborToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->otev��tToolStripMenuItem, 
				this->toolStripSeparator, this->ulo�itToolStripMenuItem, this->ulo�itjakoToolStripMenuItem, this->toolStripSeparator2, this->ukon�itToolStripMenuItem});
			this->souborToolStripMenuItem->Name = L"souborToolStripMenuItem";
			this->souborToolStripMenuItem->Size = System::Drawing::Size(57, 20);
			this->souborToolStripMenuItem->Text = L"&Soubor";
			// 
			// otev��tToolStripMenuItem
			// 
			this->otev��tToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"otev��tToolStripMenuItem.Image")));
			this->otev��tToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->otev��tToolStripMenuItem->Name = L"otev��tToolStripMenuItem";
			this->otev��tToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->otev��tToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->otev��tToolStripMenuItem->Text = L"&Otev��t";
			this->otev��tToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::otev��tToolStripMenuItem_Click);
			// 
			// toolStripSeparator
			// 
			this->toolStripSeparator->Name = L"toolStripSeparator";
			this->toolStripSeparator->Size = System::Drawing::Size(150, 6);
			// 
			// ulo�itToolStripMenuItem
			// 
			this->ulo�itToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"ulo�itToolStripMenuItem.Image")));
			this->ulo�itToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->ulo�itToolStripMenuItem->Name = L"ulo�itToolStripMenuItem";
			this->ulo�itToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->ulo�itToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->ulo�itToolStripMenuItem->Text = L"&Ulo�it";
			// 
			// ulo�itjakoToolStripMenuItem
			// 
			this->ulo�itjakoToolStripMenuItem->Name = L"ulo�itjakoToolStripMenuItem";
			this->ulo�itjakoToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->ulo�itjakoToolStripMenuItem->Text = L"Ulo�it j&ako";
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(150, 6);
			// 
			// ukon�itToolStripMenuItem
			// 
			this->ukon�itToolStripMenuItem->Name = L"ukon�itToolStripMenuItem";
			this->ukon�itToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->ukon�itToolStripMenuItem->Text = L"U&kon�it";
			this->ukon�itToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::ukon�itToolStripMenuItem_Click);
			// 
			// upravitToolStripMenuItem
			// 
			this->upravitToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->normalToolStripMenuItem, 
				this->wireframeToolStripMenuItem, this->sDFHodnotyToolStripMenuItem, this->pickingHodnotyToolStripMenuItem, this->toolStripSeparator1, 
				this->octreeToolStripMenuItem});
			this->upravitToolStripMenuItem->Name = L"upravitToolStripMenuItem";
			this->upravitToolStripMenuItem->Size = System::Drawing::Size(63, 20);
			this->upravitToolStripMenuItem->Text = L"Zobrazi�";
			// 
			// normalToolStripMenuItem
			// 
			this->normalToolStripMenuItem->Name = L"normalToolStripMenuItem";
			this->normalToolStripMenuItem->Size = System::Drawing::Size(161, 22);
			this->normalToolStripMenuItem->Text = L"Normal";
			this->normalToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::normalToolStripMenuItem_Click);
			// 
			// wireframeToolStripMenuItem
			// 
			this->wireframeToolStripMenuItem->Name = L"wireframeToolStripMenuItem";
			this->wireframeToolStripMenuItem->Size = System::Drawing::Size(161, 22);
			this->wireframeToolStripMenuItem->Text = L"Wireframe";
			this->wireframeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::wireframeToolStripMenuItem_Click);
			// 
			// sDFHodnotyToolStripMenuItem
			// 
			this->sDFHodnotyToolStripMenuItem->Name = L"sDFHodnotyToolStripMenuItem";
			this->sDFHodnotyToolStripMenuItem->Size = System::Drawing::Size(161, 22);
			this->sDFHodnotyToolStripMenuItem->Text = L"SDF hodnoty";
			this->sDFHodnotyToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::sDFHodnotyToolStripMenuItem_Click);
			// 
			// pickingHodnotyToolStripMenuItem
			// 
			this->pickingHodnotyToolStripMenuItem->Name = L"pickingHodnotyToolStripMenuItem";
			this->pickingHodnotyToolStripMenuItem->Size = System::Drawing::Size(161, 22);
			this->pickingHodnotyToolStripMenuItem->Text = L"Picking hodnoty";
			this->pickingHodnotyToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::pickingHodnotyToolStripMenuItem_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(158, 6);
			// 
			// octreeToolStripMenuItem
			// 
			this->octreeToolStripMenuItem->Name = L"octreeToolStripMenuItem";
			this->octreeToolStripMenuItem->Size = System::Drawing::Size(161, 22);
			this->octreeToolStripMenuItem->Text = L"Octree";
			this->octreeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::octreeToolStripMenuItem_Click);
			// 
			// n�strojeToolStripMenuItem
			// 
			this->n�strojeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->vypo��tajSDFToolStripMenuItem, 
				this->mo�nostiToolStripMenuItem});
			this->n�strojeToolStripMenuItem->Name = L"n�strojeToolStripMenuItem";
			this->n�strojeToolStripMenuItem->Size = System::Drawing::Size(63, 20);
			this->n�strojeToolStripMenuItem->Text = L"&N�stroje";
			// 
			// vypo��tajSDFToolStripMenuItem
			// 
			this->vypo��tajSDFToolStripMenuItem->Name = L"vypo��tajSDFToolStripMenuItem";
			this->vypo��tajSDFToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			this->vypo��tajSDFToolStripMenuItem->Text = L"Vypo��taj SDF";
			// 
			// mo�nostiToolStripMenuItem
			// 
			this->mo�nostiToolStripMenuItem->Name = L"mo�nostiToolStripMenuItem";
			this->mo�nostiToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			this->mo�nostiToolStripMenuItem->Text = L"&Mo�nosti";
			// 
			// n�pov�daToolStripMenuItem
			// 
			this->n�pov�daToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->oproduktuToolStripMenuItem});
			this->n�pov�daToolStripMenuItem->Name = L"n�pov�daToolStripMenuItem";
			this->n�pov�daToolStripMenuItem->Size = System::Drawing::Size(73, 20);
			this->n�pov�daToolStripMenuItem->Text = L"&N�pov�da";
			// 
			// oproduktuToolStripMenuItem
			// 
			this->oproduktuToolStripMenuItem->Name = L"oproduktuToolStripMenuItem";
			this->oproduktuToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->oproduktuToolStripMenuItem->Text = L"&O produktu...";
			// 
			// timer1
			// 
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel1->Location = System::Drawing::Point(180, 27);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(604, 535);
			this->panel1->TabIndex = 1;
			this->panel1->Resize += gcnew System::EventHandler(this, &Form1::panel1_Resize);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->TB_Total);
			this->panel2->Controls->Add(this->LBL_Total);
			this->panel2->Controls->Add(this->textBox1);
			this->panel2->Controls->Add(this->LBL_SDF);
			this->panel2->Controls->Add(this->TB_Triangle);
			this->panel2->Controls->Add(this->LBL_Triangle);
			this->panel2->Controls->Add(this->TB_Filename);
			this->panel2->Controls->Add(this->LBL_Filename);
			this->panel2->Location = System::Drawing::Point(0, 27);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(174, 535);
			this->panel2->TabIndex = 2;
			// 
			// TB_Total
			// 
			this->TB_Total->Location = System::Drawing::Point(21, 75);
			this->TB_Total->Name = L"TB_Total";
			this->TB_Total->ReadOnly = true;
			this->TB_Total->Size = System::Drawing::Size(150, 20);
			this->TB_Total->TabIndex = 7;
			this->TB_Total->Text = L"0";
			// 
			// LBL_Total
			// 
			this->LBL_Total->AutoSize = true;
			this->LBL_Total->Location = System::Drawing::Point(18, 58);
			this->LBL_Total->Name = L"LBL_Total";
			this->LBL_Total->Size = System::Drawing::Size(77, 13);
			this->LBL_Total->TabIndex = 6;
			this->LBL_Total->Text = L"Total Triangles";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(21, 155);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(150, 20);
			this->textBox1->TabIndex = 5;
			this->textBox1->Text = L"0";
			// 
			// LBL_SDF
			// 
			this->LBL_SDF->AutoSize = true;
			this->LBL_SDF->Location = System::Drawing::Point(18, 138);
			this->LBL_SDF->Name = L"LBL_SDF";
			this->LBL_SDF->Size = System::Drawing::Size(58, 13);
			this->LBL_SDF->TabIndex = 4;
			this->LBL_SDF->Text = L"SDF Value";
			// 
			// TB_Triangle
			// 
			this->TB_Triangle->Location = System::Drawing::Point(21, 115);
			this->TB_Triangle->Name = L"TB_Triangle";
			this->TB_Triangle->ReadOnly = true;
			this->TB_Triangle->Size = System::Drawing::Size(150, 20);
			this->TB_Triangle->TabIndex = 3;
			this->TB_Triangle->Text = L"-1";
			// 
			// LBL_Triangle
			// 
			this->LBL_Triangle->AutoSize = true;
			this->LBL_Triangle->Location = System::Drawing::Point(18, 98);
			this->LBL_Triangle->Name = L"LBL_Triangle";
			this->LBL_Triangle->Size = System::Drawing::Size(104, 13);
			this->LBL_Triangle->TabIndex = 2;
			this->LBL_Triangle->Text = L"Selected Triangle ID";
			// 
			// TB_Filename
			// 
			this->TB_Filename->Location = System::Drawing::Point(21, 35);
			this->TB_Filename->Name = L"TB_Filename";
			this->TB_Filename->ReadOnly = true;
			this->TB_Filename->Size = System::Drawing::Size(150, 20);
			this->TB_Filename->TabIndex = 1;
			// 
			// LBL_Filename
			// 
			this->LBL_Filename->AutoSize = true;
			this->LBL_Filename->Location = System::Drawing::Point(18, 19);
			this->LBL_Filename->Name = L"LBL_Filename";
			this->LBL_Filename->Size = System::Drawing::Size(49, 13);
			this->LBL_Filename->TabIndex = 0;
			this->LBL_Filename->Text = L"Filename";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 562);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Shape Diameter Function";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

#pragma region Extra Functions

	private: System::Void SetOpenGLSize(int width, int height)
	{
		if(width<1) width = 1;
		if(height<1) height = 1;
		OpenGL->ResizeOpengl(width, height);
	}
	protected: virtual void Form1::WndProc(System::Windows::Forms::Message %m) override  
	{        
		if(m.Msg == WM_MOUSEWHEEL)  
		{
			OpenGL->WndProc(m);
		}
		System::Windows::Forms::Form::WndProc(m);  
	}

#pragma endregion

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		//timer
		OpenGL->Render();
		OpenGL->SwapOpenGLBuffers();
	}
	private: System::Void panel1_Resize(System::Object^  sender, System::EventArgs^  e)
	{
		if(this->timer1->Enabled == false)
			return;
		Control^ control = dynamic_cast<Control^>(sender);
		SetOpenGLSize(control->Size.Width, control->Size.Height);
	}
	private: System::Void otev��tToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		// Displays an OpenFileDialog so the user can select a model.
		OpenFileDialog ^openFileDialog1 = gcnew OpenFileDialog();
		openFileDialog1->Filter = "3D Model Files(*.OBJ)|*.OBJ|All files (*.*)|*.*";
		openFileDialog1->Title = "Select Model";

		// Show the Dialog.
		// If the user clicked OK in the dialog and
		// a .xml file was selected, open it.
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			MController->LoadFile(MarshalString(openFileDialog1->FileName));
			OpenGL->ReloadBoundary();
			this->TB_Filename->Text = openFileDialog1->FileName;
			this->TB_Total->Text = ""+MController->GetTriangleCount();

			MController->logInfo("File: "+ MarshalString(openFileDialog1->FileName) + " Loaded");
		}
	}
	private: System::Void ukon�itToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Application::Exit();
	}
	private: System::Void octreeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		MController->show_octree = (MController->show_octree == true ? false : true);
		MController->logInfo("Zobrazi� Octree");
	}
	private: System::Void wireframeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		MController->setDrawMode(3);
		MController->logInfo("Zobrazi� Wireframe");
	}
	private: System::Void normalToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		MController->setDrawMode(1);
		MController->logInfo("Zobrazi� Normal");
	}
	private: System::Void sDFHodnotyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		MController->setDrawMode(2);
		MController->logInfo("Zobrazi� SDF hodnoty");
	}
	private: System::Void pickingHodnotyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		MController->setDrawMode(0);
		MController->logInfo("Zobrazi� Picking hodnoty");
	}
};
}

