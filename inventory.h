#include<iostream>
#include<iomanip>
#include <windows.h>
#define red 252
#define black 240
using namespace std;


void gotoXY(int x, int y){
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
	COORD CursorPosition; // used for goto
	CursorPosition.X = x; 
	CursorPosition.Y = y; 
	SetConsoleCursorPosition(console,CursorPosition); 
}

int wherex(){
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  if (!GetConsoleScreenBufferInfo(
         GetStdHandle( STD_OUTPUT_HANDLE ),
         &csbi
         ))
	return -1;
  return csbi.dwCursorPosition.X+1;
}
int wherey(){
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  if (!GetConsoleScreenBufferInfo(
         GetStdHandle( STD_OUTPUT_HANDLE ),
         &csbi
         ))
    return -1;
  return csbi.dwCursorPosition.Y;
}

int columns, rows;
void getSizeConsole() 
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = (csbi.srWindow.Right - csbi.srWindow.Left + 1)/2;
    rows = (csbi.srWindow.Bottom - csbi.srWindow.Top + 1)/2;

}

int pushStruk();
int generateStruk();
int borrow();
void setcolor(unsigned short color){
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,color);
}

void setcursor(int kolom, int baris){
	//HANDLE hStdout;
	COORD destCoord;
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	destCoord.X = kolom;
	destCoord.Y = baris;
	SetConsoleCursorPosition(hStdout, destCoord);
}
bool option;
void myNotif(){
	int choice_menu=0, x=rows;
	bool running = true;
	option=false;
	while(running!=false){
		system("cls");
		getSizeConsole();
		//24,14
		//15,2
		// setcursor(45,(rows-5));	cout<<"choice_menu: "<<choice_menu <<" x: "<<x <<" run: "<<running <<" option: "<<option;
		setcursor(0,(rows-3));
		cout<<setiosflags(ios::right)<<setw(columns-15)<<"";	putchar(201);	for(int i=0;i<29;i++){putchar(205);}	putchar(187);	cout<<endl;
		cout<<setiosflags(ios::right)<<setw(columns-15)<<"";	putchar(186);	cout<<setw(8)<<""<<"Are You Sure?"<<setw(8)<<"";	putchar(186);	cout<<endl;
		cout<<setiosflags(ios::right)<<setw(columns-15)<<"";	putchar(204);	for(int i=0;i<29;i++){putchar(205);}	putchar(185);	cout<<endl;
		cout<<setiosflags(ios::right)<<setw(columns-15)<<"";	putchar(186);	for(int i=0;i<29;i++){putchar(0);}	putchar(186);	cout<<endl;
		cout<<setiosflags(ios::right)<<setw(columns-15)<<"";	putchar(186);
		cout<<setw(4)<<"";				if(choice_menu==0){setcolor(0x0f);};
		cout<<"[YES]";					setcolor(0xf0);
		cout<<setw(12)<<"";				if(choice_menu==1){setcolor(0x0f);};
		cout<<"[NO]";					setcolor(0xf0);
		cout<<setw(4)<<"";
		putchar(186);	cout<<endl;
		cout<<setiosflags(ios::right)<<setw(columns-15)<<"";	putchar(186);	for(int i=0;i<29;i++){putchar(0);}	putchar(186);	cout<<endl;
		cout<<setiosflags(ios::right)<<setw(columns-15)<<" ";	putchar(200);	for(int i=0;i<29;i++){putchar(205);}	putchar(188);	cout<<endl;
		system("pause>nul"); // the >nul bit causes it the print no message
		if(GetAsyncKeyState(VK_RETURN) & 0x8000){ // Enter key pressed
			if(choice_menu==0){		//YES
				option=true;
				running=false;
				break;
			}
			if(choice_menu==1){		//NO
				option=false;
				running=false;
				break;
			}
		}
		else if(GetAsyncKeyState(VK_RIGHT) & 0x8000){ // Right button pressed
			if (choice_menu != 1){
				//gotoXY(1,x); cout << "  ";
				x++;
				//gotoXY(1,x); cout << ">";
				choice_menu++;
				continue;
			};
			if (choice_menu ==1){
				//gotoXY(1,x); cout << "  ";
				x=rows;
				//gotoXY(1,x); cout << ">";
				choice_menu=0;
				continue;
			};
		}
		else if(GetAsyncKeyState(VK_LEFT) & 0x8000){ // Left button pressed
			if (choice_menu != 0){
				//gotoXY(1,x); cout << "  ";
				x--;
				//gotoXY(1,x); cout << ">";
				choice_menu--;
				continue;
			};
			if (choice_menu ==0){
				//gotoXY(1,x); cout << "  ";
				x=rows;
				//gotoXY(1,x); cout << ">";
				choice_menu=1;
				continue;
			};
		}
	}
}

void myPause( const string& prompt = "" ){
	cout<<"Press enter to continue . . . ";
	string result;
	// Set the console mode to no-echo, not-line-buffered input
	DWORD mode, count;
	HANDLE ih = GetStdHandle( STD_INPUT_HANDLE  );
	HANDLE oh = GetStdHandle( STD_OUTPUT_HANDLE );
	if (!GetConsoleMode( ih, &mode ))
	throw runtime_error(
		"getpassword: You must be connected to a console to use this program.\n"
		);
	SetConsoleMode( ih, mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT) );

	// Get input string
	WriteConsoleA( oh, prompt.c_str(), prompt.length(), &count, NULL );
	char in;
	while (ReadConsoleA( ih, &in, 1, &count, NULL) && (in != '\r') && (in != '\n')){
		
	}
	// Restore the console mode
	SetConsoleMode( ih, mode );
}

string myInput( const string& prompt = "" ){
	string result;
	// Set the console mode to no-echo, not-line-buffered input
	DWORD mode, count;
	HANDLE ih = GetStdHandle( STD_INPUT_HANDLE  );
	HANDLE oh = GetStdHandle( STD_OUTPUT_HANDLE );
	if (!GetConsoleMode( ih, &mode ))
	throw runtime_error(
		"getpassword: You must be connected to a console to use this program.\n"
		);
	SetConsoleMode( ih, mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT) );

	// Get input string
	WriteConsoleA( oh, prompt.c_str(), prompt.length(), &count, NULL );
	char c;
	while (ReadConsoleA( ih, &c, 1, &count, NULL) && (c != '\r') && (c != '\n')){
		if (c == '\b'){
			if (result.length()){
				WriteConsoleA( oh, "\b \b", 3, &count, NULL );
				result.erase( result.end() -1 );
			}
		}
		else if(result.length()==0 && c==' '){
			WriteConsoleA( oh, "", 0, &count, NULL );
		}
		else if(c=='-' || c=='.' || c!='\t' && !(c>='!' && c<='/') && !(c>='[' && c<='`') && !(c>='{' && c<='~') && !(c>=':' && c<='@') && result.length()<10){
			WriteConsoleA( oh, &c, 1, &count, NULL );
			result.push_back( c );
		}
	}
	// Restore the console mode
	SetConsoleMode( ih, mode );
	cout<<endl;
	return result;
}

string inputChoose( const string& prompt = "" ){
	string result;
	// Set the console mode to no-echo, not-line-buffered input
	DWORD mode, count;
	HANDLE ih = GetStdHandle( STD_INPUT_HANDLE  );
	HANDLE oh = GetStdHandle( STD_OUTPUT_HANDLE );
	if (!GetConsoleMode( ih, &mode ))
	throw runtime_error(
		"getpassword: You must be connected to a console to use this program.\n"
		);
	SetConsoleMode( ih, mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT) );

	// Get input string
	WriteConsoleA( oh, prompt.c_str(), prompt.length(), &count, NULL );
	char c;
	while (ReadConsoleA( ih, &c, 1, &count, NULL) && (c != '\r') && (c != '\n')){
		if (c == '\b'){
			if (result.length()){
				WriteConsoleA( oh, "\b \b", 3, &count, NULL );
				result.erase( result.end() -1 );
			}
		}
		else if(result.length()==0 && c==' '){
			WriteConsoleA( oh, "", 0, &count, NULL );
		}
		else if(c!='\t' && !(c>='!' && c<='/') && !(c>='[' && c<='`') && !(c>='{' && c<='~') && !(c>=':' && c<='@') && result.length()<1){
			WriteConsoleA( oh, &c, 1, &count, NULL );
			result.push_back( c );
		}
	}
	// Restore the console mode
	SetConsoleMode( ih, mode );
	cout<<endl;
	return result;
}

string tglPlus,blnPlus,thnPlus;
int tmp1, tmp2, tmp3, tmp;
int t[9];
int bo,cd,eb;
//int bo=2-(user[tmpI].BO), cd=2-(user[tmpI].CD), eb=2-(user[tmpI].EB);
string Penulis[9]={"Mr.A","Mr.B","Mr.C","Mr.A","Mr.B","Mr.C","Mr.A","Mr.B","Mr.C"};
string Penerbit[9]={"PT.C","PT.A","PT.B","PT.B","PT.C","PT.A","PT.A","PT.B","PT.C"};
string CodeItm[9]={"bo1","bo2","bo3","cd1","cd2","cd3","eb1","eb2","eb3"};
string NumItm[9]={"1","2","3","4","5","6","7","8","9"};
string NmItm[9]={"Buku A  ","Buku B  ","Buku C  ","CD/DVD A","CD/DVD B","CD/DVD C","E-Book A","E-Book B","E-Book C"};
string Nm[9]={"Buku A","Buku B","Buku C","CD/DVD A","CD/DVD B","CD/DVD C","E-Book A","E-Book B","E-Book C"};
string ListItm[9]={"  Buku A  ","  Buku B  ","  Buku C  "," CD/DVD A "," CD/DVD B "," CD/DVD C "," E-Book A "," E-Book B "," E-Book C "};
int ItmPjm[9];
			   
