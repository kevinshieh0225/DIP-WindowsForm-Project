#pragma once
#include "ImageRegistrationForm.h"
#include <vector>
#include <map>
#include <ctype.h>
#include <msclr\marshal_cppstd.h>
#include <stdlib.h>     /* srand, rand */
#include <queue>


namespace DIP_HW1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form{
	public:
		MyForm(void){
			InitializeComponent();
		}
	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm(){
			if (components) delete components;
		}

	private: Bitmap^ openImg;
	private: Bitmap^ processImg;
	private: System::Windows::Forms::Button^  ExtractionRButton;
	private: System::Windows::Forms::Button^  ExtractionGButton;
	private: System::Windows::Forms::Button^  ExtractionBButton;
	private: System::Windows::Forms::Button^  GrayscaleButton;
	private: System::Windows::Forms::GroupBox^  ExtractionBox;
	private: System::Windows::Forms::Button^  MedianFilterButton;
	private: System::Windows::Forms::Button^  MeanFilterButton;
	private: System::Windows::Forms::GroupBox^  SmoothFilterBox;
	private: System::Windows::Forms::GroupBox^  EqualizationBox;
	private: System::Windows::Forms::Button^  HistogramEqualizationButton;
	private: System::Windows::Forms::GroupBox^  ThresholdingBox;
	private: System::Windows::Forms::TextBox^  ThresholdText;
	private: System::Windows::Forms::Button^  ThresholdEnterButton;
	private: System::Windows::Forms::GroupBox^  SobelEdgeBox;
	private: System::Windows::Forms::Button^  VerticalButton;
	private: System::Windows::Forms::Button^  HorizontalButton;
	private: System::Windows::Forms::Button^  CombinedButton;
	private: System::Windows::Forms::GroupBox^  EdgeOverlapBox;
	private: System::Windows::Forms::TextBox^  EdgeText;
	private: System::Windows::Forms::Button^  EdgeEnterButton;
	private: System::Windows::Forms::GroupBox^  ImageRegistrationBox;
	private: System::Windows::Forms::Button^  ImageRegistrationButton;
	private: System::Windows::Forms::Button^  LoadButton;
	private: System::Windows::Forms::Button^  SaveButton;
	private: System::Windows::Forms::Button^  UndoButton;
	private: System::Windows::Forms::PictureBox^  SourceImageBox;
	private: System::Windows::Forms::PictureBox^  ProcessImageBox;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  SourceHistoChart;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  ProcessHistoChart;
	private: System::Windows::Forms::GroupBox^  ConnectedComponentBox;
	private: System::Windows::Forms::Button^  ClusterButton;
	private: System::Windows::Forms::TextBox^  UpperBoundText;

