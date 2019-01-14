#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class Track
{
public:
	Track(char* artist, char* title, int year);
	Track(const Track& source);
	~Track();


	const char* GetArtist();
	const char* GetTitle();
	int GetYear();
	void PrintTrack();

private:
	char* m_artist;
	char* m_title;
	int m_year;
};

Track::Track(char* artist, char* title, int year)
{
	int artistLength = strlen(artist);
	int artistCapacity = artistLength + 1;
	this->m_artist = new char[artistCapacity];
	strcpy_s(this->m_artist, artistCapacity, artist);

	int titleLength = strlen(title);
	int titleCapacity = titleLength + 1;
	this->m_title = new char[titleCapacity];
	strcpy_s(this->m_title, titleCapacity, title);

	m_year = year;
}

Track::Track(const Track& source)
{
	int artistLength = strlen(source.m_artist);
	int artistCapacity = artistLength + 1;
	this->m_artist = new char[artistCapacity];
	strcpy_s(this->m_artist, artistCapacity, source.m_artist);

	int titleLength = strlen(source.m_title);
	int titleCapacity = titleLength + 1;
	this->m_title = new char[titleCapacity];
	strcpy_s(this->m_title, titleCapacity, source.m_title);

	m_year = source.m_year;
}

Track::~Track()
{
	delete[] m_artist;
	delete[] m_title;
}

const char* Track::GetArtist()
{
	return m_artist;
}

const char* Track::GetTitle()
{
	return m_title;
}

int Track::GetYear()
{
	return m_year;
}

void Track::PrintTrack()
{
	cout << m_artist << " - " << m_title << ", " << m_year << endl;
}