
// Lesson_1.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CLesson_1App:
// See Lesson_1.cpp for the implementation of this class
//

class CLesson_1App : public CWinApp
{
public:
	CLesson_1App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CLesson_1App theApp;