#include "Lesson7.hpp"

#include "complex/DataStructure/DataPath.hpp"
#include "complex/Parameters/DataGroupSelectionParameter.hpp"

using namespace complex;

namespace complex
{
//------------------------------------------------------------------------------
std::string Lesson7::name() const
{
  return FilterTraits<Lesson7>::name.str();
}

//------------------------------------------------------------------------------
std::string Lesson7::className() const
{
  return FilterTraits<Lesson7>::className;
}

//------------------------------------------------------------------------------
Uuid Lesson7::uuid() const
{
  return FilterTraits<Lesson7>::uuid;
}

//------------------------------------------------------------------------------
std::string Lesson7::humanName() const
{
  return "Lesson7";
}

//------------------------------------------------------------------------------
std::vector<std::string> Lesson7::defaultTags() const
{
  return {"#Unsupported", "#ProgWorkshop"};
}

//------------------------------------------------------------------------------
Parameters Lesson7::parameters() const
{
  Parameters params;
  // Create the parameter descriptors that are needed for this filter
  params.insert(std::make_unique<DataGroupSelectionParameter>(k_GeometrySelection_Key, "Geometry", "", DataPath{}));

  return params;
}

//------------------------------------------------------------------------------
IFilter::UniquePointer Lesson7::clone() const
{
  return std::make_unique<Lesson7>();
}

//------------------------------------------------------------------------------
IFilter::PreflightResult Lesson7::preflightImpl(const DataStructure& ds, const Arguments& filterArgs, const MessageHandler& messageHandler) const
{
  /****************************************************************************
   * Write any preflight sanity checking codes in this function
   ***************************************************************************/

  /**
   * These are the values that were gathered from the UI or the pipeline file or
   * otherwise passed into the filter. These are here for your convenience. If you
   * do not need some of them remove them.
   */
  auto pGeometrySelectionValue = filterArgs.value<DataPath>(k_GeometrySelection_Key);

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
  auto action = std::make_unique<Lesson7Action>();
  actions.actions.push_back(std::move(action));
  // Assign the generated outputActions to the PreflightResult::OutputActions property
  preflightResult.outputActions = std::move(actions);
#endif

  return preflightResult;
}

//------------------------------------------------------------------------------
Result<> Lesson7::executeImpl(DataStructure& data, const Arguments& filterArgs, const PipelineFilter* pipelineNode, const MessageHandler& messageHandler) const
{
  /****************************************************************************
   * Extract the actual input values from the 'filterArgs' object
   ***************************************************************************/
  auto pGeometrySelectionValue = filterArgs.value<DataPath>(k_GeometrySelection_Key);

  /****************************************************************************
   * Write your algorithm implementation in this function
   ***************************************************************************/

  return {};
}
} // namespace complex
