#include "RenameDataContainer.hpp"

#include "complex/DataStructure/DataPath.hpp"
#include "complex/Parameters/DataGroupCreationParameter.hpp"
#include "complex/Parameters/DataGroupSelectionParameter.hpp"

using namespace complex;

namespace complex
{
//------------------------------------------------------------------------------
std::string RenameDataContainer::name() const
{
  return FilterTraits<RenameDataContainer>::name.str();
}

//------------------------------------------------------------------------------
std::string RenameDataContainer::className() const
{
  return FilterTraits<RenameDataContainer>::className;
}

//------------------------------------------------------------------------------
Uuid RenameDataContainer::uuid() const
{
  return FilterTraits<RenameDataContainer>::uuid;
}

//------------------------------------------------------------------------------
std::string RenameDataContainer::humanName() const
{
  return "Rename Data Container";
}

//------------------------------------------------------------------------------
std::vector<std::string> RenameDataContainer::defaultTags() const
{
  return {"#Core", "#Memory Management"};
}

//------------------------------------------------------------------------------
Parameters RenameDataContainer::parameters() const
{
  Parameters params;
  // Create the parameter descriptors that are needed for this filter
  params.insert(std::make_unique<DataGroupSelectionParameter>(k_SelectedDataContainerName_Key, "Data Container to Rename", "", DataPath{}));
  params.insert(std::make_unique<DataGroupCreationParameter>(k_NewDataContainerName_Key, "New Data Container Name", "", DataPath{}));

  return params;
}

//------------------------------------------------------------------------------
IFilter::UniquePointer RenameDataContainer::clone() const
{
  return std::make_unique<RenameDataContainer>();
}

//------------------------------------------------------------------------------
IFilter::PreflightResult RenameDataContainer::preflightImpl(const DataStructure& ds, const Arguments& filterArgs, const MessageHandler& messageHandler) const
{
  /****************************************************************************
   * Write any preflight sanity checking codes in this function
   ***************************************************************************/

  /**
   * These are the values that were gathered from the UI or the pipeline file or
   * otherwise passed into the filter. These are here for your convenience. If you
   * do not need some of them remove them.
   */
  auto pSelectedDataContainerNameValue = filterArgs.value<DataPath>(k_SelectedDataContainerName_Key);
  auto pNewDataContainerNameValue = filterArgs.value<DataPath>(k_NewDataContainerName_Key);

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
  auto action = std::make_unique<RenameDataContainerAction>();
  actions.actions.push_back(std::move(action));
  // Assign the generated outputActions to the PreflightResult::OutputActions property
  preflightResult.outputActions = std::move(actions);
#endif

  return preflightResult;
}

//------------------------------------------------------------------------------
Result<> RenameDataContainer::executeImpl(DataStructure& data, const Arguments& filterArgs, const PipelineFilter* pipelineNode, const MessageHandler& messageHandler) const
{
  /****************************************************************************
   * Extract the actual input values from the 'filterArgs' object
   ***************************************************************************/
  auto pSelectedDataContainerNameValue = filterArgs.value<DataPath>(k_SelectedDataContainerName_Key);
  auto pNewDataContainerNameValue = filterArgs.value<DataPath>(k_NewDataContainerName_Key);

  /****************************************************************************
   * Write your algorithm implementation in this function
   ***************************************************************************/

  return {};
}
} // namespace complex
