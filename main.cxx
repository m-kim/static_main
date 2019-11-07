//==================================================================================================
// Written in 2019 by Mark Kim
//
// To the extent possible under law, the author(s) have dedicated all copyright and related and
// neighboring rights to this software to the public domain worldwide. This software is distributed
// without any warranty.
//
// You should have received a copy (see file COPYING.txt) of the CC0 Public Domain Dedication along
// with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>.
//==================================================================================================
#include <vtkm/cont/Initialize.h>
#include <vtkm/cont/DeviceAdapter.h>
#include <vtkm/cont/RuntimeDeviceTracker.h>

//#include <vtkm/cont/testing/MakeTestDataSet.h>
//#include <vtkm/cont/testing/Testing.h>
//#include <vtkm/rendering/Actor.h>
//#include <vtkm/rendering/CanvasRayTracer.h>
//#include <vtkm/rendering/MapperRayTracer.h>
//#include <vtkm/rendering/Scene.h>
//#include <vtkm/rendering/View3D.h>
//#include <vtkm/rendering/testing/RenderTest.h>


#include <vtkm/cont/Algorithm.h>
#include <vtkm/cont/ArrayHandle.h>

//void testRaytracer()
//{
//  using C = vtkm::rendering::CanvasRayTracer;
//  using M = vtkm::rendering::MapperRayTracer;
//  using V3 = vtkm::rendering::View3D;
//  using V2 = vtkm::rendering::View2D;

//  vtkm::cont::testing::MakeTestDataSet maker;
//  vtkm::cont::ColorTable colorTable("inferno");

//  vtkm::rendering::testing::Render<M, C, V3>(
//    maker.Make3DRegularDataSet0(), "pointvar", colorTable, "rt_reg3D.pnm");

//}
void testSort()
{
  std::vector<float> array(10);
  for (int i = 9; i>=0; i--){
    array[i] = i;
    }

  auto ds = vtkm::cont::make_ArrayHandle(array);

  vtkm::cont::Algorithm::Sort(ds);

}
int main(int argc, char *argv[]) {
  vtkm::cont::Initialize();
  vtkm::cont::GetRuntimeDeviceTracker().ForceDevice(vtkm::cont::DeviceAdapterTagCuda{});

  //testRaytracer();

  testSort();


}

