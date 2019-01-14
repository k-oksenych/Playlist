#include <iostream>

#include "Playlist.h"
#include "Track.h"

using namespace std;

int main()
{
	Playlist FeelIt;

	Track firstTrack("Disturbed", "What Are You Waiting For", 2015);
	//Track otherTrack(firstTrack);
	//otherTrack.PrintTrack();
	FeelIt.Add(firstTrack);

	Track secondTrack("Daughtry", "Outta My Head", 2011);
	FeelIt.Add(secondTrack);
	
	Track thirdTrack("Skillet", "Comatose", 2006);
	FeelIt.Add(thirdTrack);

	Track fourthTrack("Imagine Dragons", "Walking The Wire", 2017);
	FeelIt.Add(fourthTrack);

	Track fifthTrack("Thousand Foot Krutch", "I Climb", 2003);
	FeelIt.Add(fifthTrack);

	Track sixthTrack("System of a Down", "Deer Dance", 2001);
	FeelIt.Add(sixthTrack);

	Track seventhTrack("Disturbed", "Indestructible", 2008);
	FeelIt.Add(seventhTrack);

	//FeelIt.RemoveByTitle("Comatose");

	//FeelIt.Print();

	FeelIt.Save("user.txt");
	Playlist favorites = Playlist::Load("user.txt");
	favorites.Print();

	//Playlist newPlaylist(FeelIt);
	//newPlaylist.Print();
}