int QtItm[9]={2,2,2,	//bo1,bo2,bo3	//////////////////////////////
			  2,2,2,	//cd1,cd2,cd3	//	Item Tersedia Default	//
			  2,2,2};	//eb1,eb2,eb3	//////////////////////////////

void convert(int tgl,int bln,int thn);
			  
int tglPjm, blnPjm, thnPjm, MyKabisat;
void DatePinjam(){	//Input waktu pinjam
	cout<<"\n";
klrBln1:
	cout<<"  Tahun Pinjam(>0)\t: "; cin>>thnPjm;			setcolor(240);
	MyKabisat=thnPjm%4;	//Menentukan tahun kabisat
	if(thnPjm>0){
klrBln2:
	cout<<"  Bulan Pinjam(1-12)\t: "; cin>>blnPjm;					setcolor(240);
		if(blnPjm==1||blnPjm==3||blnPjm==5||blnPjm==7||blnPjm==8||blnPjm==10||blnPjm==12){	//Bulan dgn 31 hari
klrBln3:
			cout<<"  Tanggal Pinjam(1-31)\t: "; cin>>tglPjm;			setcolor(240);
			if(tglPjm>=1&&tglPjm<=31){}
			else{
				setcolor(252);
				goto klrBln3;
			}
		}
		else if (blnPjm==4||blnPjm==6||blnPjm==9||blnPjm==11){	//Bulan dgn 30 hari
klrBln4:
			cout<<"  Tanggal Pinjam(1-30)\t: "; cin>>tglPjm;			setcolor(240);
			if(tglPjm>=1&&tglPjm<=30){}
			else{
				setcolor(252);
				goto klrBln4;
			}
		}
		else if (blnPjm==2){	//Bulan februari
			if (MyKabisat==0){	//Kabisat
klrBln5:
				cout<<"  Tanggal Pinjam(1-29)\t: "; cin>>tglPjm;		setcolor(240);
				if(tglPjm>=1&&tglPjm<=29){}
				else{
					setcolor(252);
					goto klrBln5;
				}
			}
			else{	//Bukan kabisat
klrBln6:
				cout<<"  Tanggal Pinjam(1-28)\t: "; cin>>tglPjm;		setcolor(240);
				if(tglPjm>=1&&tglPjm<=28){}
				else{
					setcolor(252);
					goto klrBln6;
				}
			}
		}
		else{
			setcolor(252);
			goto klrBln2;
		}
	}
	else{
		setcolor(252);
		goto klrBln1;
	}
	convert(tglPjm,blnPjm,thnPjm);
}

int tglM, blnM, thnM;
void DateKembali(){
mskBln1:
	cout<<"  Tahun Kembali(>="<<thnPjm<<")\t: "; cin>>thnM;			setcolor(240);
	MyKabisat=thnM%4;	//Menentukan tahun kabisat
	if(thnM>thnPjm){	//Jika tahun pengembalian > tahun pinjam
mskBln2:
	cout<<"  Bulan Kembali(1-12)\t: "; cin>>blnM;					setcolor(240);
		if(blnM==1||blnM==3||blnM==5||blnM==7||blnM==8||blnM==10||blnM==12){	//Bulan dgn 31 hari
mskBln3:
			cout<<"  Tanggal Kembali(1-31)\t: "; cin>>tglM;			setcolor(240);
			if(tglM>=1&&tglM<=31){}
			else{
				setcolor(252);
				goto mskBln3;
			}
		}
		else if (blnM==4||blnM==6||blnM==9||blnM==11){	//Bulan dgn 30 hari
mskBln4:
			cout<<"  Tanggal Kembali(1-30)\t: "; cin>>tglM;			setcolor(240);
			if(tglM>=1&&tglM<=30){}
			else{
				setcolor(252);
				goto mskBln4;
			}
		}
		else if (blnM==2){	//Bulan februari
			if (MyKabisat==0){	//Kabisat
mskBln5:
				cout<<"  Tanggal Kembali(1-29)\t: "; cin>>tglM;		setcolor(240);
				if(tglM>=1&&tglM<=29){}
				else{
					setcolor(252);
					goto mskBln5;
				}
			}
			else{	//Bukan kabisat
mskBln6:
				cout<<"  Tanggal Kembali(1-28)\t: "; cin>>tglM;		setcolor(240);
				if(tglM>=1&&tglM<=28){}
				else{
					setcolor(252);
					goto mskBln6;
				}
			}
		}
		else{
			setcolor(252);
			goto mskBln2;
		}
	}
	else if(thnM==thnPjm){	//Jika tahun pengembalian = tahun pinjam
mskBln7:
	cout<<"  Bulan Kembali("<<blnPjm<<"-12)\t: "; cin>>blnM;					setcolor(240);
		if(blnPjm<=blnM){
			if(blnM==1||blnM==3||blnM==5||blnM==7||blnM==8||blnM==10||blnM==12){	//Bulan dgn 30 hari
mskBln8:
				if(blnPjm==blnM){
					cout<<"  Tanggal Kembali("<<tglPjm<<"-31)\t: "; cin>>tglM;			setcolor(240);
					if(tglM>=tglPjm&&tglM<=31){}
					else{
						setcolor(252);
						goto mskBln8;
					}
				}
				else{
					cout<<"  Tanggal Kembali(1-31)\t: "; cin>>tglM;			setcolor(240);
					if(tglM>=1&&tglM<=31){}
					else{
						setcolor(252);
						goto mskBln8;
					}
				}
			}
			else if (blnM==4||blnM==6||blnM==9||blnM==11){	//Bulan dgn 30 hari
mskBln9:
				if(blnPjm==blnM){
					cout<<"  Tanggal Kembali("<<tglPjm<<"-30)\t: "; cin>>tglM;			setcolor(240);
					if(tglM>=tglPjm&&tglM<=30){}
					else{
						setcolor(252);
						goto mskBln9;
					}
				}
				else{
					cout<<"  Tanggal Kembali(1-30)\t: "; cin>>tglM;			setcolor(240);
					if(tglM>=1&&tglM<=30){}
					else{
						setcolor(252);
						goto mskBln9;
					}
				}
			}
			else if (blnM==2){	//Bulan februari
				if (MyKabisat==0){	//Kabisat
mskBln10:
					if(blnPjm==blnM){	//Jika bulan pinjam dan pengembalian sama
						cout<<"  Tanggal Kembali("<<tglPjm<<"-29)\t: "; cin>>tglM;			setcolor(240);
						if(tglM>=tglPjm&&tglM<=29){}
						else{
							setcolor(252);
							goto mskBln10;
						}
					}
					else{	//Jika bulan pinjam dan pengembalian beda
						cout<<"  Tanggal Kembali(1-29)\t: "; cin>>tglM;			setcolor(240);
						if(tglM>=1&&tglM<=29){}
						else{
							setcolor(252);
							goto mskBln10;
						}
					}
				}
				else{	//Bukan kabisat
mskBln11:
					if(blnPjm==blnM){	//Jika bulan pinjam dan pengembalian sama
						cout<<"  Tanggal Kembali("<<tglPjm<<"-28)\t: "; cin>>tglM;			setcolor(240);
						if(tglM>=tglPjm&&tglM<=28){}
						else{
							setcolor(252);
							goto mskBln11;
						}
					}
					else{	//Jika bulan pinjam dan pengembalian beda
						cout<<"  Tanggal Kembali(1-28)\t: "; cin>>tglM;			setcolor(240);
						if(tglM>=1&&tglM<=28){}
						else{
							setcolor(252);
							goto mskBln11;
						}
					}
				}
			}
			else{
				setcolor(252);
				goto mskBln7;
			}
		}
		else{
			setcolor(252);
			goto mskBln7;
		}
	}
	else{
		setcolor(252);
		goto mskBln1;
	}
}

int month_days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
int kabisat, patch2, days;
void tenggang(){	//Menghitung masa pinjam+denda
	kabisat=0, patch2=0, days=0;
	patch2=thnM;
back_patch:
	if (patch2<thnPjm){}
	else{	//Mencari hari tambahan kabisat
		MyKabisat=patch2;
		patch2-=1;
		for (int i=0;4<=MyKabisat;i++){
			MyKabisat-=4;
			if (MyKabisat==0){
				kabisat+=1;
			}
			else{
			
			}
		}
		goto back_patch;
	}
		
    if(thnPjm == thnM)
    {
        if(blnPjm == blnM)
            days = tglM - tglPjm;
        else
        {
            for(int i = blnPjm; i < blnM-1;i++)
                days += month_days[i];
			if((blnPjm==1||blnPjm==2)&&blnM>2){
				days += kabisat+month_days[blnPjm-1] - tglPjm + tglM;}
			else{
				days += month_days[blnPjm-1] - tglPjm + tglM;}
        }
    }
    else
    {
        for(int i = 0; i < blnM-1; i++)
            days += month_days[i];
        for(int i = blnPjm; i < 12; i++)
            days += month_days[i];
        if(thnM - thnPjm >= 0)
        days += (kabisat+((thnM - thnPjm - 1)*365 + month_days[blnPjm-1] - tglPjm + tglM));
    }
	cout << "\nMasa Pinjam\t: ";
	if (days<=7){
		setcolor(242);
		cout<< days<<" hari"<<endl;
		setcolor(240);
		cout<<"Terlambat\t: ";
		setcolor(242);
		cout<<"0 hari x Rp. 500 x "<<tmp <<" item"<<endl;
		setcolor(240);
		cout<<"Tagihan/Denda\t: ";	setcolor(242);
		cout<<"Rp. 0";
		setcolor(240);
	}
	else{
		setcolor(252);
		cout<< days<<" hari"<<endl;
		setcolor(240);
		cout<<"Terlambat\t: ";
		setcolor(252);
		cout<< days-7<<" hari x Rp. 500 x "<<tmp <<" item"<<endl;
		setcolor(240);
		cout<<"Tagihan/Denda\t: ";	setcolor(252);	cout<<"Rp. ";
		cout<<(days-7)*(500*(tmp));
		setcolor(240);
	}
	tmp=0;
	kabisat=0, patch2=0, days=0;
}

