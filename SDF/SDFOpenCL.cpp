// SDFOpenCL.cpp : subor pre OpenCL manipulaciu
#include "stdafx.h"
#include "SDFOpenCL.h"

#define EXIT_SUCCESS			0
#define EXIT_FAIL_PLATFORM		1
#define EXIT_FAIL_GROUP			2
#define EXIT_FAIL_CONTEXT		3
#define EXIT_FAIL_COMMAND		4
#define EXIT_FAIL_CREATE		5
#define EXIT_FAIL_PROGRAM		6
#define EXIT_FAIL_KERNEL		7
#define EXIT_FAIL_DEVICE		8
#define EXIT_FAIL_MEMORY		9
#define EXIT_FAIL_WRITE			10
#define EXIT_FAIL_ARGUMENTS		11
#define EXIT_FAIL_EXECUTE		12
#define EXIT_FAIL_LOAD			13
#define EXIT_FAIL_READ			14

//#define DEBUG_OPENCL

namespace OpenCLForm
{
	
	COpenCL::COpenCL()
	{
		cpPlatform = NULL;
		device_id = NULL;
		context = NULL;
		commands = NULL;
		program = NULL;
		kernel = NULL;

		b_triangles = NULL;
		b_vertices = NULL;
		b_origins = NULL;
		b_rays = NULL;
		b_targets = NULL;
		b_outputs = NULL;

		debugger = new COpenCLDebug();
	}
	COpenCL::~COpenCL()
	{
		clReleaseMemObject(b_triangles);
		clReleaseMemObject(b_vertices);
		clReleaseMemObject(b_origins);
		clReleaseMemObject(b_rays);
		clReleaseMemObject(b_targets);
		clReleaseMemObject(b_outputs);

		clReleaseProgram(program);
		clReleaseKernel(kernel);
		clReleaseCommandQueue(commands);
		clReleaseContext(context);

		delete debugger;
	}

	int COpenCL::InitOpenCL()
	{
		int devType=CL_DEVICE_TYPE_GPU;
 
		/*****************************************/
		/* Initialize OpenCL */
		/*****************************************/
		err = 0;
		// Connect to a compute device (only first platform)
		err = clGetPlatformIDs(1, &cpPlatform, NULL);
		if (err != CL_SUCCESS)
		{
			//"Error: Failed to find a platform!"
			return EXIT_FAIL_PLATFORM;
		}
  
		// Get a device of the appropriate type (only first device)
		err = clGetDeviceIDs(cpPlatform, devType, 1, &device_id, NULL);
		if (err != CL_SUCCESS)
		{
			//"Error: Failed to create a device group!"
			return EXIT_FAIL_GROUP;
		}
  
		// Create a compute context (only one device)
		context = clCreateContext(0, 1, &device_id, NULL, NULL, &err);
		if (!context)
		{
			//"Error: Failed to create a compute context!"
			return EXIT_FAIL_CONTEXT;
		}
  
		// Create a command commands (default setting)
		commands = clCreateCommandQueue(context, device_id, 0, &err);
		if (!commands)
		{
			//"Error: Failed to create a command commands!"
			return EXIT_FAIL_COMMAND;
		}
  
		return EXIT_SUCCESS;
	
	}

	int COpenCL::LoadKernel(const char* cSourceFile)
	{
		cSourceCL = NULL;

		// Read the OpenCL kernel in from source file
		cSourceCL = oclLoadProgSource(cSourceFile, "", &szKernelLength);

		if(cSourceCL != NULL)
			return EXIT_SUCCESS;

		return EXIT_FAIL_LOAD;
	}

