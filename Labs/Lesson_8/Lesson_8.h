
// Lesson_8.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CLesson_8App:
// See Lesson_8.cpp for the implementation of this class
//

class CLesson_8App : public CWinApp
{
public:
	CLesson_8App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CLesson_8App theApp;