int set_rows;
void logo(){
	setcolor(245);
	set_rows=0+ (rows-14);
	setcursor(0, set_rows );
	cout<<setiosflags(ios::right)<<setw(columns-24)<<" ";	putchar(201);	for(int i=0;i<48;i++){putchar(205);}	putchar(187);	cout<<endl;
	cout<<setiosflags(ios::right)<<setw(columns-24)<<" ";	putchar(186);	putchar(0);	putchar(201);	for(int i=0;i<44;i++){putchar(205);}	putchar(187);	putchar(0);	putchar(186);	cout<<endl;
	cout<<setiosflags(ios::right)<<setw(columns-24)<<" ";	putchar(186);	putchar(0);	putchar(186);	cout<<setw(44)<<" ";	putchar(186);	putchar(0);	putchar(186);	cout<<endl;
	cout<<setiosflags(ios::right)<<setw(columns-24)<<" ";	putchar(186);	putchar(0);	putchar(186);	cout<<"                ``   :yNm+`                 ";	putchar(186);	putchar(0);	putchar(186);	cout<<endl;
	cout<<setiosflags(ios::right)<<setw(columns-24)<<" ";	putchar(186);	putchar(0);	putchar(186);	cout<<"              :hNy.omMMMMmNh/`              ";	putchar(186);	putchar(0);	putchar(186);	cout<<endl;
	cout<<setiosflags(ios::right)<<setw(columns-24)<<" ";	putchar(186);	putchar(0);	putchar(186);	cout<<"           -sNdoodMMMMNs- `/hNy:            ";	putchar(186);	putchar(0);	putchar(186);	cout<<endl;
	cout<<setiosflags(ios::right)<<setw(columns-24)<<" ";	putchar(186);	putchar(0);	putchar(186);	cout<<"        `omMh. +MMMMy:   `sMhood.           ";	putchar(186);	putchar(0);	putchar(186);	cout<<endl;
	cout<<setiosflags(ios::right)<<setw(columns-24)<<" ";	putchar(186);	putchar(0);	putchar(186);	cout<<"        :MMMN`  :y/` `   oMMMMNy-           ";	putchar(186);	putchar(0);	putchar(186);	cout<<endl;
	cout<<setiosflags(ios::right)<<setw(columns-24)<<" ";	putchar(186);	putchar(0);	putchar(186);	cout<<"         yMMMs";setcolor(254);cout<<"    +dMMMmo";setcolor(245);cout<<"``+mMMMMmo.        ";	putchar(186);	putchar(0);	putchar(186);	cout<<endl;
	cout<<setiosflags(ios::right)<<setw(columns-24)<<" ";	putchar(186);	putchar(0);	putchar(186);	cout<<"         `NMMM-  ";setcolor(254);cout<<"hMMNhNMMm";setcolor(245);cout<<"   -sNMMMm        ";	putchar(186);	putchar(0);	putchar(186);	cout<<endl;
	cout<<setiosflags(ios::right)<<setw(columns-24)<<" ";	putchar(186);	putchar(0);	putchar(186);	cout<<"        yy/MMMm  ";setcolor(254);cout<<"MMMs  MMM.";setcolor(245);cout<<"     :NM:        ";	putchar(186);	putchar(0);	putchar(186);	cout<<endl;
	cout<<setiosflags(ios::right)<<setw(columns-24)<<" ";	putchar(186);	putchar(0);	putchar(186);	cout<<"        oM/hMNd- ";setcolor(254);cout<<"/NMMMMMMo";setcolor(245);cout<<" /dyo.-My         ";	putchar(186);	putchar(0);	putchar(186);	cout<<endl;
	cout<<setiosflags(ios::right)<<setw(columns-24)<<" ";	putchar(186);	putchar(0);	putchar(186);	cout<<"         mN.`    ";setcolor(254);cout<<" `/sys+`";setcolor(245);cout<<" `NMMM:mN`         ";	putchar(186);	putchar(0);	putchar(186);	cout<<endl;
	cout<<setiosflags(ios::right)<<setw(columns-24)<<" ";	putchar(186);	putchar(0);	putchar(186);	cout<<"         -Mh+++++/////    yMMMsoM/          ";	putchar(186);	putchar(0);	putchar(186);	cout<<endl;
	cout<<setiosflags(ios::right)<<setw(columns-24)<<" ";	putchar(186);	putchar(0);	putchar(186);	cout<<"          sMMMMMMMMMMM`  :MMMN`.-           ";	putchar(186);	putchar(0);	putchar(186);	cout<<endl;
	cout<<setiosflags(ios::right)<<setw(columns-24)<<" ";	putchar(186);	putchar(0);	putchar(186);	cout<<"          `yyyyyyyyyyy` `NMMMM:             ";	putchar(186);	putchar(0);	putchar(186);	cout<<endl;
	cout<<setiosflags(ios::right)<<setw(columns-24)<<" ";	putchar(186);	putchar(0);	putchar(186);	cout<<"                 +NNNNNNNMMMy               ";	putchar(186);	putchar(0);	putchar(186);	cout<<endl;
	cout<<setiosflags(ios::right)<<setw(columns-24)<<" ";	putchar(186);	putchar(0);	putchar(186);	cout<<setw(44)<<" ";	putchar(186);	putchar(0);	putchar(186);	cout<<endl;
	//cout<<setiosflags(ios::right)<<setw(columns-24)<<" "<<"**                                 ";setcolor(252);cout<<"v.1.1.beta";setcolor(245);cout<<" **"<<endl;
	cout<<setiosflags(ios::right)<<setw(columns-24)<<" ";	putchar(186);	putchar(0);	putchar(186);	setcolor(252);cout<<" Create by Mr.J";	setcolor(240);	cout<<"                  ";setcolor(252);cout<<"v.1.1.beta ";setcolor(245);	putchar(186);	putchar(0);	putchar(186);	cout<<endl;
	cout<<setiosflags(ios::right)<<setw(columns-24)<<" ";	putchar(186);	putchar(0);	putchar(204);	for(int i=0;i<44;i++){if(i==8||i==35){putchar(203);}	else{putchar(205);}}	putchar(185);	putchar(0);	putchar(186);	cout<<endl;
	cout<<setiosflags(ios::right)<<setw(columns-24)<<" ";	putchar(186);	putchar(0);	putchar(204);	for(int i=0;i<8;i++){putchar(205);}	putchar(185);	cout<<"  AMIKOM RESOURCE CENTER  ";	putchar(204);	for(int i=0;i<8;i++){putchar(205);}	putchar(185);	putchar(0);	putchar(186);	cout<<endl;
	cout<<setiosflags(ios::right)<<setw(columns-24)<<" ";	putchar(186);	putchar(0);	putchar(204);	for(int i=0;i<44;i++){if(i==8||i==35){putchar(202);}	else{putchar(205);}}	putchar(185);	putchar(0);	putchar(186);	cout<<endl;
	setcolor(240);
}

void history(){
	setcolor(31);
	cout<<"+--------------------------------------------------------------------------------------------------+\n";
	cout<<"|"<<setw(43)<<""<<setw(14)<<"History Pinjam"<<setw(43)<<"|\n";
	cout<<"+--------------------------------------------------------------------------------------------------+\n";
	for(int i=0;i<9;i++){
		cout<<"|"<<ListItm[i];
	}cout<<"|\n";
	cout<<"+--------------------------------------------------------------------------------------------------+\n";
	setcolor(240);
	for(int i=0;i<9;i++){
		cout<<"|"<<setiosflags(ios::right)<<setw(6) <<ItmPjm[i] <<setiosflags(ios::right)<<setw(5);
	}cout<<setw(6)<<"|\n";
	cout<<"+--------------------------------------------------------------------------------------------------+\n";
	cout<<"|"<<setiosflags(ios::right)<<setw(17) <<ItmPjm[0]+ItmPjm[1]+ItmPjm[2] <<setiosflags(ios::right)<<setw(16);
	cout<<"|"<<setiosflags(ios::right)<<setw(17) <<ItmPjm[3]+ItmPjm[4]+ItmPjm[5] <<setiosflags(ios::right)<<setw(16);
	cout<<"|"<<setiosflags(ios::right)<<setw(17) <<ItmPjm[6]+ItmPjm[7]+ItmPjm[8] <<setiosflags(ios::right)<<setw(17)<<"|\n";
	setcolor(31);
	cout<<"+--------------------------------------------------------------------------------------------------+\n";
	cout<<"|"<<setiosflags(ios::right)<<setw(50)<<(ItmPjm[0]+ItmPjm[1]+ItmPjm[2])+(ItmPjm[3]+ItmPjm[4]+ItmPjm[5])+(ItmPjm[6]+ItmPjm[7]+ItmPjm[8])<<setiosflags(ios::left)<<setw(50)<<"|\n";
	cout<<"+--------------------------------------------------------------------------------------------------+\n";
	setcolor(240);
	//cout<<"|"<<setiosflags(ios::right)<<setw(35)<<"Buku A\t|\tBuku B\t\t|\tBuku C"<<setiosflags(ios::right)<<setw(12)<<"|\n";
	//cout<<"|"<<setiosflags(ios::right)<<setw(43)<<"\tCD/DVD A\t|\tCD/DVD B\t|\tCD/DVD C\t|\tE-Book A\t|\tE-Book B\t|\tE-Book C\t|";
	//cout<<setiosflags(ios::right)<<setw(18)<<"No.2 Buku B ["<<QtItm[1] <<"]"<<"\t|";
	//cout<<setiosflags(ios::left)<<setw(18)<<"No.3 Buku C ["<<QtItm[2] <<"]"<<"\t|\n";
	//cout<<"+-----------------------------------------------------------------------+\n";

}

