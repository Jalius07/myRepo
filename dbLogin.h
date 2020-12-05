#include <iostream>
#include <windows.h>
#include <iomanip>
#define def_length 3
#define db_length 100
using namespace std;
string name,ID;
bool GetUser,GetAdmin;
int path=0;

int userLogin();
int GetLoginInfo();
int main();

string getpassword( const string& prompt = "" ){
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

	// Get the password string
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
		else if(c=='.' || c!='\t' && !(c>='!' && c<='/') && !(c>='[' && c<='`') && !(c>='{' && c<='~') && !(c>=':' && c<='@') && result.length()<25){
			WriteConsoleA( oh, "*", 1, &count, NULL );
			result.push_back( c );
		}
	}

	// Restore the console mode
	SetConsoleMode( ih, mode );
	return result;
}

string getusername( const string& prompt = "" ){
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

	// Get the password string
	WriteConsoleA( oh, prompt.c_str(), prompt.length(), &count, NULL );
	char d;
	bool minInput=false;
	while (ReadConsoleA( ih, &d, 1, &count, NULL) && (d != '\r') && (d != '\n')){
		if (d == '\b'){
			if (result.length()){
				WriteConsoleA( oh, "\b \b", 3, &count, NULL );
				result.erase( result.end() -1 );
			}
		}
		else if(result.length()==0 && d==' '){
			WriteConsoleA( oh, "", 0, &count, NULL );
		}
		else if(d=='.' || d!='\t' && !(d>='!' && d<='/') && !(d>='[' && d<='`') && !(d>='{' && d<='~') && !(d>=':' && d<='@') && result.length()<25){
			WriteConsoleA( oh, &d, 1, &count, NULL );
			result.push_back( d );
		}
	}

	// Restore the console mode
	SetConsoleMode( ih, mode );
	return result;
}

struct pjm{
	int itmPjm[9];
	int T[9];
	int TMP1,TMP2,TMP3;
	int BO,CD,EB;
	int tglPinjam, blnPinjam, thnPinjam;
	string myCode;
}user[db_length];
struct dbLogin{
	string db_name;
	string db_id;
	//int length_db_name;
	//int length_db_id;
}dataUser[db_length]={"Jalius","18.11.2068",	"Mr.J","j",		"aaa","1"},dataAdmin[db_length]={"admin","admin",	"a","a"};

void writeDB(string in_name,string in_ID){
	for(int i=def_length+path;i<def_length+1+path;i++){
		dataUser[i].db_name=in_name;
		dataUser[i].db_id=in_ID;
	}path++;
}

///////////////////////// Stack Code ////////////////////////////////
int countPush;
struct TNode{
	string change;
	int each;
	TNode *next;
};

TNode*head;

void init(){
	head = NULL;
}

int isEmpty(){
	if(head == NULL)
	return 1;
	else
	return 0;
}

void push(string input1,int input2){
	TNode *baru;
	baru = new TNode;
	baru->change = input1;
	baru->each = input2;
	baru->next = head;
	head = baru;
}

void whatsID(string thisID){
	for(int i=0;i<9;i++){
		if(CodeItm[i]==thisID){
			cout<<Nm[i];
			break;
		}
		else if(NumItm[i]==thisID){
			cout<<Nm[i];
			break;
		};
	}
}

void pop(bool acc){
	TNode *bantu;
	string change;
	int each;
	if(acc==true){
		if (isEmpty()==0){
			bantu = head;
			change = bantu -> change;
			each = bantu -> each;
			for(int i=0;i<9;i++){
				if(CodeItm[i]==change){
					//int tmp_each=each;
					QtItm[i]+=each;
					break;
				}
				else if(NumItm[i]==change){
					//int tmp_each=each;
					QtItm[i]+=each;
					break;
				}
				else if(i==9-1){
					cout<<"!!! Not Found !!!\n";
				}
			}
			head = head -> next;
			delete bantu;
		}
		else{
			setcolor(252);	
			cout<<"!!!! Stack Empty !!!!\n";
			system("pause");	setcolor(240);
		};
	}
	else if(acc==false){
		if (isEmpty()==0){
			bantu = head;
			change = bantu -> change;
			each = bantu -> each;
			head = head -> next;
			delete bantu;
		}
		else{
			setcolor(252);	
			cout<<"!!!! Stack Empty !!!!\n";
			system("pause");	setcolor(240);
		};
	};
}

