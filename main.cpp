#include<iostream>
#include<conio.h>
#include<iomanip>
#include <windows.h>
#include "inventory.h"
#include "dbLogin.h"
using namespace std;


char tmpInput1[100], tmpInput4[100];
string input1,input2,input3,input4;

borrow(){
	system("cls");
	//cout<<user[tmpI].myCode<<", ";
	cout<<"Daftar ITEM Yang Tersedia\n";
	Library();
	cout<<"Jadi Meminjam Buku?(Y/N): "; input2=inputChoose();
	if (input2=="Y"||input2=="y"){
		if(QtItm[0]==0&&QtItm[1]==0&&QtItm[2]==0&&QtItm[3]==0&&QtItm[4]==0&&QtItm[5]==0&&QtItm[6]==0&&QtItm[7]==0&&QtItm[8]==0){	//Jika Semua Stock Kosong
			setcolor(252);
			cout<<"!!!! OUT OF STOCK !!!!\n";
			system("pause");
			setcolor(240);
			userLogin();
		}
		else{
			turnOut();
			if(out1==0&&out2==0&&out3==0&&out4==0&&out5==0&&out6==0&&out7==0&&out8==0&&out9==0){	}	//Jika USER batal Meminjam
			else{
				DatePinjam();	//Input tgl pinjam
				cout<<endl;
				strukPjm();
				setcolor(252);	myPause();	setcolor(240);
			};
			userLogin();
		}
	}
	else if (input2=="N"||input2=="n"){
		userLogin();
	}
	else{
		setcolor(252);
		cout<<"!!!! INPUT NOT VALID !!!!\n";
		system("pause");
		setcolor(240);
		borrow();
	}
	return 0;
}

//Login
void tampil(){
	int time=200;
back:
	GetUser=false;
	GetAdmin=false;
	logo();
	setcolor(245);	cout<<setiosflags(ios::right)<<setw(columns-24)<<" ";	putchar(186);	putchar(0);	putchar(186);	setcolor(240);	cout<<"  Hallo Selamat Datang :) :)";	setcolor(245);	cout<<setiosflags(ios::right)<<setw(16)<<" ";	putchar(186);	putchar(0);	putchar(186);	cout<<endl;
	cout<<setiosflags(ios::right)<<setw(columns-24)<<" ";	putchar(186);	putchar(0);	putchar(186);	setcolor(240);	cout<<"  Silahkan Masukan Biodata USER";	setcolor(245);	cout<<setiosflags(ios::right)<<setw(13)<<" ";	putchar(186);	putchar(0);	putchar(186);	cout<<endl;
	cout<<setiosflags(ios::right)<<setw(columns-24)<<" ";	putchar(186);	putchar(0);	putchar(186);
	setcolor(240);
	cout<<"    - Nama : "; 
	setcolor(245);
	cout<<setiosflags(ios::right)<<setw(31)<<" ";	putchar(186);	putchar(0);	putchar(186);	cout<<endl;
	cout<<setiosflags(ios::right)<<setw(columns-24)<<" ";	putchar(186);	putchar(0);	putchar(186);
	setcolor(240);
	cout<<"    - NIM  : "; 
	setcolor(245);
	cout<<setiosflags(ios::right)<<setw(31)<<" ";	putchar(186);	putchar(0);	putchar(186);	cout<<endl;
	cout<<setiosflags(ios::right)<<setw(columns-24)<<" ";	putchar(186);	putchar(0);	putchar(200);	for(int i=0;i<44;i++){putchar(205);}	putchar(188);	putchar(0);	putchar(186);	cout<<endl;
	cout<<setiosflags(ios::right)<<setw(columns-24)<<" ";	putchar(200);	for(int i=0;i<48;i++){putchar(205);}	putchar(188);	cout<<endl;
	//input nama & id
MyUsername:
	setcolor(240);	
	setcursor((columns-8),(set_rows+24));
	cout<<"                               ";
	setcursor((columns-8),(set_rows+24));		name=getusername();
	if((name<=" ~")||(name>=""&&name<="                               ")){goto MyUsername;};
MyPassword:
	setcursor((columns-8),(set_rows+25));
	cout<<"                              ";
	setcursor((columns-8),(set_rows+25));		ID=getpassword();
	if((ID<=" ~")||(ID>=""&&ID<="                               ")){goto MyPassword;};
	//check in dataBase
	setcursor(0,(set_rows+28));		checkDB(name,ID);
	setcursor((columns-24),(set_rows+29));
	cout<<"                                  ";
	//cout<<"\t\t\t\t\t";
	setcursor((columns+13),(set_rows+28));	cout<<"Loading: ";
	int plus=1;
	for (int i=0;i<101;i++){
		//int cPercent=i;
		//if(i>20){plus++;}
		if(i%5 && time>55 && i<60){time-=5;}
		else if(i%5 && time>30 && i>=85){time-=5;};
		Sleep(time);
		setcursor((columns+22),(set_rows+28));
		cout<<i<<"%";
		//for (int j=0;j<=1e8;j++); //You can also use sleep function instead of for loop
		if(i==100){
			//i=100;
			setcursor((columns-24),(set_rows+29));
			cout<<"Loading Complete . . .";
			setcursor((columns+22),(set_rows+28));
			//cout<<i<<"%";
			Sleep(2000);
		}
	}
}
//Menampilkan User & ID
GetLoginInfo(){
	setcolor(240);	
	if(GetUser==true){
		cout<<"Nama USER: "<<name <<"  ID: " <<ID;
	}
	else if(GetAdmin==true){
		cout<<"Hello "<<name;
	}
	return 0;
}

