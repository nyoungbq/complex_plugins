#include "ITKHistogramMatchingImage.hpp"

#include "complex/DataStructure/DataPath.hpp"
#include "complex/Filter/Actions/EmptyAction.hpp"
#include "complex/Parameters/ArraySelectionParameter.hpp"
#include "complex/Parameters/BoolParameter.hpp"
#include "complex/Parameters/NumberParameter.hpp"

#include "ITKImageProcessing/Common/ITKArrayHelper.hpp"

using namespace complex;

#include <itkHistogramMatchingImageFilter.h>
namespace
{
struct ITKHistogramMatchingImageFilterCreationFunctor
{
  float64 m_NumberOfHistogramLevels;
  float64 m_NumberOfMatchPoints;
  bool m_ThresholdAtMeanIntensity;
  DataPath m_SelectedCellArrayPath;
  DataPath m_ReferenceCellArrayPath;

  template <class InputImageType, class OutputImageType>
  auto operator()() const
  {
    using FilterType = itk::HistogramMatchingImageFilter<InputImageType, OutputImageType>;
    typename FilterType::Pointer filter = FilterType::New();
    filter->SetNumberOfHistogramLevels(m_NumberOfHistogramLevels);
    filter->SetNumberOfMatchPoints(m_NumberOfMatchPoints);
    filter->SetThresholdAtMeanIntensity(m_ThresholdAtMeanIntensity);
    filter->SetSelectedCellArrayPath(m_SelectedCellArrayPath);
    filter->SetReferenceCellArrayPath(m_ReferenceCellArrayPath);
    return filter;
  }
};
} // namespace

