#pragma once

#include <string>
#include <stdint.h>
#include <vector>

using namespace std;

union FastFloat
{
	uint64_t i;
	float x;
};

struct Xor1024
{
	uint64_t s1024[16];
	int p;
};

struct StockData
{
	uint32_t Date, Volume;
	float Open, High, Low, Close, AveragePrice;

	StockData() {}

	StockData(uint32_t date, float open, float high, float low, float close, uint32_t volume)
	{
		this->Date = date;
		this->Open = open;
		this->High = high;
		this->Low = low;
		this->Close = close;
		this->Volume = volume;
		this->AveragePrice = (this->High + this->Low) / 2.0f;
	}
};

struct StockDataVector
{
	string Description;
	vector<StockData> *Data;

	StockDataVector()
	{
		this->Data = new vector<StockData>();
	}

	StockDataVector(vector<StockData> *v)
	{
		this->Data = v;
	
	}

	~StockDataVector()
	{		
		delete this->Data;

		this->Data = NULL;
	}
};