	int COpenCL::BuildKernel()
	{
		// Create the compute program from the source buffer
		program = clCreateProgramWithSource(context, 1, (const char **)&cSourceCL, &szKernelLength, &err);
		if (!program)
		{
			//"Error: Failed to create compute program!"
			return EXIT_FAIL_CREATE;
		}
  
		// Build the program executable (default setting)
		err = clBuildProgram(program, 0, NULL, "-cl-fast-relaxed-math", NULL, NULL);
		if (err != CL_SUCCESS)
		{
			//"Error: Failed to build program executable!"
			clGetProgramBuildInfo(program, device_id, CL_PROGRAM_BUILD_LOG, sizeof(debug_buffer), debug_buffer, &debug_len);
			return EXIT_FAIL_PROGRAM;
		}

		// Create the compute kernel in the program
		kernel = clCreateKernel(program, "sdf", &err);
		if (!kernel || err != CL_SUCCESS)
		{
			//"Error: Failed to create compute kernel!"
			return EXIT_FAIL_KERNEL;
		}

		return EXIT_SUCCESS;
	}

	int COpenCL::GetGPUVariables()
	{
		err = clGetDeviceInfo(device_id, CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(cl_uint), &num_cores, NULL);
		if (err != CL_SUCCESS)
		{
			//"Error: Failed to get device info!"
			return EXIT_FAIL_DEVICE;
		}

		err = clGetDeviceInfo(device_id, CL_DEVICE_MAX_WORK_GROUP_SIZE, sizeof(size_t), &num_1D_work_items, NULL);
		if (err != CL_SUCCESS)
		{
			//"Error: Failed to get device info!"
			return EXIT_FAIL_DEVICE;
		}

		err = clGetDeviceInfo(device_id,CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS, sizeof(cl_uint), &num_dimensions, NULL);
		if (err != CL_SUCCESS)
		{
			//"Error: Failed to get device info!"
			return EXIT_FAIL_DEVICE;
		}

		err = clGetDeviceInfo(device_id, CL_DEVICE_MAX_WORK_ITEM_SIZES, sizeof(num_ND_work_items), &num_ND_work_items, NULL);
		if (err != CL_SUCCESS)
		{
			//"Error: Failed to get device info!"
			return EXIT_FAIL_DEVICE;
		}

		err = clGetDeviceInfo(device_id, CL_DEVICE_GLOBAL_MEM_SIZE, sizeof(cl_ulong), &num_memsize, NULL);
		if (err != CL_SUCCESS)
		{
			//"Error: Failed to get device info!"
			return EXIT_FAIL_DEVICE;
		}

		return EXIT_SUCCESS;
	}

	int COpenCL::SetupMemory(unsigned int ss_triangles, unsigned int ss_vertices, unsigned int ss_origins, unsigned int ss_rays, unsigned int ss_targets, unsigned int ss_outputs)
	{
		s_triangles = ss_triangles;
		s_vertices = ss_vertices;
		s_origins = ss_origins;
		s_rays = ss_rays;
		s_targets = ss_targets;
		s_outputs = ss_outputs;

		err = CL_SUCCESS;

		// Setup device memory
		b_triangles = clCreateBuffer(context, CL_MEM_READ_ONLY, s_triangles, NULL, &err);
		if (err != CL_SUCCESS)
		{
			//"Error: Failed to allocate memory!"
			return EXIT_FAIL_MEMORY;
		}
		b_vertices = clCreateBuffer(context, CL_MEM_READ_ONLY, s_vertices, NULL, &err);
		if (err != CL_SUCCESS)
		{
			//"Error: Failed to allocate memory!"
			return EXIT_FAIL_MEMORY;
		}
		b_origins = clCreateBuffer(context, CL_MEM_READ_ONLY, s_origins, NULL, &err);
		if (err != CL_SUCCESS)
		{
			//"Error: Failed to allocate memory!"
			return EXIT_FAIL_MEMORY;
		}
		b_rays = clCreateBuffer(context, CL_MEM_READ_ONLY, s_rays, NULL, &err);
		if (err != CL_SUCCESS)
		{
			//"Error: Failed to allocate memory!"
			return EXIT_FAIL_MEMORY;
		}
		b_targets = clCreateBuffer(context, CL_MEM_READ_ONLY, s_targets, NULL, &err);
		if (err != CL_SUCCESS)
		{
			//"Error: Failed to allocate memory!"
			return EXIT_FAIL_MEMORY;
		}
		b_outputs = clCreateBuffer(context, CL_MEM_WRITE_ONLY, s_outputs, NULL, &err);
		if (err != CL_SUCCESS)
		{
			//"Error: Failed to allocate memory!"
			return EXIT_FAIL_MEMORY;
		}

		return EXIT_SUCCESS;
	}