namespace complex
{
//------------------------------------------------------------------------------
std::string ITKHistogramMatchingImage::name() const
{
  return FilterTraits<ITKHistogramMatchingImage>::name.str();
}

//------------------------------------------------------------------------------
std::string ITKHistogramMatchingImage::className() const
{
  return FilterTraits<ITKHistogramMatchingImage>::className;
}

//------------------------------------------------------------------------------
Uuid ITKHistogramMatchingImage::uuid() const
{
  return FilterTraits<ITKHistogramMatchingImage>::uuid;
}

//------------------------------------------------------------------------------
std::string ITKHistogramMatchingImage::humanName() const
{
  return "ITK::Histogram Matching Image Filter";
}

//------------------------------------------------------------------------------
std::vector<std::string> ITKHistogramMatchingImage::defaultTags() const
{
  return {"#ITK Image Processing", "#ITK IntensityTransformation"};
}

//------------------------------------------------------------------------------
Parameters ITKHistogramMatchingImage::parameters() const
{
  Parameters params;
  // Create the parameter descriptors that are needed for this filter
  params.insert(std::make_unique<Float64Parameter>(k_NumberOfHistogramLevels_Key, "NumberOfHistogramLevels", "", 2.3456789));
  params.insert(std::make_unique<Float64Parameter>(k_NumberOfMatchPoints_Key, "NumberOfMatchPoints", "", 2.3456789));
  params.insert(std::make_unique<BoolParameter>(k_ThresholdAtMeanIntensity_Key, "ThresholdAtMeanIntensity", "", false));
  params.insert(std::make_unique<ArraySelectionParameter>(k_SelectedCellArrayPath_Key, "Input Attribute Array to filter", "", DataPath{}));
  params.insert(std::make_unique<ArraySelectionParameter>(k_ReferenceCellArrayPath_Key, "Reference Attribute Array to filter", "", DataPath{}));
  params.insert(std::make_unique<ArrayCreationParameter>(k_NewCellArrayName_Key, "Filtered Array", "", DataPath{}));

  return params;
}

//------------------------------------------------------------------------------
IFilter::UniquePointer ITKHistogramMatchingImage::clone() const
{
  return std::make_unique<ITKHistogramMatchingImage>();
}

//------------------------------------------------------------------------------
IFilter::PreflightResult ITKHistogramMatchingImage::preflightImpl(const DataStructure& dataStructure, const Arguments& filterArgs, const MessageHandler& messageHandler) const
{
  /****************************************************************************
   * Write any preflight sanity checking codes in this function
   ***************************************************************************/

  /**
   * These are the values that were gathered from the UI or the pipeline file or
   * otherwise passed into the filter. These are here for your convenience. If you
   * do not need some of them remove them.
   */
  auto pNumberOfHistogramLevels = filterArgs.value<float64>(k_NumberOfHistogramLevels_Key);
  auto pNumberOfMatchPoints = filterArgs.value<float64>(k_NumberOfMatchPoints_Key);
  auto pThresholdAtMeanIntensity = filterArgs.value<bool>(k_ThresholdAtMeanIntensity_Key);
  auto pSelectedCellArrayPath = filterArgs.value<DataPath>(k_SelectedCellArrayPath_Key);
  auto pReferenceCellArrayPath = filterArgs.value<DataPath>(k_ReferenceCellArrayPath_Key);
  auto pOutputArrayPath = filterArgs.value<DataPath>(k_NewCellArrayName_Key);

  // Declare the preflightResult variable that will be populated with the results
  // of the preflight. The PreflightResult type contains the output Actions and
  // any preflight updated values that you want to be displayed to the user, typically
  // through a user interface (UI).
  PreflightResult preflightResult;
  // If your filter is going to pass back some `preflight updated values` then this is where you
  // would create the code to store those values in the appropriate object. Note that we
  // in line creating the pair (NOT a std::pair<>) of Key:Value that will get stored in
  // the std::vector<PreflightValue> object.
  std::vector<PreflightValue> preflightUpdatedValues;

  // If your filter is making structural changes to the DataStructure then the filter
  // is going to create OutputActions subclasses that need to be returned. This will
  // store those actions.
  complex::Result<OutputActions> resultOutputActions;

  resultOutputActions = ITK::DataCheck(dataStructure, pSelectedCellArrayPath, pImageGeomPath, pOutputArrayPath);

  // If the filter needs to pass back some updated values via a key:value string:string set of values
  // you can declare and update that string here.
  // None found in this filter based on the filter parameters

  // If this filter makes changes to the DataStructure in the form of
  // creating/deleting/moving/renaming DataGroups, Geometries, DataArrays then you
  // will need to use one of the `*Actions` classes located in complex/Filter/Actions
  // to relay that information to the preflight and execute methods. This is done by
  // creating an instance of the Action class and then storing it in the resultOutputActions variable.
  // This is done through a `push_back()` method combined with a `std::move()`. For the
  // newly initiated to `std::move` once that code is executed what was once inside the Action class
  // instance variable is *no longer there*. The memory has been moved. If you try to access that
  // variable after this line you will probably get a crash or have subtle bugs. To ensure that this
  // does not happen we suggest using braces `{}` to scope each of the action's declaration and store
  // so that the programmer is not tempted to use the action instance past where it should be used.
  // You have to create your own Actions class if there isn't something specific for your filter's needs

  // Store the preflight updated value(s) into the preflightUpdatedValues vector using
  // the appropriate methods.
  // None found based on the filter parameters

  // Return both the resultOutputActions and the preflightUpdatedValues via std::move()
  return {std::move(resultOutputActions), std::move(preflightUpdatedValues)};
}

//------------------------------------------------------------------------------
Result<> ITKHistogramMatchingImage::executeImpl(DataStructure& dataStructure, const Arguments& filterArgs, const PipelineFilter* pipelineNode, const MessageHandler& messageHandler) const
{
  /****************************************************************************
   * Extract the actual input values from the 'filterArgs' object
   ***************************************************************************/
  auto pNumberOfHistogramLevels = filterArgs.value<float64>(k_NumberOfHistogramLevels_Key);
  auto pNumberOfMatchPoints = filterArgs.value<float64>(k_NumberOfMatchPoints_Key);
  auto pThresholdAtMeanIntensity = filterArgs.value<bool>(k_ThresholdAtMeanIntensity_Key);
  auto pSelectedCellArrayPath = filterArgs.value<DataPath>(k_SelectedCellArrayPath_Key);
  auto pReferenceCellArrayPath = filterArgs.value<DataPath>(k_ReferenceCellArrayPath_Key);
  auto pOutputArrayPath = filterArgs.value<DataPath>(k_NewCellArrayName_Key);

  /****************************************************************************
   * Write your algorithm implementation in this function
   ***************************************************************************/
  ::ITKHistogramMatchingImageFilterCreationFunctor itkFunctor;
  itkFunctor.m_NumberOfHistogramLevels = pNumberOfHistogramLevels;
  itkFunctor.m_NumberOfMatchPoints = pNumberOfMatchPoints;
  itkFunctor.m_ThresholdAtMeanIntensity = pThresholdAtMeanIntensity;
  itkFunctor.m_SelectedCellArrayPath = pSelectedCellArrayPath;
  itkFunctor.m_ReferenceCellArrayPath = pReferenceCellArrayPath;

  return ITK::Execute(dataStructure, pSelectedCellArrayPath, pImageGeomPath, pOutputArrayPath, itkFunctor);
}
} // namespace complex