	private: System::Windows::Forms::TextBox^  LowerBoundText;


	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->ExtractionRButton = (gcnew System::Windows::Forms::Button());
			this->ExtractionGButton = (gcnew System::Windows::Forms::Button());
			this->ExtractionBButton = (gcnew System::Windows::Forms::Button());
			this->GrayscaleButton = (gcnew System::Windows::Forms::Button());
			this->ExtractionBox = (gcnew System::Windows::Forms::GroupBox());
			this->MedianFilterButton = (gcnew System::Windows::Forms::Button());
			this->MeanFilterButton = (gcnew System::Windows::Forms::Button());
			this->SmoothFilterBox = (gcnew System::Windows::Forms::GroupBox());
			this->EqualizationBox = (gcnew System::Windows::Forms::GroupBox());
			this->UpperBoundText = (gcnew System::Windows::Forms::TextBox());
			this->LowerBoundText = (gcnew System::Windows::Forms::TextBox());
			this->HistogramEqualizationButton = (gcnew System::Windows::Forms::Button());
			this->ThresholdingBox = (gcnew System::Windows::Forms::GroupBox());
			this->ThresholdText = (gcnew System::Windows::Forms::TextBox());
			this->ThresholdEnterButton = (gcnew System::Windows::Forms::Button());
			this->SobelEdgeBox = (gcnew System::Windows::Forms::GroupBox());
			this->VerticalButton = (gcnew System::Windows::Forms::Button());
			this->HorizontalButton = (gcnew System::Windows::Forms::Button());
			this->CombinedButton = (gcnew System::Windows::Forms::Button());
			this->EdgeOverlapBox = (gcnew System::Windows::Forms::GroupBox());
			this->EdgeText = (gcnew System::Windows::Forms::TextBox());
			this->EdgeEnterButton = (gcnew System::Windows::Forms::Button());
			this->ImageRegistrationBox = (gcnew System::Windows::Forms::GroupBox());
			this->ImageRegistrationButton = (gcnew System::Windows::Forms::Button());
			this->LoadButton = (gcnew System::Windows::Forms::Button());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->UndoButton = (gcnew System::Windows::Forms::Button());
			this->SourceImageBox = (gcnew System::Windows::Forms::PictureBox());
			this->ProcessImageBox = (gcnew System::Windows::Forms::PictureBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SourceHistoChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->ProcessHistoChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->ConnectedComponentBox = (gcnew System::Windows::Forms::GroupBox());
			this->ClusterButton = (gcnew System::Windows::Forms::Button());
			this->ExtractionBox->SuspendLayout();
			this->SmoothFilterBox->SuspendLayout();
			this->EqualizationBox->SuspendLayout();
			this->ThresholdingBox->SuspendLayout();
			this->SobelEdgeBox->SuspendLayout();
			this->EdgeOverlapBox->SuspendLayout();
			this->ImageRegistrationBox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SourceImageBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ProcessImageBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SourceHistoChart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ProcessHistoChart))->BeginInit();
			this->ConnectedComponentBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// ExtractionRButton
			// 
			this->ExtractionRButton->Location = System::Drawing::Point(31, 14);
			this->ExtractionRButton->Name = L"ExtractionRButton";
			this->ExtractionRButton->Size = System::Drawing::Size(75, 23);
			this->ExtractionRButton->TabIndex = 0;
			this->ExtractionRButton->Text = L"R";
			this->ExtractionRButton->UseVisualStyleBackColor = true;
			this->ExtractionRButton->Click += gcnew System::EventHandler(this, &MyForm::ExtractionRButton_Click);
			// 
			// ExtractionGButton
			// 
			this->ExtractionGButton->Location = System::Drawing::Point(136, 14);
			this->ExtractionGButton->Name = L"ExtractionGButton";
			this->ExtractionGButton->Size = System::Drawing::Size(75, 23);
			this->ExtractionGButton->TabIndex = 1;
			this->ExtractionGButton->Text = L"G";
			this->ExtractionGButton->UseVisualStyleBackColor = true;
			this->ExtractionGButton->Click += gcnew System::EventHandler(this, &MyForm::ExtractionGButton_Click);
			// 
			// ExtractionBButton
			// 
			this->ExtractionBButton->Location = System::Drawing::Point(31, 43);
			this->ExtractionBButton->Name = L"ExtractionBButton";
			this->ExtractionBButton->Size = System::Drawing::Size(75, 23);
			this->ExtractionBButton->TabIndex = 2;
			this->ExtractionBButton->Text = L"B";
			this->ExtractionBButton->UseVisualStyleBackColor = true;
			this->ExtractionBButton->Click += gcnew System::EventHandler(this, &MyForm::ExtractionBButton_Click);
			// 
			// GrayscaleButton
			// 
			this->GrayscaleButton->Location = System::Drawing::Point(136, 43);
			this->GrayscaleButton->Name = L"GrayscaleButton";
			this->GrayscaleButton->Size = System::Drawing::Size(75, 23);
			this->GrayscaleButton->TabIndex = 3;
			this->GrayscaleButton->Text = L"Grayscale";
			this->GrayscaleButton->UseVisualStyleBackColor = true;
			this->GrayscaleButton->Click += gcnew System::EventHandler(this, &MyForm::GrayscaleButton_Click);
			// 
			// ExtractionBox
			// 
			this->ExtractionBox->Controls->Add(this->GrayscaleButton);
			this->ExtractionBox->Controls->Add(this->ExtractionGButton);
			this->ExtractionBox->Controls->Add(this->ExtractionRButton);
			this->ExtractionBox->Controls->Add(this->ExtractionBButton);
			this->ExtractionBox->Location = System::Drawing::Point(31, 21);
			this->ExtractionBox->Name = L"ExtractionBox";
			this->ExtractionBox->Size = System::Drawing::Size(233, 77);
			this->ExtractionBox->TabIndex = 4;
			this->ExtractionBox->TabStop = false;
			this->ExtractionBox->Text = L"Extraction";
			// 
			// MedianFilterButton
			// 
			this->MedianFilterButton->Location = System::Drawing::Point(136, 21);
			this->MedianFilterButton->Name = L"MedianFilterButton";
			this->MedianFilterButton->Size = System::Drawing::Size(75, 23);
			this->MedianFilterButton->TabIndex = 8;
			this->MedianFilterButton->Text = L"Median Filter";
			this->MedianFilterButton->UseVisualStyleBackColor = true;
			this->MedianFilterButton->Click += gcnew System::EventHandler(this, &MyForm::MedianFilterButton_Click);
			// 
			// MeanFilterButton
			// 
			this->MeanFilterButton->Location = System::Drawing::Point(31, 21);
			this->MeanFilterButton->Name = L"MeanFilterButton";
			this->MeanFilterButton->Size = System::Drawing::Size(75, 23);
			this->MeanFilterButton->TabIndex = 7;
			this->MeanFilterButton->Text = L"Mean Filter";
			this->MeanFilterButton->UseVisualStyleBackColor = true;
			this->MeanFilterButton->Click += gcnew System::EventHandler(this, &MyForm::MeanFilterButton_Click);
			// 
			// SmoothFilterBox
			// 
			this->SmoothFilterBox->Controls->Add(this->MeanFilterButton);
			this->SmoothFilterBox->Controls->Add(this->MedianFilterButton);
			this->SmoothFilterBox->Location = System::Drawing::Point(31, 119);
			this->SmoothFilterBox->Name = L"SmoothFilterBox";
			this->SmoothFilterBox->Size = System::Drawing::Size(233, 61);
			this->SmoothFilterBox->TabIndex = 9;
			this->SmoothFilterBox->TabStop = false;
			this->SmoothFilterBox->Text = L"Smooth Filter";
			// 
			// EqualizationBox
			// 
			this->EqualizationBox->Controls->Add(this->UpperBoundText);
			this->EqualizationBox->Controls->Add(this->LowerBoundText);
			this->EqualizationBox->Controls->Add(this->HistogramEqualizationButton);
			this->EqualizationBox->Location = System::Drawing::Point(31, 201);
			this->EqualizationBox->Name = L"EqualizationBox";
			this->EqualizationBox->Size = System::Drawing::Size(233, 63);
			this->EqualizationBox->TabIndex = 10;
			this->EqualizationBox->TabStop = false;
			this->EqualizationBox->Text = L"Histogram Equalization";
			// 
			// UpperBoundText
			// 
			this->UpperBoundText->Location = System::Drawing::Point(82, 21);
			this->UpperBoundText->Name = L"UpperBoundText";
			this->UpperBoundText->Size = System::Drawing::Size(54, 22);
			this->UpperBoundText->TabIndex = 15;
			this->UpperBoundText->Text = L"255";
			// 
			// LowerBoundText
			// 
			this->LowerBoundText->Location = System::Drawing::Point(22, 21);
			this->LowerBoundText->Name = L"LowerBoundText";
			this->LowerBoundText->Size = System::Drawing::Size(54, 22);
			this->LowerBoundText->TabIndex = 14;
			this->LowerBoundText->Text = L"0";
			// 
			// HistogramEqualizationButton
			// 
			this->HistogramEqualizationButton->Location = System::Drawing::Point(147, 21);
			this->HistogramEqualizationButton->Name = L"HistogramEqualizationButton";
			this->HistogramEqualizationButton->Size = System::Drawing::Size(75, 23);
			this->HistogramEqualizationButton->TabIndex = 8;
			this->HistogramEqualizationButton->Text = L"Equalization";
			this->HistogramEqualizationButton->UseVisualStyleBackColor = true;
			this->HistogramEqualizationButton->Click += gcnew System::EventHandler(this, &MyForm::HistogramEqualizationButton_Click);
			// 
			// ThresholdingBox
			// 
			this->ThresholdingBox->Controls->Add(this->ThresholdText);
			this->ThresholdingBox->Controls->Add(this->ThresholdEnterButton);
			this->ThresholdingBox->Location = System::Drawing::Point(31, 285);
			this->ThresholdingBox->Name = L"ThresholdingBox";
			this->ThresholdingBox->Size = System::Drawing::Size(233, 59);
			this->ThresholdingBox->TabIndex = 11;
			this->ThresholdingBox->TabStop = false;
			this->ThresholdingBox->Text = L"Thresholding";
			// 
			// ThresholdText
			// 
			this->ThresholdText->Location = System::Drawing::Point(22, 22);
			this->ThresholdText->Name = L"ThresholdText";
			this->ThresholdText->Size = System::Drawing::Size(111, 22);
			this->ThresholdText->TabIndex = 13;
			this->ThresholdText->Text = L"150";
			// 
			// ThresholdEnterButton
			// 
			this->ThresholdEnterButton->Location = System::Drawing::Point(147, 21);
			this->ThresholdEnterButton->Name = L"ThresholdEnterButton";
			this->ThresholdEnterButton->Size = System::Drawing::Size(76, 23);
			this->ThresholdEnterButton->TabIndex = 8;
			this->ThresholdEnterButton->Text = L"Enter";
			this->ThresholdEnterButton->UseVisualStyleBackColor = true;
			this->ThresholdEnterButton->Click += gcnew System::EventHandler(this, &MyForm::ThresholdEnterButton_Click);
			// 
			// SobelEdgeBox
			// 
			this->SobelEdgeBox->Controls->Add(this->VerticalButton);
			this->SobelEdgeBox->Controls->Add(this->HorizontalButton);
			this->SobelEdgeBox->Controls->Add(this->CombinedButton);
			this->SobelEdgeBox->Location = System::Drawing::Point(31, 364);
			this->SobelEdgeBox->Name = L"SobelEdgeBox";
			this->SobelEdgeBox->Size = System::Drawing::Size(233, 57);
			this->SobelEdgeBox->TabIndex = 14;
			this->SobelEdgeBox->TabStop = false;
			this->SobelEdgeBox->Text = L"Sobel Edge Detection";
			// 
			// VerticalButton
			// 
			this->VerticalButton->Location = System::Drawing::Point(6, 21);
			this->VerticalButton->Name = L"VerticalButton";
			this->VerticalButton->Size = System::Drawing::Size(70, 23);
			this->VerticalButton->TabIndex = 10;
			this->VerticalButton->Text = L"Vertical";
			this->VerticalButton->UseVisualStyleBackColor = true;
			this->VerticalButton->Click += gcnew System::EventHandler(this, &MyForm::VerticalButton_Click);
			// 
			// HorizontalButton
			// 
			this->HorizontalButton->Location = System::Drawing::Point(81, 21);
			this->HorizontalButton->Name = L"HorizontalButton";
			this->HorizontalButton->Size = System::Drawing::Size(70, 23);
			this->HorizontalButton->TabIndex = 9;
			this->HorizontalButton->Text = L"Horizontal";
			this->HorizontalButton->UseVisualStyleBackColor = true;
			this->HorizontalButton->Click += gcnew System::EventHandler(this, &MyForm::HorizontalButton_Click);
			// 
			// CombinedButton
			// 
			this->CombinedButton->Location = System::Drawing::Point(157, 21);
			this->CombinedButton->Name = L"CombinedButton";
			this->CombinedButton->Size = System::Drawing::Size(70, 23);
			this->CombinedButton->TabIndex = 8;
			this->CombinedButton->Text = L"Combined";
			this->CombinedButton->UseVisualStyleBackColor = true;
			this->CombinedButton->Click += gcnew System::EventHandler(this, &MyForm::CombinedButton_Click);
			// 
			// EdgeOverlapBox
			// 
			this->EdgeOverlapBox->Controls->Add(this->EdgeText);
			this->EdgeOverlapBox->Controls->Add(this->EdgeEnterButton);
			this->EdgeOverlapBox->Location = System::Drawing::Point(31, 445);
			this->EdgeOverlapBox->Name = L"EdgeOverlapBox";
			this->EdgeOverlapBox->Size = System::Drawing::Size(233, 59);
			this->EdgeOverlapBox->TabIndex = 14;
			this->EdgeOverlapBox->TabStop = false;
			this->EdgeOverlapBox->Text = L"Edge Overlapping";
			// 
			// EdgeText
			// 
			this->EdgeText->Location = System::Drawing::Point(22, 21);
			this->EdgeText->Name = L"EdgeText";
			this->EdgeText->Size = System::Drawing::Size(111, 22);
			this->EdgeText->TabIndex = 13;
			this->EdgeText->Text = L"150";
			// 
			// EdgeEnterButton
			// 
			this->EdgeEnterButton->Location = System::Drawing::Point(147, 21);
			this->EdgeEnterButton->Name = L"EdgeEnterButton";
			this->EdgeEnterButton->Size = System::Drawing::Size(76, 23);
			this->EdgeEnterButton->TabIndex = 8;
			this->EdgeEnterButton->Text = L"Enter";
			this->EdgeEnterButton->UseVisualStyleBackColor = true;
			this->EdgeEnterButton->Click += gcnew System::EventHandler(this, &MyForm::EdgeEnterButton_Click);
			// 
			// ImageRegistrationBox
			// 
			this->ImageRegistrationBox->Controls->Add(this->ImageRegistrationButton);
			this->ImageRegistrationBox->Location = System::Drawing::Point(31, 606);
			this->ImageRegistrationBox->Name = L"ImageRegistrationBox";
			this->ImageRegistrationBox->Size = System::Drawing::Size(233, 63);
			this->ImageRegistrationBox->TabIndex = 11;
			this->ImageRegistrationBox->TabStop = false;
			this->ImageRegistrationBox->Text = L"Image Registration";
			// 
			// ImageRegistrationButton
			// 
			this->ImageRegistrationButton->Location = System::Drawing::Point(22, 21);
			this->ImageRegistrationButton->Name = L"ImageRegistrationButton";
			this->ImageRegistrationButton->Size = System::Drawing::Size(189, 23);
			this->ImageRegistrationButton->TabIndex = 8;
			this->ImageRegistrationButton->Text = L"Image Registration";
			this->ImageRegistrationButton->UseVisualStyleBackColor = true;
			this->ImageRegistrationButton->Click += gcnew System::EventHandler(this, &MyForm::ImageRegistrationButton_Click);
			// 
			// LoadButton
			// 
			this->LoadButton->Location = System::Drawing::Point(37, 694);
			this->LoadButton->Name = L"LoadButton";
			this->LoadButton->Size = System::Drawing::Size(70, 23);
			this->LoadButton->TabIndex = 13;
			this->LoadButton->Text = L"Load";
			this->LoadButton->UseVisualStyleBackColor = true;
			this->LoadButton->Click += gcnew System::EventHandler(this, &MyForm::LoadButton_Click);
			// 
			// SaveButton
			// 
			this->SaveButton->Location = System::Drawing::Point(113, 694);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(70, 23);
			this->SaveButton->TabIndex = 12;
			this->SaveButton->Text = L"Save";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &MyForm::SaveButton_Click);
			// 
			// UndoButton
			// 
			this->UndoButton->Location = System::Drawing::Point(189, 694);
			this->UndoButton->Name = L"UndoButton";
			this->UndoButton->Size = System::Drawing::Size(70, 23);
			this->UndoButton->TabIndex = 11;
			this->UndoButton->Text = L"Undo";
			this->UndoButton->UseVisualStyleBackColor = true;
			this->UndoButton->Click += gcnew System::EventHandler(this, &MyForm::UndoButton_Click);
			// 
			// SourceImageBox
			// 
			this->SourceImageBox->Location = System::Drawing::Point(465, 12);
			this->SourceImageBox->Name = L"SourceImageBox";
			this->SourceImageBox->Size = System::Drawing::Size(616, 409);
			this->SourceImageBox->TabIndex = 15;
			this->SourceImageBox->TabStop = false;
			// 
			// ProcessImageBox
			// 
			this->ProcessImageBox->Location = System::Drawing::Point(465, 441);
			this->ProcessImageBox->Name = L"ProcessImageBox";
			this->ProcessImageBox->Size = System::Drawing::Size(616, 409);
			this->ProcessImageBox->TabIndex = 16;
			this->ProcessImageBox->TabStop = false;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// SourceHistoChart
			// 
			chartArea1->Name = L"ChartArea1";
			this->SourceHistoChart->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->SourceHistoChart->Legends->Add(legend1);
			this->SourceHistoChart->Location = System::Drawing::Point(1200, 90);
			this->SourceHistoChart->Name = L"SourceHistoChart";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"pixel";
			this->SourceHistoChart->Series->Add(series1);
			this->SourceHistoChart->Size = System::Drawing::Size(350, 239);
			this->SourceHistoChart->TabIndex = 19;
			this->SourceHistoChart->Text = L"chart1";
			// 
			// ProcessHistoChart
			// 
			chartArea2->Name = L"ChartArea1";
			this->ProcessHistoChart->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->ProcessHistoChart->Legends->Add(legend2);
			this->ProcessHistoChart->Location = System::Drawing::Point(1200, 479);
			this->ProcessHistoChart->Name = L"ProcessHistoChart";
			series2->ChartArea = L"ChartArea1";
			series2->Legend = L"Legend1";
			series2->Name = L"pixel";
			this->ProcessHistoChart->Series->Add(series2);
			this->ProcessHistoChart->Size = System::Drawing::Size(350, 238);
			this->ProcessHistoChart->TabIndex = 20;
			this->ProcessHistoChart->Text = L"chart2";
			// 
			// ConnectedComponentBox
			// 
			this->ConnectedComponentBox->Controls->Add(this->ClusterButton);
			this->ConnectedComponentBox->Location = System::Drawing::Point(31, 520);
			this->ConnectedComponentBox->Name = L"ConnectedComponentBox";
			this->ConnectedComponentBox->Size = System::Drawing::Size(233, 63);
			this->ConnectedComponentBox->TabIndex = 12;
			this->ConnectedComponentBox->TabStop = false;
			this->ConnectedComponentBox->Text = L"Connected Component";
			// 
			// ClusterButton
			// 
			this->ClusterButton->Location = System::Drawing::Point(22, 21);
			this->ClusterButton->Name = L"ClusterButton";
			this->ClusterButton->Size = System::Drawing::Size(189, 23);
			this->ClusterButton->TabIndex = 8;
			this->ClusterButton->Text = L"Cluster";
			this->ClusterButton->UseVisualStyleBackColor = true;
			this->ClusterButton->Click += gcnew System::EventHandler(this, &MyForm::ClusterButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1654, 862);
			this->Controls->Add(this->ConnectedComponentBox);
			this->Controls->Add(this->ProcessHistoChart);
			this->Controls->Add(this->SourceHistoChart);
			this->Controls->Add(this->ProcessImageBox);
			this->Controls->Add(this->SourceImageBox);
			this->Controls->Add(this->LoadButton);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->ImageRegistrationBox);
			this->Controls->Add(this->UndoButton);
			this->Controls->Add(this->EdgeOverlapBox);
			this->Controls->Add(this->SobelEdgeBox);
			this->Controls->Add(this->ThresholdingBox);
			this->Controls->Add(this->EqualizationBox);
			this->Controls->Add(this->SmoothFilterBox);
			this->Controls->Add(this->ExtractionBox);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ExtractionBox->ResumeLayout(false);
			this->SmoothFilterBox->ResumeLayout(false);
			this->EqualizationBox->ResumeLayout(false);
			this->EqualizationBox->PerformLayout();
			this->ThresholdingBox->ResumeLayout(false);
			this->ThresholdingBox->PerformLayout();
			this->SobelEdgeBox->ResumeLayout(false);
			this->EdgeOverlapBox->ResumeLayout(false);
			this->EdgeOverlapBox->PerformLayout();
			this->ImageRegistrationBox->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SourceImageBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ProcessImageBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SourceHistoChart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ProcessHistoChart))->EndInit();
			this->ConnectedComponentBox->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void LoadButton_Click(System::Object^  sender, System::EventArgs^  e) {
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			openImg = gcnew Bitmap(openFileDialog1->FileName);
			processImg = resetBitmap();
			SourceImageBox->Image = openImg;
			ProcessImageBox->Image = processImg;
			setHistogramChart(SourceHistoChart, openImg);
			setHistogramChart(ProcessHistoChart, processImg);
		}
	}
	private: System::Void SaveButton_Click(System::Object^  sender, System::EventArgs^  e) {
		SaveFileDialog ^ saveFileDialog1 = gcnew SaveFileDialog();
		saveFileDialog1->Filter = "JPeg Image|*.jpg|Bitmap Image|*.bmp|Gif Image|*.gif";
		saveFileDialog1->Title = "Save an Image File";
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			String^ sfd = saveFileDialog1->FileName;
			ProcessImageBox->Image->Save(sfd, System::Drawing::Imaging::ImageFormat::Jpeg);
		}
	}
	private: System::Void UndoButton_Click(System::Object^  sender, System::EventArgs^  e) {
		processImg = resetBitmap();
		ProcessImageBox->Image = processImg;
	}