int hexColor,hexColor_devide,hexColor_green;
void history2(){
	setcolor(31);
	cout<<"+---------------------------------------------------------+\n";
	cout<<"|"<<setw(22)<<""<<setw(15)<<"History Pinjam"<<setw(22)<<"|\n";
	cout<<"+---------------------------------------------------------+\n";
	cout<<"| Kode |              |             Jml Pinjam            |\n";
	cout<<"| Itm  |   Nama Itm   +-----------------------------------+\n";
	cout<<"|      |              |  Per-Itm  | Jenis Itm |   Total   |\n";
	cout<<"+------+--------------+-----------+-----------+-----------+\n";
	for(int i=0;i<9;i++){
		if((i+1)%2==1){		//jika baris genap set young color
			if(QtItm[i]==0){hexColor=207;	hexColor_devide=207;	hexColor_green=202;}	//Jika stok item habis
			else{hexColor=112;	hexColor_devide=127;	hexColor_green=114;};				//Jika stok item tidak habis
		}
		else{				//jika baris ganjil set old color
			if(QtItm[i]==0){hexColor=79;	hexColor_devide=79;		hexColor_green=74;}		//Jika stok item habis
			else{hexColor=143;	hexColor_devide=143;	hexColor_green=138;};				//Jika stok item tidak habis
		};
		
		setcolor(hexColor_devide);	cout<<"|";		setcolor(hexColor);
		cout<<setw(4);					if(ItmPjm[i]!=0){setcolor(hexColor_green);};
		cout<<CodeItm[i]<<setw(3);		setcolor(hexColor);
		setcolor(hexColor_devide);	cout<<"|";		setcolor(hexColor);
		cout<<setw(9);					if(ItmPjm[i]!=0){setcolor(hexColor_green);};
		cout<<NmItm[i]<<setw(6);		setcolor(hexColor);
		setcolor(hexColor_devide);	cout<<"|";		setcolor(hexColor);
		cout<<setw(4);					if(ItmPjm[i]!=0){setcolor(hexColor_green);};
		cout<<ItmPjm[i] <<" pcs"<<setw(4);	setcolor(hexColor);
		if(i==1||i==4||i==7){
			if(i==1){cout<<"|"<<setw(4) <<ItmPjm[0]+ItmPjm[1]+ItmPjm[2] <<" pcs"<<setw(4)<<"|"<<setw(12);}
			else if(i==4){
				setcolor(hexColor_devide);	cout<<"|";		setcolor(hexColor);
				cout<<setw(4) <<ItmPjm[3]+ItmPjm[4]+ItmPjm[5] <<" pcs"<<setw(4);
				setcolor(hexColor_devide);	cout<<"|";		setcolor(hexColor);
				cout<<setw(4) <<(ItmPjm[0]+ItmPjm[1]+ItmPjm[2])+(ItmPjm[3]+ItmPjm[4]+ItmPjm[5])+(ItmPjm[6]+ItmPjm[7]+ItmPjm[8]) <<" pcs"<<setw(4);
			}
			else if(i==7){
				setcolor(hexColor_devide);	cout<<"|";		setcolor(hexColor);
				cout<<setw(4) <<ItmPjm[6]+ItmPjm[7]+ItmPjm[8] <<" pcs"<<setw(4)<<"|"<<setw(12);
			};
		}
		else{
			setcolor(hexColor_devide);	
			if((i+1)%3==0&&i!=8){
				cout<<"|"<<"___________|"<<setw(12);
			}
			else if(i==8){
				cout<<"|"<<"___________|___________"<<"|"<<setw(12);
			}
			else{
				cout<<"|"<<setw(12)<<"|"<<setw(12);
			};
		};
		if(i!=8){
			setcolor(hexColor_devide);	cout<<"|"<<endl;
		};
		/*if(i!=8&&((i+1)%3)==0){setcolor(hexColor_devide);
			cout<<"|------+--------------+-----------+-----------+           |\n";
		};*/
	}//cout<<"+---------------------------------------------------------+\n";	
	setcolor(240);
	
}

void historyNEW(){
	int row=0;
	setcolor(31);
	putchar(201);	for(int i=0;i<49;i++){putchar(205);}	putchar(187);	cout<<endl;
	putchar(186);	cout<<setw(18)<<""<<"Pinjaman Aktif"<<setw(17)<<"";	putchar(186);	cout<<endl;
	putchar(204);	for(int i=0;i<49;i++){if(i==6||i==21||i==30){putchar(203);}	else{putchar(205);}}	putchar(185);	cout<<endl;
	putchar(186);	cout<<" Kode ";	putchar(186);	cout<<"   Nama Itm   ";	putchar(186);	cout<<" Jumlah ";	putchar(186);	cout<<"  Tanggal Pinjam  ";	putchar(186);	cout<<endl;
	putchar(186);	cout<<" Itm  ";	putchar(186);	cout<<"              ";	putchar(186);	cout<<" Pinjam ";	putchar(186);	cout<<"                  ";	putchar(186);	cout<<endl;
	putchar(200);	for(int i=0;i<49;i++){if(i==6||i==21||i==30){putchar(202);}	else{putchar(205);}}	putchar(188);	cout<<endl;
	for(int i=0;i<9;i++){
		if((row+1)%2==1){		//jika baris genap set young color
			hexColor=112;	hexColor_devide=127;	hexColor_green=114;
		}
		else{				//jika baris ganjil set old color
			hexColor=143;	hexColor_devide=143;	hexColor_green=138;
		};
		//for(int j=0;j<9;j++){
			if(ItmPjm[i]>0){
				row++;
				setcolor(hexColor_devide);	cout<<"|";			setcolor(hexColor);
				cout<<setw(4);
				cout<<CodeItm[i]<<setw(3);
				setcolor(hexColor_devide);	cout<<"|";			setcolor(hexColor);
				cout<<setw(9);
				cout<<NmItm[i]<<setw(6);
				setcolor(hexColor_devide);	cout<<"|";			setcolor(hexColor);
				cout<<setw(2);
				cout<<ItmPjm[i] <<" pcs"<<setw(3);
				setcolor(hexColor_devide);	cout<<"|";			setcolor(hexColor);
				cout<<setw(2)<<"";
				cout<<tglPlus<<tglPjm<<" "<<blnPlus<<" "<<thnPlus<<thnPjm <<setw(6);
				setcolor(hexColor_devide);	cout<<"|"<<endl;	setcolor(hexColor);
				setcolor(240);
			}	
			else if(ItmPjm[0]==0&&ItmPjm[1]==0&&ItmPjm[2]==0&&ItmPjm[3]==0&&ItmPjm[4]==0
					&&ItmPjm[5]==0&&ItmPjm[6]==0&&ItmPjm[7]==0&&ItmPjm[8]==0){
				setcolor(hexColor_devide);
				cout<<"|      |              |        |                  |\n";	setcolor(240);	break;
			};
		//}
	}
	
}

