#include "NormalizeArrays.hpp"

#include "complex/DataStructure/DataPath.hpp"
#include "complex/Parameters/ArraySelectionParameter.hpp"
#include "complex/Parameters/BoolParameter.hpp"
#include "complex/Parameters/ChoicesParameter.hpp"
#include "complex/Parameters/MultiArraySelectionParameter.hpp"
#include "complex/Parameters/NumberParameter.hpp"
#include "complex/Parameters/StringParameter.hpp"

using namespace complex;

namespace complex
{
//------------------------------------------------------------------------------
std::string NormalizeArrays::name() const
{
  return FilterTraits<NormalizeArrays>::name.str();
}

//------------------------------------------------------------------------------
std::string NormalizeArrays::className() const
{
  return FilterTraits<NormalizeArrays>::className;
}

//------------------------------------------------------------------------------
Uuid NormalizeArrays::uuid() const
{
  return FilterTraits<NormalizeArrays>::uuid;
}

//------------------------------------------------------------------------------
std::string NormalizeArrays::humanName() const
{
  return "Normalize Attribute Arrays";
}

//------------------------------------------------------------------------------
std::vector<std::string> NormalizeArrays::defaultTags() const
{
  return {"#DREAM3D Review", "#Statistics"};
}

//------------------------------------------------------------------------------
Parameters NormalizeArrays::parameters() const
{
  Parameters params;
  // Create the parameter descriptors that are needed for this filter
  params.insertLinkableParameter(std::make_unique<ChoicesParameter>(k_NormalizeType_Key, "Operation Type", "", 0, ChoicesParameter::Choices{"Rescale to Range", "Standardize"}));
  params.insert(std::make_unique<StringParameter>(k_Postfix_Key, "Postfix", "", "SomeString"));
  params.insertLinkableParameter(std::make_unique<BoolParameter>(k_UseMask_Key, "Use Mask", "", false));
  params.insert(std::make_unique<Float64Parameter>(k_DefaultValue_Key, "Default Masked Value", "", 2.3456789));
  params.insert(std::make_unique<Float64Parameter>(k_RangeMin_Key, "Range Minimum", "", 2.3456789));
  params.insert(std::make_unique<Float64Parameter>(k_RangeMax_Key, "Range Maximum", "", 2.3456789));
  params.insert(
      std::make_unique<MultiArraySelectionParameter>(k_SelectedDataArrayPaths_Key, "Attribute Arrays to Normalize", "", MultiArraySelectionParameter::ValueType{DataPath(), DataPath(), DataPath()}));
  params.insert(std::make_unique<ArraySelectionParameter>(k_MaskArrayPath_Key, "Mask", "", DataPath{}));
  // Associate the Linkable Parameter(s) to the children parameters that they control
  params.linkParameters(k_NormalizeType_Key, k_RangeMin_Key, 0);
  params.linkParameters(k_NormalizeType_Key, k_RangeMax_Key, 0);
  params.linkParameters(k_UseMask_Key, k_MaskArrayPath_Key, true);
  params.linkParameters(k_UseMask_Key, k_DefaultValue_Key, true);

  return params;
}

//------------------------------------------------------------------------------
IFilter::UniquePointer NormalizeArrays::clone() const
{
  return std::make_unique<NormalizeArrays>();
}

//------------------------------------------------------------------------------
IFilter::PreflightResult NormalizeArrays::preflightImpl(const DataStructure& ds, const Arguments& filterArgs, const MessageHandler& messageHandler) const
{
  /****************************************************************************
   * Write any preflight sanity checking codes in this function
   ***************************************************************************/

  /**
   * These are the values that were gathered from the UI or the pipeline file or
   * otherwise passed into the filter. These are here for your convenience. If you
   * do not need some of them remove them.
   */
  auto pNormalizeTypeValue = filterArgs.value<ChoicesParameter::ValueType>(k_NormalizeType_Key);
  auto pPostfixValue = filterArgs.value<StringParameter::ValueType>(k_Postfix_Key);
  auto pUseMaskValue = filterArgs.value<bool>(k_UseMask_Key);
  auto pDefaultValueValue = filterArgs.value<float64>(k_DefaultValue_Key);
  auto pRangeMinValue = filterArgs.value<float64>(k_RangeMin_Key);
  auto pRangeMaxValue = filterArgs.value<float64>(k_RangeMax_Key);
  auto pSelectedDataArrayPathsValue = filterArgs.value<MultiArraySelectionParameter::ValueType>(k_SelectedDataArrayPaths_Key);
  auto pMaskArrayPathValue = filterArgs.value<DataPath>(k_MaskArrayPath_Key);

  // Declare the preflightResult variable that will be populated with the results
  // of the preflight. The PreflightResult type contains the output Actions and
  // any preflight updated values that you want to be displayed to the user, typically
  // through a user interface (UI).
  PreflightResult preflightResult;

#if 0
  // Define the OutputActions Object that will hold the actions that would take
  // place if the filter were to execute. This is mainly what would happen to the
  // DataStructure during this filter, i.e., what modificationst to the DataStructure
  // would take place.
  OutputActions actions;
  // Define a custom class that generates the changes to the DataStructure.
  auto action = std::make_unique<NormalizeArraysAction>();
  actions.actions.push_back(std::move(action));
  // Assign the generated outputActions to the PreflightResult::OutputActions property
  preflightResult.outputActions = std::move(actions);
#endif

  return preflightResult;
}

//------------------------------------------------------------------------------
Result<> NormalizeArrays::executeImpl(DataStructure& data, const Arguments& filterArgs, const PipelineFilter* pipelineNode, const MessageHandler& messageHandler) const
{
  /****************************************************************************
   * Extract the actual input values from the 'filterArgs' object
   ***************************************************************************/
  auto pNormalizeTypeValue = filterArgs.value<ChoicesParameter::ValueType>(k_NormalizeType_Key);
  auto pPostfixValue = filterArgs.value<StringParameter::ValueType>(k_Postfix_Key);
  auto pUseMaskValue = filterArgs.value<bool>(k_UseMask_Key);
  auto pDefaultValueValue = filterArgs.value<float64>(k_DefaultValue_Key);
  auto pRangeMinValue = filterArgs.value<float64>(k_RangeMin_Key);
  auto pRangeMaxValue = filterArgs.value<float64>(k_RangeMax_Key);
  auto pSelectedDataArrayPathsValue = filterArgs.value<MultiArraySelectionParameter::ValueType>(k_SelectedDataArrayPaths_Key);
  auto pMaskArrayPathValue = filterArgs.value<DataPath>(k_MaskArrayPath_Key);

  /****************************************************************************
   * Write your algorithm implementation in this function
   ***************************************************************************/

  return {};
}
} // namespace complex