main(){
	getSizeConsole();
backMain:
		tmp1=0, tmp2=0, tmp3=0;
		bo=2, cd=2, eb=2;
	system("color f0");
	system("cls");
//Tampilan Pertama/Login
	//GetUser=true;
	tampil();
	if(GetUser==true){
		userLogin();
	}
	else if(GetAdmin==true){
		admin();
	}
}

userLogin(){
back1:
	system("cls");	system("color f0");
	int menu_item=0, x=2,movePos=0;
	bool running = true;
	gotoXY(0,0+movePos);	GetLoginInfo();	//Menampilkan USER & ID
	while(running!=false){
	
	int countPos=0;
	for(int i=0;i<9;i++){
		if(ItmPjm[i]>0){countPos++;}
	}
	int curX=wherex(), curY=wherey();
back2:
	/* gotoXY(40,0+movePos); 	cout <<"                                    ";
	gotoXY(40,0+movePos); 	cout <<"menu_item: "<<menu_item <<", " <<"x: "<<x <<", " <<"run: "<<running <<" option: "<<option;
	gotoXY(40,1+movePos);	cout<<"                   ";
	gotoXY(40,1+movePos);	cout<<curX<<" "<<curY <<" "<<countPos; */
	
	gotoXY(0,1+movePos);	cout<<"Silahkan Pilih Menu Berikut:"<<endl; 
	gotoXY(1,x+movePos);	cout<<">";
	gotoXY(2,2+movePos);			if(menu_item==0){setcolor(0x0f);};
	cout<<"1) List Item\n";						setcolor(0xf0);
	gotoXY(2,3+movePos);			if(menu_item==1){setcolor(0x0f);};
	cout<<"2) History Pinjam New V.1.1\n";		setcolor(0xf0);
	gotoXY(2,4+movePos);			if(menu_item==2){setcolor(0x0f);};
	cout<<"3) Meminjam\n";						setcolor(0xf0);
	gotoXY(2,5+movePos);			if(menu_item==3){setcolor(0x0f);};
	cout<<"4) Mengembalikan\n";					setcolor(0xf0);
	gotoXY(2,6+movePos);			if(menu_item==4){setcolor(0x0f);};
	cout<<"5) History Pinjam\n";				setcolor(0xf0);
	if(user[tmpI].myCode!="\0"){
		gotoXY(0,7+movePos);			if(menu_item==5){setcolor(0x0f);};
		cout<<"  6) Struk\n";						setcolor(0xf0);
	};
//	cout<<"t[0]: "<<t[0]<<",t[1]: "<<t[1]<<",t[2]: "<<t[2]<<",t[3]: "<<t[3]<<",t[4]: "<<t[4]<<",t[5]: "<<t[5]<<",t[6]: "<<t[6]<<",t[7]: "<<t[7]<<",t[8]: "<<t[8]<<endl;
//	cout<<"tmp1 :"<<tmp1<<", tmp2: "<<tmp2<<", tmp3: "<<tmp3<<endl;
//	cout<<"bo :"<<bo<<", cd: "<<cd<<", eb: "<<eb<<endl;
//	cout<<"ItmPjm[0]: "<<ItmPjm[0] <<"ItmPjm[1]: "<<ItmPjm[1] <<"ItmPjm[2]: "<<ItmPjm[2] <<" | ItmPjm[3]: "<<ItmPjm[3] <<", ItmPjm[4]: "<<ItmPjm[4] <<", ItmPjm[5]: "<<ItmPjm[5] <<" | ItmPjm[6]: "<<ItmPjm[6] <<", ItmPjm[7]: "<<ItmPjm[7] <<", ItmPjm[2]: "<<ItmPjm[2]<<endl;
	gotoXY(0,8+movePos);	cout<<"Press Backspace(to LogOut/Back), Press Esc/End(to exit)";
	system("pause>nul"); // the >nul bit causes it the print no message
	
		if(GetAsyncKeyState(VK_END)&0x8000){		//exit button pressed
			system("cls");
			exit(0);
		}
		else if(GetAsyncKeyState(VK_ESCAPE)&0x8000){		//exit button pressed
			myNotif();
			system("cls");
			if(option==true){exit(0);};
			goto back1;
		}
		else if(GetAsyncKeyState('\b')&0x8000){		//exit button pressed
			myNotif();
			system("cls");
			if(option==true){
				for(int i=0;i<9;i++){
					user[tmpI].itmPjm[i]=ItmPjm[i];
					user[tmpI].T[i]=t[i];
					ItmPjm[i]=0;	t[i]=0;
				}
				user[tmpI].myCode=tmpCodeStruk;
				user[tmpI].tglPinjam=tglPjm, 		user[tmpI].blnPinjam=blnPjm, 		user[tmpI].thnPinjam=thnPjm;
				user[tmpI].TMP1=tmp1;	user[tmpI].TMP2=tmp2;	user[tmpI].TMP3=tmp3;
				//t[0]=0, t[1]=0, t[2]=0, t[3]=0, t[4]=0, t[5]=0, t[6]=0, t[7]=0, t[8]=0;
				user[tmpI].BO=bo;	user[tmpI].CD=cd;	user[tmpI].EB=eb;
				//ItmPjm[0]=0, ItmPjm[1]=0, ItmPjm[2]=0, ItmPjm[3]=0, ItmPjm[4]=0, ItmPjm[5]=0, ItmPjm[6]=0, ItmPjm[7]=0, ItmPjm[2]=0;
				main();
			}
			else{goto back1;};
		}
		else if(GetAsyncKeyState(VK_RETURN) & 0x8000){ // Enter key pressed
			if(menu_item==0){		//Menampilkan List Item
backSearch:
				system("cls");
				Library();
				cout<<"Input B(to back), Input A(to sort by Ascending), Input D(to sort by Ascending)\n";
				cout<<"Input Keyword Kode Itm/Nama Itm/Penulis/Penertbit to Search\n";
				char cari[95];
				cout<<">> ";	cin.getline(cari,95);
				string find=cari;			//Convert Char Const to String
				if(find=="B"||find=="b"){
					goto back1;
				}
				else if(find=="A"||find=="a"){
					SortAscending(0,8);
					system("pause");
				}
				else if(find=="D"||find=="d"){
					SortDescending(8,0);
					system("pause");
				}
				else if(find!=""){
					SearchEngine(find);
				};
				goto backSearch;
			}
			else if(menu_item==1){	//Menampilkan History Pinjam
				if(countPos>0){countPos--;};
				system("cls");
				historyNEW();
				movePos=7+countPos;
				goto back2;
			}
			else if(menu_item==2){	//Meminjam
				if(user[tmpI].myCode=="\0"){	//Jika USER belum meminjam item
					borrow();
					if(user[tmpI].myCode!="\0"){movePos++;};
				}
				else{	//Jika USER belum mengembalikan item
					setcolor(252);
					cout<<"!!!! ANDA SUDAH MEMINJAM !!!!\n";
					system("pause");
					setcolor(240);
					goto back1;
				}
			}
			else if(menu_item==3){	//Mengembalikan
back4:
				if(user[tmpI].myCode=="\0"){	//Jika USER belum meminjam item
					setcolor(252);
					cout<<"!!!! ANDA BELUM MEMINJAM !!!!\n";
					system("pause");
					setcolor(240);
					goto back1;
				}
				else{
					system("cls");
					cout<<"Daftar ITEM Yang Tersedia\n";
					Library();
					cout<<"Jadi Mengembalikan?(Y/N): "; cin>>input3;
					if (input3=="Y"||input3=="y"){
back5:		
						cout<<"Masukan Kode Struk      : "; input4=myInput(); //cin.getline(tmpInput4,100);
						if(input4=="0"||input4=="b"||input4=="B"||input4=="Back"||input4=="BACK"||input4=="back"){
							goto back1;
						}
						else if(input4==tmpCodeStruk){
							turnIn();
							if(in1==0&&in2==0&&in3==0&&in4==0&&in5==0&&in6==0&&in7==0&&in8==0&&in9==0){	//Jika USER batal Mengembalikan
								goto back1;
							}
							else{
								DateKembali();	//Input tgl kembali
								tenggang();		//Count masa pinjam+denda
								user[tmpI].myCode.clear();
								cout<<endl<<endl;
								movePos--;
								system("pause");
								goto back1;
							}
						}
						else if(input4=="\0"){
							setcursor(0,15);
							cout<<"                                         ";
							setcursor(0,15);
							goto back5;
						}
						else{
							setcolor(252);
							cout<<"!!!! CODE NOT VALID !!!!\n";
							system("pause");
							setcolor(240);
							setcursor(0,15);
							cout<<"                                         "<<endl;
							cout<<"                                         "<<endl;
							cout<<"                                         "<<endl;
							setcursor(0,15);
							goto back5;
							goto back5;
						}
					}
					else if (input3=="N"||input3=="n"){
						goto back1;
					}
					else{
						setcolor(252);
						cout<<"!!!! INPUT NOT VALID !!!!\n";
						system("pause");
						setcolor(240);
						goto back4;
					}
				}
			}
			else if(menu_item==4){	//Menampilkan History Pinjam
				system("cls");
				history2();
				movePos=16;
				goto back2;
			}
			else if(menu_item==5 &&user[tmpI].myCode!="\0"){	//Menampilkan Struk
				system("cls");
				strukPjm();
				movePos=13+countPos;
				goto back2;
			}
		}
		else if(GetAsyncKeyState(VK_DOWN)&0x8000){		//down button pressed
			wherex();	wherey();
			if(user[tmpI].myCode=="\0"){
				if (x != 6){
					gotoXY(1,x+movePos); cout << "  ";
					x++;
					gotoXY(1,x+movePos); cout << ">";
					menu_item++;
					continue;
				};
				if (x==6){
					gotoXY(1,x+movePos); cout << "  ";
					x=2;
					gotoXY(1,x+movePos); cout << ">";
					menu_item=0;
					continue;
				};
			}
			else{
				if (x != 7){
					gotoXY(1,x+movePos); cout << "  ";
					x++;
					gotoXY(1,x+movePos); cout << ">";
					menu_item++;
					continue;
				};
				if (x==7){
					gotoXY(1,x+movePos); cout << "  ";
					x=2;
					gotoXY(1,x+movePos); cout << ">";
					menu_item=0;
					continue;
				};
			}
		}
		else if(GetAsyncKeyState(VK_UP)&0x8000){			//up button pressed
			wherex();	wherey();
			if(user[tmpI].myCode=="\0"){
				if (x != 2){
					gotoXY(1,x+movePos); cout << "  ";
					x--;
					gotoXY(1,x+movePos); cout << ">";
					menu_item--;
					continue;
				};
				if (x==2){
					gotoXY(1,x+movePos); cout << "  ";
					x=6;
					gotoXY(1,x+movePos); cout << ">";
					menu_item=4;
					continue;
				};
			}
			else{
				if (x != 2){
					gotoXY(1,x+movePos); cout << "  ";
					x--;
					gotoXY(1,x+movePos); cout << ">";
					menu_item--;
					continue;
				};
				if (x==2){
					gotoXY(1,x+movePos); cout << "  ";
					x=7;
					gotoXY(1,x+movePos); cout << ">";
					menu_item=5;
					continue;
				};
			}
		};
		
	/* if(input1==""||input1==" "){
		goto back1;
	}
	else if(input1=="1"){		//Menampilkan List Item
backSearch:
		system("cls");
		Library();
		cout<<"Input B(to back), Input A(to sort by Ascending), Input D(to sort by Ascending)\n";
		cout<<"Input Keyword Kode Itm/Nama Itm/Penulis/Penertbit to Search\n";
		char cari[95];
		cout<<">> ";	cin.getline(cari,95);
		string find=cari;			//Convert Char Const to String
		if(find=="B"||find=="b"){
			goto back1;
		}
		else if(find=="A"||find=="a"){
			SortAscending(0,8);
			system("pause");
		}
		else if(find=="D"||find=="d"){
			SortDescending(8,0);
			system("pause");
		}
		else if(find!=""){
			SearchEngine(find);
		};
		goto backSearch;
	}
	else if(input1=="2"){	//Menampilkan History Pinjam
		system("cls");
		historyNEW();
		goto back2;
	}
	else if(input1=="3"){	//Meminjam
		if(user[tmpI].myCode=="\0"){	//Jika USER belum meminjam item
			borrow();
		}
		else{	//Jika USER belum mengembalikan item
			setcolor(252);
			cout<<"!!!! ANDA SUDAH MEMINJAM !!!!\n";
			system("pause");
			setcolor(240);
			goto back1;
		}
	}
	else if(input1=="4"){	//Mengembalikan
back4:
		if(user[tmpI].myCode=="\0"){	//Jika USER belum meminjam item
			setcolor(252);
			cout<<"!!!! ANDA BELUM MEMINJAM !!!!\n";
			system("pause");
			setcolor(240);
			goto back1;
		}
		else{
			system("cls");
			cout<<"Daftar ITEM Yang Tersedia\n";
			Library();
			cout<<"Jadi Mengembalikan?(Y/N): "; cin>>input3;
			if (input3=="Y"||input3=="y"){
back5:
				cout<<"Masukan Kode Struk      : "; input4=myInput(); //cin.getline(tmpInput4,100);
				if(input4=="0"||input4=="b"||input4=="B"||input4=="Back"||input4=="BACK"||input4=="back"){
					goto back1;
				}
				else if(input4==tmpCodeStruk){
					turnIn();
					if(in1==0&&in2==0&&in3==0&&in4==0&&in5==0&&in6==0&&in7==0&&in8==0&&in9==0){	//Jika USER batal Mengembalikan
						goto back1;
					}
					else{
						DateKembali();	//Input tgl kembali
						tenggang();		//Count masa pinjam+denda
						user[tmpI].myCode.clear();
						cout<<endl<<endl;
						system("pause");
						goto back1;
					}
				}
				else if(input4=="\0"){
					setcursor(0,15);
					cout<<"                                         ";
					setcursor(0,15);
					goto back5;
				}
				else{
					setcolor(252);
					cout<<"!!!! CODE NOT VALID !!!!\n";
					system("pause");
					setcolor(240);
					setcursor(0,15);
					cout<<"                                         "<<endl;
					cout<<"                                         "<<endl;
					cout<<"                                         "<<endl;
					setcursor(0,15);
					goto back5;
					goto back5;
				}
			}
			else if (input3=="N"||input3=="n"){
				goto back1;
			}
			else{
				setcolor(252);
				cout<<"!!!! INPUT NOT VALID !!!!\n";
				system("pause");
				setcolor(240);
				goto back4;
			}
		}
	}
	else if(input1=="5"){	//Menampilkan History Pinjam
		system("cls");
		history2();
		goto back2;
	}
	else if(input1=="6"&&user[tmpI].myCode!="\0"){	//Menampilkan History Pinjam
		system("cls");
		strukPjm();
		goto back2;
	}
	else if(input1=="EXIT"||input1=="Exit"||input1=="exit"||input1=="E"||input1=="e"){	//Keluar
		system("cls");
		exit(0);
	}
	else if(input1=="LOGOUT"||input1=="Logout"||input1=="LogOut"||input1=="logout"||input1=="L"||input1=="l"){	//Logout
		for(int i=0;i<9;i++){
			user[tmpI].itmPjm[i]=ItmPjm[i];
			user[tmpI].T[i]=t[i];
			ItmPjm[i]=0;	t[i]=0;
		}
		user[tmpI].myCode=tmpCodeStruk;
		user[tmpI].tglPinjam=tglPjm, 		user[tmpI].blnPinjam=blnPjm, 		user[tmpI].thnPinjam=thnPjm;
		user[tmpI].TMP1=tmp1;	user[tmpI].TMP2=tmp2;	user[tmpI].TMP3=tmp3;
		//t[0]=0, t[1]=0, t[2]=0, t[3]=0, t[4]=0, t[5]=0, t[6]=0, t[7]=0, t[8]=0;
		user[tmpI].BO=bo;	user[tmpI].CD=cd;	user[tmpI].EB=eb;
		//ItmPjm[0]=0, ItmPjm[1]=0, ItmPjm[2]=0, ItmPjm[3]=0, ItmPjm[4]=0, ItmPjm[5]=0, ItmPjm[6]=0, ItmPjm[7]=0, ItmPjm[2]=0;
		main();
	}
	else{
		setcolor(252);
		cout<<"!!!! INPUT NOT VALID !!!!\n";
		system("pause");
		setcolor(240);
		system("cls");
		goto back1;
	} */	
	}
return 0;
}