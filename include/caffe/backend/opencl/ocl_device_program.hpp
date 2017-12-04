#ifndef CAFFE_BACKEND_OPENCL_OCL_DEVICE_PROGRAM_HPP_
#define CAFFE_BACKEND_OPENCL_OCL_DEVICE_PROGRAM_HPP_

#include "caffe/backend/device_program.hpp"
#include "caffe/backend/opencl/ocl_device_kernel.hpp"

#ifdef USE_OPENCL
#include "viennacl/backend/opencl.hpp"
#include "viennacl/ocl/backend.hpp"
#include "viennacl/ocl/context.hpp"
#include "viennacl/ocl/device.hpp"
#include "viennacl/ocl/platform.hpp"
#endif  // USE_OPENCL

namespace caffe {

#ifdef USE_OPENCL

class OclDeviceProgram : public DeviceProgram {
 public:
  explicit OclDeviceProgram(Device *dev);

  virtual void Compile(bool load_cache, bool store_cache);
  virtual shared_ptr<DeviceKernel> GetKernel(string name);

  virtual string function(string name, KernelArgs args);
  virtual string kernel_loop(string type, string index, string n);
  virtual string setup();
  virtual string atomics();
  virtual string global_ptr(string type, string name);
  virtual string local_ptr(string type, string name);
  virtual string local_mem(string type, string name);

  virtual string local_id(uint_tp fixed_index);
  virtual string local_id(string runtime_index);
  virtual string local_size(uint_tp fixed_index);
  virtual string local_size(string runtime_index);
  virtual string group_id(uint_tp fixed_index);
  virtual string group_id(string runtime_index);
  virtual string group_size(uint_tp fixed_index);
  virtual string group_size(string runtime_index);
  virtual string global_id(uint_tp fixed_index);
  virtual string global_id(string runtime_index);
  virtual string global_size(uint_tp fixed_index);
  virtual string global_size(string runtime_index);

  virtual string local_barrier();
  virtual string global_barrier();

  virtual string kernel_arg_type_void(uint64_t flags);
  virtual string kernel_arg_type_bool(uint64_t flags);
  virtual string kernel_arg_type_char(uint64_t flags);
  virtual string kernel_arg_type_half(uint64_t flags);
  virtual string kernel_arg_type_float(uint64_t flags);
  virtual string kernel_arg_type_double(uint64_t flags);
  virtual string kernel_arg_type_int8_t(uint64_t flags);
  virtual string kernel_arg_type_int16_t(uint64_t flags);
  virtual string kernel_arg_type_int32_t(uint64_t flags);
  virtual string kernel_arg_type_int64_t(uint64_t flags);
  virtual string kernel_arg_type_uint8_t(uint64_t flags);
  virtual string kernel_arg_type_uint16_t(uint64_t flags);
  virtual string kernel_arg_type_uint32_t(uint64_t flags);
  virtual string kernel_arg_type_uint64_t(uint64_t flags);

 private:
  viennacl::ocl::program ocl_program_;
};

#endif  // USE_OPENCL

}

#endif  // CAFFE_BACKEND_OPENCL_OCL_DEVICE_PROGRAM_HPP_
