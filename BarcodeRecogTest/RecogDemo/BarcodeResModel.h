#ifndef __BARCODE_RECOGAPP_VIEWMODEL_BARCODEJ_H__
#define __BARCODE_RECOGAPP_VIEWMODEL_BARCODEJ_H__

#include "IViewModel.h"
#include <vector>
#include "RecogEngineDefine.h"

class CBarcodeResModel : public IImageViewModel
{
public:
	CBarcodeResModel();
	virtual ~CBarcodeResModel();

	virtual void DrawModel(CDC* pDC, const CRect& viewRect, int realW, int realH);
	
	void SetBarcodeResult(int _cnt, CodeRecogRes* _pRes);
private:
	std::vector<CodeRecogRes> m_aRes;
};

#endif//__BARCODE_RECOGAPP_VIEWMODEL_BARCODEJ_H__
//.EOF