void printstack(){
	TNode *bantu;
	bantu = head;
	int i=countPush+1;
	if (isEmpty()==0){
		while (bantu != NULL){
			i--;
			cout<<"=========== ";
			if(i==countPush){setcolor(252);};	cout<<"Stack ke-"<<i;	setcolor(240);
			cout<<" ===========\n";
			if(i==countPush){setcolor(252);};	cout<<"No.ID  : "<<bantu->change;
			cout<<"\nJumlah : "<<bantu->each;
			cout<<endl;	setcolor(240);
			bantu = bantu->next;
		}
		cout<<"==================================\n";
	}
	else{
		setcolor(252);	
		cout<<"\n!!!! Stack Empty !!!!\n";
		setcolor(240);
	}
}

void clear(){
	TNode *bantu,*hapus;
	bantu = head;
	if (isEmpty()==0){
		while(bantu!=NULL){
			hapus = bantu;
			bantu = bantu->next;
			delete hapus;
		}
		head = NULL;
		setcolor(242);	
		cout<<"Successfully Clear Stack...\n";
		system("pause");	setcolor(240);
	}
	else{
		setcolor(252);	
		cout<<"!!!! Stack Empty !!!!\n";
		system("pause");	setcolor(240);
	}
}

void mainstack(){
	TNode *bantu;
	string change;
	int each;
	
	string input1,acc,menu;
	int input2;
	char tmpMenu[100],tmpInput1[100];
	do{
backMainStack:
		system("cls");
backStack:
		cout<<"Silahkan Pilih Menu Berikut\n";
		cout<<" 1. Push\n";
		cout<<" 2. Pop ";	if(countPush!=0){setcolor(252);		cout<<"["<<countPush<<" Stack]";		setcolor(240);};	cout<<endl;
		cout<<" 3. Clear Stack\n";
		cout<<" 4. Print Stack\n";
		cout<<" 5. View Item\n";
		cout<<"Press L(to LogOut), Press E(to exit), Press B(to back)\n";
		cout<<">> ";		 cin.getline(tmpMenu,100);		menu=tmpMenu;
		if(menu==" "||menu==""){goto backMainStack;}
		else if(menu=="E"||menu=="e"){	system("cls");		exit(0);}
		else if(menu=="L"||menu=="l"){	main();}
		else if(menu=="B"||menu=="b"){	break;}
		else if (menu<"1"||menu>"5"){
			setcolor(252);
			cout<<"\n!!!! INPUT NOT VALID !!!!\n";
			system("pause");
			setcolor(240);
		}
		else{
			if(menu=="1"){
mainPush:
				system("cls");
				Library();
				cout<<"Input B or BACK(to back), Input Code Item(to Input Stack)\n";
				cout<<"Use minus(-), or Use plus(+)\n\n";
backPush:
				setcursor(0,16);						cout<<"                                                  ";
				setcursor(0,16);
				cout<<"Input Kode          \t: ";		cin.getline(tmpInput1,100);		input1=tmpInput1;
					if(input1==" "||input1==""){goto backPush;}
					else if(input1=="back"||input1=="Back"||input1=="BACK"||input1=="b"||input1=="B"){goto backMainStack;};
					for(int i=0;i<9;i++){
						if((CodeItm[i]==input1||NumItm[i]==input1)&&countPush<=4){
							countPush++;
							//cout<<"\nChange"<<i<<endl;
backCinJml:
							setcursor(0,17);			cout<<"                                                  ";
							setcursor(0,17);
							cout<<"Jml."<<NmItm[i] <<" ["<<QtItm[i] <<" pcs]"<<"\t: ";		cin>>input2;
							int tmpQt=QtItm[i];	tmpQt+=input2;
							if(input2==0){
								countPush--;
								goto mainPush;
							}
							else if(tmpQt<0){
								setcolor(252);
								cout<<"\n!!!! Minus QtItm Detected !!!!\n";
								system("pause");
								setcursor(0,19);		cout<<"                                                  ";
								setcursor(0,20);		cout<<"                                                  ";
								setcolor(240);
								goto backCinJml;
							}
							break;
						}
						else if(i==9-1){
							setcolor(252);
							cout<<"\n!!!! Item Not Found !!!!\n";
							system("pause");
							setcursor(0,18);		cout<<"                                                  ";
							setcursor(0,19);		cout<<"                                                  ";
							setcolor(240);
							goto backPush;
						}
						else if (countPush>=5){
							setcolor(252);
							cout<<"\n!!!! Stack is Full !!!!\n";
							system("pause");
							setcursor(0,18);		cout<<"                                                  ";
							setcursor(0,19);		cout<<"                                                  ";
							setcolor(240);
							goto backPush;
						}
					}
				push(input1,input2);
				setcolor(242);	
				cout<<"\nSuccessfully Push in Stack...\n";
				system("pause");	setcolor(240);
				setcursor(0,18);		cout<<"                                                  ";
				setcursor(0,19);		cout<<"                                                  ";
				setcursor(0,20);		cout<<"                                                  ";
				goto mainPush;
			}
			else if(menu=="2"){
backMainPop:
				if (isEmpty()==1){
					setcolor(252);	
					cout<<"\n!!!! Stack Empty !!!!\n";
					system("pause");	setcolor(240);
					goto backMainStack;
				}
				else{
backPop:
					char tmpAcc[100];
					system("cls");
					printstack();
					for(int i=countPush; i>0; i--){
						bantu = head;
						change = bantu -> change;
						each = bantu -> each;
						cout<<"\n\nTambahkan ";	whatsID(change);	cout<<" ["<<each<<" pcs] " <<" (Y/N): ";		cin.getline(tmpAcc,100);	acc=tmpAcc;
						if(acc=="Y"||acc=="y"){
							pop(true);
							setcolor(242);	
							cout<<"\nSuccessfully Replace QtItm...\n";
							system("pause");	setcolor(240);
							countPush--;		system("cls");
							goto backPop;
						}
						else if(acc=="N"||acc=="n"){
							pop(false);
							setcolor(252);	
							cout<<"\nCencel Replace QtItm...\n";
							system("pause");	setcolor(240);
							countPush--;		system("cls");
							goto backPop;
						}
						else if(acc=="B"||acc=="b"||acc=="BACK"||acc=="back"||acc=="Back"){
							goto backMainStack;
						}
						else{
							setcolor(252);
							cout<<"\n!!! Input Not Valid !!!\n";
							system("pause");
							setcolor(240);
							goto backPop;
						}
					}
				}
			}
			else if(menu=="3"){
					cout<<endl;
					clear();
					countPush=0;
			}
			else if(menu=="4"){
					printstack();
					setcolor(252);	
					system("pause");	setcolor(240);
					cout<<endl;
			}
			else if(menu=="5"){
					system("cls");
					Library();
					goto backStack;
					cout<<endl;
			};
		}
	}while(menu!="b"||menu!="B");
	//if(countPush!=0){clear();};
}
///////////////////////// End of Stack Code ////////////////////////////////

