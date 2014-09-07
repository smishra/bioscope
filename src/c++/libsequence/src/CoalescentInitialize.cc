#include <Sequence/Coalescent/Initialize.hpp>
#include <numeric>
#include <cassert>

namespace Sequence
{
  std::vector<chromosome> init_sample( const std::vector<int> & pop_config,
				       const int & nsites )
  /*!
    @brief A simple function to initialize a sample of chromosomes.
    \param pop_config For a k-population model, this vector contains the 
    sample size for each pop.  Individuals are labeled as beloning to 
    population 0 to k-1, in the order specified in this vector
    \param nsites The number of sites at which mutations occur.  For a k-site model,
    recombination occurs at any of the k-1 "links" between sites.  Eaach chromosome
    is assigned a single segment starting at position 0 and ending at nsites-1.
    \ingroup coalescent
  */
  {
    assert (! pop_config.empty() );
    int nsam = std::accumulate(pop_config.begin(),pop_config.end(),0);
    std::vector<chromosome> sample(nsam);
    int k=0;
    for(unsigned i = 0 ; i < pop_config.size() ; ++i)
      {
	int popsize = pop_config[i];
	assert(popsize >= 0);
	for(int j=0;j<popsize;++j)
	  {
	    std::vector<segment> initial_segments(1,segment(0,(nsites>0 ? nsites-1 : 0),k));
	    sample[k++] = chromosome(initial_segments,i);
	  }
      }
    return sample;
  }
  
  marginal init_marginal( const int & nsam )
  /*!
    @brief Simple function to initialize a marginal tree
    \param nsam the total sample size (i.e. summed over all populations) that you want to simulate
    \ingroup coalescent
  */
  {
    std::vector<node> tree(2*nsam-1);
    for(int i=0;i<nsam;++i)
      {
	tree[i] = node(0.);
      }
    return marginal(0,nsam,nsam-1,tree);
  } 
}