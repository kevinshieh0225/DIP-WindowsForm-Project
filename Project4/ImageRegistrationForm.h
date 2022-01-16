#pragma once
#include <string>
#include <math.h>
#include <sstream>
#include <iomanip>

#define PI acos(-1)

namespace DIP_HW1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace System::Collections::Generic;

	/// <summary>
	/// ImageRegistrationForm 的摘要
	/// </summary>
	public ref class ImageRegistrationForm : public System::Windows::Forms::Form{
	public:
		ImageRegistrationForm(void){
			InitializeComponent();
		}
		ImageRegistrationForm(Bitmap ^ openImg) {
			InitializeComponent();
			OriginImg = openImg;
			OriginPicBox->Image = OriginImg;
		}

	protected:
		~ImageRegistrationForm(){
			if (components) delete components;
		}

	private: int stage = 1;
	private: Bitmap ^ OriginImg;
	private: Bitmap ^ ProcessImg;
	private: Bitmap ^ ResultImg;
	private: List<Point> OriginLocation;
	private: List<Point> RegisLocation;
	private: float Scaling = 0;
	private: float Angle = 0;
	private: float IntensityDiff = 0;

	private: System::Windows::Forms::PictureBox^  OriginPicBox;
	private: System::Windows::Forms::PictureBox^  ProcessPicBox;
	private: System::Windows::Forms::PictureBox^  ResultPicBox;
	private: System::Windows::Forms::Label^  Instructions;
	private: System::Windows::Forms::Button^  LoadRegisButton;

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;



	protected:

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->OriginPicBox = (gcnew System::Windows::Forms::PictureBox());
			this->ProcessPicBox = (gcnew System::Windows::Forms::PictureBox());
			this->ResultPicBox = (gcnew System::Windows::Forms::PictureBox());
			this->Instructions = (gcnew System::Windows::Forms::Label());
			this->LoadRegisButton = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OriginPicBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ProcessPicBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ResultPicBox))->BeginInit();
			this->SuspendLayout();
			// 
			// OriginPicBox
			// 
			this->OriginPicBox->Location = System::Drawing::Point(29, 12);
			this->OriginPicBox->Name = L"OriginPicBox";
			this->OriginPicBox->Size = System::Drawing::Size(596, 419);
			this->OriginPicBox->TabIndex = 0;
			this->OriginPicBox->TabStop = false;
			this->OriginPicBox->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &ImageRegistrationForm::OriginPicBox_Paint);
			this->OriginPicBox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ImageRegistrationForm::OriginPicBox_MouseClick);
			// 
			// ProcessPicBox
			// 
			this->ProcessPicBox->Location = System::Drawing::Point(29, 438);
			this->ProcessPicBox->Name = L"ProcessPicBox";
			this->ProcessPicBox->Size = System::Drawing::Size(596, 419);
			this->ProcessPicBox->TabIndex = 1;
			this->ProcessPicBox->TabStop = false;
			this->ProcessPicBox->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &ImageRegistrationForm::ProcessPicBox_Paint);
			this->ProcessPicBox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ImageRegistrationForm::ProcessPicBox_MouseClick);
			// 
			// ResultPicBox
			// 
			this->ResultPicBox->Location = System::Drawing::Point(654, 438);
			this->ResultPicBox->Name = L"ResultPicBox";
			this->ResultPicBox->Size = System::Drawing::Size(596, 420);
			this->ResultPicBox->TabIndex = 2;
			this->ResultPicBox->TabStop = false;
			// 
			// Instructions
			// 
			this->Instructions->AutoSize = true;
			this->Instructions->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Instructions->Location = System::Drawing::Point(698, 141);
			this->Instructions->Name = L"Instructions";
			this->Instructions->Size = System::Drawing::Size(202, 27);
			this->Instructions->TabIndex = 3;
			this->Instructions->Text = L"1. 請載入欲調整圖片";
			// 
			// LoadRegisButton
			// 
			this->LoadRegisButton->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->LoadRegisButton->Location = System::Drawing::Point(703, 191);
			this->LoadRegisButton->Name = L"LoadRegisButton";
			this->LoadRegisButton->Size = System::Drawing::Size(78, 34);
			this->LoadRegisButton->TabIndex = 4;
			this->LoadRegisButton->Text = L"Load";
			this->LoadRegisButton->UseVisualStyleBackColor = true;
			this->LoadRegisButton->Click += gcnew System::EventHandler(this, &ImageRegistrationForm::LoadRegisButton_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// ImageRegistrationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1283, 868);
			this->Controls->Add(this->LoadRegisButton);
			this->Controls->Add(this->Instructions);
			this->Controls->Add(this->ResultPicBox);
			this->Controls->Add(this->ProcessPicBox);
			this->Controls->Add(this->OriginPicBox);
			this->Name = L"ImageRegistrationForm";
			this->Text = L"ImageRegistrationForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OriginPicBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ProcessPicBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ResultPicBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	// 
	// Tool Box
	// 
	private: float getAngle(int x1, int y1, int x2, int y2) {
		float InnerProduct = x1 * x2 + y1 * y2;
		float CrossProduct = x1 * y2 - y1 * x2;
		return atan2(CrossProduct, InnerProduct);
	}
	private: float getDistance(int x1, int y1, int x2, int y2) {
		return sqrt(pow((x2 - x1),2) + pow((y2 - y1),2));
	}
	private: float getDistance(Point A, Point B) {
		return (float)(sqrt(pow((A.X - B.X), 2) + pow((A.Y - B.Y), 2)));
	}
	private: string Float2String(float A) {
		std::stringstream stream;
		stream << std::fixed << std::setprecision(2) << A;
		return stream.str();
	}
	// 
	// Flow
	// 
	private: System::Void LoadRegisButton_Click(System::Object^  sender, System::EventArgs^  e) {
		if (stage == 1) {
			if (this->openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				ProcessImg = gcnew Bitmap(openFileDialog1->FileName);
				ProcessPicBox->Image = ProcessImg;
				LoadRegisButton->Text = L"Undo";
				Instructions->Text = L"2. 請於圖片（一）進行點選四點";
				stage = 2;
			}
		}
		else if (stage == 2 || stage == 3) {
			stage = 2;
			OriginLocation.Clear();  RegisLocation.Clear();
			Instructions->Text = L"2. 請於圖片（一）進行點選四點";
		}
		else if (stage == 4) {
			ResultImg = gcnew Bitmap(OriginImg->Width, OriginImg->Height);
			//int ShiftX = OriginImg->Width / 2 - ProcessImg->Width / 2;
			//int ShiftY = OriginImg->Height / 2 - ProcessImg->Height / 2;
			processRotateScaling();
			this->IntensityDiff = IntensityDifference();
			ResultPicBox->Image = ResultImg;
			std::string text = "5. Intensity difference: ";
			text += Float2String(this->IntensityDiff);
			Instructions->Text = gcnew String(text.c_str());
			LoadRegisButton->Text = L"Save";
			stage = 5;
		}
		else if (stage == 5) {
			SaveFileDialog ^ saveFileDialog1 = gcnew SaveFileDialog();
			saveFileDialog1->Filter = "JPeg Image|*.jpg|Bitmap Image|*.bmp|Gif Image|*.gif";
			saveFileDialog1->Title = "Save an Image File";
			if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				String^ sfd = saveFileDialog1->FileName;
				ResultPicBox->Image->Save(sfd, System::Drawing::Imaging::ImageFormat::Jpeg);
			}
		}
	}

	private: System::Void OriginPicBox_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		for (int i = 0; i < OriginLocation.Count; i++) {
			Graphics ^ g = e->Graphics;
			// Create a new pen that we shall use for drawing the line
			Pen^ PenStyle = gcnew Pen(Color::DimGray, 1);
			// Draw a 50x50 pixels rectangle (x, y, width, hight)
			g->DrawEllipse(PenStyle, OriginLocation[i].X-5, OriginLocation[i].Y-5, 10, 10);
		}
	}
	private: System::Void OriginPicBox_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (stage == 2) {
			Point coordinates = e->Location;
			OriginLocation.Add(coordinates);
			OriginPicBox -> Invalidate();
			if (OriginLocation.Count == 4) {
				Instructions->Text = L"3. 請於圖片（二）進行點選四點";
				stage = 3;
			}
		}
	}
	private: System::Void ProcessPicBox_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		for (int i = 0; i < RegisLocation.Count; i++) {
			Graphics ^ g = e->Graphics;
			// Create a new pen that we shall use for drawing the line
			Pen^ PenStyle = gcnew Pen(Color::DimGray, 1);
			// Draw a 50x50 pixels rectangle (x, y, width, hight)
			g->DrawEllipse(PenStyle, RegisLocation[i].X-5, RegisLocation[i].Y-5, 10, 10);
		}
	}
	private: System::Void ProcessPicBox_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (stage == 3) {
			Point coordinates = e->Location;
			RegisLocation.Add(coordinates);
			ProcessPicBox->Invalidate();
			if (RegisLocation.Count == 4) {
			//Check if the two shape is similar
				//check Edge
				float EdgeScale_1 = getDistance(OriginLocation[0], OriginLocation[1]) / getDistance(RegisLocation[0], RegisLocation[1]);
				float EdgeScale_2 = getDistance(OriginLocation[1], OriginLocation[2]) / getDistance(RegisLocation[1], RegisLocation[2]);
				float EdgeScale_3 = getDistance(OriginLocation[2], OriginLocation[3]) / getDistance(RegisLocation[2], RegisLocation[3]);
				float EdgeScale_4 = getDistance(OriginLocation[3], OriginLocation[0]) / getDistance(RegisLocation[3], RegisLocation[0]);
				float DiagonalScale = getDistance(OriginLocation[0], OriginLocation[2]) / getDistance(RegisLocation[0], RegisLocation[2]);
				if ((abs(EdgeScale_1 - EdgeScale_2) < 0.1) && (abs(EdgeScale_2 - EdgeScale_3) < 0.1)
					&& (abs(EdgeScale_3 - EdgeScale_4) < 0.1) && (abs(EdgeScale_4 - EdgeScale_1) < 0.1) && (abs(DiagonalScale - EdgeScale_4) < 0.1)) {
					//getScaling
					this->Scaling = (float)pow(EdgeScale_1*EdgeScale_2*EdgeScale_3*EdgeScale_4, 0.25);
					//getAngle
					int checkX1 = OriginLocation[1].X - OriginLocation[0].X;
					int checkY1 = OriginLocation[1].Y - OriginLocation[0].Y;
					int checkX2 = RegisLocation[1].X - RegisLocation[0].X;
					int checkY2 = RegisLocation[1].Y - RegisLocation[0].Y;
					
					this->Angle = getAngle(checkX2, checkY2, checkX1, checkY1);

					std::string text = "4. 進行調整：縮放 ";
					text += Float2String(this->Scaling);
					text += "倍   旋轉 ";
					float angle = (float)(this->Angle * 180 / PI);
					text += Float2String(angle);
					text += "度";
					Instructions->Text = gcnew String(text.c_str());
					stage = 4;
					LoadRegisButton->Text = L"Start"; LoadRegisButton->Visible = true;
				}
				else {
					std::string text = "3. 兩圖比例有誤：";
					Instructions->Text = gcnew String(text.c_str());
					RegisLocation.Clear();
				}
			}
		}
	}
	
	private: void processRotateScaling() {
		int ShiftX = ResultImg->Width /2;	int ShiftY = ResultImg->Height/2;
		float COS = cos(-(this->Angle));
		float SIN = sin(-(this->Angle));
		//Iterate through ResultImg to get the projection point on ProcessImg
		for (int i = 0; i < ResultImg->Width; i++) {
			for (int j = 0; j < ResultImg->Height; j++) {
				int new_x = (int)(((i - ShiftX) * COS - (j - ShiftY) * SIN) / this->Scaling + ProcessImg->Width / 2);
				int new_y = (int)(((i - ShiftX) * SIN + (j - ShiftY) * COS) / this->Scaling + ProcessImg->Height/2);
				if (new_x >= 0 && new_y >= 0 && new_x < ProcessImg->Width && new_y < ProcessImg->Height)
					ResultImg->SetPixel(i, j, ProcessImg->GetPixel(new_x, new_y));
				else ResultImg->SetPixel(i, j, Color::FromArgb(0, 0, 0));
			}
		}
	}
	private: float IntensityDifference() {
		float Diff = 0;
		for (int i = 0; i < ResultImg->Width; i++) {
			for (int j = 0; j < ResultImg->Height; j++) {
				Diff += abs(OriginImg->GetPixel(i, j).R - ResultImg->GetPixel(i, j).R);
			}
		}
		return Diff / (ResultImg->Width*ResultImg->Height);
	}


};
}
