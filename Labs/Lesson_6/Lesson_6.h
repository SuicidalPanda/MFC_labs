
// Lesson_6.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CLesson_6App:
// See Lesson_6.cpp for the implementation of this class
//

class CLesson_6App : public CWinApp
{
public:
	CLesson_6App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CLesson_6App theApp;