#pragma once
//this are the structure to  relate librarys to the main ccp for it to work  also a little macro for debugging and keep it track the errors
//std Lib
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include<chrono>

//External Lib
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include <xnamath.h>

//windows
#include <windows.h>

//Internal Include
#include "Resource.h"

// MACRO for safe release of resources
#define SAFE_RELEASE(x) if(x != nullptr) x->Release(); x = nullptr;

// * To check programm
#define OutputLOG(_ClassName, _FunctionName, _OutputMessage)  \
OutputDebugStringA(_ClassName);                               \
OutputDebugStringA(" : In Function : ");                      \
OutputDebugStringA(_FunctionName);                            \
OutputDebugStringA(" : ");                                    \
OutputDebugStringA(_OutputMessage);                           \
OutputDebugStringA("\n");

#define WARNING( s )                         \
{                                            \
   std::wostringstream os_;                  \
   os_ << s;                                 \
   OutputDebugStringW( os_.str().c_str() );  \
}

struct SimpleVertex

{

	XMFLOAT3 Pos;

	XMFLOAT2 Tex;

};




struct Mesh {

	std::string name;

	std::vector <SimpleVertex> vertex;

	std::vector <unsigned int> index;

	int numVertex;

	int numIndex;

};