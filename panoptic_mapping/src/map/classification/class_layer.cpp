
#include "panoptic_mapping/map/classification/class_layer.h"

namespace panoptic_mapping {
template <typename VoxelType>
class ClassVoxelLayer : public voxblox::Layer<VoxelType> {
  // How many class assignements should be serialized.
  int serialize_top_n_classes_ = 4;

 public:
  explicit ClassVoxelLayer<VoxelType>(voxblox::FloatingPoint voxel_size,
                                      size_t voxels_per_side)
      : voxblox::Layer<VoxelType>(voxel_size, voxels_per_side) {}

  explicit ClassVoxelLayer<VoxelType>(voxblox::FloatingPoint voxel_size,
                                      size_t voxels_per_side,
                                      int serialize_top_n_classes)
      : voxblox::Layer<VoxelType>(voxel_size, voxels_per_side),
        serialize_top_n_classes_(serialize_top_n_classes) {}

  bool saveBlocksToStream(bool include_all_blocks,
                          voxblox::BlockIndexList blocks_to_include,
                          std::fstream* outfile_ptr) const;

  void setNumClassesToSerialize(int serialize_top_n_classes) {
    serialize_top_n_classes_ = serialize_top_n_classes;
  }
};

}  // namespace panoptic_mapping
