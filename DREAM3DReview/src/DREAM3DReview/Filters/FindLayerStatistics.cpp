#include "FindLayerStatistics.hpp"

#include "complex/DataStructure/DataPath.hpp"
#include "complex/Parameters/ArrayCreationParameter.hpp"
#include "complex/Parameters/ArraySelectionParameter.hpp"
#include "complex/Parameters/ChoicesParameter.hpp"

using namespace complex;

namespace complex
{
//------------------------------------------------------------------------------
std::string FindLayerStatistics::name() const
{
  return FilterTraits<FindLayerStatistics>::name.str();
}

//------------------------------------------------------------------------------
std::string FindLayerStatistics::className() const
{
  return FilterTraits<FindLayerStatistics>::className;
}

//------------------------------------------------------------------------------
Uuid FindLayerStatistics::uuid() const
{
  return FilterTraits<FindLayerStatistics>::uuid;
}

//------------------------------------------------------------------------------
std::string FindLayerStatistics::humanName() const
{
  return "Find Layer Statistics";
}

//------------------------------------------------------------------------------
std::vector<std::string> FindLayerStatistics::defaultTags() const
{
  return {"#Statistics", "#Image"};
}

//------------------------------------------------------------------------------
Parameters FindLayerStatistics::parameters() const
{
  Parameters params;
  // Create the parameter descriptors that are needed for this filter
  params.insert(std::make_unique<ChoicesParameter>(k_Plane_Key, "Layer of Interest", "", 0, ChoicesParameter::Choices{"Option 1", "Option 2", "Option 3"}));
  params.insertSeparator(Parameters::Separator{"Cell Data"});
  params.insert(std::make_unique<ArraySelectionParameter>(k_SelectedArrayPath_Key, "Attribute Array to Quantify", "", DataPath{}));
  params.insert(std::make_unique<ArrayCreationParameter>(k_LayerAttributeMatrixName_Key, "Layer Attribute Matrix", "", DataPath{}));
  params.insertSeparator(Parameters::Separator{"Cell Data"});
  params.insert(std::make_unique<ArrayCreationParameter>(k_LayerIDsArrayName_Key, "Layer IDs", "", DataPath{}));
  params.insertSeparator(Parameters::Separator{"Feature Data"});
  params.insert(std::make_unique<ArrayCreationParameter>(k_LayerMinArrayName_Key, "Layer Min", "", DataPath{}));
  params.insert(std::make_unique<ArrayCreationParameter>(k_LayerMaxArrayName_Key, "Layer Max", "", DataPath{}));
  params.insert(std::make_unique<ArrayCreationParameter>(k_LayerAvgArrayName_Key, "Layer Avg", "", DataPath{}));
  params.insert(std::make_unique<ArrayCreationParameter>(k_LayerStdArrayName_Key, "Layer Std", "", DataPath{}));
  params.insert(std::make_unique<ArrayCreationParameter>(k_LayerVarArrayName_Key, "Layer Var", "", DataPath{}));

  return params;
}

//------------------------------------------------------------------------------
IFilter::UniquePointer FindLayerStatistics::clone() const
{
  return std::make_unique<FindLayerStatistics>();
}

//------------------------------------------------------------------------------
IFilter::PreflightResult FindLayerStatistics::preflightImpl(const DataStructure& ds, const Arguments& filterArgs, const MessageHandler& messageHandler) const
{
  /****************************************************************************
   * Write any preflight sanity checking codes in this function
   ***************************************************************************/

  /**
   * These are the values that were gathered from the UI or the pipeline file or
   * otherwise passed into the filter. These are here for your convenience. If you
   * do not need some of them remove them.
   */
  auto pPlaneValue = filterArgs.value<ChoicesParameter::ValueType>(k_Plane_Key);
  auto pSelectedArrayPathValue = filterArgs.value<DataPath>(k_SelectedArrayPath_Key);
  auto pLayerAttributeMatrixNameValue = filterArgs.value<DataPath>(k_LayerAttributeMatrixName_Key);
  auto pLayerIDsArrayNameValue = filterArgs.value<DataPath>(k_LayerIDsArrayName_Key);
  auto pLayerMinArrayNameValue = filterArgs.value<DataPath>(k_LayerMinArrayName_Key);
  auto pLayerMaxArrayNameValue = filterArgs.value<DataPath>(k_LayerMaxArrayName_Key);
  auto pLayerAvgArrayNameValue = filterArgs.value<DataPath>(k_LayerAvgArrayName_Key);
  auto pLayerStdArrayNameValue = filterArgs.value<DataPath>(k_LayerStdArrayName_Key);
  auto pLayerVarArrayNameValue = filterArgs.value<DataPath>(k_LayerVarArrayName_Key);

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
  auto action = std::make_unique<FindLayerStatisticsAction>();
  actions.actions.push_back(std::move(action));
  // Assign the generated outputActions to the PreflightResult::OutputActions property
  preflightResult.outputActions = std::move(actions);
#endif

  return preflightResult;
}

//------------------------------------------------------------------------------
Result<> FindLayerStatistics::executeImpl(DataStructure& data, const Arguments& filterArgs, const PipelineFilter* pipelineNode, const MessageHandler& messageHandler) const
{
  /****************************************************************************
   * Extract the actual input values from the 'filterArgs' object
   ***************************************************************************/
  auto pPlaneValue = filterArgs.value<ChoicesParameter::ValueType>(k_Plane_Key);
  auto pSelectedArrayPathValue = filterArgs.value<DataPath>(k_SelectedArrayPath_Key);
  auto pLayerAttributeMatrixNameValue = filterArgs.value<DataPath>(k_LayerAttributeMatrixName_Key);
  auto pLayerIDsArrayNameValue = filterArgs.value<DataPath>(k_LayerIDsArrayName_Key);
  auto pLayerMinArrayNameValue = filterArgs.value<DataPath>(k_LayerMinArrayName_Key);
  auto pLayerMaxArrayNameValue = filterArgs.value<DataPath>(k_LayerMaxArrayName_Key);
  auto pLayerAvgArrayNameValue = filterArgs.value<DataPath>(k_LayerAvgArrayName_Key);
  auto pLayerStdArrayNameValue = filterArgs.value<DataPath>(k_LayerStdArrayName_Key);
  auto pLayerVarArrayNameValue = filterArgs.value<DataPath>(k_LayerVarArrayName_Key);

  /****************************************************************************
   * Write your algorithm implementation in this function
   ***************************************************************************/

  return {};
}
} // namespace complex
