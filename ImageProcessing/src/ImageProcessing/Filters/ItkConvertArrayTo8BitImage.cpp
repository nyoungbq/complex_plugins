#include "ItkConvertArrayTo8BitImage.hpp"

#include "complex/DataStructure/DataPath.hpp"
#include "complex/Parameters/ArrayCreationParameter.hpp"
#include "complex/Parameters/ArraySelectionParameter.hpp"

using namespace complex;

namespace complex
{
//------------------------------------------------------------------------------
std::string ItkConvertArrayTo8BitImage::name() const
{
  return FilterTraits<ItkConvertArrayTo8BitImage>::name.str();
}

//------------------------------------------------------------------------------
std::string ItkConvertArrayTo8BitImage::className() const
{
  return FilterTraits<ItkConvertArrayTo8BitImage>::className;
}

//------------------------------------------------------------------------------
Uuid ItkConvertArrayTo8BitImage::uuid() const
{
  return FilterTraits<ItkConvertArrayTo8BitImage>::uuid;
}

//------------------------------------------------------------------------------
std::string ItkConvertArrayTo8BitImage::humanName() const
{
  return "Convert Array to 8 Bit Image (ImageProcessing)";
}

//------------------------------------------------------------------------------
std::vector<std::string> ItkConvertArrayTo8BitImage::defaultTags() const
{
  return {"#Unsupported", "#Misc"};
}

//------------------------------------------------------------------------------
Parameters ItkConvertArrayTo8BitImage::parameters() const
{
  Parameters params;
  // Create the parameter descriptors that are needed for this filter
  params.insertSeparator(Parameters::Separator{"Cell Data"});
  params.insert(std::make_unique<ArraySelectionParameter>(k_SelectedArrayPath_Key, "Attribute Array To Convert", "", DataPath{}));
  params.insertSeparator(Parameters::Separator{"Cell Data"});
  params.insert(std::make_unique<ArrayCreationParameter>(k_NewArrayArrayName_Key, "Converted Attribute Array", "", DataPath{}));

  return params;
}

//------------------------------------------------------------------------------
IFilter::UniquePointer ItkConvertArrayTo8BitImage::clone() const
{
  return std::make_unique<ItkConvertArrayTo8BitImage>();
}

//------------------------------------------------------------------------------
IFilter::PreflightResult ItkConvertArrayTo8BitImage::preflightImpl(const DataStructure& ds, const Arguments& filterArgs, const MessageHandler& messageHandler) const
{
  /****************************************************************************
   * Write any preflight sanity checking codes in this function
   ***************************************************************************/

  /**
   * These are the values that were gathered from the UI or the pipeline file or
   * otherwise passed into the filter. These are here for your convenience. If you
   * do not need some of them remove them.
   */
  auto pSelectedArrayPathValue = filterArgs.value<DataPath>(k_SelectedArrayPath_Key);
  auto pNewArrayArrayNameValue = filterArgs.value<DataPath>(k_NewArrayArrayName_Key);

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
  auto action = std::make_unique<ItkConvertArrayTo8BitImageAction>();
  actions.actions.push_back(std::move(action));
  // Assign the generated outputActions to the PreflightResult::OutputActions property
  preflightResult.outputActions = std::move(actions);
#endif

  return preflightResult;
}

//------------------------------------------------------------------------------
Result<> ItkConvertArrayTo8BitImage::executeImpl(DataStructure& data, const Arguments& filterArgs, const PipelineFilter* pipelineNode, const MessageHandler& messageHandler) const
{
  /****************************************************************************
   * Extract the actual input values from the 'filterArgs' object
   ***************************************************************************/
  auto pSelectedArrayPathValue = filterArgs.value<DataPath>(k_SelectedArrayPath_Key);
  auto pNewArrayArrayNameValue = filterArgs.value<DataPath>(k_NewArrayArrayName_Key);

  /****************************************************************************
   * Write your algorithm implementation in this function
   ***************************************************************************/

  return {};
}
} // namespace complex
