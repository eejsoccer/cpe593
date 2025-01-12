/*
Author: Ethan Jones
Cite: Worked with classmate Tyler McShea
Pledge: I pledge my honor that I have abided by the stevens honor system
*/

//#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<algorithm>

using namespace std;

int
lcs (string a, string b)
{
  int lengA = a.length ();
  int lengB = b.length ();
  int matrix[lengA + 1][lengB + 1];

  for (int x = 0; x <= lengA; x++)
    {
      for (int z = 0; z <= lengB; z++)
	{
	  if (x == 0 || z == 0)
	    matrix[x][z] = 0;
	  else if (a.at (x - 1) == b.at (z - 1))
	    matrix[x][z] = matrix[x - 1][z - 1] + 1;
	  else
	    matrix[x][z] = std::max (matrix[x - 1][z], matrix[x][z - 1]);
	}
    }
  return matrix[lengA][lengB];
}

string
loadFile (const string filename)
{
  ifstream f (filename);
  stringstream fileContents;
  string contents;
  fileContents << f.rdbuf ();
  contents = fileContents.str ();
  return contents;
}



int
main ()
{
  string fileOne, fileTwo;
  cout << "type in the location of the first text file\n";
  cin >> fileOne;

  cout << "type in the location of the second text file\n";
  cin >> fileTwo;

  string X = loadFile (fileOne);
  string Y = loadFile (fileTwo);

  cout << lcs (X, Y) << endl;

  return 0;
}
