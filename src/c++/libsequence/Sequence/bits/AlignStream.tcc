// Code for the -*- C++ -*- namespace Sequence::AlignStream<T>

/*! \file AlignStream.tcc
  @brief implementation of AlignStream.hpp
*/

#include <Sequence/AlignStream.hpp>

namespace Sequence
{
  template<typename T>
  AlignStream<T>::AlignStream(const std::vector<T> & _data)
  {
    data.assign(_data.begin(),_data.end());
  }

  template<typename T>
  AlignStream<T>::~AlignStream(void)
  {}
  
  template<typename T>
  void AlignStream<T>::assign ( const_iterator beg,
				const_iterator end ) throw (Sequence::SeqException)
  /*!
    store the data
  */
  {
    data.assign(beg,end);
    unsigned len = beg->second.length();
    for (typename AlignStream<T>::const_iterator itr = beg+1 ; 
	 itr != end ; 
	 ++itr)
      {
	if (itr->second.length() != len)
	  {
	    throw (SeqException("AlignStream::assign -- data elements have different lengths"));
	  }
      }
  }
  
  template<typename T> 
  typename AlignStream<T>::iterator AlignStream<T>::begin()
  {
    return data.begin();
  }

  template<typename T> 
  typename AlignStream<T>::iterator AlignStream<T>::end()
  {
    return data.end();
  }

  template<typename T> 
  typename AlignStream<T>::const_iterator AlignStream<T>::begin() const
  {
    return data.begin();
  }

  template<typename T> 
  typename AlignStream<T>::const_iterator AlignStream<T>::end() const
  {
    return data.end();
  }

  template < typename T >
  bool AlignStream < T >::IsAlignment (void)
  /*!
    Implemented by a call to Alignment::IsAlignment
  */
  {
    return Alignment::IsAlignment (data);
  }

  template < typename T >
  bool AlignStream < T >::Gapped (void)
  /*!
    Implemented by a call to Alignment::Gapped
  */
  {
    return Alignment::Gapped (data);
  }

  template < typename T >
  unsigned AlignStream < T >::UnGappedLength (void)
  /*!
    Implemented by a call to Alignment::UnGappedLength
  */
  {
    return Alignment::UnGappedLength (data);
  }

  template < typename T >
  void AlignStream < T >::RemoveGaps (void)
  /*!
    Implemented by a call to Alignment::RemoveGaps
  */
  {
    Alignment::RemoveGaps (data);
  }

  template < typename T >
  void AlignStream < T >::RemoveTerminalGaps (void)
  /*!
    Implemented by a call to Alignment::RemoveTerminalGaps
  */
  {
    Alignment::RemoveTerminalGaps (data);
  }

  template < typename T >
  std::vector < T >AlignStream < T >::Trim ( std::vector <int >sites)
    throw (Sequence::SeqException)
  /*!
    Implemented by a call to Alignment::Trim
  */
  {
    return Alignment::Trim (data, sites);
  }

  template < typename T >
  std::vector < T > AlignStream < T >::TrimComplement
  (std::vector <int>sites) throw (Sequence::SeqException)
  /*!
    Implemented by a call to Alignment::TrimComplement
  */
  {
    return Alignment::TrimComplement (data, sites);
  }

  template <typename T >
  const std::vector < T> AlignStream< T >::Data(void)
  /*!
    Returns the std::vector < T* > data
  */
  {
    return data;
  }

}

