#ifndef __FST_H__
#define __FST_H__
#include <utility>
#include <set>
#include <memory>
#include <Sequence/stateCounter.hpp>
#include <Sequence/SeqExceptions.hpp>
#include <boost/utility.hpp>
/*! \file FST.hpp
  @brief delcaration of a class (Sequence::FST) to analyze population structure
*/
namespace Sequence
{
  class PolyTable;
  class FSTimpl;
  class FST : boost::noncopyable
  {
  private:
    void doCalcs(void) const;
    mutable std::auto_ptr<FSTimpl> impl;
  public:
    explicit FST(const PolyTable *data, unsigned npop, const unsigned *config=NULL,
		 const double *weights=NULL, bool haveOutgroup = false,
		 unsigned outgroup = 0) throw (SeqException);
    ~FST(void);
    double HSM(void) const;
    double Slatkin(void) const;
    double HBK(void) const;
    double piB(void) const;
    double piT(void) const;
    double piS(void) const;
    double piD(void) const;
    std::set<double> shared(unsigned pop1, unsigned pop2) const;
    std::set<double> fixed(unsigned pop1, unsigned pop2) const;
    std::pair< std::set<double>,std::set<double> > Private(unsigned pop1, unsigned pop2) const;
  };
}
#endif