/*
	Tool Box.
*/
	private: Bitmap^ resetBitmap() {
		Bitmap^ temp = gcnew Bitmap(openImg->Width,openImg->Height);
		for (int i = 0; i < openImg->Width; i++) {
			for (int j = 0; j < openImg->Height; j++)
				temp->SetPixel(i, j, openImg->GetPixel(i, j));
		}
		return temp;
	}
	private: bool checkIsGrayScale(Bitmap^ Img) {
		for (int i = 0; i < 10; i++) {
			int randomX = rand() % Img->Width;
			int randomY = rand() % Img->Height;
			if (Img->GetPixel(randomX, randomY).R != Img->GetPixel(randomX, randomY).G || 
				Img->GetPixel(randomX, randomY).R != Img->GetPixel(randomX, randomY).B) return false;
		}
		return true;
	}
	private: int returnGrayPixel(Color pixel) {
		return  (pixel.R + pixel.G + pixel.B) / 3;
	}
	private: Color returnGrayColor(int pixel) {
		return  Color::FromArgb(pixel, pixel, pixel);
	}
	private: vector<int> returnHistogram(Bitmap^ image) {
		vector<int> Histogram(256, 0);
		int i, j, pixel;
		for (i = 0; i < image->Width; i++) {
			for (j = 0; j < image->Height; j++) {
				pixel = returnGrayPixel(image->GetPixel(i, j));
				Histogram[pixel] += 1;
			}
		}
		return Histogram;
	}
	private: void setHistogramChart(System::Windows::Forms::DataVisualization::Charting::Chart^ histochart, Bitmap^ image) {
		vector<int> SourceHisto = returnHistogram(image);
		histochart->Series["pixel"]->Points->Clear();
		for (unsigned int i = 0; i < SourceHisto.size(); i++) histochart->Series["pixel"]->Points->AddXY(i, SourceHisto[i]);
	}
	private: bool check_number(System::String^ Str) {
		std::string str = msclr::interop::marshal_as<std::string>(Str);
		int i = 0;
		for (unsigned int i = 0; i < str.length(); i++)
			if (isdigit(str[i]) == false)
				return false;
		return true;
	}
	private: Bitmap^ returnVerticalSobel(int threshold) {
		if (threshold < 0) threshold = 150;
		Bitmap^ temp = gcnew Bitmap(processImg->Width,processImg->Height);
		vector<vector<int>> VerticalFilter = { {1,2,1},{0,0,0},{-1,-2,-1} };
		for (int i = 0; i < temp->Width; i++) {
			for (int j = 0; j < temp->Height; j++) {
				int pixel = 0;
				if ((i > 0) && (i < temp->Width - 1) && (j > 0) && (j < temp->Height - 1)) {
					for (int k = -1; k <= 1; k++) {
						for (int l = -1; l <= 1; l++) {
							if ((i + k >= 0) && (i + k < temp->Width) && (j + l >= 0) && (j + l < temp->Height))
								pixel += (returnGrayPixel(processImg->GetPixel(i + k, j + l)) * VerticalFilter[k + 1][l + 1]);
						}
					}
					if (abs(pixel) > threshold) pixel = 255;
					else pixel = 0;
				}
				else pixel = returnGrayPixel(processImg->GetPixel(i, j));
				Color newColor = returnGrayColor(pixel);
				temp->SetPixel(i, j, newColor);
			}
		}
		return temp;
	}
	private: Bitmap^ returnHorizontalSobel(int threshold) {
		if (threshold < 0) threshold = 150;
		Bitmap^ temp = gcnew Bitmap(processImg->Width, processImg->Height);
		vector<vector<int>> HorizontalFilter = { {1,0,-1},{2,0,-2},{1,0,-1} };
		for (int i = 0; i < temp->Width; i++) {
			for (int j = 0; j < temp->Height; j++) {
				int pixel = 0;
				if ((i > 0) && (i < temp->Width - 1) && (j > 0) && (j < temp->Height - 1)) {
					for (int k = -1; k <= 1; k++) {
						for (int l = -1; l <= 1; l++) {
							if ((i + k >= 0) && (i + k < temp->Width) && (j + l >= 0) && (j + l < temp->Height))
								pixel += (returnGrayPixel(processImg->GetPixel(i + k, j + l)) * HorizontalFilter[k + 1][l + 1]);
						}
					}
					if (abs(pixel) > threshold) pixel = 255;
					else pixel = 0;
				}
				else pixel = returnGrayPixel(processImg->GetPixel(i, j));
				Color newColor = returnGrayColor(pixel);
				temp->SetPixel(i, j, newColor);
			}
		}
		return temp;
	}
	private: Bitmap^ returnSobelfilter(int threshhold) {
		Bitmap^ Vertical = returnVerticalSobel(threshhold);
		Bitmap^ Horizontal = returnHorizontalSobel(threshhold);
		Bitmap^ Combined = gcnew Bitmap(processImg->Width, processImg->Height);
		for (int i = 0; i < Vertical->Width; i++) {
			for (int j = 0; j < Vertical->Height; j++) {
				if (!(returnGrayPixel(Vertical->GetPixel(i, j)) || returnGrayPixel(Horizontal->GetPixel(i, j)))) Combined->SetPixel(i, j, returnGrayColor(0));
				else Combined->SetPixel(i, j, returnGrayColor(255));
			}
		}
		return Combined;
	}
	private: Color RandColor() {
		int R = (rand() % 254) + 1;
		int G = (rand() % 254) + 1;
		int B = (rand() % 254) + 1;
		return Color::FromArgb(R, G, B);
	}
