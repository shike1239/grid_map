/*
 * MinFilter.hpp
 *
 *  Created on: Mar 18, 2015
 *      Author: Martin Wermelinger, Peter Fankhauser
 *   Institute: ETH Zurich, Autonomous Systems Lab
 */

#pragma once

#include <filters/filter_base.h>

#include <vector>
#include <string>

namespace grid_map {

/*!
 * Minimum filter class takes the minimum out of different layers of a grid map.
 */
template<typename T>
class MinFilter : public filters::FilterBase<T>
{

 public:
  /*!
   * Constructor
   */
  MinFilter();

  /*!
   * Destructor.
   */
  virtual ~MinFilter();

  /*!
   * Configures the filter from parameters on the parameter server.
   */
  virtual bool configure();

  /*!
   * Takes the minimum out of different layers of a grid map.
   * @param mapIn gridMap with the different layers to take the min.
   * @param mapOut gridMap with an additional layer containing the sum.
   */
  virtual bool update(const T& mapIn, T& mapOut);

 private:

  //! List of layers that are added together.
  std::vector<std::string> layers_;

  //! Output layer name.
  std::string outputLayer_;

};

} /* namespace */