void admin(){
	string IN_ID,	IN_name,	in;
	char tmpIN[100];
	setcolor(240);
	system("cls");
mainAdmin:
	GetLoginInfo();
	cout<<", You get permission as Administrator";
	cout<<" \nSilahkan Pilih Menu Berikut: \n"; 
		cout<<" 1. ADD User\n 2. Monitoring User\n 3. Edit QtItm with LinkedList Stack\n";
		cout<<"Press L(to LogOut), Press E(to exit)\n>> ";	cin.getline(tmpIN,100);
		in=tmpIN;
		if(in==""||in==" "){
			admin();
		}
		else if(in=="1"){
createUser:
			system("cls");
			cout<<"Input B or BACK (to Back)"<<endl;
			cout<<"To Create User Please Input 5 s/d 24 Character"<<endl;
				cout<<"\nNama : ";
				cout<<"\nID   : ";	
nameNull:
				setcursor(7,3);		cout<<"                              ";
				setcursor(7,3);		IN_name=getusername();
				if((IN_name<=" ~")||(IN_name>=""&&IN_name<="                               ")){goto nameNull;}
				else if(IN_name=="B"||IN_name=="b"||IN_name=="BACK"||IN_name=="back"||IN_name=="Back"){admin();}
				else if(IN_name.length()<5){goto nameNull;};
idNull:	
				setcursor(7,4);		cout<<"                              ";
				setcursor(7,4);		IN_ID=getusername();
				if((IN_ID<=" ~")||(IN_ID>=""&&IN_ID<="                               ")){goto idNull;}
				else if(IN_ID=="B"||IN_ID=="b"||IN_ID=="BACK"||IN_ID=="back"||IN_name=="Back"){admin();}
				else if(IN_ID.length()<5){goto idNull;};
//Checking Duplicate Data
				bool duplicateName=false, duplicateID=false;
				for(int i=0;i<db_length;i++){
					if(IN_name==dataUser[i].db_name){
						duplicateName=true;
					}
					else if(IN_ID==dataUser[i].db_id){
						duplicateID=true;
					};
				}
//Checking NULL insert				
				if(duplicateName!=true && duplicateID!=true &&(IN_name!=""||IN_name!=" ")&&(IN_ID!=""||IN_ID!=" ")){
					cout<<"\n";
					writeDB(IN_name,IN_ID);	setcolor(252);
					cout<<endl<<IN_name<<" "<<IN_ID<<" successfully saved in the DataBase\n";
					system("pause");
				}
				else if(duplicateName==true&&duplicateID==true){
					setcolor(252);	cout<<"\n\n!!! Found Duplicate Data in the DataBase !!!\n";
					system("pause");	setcolor(240);
				}
				else if(duplicateName==true){
					setcolor(252);	cout<<"\n\n!!! Found Duplicate Name in the DataBase !!!\n";
					system("pause");	setcolor(240);
				}
				else if(duplicateID==true){
					setcolor(252);	cout<<"\n\n!!! Found Duplicate ID in the DataBase !!!\n";
					system("pause");	setcolor(240);
				};	setcolor(240);
				goto createUser;
		}
		else if(in=="2"){
			system("cls");
			setcolor(31);
			putchar(201);	for(int i=0;i<80;i++){if(i==27||i==55){putchar(203);}	else{putchar(205);}}	putchar(187);	cout<<endl;
			putchar(186);	cout<<setw(9)<<""<<"Nama User"<<setw(9)<<" ";putchar(186);cout<<setw(9)<<""<<"Password"<<setw(10)<<" ";putchar(186);cout<<setw(5)<<""<<"Pinjaman aktif"<<setw(5)<<" ";putchar(186);cout<<endl;
			putchar(200);	for(int i=0;i<80;i++){if(i==27||i==55){putchar(202);}	else{putchar(205);}}	putchar(188);	cout<<endl;		setcolor(240);
			//putchar(218);	for(int i=0;i<80;i++){if(i==27||i==55){putchar(194);}	else{putchar(196);}}	putchar(191);	cout<<endl;
			for(int i=0;i<def_length+path;i++){
				int l=0;
				cout<<"| ";
				cout<<dataUser[i].db_name<<setw(26-dataUser[i].db_name.length())<<""<<"| ";	//print "|	Name User	|"
				cout<<dataUser[i].db_id<<setw(26-dataUser[i].db_id.length())<<""<<"| ";		//print	"	ID User		|"
				for(int j=0;j<9;j++){
					if(user[i].itmPjm[j]>0){
						l++;
						if(l>=2){
							cout<<"|"<<setw(28)<<"|"<<setw(29)<<"| ";
						};
						cout<<l<<". "<<NmItm[j]<<" ["<<user[i].itmPjm[j]<<" pcs]"<<setw(6)<<"|\n";
					}
					else if(user[i].itmPjm[0]==0&&user[i].itmPjm[1]==0&&user[i].itmPjm[2]==0&&user[i].itmPjm[3]==0&&user[i].itmPjm[4]==0
					&&user[i].itmPjm[5]==0&&user[i].itmPjm[6]==0&&user[i].itmPjm[7]==0&&user[i].itmPjm[8]==0){
						cout<<"NULL"<<setw(18)<<""<<" |\n";		break;
					};
				}
				if(i!=def_length+(path-1)){putchar(195);	for(int i=0;i<80;i++){if(i==27||i==55){putchar(197);}	else{putchar(196);}}	putchar(180);	cout<<endl;}
			}putchar(192);	for(int i=0;i<80;i++){if(i==27||i==55){putchar(193);}	else{putchar(196);}}	putchar(217);	cout<<endl;
			goto mainAdmin;
		}
		else if(in=="3"){mainstack();	admin();}
		else if(in=="LOGOUT"||in=="Logout"||in=="LogOut"||in=="logout"||in=="L"||in=="l"){main();}	//LogOut
		else if(in=="EXIT"||in=="Exit"||in=="exit"||in=="E"||in=="e"){system("cls");	exit(0);}	//Keluar
		else{
			setcolor(252);
			cout<<"!!!! INPUT NOT VALID !!!!\n";
			system("pause");
			setcolor(240);
			admin();
		};
}
int tmpI,tmpJ;
void checkDB(string check_name="",string check_ID=""){
	GetUser=false;
	GetAdmin=false;
	//cout<<"hallo"<<check_name;
	for(int i=0;i<db_length;i++){
		//cout<<" angka-"<<i<<dataAdmin[i].db_name<<dataUser[i].db_name;
//Login admin, checking db_Login.dataAdmin
		if(check_name==dataAdmin[i].db_name&&check_ID==dataAdmin[i].db_id){
			setcolor(242);	cout<<setw(columns-24)<<" "<<"~ Login as Admin . . .\n";	cout<<setw(columns-24)<<" ";		myPause();
			//admin();
			GetAdmin=true;
			break;
		}
//Login user, checking db_Login.dataUser
		else if(check_name==dataUser[i].db_name&&check_ID==dataUser[i].db_id){
			setcolor(242);	cout<<setw(columns-24)<<" "<<"~ Login as User . . .\n";	cout<<setw(columns-24)<<" ";		myPause();
			for(int j=0;j<9;j++){
				ItmPjm[j]=user[i].itmPjm[j];
				t[j]=user[i].T[j];
				tmpI=i;
			}
			tmpCodeStruk=user[tmpI].myCode;
			tglPjm=user[i].tglPinjam, blnPjm=user[i].blnPinjam, thnPjm=user[i].thnPinjam;
			bo=2-user[i].BO;	cd=2-user[i].CD;	eb=2-user[i].EB;
			tmp1=user[i].TMP1;	tmp2=user[i].TMP2;	tmp3=user[i].TMP3;
			GetUser=true;
			break;
		}
//Login Failed
		else{
			if(i==(db_length-1)){
				//cout<<"hallo4";
				//system("cls");		LoginGranted();
				setcolor(252);	cout<<setw(columns-24)<<" "<<"~ Login Failed . . .\n";	cout<<setw(columns-24)<<" ";		myPause();
				main();	
				break;
			};
		};
	}
}

