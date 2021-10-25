#ifndef __SVISION_BARRECENGINE_ERRCODEJ_H__
#define __SVISION_BARRECENGINE_ERRCODEJ_H__

// error codes of engine
enum ErrorCode {
	svec_mismatched_vectors = -8,		// mismatched vectors of result
	svec_get_attributes = -7,			// failed to get parameters
	svec_raised_find_code = -6,			// failed to find barcode
	svec_cannot_alloc_image = -5,		// failed to alloc buffer of image
	svec_not_implement = -4,			// not implement yet
	svec_too_large_image = -3,			// input image is too large
	svec_modelfail = -2,				// failed to create model
	svec_invalid_param = -1,			// invalid parameters
	svec_ok = 0,						// no error, success
};
#endif//__SVISION_BARRECENGINE_ERRCODEJ_H__
//.EOF