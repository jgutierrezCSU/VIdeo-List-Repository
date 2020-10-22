
//Gutierrez,jesus
//jgutierrez

#include <iostream>
using namespace std;
#include "video.h"
#include "vlist.h"

Vlist list;
string lookup_video;
string remove_video;
string title;
string link;
string comment;
float length;
int rating;
int videoCount = 0;

void cmd_help()
{

	cout << "Options:\nInsert: Insert a new video into the linked list (Title,  url, comment,length,rating)"<< endl;
	cout << "print: Print  all  the  videos  in  thelist  " << endl;
	cout << "length: Print the number of videosin the list as a single integer" << endl;
	cout << "lookup: If the given title is in thelist, print the video " << endl;
	cout << "remove: Remove given title if in list" << endl;
	cout << "print_by_length: prints all the videos in the list ordered by length (short to long),If two or more videos have the same length ,sorted alphabetically\n" << endl;
	
	cout << "exit: Exit program\n" << endl;
	

}



int main()
{
	//command given by user , needs to be insert , remove ,print , length or lookup.Else will terminate w/ cerr
	string command;
	const int MAX = 100;

	cmd_help();
	
	// while loop for user input
	while(getline(cin, command))
	{	

		//will insert users videos
		if (command == "insert")
		{
				
					cout << "Title: ";
					getline(cin,title);
					cout << "Link: " ;
					getline(cin,link);
					cout << "Comment: " ;
					getline(cin,comment);
					cout << "Length (float): ";
					cin >> length;
					cout << "Rating (int): ";
					cin >> rating;
					cin.ignore();
					
					if (videoCount >= MAX)
					{
						cerr << "Too many videos, giving up." << endl;
						return 1;
					}
					// "if" will check if there are any duplicate videos and return tru or false
					//false means no duplicates
					if (list.check_duplicates(title) == false){
					//if no duplicates create new VIDEO objects DYNAMICALLY
					Video *video_ptr = new Video(title,link,comment,length ,rating );
					// passing pointer to object in vlist
					list.insert(video_ptr);
					 }
					 //if there are duplicates print our cerr
					 else{
					 	cerr << "Could not insert video <" << title << ">, already in list." << endl;
					 }
					
					
		}
		// user needs to look up video 
		else if(command == "lookup")
		{	
			cout << "Title: ";
			getline(cin,lookup_video);
			//list.lookup(lookup_video);
			//if title of video is not in list return false and print cerr
			if (list.lookup(lookup_video) == false )
			{
				cerr << "Title <" <<lookup_video<< "> not in list." << endl;

			}

		}
		//user wants to remove video from list
		else if(command == "remove")
		{
			cout << "Title: ";
			//get what video need to be removed
			getline(cin,remove_video);
			//list.lookup(lookup_video);
			if (list.remove(remove_video) == false )
			{  //print out cerr if video was not found
				cerr << "Title <" << remove_video << "> not in list, could not delete." << endl;

			}
		}
		// user wants to print length
		else if(command == "length")
		{
			cout << "Number of Videos in list: ";
			//print count from lookup function
			cout << list.length() << endl;
			//cout  << counter << endl;
		}
		//user want to print list
		//print nothing if list is empty
		else if (command == "print")
		{
			
			list.print();
			
		}
		else if (command == "print_by_length")
		{
			//int size =list.length();
			//int high = size;
			list.print_by_length();
			
		}
		else if (command == "exit")
		{
			
			return 0;
			
		}


		//user did not choose any valid arguments/commands
		else{

		cerr << "<" << command << "> is not a legal command\n\n" << endl;
			cmd_help();
		}
	}
	
	
}