/*
	First Homework.
*/

	private: System::Void ExtractionRButton_Click(System::Object^  sender, System::EventArgs^  e) {
		// Loop through the images pixels to reset color.
		if (!checkIsGrayScale(processImg)) {
			for (int i = 0; i < processImg->Width; i++) {
				for (int j = 0; j < processImg->Height; j++) {
					int pixelColor = processImg->GetPixel(i, j).R;
					Color newColor = Color::FromArgb(pixelColor, pixelColor, pixelColor);
					processImg->SetPixel(i, j, newColor); // Now greyscale
				}
			}
			setHistogramChart(ProcessHistoChart, processImg);
			ProcessImageBox->Image = processImg;
		}
	}
	private: System::Void ExtractionGButton_Click(System::Object^  sender, System::EventArgs^  e) {
		// Loop through the images pixels to reset color.
		if (!checkIsGrayScale(processImg)) {
			for (int i = 0; i < processImg->Width; i++) {
				for (int j = 0; j < processImg->Height; j++) {
					int pixelColor = processImg->GetPixel(i, j).G;
					Color newColor = Color::FromArgb(pixelColor, pixelColor, pixelColor);
					processImg->SetPixel(i, j, newColor); // Now greyscale
				}
			}
			setHistogramChart(ProcessHistoChart, processImg);
			ProcessImageBox->Image = processImg;
		}
	}
	private: System::Void ExtractionBButton_Click(System::Object^  sender, System::EventArgs^  e) {
		// Loop through the images pixels to reset color.
		if (!checkIsGrayScale(processImg)) {
			for (int i = 0; i < processImg->Width; i++) {
				for (int j = 0; j < processImg->Height; j++) {
					int pixelColor = openImg->GetPixel(i, j).B;
					Color newColor = Color::FromArgb(pixelColor, pixelColor, pixelColor);
					processImg->SetPixel(i, j, newColor); // Now grayscale
				}
			}
			setHistogramChart(ProcessHistoChart, processImg);
			ProcessImageBox->Image = processImg;
		}
	}
	private: System::Void GrayscaleButton_Click(System::Object^  sender, System::EventArgs^  e) {
		// Loop through the images pixels to reset color.
		if (!checkIsGrayScale(processImg)) {
			for (int i = 0; i < processImg->Width; i++) {
				for (int j = 0; j < processImg->Height; j++) {
					int gray = returnGrayPixel(processImg->GetPixel(i, j));
					Color newColor = returnGrayColor(gray);
					processImg->SetPixel(i, j, newColor); // Now greyscale
				}
			}
			setHistogramChart(ProcessHistoChart, processImg);
			ProcessImageBox->Image = processImg;
		}
	}
