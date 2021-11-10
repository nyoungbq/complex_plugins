#include "ImportQMMeltpoolH5File.hpp"

#include "complex/DataStructure/DataPath.hpp"
#include "complex/Parameters/DataGroupCreationParameter.hpp"
#include "complex/Parameters/MultiInputFileFilterParameter.hpp"
#include "complex/Parameters/NumberParameter.hpp"
#include "complex/Parameters/StringParameter.hpp"
#include "complex/Parameters/VectorParameter.hpp"

using namespace complex;

namespace complex
{
//------------------------------------------------------------------------------
std::string ImportQMMeltpoolH5File::name() const
{
  return FilterTraits<ImportQMMeltpoolH5File>::name.str();
}

//------------------------------------------------------------------------------
std::string ImportQMMeltpoolH5File::className() const
{
  return FilterTraits<ImportQMMeltpoolH5File>::className;
}

//------------------------------------------------------------------------------
Uuid ImportQMMeltpoolH5File::uuid() const
{
  return FilterTraits<ImportQMMeltpoolH5File>::uuid;
}

//------------------------------------------------------------------------------
std::string ImportQMMeltpoolH5File::humanName() const
{
  return "Import QM Meltpool HDF5 File";
}

//------------------------------------------------------------------------------
std::vector<std::string> ImportQMMeltpoolH5File::defaultTags() const
{
  return {"#IO", "#Input", "#Read", "#Import"};
}

//------------------------------------------------------------------------------
Parameters ImportQMMeltpoolH5File::parameters() const
{
  Parameters params;
  // Create the parameter descriptors that are needed for this filter
  /*[x]*/ params.insert(std::make_unique<MultiInputFileFilterParameter>(k_InputFiles_Key, "Input File(s)", "", {}));
  params.insert(std::make_unique<VectorInt32Parameter>(k_SliceRange_Key, "Slice Index Start/End [Inclusive]", "", std::vector<int32>(2), std::vector<std::string>(2)));
  params.insert(std::make_unique<DataGroupCreationParameter>(k_DataContainerPath_Key, "Data Container Name", "", DataPath{}));
  params.insert(std::make_unique<StringParameter>(k_VertexAttributeMatrixName_Key, "Vertex Attribute Matrix Name", "", "SomeString"));
  params.insert(std::make_unique<Float32Parameter>(k_Power_Key, "Power", "", 1.23345f));

  return params;
}

//------------------------------------------------------------------------------
IFilter::UniquePointer ImportQMMeltpoolH5File::clone() const
{
  return std::make_unique<ImportQMMeltpoolH5File>();
}

//------------------------------------------------------------------------------
IFilter::PreflightResult ImportQMMeltpoolH5File::preflightImpl(const DataStructure& ds, const Arguments& filterArgs, const MessageHandler& messageHandler) const
{
  /****************************************************************************
   * Write any preflight sanity checking codes in this function
   ***************************************************************************/

  /**
   * These are the values that were gathered from the UI or the pipeline file or
   * otherwise passed into the filter. These are here for your convenience. If you
   * do not need some of them remove them.
   */
  auto pInputFilesValue = filterArgs.value<<<<NOT_IMPLEMENTED>>>>(k_InputFiles_Key);
  auto pSliceRangeValue = filterArgs.value<VectorInt32Parameter::ValueType>(k_SliceRange_Key);
  auto pDataContainerPathValue = filterArgs.value<DataPath>(k_DataContainerPath_Key);
  auto pVertexAttributeMatrixNameValue = filterArgs.value<StringParameter::ValueType>(k_VertexAttributeMatrixName_Key);
  auto pPowerValue = filterArgs.value<float32>(k_Power_Key);

  // These variables should be updated with the latest data generated for each variable during preflight.
  // These will be returned through the preflightResult variable to the
  // user interface. You could make these member variables instead if needed.
  std::string possibleIndices;

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
  auto action = std::make_unique<ImportQMMeltpoolH5FileAction>();
  actions.actions.push_back(std::move(action));
  // Assign the generated outputActions to the PreflightResult::OutputActions property
  preflightResult.outputActions = std::move(actions);
#endif

  // These values should have been updated during the preflightImpl(...) method
  preflightResult.outputValues.push_back({"PossibleIndices", possibleIndices});

  return preflightResult;
}

//------------------------------------------------------------------------------
Result<> ImportQMMeltpoolH5File::executeImpl(DataStructure& data, const Arguments& filterArgs, const PipelineFilter* pipelineNode, const MessageHandler& messageHandler) const
{
  /****************************************************************************
   * Extract the actual input values from the 'filterArgs' object
   ***************************************************************************/
  auto pInputFilesValue = filterArgs.value<<<<NOT_IMPLEMENTED>>>>(k_InputFiles_Key);
  auto pSliceRangeValue = filterArgs.value<VectorInt32Parameter::ValueType>(k_SliceRange_Key);
  auto pDataContainerPathValue = filterArgs.value<DataPath>(k_DataContainerPath_Key);
  auto pVertexAttributeMatrixNameValue = filterArgs.value<StringParameter::ValueType>(k_VertexAttributeMatrixName_Key);
  auto pPowerValue = filterArgs.value<float32>(k_Power_Key);

  /****************************************************************************
   * Write your algorithm implementation in this function
   ***************************************************************************/

  return {};
}
} // namespace complex
