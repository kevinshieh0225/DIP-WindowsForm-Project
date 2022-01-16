#pragma once
#include "ImageRegistrationForm.h"
#include <vector>
#include <map>
#include <ctype.h>
#include <msclr\marshal_cppstd.h>
#include <stdlib.h>     /* srand, rand */
#include <queue>

#define _USE_MATH_DEFINES // for C++
#include <math.h>


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
	private: System::Windows::Forms::Button^  GaussianFilterButton;
	private: System::Windows::Forms::TextBox^  FilterSizeText;
	private: System::Windows::Forms::GroupBox^  CannyEdgeBox;
	private: System::Windows::Forms::Button^  CannyEdgeDetectionButton;
	private: System::Windows::Forms::TextBox^  CannyUpperThreshholdText;
	private: System::Windows::Forms::TextBox^  CannyLowThreshholdText;




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
			this->FilterSizeText = (gcnew System::Windows::Forms::TextBox());
			this->GaussianFilterButton = (gcnew System::Windows::Forms::Button());
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
			this->CannyEdgeBox = (gcnew System::Windows::Forms::GroupBox());
			this->CannyEdgeDetectionButton = (gcnew System::Windows::Forms::Button());
			this->CannyLowThreshholdText = (gcnew System::Windows::Forms::TextBox());
			this->CannyUpperThreshholdText = (gcnew System::Windows::Forms::TextBox());
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
			this->CannyEdgeBox->SuspendLayout();
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
			this->MedianFilterButton->Location = System::Drawing::Point(67, 21);
			this->MedianFilterButton->Name = L"MedianFilterButton";
			this->MedianFilterButton->Size = System::Drawing::Size(50, 23);
			this->MedianFilterButton->TabIndex = 8;
			this->MedianFilterButton->Text = L"Median";
			this->MedianFilterButton->UseVisualStyleBackColor = true;
			this->MedianFilterButton->Click += gcnew System::EventHandler(this, &MyForm::MedianFilterButton_Click);
			// 
			// MeanFilterButton
			// 
			this->MeanFilterButton->Location = System::Drawing::Point(6, 21);
			this->MeanFilterButton->Name = L"MeanFilterButton";
			this->MeanFilterButton->Size = System::Drawing::Size(55, 23);
			this->MeanFilterButton->TabIndex = 7;
			this->MeanFilterButton->Text = L"Mean";
			this->MeanFilterButton->UseVisualStyleBackColor = true;
			this->MeanFilterButton->Click += gcnew System::EventHandler(this, &MyForm::MeanFilterButton_Click);
			// 
			// SmoothFilterBox
			// 
			this->SmoothFilterBox->Controls->Add(this->FilterSizeText);
			this->SmoothFilterBox->Controls->Add(this->GaussianFilterButton);
			this->SmoothFilterBox->Controls->Add(this->MeanFilterButton);
			this->SmoothFilterBox->Controls->Add(this->MedianFilterButton);
			this->SmoothFilterBox->Location = System::Drawing::Point(31, 111);
			this->SmoothFilterBox->Name = L"SmoothFilterBox";
			this->SmoothFilterBox->Size = System::Drawing::Size(233, 61);
			this->SmoothFilterBox->TabIndex = 9;
			this->SmoothFilterBox->TabStop = false;
			this->SmoothFilterBox->Text = L"Smooth Filter";
			// 
			// FilterSizeText
			// 
			this->FilterSizeText->Location = System::Drawing::Point(184, 21);
			this->FilterSizeText->Name = L"FilterSizeText";
			this->FilterSizeText->Size = System::Drawing::Size(39, 22);
			this->FilterSizeText->TabIndex = 16;
			this->FilterSizeText->Text = L"3";
			// 
			// GaussianFilterButton
			// 
			this->GaussianFilterButton->Location = System::Drawing::Point(123, 21);
			this->GaussianFilterButton->Name = L"GaussianFilterButton";
			this->GaussianFilterButton->Size = System::Drawing::Size(55, 23);
			this->GaussianFilterButton->TabIndex = 9;
			this->GaussianFilterButton->Text = L"Guassian";
			this->GaussianFilterButton->UseVisualStyleBackColor = true;
			this->GaussianFilterButton->Click += gcnew System::EventHandler(this, &MyForm::GaussianFilterButton_Click);
			// 
			// EqualizationBox
			// 
			this->EqualizationBox->Controls->Add(this->UpperBoundText);
			this->EqualizationBox->Controls->Add(this->LowerBoundText);
			this->EqualizationBox->Controls->Add(this->HistogramEqualizationButton);
			this->EqualizationBox->Location = System::Drawing::Point(31, 190);
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
			this->ThresholdingBox->Location = System::Drawing::Point(31, 273);
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
			this->SobelEdgeBox->Location = System::Drawing::Point(31, 355);
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
			this->EdgeOverlapBox->Location = System::Drawing::Point(31, 516);
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
			this->ImageRegistrationBox->Location = System::Drawing::Point(31, 684);
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
			this->LoadButton->Location = System::Drawing::Point(37, 772);
			this->LoadButton->Name = L"LoadButton";
			this->LoadButton->Size = System::Drawing::Size(70, 23);
			this->LoadButton->TabIndex = 13;
			this->LoadButton->Text = L"Load";
			this->LoadButton->UseVisualStyleBackColor = true;
			this->LoadButton->Click += gcnew System::EventHandler(this, &MyForm::LoadButton_Click);
			// 
			// SaveButton
			// 
			this->SaveButton->Location = System::Drawing::Point(113, 772);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(70, 23);
			this->SaveButton->TabIndex = 12;
			this->SaveButton->Text = L"Save";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &MyForm::SaveButton_Click);
			// 
			// UndoButton
			// 
			this->UndoButton->Location = System::Drawing::Point(189, 772);
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
			this->ConnectedComponentBox->Location = System::Drawing::Point(31, 598);
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
			// CannyEdgeBox
			// 
			this->CannyEdgeBox->Controls->Add(this->CannyUpperThreshholdText);
			this->CannyEdgeBox->Controls->Add(this->CannyLowThreshholdText);
			this->CannyEdgeBox->Controls->Add(this->CannyEdgeDetectionButton);
			this->CannyEdgeBox->Location = System::Drawing::Point(31, 434);
			this->CannyEdgeBox->Name = L"CannyEdgeBox";
			this->CannyEdgeBox->Size = System::Drawing::Size(233, 63);
			this->CannyEdgeBox->TabIndex = 12;
			this->CannyEdgeBox->TabStop = false;
			this->CannyEdgeBox->Text = L"Canny Edge Detection";
			// 
			// CannyEdgeDetectionButton
			// 
			this->CannyEdgeDetectionButton->Location = System::Drawing::Point(9, 21);
			this->CannyEdgeDetectionButton->Name = L"CannyEdgeDetectionButton";
			this->CannyEdgeDetectionButton->Size = System::Drawing::Size(127, 23);
			this->CannyEdgeDetectionButton->TabIndex = 8;
			this->CannyEdgeDetectionButton->Text = L"Canny Edge Detection";
			this->CannyEdgeDetectionButton->UseVisualStyleBackColor = true;
			this->CannyEdgeDetectionButton->Click += gcnew System::EventHandler(this, &MyForm::CannyEdgeDetectionButton_Click);
			// 
			// CannyLowThreshholdText
			// 
			this->CannyLowThreshholdText->Location = System::Drawing::Point(143, 22);
			this->CannyLowThreshholdText->Name = L"CannyLowThreshholdText";
			this->CannyLowThreshholdText->Size = System::Drawing::Size(36, 22);
			this->CannyLowThreshholdText->TabIndex = 16;
			this->CannyLowThreshholdText->Text = L"50";
			// 
			// CannyUpperThreshholdText
			// 
			this->CannyUpperThreshholdText->Location = System::Drawing::Point(186, 22);
			this->CannyUpperThreshholdText->Name = L"CannyUpperThreshholdText";
			this->CannyUpperThreshholdText->Size = System::Drawing::Size(36, 22);
			this->CannyUpperThreshholdText->TabIndex = 17;
			this->CannyUpperThreshholdText->Text = L"150";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1654, 862);
			this->Controls->Add(this->CannyEdgeBox);
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
			this->SmoothFilterBox->PerformLayout();
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
			this->CannyEdgeBox->ResumeLayout(false);
			this->CannyEdgeBox->PerformLayout();
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
	private: bool IsInBounds(float value, float low, float high) {
		return (value >= low) && (value <= high);
	}
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

	private: Bitmap^ completeEdge(Bitmap ^ map, int size) {
		int width = map->Width-1; int height = map->Height-1;
		for (int j = 1; j < height; j++) {
			for (int i = 0; i < size; ++i) {
				map->SetPixel(i, j, map->GetPixel(size, j));
				map->SetPixel(width-i, j, map->GetPixel(width - size, j));
			}

		}
		for (int i = 0; i < width+1; i++) {
			for (int j = 0; j < size; ++j) {
				map->SetPixel(i, j, map->GetPixel(i, size));
				map->SetPixel(i, height-j, map->GetPixel(i, height - size));
			}
		}
		
		return map;
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
	
//check if the input string can be change to int
	private: bool check_number(System::String^ Str) {
		std::string str = msclr::interop::marshal_as<std::string>(Str);
		int i = 0;
		for (unsigned int i = 0; i < str.length(); i++)
			if (isdigit(str[i]) == false)
				return false;
		return true;
	}

// for hw 5
	private: Bitmap^ returnGuassianFilter(int FilterSize, Bitmap^ Img) {
		// create filter
		vector<vector<float>> GKernel(FilterSize, vector<float>(FilterSize, 0));
		// initialising standard deviation to 1.0
		float sigma = 1.0;
		float r, s = 2.0 * sigma * sigma;

		// sum is for normalization
		float sum = 0.0;
		int conv = FilterSize / 2;
		// generating 5x5 kernel
		for (int x = -conv; x <= conv; x++) {
			for (int y = -conv; y <= conv; y++) {
				r = sqrt(x * x + y * y);
				GKernel[x + conv][y + conv] = (exp(-(r * r) / s)) / (M_PI * s);
				sum += GKernel[x + conv][y + conv];
			}
		}
		// normalising the Kernel
		for (int i = 0; i < FilterSize; ++i)
			for (int j = 0; j < FilterSize; ++j)
				GKernel[i][j] /= sum;

		Bitmap^ temp = gcnew Bitmap(Img->Width, Img->Height);
		for (int i = conv; i < temp->Width - conv; i++) {
			for (int j = conv; j < temp->Height - conv; j++) {
				int pixel = 0;
				for (int k = -conv; k <= conv; k++) {
					for (int l = -conv; l <= conv; l++) {
						pixel += (returnGrayPixel(Img->GetPixel(i + k, j + l)) * GKernel[k + conv][l + conv]);
					}
				}
				pixel = abs(pixel);
				if (pixel > 255) pixel = 255;
				temp->SetPixel(i, j, returnGrayColor(pixel));
			}
		}
		return completeEdge(temp,conv);
	}

	private: Bitmap^ returnVerticalSobel(Bitmap^ Img) {
		Bitmap^ temp = gcnew Bitmap(Img->Width, Img->Height);
		vector<vector<int>> VerticalFilter = { {1,2,1},{0,0,0},{-1,-2,-1} };
		for (int i = 1; i < temp->Width-1; i++) {
			for (int j = 1; j < temp->Height-1; j++) {
				int pixel = 0;
				for (int k = -1; k <= 1; k++) {
					for (int l = -1; l <= 1; l++) {
						pixel += (returnGrayPixel(Img->GetPixel(i + k, j + l)) * VerticalFilter[k + 1][l + 1]);
					}
				}
				pixel = abs(pixel);
				if (pixel > 255) pixel = 255;
				temp->SetPixel(i, j, returnGrayColor(pixel));
			}
		}
		return completeEdge(temp,1);
	}
	private: Bitmap^ returnHorizontalSobel(Bitmap^ Img) {
		Bitmap^ temp = gcnew Bitmap(Img->Width, Img->Height);
		vector<vector<int>> HorizontalFilter = { {1,0,-1},{2,0,-2},{1,0,-1} };
		for (int i = 1; i < temp->Width-1; i++) {
			for (int j = 1; j < temp->Height-1; j++) {
				int pixel = 0;
				for (int k = -1; k <= 1; k++) {
					for (int l = -1; l <= 1; l++) {
						pixel += (returnGrayPixel(Img->GetPixel(i + k, j + l)) * HorizontalFilter[k + 1][l + 1]);
					}
				}
				pixel = abs(pixel);
				if (pixel > 255) pixel = 255;
				temp->SetPixel(i, j, returnGrayColor(pixel));
			}
		}
		return completeEdge(temp,1);
	}
	private: Bitmap^ returnSobelfilter(Bitmap^ Img) {
		Bitmap^ Vertical = returnVerticalSobel(Img);
		Bitmap^ Horizontal = returnHorizontalSobel(Img);
		Bitmap^ Combined = gcnew Bitmap(processImg->Width, processImg->Height);
		int verticalpixel, horizontalpixel, pixel;
		for (int i = 0; i < Vertical->Width; i++) {
			for (int j = 0; j < Vertical->Height; j++) {
				verticalpixel = returnGrayPixel(Vertical->GetPixel(i, j));
				horizontalpixel = returnGrayPixel(Horizontal->GetPixel(i, j));
				pixel = sqrt(verticalpixel*verticalpixel + horizontalpixel* horizontalpixel);
				if (pixel > 255) pixel = 255;
				Combined->SetPixel(i, j, returnGrayColor(pixel));
			}
		}
		return Combined;
	}
// for hw 6
	private: Bitmap^ returnSobelfilter(Bitmap^ Img, int Threshhold) {
		Bitmap^ Vertical = returnVerticalSobel(Img);
		Bitmap^ Horizontal = returnHorizontalSobel(Img);
		Bitmap^ EdgeApply = gcnew Bitmap(processImg->Width, processImg->Height);
		int verticalpixel, horizontalpixel, pixel;
		for (int i = 0; i < Vertical->Width; i++) {
			for (int j = 0; j < Vertical->Height; j++) {
				verticalpixel = returnGrayPixel(Vertical->GetPixel(i, j));
				horizontalpixel = returnGrayPixel(Horizontal->GetPixel(i, j));
				pixel = sqrt(verticalpixel*verticalpixel + horizontalpixel * horizontalpixel);
				if (pixel < Threshhold)
					EdgeApply->SetPixel(i, j, processImg->GetPixel(i, j));
				else
					EdgeApply->SetPixel(i, j, Color::FromArgb(processImg->GetPixel(i, j).R, 255, processImg->GetPixel(i, j).B));
			}
		}
		return EdgeApply;
	}

// for hw 7
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
	if (check_number(FilterSizeText->Text)) {
		Int32 FilterSize = System::Convert::ToInt32(FilterSizeText->Text);
		Int32 FilterArea = FilterSize * FilterSize;
		Int32 conv = FilterSize / 2;
		Bitmap^ temp = gcnew Bitmap(processImg->Width, processImg->Height);
		for (int i = conv; i < processImg->Width - conv; i++) {
			for (int j = conv; j < processImg->Height - conv; j++) {
				int mean = 0;
				//Convolution to find local mean
				for (int k = i - conv; k <= i + conv; k++) {
					for (int l = j - conv; l <= j + conv; l++) {
						mean += returnGrayPixel(processImg->GetPixel(k, l));
					}
				}
				temp->SetPixel(i, j, returnGrayColor(mean / FilterArea));
			}
		}
		processImg = completeEdge(temp,conv);
		setHistogramChart(ProcessHistoChart, processImg);
		ProcessImageBox->Image = processImg;
	}
}
private: System::Void MedianFilterButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (check_number(FilterSizeText->Text)) {
		Int32 FilterSize = System::Convert::ToInt32(FilterSizeText->Text);
		Int32 conv = FilterSize / 2;
		Bitmap^ temp = gcnew Bitmap(processImg->Width, processImg->Height);
		for (int i = conv; i < processImg->Width - conv; i++) {
			for (int j = conv; j < processImg->Height - conv; j++) {
				int FilterArea = FilterSize * FilterSize;
				vector<int> convec(FilterArea, 0); int idx = 0;
				//Convolution to find local median
				for (int k = i - conv; k <= i + conv; k++) {
					for (int l = j - conv; l <= j + conv; l++) {
						convec[idx++] = returnGrayPixel(processImg->GetPixel(k, l));
					}
				}
				std::nth_element(convec.begin(), convec.begin() + FilterArea/2, convec.end());
				temp->SetPixel(i, j, returnGrayColor(convec[FilterArea / 2]));
			}
		}
		processImg = completeEdge(temp,conv);
		setHistogramChart(ProcessHistoChart, processImg);
		ProcessImageBox->Image = processImg;
	}
}

