#pragma once
#include <cstdio>
#include <iostream>

#include "Track.h"

using namespace std;

class Playlist
{
public:
	Playlist();
	~Playlist();
	Playlist(const Playlist& sourse);
	static Playlist Load(const char* const path);

	void Add(const Track& track);
	int GetCount();
	void Print();
	bool RemoveByArtist(const char* const artist);
	bool RemoveByTitle(const char* const title);
	void Save(const char* const path);

private:
	Track** m_playlist;
	int m_size;
	int m_maxSize;
};

Playlist::Playlist()
{
	m_maxSize = 50;
	m_playlist = new Track*[m_maxSize];
	m_size = 0;
}

Playlist::Playlist(const Playlist& source)
{
	m_maxSize = source.m_maxSize;
	m_size = source.m_size;

	this->m_playlist = new Track*[m_maxSize];

	for (int i = 0; i < m_size; ++i)
	{
		this->m_playlist[i] = source.m_playlist[i];
	}
}

Playlist::~Playlist()
{
	delete[] m_playlist;
}

Playlist Playlist::Load(const char* const path)
{
	FILE* file = fopen(path, "rt");

	Playlist playlist;
	playlist.m_playlist = new Track*[playlist.m_maxSize];

	if (file != nullptr)
	{
		fread(&playlist.m_size, sizeof(int), 1, file);
		for (int i = 0; i < playlist.m_size; ++i)
		{
			fread(&playlist.m_playlist[i], sizeof(Track), 1, file);
		}
		fclose(file);
	}

	return playlist;
}

void Playlist::Save(const char* const path)
{
	FILE* file = fopen(path, "wt");

	if (file != nullptr)
	{
		fwrite(&m_size, sizeof(int), 1, file);
		for (int i = 0; i < m_size; ++i)
		{
			fwrite(&m_playlist[i], sizeof(Track), 1, file);
		}
		fclose(file);
	}
}

void Playlist::Add(const Track& track)
{
	if (m_size < m_maxSize)
	{
		m_playlist[m_size] = new Track (track);

		++m_size;
	}
	else
	{
		m_maxSize *= 2;

		Track** new_playlist = new Track*[m_maxSize];

		for (int i = 0; i < m_size; ++i)
		{
			new_playlist[i] = m_playlist[i];
		}
		new_playlist[m_size] = new Track(track);
		++m_size;

		delete[] m_playlist;

		m_playlist = new_playlist;
	}
}

int Playlist::GetCount()
{
	return m_size;
}

void Playlist::Print()
{
	for (int i = 0; i < m_size; ++i)
	{
		m_playlist[i]->PrintTrack();
	}
}

bool Playlist::RemoveByArtist(const char* const artist)
{
	for (int i = 0; i < m_size; ++i)
	{
		if (m_playlist[i]->GetArtist() == artist)
		{
			for (int j = i; j < m_size - 1; ++j)
			{
				m_playlist[j] = m_playlist[j + 1];
			}
			--m_size;
			return true;
		}
	}

	return false;
}

bool Playlist::RemoveByTitle(const char* const title)
{
	for (int i = 0; i < m_size; ++i)
	{
		if (m_playlist[i]->GetTitle() == title)
		{
			for (int j = i; j < m_size; ++j)
			{
				m_playlist[j] = m_playlist[j + 1];
			}
			--m_size;
			return true;
		}
	}

	return false;
}