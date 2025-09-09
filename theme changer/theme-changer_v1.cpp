#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <cstdlib>
using namespace std;
namespace fs = std::filesystem;

void replaceFile(string themePath)
{
	string homedir = getenv("HOME");
	fs::path themePath1 = fs::path(homedir) / "code/mini-projects/theme changer/";

	fs::current_path(themePath1);
	ifstream sourceFile(themePath);
	if(!sourceFile)
	{
		if(sourceFile.bad()) cout << "bad file" << endl;
		if(sourceFile.fail()) cout << "fail file" << endl;
		if(sourceFile.eof()) cout << "eof file" << endl;
		return;
	}
	string temp_string;
	string temp_string1;
	while(getline(sourceFile, temp_string))
	{
		temp_string1 += temp_string + "\n";	
	}	
	sourceFile.close();
	fs::current_path(homedir+"/.config/hypr");

	ofstream destFile("hyprland.conf", ios::binary);
	destFile << temp_string1;
	destFile.close();
}

int main()
{
	cout << "" << endl;
	cout << "--- Theme-Changer_v1 ---" << endl;
	cout << "Choose your desired Theme:" << endl;
	cout << "1. Original" << endl;
	cout << "2. Riced 1" << endl;
	cout << "3. Riced 2(main)" << endl;
	cout << "[1-3]: " << endl;

	int choice = 0;
	cin >> choice;

	if(choice == 1) 
	{
		system("pkill mpv");
		system("hyprpaper >/dev/null 2>&1 &");
		replaceFile("themes/hyprland.conf");
		cout << "replaced current theme with theme 1" << endl;
	}
	if(choice == 2) 
	{
		replaceFile("themes/riced1_hyprland.conf");
		system("mpvpaper -o \"--loop-file inf\" '*' ~/vids/wallpaper_juzo_suzuya.mp4 >/dev/null 2>&1 &");
		cout << "replaced current theme with theme 2" << endl;
	}
	if(choice == 3) 
	{
		replaceFile("themes/riced2_hyprland.conf");
		system("mpvpaper -o \"--loop-file inf\" '*' ~/vids/wallpaper_juzo_suzuya.mp4 >/dev/null 2>&1 &");
		cout << "replaced current theme with theme 3" << endl;
	}


	return 0;
}
