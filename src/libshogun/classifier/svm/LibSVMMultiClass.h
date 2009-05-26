/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 1999-2009 Soeren Sonnenburg
 * Copyright (C) 1999-2009 Fraunhofer Institute FIRST and Max-Planck-Society
 */

#ifndef _LIBSVM_MULTICLASS_H___
#define _LIBSVM_MULTICLASS_H___

#include "lib/common.h"
#include "classifier/svm/MultiClassSVM.h"
#include "classifier/svm/SVM_libsvm.h"

#include <stdio.h>
enum LIBSVM_SOLVER_TYPE
{
	LIBSVM_C_SVC = 1,
	LIBSVM_NU_SVC = 2
};

/** @brief class LibSVMMultiClass */
class CLibSVMMultiClass : public CMultiClassSVM
{
	public:
		/** default constructor */
		CLibSVMMultiClass(LIBSVM_SOLVER_TYPE st=LIBSVM_C_SVC);

		/** constructor
		 *
		 * @param C constant C
		 * @param k kernel
		 * @param lab labels
		 */
		CLibSVMMultiClass(float64_t C, CKernel* k, CLabels* lab);
		virtual ~CLibSVMMultiClass();

		/** train SVM
		 *
		 * @return if training was successful
		 */
		virtual bool train();

		/** get classifier type
		 *
		 * @return classifier type LIBSVMMULTICLASS
		 */
		virtual inline EClassifierType get_classifier_type() { return CT_LIBSVMMULTICLASS; }

		/** @return object name */
		inline virtual const char* get_name() const { return "LibSVMMultiClass"; }

	protected:
		/** SVM problem */
		svm_problem problem;
		/** SVM parameter */
		svm_parameter param;

		/** SVM model */
		struct svm_model* model;

		/** solver type */
		LIBSVM_SOLVER_TYPE solver_type;
};
#endif

