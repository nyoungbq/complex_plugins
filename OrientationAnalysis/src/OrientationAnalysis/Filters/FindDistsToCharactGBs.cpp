#include "FindDistsToCharactGBs.hpp"

#include "complex/DataStructure/DataPath.hpp"
#include "complex/Parameters/ArrayCreationParameter.hpp"
#include "complex/Parameters/ArraySelectionParameter.hpp"

using namespace complex;

namespace complex
{
//------------------------------------------------------------------------------
std::string FindDistsToCharactGBs::name() const
{
  return FilterTraits<FindDistsToCharactGBs>::name.str();
}

//------------------------------------------------------------------------------
std::string FindDistsToCharactGBs::className() const
{
  return FilterTraits<FindDistsToCharactGBs>::className;
}

//------------------------------------------------------------------------------
Uuid FindDistsToCharactGBs::uuid() const
{
  return FilterTraits<FindDistsToCharactGBs>::uuid;
}

//------------------------------------------------------------------------------
std::string FindDistsToCharactGBs::humanName() const
{
  return "Find Distances to Characteristic Grain Boundaries";
}

//------------------------------------------------------------------------------
std::vector<std::string> FindDistsToCharactGBs::defaultTags() const
{
  return {"#Statistics", "#Crystallography"};
}

//------------------------------------------------------------------------------
Parameters FindDistsToCharactGBs::parameters() const
{
  Parameters params;
  // Create the parameter descriptors that are needed for this filter
  params.insertSeparator(Parameters::Separator{"Face Data"});
  params.insert(std::make_unique<ArraySelectionParameter>(k_SurfaceMeshFaceLabelsArrayPath_Key, "Face Labels", "", DataPath{}));
  params.insert(std::make_unique<ArraySelectionParameter>(k_SurfaceMeshFaceNormalsArrayPath_Key, "Face Normals", "", DataPath{}));
  params.insertSeparator(Parameters::Separator{"Cell Feature Data"});
  params.insert(std::make_unique<ArraySelectionParameter>(k_FeatureEulerAnglesArrayPath_Key, "Average Euler Angles", "", DataPath{}));
  params.insert(std::make_unique<ArraySelectionParameter>(k_FeaturePhasesArrayPath_Key, "Phases", "", DataPath{}));
  params.insertSeparator(Parameters::Separator{"Cell Ensemble Data"});
  params.insert(std::make_unique<ArraySelectionParameter>(k_CrystalStructuresArrayPath_Key, "Crystal Structures", "", DataPath{}));
  params.insertSeparator(Parameters::Separator{"Face Data"});
  params.insert(std::make_unique<ArrayCreationParameter>(k_DistToTiltArrayPath_Key, "Distance to Nearest Tilt Boundary", "", DataPath{}));
  params.insert(std::make_unique<ArrayCreationParameter>(k_DistToTwistArrayPath_Key, "Distance to Nearest Twist Boundary", "", DataPath{}));
  params.insert(std::make_unique<ArrayCreationParameter>(k_DistToSymmetricArrayPath_Key, "Distance to Nearest Symmetric Boundary", "", DataPath{}));
  params.insert(std::make_unique<ArrayCreationParameter>(k_DistTo180TiltArrayPath_Key, "Distance to Nearest 180°-tilt  Boundary", "", DataPath{}));

  return params;
}

//------------------------------------------------------------------------------
IFilter::UniquePointer FindDistsToCharactGBs::clone() const
{
  return std::make_unique<FindDistsToCharactGBs>();
}

//------------------------------------------------------------------------------
IFilter::PreflightResult FindDistsToCharactGBs::preflightImpl(const DataStructure& ds, const Arguments& filterArgs, const MessageHandler& messageHandler) const
{
  /****************************************************************************
   * Write any preflight sanity checking codes in this function
   ***************************************************************************/

  /**
   * These are the values that were gathered from the UI or the pipeline file or
   * otherwise passed into the filter. These are here for your convenience. If you
   * do not need some of them remove them.
   */
  auto pSurfaceMeshFaceLabelsArrayPathValue = filterArgs.value<DataPath>(k_SurfaceMeshFaceLabelsArrayPath_Key);
  auto pSurfaceMeshFaceNormalsArrayPathValue = filterArgs.value<DataPath>(k_SurfaceMeshFaceNormalsArrayPath_Key);
  auto pFeatureEulerAnglesArrayPathValue = filterArgs.value<DataPath>(k_FeatureEulerAnglesArrayPath_Key);
  auto pFeaturePhasesArrayPathValue = filterArgs.value<DataPath>(k_FeaturePhasesArrayPath_Key);
  auto pCrystalStructuresArrayPathValue = filterArgs.value<DataPath>(k_CrystalStructuresArrayPath_Key);
  auto pDistToTiltArrayPathValue = filterArgs.value<DataPath>(k_DistToTiltArrayPath_Key);
  auto pDistToTwistArrayPathValue = filterArgs.value<DataPath>(k_DistToTwistArrayPath_Key);
  auto pDistToSymmetricArrayPathValue = filterArgs.value<DataPath>(k_DistToSymmetricArrayPath_Key);
  auto pDistTo180TiltArrayPathValue = filterArgs.value<DataPath>(k_DistTo180TiltArrayPath_Key);

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
  auto action = std::make_unique<FindDistsToCharactGBsAction>();
  actions.actions.push_back(std::move(action));
  // Assign the generated outputActions to the PreflightResult::OutputActions property
  preflightResult.outputActions = std::move(actions);
#endif

  return preflightResult;
}

//------------------------------------------------------------------------------
Result<> FindDistsToCharactGBs::executeImpl(DataStructure& data, const Arguments& filterArgs, const PipelineFilter* pipelineNode, const MessageHandler& messageHandler) const
{
  /****************************************************************************
   * Extract the actual input values from the 'filterArgs' object
   ***************************************************************************/
  auto pSurfaceMeshFaceLabelsArrayPathValue = filterArgs.value<DataPath>(k_SurfaceMeshFaceLabelsArrayPath_Key);
  auto pSurfaceMeshFaceNormalsArrayPathValue = filterArgs.value<DataPath>(k_SurfaceMeshFaceNormalsArrayPath_Key);
  auto pFeatureEulerAnglesArrayPathValue = filterArgs.value<DataPath>(k_FeatureEulerAnglesArrayPath_Key);
  auto pFeaturePhasesArrayPathValue = filterArgs.value<DataPath>(k_FeaturePhasesArrayPath_Key);
  auto pCrystalStructuresArrayPathValue = filterArgs.value<DataPath>(k_CrystalStructuresArrayPath_Key);
  auto pDistToTiltArrayPathValue = filterArgs.value<DataPath>(k_DistToTiltArrayPath_Key);
  auto pDistToTwistArrayPathValue = filterArgs.value<DataPath>(k_DistToTwistArrayPath_Key);
  auto pDistToSymmetricArrayPathValue = filterArgs.value<DataPath>(k_DistToSymmetricArrayPath_Key);
  auto pDistTo180TiltArrayPathValue = filterArgs.value<DataPath>(k_DistTo180TiltArrayPath_Key);

  /****************************************************************************
   * Write your algorithm implementation in this function
   ***************************************************************************/

  return {};
}
} // namespace complex
