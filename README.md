# 學生成績管理系統
級別:112   <br>
班級:資工一乙    <br>
姓名:余祥鳴  <br>
學號:41243215 <br>

## 介紹

本程式主要有以下重點:<br/><br/>
新增學生：<br>
輸入(1)來選擇新增學生功能，接下來只要接連輸入學生的「姓名、學號及成績」就會先暫存。<br><br>

顯示學生資訊：<br>
輸入(2)來選擇「顯示學生資訊」功能，執行後將會顯示以往儲存過的學生資料，資料包含了「姓名、學號及成績」。<br><br>

查詢學生：<br>
輸入(3)來選擇「查詢學生」功能，查詢的方式是由輸入「學號」來搜尋學生。<br><br>

編輯學生資訊：<br>
輸入(4)來選擇「編輯學生資訊」，用法為先輸入要編輯那位學生的「學號」，然後再接著輸入「姓名、學號及成績」。<br><br>

刪除學生：<br>
輸入(5)來選擇「刪除學生功能」，只要輸入該生的學號就即可將該生的資料從記錄中刪除。<br><br>

保存到文件：<br>
輸入(6)來選擇「保存到文件」功能，此功能就是將剛剛使用者所做的動作例如「新增、刪除學生」儲存下來，每一次使用該程式都可以利用這個功能手動儲存資料。<br><br>

退出：<br>
輸入(0)來選擇「保存並退出」功能，將該程式退出，此功能會連帶儲存功能。<br>

## 功能條列說明
新增學生資訊<br>
顯示學生資訊<br>
查詢學生資訊<br>
編輯學生資訊<br>
刪除學生資訊<br>
保存到文件<br>
載入學生資訊<br>
退出<br>

## 程式結構圖
主程式流程:

一.開始<br><br>
初始化學生資訊數組和計數變數<br>
顯示功能選單<br>
根據用戶輸入的選擇執行相應的功能<br>
如果選擇為0，退出循環<br>
結束 <br><br>

二.新增學生流程<br><br>
顯示新增學生標題<br>
如果學生數未滿上限<br>
輸入學生姓名<br>
輸入學生學號<br>
輸入學生成績<br>
將學生資訊保存到數組<br>
學生數加一<br>
顯示新增成功消息<br>
否則，顯示系統滿提示<br>
返回主程式<br><br>

三.顯示學生資訊流程<br><br>
如果學生數大於0<br>
顯示學生資訊標題<br>
顯示表頭（姓名、學號、成績）<br>
遍歷學生數組，顯示每個學生的姓名、學號、成績<br>
否則，顯示沒有學生資訊提示<br>
返回主程式<br><br>

四.查詢學生流程<br><br>
輸入要查詢的學號<br>
顯示查詢結果表頭（姓名、學號、成績）<br>
遍歷學生數組，如果找到匹配學號的學生，顯示該學生的姓名、學號、成績<br>
如果找不到，顯示找不到學生提示<br>
返回主程式<br><br>

五.編輯學生資訊流程<br><br>
輸入要編輯的學號<br>
遍歷學生數組，如果找到匹配學號的學生<br>
輸入新的學生姓名、學號、成績<br>
更新該學生的資訊<br>
顯示編輯成功消息<br>
如果找不到，顯示找不到學生提示<br>
返回主程式<br><br>

六.刪除學生流程<br><br>
輸入要刪除的學號<br>
遍歷學生數組，如果找到匹配學號的學生<br>
將要刪除的學生之後的內容整體往前移動<br>
學生數減一<br>
顯示刪除成功消息<br>
如果找不到，顯示找不到學生提示<br>
返回主程式<br><br>

七.保存到文件流程<br><br>
打開文件以寫入模式<br>
如果成功打開文件<br>
遍歷學生數組，將每個學生的資訊寫入文件<br>
關閉文件<br>
顯示保存成功消息<br>
否則，顯示無法打開文件提示<br>
返回主程式<br><br>

八.從文件載入流程<br><br>
打開文件以讀取模式<br>
如果成功打開文件<br>
遍歷文件，讀取每個學生的資訊<br>
將學生資訊保存到學生數組<br>
學生數加一<br>
顯示載入成功消息<br>
關閉文件<br>
否則，顯示無法打開文件提示<br>
返回主程式<br>

## 流程圖
![程式流程圖](https://github.com/codingnoooob/41243215/blob/main/Untitled%20diagram-2023-12-26-045442.png?raw=true)

## 技術使用說明
* 規劃
   * 流程圖 --Chap1--
   * 標頭檔 --Chap7--
   * 撰寫或測試時使用中斷點 --Chap2--

* 程式
   * 定義：使用 #define 指令來定義常數 --Chap2--
   * 結構：利用結構定義了 Student 來表示學生的信息，包括姓名、學號和成績 --Chap9--
   * 結構陣列：程式使用結構陣列來存儲多個學生的信息 --Chap9--
   * 文件輸入/輸出：程式包含了用於讀取和寫入文件的函數 (saveToFile 和 loadFromFile)。使用 fopen、fclose 和 fprintf 進行寫入，以及 fopen、fclose 和 fscanf 進行讀取 --Chap10--
   * 函數：程式定義了多個函數 (addStudent、displayStudents、searchStudent、editStudent、deleteStudent、saveToFile、loadFromFile) 來模塊化和組織代碼 --Chap4,7--
   * 迴圈：程式在 main 函數中使用 do-while while 以及 for 循環，重複顯示菜單並根據用戶輸入執行相應的操作，直到用戶選擇退出（輸入0） --Chap4,6--
   * 開關語句：主迴圈中使用 switch 語句根據用戶輸入選擇的操作 --Chap5--
   * 輸入/輸出：使用 printf 和 scanf 函數進行輸入和輸出操作 --Chap3--
   * 條件式：使用 if-else 來檢查條件，例如確定是否要添加新學生或檢查系統是否已滿 --Chap5-- 判斷(==,>=,!=,&&,||) --Chap4--
   * 浮點數float：使用浮點數來表示學生的成績 --Chap2--
   * 字串：使用字串來存儲學生的姓名 --Chap3--
   * 指標和內存分配：使用 malloc 和 free 函數進行動態內存分配 --Chap8--

## 心得
其中經歷了非常多的困難，像是基本的迴圈參數設定，經過幾百回思考以及重試才得以解開等等等...在寫程式的過程中，我又更靈活的運用的自訂函式的用法，這讓我在看程式的時候變得更簡潔看得懂。其中用到指標的時候，我覺得指標算是我最不拿手的一種技術吧，在撰寫過程中查詢了很多資料也一直來回看老師給的PPT，花了不少時間才把指標的部分完成。在挑選題目的時候，我有在想要自己寫出一種類似管理系統的程式，所以我就選擇了學生成績管理系統，雖然現在的功能其實還不算多，但我相信如果我繼續下去以及再研究更多更多寫程式的技巧，一定可以將程式寫得更精巧、更多功能以及更多用法。

## 開發時間

2023/11/24, 4hr<br>
2023/11/29, 2hr<br>
2023/12/08, 3hr<br>
2023/12/15, 3hr<br>
2023/12/25, 2hr<br>