void convert(int tgl,int bln,int thn){
	if(tgl<10){tglPlus="0";}
	else{tglPlus="";};
	
	if(bln==1){blnPlus="Jan";}
	else if(bln==2){blnPlus="Feb";}
	else if(bln==3){blnPlus="Mar";}
	else if(bln==4){blnPlus="Apr";}
	else if(bln==5){blnPlus="Mei";}
	else if(bln==6){blnPlus="Jun";}
	else if(bln==7){blnPlus="Jul";}
	else if(bln==8){blnPlus="Agt";}
	else if(bln==9){blnPlus="Sep";}
	else if(bln==10){blnPlus="Okt";}
	else if(bln==11){blnPlus="Nov";}
	else if(bln==12){blnPlus="Des";};
	
	if(thn>=10&&thn<100){thnPlus="20";}
	else if(thn<10){thnPlus="200";}
	else if(thn>=100&&thn<2000){thnPlus="2";};
}
string tmpCodeStruk;
void strukPjm(){
	putchar(201);	for(int i=0;i<11;i++){putchar(205);}	putchar(185);	cout<<" Struk Pinjam ";	putchar(204);	for(int i=0;i<12;i++){putchar(205);}	putchar(187);	cout<<endl;
	putchar(186);	cout<<"         AMIKOM RESOURCE CENTER        ";	putchar(186);	cout<<endl;
	putchar(186);	cout<<"           Telp: 0274-12xxxx           ";	putchar(186);	cout<<endl;
	putchar(204);	for(int i=0;i<39;i++){putchar(205);}	putchar(185);	cout<<endl;
	putchar(186);	cout<<" Kode Struk : " <<tmpCodeStruk <<setw(25-tmpCodeStruk.length())<<"";	putchar(186);	cout<<endl;
	putchar(204);	for(int i=0;i<39;i++){if(i==10||i==26){putchar(203);}else{putchar(205);}}	putchar(185);	cout<<endl;
	putchar(186);	cout<<"   Kode" <<setw(3) <<"";	putchar(186);	cout<<setw(5) <<"" <<"Nama" <<setw(6) <<"";	putchar(186);	cout<<setw(4) <<"" <<"Jml " <<setw(4)<<"";	putchar(186);	cout<<endl;
	putchar(186);	cout<<"   Item" <<setw(3) <<"";	putchar(186);	cout<<setw(5) <<"" <<"Item" <<setw(6) <<"";	putchar(186);	cout<<setw(4) <<"" <<"Item" <<setw(4)<<"";	putchar(186);	cout<<endl;
	putchar(204);	for(int i=0;i<39;i++){if(i==10||i==26){putchar(206);}else{putchar(205);}}	putchar(185);	cout<<endl;
	for(int i=0;i<9;i++){
		if(ItmPjm[i]!=0){
			putchar(186);	cout<<" "<<CodeItm[i]<<setw(6)<<"";	putchar(186);	cout<<" "<<NmItm[i]<<setw(6)<<"";	putchar(186);	cout<<" "<<ItmPjm[i]<<" pcs" <<setw(6)<<"";	putchar(186);	cout<<endl;
		}
	}
	putchar(204);	for(int i=0;i<39;i++){if(i==10||i==26){putchar(202);}else{putchar(205);}}	putchar(185);	cout<<endl;
	putchar(186);	cout<<" Total      : " <<(ItmPjm[0]+ItmPjm[1]+ItmPjm[2])+(ItmPjm[3]+ItmPjm[4]+ItmPjm[5])+(ItmPjm[6]+ItmPjm[7]+ItmPjm[8]) <<" pcs" <<setw(25-5)<<"";	putchar(186);	cout<<endl;
	putchar(186);	cout<<" Tgl Pinjam : " <<tglPlus<<tglPjm<<" "<<blnPlus<<" "<<thnPlus<<thnPjm <<setw(25-11)<<"";	putchar(186);	cout<<endl;
	putchar(200);	for(int i=0;i<39;i++){putchar(205);}	putchar(188);	cout<<endl;
}
void structKmbl(){
	cout<<"+--------- Struct Pengembalian ---------+\n";
	cout<<"|         AMIKOM RESOURCE CENTER        |\n";
	cout<<"|           Telp: 0274-12xxxx           |\n";
	cout<<"+---------------------------------------+\n";
	cout<<"| Kode" <<setw(3) <<"|" <<setw(4) <<"" <<"Nama" <<setw(5) <<"|" <<setw(1) <<"" <<"Jml " <<setw(14) <<"|" <<endl;
	cout<<"| Item" <<setw(3) <<"|" <<setw(4) <<"" <<"Item" <<setw(5) <<"|" <<setw(1) <<"" <<"Item" <<setw(14) <<"|" <<endl;
	cout<<"+---------------------------------------+\n";
	for(int i=0;i<9;i++){
		if(ItmPjm[i]!=0){
			cout<<"| "<<CodeItm[i] <<setw(5) <<"" <<NmItm[i] <<setw(6) <<ItmPjm[i]<<" pcs" <<setw(13) <<"|" <<endl;
		}
	}
	cout<<"+---------------------------------------+\n";
	cout<<"| Total     : " <<setw(9) <<"" <<(ItmPjm[0]+ItmPjm[1]+ItmPjm[2])+(ItmPjm[3]+ItmPjm[4]+ItmPjm[5])+(ItmPjm[6]+ItmPjm[7]+ItmPjm[8]) <<" pcs" <<setw(13) <<"|" <<endl;
	cout<<"| Tgl Pinjam: " <<setw(3) <<"" <<tglPlus<<tglPjm<<" "<<blnPlus<<" "<<thnPlus<<thnPjm <<setw(13)<<"|"<<endl;
	cout<<"+---------------------------------------+\n";
}

void Library(){
	setcolor(31);
	putchar(201);	for(int i=0;i<61;i++){if(i==3||i==10||i==25||i==37||i==49){putchar(203);}	else{putchar(205);}}	putchar(187);	cout<<endl;
	putchar(186);	cout<<"No ";	putchar(186);	cout<<" Kode ";	putchar(186);	cout<<"   Nama Itm   ";	putchar(186);	cout<<"  Jml Item ";	putchar(186);	cout<<"  Penulis  ";	putchar(186);	cout<<" Penerbit  ";	putchar(186);	cout<<endl;
	putchar(186);	cout<<"   ";	putchar(186);	cout<<" Itm  ";	putchar(186);	cout<<"              ";	putchar(186);	cout<<"  Tersedia ";	putchar(186);	cout<<"           ";	putchar(186);	cout<<"           ";	putchar(186);	cout<<endl;
	putchar(200);	for(int i=0;i<61;i++){if(i==3||i==10||i==25||i==37||i==49){putchar(202);}	else{putchar(205);}}	putchar(188);	cout<<endl;
	for(int i=0;i<9;i++){
		if((i+1)%2==1){		//jika baris genap set young color
			if(QtItm[i]==0){hexColor=207;	hexColor_devide=207;	hexColor_green=202;}	//Jika stok item habis
			else{hexColor=112;	hexColor_devide=127;	hexColor_green=114;};				//Jika stok item tidak habis
		}
		else{				//jika baris ganjil set old color
			if(QtItm[i]==0){hexColor=79;	hexColor_devide=79;		hexColor_green=74;}		//Jika stok item habis
			else{hexColor=143;	hexColor_devide=143;	hexColor_green=138;};				//Jika stok item tidak habis
		};
		
		setcolor(hexColor_devide);				cout<<"|";	setcolor(hexColor);
		cout<<setw(2);							if(ItmPjm[i]!=0){setcolor(hexColor_green);};
		cout<<i+1<<setw(2);						setcolor(hexColor_devide);
		
		cout<<"|";
		cout<<setw(4);							setcolor(hexColor);	if(ItmPjm[i]!=0){setcolor(hexColor_green);};
		cout<<CodeItm[i]<<setw(3);				setcolor(hexColor_devide);
		
		cout<<"|";
		cout<<setw(9);							setcolor(hexColor);	if(ItmPjm[i]!=0){setcolor(hexColor_green);};
		cout<<NmItm[i]<<setw(6);				setcolor(hexColor_devide);
		
		cout<<"|";
		cout<<setw(4);							setcolor(hexColor);	if(ItmPjm[i]!=0){setcolor(hexColor_green);};
		cout<<QtItm[i] <<" pcs"<<setw(4);		setcolor(hexColor_devide);
		
		cout<<"|";								setcolor(hexColor);
		cout<<setw(8) <<Penulis[i] <<setw(4);	setcolor(hexColor_devide);
		
		cout<<"|";								setcolor(hexColor);
		cout<<setw(8) <<Penerbit[i];			setcolor(hexColor_devide);
		cout<<setw(5)<<"|\n";
		//if(i<8){cout<<"|---+------+--------------+-----------+-----------+-----------|\n";}
		//else{cout<<"+-------------------------------------------------------------+\n";};
	}setcolor(240);
	
}

string sort_CodeItm[9], sort_NmItm[9], sort_Penulis[9], sort_Penerbit[9];
int sort_QtItm[9];
//void SortEngine(int first,int last);

void Sort(){
	string tmpCode[9],tmpNm[9],tmpPenulis[9],tmpPenerbit[9];
	int tmpQt[9];
		
	for(int i=0;i<9;i++){
		/*tmpCode[i]=CodeItm[i];
		tmpNm[i]=NmItm[i];
		tmpQt[i]=QtItm[i];
		tmpPenulis[i]=Penulis[i];
		tmpPenerbit[i]=Penerbit[i];
		*/
		sort_CodeItm[i]	= CodeItm[i];
		sort_NmItm[i]	= NmItm[i];
		sort_QtItm[i]	= QtItm[i];
		sort_Penulis[i]	= Penulis[i];
		sort_Penerbit[i]= Penerbit[i];
	}
	
	for(int i=0;i<9;i++){
		string tempSort;
		for(int j=i+1;j<9;j++){
			if(sort_CodeItm[i]>sort_CodeItm[j]){
				tempSort=sort_CodeItm[i];
				sort_CodeItm[i]=sort_CodeItm[j];
				sort_CodeItm[j]=tempSort;
				
				tempSort=sort_NmItm[i];
				sort_NmItm[i]=sort_NmItm[j];
				sort_NmItm[j]=tempSort;
				
				tempSort=sort_Penulis[i];
				sort_Penulis[i]=sort_Penulis[j];
				sort_Penulis[j]=tempSort;
				
				tempSort=sort_Penerbit[i];
				sort_Penerbit[i]=sort_Penerbit[j];
				sort_Penerbit[j]=tempSort;
			}
		}
	}
}

