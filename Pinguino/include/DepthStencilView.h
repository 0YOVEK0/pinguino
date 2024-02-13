#pragma once
#include "Prerequisites.h"

class Device;
class DeviceContext;

//DepthStencilView class encapsulates functionality related to depth stencil views in a Direct3D application,
//providing methods for initialization, rendering, and resource management.
class 
DepthStencilView
{
public:
	DepthStencilView() = default;
	~DepthStencilView() { SAFE_RELEASE(m_depthStencilView); };

	void
		init(Device device, ID3D11Resource* depthStencil, DXGI_FORMAT format);

	void
		update();

	void
		render(DeviceContext& deviceContext);

	void
		destroy();

public:

	ID3D11DepthStencilView* m_depthStencilView = nullptr;
};

