/*

Copyright (C) 2003-2009 Kevin Thornton, krthornt[]@[]uci.edu

Remove the brackets to email me.

This file is part of libsequence.

libsequence is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

libsequence is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
long with libsequence.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <cassert>
#include <Sequence/Grantham.hpp>
#include <Sequence/WeightingSchemes.hpp>
#include <Sequence/PathwayHelper.hpp>
#include <Sequence/RedundancyCom95.hpp>
#include <Sequence/SingleSub.hpp>
#include <Sequence/ThreeSubs.hpp>

using std::string;
//handle cases where codons are fully substituted
namespace Sequence
  {
  ThreeSubs::~ThreeSubs (void)
  /*!
    does nothing
  */
  {
  }

  void ThreeSubs::operator() (const RedundancyCom95 * sitesObj,
                              const std::string &codon1, const std::string &codon2,
                              const Sequence::WeightingScheme3 *weights3)
  /*!
    \param sitesObj an object of type Sequence::RedundancyCom95
    \param code see Sequence::GeneticCodes for valid values
    \param codon1 a std::string of length 3
    \param codon2 a std::string of length 3
    \param weights3 a weighting scheme for the pathways
    \note length of codons is checked by assert()
   */
  {
    assert(codon1.length() == 3 && codon2.length() == 3);
    string intermediates[9];
    Intermediates3(intermediates,codon1,codon2);
    p0 = p2S = p2V = p4 = q0 = q2S = q2V = q4 = 0.0;

    weights3->Calculate(codon1,codon2);
    double *weights = weights3->weights();
    Calculate (sitesObj, intermediates, codon1, codon2, weights[0],
               weights[1], weights[2], weights[3], weights[4], weights[5]);
  }

  void
  ThreeSubs::Calculate (const RedundancyCom95 * sitesObj,
                        const std::string *intermediates,
                        const std::string & codon1, const std::string & codon2,
                        double w_path1, double w_path2, double w_path3,
                        double w_path4, double w_path5, double w_path6)
  /*!
    calculate number of changes along each pathway
  */
  {
    //arrays to store transition / transversion values per branch
    double p0_b[15], p2S_b[15], p2V_b[15], p4_b[15];
    double q0_b[15], q2S_b[15], q2V_b[15], q4_b[15];

    //initialuze the SingleSub class for the first path
    SingleSub Single;
    //there are 15 branches to iterate over--you'll need to draw a picture...
    //there is a picture in the documentation
    for (int i = 0; i <= 14; ++i)
      {
        switch (i)
          {
          case 0:
            //already initialized above
            // *Single =  SingleSub (sitesObj, codon1,intermediates[0]);
            Single(sitesObj, codon1,intermediates[0]);
            break;
          case 1:
            Single (sitesObj, intermediates[0],
                    intermediates[1]);
            break;
          case 2:
            Single (sitesObj, intermediates[1],
                    codon2);
            break;
          case 3:
            Single (sitesObj, intermediates[0],
                    intermediates[2]);
            break;
          case 4:
            Single (sitesObj, intermediates[2],
                    codon2);
            break;
          case 5:
            Single (sitesObj, codon1,
                    intermediates[3]);
            break;
          case 6:
            Single (sitesObj, intermediates[3],
                    intermediates[4]);
            break;
          case 7:
            Single (sitesObj, intermediates[4],
                    codon2);
            break;
          case 8:
            Single (sitesObj, intermediates[3],
                    intermediates[5]);
            break;
          case 9:
            Single (sitesObj, intermediates[5],
                    codon2);
            break;
          case 10:
            Single (sitesObj, codon1,
                    intermediates[6]);
            break;
          case 11:
            Single (sitesObj, intermediates[6],
                    intermediates[7]);
            break;
          case 12:
            Single (sitesObj, intermediates[7],
                    codon2);
            break;
          case 13:
            Single (sitesObj, intermediates[6],
                    intermediates[8]);
            break;
          case 14:
            Single (sitesObj, intermediates[8],
                    codon2);
            break;
          }
        p0_b[i] = Single.P0();
        p2S_b[i] =Single.P2S();
        p2V_b[i] =Single.P2V();
        p4_b[i] = Single.P4();
        q0_b[i] = Single.Q0();
        q2S_b[i] =Single.Q2S();
        q2V_b[i] =Single.Q2V();
        q4_b[i] = Single.Q4();
      }
    //sum up changes along each branch, weighting by the
    //weight factor for each path
    p0 = (p0_b[0] + p0_b[1] + p0_b[2]) * w_path1
         + (p0_b[0] + p0_b[3] +  p0_b[4]) * w_path2
         + (p0_b[5] + p0_b[6] + p0_b[7]) * w_path3
         + (p0_b[5] + p0_b[8] + p0_b[9]) * w_path4
         + (p0_b[10] + p0_b[11] + p0_b[12]) * w_path5
         + (p0_b[10] + p0_b[13] + p0_b[14]) * w_path6;

    p2S = (p2S_b[0] + p2S_b[1] + p2S_b[2]) * w_path1
          + (p2S_b[0] + p2S_b[3] + p2S_b[4]) * w_path2
          + (p2S_b[5] + p2S_b[6] + p2S_b[7]) * w_path3
          + (p2S_b[5] + p2S_b[8] + p2S_b[9]) * w_path4
          + (p2S_b[10] + p2S_b[11] + p2S_b[12]) * w_path5
          + (p2S_b[10] + p2S_b[13] + p2S_b[14]) * w_path6;

    p2V = (p2V_b[0] + p2V_b[1] + p2V_b[2]) * w_path1
          + (p2V_b[0] + p2V_b[3] + p2V_b[4]) *   w_path2
          + (p2V_b[5] + p2V_b[6] + p2V_b[7]) * w_path3
          + (p2V_b[5] + p2V_b[8] + p2V_b[9]) * w_path4
          + (p2V_b[10] + p2V_b[11] + p2V_b[12]) * w_path5
          + (p2V_b[10] + p2V_b[13] + p2V_b[14]) * w_path6;

    p4 = (p4_b[0] + p4_b[1] + p4_b[2]) * w_path1
         + (p4_b[0] + p4_b[3] +  p4_b[4]) * w_path2
         + (p4_b[5] + p4_b[6] + p4_b[7]) * w_path3
         + (p4_b[5] + p4_b[8] +  p4_b[9]) * w_path4
         + (p4_b[10] + p4_b[11] + p4_b[12]) * w_path5
         + (p4_b[10] + p4_b[13] + p4_b[14]) * w_path6;

    q0 = (q0_b[0] + q0_b[1] + q0_b[2]) * w_path1
         + (q0_b[0] + q0_b[3] +  q0_b[4]) * w_path2
         + (q0_b[5] + q0_b[6] + q0_b[7]) * w_path3
         + (q0_b[5] + q0_b[8] + q0_b[9]) *  w_path4
         + (q0_b[10] + q0_b[11] + q0_b[12]) * w_path5
         +  (q0_b[10] + q0_b[13] + q0_b[14]) * w_path6;

    q2S = (q2S_b[0] + q2S_b[1] + q2S_b[2]) * w_path1
          + (q2S_b[0] + q2S_b[3] + q2S_b[4]) *   w_path2
          + (q2S_b[5] + q2S_b[6] + q2S_b[7]) * w_path3
          + (q2S_b[5] + q2S_b[8] + q2S_b[9]) * w_path4
          + (q2S_b[10] +q2S_b[11] + q2S_b[12]) * w_path5
          + (q2S_b[10] + q2S_b[13] + q2S_b[14]) * w_path6;

    q2V = (q2V_b[0] + q2V_b[1] + q2V_b[2]) * w_path1
          + (q2V_b[0] + q2V_b[3] +	q2V_b[4]) *  w_path2
          + (q2V_b[5] + q2V_b[6] + q2V_b[7]) * w_path3
          + (q2V_b[5] + q2V_b[8] + q2V_b[9]) * w_path4
          + (q2V_b[10] +  q2V_b[11] + q2V_b[12]) * w_path5
          + (q2V_b[10] + q2V_b[13] + q2V_b[14]) * w_path6;

    q4 = (q4_b[0] + q4_b[1] + q4_b[2]) * w_path1
         + (q4_b[0] + q4_b[3] +  q4_b[4]) * w_path2
         + (q4_b[5] + q4_b[6] + q4_b[7]) * w_path3
         + (q4_b[5] + q4_b[8] + q4_b[9]) *  w_path4
         + (q4_b[10] + q4_b[11] + q4_b[12]) * w_path5
         +  (q4_b[10] + q4_b[13] + q4_b[14]) * w_path6;
  }

}

