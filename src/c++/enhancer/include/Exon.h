#ifndef EXON_H
#define EXON_H

#include <string>
#include <vector>
#include <map>

#include <EnhancerDefines.h>
#include <Annotation.h>

using namespace std ;

typedef map <string, vector <Annotation *> > GENEEXONS ;

class Exon {

  public : 
  Exon () {} ;

  void InsertExon (char *genename, Annotation *Anot)
    {

      vector <Annotation *> temp ;

      GENEEXONS::iterator Ge = GeneExonList.find (genename) ;
      if (Ge == GeneExonList.end()) 
	{
	  GeneExonList.insert (make_pair(genename, temp)) ;
	}
      Ge = GeneExonList.find (genename) ;
      (*Ge).second.push_back(Anot) ;
      return ; 
    }

  vector <Annotation *> & GetExonList (char *genename)
    {
      GENEEXONS::iterator Ge = GeneExonList.find (genename) ;
      if (Ge != GeneExonList.end())
	return (*Ge).second ;
      //      else
      //	return  (vector <Annotation *>) NULL ;
    }

  private :
    
    GENEEXONS GeneExonList ;

} ;

#endif