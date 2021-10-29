# [影像處理 DIP HW1 Report](https://hackmd.io/@Masamaloka/DIP_HW1)
> N26100668 謝旻恩



## 0. 專案概要
### 0.1. Introduction
本次專案透過 Microsoft Visual C++ 在不透過 opencv 的強大函式庫下，實作一份影像處理的 WindowsForm 應用介面。
![](https://i.imgur.com/cN0XOoy.png)

### 0.2. Application Flow
1. 首先透過 "Load" Button 載入圖片
2. 透過點擊左欄功能，以在 Process Image 添加不同的 Filter。除了一些特殊限制，基本上 Filter 都能夠重複疊加處理。
3. 除了 "Image Registration" 會跳出新的 Form 頁面，其他都功能皆會在此 Form 作呈現，並顯示其對應的 Gray-scale Histogram。
4. "Undo" Button 用以清除疊加 Filter的紀錄，還原回原始輸入的照片。
5. 最後透過 "Save" Button 來儲存處理後 .jpg 型式的影像。

### 0.3. Discussion 
#### **1. Input Image Color**
除了 "RGB Extraction" 特別限制只能執行彩色照片外，其他功能並不限定輸入圖片，然而皆將輸入視為灰階照片進行處理，在本次專案特別以兩個主要 function 處理輸入 Color 顏色，使所有照片皆能以灰階作運算。
```cpp=
private: int returnGrayPixel(Color pixel) {
    return  (pixel.R + pixel.G + pixel.B) / 3;
}
private: Color returnGrayColor(int pixel) {
    return  Color::FromArgb(pixel, pixel, pixel);
}
```
#### **2. Bitmap^ Initialize Issue**
為了使 Process Image 能夠疊加 Filter 並還原，透過兩張Bitmap ^ 。 
this -> openImg 負責存儲原始素質, this -> processImg 負責做 Filter 疊加。
其中我透過不同的方式初始化兩個 Bitmap^

```cpp=
private: Bitmap^ openImg;
private: Bitmap^ processImg;

private: System::Void LoadButton_Click(System::Object^  sender, System::EventArgs^  e) {
    this -> openImg = gcnew Bitmap(openFileDialog1->FileName);
    this -> processImg = resetBitmap();
    ...
}

private: Bitmap^ resetBitmap() {
    Bitmap^ temp = gcnew Bitmap(openImg->Width,openImg->Height);
    for (int i = 0; i < openImg->Width; i++) {
        for (int j = 0; j < openImg->Height; j++)
            temp->SetPixel(i, j, openImg->GetPixel(i, j));
    }
    return temp;
}
```
若 this -> processImg 使用如 openImg 的方式做初始化，則可能產生：
:::danger
System.InvalidOperationException: '對於具有索引像素格式的影像不支援 SetPixel。'
:::
- ref : [c#_具有索引像素格式的图像不支持 SetPixel](https://blog.csdn.net/pengjian444/article/details/50990374)

#### **3. System::String to int / float to System::String**
由於系統有使用者輸入數值的需求，並也需要我們回傳執行後的數值，故需要針對 System::String 與 int/float 轉換的 function。

在 **System::String to int** 首先我會用一個 bool check_number() 以確定輸入字串是否為數字，再進行轉換。
```cpp=
private: bool check_number(System::String^ Str) {
    std::string str = msclr::interop::marshal_as<std::string>(Str);
    int i = 0;
    for (unsigned int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}
if(check_number(InputText->Text))
    Int32 Input = System::Convert::ToInt32(InputText->Text);
```
在 **float to System::String** 利用 std::stringstream 做 float to std::string 的轉換，在準備好文字後再一次轉換為 System::String。
```cpp=
float Value;
string text = "The Result: ";
std::stringstream stream;
stream << std::fixed << std::setprecision(2) << Value;
text += stream.str();
ClusterButton->Text = gcnew String(text.c_str());
```

## 1. RGB Extraction & transformation
### 1.1. Introduction
將彩色圖片分別的 RGB 抽取出來顯示，第四個按鈕顯示灰階處理。
![](https://i.imgur.com/2PdVi2A.png)

### 1.2. Method
1. **判斷是否彩色照片：** 對 Bitmap 隨機抽樣檢查十個點，若發現有 RGB Channel 任一數值不同，則判定此照片為彩色照片，反之則為灰階照片。
2. **逐幀處理 RGB ：** Iteration 經過所有 pixel 並取出RGB ，若為 Grayscale 則將 RGB 做平均呈現。

```cpp=
private: bool checkIsGrayScale(Bitmap^ Img) {
    // check if Img is Grayscale
    for (check random Img (X,Y) 10 times) {
        if (Img.GetPixel(X,Y).R != Img.GetPixel(X,Y).G || 
            Img.GetPixel(X,Y).R != Img.GetPixel(X,Y).B ) 
            return false;
    }
    return true;
}

private: System::Void ExtractionRButton_Click(...)
private: System::Void ExtractionGButton_Click(...)
private: System::Void ExtractionBButton_Click(...)
private: System::Void GrayscaleButton_Click(...) {
    // Loop through the images pixels to reset color.
    if (!checkIsGrayScale(processImg)) {
        for (iterate through processImg Pixels) {
            processImg->SetPixel(i, j, Color::RGB or grayscale); 
        }
        Set HistogramChart and ProcessImageBox;
    }
}
```

## 2. Mean and Median Smooth filter
### 2.1. Introduction
透過Mean and Median Filter以降低圖片的雜訊。由結果可看到 Median Filter 的除雜訊效果好，不過也仍有 Over-Smooth 的情形。
![](https://i.imgur.com/5qwHOhM.png)

### 2.2. Method
1. 逐一 pixel 計算 3x3 Filter 之 mean 或 median ，成為該 pixel 新的數值。
2. 需特別檢查邊界的 neighbor pixel ，恐不足 9 點。

```cpp=
private: System::Void MeanFilterButton_Click(...){
    for (iterate through processImg Pixels) {
        int mean = 0;
        for (Convolution through 3x3 Pixels){
            mean +=  accumulateValue;
        }
        processImg->SetPixel(x, y, mean/9)
    }
}

private: System::Void MedianFilterButton_Click(...){
    for (iterate through processImg Pixels) {
        vector<int> MedianVec = { };
        for (Convolution through 3x3 Pixels){
            MedianVec.insert(Sorted Vector<int>);
        }
        processImg->SetPixel(x, y, MedianVec[4])
    }
}
```

## 3. Histogram Equalization
### 3.1. Introduction
設定 Histogram Equalization 來調整 Pixel Intensity 分布。提供 TextBox 讓使用者輸入 Upper/Lower Bound，預設數值 [0,255]。
![](https://i.imgur.com/34qWZm3.png)

### 3.2. Method
1. 使用 vector<int> 逐一 pixel 紀錄 Intensity Distribution。
2. 將原先的 Distribution，透過 CDF 映射至對應的  Intensity map<int,int>。
$$G(z_q)_{8-bit} =round( (Upper-Lower) ⋅ CDF(z_q))+Lower$$
3. 透過 map 對原圖逐一 pixel 轉換。



```cpp=
private: System::Void HistogramEqualizationButton_Click(...) {
    if (check_number(LowerBoundText->Text) && check_number(UpperBoundText->Text)
        && LowerBound, UpperBound is comform to restriction) {
        Int32 LowerBound,UpperBound = System::Convert::ToInt32(BoundText->Text);
        // get the Intensity distribution
        vector<int> SourceHisto = returnHistogram(processImg); 
        // get the Projection Mapping
        map<int, int> HistoMapping;
        for(iterate through SourceHisto){
            int new = (((UpperBound- LowerBound) * accum) / totalpixel) + LowerBound;
            HistoMapping[i] = after;
        }
        // Mapping
        for(iterate through processImg){
           processImg->SetPixel(i, j, newProjectionColor); 
        }
    }
}
```

## 4. Thresholding 
### 4.1. Introduction
令使用者輸入 [0,255] 的 Threshold，大於 Threshold 為 255 反之為 0。
![](https://i.imgur.com/njNO8Fj.png)
### 4.2. Method

```cpp=
private: System::Void ThresholdEnterButton_Click(...) {
    if (check_number(ThresholdText->Text) && Threshhold comform the restriction) {
        Int32 Threshhold = System::Convert::ToInt32(ThresholdText->Text);
        for(iterate through processImg){
            newColor = Color (processImg[i, j] > Threshhold )? 255:0;
            processImg->SetPixel(i, j, newColor);
        }
    }
}
```
## 5. Sobel edge detection
### 5.1. Introduction
![](https://i.imgur.com/wUIOZUe.png)
### 5.2. Method
1. 令processImg Convolution 經過 Vertical/Horizontal Sobel Filter，設定 Threshold 預設 150 ，取得 edge result。
$$Vertical Sobel Filter = \left[\begin{array}{ccc}1&2&1\\0&0&0\\-1&-2&-1\\\end{array}\right]$$
$$Horizontal Sobel Filter = \left[\begin{array}{ccc}1&0&-1\\2&0&-2\\1&0&-1\\\end{array}\right]$$
2. **將兩圖結果 combined**：聯集兩圖的白色數值(255)。
```cpp=
private: System::Void VerticalButton_Click(...){
    for(iterate through processImg){
        //convolution through Vertical Sobel Filter
    }
}
private: System::Void HorizontalButton_Click(...){
    for(iterate through processImg){
        //convolution through Horizontal Sobel Filter
    }
}
private: System::Void CombinedButton_Click(...){
    Bitmap ^ Vertical = //processImg ★ VSobel;
    Bitmap ^ Horizontal = //processImg ★ HSobel;
    Bitmap ^ Combined = gcnew Bitmap(w,h);
    for(iterate through Combined){
        Combined = Vertical ∪ Horizontal;
    }
}
```

## 6. Edge overlapping
### 6.1. Introduction
![](https://i.imgur.com/S5iYHH3.png)
### 6.2. Method
1. 依前題計算出 processImg 的 Sobel edge detection。
2. 檢查 processImg 的每一點，將 Sobel edge 的 pixel 調整為 Color::FromArgb(origin.R ,255 ,origin.B);
```cpp=
private: System::Void EdgeEnterButton_Click(...){
    if(EdgeText->Text is a int [0,255]){
        Int32 Threshhold = System::Convert::ToInt32(EdgeText->Text);
        Bitmap^ EdgeApply = returnSobelfilter(Threshhold);
        for(iterate through prossImg){
            EdgeApply->SetPixel(i, j, Color::FromArgb(, 255, ));
        }
    }
}
```


## 7. Connected Component
### 7.1. Introduction
提供一張黑白照片，將黑色 pixel 以 8-adjacancy 分類圖色，最後告訴使用者共被分類為幾個區塊。
![](https://i.imgur.com/mIHLDWr.png)

### 7.2. Method
1. Iterate processImg 的 pixel，若發現黑點(Intensity = 0)，則開始尋找相鄰所有黑點進行圖色。
2. **執行Breadth-First Search**：使用一個 queue<vector<int>> 來記錄相鄰的黑點，依序將找到的相鄰點放置入 queue ，在圖色完後並再次檢查 queue 中是否還有相鄰黑點，直到 queue 再也沒有記錄點為止。便回到步驟 1. 繼續尋找新區塊。
    
```cpp=
private: System::Void ClusterButton_Click(...){
    for (Iterate through processImg) {
        if(Find pixel Intensity == 0){
            // Start BFS
            queue<vector<int>> record ;
            Color newColor = randomColor() //new random color for the region
            while (!record.empty()) {
                vector<int> pixel = record.front(); record.pop();
                // find 8-adjacancy of pixel
                // if there is black pixel, record.push()
            }
        }
    }
}
```
### 7.3. Discussion
#### 1. Why Breadth-First Search?
最剛開始時我的做法並非使用 BFS 來對 Region 作圖色，我的作法如下：
1. iterate through processImg
2. 如果有黑點，確認目前已處理過的四周是否有圖色
3. 若有則改變成與他相同之顏色，如沒有則隨機圖新的顏色。

但這樣做會有一個問題：
![](https://i.imgur.com/cTZiKrt.png)
如果我們今天有一個凸型的黑色區塊，理論上應該是都要塗成同一顏色，但如果我們依照上面的做法做的話，他搜尋到的這兩處凸起會被視作不同的圖色區域，甚至影響到後續圖色判定的結果。
    
為了避免這樣的情況發生，我們必須在碰到黑色區塊時便開始動手尋找所有與其相鄰的 Region 。在這邊實作便選擇了 BFS 的策略。

## 8. Image registration
### 8.1. Introduction
提供兩張經過旋轉、縮放的照片，使用者可以針對照片做四點的標記校正，系統須提供校正的 Scaling 與 Rotation 角度，對照片做校正後與原圖的 Intensity Difference。
    
![](https://i.imgur.com/bBQKBoS.png)

### 8.2. System Issue
#### **1. Open New Form**
由於本題的需求相較其他題較為不同，除了 Loading 照片要兩張，並且需要對照片進行標記，最後要顯示校正結果與  Scaling, Rotation, Intensity Difference。所以我決定將此系統分配至新的 Form 上。

在載入照片並按下 "Image Registration" Button後，將會開啟新的 Form 並將 Bitmap ^ 傳入第二個 Form 中。
    
為了達到此結果，我做了兩件事情：
1. 開啟新的 "ImageRegistrationForm1.h"，並 overload Contructor，讓 ImageRegistrationForm1 被建構時能傳入"MyForm.h"中的 Bitmap ^ 來做使用。
2. 在 "MyForm.h" 中 #include "ImageRegistrationForm1.h"，並在 "Image Registration" Button 被觸發時，建構並開啟 ImageRegistrationForm1。

```cpp=
//MyForm.h
#pragma once
#include "ImageRegistrationForm1.h"
...
private: System::Void ImageRegistrationButton_Click(...) {
	ImageRegistrationForm1 ^ form = gcnew ImageRegistrationForm1(openImg);
	form->ShowDialog();
}

//ImageRegistrationForm1.h
public ref class ImageRegistrationForm1 : public System::Windows::Forms::Form{
    public:
        ImageRegistrationForm1(void){
            InitializeComponent();
        }
        //overload construction to tranfer Bitmap ^
        ImageRegistrationForm1(Bitmap ^ openImg) {
            InitializeComponent();
            OriginImg = openImg;
            OriginPicBox->Image = OriginImg;
        }
    ...
}
```
#### **2. System Flow**
在 "ImageRegistrationForm1.h" 中有以下幾個物件：
- **Label^ Instructions：** 提示使用者操作步驟。
- **Button^ LoadRegisButton：** 在不同階段提供使用者 "Load picture", "Undo Labeling", "Start Register" ,"Save Image" 等等的功能。
- **PictureBox^  OriginPicBox：** 原始照片。
- **PictureBox^  RegisPicBox：** 欲校正照片。
- **PictureBox^  ProcessPicBox：** 校正後照片。

| Stage | Description | 
| -------- | -------- |
| 1)Load RegisImg |載入欲校正之照片|
| 2)Label on OriginImg |在 OriginImg 上進行 label 標註|
| 3)Label on RegisImg | 在 RegisImg 上進行 label 標註，並驗證兩標註點是否為相似四邊形，若是則繼續，否則要求使用者重新標註。|
| 4)Start Regis | 計算 Scaling 與 Rotation 角度。 |
| 5)Result | 旋轉過後計算 Intensity Difference 並讓使用者儲存照片。 |

#### **3. Label on Picture**
```cpp=
vector<Point> OriginLocation = {};
    
private: System::Void OriginPicBox_Paint(...) {
    for (int i = 0; i < OriginLocation.Count; i++) {
        Graphics ^ g = e->Graphics;
        Pen^ PenStyle = gcnew Pen(Color::DimGray, 1);
        // Draw a 50x50 pixels rectangle (x, y, width, hight)
        g->DrawEllipse(PenStyle, OriginLocation[i].X-5, OriginLocation[i].Y-5, 10, 10);
    }
}
private: System::Void OriginPicBox_MouseClick(...) {
    Point coordinates = e->Location;
    OriginLocation.Add(coordinates);
    OriginPicBox -> Invalidate();
}
```
#### **4. Check if two label is similar shape**
計算兩圖的 Edge Scale 和 Diagonal Scale，若五個數值差異不大，即是為相似四邊形。
![](https://i.imgur.com/VUHAv4V.png)
```cpp=
private: System::Void RegisPicBox_MouseClick(...) {
    //After Labeling ,Check if the two shape is similar
    float EdgeScale_1,EdgeScale_2,EdgeScale_3,EdgeScale_4, DiagonalScale;
    // get the Edge Scale of the two Label Shape, and Diagonal Scale
    if(the 5 scale smaller than threshold){
        // get Scale and Angle
    }
}
```
### 8.3. Method
**1. Scale and Angle**
Scaling 的計算方式是將方才驗證後的 Edge Scale 取 幾何平均數(geometric mean)。
$$Scaling = \sqrt[4]{\prod EdgeScaling}$$

Angle的作法是將 Point[0] 視作參考點：首先必須將兩圖的 Point[1] - Point[0]，如是便能取得兩圖在對應參考點之 $\vec{a}$ $\vec{b}$，而後做以下運算以取得角度：
$$InnerProduct = x_1\cdot x_2 + y_1\cdot y_2= \Vert a\Vert\Vert b\Vert\cdot cos(\theta)\\
CrossProduct = x_1\cdot y_2 - y_1\cdot x_2 = \Vert a\Vert\Vert b\Vert\cdot sin(\theta)\\
Angle = \arctan(\frac{CrossProduct}{InnerProduct})$$
**2. Registration**
1. Iterate through processImg to find the projection point on regisImg.
2. Projection location is as follow:
$$
rMid = middle\ of\ regisImg\\
pMid = middle\ of\ processImg\\
iterate\ to\ find\ processImg[x ,y]\ projection\ to\ regisImg[x',y']\\
x' = ((x - pMid.x)*cos(-\theta) - (y - pMid.y)*sin(-\theta))/Scaling + rMid.x\\
y' = ((x - pMid.x)*sin(-\theta) + (y - pMid.y)*cos(-\theta))/Scaling + rMid.y
$$
:::info
我們的 Registration 公式是與 transform matrix 剛好相反：
- 理應上我們是希望 regisImg 旋轉 $\theta$ 並放大 $Scaling$
- 然而我們在這裡卻是旋轉 $-\theta$ 並縮小 $Scaling$

原因是我其實是對 process Bitmap 去做映射的「反校正」，去尋找在我們「反校正」對應在 regis Bitmap 的對應位置。

如果使用 regis Bitmap 做縮放去映射到 process Bitmap 上，會導致  process Bitmap 可能會有未被映射到的位置，而必須做 interpolation 的步驟。
:::