int cpRibuan,cpRatusan,cpPuluhan,cpSatuan;
string MyCode;
generateStruk(){
	char no[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	string it="IT-";
	for (int ribuan=cpRibuan; ribuan<16; ribuan++){
		for (int ratusan=cpRatusan; ratusan<16; ratusan++){
			for (int puluhan=cpPuluhan; puluhan<16; puluhan++){
				for (int satuan=cpSatuan; satuan<16; satuan++){
					if(puluhan==0&&ratusan==0&&ribuan==0&&satuan==0){cpSatuan=1;	satuan=1;}
					MyCode=it+no[ribuan]+no[ratusan]+no[puluhan]+no[satuan];
					cout<<"Kode Struk: "<<MyCode<<endl;
					cpSatuan++;
					break;
				}	if(cpSatuan>=16){cpPuluhan++;	cpSatuan=0;}		break;
			}	if(cpPuluhan>=16){cpRatusan++;	cpPuluhan=0;}	break;
		}	if(cpRatusan>=16){cpRibuan++;	cpRatusan=0;}	break;
	}	if(cpRibuan>=16){cpSatuan=0,cpPuluhan=0,cpRatusan=0,cpRibuan=0;};
	return 0;
}

pushStruk(){
	if(ItmPjm[0]==0&&ItmPjm[1]==0&&ItmPjm[2]==0&&ItmPjm[3]==0&&ItmPjm[4]==0&&ItmPjm[5]==0&&ItmPjm[6]==0&&ItmPjm[7]==0&&ItmPjm[8]==0);	//Jika USER belum meminjam item
	else{user[tmpI].myCode=MyCode;};
	tmpCodeStruk=user[tmpI].myCode;
	//cout<<user[tmpI].myCode<<", ";
	return 0;
}