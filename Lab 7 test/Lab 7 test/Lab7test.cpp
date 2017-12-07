// Lab7test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	
    return 0;
}

void Loop()
{
	int n = 0;
	for (int x = 0; x < 10; x++)
	{
		for (int y = x + 1; y < 10; y++)
		{
			for (int z = y + 1; z < 10; z++)
			{
				n++;
			}
			if (y + 1 >= 10)
			{
				n++;
			}
		}
		if (x + 1 >= 10)
		{
			n++;
		}
	}
	
}

