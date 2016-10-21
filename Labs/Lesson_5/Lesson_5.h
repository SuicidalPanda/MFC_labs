
// Lesson_5.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CLesson_5App:
// See Lesson_5.cpp for the implementation of this class
//

class CLesson_5App : public CWinApp
{
public:
	CLesson_5App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CLesson_5App theApp;