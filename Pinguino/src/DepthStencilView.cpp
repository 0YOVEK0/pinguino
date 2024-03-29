#include "DepthStencilView.h"
#include "Device.h"
#include "DeviceContext.h"
void 
DepthStencilView::init(Device device, ID3D11Resource* depthStencil, DXGI_FORMAT format)
{
	if (device.m_device ==nullptr)
	{
		WARNING("ERROR Device::DepthStencilView : [CHECK FOR Device device : OK]\n ")
			exit(1);
	}
	else if (depthStencil == nullptr)
	{
		WARNING("ERROR Device::DepthStencilView : [CHECK FOR  ID3D11Resource* depthStencil : OK]\n ")
			exit(1);
	}
	else
	{
		D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;
		memset(&descDSV,0, sizeof(descDSV));
		descDSV.Format = format;
		descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
		descDSV.Texture2D.MipSlice = 0;

		device.CreateDepthStencilView(depthStencil, &descDSV, &m_depthStencilView);
	}
}

void 
DepthStencilView::update()
{
}

void 
DepthStencilView::render(DeviceContext& deviceContext)
{
	deviceContext.ClearDepthStencilView(m_depthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);
}

void
DepthStencilView::destroy()
{
	SAFE_RELEASE(m_depthStencilView);
}