void SortAscending(int first,int last){
	Sort();
	setcolor(31);
	putchar(201);	for(int i=0;i<61;i++){if(i==3||i==10||i==25||i==37||i==49){putchar(203);}	else{putchar(205);}}	putchar(187);	cout<<endl;
	putchar(186);	cout<<"No ";	putchar(186);	cout<<" Kode ";	putchar(186);	cout<<"   Nama Itm   ";	putchar(186);	cout<<"  Jml Item ";	putchar(186);	cout<<"  Penulis  ";	putchar(186);	cout<<" Penerbit  ";	putchar(186);	cout<<endl;
	putchar(186);	cout<<"   ";	putchar(186);	cout<<" Itm  ";	putchar(186);	cout<<"              ";	putchar(186);	cout<<"  Tersedia ";	putchar(186);	cout<<"           ";	putchar(186);	cout<<"           ";	putchar(186);	cout<<endl;
	putchar(200);	for(int i=0;i<61;i++){if(i==3||i==10||i==25||i==37||i==49){putchar(202);}	else{putchar(205);}}	putchar(188);	cout<<endl;
	for(int i=first;i<=last;i++){
		if((i+1)%2==1){		//jika baris genap set young color
			if(QtItm[i]==0){hexColor=207;	hexColor_devide=207;	hexColor_green=202;}	//Jika stok item habis
			else{hexColor=112;	hexColor_devide=127;	hexColor_green=114;};				//Jika stok item tidak habis
		}
		else{				//jika baris ganjil set old color
			if(QtItm[i]==0){hexColor=79;	hexColor_devide=79;		hexColor_green=74;}		//Jika stok item habis
			else{hexColor=143;	hexColor_devide=143;	hexColor_green=138;};				//Jika stok item tidak habis
		};
		
		setcolor(hexColor_devide);				cout<<"|";	setcolor(hexColor);
		cout<<setw(2);							if(ItmPjm[i]!=0){setcolor(hexColor_green);};
		cout<<i+1<<setw(2);						setcolor(hexColor_devide);
		
		cout<<"|";
		cout<<setw(4);							setcolor(hexColor);	if(ItmPjm[i]!=0){setcolor(hexColor_green);};
		cout<<sort_CodeItm[i]<<setw(3);				setcolor(hexColor_devide);
		
		cout<<"|";
		cout<<setw(9);							setcolor(hexColor);	if(ItmPjm[i]!=0){setcolor(hexColor_green);};
		cout<<sort_NmItm[i]<<setw(6);				setcolor(hexColor_devide);
		
		cout<<"|";
		cout<<setw(4);							setcolor(hexColor);	if(ItmPjm[i]!=0){setcolor(hexColor_green);};
		cout<<sort_QtItm[i] <<" pcs"<<setw(4);		setcolor(hexColor_devide);
		
		cout<<"|";								setcolor(hexColor);
		cout<<setw(8) <<sort_Penulis[i] <<setw(4);	setcolor(hexColor_devide);
		
		cout<<"|";								setcolor(hexColor);
		cout<<setw(8) <<sort_Penerbit[i];			setcolor(hexColor_devide);
		cout<<setw(5)<<"|\n";
		//if(i<8){cout<<"|---+------+--------------+-----------+-----------+-----------|\n";}
		//else{cout<<"+-------------------------------------------------------------+\n";};
	}setcolor(240);
}

void SortDescending(int first,int last){
	Sort();
	setcolor(31);
	int num=1;
	putchar(201);	for(int i=0;i<61;i++){if(i==3||i==10||i==25||i==37||i==49){putchar(203);}	else{putchar(205);}}	putchar(187);	cout<<endl;
	putchar(186);	cout<<"No ";	putchar(186);	cout<<" Kode ";	putchar(186);	cout<<"   Nama Itm   ";	putchar(186);	cout<<"  Jml Item ";	putchar(186);	cout<<"  Penulis  ";	putchar(186);	cout<<" Penerbit  ";	putchar(186);	cout<<endl;
	putchar(186);	cout<<"   ";	putchar(186);	cout<<" Itm  ";	putchar(186);	cout<<"              ";	putchar(186);	cout<<"  Tersedia ";	putchar(186);	cout<<"           ";	putchar(186);	cout<<"           ";	putchar(186);	cout<<endl;
	putchar(200);	for(int i=0;i<61;i++){if(i==3||i==10||i==25||i==37||i==49){putchar(202);}	else{putchar(205);}}	putchar(188);	cout<<endl;
	for(int i=first;i>=last;i--){
		if((i+1)%2==1){		//jika baris genap set young color
			if(QtItm[i]==0){hexColor=207;	hexColor_devide=207;	hexColor_green=202;}	//Jika stok item habis
			else{hexColor=112;	hexColor_devide=127;	hexColor_green=114;};				//Jika stok item tidak habis
		}
		else{				//jika baris ganjil set old color
			if(QtItm[i]==0){hexColor=79;	hexColor_devide=79;		hexColor_green=74;}		//Jika stok item habis
			else{hexColor=143;	hexColor_devide=143;	hexColor_green=138;};				//Jika stok item tidak habis
		};
		
		setcolor(hexColor_devide);				cout<<"|";	setcolor(hexColor);
		cout<<setw(2);							if(ItmPjm[i]!=0){setcolor(hexColor_green);};
		cout<<num<<setw(2);						setcolor(hexColor_devide);
		num++;
		cout<<"|";
		cout<<setw(4);							setcolor(hexColor);	if(ItmPjm[i]!=0){setcolor(hexColor_green);};
		cout<<sort_CodeItm[i]<<setw(3);				setcolor(hexColor_devide);
		
		cout<<"|";
		cout<<setw(9);							setcolor(hexColor);	if(ItmPjm[i]!=0){setcolor(hexColor_green);};
		cout<<sort_NmItm[i]<<setw(6);				setcolor(hexColor_devide);
		
		cout<<"|";
		cout<<setw(4);							setcolor(hexColor);	if(ItmPjm[i]!=0){setcolor(hexColor_green);};
		cout<<sort_QtItm[i] <<" pcs"<<setw(4);		setcolor(hexColor_devide);
		
		cout<<"|";								setcolor(hexColor);
		cout<<setw(8) <<sort_Penulis[i] <<setw(4);	setcolor(hexColor_devide);
		
		cout<<"|";								setcolor(hexColor);
		cout<<setw(8) <<sort_Penerbit[i];			setcolor(hexColor_devide);
		cout<<setw(5)<<"|\n";
		//if(i<8){cout<<"|---+------+--------------+-----------+-----------+-----------|\n";}
		//else{cout<<"+-------------------------------------------------------------+\n";};
	}setcolor(240);
}

void SearchEngine(string search){
	int j=0;
	int k=0;
	for (int i=0;i<9;i++){
	if(CodeItm[i]==search||Nm[i]==search||Penulis[i]==search||Penerbit[i]==search){
	k+=1;
		if(j==0){
			j+=1;
			setcolor(31);
			putchar(201);	for(int i=0;i<61;i++){if(i==3||i==10||i==25||i==37||i==49){putchar(203);}	else{putchar(205);}}	putchar(187);	cout<<endl;
			putchar(186);	cout<<"No ";	putchar(186);	cout<<" Kode ";	putchar(186);	cout<<"   Nama Itm   ";	putchar(186);	cout<<"  Jml Item ";	putchar(186);	cout<<"  Penulis  ";	putchar(186);	cout<<" Penerbit  ";	putchar(186);	cout<<endl;
			putchar(186);	cout<<"   ";	putchar(186);	cout<<" Itm  ";	putchar(186);	cout<<"              ";	putchar(186);	cout<<"  Tersedia ";	putchar(186);	cout<<"           ";	putchar(186);	cout<<"           ";	putchar(186);	cout<<endl;
			putchar(200);	for(int i=0;i<61;i++){if(i==3||i==10||i==25||i==37||i==49){putchar(202);}	else{putchar(205);}}	putchar(188);	cout<<endl;
		};
		if((i+1)%2==1){		//jika baris genap set young color
			if(QtItm[i]==0){hexColor=207;	hexColor_devide=207;	hexColor_green=202;}	//Jika stok item habis
			else{hexColor=112;	hexColor_devide=127;	hexColor_green=114;};				//Jika stok item tidak habis
		}
		else{				//jika baris ganjil set old color
			if(QtItm[i]==0){hexColor=79;	hexColor_devide=79;		hexColor_green=74;}		//Jika stok item habis
			else{hexColor=143;	hexColor_devide=143;	hexColor_green=138;};				//Jika stok item tidak habis
		};
		
		setcolor(hexColor_devide);				cout<<"|";	setcolor(hexColor);
		cout<<setw(2);							if(ItmPjm[i]!=0){setcolor(hexColor_green);};
		cout<<i+1<<setw(2);						setcolor(hexColor_devide);
		
		cout<<"|";
		cout<<setw(4);							setcolor(hexColor);	if(ItmPjm[i]!=0){setcolor(hexColor_green);};
		cout<<CodeItm[i]<<setw(3);				setcolor(hexColor_devide);
		
		cout<<"|";
		cout<<setw(9);							setcolor(hexColor);	if(ItmPjm[i]!=0){setcolor(hexColor_green);};
		cout<<NmItm[i]<<setw(6);				setcolor(hexColor_devide);
		
		cout<<"|";
		cout<<setw(4);							setcolor(hexColor);	if(ItmPjm[i]!=0){setcolor(hexColor_green);};
		cout<<QtItm[i] <<" pcs"<<setw(4);		setcolor(hexColor_devide);
		
		cout<<"|";								setcolor(hexColor);
		cout<<setw(8) <<Penulis[i] <<setw(4);	setcolor(hexColor_devide);
		
		cout<<"|";								setcolor(hexColor);
		cout<<setw(8) <<Penerbit[i];			setcolor(hexColor_devide);
		cout<<setw(5)<<"|\n";
	}
	else if(i==8&&k==0){
		setcolor(252);cout<<"!!! Not Founds !!!\n";break;};
	}
	setcolor(240);
	system("pause");
}

