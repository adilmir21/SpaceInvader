#include<iostream>
#include"mygraphics.h"
#include<Windows.h>
#include<time.h>
#include<cstring>
#include<string>
#include<fstream>
using namespace std;
bool endgame = false, endgame2 = false, endgame3 = false;
char gender, genders[1000], name[100], names[100];
string password, passwords[1000], g;
long int id, ids[1000];
int choice, count_m = 0, count_f = 0, q = 0, e = 0, vm = 0, fv = 0, easy_count = 0, normal_count = 0, choice2, age, male, female;  // fv is a ramdom variable
int gamec, score3, e1, n1;    // type of game eg easy, hard , normal
int menu(int choice);

void newaccount(char name[], long int& id, char& gender, string& password, int age);
void login(char name[], string password);
void  gamemode(int gamec);
int easymode();
int normalmode();
int hardmode();

int menu(int choice)
{
	int option;
	cout << "---------------------------" << endl;
	cout << "         M E N U  " << endl;
	cout << "---------------------------" << endl;
	cout << endl;
	cout << " 1 FOR SIGN UP \n" << endl;
	cout << " 2 FOR LOGIN \n" << endl;
	cout << " 3 FOR QUITING \n" << endl;
	cout << " YOUR CHOICE IS : ";
	cin >> choice;
	while (choice < 1 || choice > 3)
	{
		if (choice < 1 || choice > 3)
		{
			cout << "wrong entry enter again " << endl;
		}
		cin >> choice;
		if (choice == 1)
		{
			newaccount(name, id, gender, password, age);
		}
		else if (choice == 2)
		{
			login(name, password);
		}
		else if (choice == 3)
		{
			cout << " Are You Sure ? " << endl;
			cout << " 1 = YES / 2 = NO ";
			cout << " Your Choice : ";
			cin >> option;
			while (option < 1 || option>2)
			{
				cout << " Wrong option ! Enter again :";
				cin >> option;
			}
				if (option == 1)
			{
				return 0;
			}
			else if (option == 2)
			{
				menu(choice);
			}
			if (option == 1)
			{
				return 0;
			}
			else if (option == 2)
			{
				menu(choice);
			}

			
		}
		
	}
	if (choice == 1)
	{
		newaccount(name, id, gender, password, age);
	}
	else if (choice == 2)
	{
		login(name, password);
	}
	else if (choice == 3)
	{
		return 0;
	}


}

