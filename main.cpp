//File name: main.cpp
//Developer: Giovanni Carmona
//Email: carmonag141228@student.vvc.edu
//Description: The concordance will be a list of all the words found in a text file, alice.txt, with a count of the
//number of times the word occurred,  where the word occurred, punctuation is to be removed, and all letters are forced
//to be lowercase.
#include <ctype.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>

int main()

{
  char file[20];
  
  double line=0;
  int i=0;
  int j=0;
  int k=0;
  
  std::string lines[1000];
  std::string word;
  std::string concord[1000];

  int count[1000]={0};
  int x=0;

  std::ifstream f;
  f.open("alice.txt");
  std::string w;
  //removes punctuations and converts upper case letters to lower case
  while(f.good())
  { 
    std::getline(f, word);
      for(int i=0; i < word.length(); i++)
    {
      if(!isalpha(word.at(i)))
      {
        if(word.at(i)!= ' ')
          for(int j=i; j < word.length()-1; j++)
      {
        word.at(j) = word.at(j+1);
    }
      if(i == word.length()-1)
        word.at(i)= ' ';
        }
      if(!islower(word.at(i)))
        {
         word.at(i)=tolower(word.at(i));
        }
     }
   std::istringstream s(word);
    while(s>>w) 
    //read each word in each line
    {
      bool fail = false;
      int m = -1;
      
      for(int k = 0; k < x; k++)
      {
        if(concord[k] == w)
      {
      fail=true;
      m = k;
      }
    }
      if(fail!=true)
      {
      concord[x]=w;
      count[x]=1;
      std::stringstream number;
      
      number << line + 1;
      lines[x]=number.str();
      x++;
    }
    else
      {
    count[m]++;
    std::stringstream number_;
    number_<< line+1;
    lines[m] = lines[m]+","+ number_.str();
      }
    }
      line=line+1;
     }

     std::cout << std::left << std::setw(15) << "Word" << std::setw(3) << " : "<<"count"<< std::setw(3) << " : " << "Occurences"<<std::endl;

     for(int b = 0; b < x; b++)

          std::cout << std::left << std::setw(15) << concord[b]<< std::setw(5) << " : " << count[b]<<std::setw(3)<<" : "<<lines[b]<< std::endl;
     return 0;

}
