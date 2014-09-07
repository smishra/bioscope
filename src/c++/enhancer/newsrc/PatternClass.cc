 #include <XmlDefines.h>
#include <string.h>
 #include <SeqCodeDefines.h>
 #include <PatternClass.h>

char ATGCCHAR[] = {
  'A',
  'T',
  'C',
  'G' 
} ;
 
int ATGC1[] = {

  0,   // A
  3,   // B
  2,   // C
  3,   // D
  0,    // E
  0,    // F
  3,   // G
  3,   // H
  0,    // I
  0,    // J
  2,   // K
  0,    // L
  2,   // M
  4,    // N
  0,    // O
  0,    // P
  0,    // Q
  2,   // R
  2,   // S
  1,   // T
  0,    // U
  3,   // V
  2,   // W 
  0,    // X
  2,   // Y
  0,    // Z
} ;

 void 
 PatternClass::reversePattern () 
     {
       int PatternLength = OriginalPattern.length () ;
       int start = 0 ;
       int count = 1 ;
       char *c_pattern = (char *) OriginalPattern.c_str() ;

       char tempstr[1000] ;
       char revstr[1000] ;

       memset (tempstr, '\0', 1000) ;
       memset (revstr, '\0', 1000) ;
       while (count < PatternLength) 
	 {

	   while ((!(isalpha (c_pattern[count]))) || isdigit(c_pattern[count]))
	     {
	       count++ ;
	       if (count >= PatternLength) 
		 break ;
	     }

	   strncpy (tempstr, &c_pattern[start], count - start) ;
	   strcat (tempstr, revstr) ;
	   strcpy (revstr, tempstr) ;

	   memset(tempstr, '\0', 1000) ;
	   start = count ;
	   count++ ;
	 }
       if (strlen(revstr) < strlen(c_pattern ) )
       {
	 tempstr[0] = c_pattern[strlen(c_pattern)-1] ;
	 strcat (tempstr, revstr) ;
	 strcpy (revstr, tempstr) ;
       }

       for (count = 0 ; count < strlen(revstr) ; count++)
	 {
	   if (isalpha(revstr[count]))
	       revstr[count] = ComplementCode[revstr[count] - 0x41][0] ;
	 }
       ReversePattern = revstr ;
     }

 void 
 PatternClass::TranslateToRegex ( string &PatternString, string &Destination) 
     {

       int PatternLength ;
       char tempbuffer[1000] ;
       char *c_pattern = (char *) PatternString.c_str() ;

       for (PatternLength = 0 ; PatternLength < strlen(c_pattern) ;
	    PatternLength++) 
	 {
	   if (isalpha(c_pattern[PatternLength]) )
	     {
	       Destination += TransformCode[c_pattern[PatternLength] - 0x41 ] ;
	     }
	   else if (isdigit(c_pattern[PatternLength]))
	     {
	       sprintf (tempbuffer, "{0,%c}", c_pattern[PatternLength]) ;
	       Destination += tempbuffer ;
	     }
	   else
	     {
	       sprintf (tempbuffer, "%c", c_pattern[PatternLength]) ;
	       Destination += tempbuffer ;
	     }
	 }
     }

void 
PatternClass::PrintTrip(int pos, int & TripCount)
{
  
  char substring[4];
  int left ;
  int middle ;
  int right ;
  int i, j, k ;
  int count = 0 ;

  memset(substring, '\0', 4) ;
  OriginalPattern.copy(substring, 3, pos - 2) ;
  PatUnrolledCount[TripCount] = 0  ;
  for (i = 0 ; i < strlen (LetterCodes[substring[0] - 0x41]) ; i++)
    {
      left = ATGC1[LetterCodes[substring[0]-0x41][i] - 0x41] << 4 ;
      for (j = 0 ; j < strlen (LetterCodes[substring[1] - 0x41]) ; j++)
	{
	  middle = ATGC1[LetterCodes[substring[1]-0x41][j] - 0x41] << 2 ;
	  for (k = 0 ; k < strlen (LetterCodes[substring[2] - 0x41]) ; k++)
	    {
	      right = ATGC1[LetterCodes[substring[2]-0x41][k] - 0x41]  ;
	      PatUnrolled[TripCount][count++] = left | middle | right ;
	      PatUnrolledCount[TripCount]++ ;
	    }
	}
    }
  strcpy (Patterns[TripCount], substring)  ;
  cout << substring << endl ;

}

void PatternClass::PrintAll()
{

  int i, j ; 

  cout << "Printing all the seq length " << endl ;
  for (i = 0 ; i < PatternCount ; i++)
    {
      cout << Patterns[i] << endl ;
      for (j = 0 ; j < PatUnrolledCount[i] ; j++)
	{
	  cout << ATGCCHAR[((PatUnrolled[i][j] >> 4) & 0x3)] << ATGCCHAR[((PatUnrolled[i][j] >>2) & 0x3)] << ATGCCHAR[(PatUnrolled[i][j] & 0x3)] << endl ;
	}
      cout << endl ;
    }

      

}

void 
PatternClass::SetVarCodesCount()
{

  string::iterator str_iter ;
  int i = 0 ;
  PatternCount = 0 ;
  
  for (str_iter = OriginalPattern.begin() ; str_iter != OriginalPattern.end() ; str_iter++)
    {
      PTValue[i] = VarCodes[*str_iter - 0x41] ;
      PTSums[i] = VarCodes[*str_iter - 0x41] ;
      if (i == 1) 
	{
	  PTSums[i] += PTValue[0] ;
	}
      else if (i != 0)
	{
	  PTSums[i] += PTValue[i-1] + PTValue[i-2] ;
	}
      if (PTSums[i] >= 3)
	{
	  PrintTrip (i, PatternCount) ;
	  PatternCount++ ;
	}
      i++ ;
    }

  PrintAll() ;
  
}
