#include <iostream>
#include <cstdint>

#include <string>
#include <vector>
#include <unordered_map>

#include "GLFW/glfw3.h"
#include "Bitmap/Bitmap.h"

const uint32_t RED   = 0x000000FF;
const uint32_t GREEN = 0x0000FF00;
const uint32_t BLUE  = 0x00FF0000;
const int width = 1920, height = 1080;

int main(int argc, const char** argv)
{
  std::unordered_map<std::string, std::string> cmdLineParams;
  std::cout << GLFW_KEY_0 << std::endl;
  for(int i=0; i<argc; ++i)
  {
    std::string key(argv[i]);

    if(key.size() > 0 && key[0]=='-')
    {
      if(i != argc-1) // not last argument
      {
        cmdLineParams[key] = argv[i+1];
        i++;
      }
      else
        cmdLineParams[key] = "";
    }
  }

  std::string outFilePath = "zout.bmp";
  if(cmdLineParams.find("-out") != cmdLineParams.end())
    outFilePath = cmdLineParams["-out"];

  int sceneId = 0;
  if(cmdLineParams.find("-scene") != cmdLineParams.end())
    sceneId = atoi(cmdLineParams["-scene"].c_str());

  uint32_t color = 0;
  if(sceneId == 1)
    color = RED;
  else if(sceneId == 2)
    color = RED | GREEN;
  else if(sceneId == 3)
    color = BLUE;
  
  std::vector<uint32_t> image(width*height); 
  for(auto& pixel : image)
    pixel = color;

  BMP::SaveBMP(outFilePath.c_str(), image.data(), width, height);

  std::cout << "end." << std::endl;
  return 0;
}