	int COpenCL::LaunchKernel(cl_uint3	*c_triangles, cl_float4	*c_vertices, cl_uint *c_origins, cl_float4 *c_rays, cl_uint *c_targets, cl_float *c_outputs, cl_uint4 c_params)
	{
		// Transfer the input vectors into device memory
		err = CL_SUCCESS;
		err |= clEnqueueWriteBuffer(commands, b_triangles, CL_FALSE, 0, s_triangles, c_triangles, 0, NULL, NULL);
		err |= clEnqueueWriteBuffer(commands, b_vertices, CL_FALSE, 0, s_vertices, c_vertices, 0, NULL, NULL);
		err |= clEnqueueWriteBuffer(commands, b_origins, CL_FALSE, 0, s_origins, c_origins, 0, NULL, NULL);
		err |= clEnqueueWriteBuffer(commands, b_rays, CL_FALSE, 0, s_rays, c_rays, 0, NULL, NULL);
		err |= clEnqueueWriteBuffer(commands, b_targets, CL_FALSE, 0, s_targets, c_targets, 0, NULL, NULL);
		//err |= clEnqueueWriteBuffer(commands, b_outputs, CL_FALSE, 0, s_outputs, c_outputs, 0, NULL, NULL);
		if (err != CL_SUCCESS)
		{
			//"Error: Failed to write to source array!"
			return(EXIT_FAIL_WRITE);
		}
  
		// Set the arguments to the compute kernel
		err = CL_SUCCESS;
		cl_uint n = 0;

#ifndef DEBUG_OPENCL
		err  = clSetKernelArg(kernel, n++, sizeof(cl_mem), &b_triangles);
		err |= clSetKernelArg(kernel, n++, sizeof(cl_mem), &b_vertices);
		err |= clSetKernelArg(kernel, n++, sizeof(cl_mem), &b_origins);
		err |= clSetKernelArg(kernel, n++, sizeof(cl_mem), &b_rays);
		err |= clSetKernelArg(kernel, n++, sizeof(cl_mem), &b_targets);
		err |= clSetKernelArg(kernel, n++, sizeof(cl_uint4), &c_params);
		err |= clSetKernelArg(kernel, n++, sizeof(cl_mem), &b_outputs);
		if (err != CL_SUCCESS)
		{
			//"Error: Failed to set kernel arguments! " << err << endl;
			return EXIT_FAIL_ARGUMENTS;
		}

		// Execute the kernel
		err = clEnqueueNDRangeKernel(commands, kernel, 1, NULL, &global, &local, 0, NULL, NULL);
		if (err != CL_SUCCESS)//CL_INVALID_WORK_GROUP_SIZE;
		{
			//"Error: Failed to execute kernel!"
			return EXIT_FAIL_EXECUTE;
		}

		err = clEnqueueReadBuffer(commands, b_outputs, CL_FALSE, 0, s_outputs, c_outputs, 0, NULL, NULL );
		if (err != CL_SUCCESS)
		{
			//"Error: Failed to read from source array!"
			return(EXIT_FAIL_READ);//CL_OUT_OF_RESOURCES
		}
#else
		debugger->SetArgSize(7);
		debugger->SetArgValue(n++, c_triangles);
		debugger->SetArgValue(n++, c_vertices);
		debugger->SetArgValue(n++, c_origins);
		debugger->SetArgValue(n++, c_rays);
		debugger->SetArgValue(n++, c_targets);
		debugger->SetArgValue(n++, &c_params);
		debugger->SetArgValue(n++, c_outputs);

		debugger->ExecuteKernel(global, local);
#endif
		return EXIT_SUCCESS;
	}

	void COpenCL::WaitForFinish()
	{
		clFinish(commands);
	}


}