#ifndef ENHANCER_CLASS
#define ENHANCER_CLASS

#include <string.h>
#include <vector>
#include <stdbool.h>
#include <algorithm>
#include <map>

using namespace std ;


class MotifClass {


  public :

    MotifClass (char ch, char orientation, int len, unsigned long pos)
    {
      Name = ch ;
      Type = orientation ;
      Length = len ;
      Position = pos ;
    }

  char GetName ()
    {
      return Name ;
    }

  char GetType ()
    {
      return Type ;
    }

  int GetLength ()
    {
      return Length ;
    }

  int GetPosition ()
    {
      return Position ;
    }
  
  private :
    
   char Name ;
   char Type ;
   int Length ;
   unsigned long Position ;
} ;

class EnhancerClass {

  public :

  EnhancerClass (char *fname, char val)
    {
      strcpy (FileName, fname) ;
      Name = val ;
    }

  ~EnhancerClass ()
    {
      int dsize = Motifs.size();
      vector<MotifClass *>::iterator startIterator;
      for( int i=0; i < dsize; i++ ) {
	startIterator = Motifs.begin();
	MotifClass *temp = *startIterator ;
	delete temp ;
	Motifs.erase( startIterator );
      }
    }
   
      

  void AddMotif (char ch, char orient, unsigned long pos, int len) 
    {

      MotifClass *Mot = new MotifClass(ch, orient, pos, len) ;
      Motifs.push_back (Mot) ;
    }
  void SetParameters () 
    {
      Start = Motifs[0]->GetPosition() ;
      End  = Motifs[Motifs.size() - 1]->GetPosition() ;
    }

  unsigned long GetPosition () 
    {
      return Start ;
    }

  unsigned long GetEnd ()
    {
      return End ;
    }

  unsigned long GetLength()
    {
      return (End - Start) ;
    }


  char * GetFileName ()
    {
      return FileName ;
    }

  char GetName ()
    {
      return Name ;
    }

  void SetName (char val)
    {
      Name = val ;
    }
  
  void SetFileName (char *val) 
    {
      strcpy (FileName, val) ;
    }

  vector<MotifClass *> GetMotifs ()
    {
      return Motifs ;
    } 
      
  private :

  vector<MotifClass *> Motifs ;
  unsigned long Start ;
  unsigned long End ;
  char Name ;
  char FileName [100] ;

} ;

#endif