void newaccount(char name[], long int& id, char& gender, string& password, int age)
{
	ofstream file, file1, file2, file3, file4;
	file1.open("name.txt",ios::app);
	file2.open("password.txt",ios::app);
	file3.open("g.txt", ios::app);
	ifstream file_3;
	file_3.open("male.txt");
	cout << "--------------------------------" << endl;
	cout << "        S I G N U P " << endl;
	cout << "--------------------------------" << endl;
	cin.ignore();
	cout << " Enter your name : ";
	cin.getline(name, 100);
	int len = strlen(name);
	file1 << name;
	file1 << "\n";
	file1.close();
	
	cout << " Enter password : ";

	cin >> password;
	file2 << password << endl;
	passwords[q] = password;
	q++;
	cout << " Enter your age : ";
	cin >> age;
	cout << " Enter your id number : ";
	cin >> id;
	ids[fv] = id;
	fv++;


	cout << " Are you male or female?  m for male f for female : ";
	cin >> gender;
	while (gender != 'm' && gender != 'f')
	{
		cout << " Wrong entery. Enter again : ";
		cin >> gender;
	}
	file3 << gender << endl;
	cout << " Sign up successful " << endl;
	genders[e] = gender;
	e++;


	if (gender == 'm')
	{
		g = "male";
	}
	else if (gender == 'f')
	{
		g = "female";
	}

	file.open("data.txt",ios::app);
	file << "ID     NAME    PASSWORD    AGE    GENDER    " << endl;
	file << id << "     ";
	for (int z = 0; z <= len; z++)
	{
		file << name[z];
	}
	file << "     " << password << "          " << age << "     ";
	file << g << endl;
	file.close();
	file2.close();
	file3.close();
	file4.close();
	file_3.close();
	login(name, password);
}
void login(char name[], string password)
{
	
	cout << "--------------------------------" << endl;
	cout << "         L O G I N   " << endl;
	cout << "--------------------------------" << endl;
	ifstream read;
	ifstream read1;
	string p[100];
	read.open("name.txt");
	read1.open("password.txt");
	if (!read.is_open())
	{
		cout << " There is nothing in file Please Sign up" << endl;
		menu(choice);
	}
	string name2;
	string pass2, n[100];
	cin.ignore();
	cout << " Enter your name : ";
	getline(cin,name2);
	cout << " Enter password : ";
	cin >> pass2;
	int ad = 0;
	while (!read.eof())
	{
		getline(read,n[ad]);
		ad++;
	}

	ad = 0;
	while (!read1.eof())
	{
		read1 >> p[ad];
		ad++;
	}
	
	int check = 0;//to check if names are equal
	ad = 0;
	int index,index1,com=0;
	bool  name_check = false,pass_check = true;
	while ( pass_check==true && name_check == false)
	{
		if (name2.compare(n[ad]) == 0 )
		{
			check = 1;
			index = ad;
			name_check = true;
		}
		if (pass2.compare(p[ad])==0)
		{
			com = 1;
			index1 = ad;
			pass_check = false;
		}
		ad++;
	}
	if (check == 1 && com == 1 && (index == index1))
	{
		
		cout << " LOGIN SUCCESSFUL " << endl;
		gamemode(gamec);
	}
		else
		{
		cout << " LOGIN NOT SUCCESSFULL " << endl;
		login(name, password);
		}
	read.close();
	read1.close();
		
}
void gamemode(int gamec)
{
	ifstream game_1, game_2;
	game_1.open("gamecount.txt");

	game_1 >> e1;
	game_2.open("gamecount1.txt");
	game_2 >> n1;
	cout << " Which game mode do you want to play? " << endl;
	cout << " Easy mode is mandatory " << endl;
	cout << " 1 for Easy " << endl;
	cout << " 2 for Normal " << endl;
	cout << " 3 for Hard " << endl;
	cout << " Your Choice is : ";
	cin >> gamec;
	if (gamec == 1)
	{

		easymode();

	}
	else if (gamec == 2)
	{
		if (e1 >= 1)
		{

			normalmode();

		}
		else
		{
			cout << " You have to play easy mode first ! \n" << endl;
			cout << " Choose again \n " << endl;
			gamemode(gamec);
		}
	}
	else if (gamec == 3)
	{
		if (e1 >= 1 && n1 >= 1)
		{
			hardmode();

		}
		else
		{
			cout << " you have to play easy and normal  mode first ! \n" << endl;
			cout << " choose again \n " << endl;
			gamemode(gamec);
		}
	}
	else
	{
		cout << " wrong entry " << endl;
		cout << " you are playing easy mode " << endl;
		easymode();
	}
	game_1.close();
	game_2.close();
}
int easymode()
{
	endgame = false;
	int i = 0, j = 0, k = 0, a = 0, b = 400, d = 400;// coordinates for space ship and aliens
	int x = 0, y = 0, z = 0;// coordinates for alien bullets
	int l = 255, l2 = 255, l3 = 255, m = 255, n = 255, o = 255, p = 255, fh = 24, qw = 100, zx = 98;//colors of the alliens
	int w = 255, w1 = 255, w2 = 255, black = 0, black1 = 0, black2 = 0, pur = 178, pur2 = 178, pink = 106, pink2 = 106, blue2 = 19, blue = 19, blu = 127, blu2 = 127, yel = 216, yel2 = 216, green = 33, ora = 252, gro = 102;
	int damage = 0;// damage to the space ship
	int h1 = 1, h2 = 1, h3 = 1, h4 = 1, h5 = 1, h6 = 1;//healths of aliens
	int score = 0;// initial score
	int H1 = 0;// x coordinates for rectangles of lives 
	int h = 255, t = 255, t1 = 255;// colors of ellipses for lives
	int easy_count = 0, choice2, gamec = 0, age, count_m = 0, count_f = 0;
	int  e1;
	char genders[100];
	string name1[10];
	ofstream game;
	game.open("gamecount.txt",ios::trunc); // trunc is to remove already present data in file.
	easy_count++;
	ifstream game_1, file_3;
	game_1.open("gamecount.txt");
	game << easy_count << endl;
	game_1 >> e1;
	system("CLS");
	int s = 0;




	while (endgame == false) {


		// symbols for healths

		drawEllipse(180 + H1, 20, 200 + H1, 40, w, pur, blu, w, pur, blu);
		drawEllipse(220 + H1, 20, 240 + H1, 40, w, yel, black, w, yel, black);
		drawEllipse(260 + H1, 20, 280 + H1, 40, w, black, black, w, black, black);


		drawRectangle(110 + i, 80 + j, 150 + i, 120 + j, fh, qw, zx, fh, qw, zx);//aliens



		drawRectangle(120 + x, 80 + y, 130 + x, 100 + y, fh, qw, zx, fh, qw, zx);//alien bullet

		drawEllipse(160 + i, 80 + j, 200 + i, 120 + j, pur, black, l, pur, black, l);//alien



		drawEllipse(170 + x, 80 + y, 180 + x, 100 + y, pur, black, l, pur, black, l);//alien bullet

		drawRectangle(210 + i, 80 + j, 250 + i, 120 + j, l2, pink, w, l2, pink, n);//alien


		drawEllipse(220 + x, 80 + y, 230 + x, 100 + y, l2, pink, w, l2, pink, n);//alien bullet

		drawEllipse(260 + i, 80 + j, 300 + i, 120 + j, w1, blue, blu, w1, blue, blu);//allien


		drawEllipse(270 + x, 80 + y, 280 + x, 100 + y, w1, blue, blu, w1, blue, blu);// alien bullet

		drawRectangle(310 + i, 80 + j, 350 + i, 120 + j, l3, yel, w2, l3, yel, w2);//alien



		drawEllipse(320 + x, 80 + y, 330 + x, 100 + y, l3, yel, w2, l3, yel, w2);// alien bullet

		drawEllipse(10 * a + 0, b + 0, 10 * a + 50, b + 25, 0, 0, 0, 255, 216, 0);// space ship



		delay(10);
		//for bullets when the strike the bottom of the screen.
		drawRectangle(110 + i, 80 + j, 150 + i, 120 + j, 0, 0, 0, 0, 0, 0);

		drawRectangle(120 + x, 80 + y, 130 + x, 100 + y, 0, 0, 0, 0, 0, 0);



		drawEllipse(160 + i, 80 + j, 200 + i, 120 + j, 0, 0, 0, 0, 0, 0);

		drawEllipse(170 + x, 80 + y, 180 + x, 100 + y, 0, 0, 0, 0, 0, 0);


		drawRectangle(210 + i, 80 + j, 250 + i, 120 + j, 0, 0, 0, 0, 0, 0);

		drawEllipse(220 + x, 80 + y, 230 + x, 100 + y, 0, 0, 0, 0, 0, 0);


		drawEllipse(260 + i, 80 + j, 300 + i, 120 + j, 0, 0, 0, 0, 0, 0);

		drawEllipse(270 + x, 80 + y, 280 + x, 100 + y, 0, 0, 0, 0, 0, 0);



		drawRectangle(310 + i, 80 + j, 350 + i, 120 + j, 0, 0, 0, 0, 0, 0);

		drawEllipse(320 + x, 80 + y, 330 + x, 100 + y, 0, 0, 0, 0, 0, 0);



		drawEllipse(10 * a + 0, b + 0, 10 * a + 50, b + 25, 0, 0, 0, 0, 0, 0);

		i += 3;//incremants the x coordinates of the aliens
		if (i >= 600) {
			i = 0;
			j += 10;//incremants the y coordinate of the aliens 
			if (j >= 150) {
				j = 0;
			}
		}
		if (y <= b + 25) {//incremants the  y coordinate of bullet
			y += 4;

		}
		if (80 + y >= b + 25) {
			x = i;
			y = j;
			// condition to increase the damage on the ship when the alien bullets collide with the space ship 
			if ((120 + x >= 10 * a + 0 || 130 + x <= 10 * a + 50) || (170 + x >= 10 * a + 0 || 180 + x <= 10 * a + 50) || (220 + x >= 10 * a + 0 || 230 + x <= 10 * a + 50) || (270 + x >= 10 * a + 0 || 280 + x <= 10 * a + 50) || (320 + x >= 10 * a + 0 || 330 + x <= 10 * a + 50)) {
				damage += 1;
				if (damage == 10) {
					cout << " You lose !" << endl;
					system("CLS");
					endgame = true;
				}
			}
		}
		//to move the space ship left	
		if (GetAsyncKeyState(VK_LEFT) != 0) {
			a -= 1;   // moves the spaceship towards left
		}
		//to move the space ship to right
		if (GetAsyncKeyState(VK_RIGHT) != 0) {
			a += 1;   // moves the spaceship towards right
		}
		//to make the space ship fire
		if (GetAsyncKeyState(VK_SPACE) != 0)
		{
			//draws bullet
			drawRectangle(10 * a + 23, d + 5, 10 * a + 50 - 20, d + 25, 0, 0, 0, 0, 127, 127);
			delay(10);
			drawRectangle(10 * a + 23, d + 5, 10 * a + 50 - 20, d + 25, 0, 0, 0, 0, 0, 0);
			d -= 10;//decremants the coordinates of the bullet
			if (d <= 120 + j) /*here j is the x cordinates so that bullets at different positions also decrease their coordinates */  {
				d = 400;
				//decreases the health of the aliens
				if (10 * a + 23 >= 110 + i && 10 * a + 50 - 20 < 150 + i) {
					h1--;
					if (h1 == 0) {
						fh = 0;
						qw = 0;
						zx = 0;

						score += 10;

					}
				}
				if (10 * a + 23 >= 160 + i && 10 * a + 50 - 20 < 200 + i) {
					h2--;
					if (h2 == 0) {
						pur = 0;
						l = 0;
						black = 0;
						score += 10;

					}
				}
				if (10 * a + 23 >= 210 + i && 10 * a + 50 - 20 < 250 + i) {
					h3--;
					if (h3 == 0) {
						n = 0;
						pink = 0;
						w = 0;
						l2 = 0;
						score += 10;

					}
				}
				if (10 * a + 23 >= 260 + i && 10 * a + 50 - 20 < 300 + i) {
					h4--;
					if (h4 == 0) {
						o = 0;
						w1 = 0;
						blue = 0;
						blu = 0;
						score += 10;

					}
				}
				if (10 * a + 23 >= 310 + i && 10 * a + 50 - 20 < 350 + i) {
					h5--;
					if (h5 == 0) {
						p = 0;
						l3 = 0;
						yel = 0;
						w2 = 0;
						score += 10;
					}
				}
				score3 = score;
				if (score == 50) {
					endgame = true;
					system("cls");
				}
			}
		}
	}
	ifstream read;
	read.open("name.txt");
	int ad = 0;
	while (!read.eof())
	{
		getline(read, name1[ad]);
		ad++;
	}
	cout << " Player : ";
	cout << name1[0];
	cout << endl;
	int dx = 0;
	file_3.open("g.txt");
	while (!file_3.eof())
	{
		file_3 >> genders[dx];

		if (genders[dx] == 'm')
		{
			count_m++;
		}
		else if (genders[dx] == 'f')
		{
			count_f++;
		}
		dx++;
	}
	cout << " Score : " << score << endl;
	cout << " Number of males played the game : " << count_m << endl;
	cout << " Number of female played the game : " << count_f << endl;
	if (count_m > count_f)
	{
		cout << " Males Have Played This game More " << endl;
	}
	else if (count_f > count_m)
	{
		cout << " Females Have played This Game more " << endl;
	}
	else
	{
		cout << " Both Gender Have played Equal Number of Times " << endl;
	}
	cout << endl;
	cout << endl;
	cout << endl;
	cout << " CONGRATULATIONS !! \n" << endl;
	cout << " YOU WIN " << endl;
	cout << " Do You Want to Play Again? " << endl;
	cout << "  1 for Yes & 2 for No : ";
	cin >> choice2;
	if (choice2 == 1)
	{

		gamemode(gamec);
		return 0;
	}
	else if (choice2 == 2)
	{
		return 0;
	}
	else
	{
		cout << "Quiting !" << endl;
		return 0;
	}
	file_3.close();
	system("pause");
	return 0;

}
int normalmode()
{
	int normal_count, n1, count_m = 0, count_f = 0;
	endgame2 = false;
	int i = 0, j = 0, k = 0, a = 0, b = 400, d = 400;// coordinates for space ship and aliens
	int x = 0, y = 0, z = 0;// coordinates for alien bullets
	int l = 255, l2 = 255, l3 = 255, m = 255, n = 255, o = 255, p = 255, fh = 24, qw = 100, zx = 98;//colors of the alliens
	int w = 255, w1 = 255, w2 = 255, black = 0, black1 = 0, black2 = 0, pur = 178, pur2 = 178, pink = 106, pink2 = 106, blue2 = 19, blue = 19, blu = 127, blu2 = 127, yel = 216, yel2 = 216, green = 33, ora = 252, gro = 102;
	int damage = 0;// damage to the space ship
	int score = 0;// initial score
	int H1 = 0;// x coordinates for rectangles of lives 
	int h = 255, t = 255, t1 = 255;// colors of ellipses for lives
	ofstream games1;
	games1.open("gamecount1.txt",ios::trunc); // trunc is used to delete already present data in file.
	normal_count = 0;
	normal_count++;
	games1 << normal_count;
	games1.close();
	string name1[10];
	system("CLS");
	int h1 = 2, h2 = 2, h3 = 2, h4 = 2, h5 = 2, h6 = 2;
	int s = 0;




	while (endgame2 == false) {


		// symbols for healths

		drawEllipse(180 + H1, 20, 200 + H1, 40, w, pur, blu, w, pur, blu);
		drawEllipse(220 + H1, 20, 240 + H1, 40, w, yel, black, w, yel, black);
		drawEllipse(260 + H1, 20, 280 + H1, 40, w, black, black, w, black, black);


		drawEllipse(110 + i, 80 + j, 150 + i, 120 + j, fh, qw, zx, fh, qw, zx);//aliens



		drawRectangle(120 + x, 80 + y, 130 + x, 100 + y, fh, qw, zx, fh, qw, zx);//alien bullet

		drawEllipse(160 + i, 80 + j, 200 + i, 120 + j, pur, black, l, pur, black, l);//alien



		drawEllipse(170 + x, 80 + y, 180 + x, 100 + y, pur, black, l, pur, black, l);//alien bullets

		drawRectangle(210 + i, 80 + j, 250 + i, 120 + j, l, pink, w, l, pink, n);//alien


		drawEllipse(220 + x, 80 + y, 230 + x, 100 + y, l, pink, w, l, pink, n);//alien bullet

		drawEllipse(260 + i, 80 + j, 300 + i, 120 + j, w, blue, blu, w, blue, blu);//allien


		drawEllipse(270 + x, 80 + y, 280 + x, 100 + y, w, blue, blu, w, blue, blu);// alien bullet

		drawRectangle(310 + i, 80 + j, 350 + i, 120 + j, l, yel, w, l, yel, w);//alien



		drawEllipse(320 + x, 80 + y, 330 + x, 100 + y, l, yel, w, l, yel, w);// alien bullet
		drawRectangle(360 + i, 80 + j, 400 + i, 120 + j, ora, gro, fh, ora, gro, fh);//alien
		drawEllipse(370 + x, 80 + y, 380 + x, 100 + y, ora, gro, fh, ora, gro, fh);// alien bullet

		drawEllipse(10 * a + 0, b + 0, 10 * a + 50, b + 25, 0, 0, 0, 255, 216, 0);// space ship



		delay(10);
		//for bullets when the strike the bottom of the screen.
		drawRectangle(110 + i, 80 + j, 150 + i, 120 + j, 0, 0, 0, 0, 0, 0);

		drawRectangle(120 + x, 80 + y, 130 + x, 100 + y, 0, 0, 0, 0, 0, 0);



		drawEllipse(160 + i, 80 + j, 200 + i, 120 + j, 0, 0, 0, 0, 0, 0);

		drawEllipse(170 + x, 80 + y, 180 + x, 100 + y, 0, 0, 0, 0, 0, 0);


		drawRectangle(210 + i, 80 + j, 250 + i, 120 + j, 0, 0, 0, 0, 0, 0);

		drawEllipse(220 + x, 80 + y, 230 + x, 100 + y, 0, 0, 0, 0, 0, 0);


		drawEllipse(260 + i, 80 + j, 300 + i, 120 + j, 0, 0, 0, 0, 0, 0);

		drawEllipse(270 + x, 80 + y, 280 + x, 100 + y, 0, 0, 0, 0, 0, 0);



		drawRectangle(310 + i, 80 + j, 350 + i, 120 + j, 0, 0, 0, 0, 0, 0);

		drawEllipse(320 + x, 80 + y, 330 + x, 100 + y, 0, 0, 0, 0, 0, 0);



		drawEllipse(360 + i, 80 + j, 400 + i, 120 + j, 0, 0, 0, 0, 0, 0);

		drawEllipse(370 + x, 80 + y, 380 + x, 100 + y, 0, 0, 0, 0, 0, 0);

		drawEllipse(10 * a + 0, b + 0, 10 * a + 50, b + 25, 0, 0, 0, 0, 0, 0);

		i += 3;//incremants the x coordinates of the aliens
		if (i >= 600) {
			i = 0;
			j += 10;//incremants the y coordinate of the aliens 
			if (j >= 150) {
				j = 0;
				// when aliens strike the boundry, 
			}
		}
		if (y <= b + 25) {//incremants the  y coordinate of bullet
			y += 4;

		}
		if (80 + y >= b + 25) {
			x = i;
			y = j;
			// condition to increase the damage on the ship when the alien bullets collide with the space ship 
			if ((120 + x >= 10 * a + 0 || 130 + x <= 10 * a + 50) || (170 + x >= 10 * a + 0 || 180 + x <= 10 * a + 50) || (220 + x >= 10 * a + 0 || 230 + x <= 10 * a + 50) || (270 + x >= 10 * a + 0 || 280 + x <= 10 * a + 50) || (320 + x >= 10 * a + 0 || 330 + x <= 10 * a + 50) || (370 + x >= 10 * a + 0 || 370 + x <= 10 * a + 50)) {
				damage += 2;
				if (damage == 10) {
					cout << " YOU LOOSE ! "<<endl;
					endgame2 = true;
					system("CLS");
				}
			}



		}
		//to move the space ship left	
		if (GetAsyncKeyState(VK_LEFT) != 0) {
			a -= 1;   // moves the spaceship towards left
		}
		//to move the space ship to right
		if (GetAsyncKeyState(VK_RIGHT) != 0) {
			a += 1;   // moves the spaceship towards right
		}
		//to make the space ship fire
		if (GetAsyncKeyState(VK_SPACE) != 0)
		{
			//draws bullet
			drawRectangle(10 * a + 23, d + 5, 10 * a + 50 - 20, d + 25, 0, 0, 0, 0, 127, 127);
			delay(10);
			drawRectangle(10 * a + 23, d + 5, 10 * a + 50 - 20, d + 25, 0, 0, 0, 0, 0, 0); // to add a bit of delay in movement
			d -= 10;//decremants the coordinates of the bullet
			if (d <= 120 + j)/*here j is the x cordinates so that bullets at different positions also decrease their coordinates */ {
				d = 400;
				//decreases the health of the aliens
				if (10 * a + 23 >= 110 + i && 10 * a + 50 - 20 < 150 + i) {
					h1--;
					if (h1 == 0) {
						fh = 0;
						qw = 0;
						zx = 0;


						score += 10;

					}
				}
				if (10 * a + 23 >= 160 + i && 10 * a + 50 - 20 < 200 + i) {
					h2--;
					if (h2 == 0) {
						pur = 0;
						l = 0;
						w = 0;
						black = 0;
						score += 10;

					}
				}
				if (10 * a + 23 >= 210 + i && 10 * a + 50 - 20 < 250 + i) {
					h3--;
					if (h3 == 0) {
						n = 0;
						pink = 0;
						w = 0;
						l = 0;
						score += 10;

					}
				}
				if (10 * a + 23 >= 260 + i && 10 * a + 50 - 20 < 300 + i) {
					h4--;
					if (h4 == 0) {
						o = 0;
						w = 0;
						blue = 0;
						blu = 0;
						score += 10;

					}
				}
				if (10 * a + 23 >= 310 + i && 10 * a + 50 - 20 < 350 + i) {
					h5--;
					if (h5 == 0) {
						p = 0;
						l = 0;
						yel = 0;
						w = 0;
						score += 10;

					}
				}
				if (10 * a + 23 >= 360 + i && 10 * a + 50 - 20 < 400 + i) {
					h6--;
					if (h6 == 0) {
						ora = 0;
						gro = 0;

						fh = 0;


						score += 10;
					}
				}

				if (score == 60) {
					endgame2 = true;
					cout << " CONGRATULATIONS !! \n" << endl;
					cout << " YOU WIN !!" << endl;


				}
			}
		}
	}
	ifstream read;
	read.open("name.txt");
	int ad = 0;
	while (!read.eof())
	{
		getline(read, name1[ad]);
		ad++;
	}
	cout << " Player : ";
	cout << name1[0];
	cout << endl;
	ifstream file_3;
	file_3.open("g.txt");
		int dx = 0;
	while (!file_3.eof())
	{
		file_3 >> genders[dx];

		if (genders[dx] == 'm')
		{
			count_m++;
		}
		else if (genders[dx] == 'f')
		{
			count_f++;
		}
		dx++;
	}
	cout << " Score : " << score << endl;
	cout << " Number of males played the game : " << count_m << endl;
	cout << " Number of female played the game : " << count_f << endl;
	if (count_m > count_f)
	{
		cout << " Males Have Played This game More " << endl;
	}
	else if (count_f > count_m)
	{
		cout << " Females Have played This Game more " << endl;
	}
	else
	{
		cout << " Both Gender Have played Equal Number of Times " << endl;
	}
	cout << endl;
	int choice3;
	cout << " Do you want to play again? " << endl;
	cout << "  1 for Yes & 2 for No : ";
	cin >> choice3;
	if (choice3 == 1)
	{
		gamemode(choice);
	}
	while (choice3 < 1 && choice3>2)
	{
		cout << " wrong Entry!!. Enter again" << endl;
		cin >> choice2;
		if (choice3 == 1)
		{
			gamemode(choice);
		}
		if (choice3 == 2)
		{
			return 0;
		}
	}
	if (choice3 == 2)
	{
		return 0;
	}

	file_3.close();
	system("pause");
	return 0;
}
int hardmode()
{
	int count_m=0,count_f=0;
	ifstream file_3;
	endgame3 = 0;
	int i = 0, j = 0, k = 0, a = 0, b = 400, d = 400;// coordinates for space ship and aliens
	int x = 0, y = 0, z = 0;// coordinates for alien bullets
	int l = 255, l2 = 255, l3 = 255, m = 255, n = 255, o = 255, p = 255, fh = 24, qw = 100, zx = 98;//colors of the alliens
	int w = 255, w1 = 255, w2 = 255, black = 1, black1 = 1, black2 = 1, pur = 178, pur2 = 178, pink = 106, pink2 = 106, blue2 = 19, blue = 19, blu = 127, blu2 = 127, yel = 216, yel2 = 216, green = 33, ora = 252, gro = 102;
	int damage = 0;// damage to the space ship
	//int h1 = 1, h2 = 1, h3 = 1, h4 = 1, h5 = 1, h6 = 1;//healths of aliens
	int score = 0;// initial score
	int H1 = 0;// x coordinates for rectangles of lives 
	int h = 255, t = 255, t1 = 255;// colors of ellipses for lives
	string name1[10];
	int h1 = 4, h2 = 4, h3 = 4, h4 = 4, h5 = 4, h6 = 4, h7 = 4;
	int df = 209, hj = 255, tr = 45;// colors for aliens
	system("CLS");
	h1 = 4, h2 = 4, h3 = 4, h4 = 4, h5 = 4, h6 = 4;
	int s = 0;




	while (endgame3 == false) {


		// symbols for healths

		drawEllipse(180 + H1, 20, 200 + H1, 40, w, pur, blu, w, pur, blu);
		drawEllipse(220 + H1, 20, 240 + H1, 40, w, yel, black, w, yel, black);
		drawEllipse(260 + H1, 20, 280 + H1, 40, w, black, black, w, black, black);


		drawEllipse(110 + i, 80 + j, 150 + i, 120 + j, fh, qw, zx, fh, qw, zx);//aliens



		drawRectangle(120 + x, 80 + y, 130 + x, 100 + y, fh, qw, zx, fh, qw, zx);//alien bullet

		drawEllipse(160 + i, 80 + j, 200 + i, 120 + j, pur, black, l, pur, black, l);//alien



		drawEllipse(170 + x, 80 + y, 180 + x, 100 + y, pur, black, l, pur, black, l);//alien bullet

		drawRectangle(210 + i, 80 + j, 250 + i, 120 + j, l, pink, w, l, pink, n);//alien


		drawEllipse(220 + x, 80 + y, 230 + x, 100 + y, l, pink, w, l, pink, n);//alien bullet
		drawEllipse(260 + i, 80 + j, 300 + i, 120 + j, w, blue, blu, w, blue, blu);//allien


		drawEllipse(270 + x, 80 + y, 280 + x, 100 + y, w, blue, blu, w, blue, blu);// alien bullet

		drawRectangle(310 + i, 80 + j, 350 + i, 120 + j, l, yel, w, l, yel, w);//alien



		drawEllipse(320 + x, 80 + y, 330 + x, 100 + y, l, yel, w, l, yel, w);// alien bullet
		drawRectangle(360 + i, 80 + j, 400 + i, 120 + j, ora, gro, fh, ora, gro, fh);//alien
		drawEllipse(370 + x, 80 + y, 380 + x, 100 + y, ora, gro, fh, ora, gro, fh);// alien bullet


		drawRectangle(410 + i, 80 + j, 450 + i, 120 + j, df, hj, tr, df, hj, tr);//alien
		drawEllipse(420 + x, 80 + y, 430 + x, 100 + y, df, hj, tr, df, hj, tr);// alien bullet


		drawEllipse(10 * a + 0, b + 0, 10 * a + 50, b + 25, 0, 0, 0, 255, 216, 0);// space ship



		delay(10);
		//for bullets when the strike the bottom of the screen.
		drawRectangle(110 + i, 80 + j, 150 + i, 120 + j, 0, 0, 0, 0, 0, 0);

		drawRectangle(120 + x, 80 + y, 130 + x, 100 + y, 0, 0, 0, 0, 0, 0);



		drawEllipse(160 + i, 80 + j, 200 + i, 120 + j, 0, 0, 0, 0, 0, 0);

		drawEllipse(170 + x, 80 + y, 180 + x, 100 + y, 0, 0, 0, 0, 0, 0);


		drawRectangle(210 + i, 80 + j, 250 + i, 120 + j, 0, 0, 0, 0, 0, 0);

		drawEllipse(220 + x, 80 + y, 230 + x, 100 + y, 0, 0, 0, 0, 0, 0);


		drawEllipse(260 + i, 80 + j, 300 + i, 120 + j, 0, 0, 0, 0, 0, 0);

		drawEllipse(270 + x, 80 + y, 280 + x, 100 + y, 0, 0, 0, 0, 0, 0);



		drawRectangle(310 + i, 80 + j, 350 + i, 120 + j, 0, 0, 0, 0, 0, 0);

		drawEllipse(320 + x, 80 + y, 330 + x, 100 + y, 0, 0, 0, 0, 0, 0);



		drawEllipse(360 + i, 80 + j, 400 + i, 120 + j, 0, 0, 0, 0, 0, 0);

		drawEllipse(370 + x, 80 + y, 380 + x, 100 + y, 0, 0, 0, 0, 0, 0);


		drawEllipse(410 + i, 80 + j, 450 + i, 120 + j, 0, 0, 0, 0, 0, 0);
		drawEllipse(420 + x, 80 + y, 430 + x, 100 + y, 0, 0, 0, 0, 0, 0);



		drawEllipse(10 * a + 0, b + 0, 10 * a + 50, b + 25, 0, 0, 0, 0, 0, 0);

		i += 3;//incremants the x coordinates of the aliens
		if (i >= 600) {
			i = 0;
			j += 10;//incremants the y coordinate of the aliens 
			if (j >= 150) {
				j = 0;
				// when aliens strike the boundry, y cordinate increases and aliens starts from the next row( lower than the previous position)
			}
		}
		if (y <= b + 25) {//incremants the  y coordinate of bullet
			y += 4;

		}
		if (80 + y >= b + 25) {
			x = i;
			y = j;
			// condition to increase the damage on the ship when the alien bullets collide with the space ship 
			if ((120 + x >= 10 * a + 0 && 130 + x <= 10 * a + 50) || (170 + x >= 10 * a + 0 && 180 + x <= 10 * a + 50) || (220 + x >= 10 * a + 0 && 230 + x <= 10 * a + 50) || (270 + x >= 10 * a + 0 && 280 + x <= 10 * a + 50) || (320 + x >= 10 * a + 0 && 330 + x <= 10 * a + 50) || (370 + x >= 10 * a + 0 && 380 + x <= 10 * a + 50) || (420 + x >= 10 * a + 0 && 430 + x <= 10 * a + 50)) {

					damage += 2;
					if (damage == 10) {
						cout << " YOU LOOSE ! " << endl;
						endgame3 = true;
				}
			}
		}
		//to move the space ship left	
		if (GetAsyncKeyState(VK_LEFT) != 0) {
			a -= 1;   // moves the spaceship towards left
		}
		//to move the space ship to right
		if (GetAsyncKeyState(VK_RIGHT) != 0) {
			a += 1;   // moves the spaceship towards right
		}
		//to make the space ship fire
		if (GetAsyncKeyState(VK_SPACE) != 0)
		{
			//draws bullet
			drawRectangle(10 * a + 23, d + 5, 10 * a + 50 - 20, d + 25, 0, 0, 0, 0, 127, 127);
			delay(10);
			drawRectangle(10 * a + 23, d + 5, 10 * a + 50 - 20, d + 25, 0, 0, 0, 0, 0, 0); // to add a bit of delay in movement
			d -= 10;//decremants the coordinates of the bullet
			if (d <= 120 + j) {
				d = 400;
				//decreases the health of the aliens
				if (10 * a + 23 >= 110 + i && 10 * a + 50 - 20 < 150 + i) {
					h1--;
					if (h1 == 0) {
						fh = 0;
						qw = 0;
						zx = 0;
						score += 10;
					}
				}
				if (10 * a + 23 >= 160 + i && 10 * a + 50 - 20 < 200 + i) {
					h2--;
					if (h2 == 0) {
						pur = 0;
						l = 0;
						w = 0;
						black = 0;
						score += 10;
					}
				}
				if (10 * a + 23 >= 210 + i && 10 * a + 50 - 20 < 250 + i) {
					h3--;
					if (h3 == 0) {
						n = 0;
						pink = 0;
						w = 0;
						l = 0;
						score += 10;
					}
				}
				if (10 * a + 23 >= 260 + i && 10 * a + 50 - 20 < 300 + i) {
					h4--;
					if (h4 == 0) {
						o = 0;
						w = 0;
						blue = 0;
						blu = 0;
						score += 10;
					}
				}
				if (10 * a + 23 >= 310 + i && 10 * a + 50 - 20 < 350 + i) {
					h5--;
					if (h5 == 0) {
						p = 0;
						l = 0;
						yel = 0;
						w = 0;
						score += 10;
					}
				}
				if (10 * a + 23 >= 360 + i && 10 * a + 50 - 20 < 400 + i) {
					h6--;
					if (h6 == 0) {
						ora = 0;
						gro = 0;

						fh = 0;
						score += 10;
					}
				}
				if (10 * a + 23 >= 410 + i && 10 * a + 50 - 20 < 450 + i) {
					h7--;
					if (h7 == 0) {
						df = 0;
						hj = 0;
						tr = 0;

						score += 10;
					}
				}
				

				if (score == 70) {
					endgame3 = true;
					cout << " CONGRATULATIONS !! \n" << endl;
					cout << " YOU WIN !! \n" << endl;

				}
			}
		}
	}
	ifstream read;
	read.open("name.txt");
	int ad = 0;
	while (!read.eof())
	{
		getline(read, name1[ad]);
		ad++;
	}
	cout << " Player : ";
	cout << name1[0];
	cout << endl;
	int dx = 0;
	file_3.open("g.txt");
	while (!file_3.eof())
	{
		file_3 >> genders[dx];

		if (genders[dx] == 'm')
		{
			count_m++;
		}
		else if (genders[dx] == 'f')
		{
			count_f++;
		}
		dx++;
	}
	cout << " Score : " << score << endl;
	cout << " Number of males played the game : " << count_m << endl;
	cout << " Number of female played the game : " << count_f << endl;
	if (count_m > count_f)
	{
		cout << " Males Have Played This game More " << endl;
	}
	else if (count_f > count_m)
	{
		cout << " Females Have played This Game more " << endl;
	}
	else
	{
		cout << " Both Gender Have played Equal Number of Times " << endl;
	}
	cout << endl;
	int choice4;
	cout << " Do you want to play again? " << endl;
	cout << "  1 for Yes & 2 for No : ";
	cin >> choice4;
	while (choice4 < 1 || choice4>2)
	{
		if (choice4 == 1)
		{
			gamemode(choice);
		}
		else if (choice4 == 2)
		{
			return 0;
		}
	}
	if (choice4 == 1)
	{
		gamemode(choice);
	}
	else if (choice4 == 2)
	{
		return 0;
	}
	file_3.close();
	system("pause");
	return 0;
}
int main() {
	menu(choice);
	system("pause");
	return 0;
}
