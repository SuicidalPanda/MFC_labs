
// Lesson_10.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CLesson_10App:
// See Lesson_10.cpp for the implementation of this class
//

class CLesson_10App : public CWinApp
{
public:
	CLesson_10App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CLesson_10App theApp;