int out1,out2,out3,out4,out5,out6,out7,out8,out9;
char pinjam;
void turnOut(){
string idItm;
int jmlItm, hasil;
bool range=false;
turnOut1:
cout<<"Masukan Jumlah ITEM Yang Akan Di Pinjam(0-6): "; cin>>pinjam;
	if(pinjam>'0'&&pinjam<'7'){
		generateStruk();
		out1=0,out2=0,out3=0,out4=0,out5=0,out6=0,out7=0,out8=0,out9=0;
		for(char a='1'; a<=pinjam; a++){
			cout<<"ITEM ke-"<<a<<endl;
turnOut2:
			cout<<"  Masukan ID item\t\t: "; cin>>idItm;
			//if((idItm>="0" && idItm<="9")||(Code)){
//Input Null
				if(idItm=="0"){
					
				}
//Buku A
				else if(idItm=="1"||idItm==CodeItm[0]){
					if (tmp1<2){
turnOut3:
						cout<<"  Masukan Jumlah Buku A";
							if(range==false){setcolor(black);}
							else{setcolor(red);	range=false;}
						cout<<"(0-" <<bo <<")\t";	setcolor(black);	cout<<": ";	cin>>jmlItm;
						if(QtItm[0]<=0){
							setcolor(252);
							cout<<"!!! "<<Nm[0]<<" is OUT OF STOCK !!!\n";
							setcolor(240);
							goto turnOut2;
						}
						else if(jmlItm>=0&&jmlItm<=bo){
							out1+=jmlItm;
							ItmPjm[0]+=jmlItm;
							bo-=jmlItm;
							QtItm[0]-=jmlItm;
							t[0]+=jmlItm;
							tmp1+=jmlItm;
						}
						else{
							range=true;
							goto turnOut3;
						}
					}
					else{
						setcolor(252);
						cout<<"!!! BOOK QUOTA IS FULL !!!\n";
						setcolor(240);
						goto turnOut2;
					}
				}
//Buku B
				else if(idItm=="2"||idItm==CodeItm[1]){
					if (tmp1<2){
turnOut4:
						cout<<"  Masukan Jumlah Buku B";
							if(range==false){setcolor(black);}
							else{setcolor(red);	range=false;}
						cout<<"(0-" <<bo <<")\t";	setcolor(black);	cout<<": ";	cin>>jmlItm;
						if(QtItm[1]<=0){
							setcolor(252);
							cout<<"!!! "<<Nm[1]<<" is OUT OF STOCK !!!\n";
							setcolor(240);
							goto turnOut2;
						}
						else if(jmlItm>=0&&jmlItm<=bo){
							out2+=jmlItm;
							ItmPjm[1]+=jmlItm;
							bo-=jmlItm;
							QtItm[1]-=jmlItm;
							t[1]+=jmlItm;
							tmp1+=jmlItm;
						}
						else{
							range=true;
							goto turnOut4;
						}
					}
					else{
						setcolor(252);
						cout<<"!!! BOOK QUOTA IS FULL !!!\n";
						setcolor(240);
						goto turnOut2;
					}
				}
//Buku C
				else if(idItm=="3"||idItm==CodeItm[2]){
					if (tmp1<2){
turnOut5:
						cout<<"  Masukan Jumlah Buku C";
							if(range==false){setcolor(black);}
							else{setcolor(red);	range=false;}
						cout<<"(0-" <<bo <<")\t";	setcolor(black);	cout<<": ";	cin>>jmlItm;
						if(QtItm[2]<=0){
							setcolor(252);
							cout<<"!!! "<<Nm[2]<<" is OUT OF STOCK !!!\n";
							setcolor(240);
							goto turnOut2;
						}
						else if(jmlItm>=0&&jmlItm<=bo){
							out3+=jmlItm;
							ItmPjm[2]+=jmlItm;
							bo-=jmlItm;
							QtItm[2]-=jmlItm;
							t[2]+=jmlItm;
							tmp1+=jmlItm;
						}
						else{
							range=true;
							goto turnOut5;
						}
					}
					else{
						setcolor(252);
						cout<<"!!! BOOK QUOTA IS FULL !!!\n";
						setcolor(240);
						goto turnOut2;
					}
				}
//CD/DVD A
				else if(idItm=="4"||idItm==CodeItm[3]){
					if (tmp2<2){
turnOut6:
						cout<<"  Masukan Jumlah CD/DVD A";
							if(range==false){setcolor(black);}
							else{setcolor(red);	range=false;}
						cout<<"(0-" <<cd <<")\t";	setcolor(black);	cout<<": ";	cin>>jmlItm;
						if(QtItm[3]<=0){
							setcolor(252);
							cout<<"!!! "<<Nm[3]<<" is OUT OF STOCK !!!\n";
							setcolor(240);
							goto turnOut2;
						}
						else if(jmlItm>=0&&jmlItm<=cd){
							out4+=jmlItm;
							ItmPjm[3]+=jmlItm;
							cd-=jmlItm;
							QtItm[3]-=jmlItm;
							t[3]+=jmlItm;
							tmp2+=jmlItm;
						}
						else{
							range=true;
							goto turnOut6;
						}
					}
					else{
						setcolor(252);
						cout<<"!!! CD/DVD QUOTA IS FULL !!!\n";
						setcolor(240);
						goto turnOut2;
					}
				}
//CD/DVD B
				else if(idItm=="5"||idItm==CodeItm[4]){
					if (tmp2<2){
turnOut7:
						cout<<"  Masukan Jumlah CD/DVD B";
							if(range==false){setcolor(black);}
							else{setcolor(red);	range=false;}
						cout<<"(0-" <<cd <<")\t";	setcolor(black);	cout<<": ";	cin>>jmlItm;
						if(QtItm[4]<=0){
							setcolor(252);
							cout<<"!!! "<<Nm[4]<<" is OUT OF STOCK !!!\n";
							setcolor(240);
							goto turnOut2;
						}
						else if(jmlItm>=0&&jmlItm<=cd){
							out5+=jmlItm;
							ItmPjm[4]+=jmlItm;
							cd-=jmlItm;
							QtItm[4]-=jmlItm;
							t[4]+=jmlItm;
							tmp2+=jmlItm;
						}
						else{
							range=true;
							goto turnOut7;
						}
					}
					else{
						setcolor(252);
						cout<<"!!! CD/DVD QUOTA IS FULL !!!\n";
						setcolor(240);
						goto turnOut2;
					}
				}
//CD/DVD C
				else if(idItm=="6"||idItm==CodeItm[5]){
					if (tmp2<2){
turnOut8:
						cout<<"  Masukan Jumlah CD/DVD C";
							if(range==false){setcolor(black);}
							else{setcolor(red);	range=false;}
						cout<<"(0-" <<cd <<")\t";	setcolor(black);	cout<<": ";	cin>>jmlItm;
						if(QtItm[5]<=0){
							setcolor(252);
							cout<<"!!! "<<Nm[5]<<" is OUT OF STOCK !!!\n";
							setcolor(240);
							goto turnOut2;
						}
						else if(jmlItm>=0&&jmlItm<=cd){
							out6+=jmlItm;
							ItmPjm[5]+=jmlItm;
							cd-=jmlItm;
							QtItm[5]-=jmlItm;
							t[5]+=jmlItm;
							tmp2+=jmlItm;
						}
						else{
							range=true;
							goto turnOut8;
						}
					}
					else{
						setcolor(252);
						cout<<"!!! CD/DVD QUOTA IS FULL !!!\n";
						setcolor(240);
						goto turnOut2;
					}
				}
//E-Book A
				else if(idItm=="7"||idItm==CodeItm[6]){
					if (tmp3<2){
turnOut9:
						cout<<"  Masukan Jumlah E-Book A";
							if(range==false){setcolor(black);}
							else{setcolor(red);	range=false;}
						cout<<"(0-" <<eb <<")\t";	setcolor(black);	cout<<": ";	cin>>jmlItm;
						if(QtItm[6]<=0){
							setcolor(252);
							cout<<"!!! "<<Nm[6]<<" is OUT OF STOCK !!!\n";
							setcolor(240);
							goto turnOut2;
						}
						else if(jmlItm>=0&&jmlItm<=eb){
							out7+=jmlItm;
							ItmPjm[6]+=jmlItm;
							eb-=jmlItm;
							QtItm[6]-=jmlItm;
							t[6]+=jmlItm;
							tmp3+=jmlItm;
						}
						else{
							range=true;
							goto turnOut9;
						}
					}
					else{
						setcolor(252);
						cout<<"!!! E-BOOK QUOTA IS FULL !!!\n";
						setcolor(240);
						goto turnOut2;
					}
				}
//E-Book B
				else if(idItm=="8"||idItm==CodeItm[7]){
					if (tmp3<2){
turnOut10:
						cout<<"  Masukan Jumlah E-Book B";
							if(range==false){setcolor(black);}
							else{setcolor(red);	range=false;}
						cout<<"(0-" <<eb <<")\t";	setcolor(black);	cout<<": ";	cin>>jmlItm;
						if(QtItm[7]<=0){
							setcolor(252);
							cout<<"!!! "<<Nm[7]<<" is OUT OF STOCK !!!\n";
							setcolor(240);
							goto turnOut2;
						}
						else if(jmlItm>=0&&jmlItm<=eb){
							out8+=jmlItm;
							ItmPjm[7]+=jmlItm;
							eb-=jmlItm;
							QtItm[7]-=jmlItm;
							t[7]+=jmlItm;
							tmp3+=jmlItm;
						}
						else{
							range=true;
							goto turnOut10;
						}
					}
					else{
						setcolor(252);
						cout<<"!!! QUOTA IS FULL !!!\n";
						setcolor(240);
						goto turnOut2;
					}
				}
//E-Book C
				else if(idItm=="9"||idItm==CodeItm[8]){
					if (tmp3<2){
turnOut11:
						cout<<"  Masukan Jumlah E-Book C";
							if(range==false){setcolor(black);}
							else{setcolor(red);	range=false;}
						cout<<"(0-" <<eb <<")\t";	setcolor(black);	cout<<": ";	cin>>jmlItm;
						if(QtItm[8]<=0){
							setcolor(252);
							cout<<"!!! "<<Nm[8]<<" is OUT OF STOCK !!!\n";
							setcolor(240);
							goto turnOut2;
						}
						else if(jmlItm>=0&&jmlItm<=eb){
							out9+=jmlItm;
							ItmPjm[8]+=jmlItm;
							eb-=jmlItm;
							QtItm[8]-=jmlItm;
							t[8]+=jmlItm;
							tmp3+=jmlItm;
						}
						else{
							range=true;
							goto turnOut11;
						}
					}
					else{
						setcolor(252);
						cout<<"!!! E-BOOK QUOTA IS FULL !!!\n";
						setcolor(240);
						goto turnOut2;
					}
				}
			//}
				else{
					setcolor(252);
					cout<<"!!!! ITEM NOT FOUND !!!!\n";
					setcolor(240);
					goto turnOut2;
				};
		}
	}
	else{
		setcolor(252);
		cout<<"!!!! INPUT NOT VALID !!!!\n";
		system("pause");
		setcolor(240);
		borrow();
	};
	pushStruk();
}