/*
	Second Homework.
*/
private: System::Void MeanFilterButton_Click(System::Object^  sender, System::EventArgs^  e) {
	for (int i = 0; i < processImg->Width; i++) {
		for (int j = 0; j < processImg->Height; j++) {
			int mean = 0;
			for (int k = i - 1; k <= i + 1; k++) {
				for (int l = j - 1; l <= j + 1; l++) {
					if ((k >= 0) && (k < processImg->Width) && (l >= 0) && (l < processImg->Height))	mean += returnGrayPixel(processImg->GetPixel(k, l));
				}
			}
			Color newColor = returnGrayColor(mean / 9);
			processImg->SetPixel(i, j, newColor);
		}
	}
	setHistogramChart(ProcessHistoChart, processImg);
	ProcessImageBox->Image = processImg;
}
private: System::Void MedianFilterButton_Click(System::Object^  sender, System::EventArgs^  e) {
	for (int i = 1; i < processImg->Width; i++) {
		for (int j = 1; j < processImg->Height; j++) {
			vector<int> convec = { };
			for (int k = i - 1; k <= i + 1; k++) {
				for (int l = j - 1; l <= j + 1; l++) {
					int insertion = 0;
					if ((k >= 0) && (k < processImg->Width) && (l >= 0) && (l < processImg->Height))	insertion = returnGrayPixel(processImg->GetPixel(k, l));
					size_t idx = 0;
					for (idx; idx < convec.size(); idx++) {
						if (convec[idx] > insertion) break;
					}
					convec.insert(convec.begin() + idx, insertion);
				}
			}
			Color newColor = returnGrayColor(convec[4]);
			processImg->SetPixel(i, j, newColor);
		}
	}
	setHistogramChart(ProcessHistoChart, processImg);
	ProcessImageBox->Image = processImg;
}
/*
	Third Homework.
*/
private: System::Void HistogramEqualizationButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (check_number(LowerBoundText->Text) && check_number(UpperBoundText->Text)) {
		Int32 LowerBound = System::Convert::ToInt32(LowerBoundText->Text);
		Int32 UpperBound = System::Convert::ToInt32(UpperBoundText->Text);
		if ((LowerBound <= 255) && (LowerBound >= 0) &&
			(UpperBound <= 255) && (UpperBound >= 0) && (LowerBound< UpperBound)) {
			vector<int> SourceHisto = returnHistogram(processImg);
			int totalpixel = processImg->Width * processImg->Height;
			int accum = 0;
			map<int, int> HistoMapping;
			int i, j;
			for (i = 0; i < 256; i++) {
				if (SourceHisto[i] == 0) continue;
				accum += SourceHisto[i];
				int after = (((UpperBound- LowerBound) * accum) / totalpixel) + LowerBound;
				HistoMapping[i] = after;
			}
			for (i = 0; i < processImg->Width; i++) {
				for (j = 0; j < processImg->Height; j++) {
					int pixelMap = HistoMapping[returnGrayPixel(processImg->GetPixel(i, j))];
					Color newColor = returnGrayColor(pixelMap);
					processImg->SetPixel(i, j, newColor);
				}
			}
			setHistogramChart(ProcessHistoChart, processImg);
			ProcessImageBox->Image = processImg;
		}
	}
}
/*
	Fourth Homework.
*/
private: System::Void ThresholdEnterButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (check_number(ThresholdText->Text)) {
		Int32 Threshhold = System::Convert::ToInt32(ThresholdText->Text);
		int i, j, pixel;
		if ((Threshhold <= 255) && (Threshhold >= 0)) {
			for (i = 0; i < processImg->Width; i++) {
				for (j = 0; j < processImg->Height; j++) {
					if (returnGrayPixel(processImg->GetPixel(i, j)) >= Threshhold) pixel = 255;
					else pixel = 0;
					Color newColor = returnGrayColor(pixel);
					processImg->SetPixel(i, j, newColor);
				}
			}
			setHistogramChart(ProcessHistoChart, processImg);
			ProcessImageBox->Image = processImg;
		}
	}
}
/*
	Fifth Homework.
*/
private: System::Void VerticalButton_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap^ temp = returnVerticalSobel(-1);
	setHistogramChart(ProcessHistoChart, temp);
	ProcessImageBox->Image = temp;
}
private: System::Void HorizontalButton_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap^ temp = returnHorizontalSobel(-1);
	setHistogramChart(ProcessHistoChart, temp);
	ProcessImageBox->Image = temp;
}
private: System::Void CombinedButton_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap^ Combined = returnSobelfilter(-1);
	setHistogramChart(ProcessHistoChart, Combined);
	ProcessImageBox->Image = Combined;
}
/*
	Sixth Homework.
*/
private: System::Void EdgeEnterButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (check_number(EdgeText->Text)) {
		Int32 Threshhold = System::Convert::ToInt32(EdgeText->Text);
		if ((Threshhold <= 255) && (Threshhold >= 0)) {
			Bitmap^ EdgeApply = returnSobelfilter(Threshhold);
			for (int i = 0; i < EdgeApply->Width; i++) {
				for (int j = 0; j < EdgeApply->Height; j++) {
					if (!(EdgeApply->GetPixel(i, j).G)) EdgeApply->SetPixel(i, j, processImg->GetPixel(i, j));
					else
						EdgeApply->SetPixel(i, j, Color::FromArgb(processImg->GetPixel(i, j).R, 255, processImg->GetPixel(i, j).B));
				}
			}
			setHistogramChart(ProcessHistoChart, EdgeApply);
			ProcessImageBox->Image = EdgeApply;
			}
		}
}
/*
	Seventh Homework.
*/
private: System::Void ClusterButton_Click(System::Object^  sender, System::EventArgs^  e) {
	int Region = 0;
	for (int i = 0; i < processImg->Width; i++) {
		for (int j = 0; j < processImg->Height; j++) {
			if (processImg->GetPixel(i, j).R == 0) {
				Region += 1;
				queue<vector<int>> record ; record.push({ i, j });
				Color newColor = RandColor();
				processImg->SetPixel(i,j, newColor);
				while (!record.empty()) {
					vector<int> pixel = record.front(); record.pop();
					for (int k = -1; k <= 1; k++) {	for (int l = -1; l <= 1; l++) {
							if ((pixel[0] + k >= 0) && (pixel[1] + l >= 0) &&
								(pixel[0] + k < processImg->Width) && (pixel[1] + l < processImg->Height)) {
									if (processImg->GetPixel(pixel[0] + k, pixel[1] + l).R == 0) {
										processImg->SetPixel(pixel[0] + k, pixel[1] + l, newColor);
										record.push({ pixel[0] + k, pixel[1] + l });
									} 
							}
					}}
				}
			}
	}}
	std::stringstream stream;
	stream << std::fixed << Region;
	string text = "Cluster Region: ";
	text += stream.str();
	ClusterButton->Text = gcnew String(text.c_str());

	setHistogramChart(ProcessHistoChart, processImg);
	ProcessImageBox->Image = processImg;
}
 /*
	Eighth Homework.
*/
private: System::Void ImageRegistrationButton_Click(System::Object^  sender, System::EventArgs^  e) {
	ImageRegistrationForm ^ form = gcnew ImageRegistrationForm(openImg);
	form->ShowDialog();
}
};
}
