#include "ClearDataMask.hpp"

#include "complex/DataStructure/DataPath.hpp"
#include "complex/Parameters/ArraySelectionParameter.hpp"

using namespace complex;

namespace complex
{
//------------------------------------------------------------------------------
std::string ClearDataMask::name() const
{
  return FilterTraits<ClearDataMask>::name.str();
}

//------------------------------------------------------------------------------
std::string ClearDataMask::className() const
{
  return FilterTraits<ClearDataMask>::className;
}

//------------------------------------------------------------------------------
Uuid ClearDataMask::uuid() const
{
  return FilterTraits<ClearDataMask>::uuid;
}

//------------------------------------------------------------------------------
std::string ClearDataMask::humanName() const
{
  return "Clear Data (Mask)";
}

//------------------------------------------------------------------------------
std::vector<std::string> ClearDataMask::defaultTags() const
{
  return {"#Processing", "#Cleanup"};
}

//------------------------------------------------------------------------------
Parameters ClearDataMask::parameters() const
{
  Parameters params;
  // Create the parameter descriptors that are needed for this filter
  params.insert(std::make_unique<ArraySelectionParameter>(k_MaskArrayPath_Key, "Mask", "", DataPath{}));

  return params;
}

//------------------------------------------------------------------------------
IFilter::UniquePointer ClearDataMask::clone() const
{
  return std::make_unique<ClearDataMask>();
}

//------------------------------------------------------------------------------
IFilter::PreflightResult ClearDataMask::preflightImpl(const DataStructure& ds, const Arguments& filterArgs, const MessageHandler& messageHandler) const
{
  /****************************************************************************
   * Write any preflight sanity checking codes in this function
   ***************************************************************************/

  /**
   * These are the values that were gathered from the UI or the pipeline file or
   * otherwise passed into the filter. These are here for your convenience. If you
   * do not need some of them remove them.
   */
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
  auto action = std::make_unique<ClearDataMaskAction>();
  actions.actions.push_back(std::move(action));
  // Assign the generated outputActions to the PreflightResult::OutputActions property
  preflightResult.outputActions = std::move(actions);
#endif

  return preflightResult;
}

//------------------------------------------------------------------------------
Result<> ClearDataMask::executeImpl(DataStructure& data, const Arguments& filterArgs, const PipelineFilter* pipelineNode, const MessageHandler& messageHandler) const
{
  /****************************************************************************
   * Extract the actual input values from the 'filterArgs' object
   ***************************************************************************/
  auto pMaskArrayPathValue = filterArgs.value<DataPath>(k_MaskArrayPath_Key);

  /****************************************************************************
   * Write your algorithm implementation in this function
   ***************************************************************************/

  return {};
}
} // namespace complex