private: System::Void GaussianFilterButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (check_number(FilterSizeText->Text)) {
		Int32 FilterSize = System::Convert::ToInt32(FilterSizeText->Text);
		processImg = returnGuassianFilter(FilterSize, processImg);
		setHistogramChart(ProcessHistoChart, processImg);
		ProcessImageBox->Image = processImg;
	}

}
/*
	Third Homework.
*/
private: System::Void HistogramEqualizationButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (check_number(LowerBoundText->Text) && check_number(UpperBoundText->Text)) {
		Int32 LowerBound = System::Convert::ToInt32(LowerBoundText->Text);
		Int32 UpperBound = System::Convert::ToInt32(UpperBoundText->Text);
		if (IsInBounds(LowerBound,0,255) && IsInBounds(UpperBound, 0, 255) && (LowerBound< UpperBound)) {
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
		if (IsInBounds(Threshhold, 0, 255)) {
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
	processImg = returnVerticalSobel(processImg);
	setHistogramChart(ProcessHistoChart, processImg);
	ProcessImageBox->Image = processImg;
}
private: System::Void HorizontalButton_Click(System::Object^  sender, System::EventArgs^  e) {
	processImg = returnHorizontalSobel(processImg);
	setHistogramChart(ProcessHistoChart, processImg);
	ProcessImageBox->Image = processImg;
}
private: System::Void CombinedButton_Click(System::Object^  sender, System::EventArgs^  e) {
	processImg = returnSobelfilter(processImg);
	setHistogramChart(ProcessHistoChart, processImg);
	ProcessImageBox->Image = processImg;
}
/*
	Sixth Homework.
*/
private: System::Void EdgeEnterButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (check_number(EdgeText->Text)) {
		Int32 Threshhold = System::Convert::ToInt32(EdgeText->Text);
		if (IsInBounds(Threshhold, 0, 255)) {
			processImg = returnSobelfilter(processImg, Threshhold);
			setHistogramChart(ProcessHistoChart, processImg);
			ProcessImageBox->Image = processImg;
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
				//Start BFS
				Region += 1;
				queue<vector<int>> record ; record.push({ i, j });
				Color newColor = RandColor();
				processImg->SetPixel(i,j, newColor);
				while (!record.empty()) {
					vector<int> pixel = record.front(); record.pop();
					for (int k = -1; k <= 1; k++) {	
						for (int l = -1; l <= 1; l++) {
							if (IsInBounds(pixel[0] + k, 0, processImg->Width-1) && 
								IsInBounds(pixel[1] + l, 0, processImg->Height - 1)) {
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

private: System::Void CannyEdgeDetectionButton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (check_number(CannyLowThreshholdText->Text) && check_number(CannyUpperThreshholdText->Text)) {
		Int32 weakEdge = System::Convert::ToInt32(CannyLowThreshholdText->Text) , strongEdge = System::Convert::ToInt32(CannyUpperThreshholdText->Text);
		// 1. Guassian Low Pass Filter
		processImg = returnGuassianFilter(5, processImg);

		// 2. Sobel Edge Detection
		Bitmap^ Vertical = returnVerticalSobel(processImg);
		Bitmap^ Horizontal = returnHorizontalSobel(processImg);
		vector<vector<float>> amplitude(processImg->Width, vector<float>(processImg->Height, 0.0));
		vector<vector<float>> direction(processImg->Width, vector<float>(processImg->Height, 0.0));
		vector<vector<float>> nmsamp(processImg->Width, vector<float>(processImg->Height, 0.0));
		float verticalpixel, horizontalpixel, amp, direct;
		for (int i = 0; i < processImg->Width; i++) {
			for (int j = 0; j < processImg->Height; j++) {
				verticalpixel = returnGrayPixel(Vertical->GetPixel(i, j));
				horizontalpixel = returnGrayPixel(Horizontal->GetPixel(i, j));
				amp = sqrt(verticalpixel*verticalpixel + horizontalpixel * horizontalpixel);
				direct = atan(verticalpixel / horizontalpixel);
				amplitude[i][j] = amp;
				direction[i][j] = direct;
				nmsamp[i][j] = amp;
			}
		}

		// 3. Non Maximum Suppression
		for (int i = 1; i < processImg->Width - 1; ++i) {
			for (int j = 1; j < processImg->Height - 1; ++j) {
				// 0~22.5度，157.5~180度 為 0 度區間
				if (IsInBounds(direction[i][j], 0, 22.5 / 180 * M_PI) || IsInBounds(direction[i][j], 157.5 / 180 * M_PI, M_PI)) {
					if (amplitude[i][j] < amplitude[i][j - 1] || amplitude[i][j] < amplitude[i][j])  nmsamp[i][j + 1] = 0;
				}
				// 22.5~67.5度 為 45度區間
				else if (IsInBounds(direction[i][j], 22.5 / 180 * M_PI, 67.5 / 180 * M_PI)) {
					if (amplitude[i][j] < amplitude[i - 1][j - 1] || amplitude[i][j] < amplitude[i + 1][j + 1])  nmsamp[i][j] = 0;
				}
				// 67.5~112.5度 為 90度區間
				else if (IsInBounds(direction[i][j], 67.5 / 180 * M_PI, 112.5 / 180 * M_PI)) {
					if (amplitude[i][j] < amplitude[i - 1][j] || amplitude[i][j] < amplitude[i + 1][j])  nmsamp[i][j] = 0;
				}
				//112.5~157.5度 為 135度區間
				else {
					if (amplitude[i][j] < amplitude[i - 1][j + 1] || amplitude[i][j] < amplitude[i + 1][j - 1])  nmsamp[i][j] = 0;
				}
			}
		}

		// 4. Double Thresholding

		for (int i = 1; i < processImg->Width - 1; ++i) {
			for (int j = 1; j < processImg->Height - 1; ++j) {
				if (nmsamp[i][j] > strongEdge) processImg->SetPixel(i, j, returnGrayColor(255));
				else if (nmsamp[i][j] < weakEdge) processImg->SetPixel(i, j, returnGrayColor(0));
				else {
					if (nmsamp[i - 1][j - 1] > strongEdge ||
						nmsamp[i - 1][j] > strongEdge ||
						nmsamp[i - 1][j + 1] > strongEdge ||
						nmsamp[i][j - 1] > strongEdge ||
						nmsamp[i][j + 1] > strongEdge ||
						nmsamp[i + 1][j - 1] > strongEdge ||
						nmsamp[i + 1][j] > strongEdge ||
						nmsamp[i + 1][j + 1] > strongEdge) {
						processImg->SetPixel(i, j, returnGrayColor(255));
					}
					else processImg->SetPixel(i, j, returnGrayColor(0));
				}
			}
		}
		processImg = completeEdge(processImg, 1);
		setHistogramChart(ProcessHistoChart, processImg);
		ProcessImageBox->Image = processImg;
	}
}
};
}