int in1,in2,in3,in4,in5,in6,in7,in8,in9;
void turnIn(){ 
string idItm;
char kembali;
int jmlItm;
int hasil;
turnIn1:
/* cout<<"Masukan Jumlah ITEM Yang Akan Di Kembalikan(0-6): "; cin>>kembali;
	if(kembali>'0'&&kembali<'7'){
		in1=0,in2=0,in3=0,in4=0,in5=0,in6=0,in7=0,in8=0,in9=0; */
	//for(char x='1'; x<=pinjam; x++){
	for(char a='1'; a<=pinjam; a++){
		for(int i=0; i<9; i++){
			if(ItmPjm[i]>0){
				cout<<endl;
				cout<<"  ITEM ke-"<<a<<endl;
turnIn2:
				//if(idItm>="0" && idItm<="9"){
				if(ItmPjm[0]){
turnIn3:
					cout<<"  Masukan Jumlah Buku A(" <<ItmPjm[0] <<" pcs)\t: "; cin>>jmlItm;
					if(jmlItm==ItmPjm[0]){
						tmp+=jmlItm;		//Menghitung Jml Item Keseluruhan
						in1+=jmlItm;		//Menghitung Jml Item Buku A
						ItmPjm[0]-=jmlItm;	//Menghitung Jml Item yg diPinjam
						bo+=jmlItm;			//Menghitung Jml Item Buku Keseluruhan
						QtItm[0]+=jmlItm;	//Menghitung Jml Item Tersedia
						t[0]-=jmlItm;		//
						tmp1-=jmlItm;
					}
					else{
						setcolor(252);
						cout<<"!!! OUT OF RANGE !!!\n";
						setcolor(240);
						goto turnIn3;
					}
					break;
				}
				else if(ItmPjm[1]){
turnIn4:
					cout<<"  Masukan Jumlah Buku B(" <<ItmPjm[1] <<" pcs)\t: "; cin>>jmlItm;
					if(jmlItm==ItmPjm[1]){
						tmp+=jmlItm;
						in2+=jmlItm;
						ItmPjm[1]-=jmlItm;
						bo+=jmlItm;
						QtItm[1]+=jmlItm;
						t[1]-=jmlItm;
						tmp1-=jmlItm;
					}
					else{
						setcolor(252);
						cout<<"!!! OUT OF RANGE !!!\n";
						setcolor(240);
						goto turnIn4;
					}
					break;
				}
				else if(ItmPjm[2]){
turnIn5:
					cout<<"  Masukan Jumlah Buku C(" <<ItmPjm[2] <<" pcs)\t: "; cin>>jmlItm;
					if(jmlItm==ItmPjm[2]){
						tmp+=jmlItm;
						in3+=jmlItm;
						ItmPjm[2]-=jmlItm;
						bo+=jmlItm;
						QtItm[2]+=jmlItm;
						t[2]-=jmlItm;
						tmp1-=jmlItm;
					}
					else{
						setcolor(252);
						cout<<"!!! OUT OF RANGE !!!\n";
						setcolor(240);
						goto turnIn5;
					}
					break;
				}
				else if(ItmPjm[3]){
turnIn6:
					cout<<"  Masukan Jumlah CD/DVD A(" <<ItmPjm[3] <<" pcs): "; cin>>jmlItm;
					if(jmlItm==ItmPjm[3]){
						tmp+=jmlItm;
						in4+=jmlItm;
						ItmPjm[3]-=jmlItm;
						cd+=jmlItm;
						QtItm[3]+=jmlItm;
						t[3]-=jmlItm;
						tmp2-=jmlItm;
					}
					else{
						setcolor(252);
						cout<<"!!! OUT OF RANGE !!!\n";
						setcolor(240);
						goto turnIn6;
					}
					break;
				}
				else if(ItmPjm[4]){
turnIn7:
					cout<<"  Masukan Jumlah CD/DVD B(" <<ItmPjm[4] <<" pcs): "; cin>>jmlItm;
					if(jmlItm==ItmPjm[4]){
						tmp+=jmlItm;
						in5+=jmlItm;
						ItmPjm[4]-=jmlItm;
						cd+=jmlItm;
						QtItm[4]+=jmlItm;
						t[4]-=jmlItm;
						tmp2-=jmlItm;
					}	
					else{
						setcolor(252);
						cout<<"!!! OUT OF RANGE !!!\n";
						setcolor(240);
						goto turnIn7;
					}
					break;
				}
				else if(ItmPjm[5]){
turnIn8:
					cout<<"  Masukan Jumlah CD/DVD C(" <<ItmPjm[5] <<" pcs): "; cin>>jmlItm;
					if(jmlItm==ItmPjm[5]){
						tmp+=jmlItm;
						in6+=jmlItm;
						ItmPjm[5]-=jmlItm;
						cd+=jmlItm;
						QtItm[5]+=jmlItm;
						t[5]-=jmlItm;
						tmp2-=jmlItm;
					}
					else{
						setcolor(252);
						cout<<"!!! OUT OF RANGE !!!\n";
						setcolor(240);
						goto turnIn8;
					}
					break;
				}
				else if(ItmPjm[6]){
turnIn9:
					cout<<"  Masukan Jumlah E-Book A(" <<ItmPjm[6] <<" pcs): "; cin>>jmlItm;
					if(jmlItm==ItmPjm[6]){
						tmp+=jmlItm;
						in7+=jmlItm;
						ItmPjm[6]-=jmlItm;
						eb+=jmlItm;
						QtItm[6]+=jmlItm;
						t[6]-=jmlItm;
						tmp3-=jmlItm;
					}
					else{
						setcolor(252);
						cout<<"!!! OUT OF RANGE !!!\n";
						setcolor(240);
						goto turnIn9;
					}
					break;
				}
				else if(ItmPjm[7]){
turnIn10:
					cout<<"  Masukan Jumlah E-Book B(" <<ItmPjm[7] <<" pcs): "; cin>>jmlItm;
					if(jmlItm==ItmPjm[7]){
						tmp+=jmlItm;
						in8+=jmlItm;
						ItmPjm[7]-=jmlItm;
						eb+=jmlItm;
						QtItm[7]+=jmlItm;
						t[7]-=jmlItm;
						tmp3-=jmlItm;
					}
					else{
						setcolor(252);
						cout<<"!!! OUT OF RANGE !!!\n";
						setcolor(240);
						goto turnIn10;
					}
					break;
				}
				else if(ItmPjm[8]){
turnIn11:
					cout<<"  Masukan Jumlah E-Book C(" <<ItmPjm[8] <<" pcs): "; cin>>jmlItm;
					if(jmlItm==ItmPjm[8]){
						tmp+=jmlItm;
						in9+=jmlItm;
						ItmPjm[8]-=jmlItm;
						eb+=jmlItm;
						QtItm[8]+=jmlItm;
						t[8]-=jmlItm;
						tmp3-=jmlItm;
					}
					else{
						setcolor(252);
						cout<<"!!! OUT OF RANGE !!!\n";
						setcolor(240);
						goto turnIn11;
					}
					break;
				}
			}
			/* else if(a==pinjam&&i==9-1){
				break;
			}; */
		}
		//cout<<endl;
	}
	cout<<endl;
}